#include "pay_success.h"
#include "ui_pay_success.h"
#include <all_order.h>

pay_success::pay_success(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::pay_success)
{
    ui->setupUi(this);
}

pay_success::~pay_success()
{
    delete ui;
}

void pay_success::on_back_mainp_button_clicked()
{
    (this)->close();
}


void pay_success::on_look_order_button_clicked()
{
    client_pay_success.show();
}

