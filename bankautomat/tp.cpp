#include "tp.h"
#include "ui_tp.h"

Tp::Tp(QString id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tp)
{
    timerCounter=0;
    ui->setupUi(this);
    idKortti=id;

    objQTimer = new QTimer();

    connect(objQTimer, SIGNAL(timeout()),
            this, SLOT(TimerSlot()));

    objQTimer->start(1000);
}

Tp::~Tp()
{
    delete ui;
}
void Tp::TimerSlot()
{
    qDebug() << "Näytä Tp Timer.."<<timerCounter;
    timerCounter++;

    if(timerCounter==10) // sulkee formin jos ei paina nappeja 10 sekunttiin
        {
            objQTimer->stop();

            delete objQTimer;
            objQTimer = nullptr;

            this->close();

        }
}

void Tp::on_btntapahtumat_clicked()
{
    timerCounter=0;
    qDebug()<<"tapahtumat";
    QString site_url="http://localhost:3000/tilitapahtumat/"+idKortti;
        qDebug()<<"tilitapahtumat"+idKortti;
        //QString credentials="newAdmin:newPass";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //QByteArray data = credentials.toLocal8Bit().toBase64();
        //QString headerData = "Basic " + data;
        //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
        tilitapahtumatManager = new QNetworkAccessManager(this);
        connect(tilitapahtumatManager, SIGNAL(finished (QNetworkReply*)),
        this, SLOT(tilitapahtumatSlot(QNetworkReply*)));
        reply = tilitapahtumatManager->get(request);
}

void Tp::tilitapahtumatSlot(QNetworkReply *reply)
{

        qDebug()<< "tilitapahtumatSlot";
        QByteArray response_data=reply->readAll();

        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        qDebug()<<"jsoni dokki"<<json_doc;
        QJsonArray json_array = json_doc.array();
        qDebug()<<"jsoni array"<<json_array;
        QString tilitapahtumat;

        foreach (const QJsonValue &value, json_array) { //json_arraystä muutetaan tulostettavaan muotoon
        QJsonObject json_obj = value.toObject();
        qDebug()<<"jsoni obj"<<json_obj;
        tilitapahtumat+=QString(json_obj["Paivays"].toString())+" "+json_obj["Tapahtuma"].toString()+" "+QString::number(json_obj["Summa"].toDouble())+" "+json_obj["idKortti"].toString();


        }

        qDebug()<<tilitapahtumat;
        ui->textTapahtumat->setText(tilitapahtumat);
        reply->deleteLater();
        tilitapahtumatManager->deleteLater();
}

void Tp::on_btnSuljetapahtumat_clicked()
{
        timerCounter=0;
        objQTimer->stop();
        this->close();
}

