#include "sever_mainp.h"
#include "ui_sever_mainp.h"


sever_mainp::sever_mainp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sever_mainp)
{
    ui->setupUi(this);
}

sever_mainp::~sever_mainp()
{
    delete ui;
}

void sever_mainp::on_food_manage_clicked()
{
    ///打开菜品管理页
    goodsPage.show();
}


void sever_mainp::on_order_manage_clicked()
{
    ///打开订单管理页面
    orderPage.show();
}

