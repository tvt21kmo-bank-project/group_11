#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class Saldo;
}

class Saldo : public QDialog
{
    Q_OBJECT

public:
    explicit Saldo(QString idKortti, QWidget *parent = 0);
    ~Saldo();

private slots:
    void on_btnSaldoClose_clicked();
    void saldoSlot(QNetworkReply *reply);

    void on_btnNaytaSaldo_clicked();
    void TimerSlot();

private:

    Ui::Saldo *ui;
    QString idKortti;
    QNetworkAccessManager *saldoManager;
    QNetworkReply *reply;
    QTimer *objQTimer;
    short timerCounter;
};

#endif // SALDO_H
