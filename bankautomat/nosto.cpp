#include "nosto.h"
#include "ui_nosto.h"

Nosto::Nosto(QString idKortti, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nosto)
{
    timerCounter=0;
    this->idKortti=idKortti;
    ui->setupUi(this);
    qDebug()<<"Saldo "+this->idKortti;

    objQTimer = new QTimer();

    connect(objQTimer, SIGNAL(timeout()),
            this, SLOT(TimerSlot()));

    objQTimer->start(1000);
}

Nosto::~Nosto()
{
    delete ui;
}

void Nosto::TimerSlot()
{
    qDebug() << "Näytä Nosto Timer.."<<timerCounter;
    timerCounter++;

    if(timerCounter==10) // sulkee formin jos paina nappeja 10 sekunttiin
        {
            objQTimer->stop();

            delete objQTimer;
            objQTimer = nullptr;

            this->close();

        }
}

void Nosto::on_btnNostoClose_clicked()
{
    objQTimer->stop();
    this->close();
}

void Nosto::nostoSlot(QNetworkReply *reply)
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
        saldo+="\rSaldonne on: "+QString::number(json_obj["Saldo"].toDouble());


        }

        qDebug()<<saldo;
        ui->txtNosto->setText(saldo);
        reply->deleteLater();
        nostoManager->deleteLater();
}

void Nosto::on_btnNostoSaldo_clicked()
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
    nostoManager = new QNetworkAccessManager(this);
    connect(nostoManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(nostoSlot(QNetworkReply*)));
    reply = nostoManager->get(request);
}
