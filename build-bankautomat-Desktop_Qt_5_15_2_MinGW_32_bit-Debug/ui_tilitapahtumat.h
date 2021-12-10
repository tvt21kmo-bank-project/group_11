/********************************************************************************
** Form generated from reading UI file 'tilitapahtumat.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILITAPAHTUMAT_H
#define UI_TILITAPAHTUMAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tilitapahtumat
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textTapahtumat;
    QPushButton *btnTapahtumat;
    QPushButton *btnTakaisin;

    void setupUi(QDialog *Tilitapahtumat)
    {
        if (Tilitapahtumat->objectName().isEmpty())
            Tilitapahtumat->setObjectName(QString::fromUtf8("Tilitapahtumat"));
        Tilitapahtumat->resize(620, 468);
        pushButton = new QPushButton(Tilitapahtumat);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 360, 80, 21));
        widget = new QWidget(Tilitapahtumat);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(7, 20, 601, 248));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textTapahtumat = new QTextEdit(widget);
        textTapahtumat->setObjectName(QString::fromUtf8("textTapahtumat"));

        verticalLayout->addWidget(textTapahtumat);

        btnTapahtumat = new QPushButton(widget);
        btnTapahtumat->setObjectName(QString::fromUtf8("btnTapahtumat"));

        verticalLayout->addWidget(btnTapahtumat);

        btnTakaisin = new QPushButton(widget);
        btnTakaisin->setObjectName(QString::fromUtf8("btnTakaisin"));

        verticalLayout->addWidget(btnTakaisin);


        retranslateUi(Tilitapahtumat);

        QMetaObject::connectSlotsByName(Tilitapahtumat);
    } // setupUi

    void retranslateUi(QDialog *Tilitapahtumat)
    {
        Tilitapahtumat->setWindowTitle(QCoreApplication::translate("Tilitapahtumat", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Tilitapahtumat", "PushButton", nullptr));
        btnTapahtumat->setText(QCoreApplication::translate("Tilitapahtumat", "Tapahtumat", nullptr));
        btnTakaisin->setText(QCoreApplication::translate("Tilitapahtumat", "Takaisin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tilitapahtumat: public Ui_Tilitapahtumat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILITAPAHTUMAT_H
