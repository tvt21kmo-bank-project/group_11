#ifndef PANKKI_H
#define PANKKI_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Pankki;
}

class Pankki : public QDialog
{
    Q_OBJECT

public:
    explicit Pankki(QString idTili, QString idKortti, QWidget *parent = 0);
    ~Pankki();

private slots:
    void on_btnPankkiClose_clicked();
    void on_btnPankkiSuorita_clicked();

    void creditSlot(QNetworkReply *reply);
    void debitSlot(QNetworkReply *reply);

    void on_btnNosto_10_clicked();

    void on_btnNosto_20_clicked();

    void on_btnNosto_40_clicked();

    void on_btnNosto_60_clicked();

    void on_btnNosto_100_clicked();

    void on_btnNosto_200_clicked();

    void on_btnNosto_500_clicked();

private:
    Ui::Pankki *ui;
    QNetworkAccessManager *creditManager;
    QNetworkAccessManager *debitManager;
    QNetworkReply *reply;
    QString idTili;
    QString idKortti;

};

#endif // PANKKI_H
