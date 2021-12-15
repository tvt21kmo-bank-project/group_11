#include "valikko.h"
#include "ui_valikko.h"

valikko::valikko(QString idTili, QString idKortti, QString Etunimi, QString Sukunimi, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::valikko)
{

    ui->setupUi(this);
    timerCounter=0;
    this->showFullScreen();
    this->idTili=idTili;
    this->idKortti=idKortti;
    this->Etunimi=Etunimi;
    this->Sukunimi=Sukunimi;
    //qDebug()<<"valikko "+this->idTili;
    //qDebug()<<"valikko "<< Etunimi;
    //qDebug()<<"valikko " <<Sukunimi;
    ui->labelValikkoAsiakas->setText("Tervetuloa "+Etunimi+" "+Sukunimi);


    objQTimer = new QTimer();

    // setup signal and slot
    connect(objQTimer, SIGNAL(timeout()),
            this, SLOT(TimerSlot()));

    objQTimer->start(1000);
}


valikko::~valikko()
{
    delete ui;
    ui = nullptr;
    delete objPankki;
    objPankki=nullptr;
    delete objSaldo;
    objSaldo = nullptr;
    delete objTilitapahtumat;
    objTilitapahtumat = nullptr;
}

void valikko::TimerSlot()
{
    qDebug() << "credit Valikon Timer.."<<timerCounter;
    timerCounter++;

    if(timerCounter==30) // sulkee formin jos ei paina nappeja 30 sekunttiin
        {
            objQTimer->stop();

            delete objQTimer;
            objQTimer = nullptr;

            this->close();
            //emit finishProgram();
        }
}

//void valikko::on_btnValikkoClose_clicked()
//{
//    timerCounter=0;
//    objQTimer->stop();
//    this->close();

//}

void valikko::on_btnNostaRahaa_clicked()
{
    //timerCounter=0;
    objQTimer->stop();
    objPankki=new Pankki(this->idTili, this->idKortti);
    objPankki->show();
}

void valikko::on_btnNaytaSaldo_clicked()
{
    //timerCounter=0;
    objQTimer->stop();
    objSaldo=new Saldo(this->idKortti);
    objSaldo->show();
}

void valikko::on_btnSelaaTilitapahtumia_clicked()
{
    //timerCounter=0;
    objQTimer->stop();
    objTilitapahtumat= new Tp(this->idKortti);
    objTilitapahtumat->show();
}

void valikko::on_btnKirjauduUlos_clicked()
{
    timerCounter=0;
    this->close();
}

