#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <QFile>
#include <QFileDialog>
#include <QDataStream>
#include <QMessageBox>
#include <QDialog>
#include <QDialogButtonBox>

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

double R;
int I;
int sigfig = -1;
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
calcPairType calcpair;
vector<string> stringslice;
vector<string>::iterator iter;

Ui::MainWindow *ui;  //make ui global

enum OutputStateEnum {outputfix, outputfloat, outputgen};
OutputStateEnum OutputState = outputfix;

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
        ui->lineEdit->setText(argv);
    }
}

MainWindow::~MainWindow() { // destructor
    delete ui;
}


void MainWindow::on_lineEdit_returnPressed() {
    QString inlineedit = ui->lineEdit->text();
    string inbuf = inlineedit.toStdString();
    inbuf = makesubst(inbuf);
    ProcessInput(inbuf);

}

void MainWindow::on_pushButton_exit_clicked() {
    QString inlinedit = ui->lineEdit->text();
    string inbuf = inlinedit.toStdString();
    inbuf = makesubst(inbuf);
    ProcessInput(inbuf);
}

void WriteStack() {
    IF OutputState == outputfix THEN
            // _, stackslice = GetResult("DUMPFIXED");
    ELSIF OutputState == outputfloat THEN
            // _, stackslice = GetResult("DUMPFLOAT");
    ELSIF OutputState == outputgen THEN
            // _, stackslice = GetResult("DUMP");
    ENDIF;

    // write the string vector I called stringslice in hpcalcc2 to listWidget_Stack
}

void WriteReg() {

}

void WriteHelp() {

}


void ProcessInput(string cmdstr) {
    string LastCompiled = LastCompiledDate + " " + LastCompiledTime;

    PushStacks();

    calcpair = GetResult(cmdstr);

    if (NOT calcpair.ss.empty()) {
        for (iter = calcpair.ss.begin(); iter != calcpair.ss.end(); iter++) {
            QString qstr = iter->c_str(); // recall that the -> operator is a type of dereference operator.
            ui->listWidget_Output->addItem(qstr);
        }
    }
    QString qR1, qR2, qR3;
    string str = to_string(calcpair.R);
    str = CropNStr(str);

    if (calcpair.R > 10000) str = AddCommas(str);

    qR1 = qR1.arg(str.c_str());
    qR2 = QString::fromStdString(str);
    qR3 = qR3.arg(calcpair.R);
    // qR = qR.arg(calcpair.R,0,'g',-1,' ');  more general form of the conversion which can use 'e', 'f' and sigfig.
    // qR = qR.arg(calcpair.R,0,'g',sigfig);  more general form of the conversion which can use 'e', 'f' and sigfig.


// I have to WriteStack, WriteReg, WriteHelp, output command line list, process some commands not run thru GetResult, like stoN, rclN, fix, float, gen, exit, quit, sigfig,
// have command not found error displayed
// if cmdstr is empty, display message to the output area to exit either type the commands exit, quit, or click the button.
// maybe I can use the menu structure to also change the output state and sigfig variables.


}





void MainWindow::on_pushButton_quit_clicked()
{
    QApplication::quit();
    // same as QCoreApplication::quit();
    // if the event loop is not running, these quit() commands will not work.  In that case, need to call exit(EXIT_FAILURE);
    exit(EXIT_FAILURE);
}
