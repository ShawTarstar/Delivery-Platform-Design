#include "sever_order.h"
#include "ui_sever_order.h"

sever_order::sever_order(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sever_order)
{
    ui->setupUi(this);

    ///////////////初始化列表
    ui->ordertable->setColumnCount(4);
    QStringList foodList;
    foodList << "订单号";
    foodList << "金额";
    foodList << "时间";
    foodList << "操作";
    ui->ordertable->setHorizontalHeaderLabels(foodList);
    ui->ordertable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); ///设置列宽


}

sever_order::~sever_order()
{
    delete ui;
}

void sever_order::on_pushButton_clicked()
{
    horderPage.show();
}


void sever_order::on_back_clicked()
{
    this->close();
}

