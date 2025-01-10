#include "sever_horder.h"
#include "ui_sever_horder.h"

#include<QString>

sever_horder::sever_horder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sever_horder)
{
    ui->setupUi(this);

    ///////////////初始化列表
    ui->hordertable->setColumnCount(3);
    QStringList foodList;
    foodList << "订单号";
    foodList << "时间";
    foodList << "金额";

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

void sever_horder::addline(QString n,int t,double price){
    //添加行数
    int count =ui->hordertable->rowCount();

    ui->hordertable->setRowCount(count+1);


    QTableWidgetItem* nItem=new QTableWidgetItem(n);
    QTableWidgetItem* priceItem = new QTableWidgetItem(QString::number(price));
    QTableWidgetItem* tItem = new QTableWidgetItem(QString::number(t));

    ui->hordertable->setItem(count,0,nItem);
    ui->hordertable->setItem(count,1,priceItem);
    ui->hordertable->setItem(count,2,tItem);
    ui->hordertable->show();
    ui->hordertable->viewport()->update(); //强制更新表格视图
}

