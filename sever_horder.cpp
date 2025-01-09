#include "sever_horder.h"
#include "ui_sever_horder.h"

sever_horder::sever_horder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sever_horder)
{
    ui->setupUi(this);

    ///////////////初始化列表
    ui->hordertable->setColumnCount(4);
    QStringList foodList;
    foodList << "订单号";
    foodList << "时间";
    foodList << "金额";
    foodList << "状态";
    ui->hordertable->setHorizontalHeaderLabels(foodList);
    ui->hordertable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); ///设置列宽

}

sever_horder::~sever_horder()
{
    delete ui;
}

void sever_horder::on_back_clicked()
{
    this->close();
}

