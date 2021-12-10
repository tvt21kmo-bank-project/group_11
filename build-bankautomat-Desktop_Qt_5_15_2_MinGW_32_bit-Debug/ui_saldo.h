/********************************************************************************
** Form generated from reading UI file 'saldo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALDO_H
#define UI_SALDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Saldo
{
public:
    QPushButton *btnSaldoClose;
    QPushButton *btnNaytaSaldo;
    QTextEdit *txtSaldo;

    void setupUi(QDialog *Saldo)
    {
        if (Saldo->objectName().isEmpty())
            Saldo->setObjectName(QString::fromUtf8("Saldo"));
        Saldo->resize(593, 514);
        btnSaldoClose = new QPushButton(Saldo);
        btnSaldoClose->setObjectName(QString::fromUtf8("btnSaldoClose"));
        btnSaldoClose->setGeometry(QRect(350, 230, 75, 23));
        btnNaytaSaldo = new QPushButton(Saldo);
        btnNaytaSaldo->setObjectName(QString::fromUtf8("btnNaytaSaldo"));
        btnNaytaSaldo->setGeometry(QRect(90, 230, 75, 23));
        txtSaldo = new QTextEdit(Saldo);
        txtSaldo->setObjectName(QString::fromUtf8("txtSaldo"));
        txtSaldo->setGeometry(QRect(50, 30, 441, 121));
        QFont font;
        font.setPointSize(20);
        txtSaldo->setFont(font);

        retranslateUi(Saldo);

        QMetaObject::connectSlotsByName(Saldo);
    } // setupUi

    void retranslateUi(QDialog *Saldo)
    {
        Saldo->setWindowTitle(QCoreApplication::translate("Saldo", "Dialog", nullptr));
        btnSaldoClose->setText(QCoreApplication::translate("Saldo", "Sulje", nullptr));
        btnNaytaSaldo->setText(QCoreApplication::translate("Saldo", "N\303\244yt\303\244 Saldo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Saldo: public Ui_Saldo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALDO_H
