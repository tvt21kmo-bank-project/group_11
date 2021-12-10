#ifndef TP_H
#define TP_H

#include <QDialog>
#include <QtDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Tp;
}

class Tp : public QDialog
{
    Q_OBJECT

public:
    explicit Tp(QString id, QWidget *parent = nullptr);
    ~Tp();

private slots:
    void on_btntapahtumat_clicked();
    void tilitapahtumatSlot(QNetworkReply *reply);

    void on_btnSuljetapahtumat_clicked();
    void TimerSlot();
private:
    Ui::Tp *ui;
    QString idKortti;
    QNetworkAccessManager *tapahtumatManager;
    QNetworkAccessManager *tilitapahtumatManager;
    QNetworkReply *reply;
    QTimer *objQTimer;
    short timerCounter;
};

#endif // TP_H
