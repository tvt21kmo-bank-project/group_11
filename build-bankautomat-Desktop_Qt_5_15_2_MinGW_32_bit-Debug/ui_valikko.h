/********************************************************************************
** Form generated from reading UI file 'valikko.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALIKKO_H
#define UI_VALIKKO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_valikko
{
public:
    QLabel *label;
    QPushButton *btnValikkoClose;
    QLabel *labelValikkoAsiakas;
    QPushButton *btnValitseTili;
    QPushButton *btnNostaRahaa;
    QPushButton *btnNaytaSaldo;
    QPushButton *btnSelaaTilitapahtumia;
    QPushButton *btnKirjauduUlos;

    void setupUi(QDialog *valikko)
    {
        if (valikko->objectName().isEmpty())
            valikko->setObjectName(QString::fromUtf8("valikko"));
        valikko->resize(1835, 945);
        label = new QLabel(valikko);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(780, 40, 301, 71));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        btnValikkoClose = new QPushButton(valikko);
        btnValikkoClose->setObjectName(QString::fromUtf8("btnValikkoClose"));
        btnValikkoClose->setGeometry(QRect(1480, 800, 141, 41));
        labelValikkoAsiakas = new QLabel(valikko);
        labelValikkoAsiakas->setObjectName(QString::fromUtf8("labelValikkoAsiakas"));
        labelValikkoAsiakas->setGeometry(QRect(1000, 60, 191, 31));
        labelValikkoAsiakas->setFont(font);
        btnValitseTili = new QPushButton(valikko);
        btnValitseTili->setObjectName(QString::fromUtf8("btnValitseTili"));
        btnValitseTili->setGeometry(QRect(690, 240, 181, 71));
        btnNostaRahaa = new QPushButton(valikko);
        btnNostaRahaa->setObjectName(QString::fromUtf8("btnNostaRahaa"));
        btnNostaRahaa->setGeometry(QRect(910, 240, 181, 71));
        btnNaytaSaldo = new QPushButton(valikko);
        btnNaytaSaldo->setObjectName(QString::fromUtf8("btnNaytaSaldo"));
        btnNaytaSaldo->setGeometry(QRect(690, 340, 181, 71));
        btnSelaaTilitapahtumia = new QPushButton(valikko);
        btnSelaaTilitapahtumia->setObjectName(QString::fromUtf8("btnSelaaTilitapahtumia"));
        btnSelaaTilitapahtumia->setGeometry(QRect(910, 340, 181, 71));
        btnKirjauduUlos = new QPushButton(valikko);
        btnKirjauduUlos->setObjectName(QString::fromUtf8("btnKirjauduUlos"));
        btnKirjauduUlos->setGeometry(QRect(790, 450, 181, 71));

        retranslateUi(valikko);

        QMetaObject::connectSlotsByName(valikko);
    } // setupUi

    void retranslateUi(QDialog *valikko)
    {
        valikko->setWindowTitle(QCoreApplication::translate("valikko", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("valikko", "Tervetuloa", nullptr));
        btnValikkoClose->setText(QCoreApplication::translate("valikko", "Close", nullptr));
        labelValikkoAsiakas->setText(QString());
        btnValitseTili->setText(QCoreApplication::translate("valikko", "Valitse tili", nullptr));
        btnNostaRahaa->setText(QCoreApplication::translate("valikko", "Nosta rahaa", nullptr));
        btnNaytaSaldo->setText(QCoreApplication::translate("valikko", "N\303\244yt\303\244 saldo", nullptr));
        btnSelaaTilitapahtumia->setText(QCoreApplication::translate("valikko", "Selaa tilitapahtumia", nullptr));
        btnKirjauduUlos->setText(QCoreApplication::translate("valikko", "Kirjaudu ulos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class valikko: public Ui_valikko {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALIKKO_H
