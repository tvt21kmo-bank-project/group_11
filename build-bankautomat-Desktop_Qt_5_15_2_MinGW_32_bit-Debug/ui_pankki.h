/********************************************************************************
** Form generated from reading UI file 'pankki.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANKKI_H
#define UI_PANKKI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Pankki
{
public:
    QPushButton *btnPankkiClose;
    QLineEdit *le_Summa;
    QLabel *label_3;
    QPushButton *btnPankkiSuorita;
    QLabel *labelPankkiInfo;
    QPushButton *btnNosto_10;
    QPushButton *btnNosto_20;
    QPushButton *btnNosto_40;
    QPushButton *btnNosto_60;
    QPushButton *btnNosto_100;
    QPushButton *btnNosto_200;
    QPushButton *btnNosto_500;

    void setupUi(QDialog *Pankki)
    {
        if (Pankki->objectName().isEmpty())
            Pankki->setObjectName(QString::fromUtf8("Pankki"));
        Pankki->resize(1196, 800);
        btnPankkiClose = new QPushButton(Pankki);
        btnPankkiClose->setObjectName(QString::fromUtf8("btnPankkiClose"));
        btnPankkiClose->setGeometry(QRect(940, 710, 141, 41));
        le_Summa = new QLineEdit(Pankki);
        le_Summa->setObjectName(QString::fromUtf8("le_Summa"));
        le_Summa->setGeometry(QRect(390, 370, 113, 20));
        label_3 = new QLabel(Pankki);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(390, 330, 91, 16));
        btnPankkiSuorita = new QPushButton(Pankki);
        btnPankkiSuorita->setObjectName(QString::fromUtf8("btnPankkiSuorita"));
        btnPankkiSuorita->setGeometry(QRect(520, 340, 161, 51));
        labelPankkiInfo = new QLabel(Pankki);
        labelPankkiInfo->setObjectName(QString::fromUtf8("labelPankkiInfo"));
        labelPankkiInfo->setGeometry(QRect(90, 410, 471, 61));
        QFont font;
        font.setPointSize(14);
        labelPankkiInfo->setFont(font);
        btnNosto_10 = new QPushButton(Pankki);
        btnNosto_10->setObjectName(QString::fromUtf8("btnNosto_10"));
        btnNosto_10->setGeometry(QRect(220, 90, 141, 61));
        btnNosto_20 = new QPushButton(Pankki);
        btnNosto_20->setObjectName(QString::fromUtf8("btnNosto_20"));
        btnNosto_20->setGeometry(QRect(380, 90, 141, 61));
        btnNosto_40 = new QPushButton(Pankki);
        btnNosto_40->setObjectName(QString::fromUtf8("btnNosto_40"));
        btnNosto_40->setGeometry(QRect(220, 170, 141, 61));
        btnNosto_60 = new QPushButton(Pankki);
        btnNosto_60->setObjectName(QString::fromUtf8("btnNosto_60"));
        btnNosto_60->setGeometry(QRect(380, 170, 141, 61));
        btnNosto_100 = new QPushButton(Pankki);
        btnNosto_100->setObjectName(QString::fromUtf8("btnNosto_100"));
        btnNosto_100->setGeometry(QRect(220, 250, 141, 61));
        btnNosto_200 = new QPushButton(Pankki);
        btnNosto_200->setObjectName(QString::fromUtf8("btnNosto_200"));
        btnNosto_200->setGeometry(QRect(380, 250, 141, 61));
        btnNosto_500 = new QPushButton(Pankki);
        btnNosto_500->setObjectName(QString::fromUtf8("btnNosto_500"));
        btnNosto_500->setGeometry(QRect(220, 330, 141, 61));

        retranslateUi(Pankki);

        QMetaObject::connectSlotsByName(Pankki);
    } // setupUi

    void retranslateUi(QDialog *Pankki)
    {
        Pankki->setWindowTitle(QCoreApplication::translate("Pankki", "Dialog", nullptr));
        btnPankkiClose->setText(QCoreApplication::translate("Pankki", "Close", nullptr));
        label_3->setText(QCoreApplication::translate("Pankki", "Muu Summa", nullptr));
        btnPankkiSuorita->setText(QCoreApplication::translate("Pankki", "Suorita Muu Summa", nullptr));
        labelPankkiInfo->setText(QString());
        btnNosto_10->setText(QCoreApplication::translate("Pankki", "10", nullptr));
        btnNosto_20->setText(QCoreApplication::translate("Pankki", "20", nullptr));
        btnNosto_40->setText(QCoreApplication::translate("Pankki", "40", nullptr));
        btnNosto_60->setText(QCoreApplication::translate("Pankki", "60", nullptr));
        btnNosto_100->setText(QCoreApplication::translate("Pankki", "100", nullptr));
        btnNosto_200->setText(QCoreApplication::translate("Pankki", "200", nullptr));
        btnNosto_500->setText(QCoreApplication::translate("Pankki", "500", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pankki: public Ui_Pankki {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANKKI_H
