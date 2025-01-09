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

    //遍历该商家所有菜品
    QSettings settings("order_data.ini", QSettings::IniFormat);
    QString businessName=getbusinessName();
    // 切换到商家所在的 group（比如 bob）
    settings.beginGroup(businessName);

    // 遍历该商家下所有的菜品（以 '商家名\菜品名' 为前缀）
    foreach (const QString &key, settings.childKeys()) {
        // 通过 '商家名\菜品名' 拆分 key，获取菜品名
        QStringList parts = key.split("/");
        if (parts.size() == 2) {
            QString dishName = parts[1];  // 获取菜品名

            // 读取菜品的详细信息
            QString name = settings.value(businessName + "/" + dishName + "/name").toString();
            double price = settings.value(businessName + "/" + dishName + "/price").toDouble();
            QString pixLocation = settings.value(businessName + "/" + dishName + "/pixlocation").toString();
        }
    }
    settings.endGroup();

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

//用于获取该商家的名字
QString sever_goods::getbusinessName()
{
    QString filepath="user_temp.ini";
    QSettings settings(filepath,QSettings::IniFormat);
    //读入数据
    QString businessName;
    QStringList groups = settings.childGroups();
    if (!groups.isEmpty()) {
        // 进入第一个节
        QString firstSection = groups.first();
        settings.beginGroup(firstSection);
        businessName=settings.value("name").toString();

        settings.endGroup(); // 结束访问组
        return businessName;
    } else {
        qDebug() << "INI 文件中没有任何节。";
        return "";
    }

}
