#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Nosto;
}

class Nosto : public QDialog
{
    Q_OBJECT

public:
    explicit Nosto(QString idKortti, QWidget *parent = 0);
    ~Nosto();

private slots:
    void on_btnNostoClose_clicked();
    void nostoSlot(QNetworkReply *reply);
    void on_btnNostoSaldo_clicked();
    void TimerSlot();

private:
    Ui::Nosto *ui;
    QString idKortti;
    QNetworkAccessManager *nostoManager;
    QNetworkReply *reply;
    QTimer *objQTimer;
    short timerCounter;
};

#endif // NOSTO_H
