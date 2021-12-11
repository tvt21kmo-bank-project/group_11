#ifndef DEBITPANKKI_H
#define DEBITPANKKI_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class debitPankki;
}

class debitPankki : public QDialog
{
    Q_OBJECT

public:
    explicit debitPankki(QString idTili, QString idKortti, QWidget *parent = 0);
    ~debitPankki();


private slots:
    void on_btnDebitPankkiClose_clicked();
    void debitSlot(QNetworkReply *reply);
    void TimerSlot();

    void on_btnDebitPankkiSuorita_clicked();

    void on_btnDebitNosto10_clicked();

    void on_btnDebitNosto20_clicked();

    void on_btnDebitNosto40_clicked();

    void on_btnDebitNosto60_clicked();

    void on_btnDebitNosto100_clicked();

    void on_btnDebitNosto200_clicked();

    void on_btnDebitNosto500_clicked();

private:
    Ui::debitPankki *ui;
    QNetworkAccessManager *debitManager;
    QNetworkReply *reply;
    QString idTili;
    QString idKortti;
    QTimer *objQTimer;
    short timerCounter;
};

#endif // DEBITPANKKI_H
