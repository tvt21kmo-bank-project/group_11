/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEditKorttinumero;
    QLineEdit *lineEditPIN;
    QPushButton *btnLogin;
    QPushButton *btnLoginClose;
    QLabel *labelLoginInfo;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1840, 955);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEditKorttinumero = new QLineEdit(centralWidget);
        lineEditKorttinumero->setObjectName(QString::fromUtf8("lineEditKorttinumero"));
        lineEditKorttinumero->setGeometry(QRect(730, 270, 201, 31));
        QFont font;
        font.setPointSize(14);
        lineEditKorttinumero->setFont(font);
        lineEditPIN = new QLineEdit(centralWidget);
        lineEditPIN->setObjectName(QString::fromUtf8("lineEditPIN"));
        lineEditPIN->setGeometry(QRect(730, 320, 201, 31));
        lineEditPIN->setFont(font);
        lineEditPIN->setEchoMode(QLineEdit::Password);
        btnLogin = new QPushButton(centralWidget);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(780, 370, 91, 61));
        QFont font1;
        font1.setPointSize(18);
        btnLogin->setFont(font1);
        btnLoginClose = new QPushButton(centralWidget);
        btnLoginClose->setObjectName(QString::fromUtf8("btnLoginClose"));
        btnLoginClose->setGeometry(QRect(960, 620, 121, 41));
        labelLoginInfo = new QLabel(centralWidget);
        labelLoginInfo->setObjectName(QString::fromUtf8("labelLoginInfo"));
        labelLoginInfo->setGeometry(QRect(720, 490, 221, 41));
        QFont font2;
        font2.setPointSize(12);
        labelLoginInfo->setFont(font2);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(600, 270, 131, 21));
        label->setFont(font2);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(650, 320, 71, 20));
        label_2->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1840, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnLogin->setText(QCoreApplication::translate("MainWindow", "Log in", nullptr));
        btnLoginClose->setText(QCoreApplication::translate("MainWindow", "Lopeta", nullptr));
        labelLoginInfo->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Korttinumero", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "PIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
