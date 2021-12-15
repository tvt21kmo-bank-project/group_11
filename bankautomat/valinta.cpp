#include "valinta.h"
#include "ui_valinta.h"

Valinta::Valinta(QString idTili, QString idKortti, QString Etunimi, QString Sukunimi, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Valinta)
{
    ui->setupUi(this);
    timerCounter=0;
    this->idTili=idTili;
    this->idKortti=idKortti;
    this->Etunimi=Etunimi;
    this->Sukunimi=Sukunimi;
    qDebug()<<Etunimi;

    objQTimer = new QTimer();

    connect(objQTimer, SIGNAL(timeout()),
            this, SLOT(TimerSlot()));

    objQTimer->start(1000);
}

Valinta::~Valinta()
{
    delete ui;
}

void Valinta::TimerSlot()
{
    qDebug() << "Valinta Timer.."<<timerCounter;
    timerCounter++;

    if(timerCounter==10) // sulkee formin jos ei paina nappeja 30 sekunttiin
        {
            objQTimer->stop();

            delete objQTimer;
            objQTimer = nullptr;

            this->close();
            //emit finishProgram();
        }
}

void Valinta::on_btnCreditValinta_clicked()
{

    objValikko=new valikko(idTili, idKortti, Etunimi, Sukunimi);
    objValikko->show();
    timerCounter=0;
    objQTimer->stop();
    this->close();
}

void Valinta::on_btnDebitValinta_clicked()
{
    objDebitValikko=new debitValikko(idTili, idKortti, Etunimi, Sukunimi);
    objDebitValikko->show();
    timerCounter=0;
    objQTimer->stop();
    this->close();
}

void Valinta::on_btnValintaClose_clicked()
{
    timerCounter=0;
    this->close();
}
