#include "debitpankki.h"
#include "ui_debitpankki.h"

debitPankki::debitPankki(QString idTili, QString idKortti, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::debitPankki)
{
    timerCounter=0;
    ui->setupUi(this);
    this->idTili=idTili;
    this->idKortti=idKortti;
    qDebug()<<"pankki idTili "+this->idTili;
    qDebug()<<"pankki idKortti "+this->idKortti;

    objQTimer = new QTimer();

    // setup signal and slot
    connect(objQTimer, SIGNAL(timeout()),
            this, SLOT(TimerSlot()));

    objQTimer->start(1000);
}

debitPankki::~debitPankki()
{
    objQTimer->stop();
    delete ui;
}


void debitPankki::debitSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    if(response_data == "1"){
        objNosto=new Nosto(this->idKortti);
        objNosto->show();
        this->close();
        objQTimer->stop();

//        ui->labelDebitPankkiInfo->setText("Nosto onnistui!");
//        ui->leDebitSumma->setText("");
    }
    else {
        ui->labelDebitPankkiInfo->setText("Nosto epäonnistui, tilillä ei tarpeeksi katetta.");
        ui->leDebitSumma->setText("");
    }
}

void debitPankki::TimerSlot()
{
    qDebug() << "Debitin Nosta rahaa Timer.."<<timerCounter;
    timerCounter++;

    if(timerCounter==10) // sulkee formin jos paina nappeja 10 sekunttiin
        {
            objQTimer->stop();

            delete objQTimer;
            objQTimer = nullptr;

            this->close();
            //emit finishProgram();
        }
}


void debitPankki::on_btnDebitPankkiSuorita_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa",ui->leDebitSumma->text());
    QString site_url="http://localhost:3000/bank/debit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    debitManager = new QNetworkAccessManager(this);
    connect(debitManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(debitSlot(QNetworkReply*)));
    reply = debitManager->post(request, QJsonDocument(json).toJson());
    ui->labelDebitPankkiInfo->setText("");
}

void debitPankki::on_btnDebitNosto10_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","10");                                      //Tässä syötetään nappia vastaava rahasumma
    QString site_url="http://localhost:3000/bank/debit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    debitManager = new QNetworkAccessManager(this);
    connect(debitManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(debitSlot(QNetworkReply*)));
    reply = debitManager->post(request, QJsonDocument(json).toJson());     // jos ongelmia, lisää managereja jokaiselle
    ui->labelDebitPankkiInfo->setText("");
}

void debitPankki::on_btnDebitNosto20_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","20");                                      //Tässä syötetään nappia vastaava rahasumma
    QString site_url="http://localhost:3000/bank/debit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    debitManager = new QNetworkAccessManager(this);
    connect(debitManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(debitSlot(QNetworkReply*)));
    reply = debitManager->post(request, QJsonDocument(json).toJson());
    ui->labelDebitPankkiInfo->setText("");
}

void debitPankki::on_btnDebitNosto40_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","40");                                      //Tässä syötetään nappia vastaava rahasumma
    QString site_url="http://localhost:3000/bank/debit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    debitManager = new QNetworkAccessManager(this);
    connect(debitManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(debitSlot(QNetworkReply*)));
    reply = debitManager->post(request, QJsonDocument(json).toJson());
    ui->labelDebitPankkiInfo->setText("");
}

void debitPankki::on_btnDebitNosto60_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","60");                                      //Tässä syötetään nappia vastaava rahasumma
    QString site_url="http://localhost:3000/bank/debit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    debitManager = new QNetworkAccessManager(this);
    connect(debitManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(debitSlot(QNetworkReply*)));
    reply = debitManager->post(request, QJsonDocument(json).toJson());
    ui->labelDebitPankkiInfo->setText("");
}

void debitPankki::on_btnDebitNosto100_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","100");                                      //Tässä syötetään nappia vastaava rahasumma
    QString site_url="http://localhost:3000/bank/debit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    debitManager = new QNetworkAccessManager(this);
    connect(debitManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(debitSlot(QNetworkReply*)));
    reply = debitManager->post(request, QJsonDocument(json).toJson());
    ui->labelDebitPankkiInfo->setText("");
}

void debitPankki::on_btnDebitNosto200_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","200");                                      //Tässä syötetään nappia vastaava rahasumma
    QString site_url="http://localhost:3000/bank/debit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    debitManager = new QNetworkAccessManager(this);
    connect(debitManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(debitSlot(QNetworkReply*)));
    reply = debitManager->post(request, QJsonDocument(json).toJson());
    ui->labelDebitPankkiInfo->setText("");
}

void debitPankki::on_btnDebitNosto500_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","500");                                      //Tässä syötetään nappia vastaava rahasumma
    QString site_url="http://localhost:3000/bank/debit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    debitManager = new QNetworkAccessManager(this);
    connect(debitManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(debitSlot(QNetworkReply*)));
    reply = debitManager->post(request, QJsonDocument(json).toJson());
    ui->labelDebitPankkiInfo->setText("");
}
