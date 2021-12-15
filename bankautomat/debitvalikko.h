#ifndef DEBITVALIKKO_H
#define DEBITVALIKKO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "pankki.h"
#include "saldo.h"
#include "tp.h"
#include "debitpankki.h"

namespace Ui {
class debitValikko;
}

class debitValikko : public QDialog
{
    Q_OBJECT

public:
    explicit debitValikko(QString idTili, QString idKortti, QString Etunimi, QString Sukunimi, QWidget *parent = 0);
    ~debitValikko();

private slots:

    void on_btnDebitValikkoNosto_clicked();

    void on_btnDebitValikkoSaldo_clicked();

    void on_btnDebitValikkoTilitapah_clicked();

    void on_btnDebitValikkoKirjauduUlos_clicked();

    void TimerSlot();

private:
    Ui::debitValikko *ui;
    //Pankki *objPankki;
    debitPankki *objDebitPankki;
    Saldo *objSaldo;
    Tp *objTilitapahtumat;
    QString idTili;
    QString idKortti;
    QString Etunimi;
    QString Sukunimi;
    QTimer *objDQTimer;
    short timerCounter;
};

#endif // DEBITVALIKKO_H
