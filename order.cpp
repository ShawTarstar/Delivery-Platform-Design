#include "data.h"
#include "ui_data.h"

QString sourceFileName="order_data.txt";

Order::Order(){}
void Order::setOrder()//设置订单信息
{//遍历购物车，如果勾选了就加入order.d[]


    saveOrder();
}
void Order::saveOrder()
{
    QFile file(sourceFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件进行写入";
        return;
    }

    QTextStream out(&file);
    out<<num<<","<<sum<<","<<client_info<<","<<business_info;


    file.close();
}
