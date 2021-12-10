#include "valikko.h"
#include "ui_valikko.h"

valikko::valikko(QString idTili, QString idKortti, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::valikko)
{
    timerCounter=0;
    this->idTili=idTili;
    this->idKortti=idKortti;
    ui->setupUi(this);
    qDebug()<<"valikko "+this->idTili;

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
}

void valikko::TimerSlot()
{
    qDebug() << "Valikon Timer.."<<timerCounter;
    timerCounter++;

    if(timerCounter==30) // sulkee formin jos paina nappeja 30 sekunttiin
        {
            objQTimer->stop();

            delete objQTimer;
            objQTimer = nullptr;

            this->close();
            //emit finishProgram();
        }
}

void valikko::on_btnValikkoClose_clicked()
{
    timerCounter=0;
    this->close();

}

void valikko::on_btnNostaRahaa_clicked()
{
    timerCounter=0;
    objQTimer->stop();
    objPankki=new Pankki(this->idTili, this->idKortti);
    objPankki->show();
}

void valikko::on_btnNaytaSaldo_clicked()
{
    timerCounter=0;
    objQTimer->stop();
    objSaldo=new Saldo(this->idKortti);
    objSaldo->show();
}

void valikko::on_btnSelaaTilitapahtumia_clicked()
{
    timerCounter=0;
    objQTimer->stop();
}

void valikko::on_btnKirjauduUlos_clicked()
{
    timerCounter=0;
    objQTimer->stop();
}

void valikko::on_btnValitseTili_clicked()
{
    timerCounter=0;
    objQTimer->stop();
}
