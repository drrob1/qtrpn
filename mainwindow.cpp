#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <QFile>
#include <QFileDialog>
#include <QDataStream>
#include <QMessageBox>
#include <QDialog>
#include <QInputDialog>
#include <QTextStream>  // doesn't do what I want.  I want stringstream functionality.  I'll just have to use a stringstream for that, after all.

//#include <string>  already in macros.h
// ----------------------- my stuff
#include "macros.h"
#include "hpcalcc2.h"
// in hpcalcc2.h is this
//  struct calcPairType {
//      vector<string> ss;
//      double R;
//  };

#include "tokenizec2.h"
#include "timlibc2.h"
#include "holidaycalc2.h"
#include "getcommandline2.h"
#include "makesubst.h"

void ProcessInput(string cmdstr);  // forward reference

//double R;  not global
//int I;     not global
int SigFig = -1;  // qt creator complained about a double definition of sigfig, so this one is now SigFig
struct RegisterType {
    double value;
    QString name;
};

ARRAYOF RegisterType Storage[36];  // var Storage []RegisterType  in Go syntax
ARRAYOF double Stk[StackSize];
bool CombinedFileExists;
const char *CombinedFileName = "RPNStackStorage.sav";
const QString CombinedFilenamestring = CombinedFileName;
string LastCompiledDate = __DATE__;
string LastCompiledTime = __TIME__;

// Ui::MainWindow *ui;  //make ui global   Didn't work.  I think it crashed the pgm.

enum OutputStateEnum {outputfix, outputfloat, outputgen};
OutputStateEnum OutputState = outputfix;

// constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) { // constructor
    ui->setupUi(this);

    QFile fh(CombinedFileName);
    CombinedFileExists = fh.exists();
    if (CombinedFileExists) { // read the file into the stack and storage registers.
        bool opened = fh.open(QFile::ReadOnly);
        if (NOT opened) QMessageBox::warning(this," file not opened", "Stack and Storage combined input file could not be opened, but it exists.");
        QDataStream combinedfile(&fh);
        for (int i = 0; i < StackSize; i++) {  // read in Stk
          combinedfile >> Stk[i];
          PUSHX(Stk[i]);
        }

        for (int i = 0; i < 36; i++) {  // read in Storage registers
            QString qstr;
            double r;
            combinedfile >> r;
            combinedfile >> qstr;
            Storage[i].value = r;
            Storage[i].name = qstr;
        }
    } else {  // init the stack and storage registers to the zero value for each type.
        for (int i = 0; i < StackSize; i++) Stk[i] = 0.;  // Zero out stack
        for (int i = 0; i < 36; i++) {
            Storage[i].value = 0.;
            Storage[i].name = "";
        }
    }
    QStringList list = QCoreApplication::arguments();
    QString qstr, argv;
    if (NOT list.isEmpty()){
        QStringList::iterator iter;
        argv = "";
        for (iter = list.begin(); iter != list.end(); iter++){
            qstr = *iter;
            argv += qstr + " ";
        }
//        ui->lineEdit->setText(argv);  It's not doing what I want when run thru Qt Creator.
    }
}

MainWindow::~MainWindow() { // destructor
    delete ui;
}


void WriteStack(Ui::MainWindow *ui) {

    calcPairType calcpair; // var calcpair calcPairType  using Go syntax
    ARRAYOF QString qstack[StackSize];

    IF OutputState == outputfix THEN
            // _, stackslice = GetResult("DUMPFIXED");
            calcpair = GetResult("DUMPFIXED");
    ELSIF OutputState == outputfloat THEN
            // _, stackslice = GetResult("DUMPFLOAT");
            calcpair = GetResult("DUMPFLOAT");
    ELSIF OutputState == outputgen THEN
            // _, stackslice = GetResult("DUMP");
            calcpair = GetResult("DUMP");
    ENDIF;

    ui->listWidget_Stack->clear();
    // assign stack of qstrings and write the string vectors listWidget_Stack
    for (int i = 0; i < StackSize; i++) {
        qstack[i] = qstack[i].fromStdString(calcpair.ss[i]);
        ui->listWidget_Stack->addItem(qstack[i]);
    }
} // WriteStack()

int FUNCTION GetRegIdx(char c) {
    int idx = 0;
    char ch;

    ch = CAP(c);
    if ((ch >= '0') AND (ch <= '9')) {
        idx = ch - '0';
    } else if ((ch >= 'A') AND (ch <= 'Z'))   {
        idx = ch - 'A' + 10;
    }
    return idx;
} // GetRegIdx

char FUNCTION GetRegChar(int i) {
    char ch = '\0';

    if ((i >= 0) AND (i <= 9)) {
        ch = '0' + i;
    } else if ((i >= 10) AND (i < 36)) {
        ch = 'A' + i - 10;
    }
    return ch;
} // GetRegChar

void WriteReg(Ui::MainWindow *ui) {
/*
 struct RegisterType {
    double value;
    QString name;
 };
ARRAYOF RegisterType Storage[36];  // var Storage []RegisterType  in Go syntax

enum OutputStateEnum {outputfix, outputfloat, outputgen};
OutputStateEnum OutputState = outputfix;
 */
  stringstream stream;

  stream << "The following registers are not zero.";
  for (int i = 0; i < 36; i++) {
      if (Storage[i].value != 0.) {
          stream << "Reg [" << GetRegChar(i) << "]: ";
          stream << Storage[i].name.toStdString() << "= ";
          if (OutputState == outputfix) {
              stream.setf(ios::fixed);
              stream.width(15);
              stream.precision(SigFig);
              stream << Storage[i].value << endl;

          } else if (OutputState == outputfloat) {
              stream.setf(ios::scientific);
              stream.width(15);
              stream.precision(SigFig);
              stream << Storage[i].value << endl;

          } else {
              string str;
              str = to_string(Storage[i].value);
              stream << str << endl;

          }

      }
  }
  stream.flush();
  ui->listWidget_Registers->clear();
  QString qstr = QString::fromStdString(stream.str());
  ui->listWidget_Registers->addItem(qstr);
} // WriteReg()

void WriteHelp(QWidget *parent) {  // this param is intended so that 'this' can be used in the QMessageBox call.
    stringstream stream;
    calcPairType calcpairvar;
    vector<string> stringslice;
    vector<string>::iterator iterate;

    calcpairvar = GetResult("HELP");

    IF NOT calcpairvar.ss.empty() THEN
      for (iterate = calcpairvar.ss.begin(); iterate != calcpairvar.ss.end(); iterate++) {
         stream << *iterate  << endl;
      }

      calcpairvar.ss.clear();
      stream.flush();

      QString qs = QString::fromStdString(stream.str());
      QMessageBox::information(parent,"Help", qs);
    ENDIF;
}

void FUNCTION repaint(Ui::MainWindow *ui) {
  WriteStack(ui);
  WriteReg(ui);
} // repaint()



void ProcessInput(QWidget *parent, Ui::MainWindow *ui, string cmdstr) {
    string LastCompiled = LastCompiledDate + " " + LastCompiledTime;
    calcPairType calcpair;
    vector<string> stringslice;
    vector<string>::iterator iter;

    PushStacks();

    // Write cmdstr to the history box, ie, listWidget_History.
    QString qs = QString::fromStdString(cmdstr);
    ui->listWidget_History->addItem(qs);

    if (cmdstr.compare("help") == 0) {
        WriteHelp(parent);
    } else {
        calcpair = GetResult(cmdstr);

        if (NOT calcpair.ss.empty()) {
            for (iter = calcpair.ss.begin(); iter != calcpair.ss.end(); iter++) {
                QString qstr = iter->c_str(); // recall that the -> operator is a type of dereference operator.
                ui->listWidget_Output->addItem(qstr);
            }
        }


        QString qR1, qR2, qR3, qRfix, qRfloat, qRgen;
        string str = to_string(calcpair.R);
        str = CropNStr(str);

        if (calcpair.R > 10000) str = AddCommas(str);

        qR1 = qR1.arg(str.c_str()); // this doesn't work
        qR2 = QString::fromStdString(str); // this is only line that works
        qR3 = qR3.arg(calcpair.R);  // this doesn't work
        qRgen = qRgen.arg(calcpair.R,0,'f',SigFig);// params are: double,int fieldwidth=0, char format='g', int precision= -1 ,QChar fillchar = QLatin1Char(' ').  Not working.
        qRfix = qRfix.arg(calcpair.R,0,'f',SigFig);  // more general form of the conversion which can use 'e', 'f' and sigfig.  Not working
        qRfloat = qRfloat.arg(calcpair.R,0,'f',SigFig);  // not working.
        QString qoutputline;
        qoutputline = "qR1= " + qR1 + ", qR2= " + qR2 + ", qR3= " + qR3 + ", qRgen= " + qRgen + ", qRfix= " + qRfix + ", qRfloat= " + qRfloat;
        ui->listWidget_Output->clear();
        ui->listWidget_Output->addItem(qoutputline);
    } // else from if input "help"

// I have to WriteStack, WriteReg, WriteHelp, output command line list, process some commands not run thru GetResult, like stoN, rclN, fix, float, gen, exit, quit, sigfig,
// have command not found error displayed
// if cmdstr is empty, display message to the output area to exit either type the commands exit, quit, or click the button.
// maybe I can use the menu structure to also change the output state and sigfig variables.

    repaint(ui);

    // clear the input lineedit before returning to it
    ui->lineEdit->clear();

}


void MainWindow::on_lineEdit_returnPressed() {
    QString inlineedit = ui->lineEdit->text();
    string inbuf = inlineedit.toStdString();
    inbuf = makesubst(inbuf);
    ProcessInput(this, ui, inbuf);
    //show();  not needed.
}

void MainWindow::on_pushButton_enter_clicked()
{
    QString inlineedit = ui->lineEdit->text();
    string inbuf = inlineedit.toStdString();
    inbuf = makesubst(inbuf);
    ProcessInput(this, ui, inbuf);
    //show();  not needed.
}

void MainWindow::on_pushButton_exit_clicked() {
    GETSTACK(Stk);
// need to write the file
    QApplication::quit();      // same as QCoreApplication::quit();

    // if the event loop is not running, these quit() commands will not work.  In that case, need to call exit(EXIT_FAILURE);
    exit(EXIT_FAILURE);
}

void MainWindow::on_pushButton_quit_clicked() {
    GETSTACK(Stk);
// need to write the file
    QApplication::quit();      // same as QCoreApplication::quit();

    // if the event loop is not running, these quit() commands will not work.  In that case, need to call exit(EXIT_FAILURE);
    exit(EXIT_FAILURE);
}

void MainWindow::on_action2_triggered() {
    SigFig = 0;
    GetResult("sig0");
}

void MainWindow::on_action4_triggered() {
    SigFig = 2;
    GetResult("sig2");
}

void MainWindow::on_action4_2_triggered() {
    SigFig = 4;
    GetResult("fix4");
}

void MainWindow::on_action6_triggered() {
    SigFig = 6;
    GetResult("fix6");
}

void MainWindow::on_action8_triggered() {
    SigFig = 8;
    GetResult("sig8");
}

void MainWindow::on_action_1_triggered() {
    SigFig = -1;
    GetResult("sig");
}

void MainWindow::on_actionfixed_triggered() {
    OutputState = outputfix;
}

void MainWindow::on_actionfloat_triggered() {
    OutputState = outputfloat;
}

void MainWindow::on_actiongen_triggered() {
    OutputState = outputgen;
}
