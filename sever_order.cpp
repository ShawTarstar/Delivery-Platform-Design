#include "sever_order.h"
#include "ui_sever_order.h"

sever_order::sever_order(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sever_order)
{
    ui->setupUi(this);

    ///////////////初始化列表
    ui->foodstable->setColumnCount(4);
    QStringList foodList;
    foodList << "订单号";
    foodList << "金额";
    foodList << "时间";
    foodList << "操作";
    ui->foodstable->setHorizontalHeaderLabels(foodList);
    ui->foodstable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); ///设置列宽


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


void sever_order::on_pushButton_2_clicked()
{

}

void sever_order::addline(int n,double price,int time){
    //添加行数
    int count =ui->foodstable->rowCount();

    ui->foodstable->setRowCount(count+1);
    //ui->foodstable->insertRow(ui->foodstable->rowCount());

    // 连接按钮的 clicked 信号
    QPushButton *dbutton = new QPushButton("完成");
    connect(dbutton, &QPushButton::clicked, [this,n]() {});
    ui->foodstable->setCellWidget(count, ui->foodstable->columnCount() - 1, dbutton);

    //显示该商品

    QTableWidgetItem* nItem=new QTableWidgetItem(n);
    QTableWidgetItem* priceItem = new QTableWidgetItem(QString::number(price));
    QTableWidgetItem* tItem = new QTableWidgetItem(QString::number(time));
    ui->foodstable->setItem(count,0,nItem);
    ui->foodstable->setItem(count,1,priceItem);
    ui->foodstable->setItem(count,2,tItem);
    ui->foodstable->show();
    ui->foodstable->viewport()->update(); //强制更新表格视图
}
