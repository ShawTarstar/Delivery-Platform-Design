#include "all_order.h"
#include "ui_all_order.h"

all_order::all_order(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::all_order)
{
    ui->setupUi(this);
}

all_order::~all_order()
{
    delete ui;
}




void all_order::on_food_pho_1_linkActivated(const QString &link)
{

}


void all_order::on_food_name_1_linkActivated(const QString &link)
{

}


void all_order::on_food_sumprice_label_linkActivated(const QString &link)
{

}


void all_order::on_pay_stage_1_label_linkActivated(const QString &link)
{

}


void all_order::on_food_pho_2_linkActivated(const QString &link)
{

}


void all_order::on_food_name_2_linkActivated(const QString &link)
{

}


void all_order::on_food_sumprice_2_linkActivated(const QString &link)
{

}


void all_order::on_pay_stage_2_label_linkActivated(const QString &link)
{

}


void all_order::on_back_to_main_Button_clicked()
{
    (this)->close();
}

