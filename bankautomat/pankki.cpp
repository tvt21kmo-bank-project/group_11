#include "pankki.h"
#include "ui_pankki.h"

Pankki::Pankki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pankki)
{
    ui->setupUi(this);
}

Pankki::~Pankki()
{
    delete ui;
}

void Pankki::on_btnPankkiClose_clicked()
{
    this->close();
}

void Pankki::on_btnPankkiSuorita_clicked()
{
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idTili",ui->le_idTili->text());
    json.insert("idKortti",ui->le_idKortti->text());
    json.insert("Summa",ui->le_Summa->text());
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
}

void Pankki::debitSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    if(response_data == "1"){
        ui->labelPankkiInfo->setText("Nosto Onnistu");
        ui->le_idTili->setText("");
        ui->le_idKortti->setText("");
        ui->le_Summa->setText("");
    }
    else {
        ui->labelPankkiInfo->setText("Nosto Epäonnistu");
        ui->le_idTili->setText("");
        ui->le_idKortti->setText("");
        ui->le_Summa->setText("");
    }
}

void Pankki::creditSlot(QNetworkReply *reply)
{

}


