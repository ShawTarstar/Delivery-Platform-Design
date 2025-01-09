#include "sever_goods.h"
#include "ui_sever_goods.h"
#include <QString>
#include <QApplication>
#include <QSettings>
#include <QDebug>
#include <QMessageBox>
#include <QSettings>
#include <QLabel>
#include <QPixmap>
#include <QCoreApplication>
#include <QVariant>
#include <QFileDialog>
#include <QPushButton>

#include "data.h"


sever_goods::sever_goods(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sever_goods)
{
    ui->setupUi(this);

    ui->setupUi(this);

    ///////////////初始化列表
    ui->foodstable->setColumnCount(3);
    QStringList foodList;
    foodList << "名称";
    foodList << "价格";
    foodList << "操作";
    ui->foodstable->setHorizontalHeaderLabels(foodList);
    ui->foodstable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); ///设置列宽

    QString name;
    double price=0;

    //data::findDishList(name,pixlocation,price,amount);

}



sever_goods::~sever_goods()
{
    delete ui;
}

void sever_goods::on_back_clicked()
{
    this->close();
}

///添加商品
void sever_goods::on_add_clicked()
{
    QString name = ui->nameline->text();
    double price = ui->pricebox->value();

    if(name.isEmpty()){
        QMessageBox::warning(this,"错误","请将信息填写完整！");
        return;
    }
    else{
        QMessageBox::warning(this,"提示","添加成功！");
    }



    QPushButton *dbutton = new QPushButton("删除");
    // 连接按钮的 clicked 信号

    connect(dbutton, &QPushButton::clicked, [this,name]() {idx=name;emit deletesignal(idx);});
    ui->foodstable->setCellWidget(ui->foodstable->rowCount(), ui->foodstable->columnCount() - 1, dbutton);

}

void sever_goods::deletefood(QString idx){
    ///删除表格中信息


    ///
    ui->foodstable->clearContents();

    ///从新载入信息

}


