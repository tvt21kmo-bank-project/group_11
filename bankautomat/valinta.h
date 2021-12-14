#ifndef VALINTA_H
#define VALINTA_H

#include <QDialog>
#include "valikko.h"
#include "debitvalikko.h"

namespace Ui {
class Valinta;
}

class Valinta : public QDialog
{
    Q_OBJECT

public:
    explicit Valinta(QString idTili, QString idKortti,QWidget *parent = 0);
    ~Valinta();

private slots:
    void on_btnCreditValinta_clicked();

    void on_btnDebitValinta_clicked();

    void on_btnValintaClose_clicked();
    void TimerSlot();

private:
    Ui::Valinta *ui;
    valikko *objValikko;
    debitValikko *objDebitValikko;
    QString idTili;
    QString idKortti;
    QTimer *objQTimer;
    short timerCounter;
};

#endif // VALINTA_H
