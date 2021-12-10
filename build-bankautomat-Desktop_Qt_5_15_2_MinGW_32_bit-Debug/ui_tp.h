/********************************************************************************
** Form generated from reading UI file 'tp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP_H
#define UI_TP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tp
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textTapahtumat;
    QPushButton *btnSuljetapahtumat;
    QPushButton *btntapahtumat;

    void setupUi(QDialog *Tp)
    {
        if (Tp->objectName().isEmpty())
            Tp->setObjectName(QString::fromUtf8("Tp"));
        Tp->resize(1161, 643);
        widget = new QWidget(Tp);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(270, 60, 291, 511));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textTapahtumat = new QTextEdit(widget);
        textTapahtumat->setObjectName(QString::fromUtf8("textTapahtumat"));

        verticalLayout->addWidget(textTapahtumat);

        btnSuljetapahtumat = new QPushButton(widget);
        btnSuljetapahtumat->setObjectName(QString::fromUtf8("btnSuljetapahtumat"));

        verticalLayout->addWidget(btnSuljetapahtumat);

        btntapahtumat = new QPushButton(widget);
        btntapahtumat->setObjectName(QString::fromUtf8("btntapahtumat"));

        verticalLayout->addWidget(btntapahtumat);


        retranslateUi(Tp);

        QMetaObject::connectSlotsByName(Tp);
    } // setupUi

    void retranslateUi(QDialog *Tp)
    {
        Tp->setWindowTitle(QCoreApplication::translate("Tp", "Dialog", nullptr));
        btnSuljetapahtumat->setText(QCoreApplication::translate("Tp", "Sulje", nullptr));
        btntapahtumat->setText(QCoreApplication::translate("Tp", "Tapahtumat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tp: public Ui_Tp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP_H
