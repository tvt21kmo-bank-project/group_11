#include "valikko.h"
#include "ui_valikko.h"

valikko::valikko(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::valikko)
{
    ui->setupUi(this);
}

valikko::~valikko()
{
    delete ui;
}

void valikko::on_btnValikkoClose_clicked()
{
    this->close();

}

void valikko::on_btnNostaRahaa_clicked()
{

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
