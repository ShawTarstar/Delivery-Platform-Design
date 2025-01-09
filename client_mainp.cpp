#include "client_mainp.h"
#include "ui_client_mainp.h"

client_mainp::client_mainp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::client_mainp)
{
    ui->setupUi(this);
}

client_mainp::~client_mainp()
{
    delete ui;
}

void client_mainp::on_quitButton_clicked()
{

    this->close();

}


void client_mainp::on_foodchoice_Button_clicked()
{
    clint_food_show.show();

}


void client_mainp::on_shopcar_Button_clicked()
{
    clint_shopcar.show();

}


void client_mainp::on_ordermng_Button_clicked()
{
    clint_all_order.show();

}





void client_mainp::on_Client_id_label_linkActivated(const QString &link)
{

}

