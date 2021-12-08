#include "valikko.h"
#include "ui_valikko.h"

valikko::valikko(QString idTili, QString idKortti, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::valikko)
{
    this->idTili=idTili;
    this->idKortti=idKortti;
    ui->setupUi(this);
    qDebug()<<"valikko "+this->idTili;

}


valikko::~valikko()
{
    delete ui;
    ui = nullptr;
    delete objPankki;
    objPankki=nullptr;
}

void valikko::on_btnValikkoClose_clicked()
{
    this->close();

}

void valikko::on_btnNostaRahaa_clicked()
{
    objPankki=new Pankki(this->idTili, this->idKortti);
    objPankki->show();
}

void valikko::on_btnNaytaSaldo_clicked()
{

}

void valikko::on_btnSelaaTilitapahtumia_clicked()
{

}

void valikko::on_btnKirjauduUlos_clicked()
{

}

void valikko::on_btnValitseTili_clicked()
{

}
