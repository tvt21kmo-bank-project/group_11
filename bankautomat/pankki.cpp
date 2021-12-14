#include "pankki.h"
#include "ui_pankki.h"

Pankki::Pankki(QString idTili, QString idKortti, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pankki)
{
    timerCounter=0;
    this->idTili=idTili;
    this->idKortti=idKortti;
    ui->setupUi(this);
    qDebug()<<"pankki idTili "+this->idTili;
    qDebug()<<"pankki idKortti "+this->idKortti;
    objQTimer = new QTimer();

    // setup signal and slot
    connect(objQTimer, SIGNAL(timeout()),
            this, SLOT(TimerSlot()));

    objQTimer->start(1000);

}

Pankki::~Pankki()
{
    delete ui;
}

void Pankki::TimerSlot()
{
    qDebug() << "Nosta rahaa Timer.."<<timerCounter;
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


void Pankki::on_btnPankkiClose_clicked()
{
    objQTimer->stop();
    this->close();
}

void Pankki::on_btnPankkiSuorita_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa",ui->le_Summa->text());
    QString site_url="http://localhost:3000/bank/credit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    creditManager = new QNetworkAccessManager(this);
    connect(creditManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(creditSlot(QNetworkReply*)));
    reply = creditManager->post(request, QJsonDocument(json).toJson());
    ui->labelPankkiInfo->setText("");
}

void Pankki::creditSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    if(response_data == "1"){
        ui->labelPankkiInfo->setText("Nosto Onnistui!");
        ui->le_Summa->setText("");
    }
    else {
        ui->labelPankkiInfo->setText("Nosto epäonnistui, tilillä ei tarpeeksi katetta.");
        ui->le_Summa->setText("");
    }
}


void Pankki::on_btnNosto_10_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","10");                                      //Tässä syötetään nappia vastaava rahasumma
    QString site_url="http://localhost:3000/bank/credit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    creditManager = new QNetworkAccessManager(this);
    connect(creditManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(creditSlot(QNetworkReply*)));
    reply = creditManager->post(request, QJsonDocument(json).toJson());     // jos ongelmia, lisää managereja jokaiselle
    ui->labelPankkiInfo->setText("");
}

void Pankki::on_btnNosto_20_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","20");
    QString site_url="http://localhost:3000/bank/credit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    creditManager = new QNetworkAccessManager(this);
    connect(creditManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(creditSlot(QNetworkReply*)));
    reply = creditManager->post(request, QJsonDocument(json).toJson());
    ui->labelPankkiInfo->setText("");
}

void Pankki::on_btnNosto_40_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","40");
    QString site_url="http://localhost:3000/bank/credit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    creditManager = new QNetworkAccessManager(this);
    connect(creditManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(creditSlot(QNetworkReply*)));
    reply = creditManager->post(request, QJsonDocument(json).toJson());
    ui->labelPankkiInfo->setText("");
}

void Pankki::on_btnNosto_60_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","60");
    QString site_url="http://localhost:3000/bank/credit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    creditManager = new QNetworkAccessManager(this);
    connect(creditManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(creditSlot(QNetworkReply*)));
    reply = creditManager->post(request, QJsonDocument(json).toJson());
    ui->labelPankkiInfo->setText("");
}

void Pankki::on_btnNosto_100_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","100");
    QString site_url="http://localhost:3000/bank/credit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    creditManager = new QNetworkAccessManager(this);
    connect(creditManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(creditSlot(QNetworkReply*)));
    reply = creditManager->post(request, QJsonDocument(json).toJson());
    ui->labelPankkiInfo->setText("");
}

void Pankki::on_btnNosto_200_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","200");
    QString site_url="http://localhost:3000/bank/credit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    creditManager = new QNetworkAccessManager(this);
    connect(creditManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(creditSlot(QNetworkReply*)));
    reply = creditManager->post(request, QJsonDocument(json).toJson());
    ui->labelPankkiInfo->setText("");
}

void Pankki::on_btnNosto_500_clicked()
{
    timerCounter=0;
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",this->idTili);
    json.insert("idKortti",this->idKortti);
    json.insert("Summa","500");
    QString site_url="http://localhost:3000/bank/credit_nosto";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    creditManager = new QNetworkAccessManager(this);
    connect(creditManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(creditSlot(QNetworkReply*)));
    reply = creditManager->post(request, QJsonDocument(json).toJson());
    ui->labelPankkiInfo->setText("");
}
