/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action2;
    QAction *action4;
    QAction *action4_2;
    QAction *action6;
    QAction *action8;
    QAction *action_1;
    QAction *actionfixed;
    QAction *actionfloat;
    QAction *actiongen;
    QAction *actionClear_Output;
    QWidget *centralwidget;
    QListWidget *listWidget_Stack;
    QListWidget *listWidget_Registers;
    QListWidget *listWidget_Output;
    QListWidget *listWidget_History;
    QPushButton *pushButton_quit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_enter;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_exit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_T1;
    QLabel *label_T2;
    QLabel *label_T3;
    QLabel *label_T4;
    QLabel *label_T5;
    QLabel *label_Z;
    QLabel *label_Y;
    QLabel *label_X;
    QMenuBar *menubar;
    QMenu *menusigfig;
    QMenu *menuOutputState;
    QMenu *menuClear_Output_Area;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(861, 669);
        action2 = new QAction(MainWindow);
        action2->setObjectName(QStringLiteral("action2"));
        action4 = new QAction(MainWindow);
        action4->setObjectName(QStringLiteral("action4"));
        action4_2 = new QAction(MainWindow);
        action4_2->setObjectName(QStringLiteral("action4_2"));
        action6 = new QAction(MainWindow);
        action6->setObjectName(QStringLiteral("action6"));
        action8 = new QAction(MainWindow);
        action8->setObjectName(QStringLiteral("action8"));
        action_1 = new QAction(MainWindow);
        action_1->setObjectName(QStringLiteral("action_1"));
        actionfixed = new QAction(MainWindow);
        actionfixed->setObjectName(QStringLiteral("actionfixed"));
        actionfloat = new QAction(MainWindow);
        actionfloat->setObjectName(QStringLiteral("actionfloat"));
        actiongen = new QAction(MainWindow);
        actiongen->setObjectName(QStringLiteral("actiongen"));
        actionClear_Output = new QAction(MainWindow);
        actionClear_Output->setObjectName(QStringLiteral("actionClear_Output"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        listWidget_Stack = new QListWidget(centralwidget);
        listWidget_Stack->setObjectName(QStringLiteral("listWidget_Stack"));
        listWidget_Stack->setGeometry(QRect(40, 70, 451, 241));
        QFont font;
        font.setPointSize(12);
        listWidget_Stack->setFont(font);
        listWidget_Registers = new QListWidget(centralwidget);
        listWidget_Registers->setObjectName(QStringLiteral("listWidget_Registers"));
        listWidget_Registers->setGeometry(QRect(50, 330, 441, 192));
        listWidget_Output = new QListWidget(centralwidget);
        listWidget_Output->setObjectName(QStringLiteral("listWidget_Output"));
        listWidget_Output->setGeometry(QRect(50, 530, 781, 91));
        listWidget_History = new QListWidget(centralwidget);
        listWidget_History->setObjectName(QStringLiteral("listWidget_History"));
        listWidget_History->setGeometry(QRect(510, 70, 321, 451));
        pushButton_quit = new QPushButton(centralwidget);
        pushButton_quit->setObjectName(QStringLiteral("pushButton_quit"));
        pushButton_quit->setGeometry(QRect(760, 20, 101, 31));
        pushButton_quit->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 731, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton_enter = new QPushButton(layoutWidget);
        pushButton_enter->setObjectName(QStringLiteral("pushButton_enter"));
        pushButton_enter->setFont(font);

        horizontalLayout->addWidget(pushButton_enter);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_exit = new QPushButton(layoutWidget);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setFont(font);

        horizontalLayout_2->addWidget(pushButton_exit);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 70, 17, 231));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_T1 = new QLabel(layoutWidget1);
        label_T1->setObjectName(QStringLiteral("label_T1"));

        verticalLayout->addWidget(label_T1);

        label_T2 = new QLabel(layoutWidget1);
        label_T2->setObjectName(QStringLiteral("label_T2"));

        verticalLayout->addWidget(label_T2);

        label_T3 = new QLabel(layoutWidget1);
        label_T3->setObjectName(QStringLiteral("label_T3"));

        verticalLayout->addWidget(label_T3);

        label_T4 = new QLabel(layoutWidget1);
        label_T4->setObjectName(QStringLiteral("label_T4"));

        verticalLayout->addWidget(label_T4);

        label_T5 = new QLabel(layoutWidget1);
        label_T5->setObjectName(QStringLiteral("label_T5"));

        verticalLayout->addWidget(label_T5);

        label_Z = new QLabel(layoutWidget1);
        label_Z->setObjectName(QStringLiteral("label_Z"));

        verticalLayout->addWidget(label_Z);

        label_Y = new QLabel(layoutWidget1);
        label_Y->setObjectName(QStringLiteral("label_Y"));

        verticalLayout->addWidget(label_Y);

        label_X = new QLabel(layoutWidget1);
        label_X->setObjectName(QStringLiteral("label_X"));
        label_X->setFont(font);

        verticalLayout->addWidget(label_X);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 861, 21));
        menusigfig = new QMenu(menubar);
        menusigfig->setObjectName(QStringLiteral("menusigfig"));
        menuOutputState = new QMenu(menubar);
        menuOutputState->setObjectName(QStringLiteral("menuOutputState"));
        menuClear_Output_Area = new QMenu(menubar);
        menuClear_Output_Area->setObjectName(QStringLiteral("menuClear_Output_Area"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menusigfig->menuAction());
        menubar->addAction(menuOutputState->menuAction());
        menubar->addAction(menuClear_Output_Area->menuAction());
        menusigfig->addAction(action2);
        menusigfig->addAction(action4);
        menusigfig->addAction(action4_2);
        menusigfig->addAction(action6);
        menusigfig->addAction(action8);
        menusigfig->addAction(action_1);
        menuOutputState->addAction(actionfixed);
        menuOutputState->addAction(actionfloat);
        menuOutputState->addAction(actiongen);
        menuClear_Output_Area->addAction(actionClear_Output);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action2->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        action4->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        action4_2->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        action6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        action8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        action_1->setText(QApplication::translate("MainWindow", "-1", Q_NULLPTR));
        actionfixed->setText(QApplication::translate("MainWindow", "fixed", Q_NULLPTR));
        actionfloat->setText(QApplication::translate("MainWindow", "float", Q_NULLPTR));
        actiongen->setText(QApplication::translate("MainWindow", "gen", Q_NULLPTR));
        actionClear_Output->setText(QApplication::translate("MainWindow", "Clear Output", Q_NULLPTR));
        pushButton_quit->setText(QApplication::translate("MainWindow", "Quit, no save", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Enter command or help", Q_NULLPTR));
        pushButton_enter->setText(QApplication::translate("MainWindow", "enter", Q_NULLPTR));
        pushButton_exit->setText(QApplication::translate("MainWindow", "exit", Q_NULLPTR));
        label_T1->setText(QApplication::translate("MainWindow", "T1", Q_NULLPTR));
        label_T2->setText(QApplication::translate("MainWindow", "T2", Q_NULLPTR));
        label_T3->setText(QApplication::translate("MainWindow", "T3", Q_NULLPTR));
        label_T4->setText(QApplication::translate("MainWindow", "T4", Q_NULLPTR));
        label_T5->setText(QApplication::translate("MainWindow", "T5", Q_NULLPTR));
        label_Z->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        label_Y->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_X->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        menusigfig->setTitle(QApplication::translate("MainWindow", "sigfig", Q_NULLPTR));
        menuOutputState->setTitle(QApplication::translate("MainWindow", "OutputState", Q_NULLPTR));
        menuClear_Output_Area->setTitle(QApplication::translate("MainWindow", "Clear Output Area", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
