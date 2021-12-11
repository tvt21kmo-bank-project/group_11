#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete objDebitValikko;
    objDebitValikko = nullptr;
    delete objValinta;
    objValinta = nullptr;

}

void MainWindow::on_btnLogin_clicked()
{
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("Korttinumero",ui->lineEditKorttinumero->text());
    json.insert("PIN",ui->lineEditPIN->text());
    QString site_url="http://localhost:3000/login";
    // credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //QByteArray data = credentials.toLocal8Bit().toBase64();
    //QString headerData = "Basic " + data;
    //request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(loginSlot(QNetworkReply*)));
    reply = loginManager->post(request, QJsonDocument(json).toJson());
}
int count = 0;

void MainWindow::loginSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument j_doc = QJsonDocument::fromJson(response_data);
    QJsonObject j_obj = j_doc.object();
    //qDebug()<<j_obj;
    QString idTili = QString::number(j_obj["idTili"].toInt()); // tuodaan loginin mukana tilin ja kortin ID:t, tilin tyyppi ja nimet
    QString idKortti = QString::number(j_obj["idKortti"].toInt());
    QString Tilin_tyyppi = QString(j_obj["Tilin_tyyppi"].toString());
    QString Etunimi = QString(j_obj["Etunimi"].toString());
    QString Sukunimi = QString(j_obj["Sukunimi"].toString());
    //qDebug()<<idTili;
    //qDebug()<<"Tilin tyyppi: "<<Tilin_tyyppi;
    //qDebug()<<"Etunimes : "<<Etunimi;
    //qDebug()<<"Sukuname : "<<Sukunimi;
    //objValinta=new Valinta(idTili, idKortti);
    //objValikko=new valikko(idTili, idKortti);
    //objDebitValikko=new debitValikko(idTili, idKortti);
    if(response_data !="false" ){
        qDebug()<<"Oikea tunnus, kirjaudutaan...";

        if(Tilin_tyyppi == "Credit" || Tilin_tyyppi == "credit"){
            qDebug()<<"Päästiin credittii";
            objValinta=new Valinta(idTili, idKortti);
            objValinta->show();
            ui->lineEditKorttinumero->setText("");
            ui->lineEditPIN->setText("");
            ui->labelLoginInfo->setText("");
        }else{
            objDebitValikko=new debitValikko(idTili, idKortti);
            objDebitValikko->show();
            ui->lineEditKorttinumero->setText("");
            ui->lineEditPIN->setText("");
            ui->labelLoginInfo->setText("");
        }


    }
    else if(response_data=="false") {
        ui->lineEditKorttinumero->setText("");
        ui->lineEditPIN->setText("");
        qDebug()<<"tunnus ja salasana ei täsmää";
        ui->labelLoginInfo->setText("Tunnus ja salasana ei täsmää");
    count ++;
    if (count == 3){
            ui->labelLoginInfo->setText("Kortti lukittu");
            count = 0;
       }
    }


    else {
        ui->lineEditKorttinumero->setText("");
        ui->lineEditPIN->setText("");
        ui->labelLoginInfo->setText("Virhe tietokantayhteydessä");

    }

}

//int count = 0;
//for(;;)
//{
//    ask_password();
//    if (password == expected_password)
//        break;
//    count++;
//    if (count == 3)
//    {
//       Sleep(300000);    // 5 minutes = 300000 ms.
//       count = 0;
//    }
//}

void MainWindow::on_btnLoginClose_clicked()
{
    this->close();
}
