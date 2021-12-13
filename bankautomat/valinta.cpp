#include "valinta.h"
#include "ui_valinta.h"

Valinta::Valinta(QString idTili, QString idKortti, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Valinta)
{
    ui->setupUi(this);
    this->idTili=idTili;
    this->idKortti=idKortti;
}

Valinta::~Valinta()
{
    delete ui;
}

void Valinta::on_btnCreditValinta_clicked()
{

    objValikko=new valikko(idTili, idKortti);
    objValikko->show();
}

void Valinta::on_btnDebitValinta_clicked()
{
    objDebitValikko=new debitValikko(idTili, idKortti);
    objDebitValikko->show();
}

void Valinta::on_btnValintaClose_clicked()
{
    this->close();
}
