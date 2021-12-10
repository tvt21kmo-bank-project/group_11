#ifndef VALIKKO_H
#define VALIKKO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "pankki.h"
#include "saldo.h"

namespace Ui {
class valikko;
}

class valikko : public QDialog
{
    Q_OBJECT

public:
    explicit valikko(QString idTili, QString idKortti, QWidget *parent = 0);
    ~valikko();

private slots:
    void on_btnValikkoClose_clicked();

    void on_btnValitseTili_clicked();

    void on_btnNostaRahaa_clicked();

    void on_btnNaytaSaldo_clicked();

    void on_btnSelaaTilitapahtumia_clicked();

    void on_btnKirjauduUlos_clicked();
    void TimerSlot();

private:
    Ui::valikko *ui;
    Pankki *objPankki;
    Saldo *objSaldo;
    QString idTili;
    QString idKortti;
    QTimer *objQTimer;
    short timerCounter;
};

#endif // VALIKKO_H
