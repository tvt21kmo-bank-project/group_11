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
    explicit Pankki(QWidget *parent = 0);
    ~Pankki();

private slots:
    void on_btnPankkiClose_clicked();
    void on_btnPankkiSuorita_clicked();

    void creditSlot(QNetworkReply *reply);
    void debitSlot(QNetworkReply *reply);

private:
    Ui::Pankki *ui;
    QNetworkAccessManager *creditManager;
    QNetworkAccessManager *debitManager;
    QNetworkReply *reply;

};

#endif // PANKKI_H
