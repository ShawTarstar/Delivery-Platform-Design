#include "shopcar.h"
#include "ui_shopcar.h"

shopcar::shopcar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::shopcar)
{
    ui->setupUi(this);
}

shopcar::~shopcar()
{
    delete ui;
}

void shopcar::on_server_name_1_linkActivated(const QString &link)
{

}


void shopcar::on_add_1_clicked()
{

}


void shopcar::on_food_pho_1_linkActivated(const QString &link)
{


}


void shopcar::on_food_name_1_linkActivated(const QString &link)
{

}


void shopcar::on_food_perprice_1_linkActivated(const QString &link)
{

}


void shopcar::on_food_num_1_linkActivated(const QString &link)
{

}


void shopcar::on_radioButton_2_clicked()
{

}


void shopcar::on_food_pho_2_linkActivated(const QString &link)
{

}


void shopcar::on_food_name_2_linkActivated(const QString &link)
{

}


void shopcar::on_food_perpri_2_linkActivated(const QString &link)
{

}




void shopcar::on_all_choose_button_clicked()
{

}


void shopcar::on_sum_price_linkActivated(const QString &link)
{

}


void shopcar::on_pay_button_clicked()
{
    client_pay_success.show();
}


void shopcar::on_food_num_2_linkActivated(const QString &link)
{

}


void shopcar::on_back_to_mainp_button_clicked()
{
    (this)->close();
}


void shopcar::on_manage_Button_clicked()
{

}

