#include "debitvalikko.h"
#include "ui_debitvalikko.h"

debitValikko::debitValikko(QString idTili, QString idKortti, QString Etunimi, QString Sukunimi, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::debitValikko)
{
    ui->setupUi(this);
    timerCounter=0;
    this->idTili=idTili;
    this->idKortti=idKortti;
    this->Etunimi=Etunimi;
    this->Sukunimi=Sukunimi;
    qDebug()<<"debit valikko "+this->idTili;
    ui->labelDebitValikko->setText("Tervetuloa "+Etunimi+" "+Sukunimi);

    objDQTimer = new QTimer();

    // setup signal and slot
    connect(objDQTimer, SIGNAL(timeout()),
            this, SLOT(TimerSlot()));

    objDQTimer->start(1000);
}

debitValikko::~debitValikko()
{
    delete ui;
    ui = nullptr;
    delete objDebitPankki;
    objDebitPankki=nullptr;
    delete objSaldo;
    objSaldo = nullptr;
    delete objTilitapahtumat;
    objTilitapahtumat = nullptr;
}


void debitValikko::on_btnDebitValikkoNosto_clicked()
{
    timerCounter=0;
    objDQTimer->stop();
    qDebug()<<"debit valikko nosto";
    objDebitPankki=new debitPankki(this->idTili, this->idKortti);
    objDebitPankki->show();
}

void debitValikko::on_btnDebitValikkoSaldo_clicked()
{
    timerCounter=0;
    objDQTimer->stop();
    qDebug()<<"debit valikko saldo";
    objSaldo=new Saldo(this->idKortti);
    objSaldo->show();
}

void debitValikko::on_btnDebitValikkoTilitapah_clicked()
{
    timerCounter=0;
    objDQTimer->stop();
    qDebug()<<"debit valikko tilitapah";
    objTilitapahtumat= new Tp(this->idKortti);
    objTilitapahtumat->show();
}

void debitValikko::on_btnDebitValikkoKirjauduUlos_clicked()
{
    timerCounter=0;
    objDQTimer->stop();
    qDebug()<<"debit valikko logout";
    this->close();
}

void debitValikko::TimerSlot()
{
    qDebug() << "Debit Valikon Timer.."<<timerCounter;
    timerCounter++;

    if(timerCounter==30) // sulkee formin jos ei paina nappeja 30 sekunttiin
        {
            objDQTimer->stop();

            delete objDQTimer;
            objDQTimer = nullptr;

            this->close();
            //emit finishProgram();
        }
}
