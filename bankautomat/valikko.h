#ifndef VALIKKO_H
#define VALIKKO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "pankki.h"
#include "saldo.h"
#include "tp.h"



namespace Ui {
class valikko;
}

class valikko : public QDialog
{
    Q_OBJECT

public:
    explicit valikko(QString idTili, QString idKortti, QString Etunimi, QString Sukunimi, QWidget *parent = 0);
    ~valikko();

private slots:

    void on_btnNostaRahaa_clicked();

    void on_btnNaytaSaldo_clicked();

    void on_btnSelaaTilitapahtumia_clicked();

    void on_btnKirjauduUlos_clicked();
    void TimerSlot();

private:
    Ui::valikko *ui;
    Pankki *objPankki;
    Saldo *objSaldo;
    Tp *objTilitapahtumat;
    QString idTili;
    QString idKortti;
    QString Etunimi;
    QString Sukunimi;
    QTimer *objQTimer;
    short timerCounter;
};

#endif // VALIKKO_H
