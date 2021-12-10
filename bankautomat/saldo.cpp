#include "saldo.h"
#include "ui_saldo.h"

Saldo::Saldo(QString idKortti, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Saldo)
{
    timerCounter=0;
    this->idKortti=idKortti;
    ui->setupUi(this);
    qDebug()<<"Saldo "+this->idKortti;

    objQTimer = new QTimer();

    // setup signal and slot
    connect(objQTimer, SIGNAL(timeout()),
            this, SLOT(TimerSlot()));

    objQTimer->start(1000);



}

Saldo::~Saldo()
{
    delete ui;
}
void Saldo::TimerSlot()
{
    qDebug() << "Näytä Saldo Timer.."<<timerCounter;
    timerCounter++;

    if(timerCounter==10) // sulkee formin jos paina nappeja 10 sekunttiin
        {
            objQTimer->stop();

            delete objQTimer;
            objQTimer = nullptr;

            this->close();

        }
}

void Saldo::on_btnSaldoClose_clicked()
{
    objQTimer->stop();
    this->close();
}

void Saldo::saldoSlot(QNetworkReply *reply)
{


        QByteArray response_data=reply->readAll();

        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        qDebug()<<"jsoni dokki"<<json_doc;
        QJsonArray json_array = json_doc.array();
        qDebug()<<"jsoni array"<<json_array;
        QString saldo;

        foreach (const QJsonValue &value, json_array) { //json_arraystä muutetaan tulostettavaan muotoon
        QJsonObject json_obj = value.toObject();
        qDebug()<<"jsoni obj"<<json_obj;
        saldo+=QString(json_obj["Etunimi"].toString())+" "+json_obj["Sukunimi"].toString()+"\rSaldonne on: "+QString::number(json_obj["Saldo"].toDouble());


        }

        qDebug()<<saldo;
        ui->txtSaldo->setText(saldo);
        reply->deleteLater();
        saldoManager->deleteLater();
}

void Saldo::on_btnNaytaSaldo_clicked()
{
    timerCounter=0;


        QString site_url="http://localhost:3000/saldo/"+idKortti;
        qDebug()<<idKortti;
        //QString credentials="newAdmin:newPass";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //QByteArray data = credentials.toLocal8Bit().toBase64();
        //QString headerData = "Basic " + data;
        //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
        saldoManager = new QNetworkAccessManager(this);
        connect(saldoManager, SIGNAL(finished (QNetworkReply*)),
        this, SLOT(saldoSlot(QNetworkReply*)));
        reply = saldoManager->get(request);
}


