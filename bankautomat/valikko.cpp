#include "valikko.h"
#include "ui_valikko.h"

valikko::valikko(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::valikko)
{
    ui->setupUi(this);
    objPankki=new Pankki;
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
    objPankki->showFullScreen();
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
