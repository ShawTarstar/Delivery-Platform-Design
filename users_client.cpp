#include "data.h"
#include "ui_data.h"

/****************************
 * 林桐舟
[mike]
mike\luosifen\name=luosifen
mike\luosifen\amount=1
mike\luosifen\price=12
mike\luosifen\pixlocation=123456

/****************************/

/***********************
 * 调用时，按照如下规则调用：
 * addShopCart("菜名","图片地址","价格","数量")
 * 功能：为购物车添加一个菜品。
 * *********************/

QString ShopCart_data="ShopCart_data.ini";

void Client::addShopCart(QString name,QString pixlocation,double price,int amount)
{
    QSettings settings(ShopCart_data,QSettings::IniFormat);
    settings.beginGroup(getName());

    //检查购物车中是否已有该商品，有则直接加数量
    if(findShopCart(name,pixlocation,price,amount)==1)
    {
        amount++;
        QString title=QString("%1/%2").arg(getName()).arg(name);

        settings.setValue(title+"/amount",amount);

        qDebug()<<"sucessfully add shopcart's amount "<<name;

        return;
    }
    else//否则增加新商品
    {
        QString title=QString("%1/%2").arg(getName()).arg(name);

        settings.setValue(title+"/name",name);
        settings.setValue(title+"/amount",amount);
        settings.setValue(title+"/price",price);
        settings.setValue(title+"/pixlocation",pixlocation);
        settings.endGroup();

        qDebug()<<"sucessfully set new shopcart's item"<<name;
    }

}

/***********************
 * 调用时，按照如下规则调用：
 * deleteShopCart("菜名")
 * 功能：购物车中该菜品数量减一。
 * *********************/

void Client::deleteShopCart(QString name)
{
    QSettings settings(ShopCart_data,QSettings::IniFormat);
    settings.beginGroup(getName());
    QString pix;
    double price;
    int amount;

    if(findShopCart(name,pix,price,amount)==1)
    {
        if(amount>1)
        {
            amount--;
            QString title=QString("%1/%2/").arg(getName()).arg(name);

            settings.setValue(title+"name",name);
            settings.setValue(title+"amount",amount);
            settings.setValue(title+"price",price);
            settings.setValue(title+"pixlocation",pix);
            settings.sync();

            return;
        }
        else//购物车该商品数量为1，再删除一次则需删除购物车中该商品信息
        {
            QString title=QString("%1/%2").arg(getName()).arg(name);

            settings.remove(title);

            qDebug()<<"remove "<<title;
            return;
        }
    }

    qDebug()<<"找不到该商品！";
}

/***********************
 * 调用时，按照如下规则调用：
 * createOrder(商家对象)
 * 功能：创建新订单
 * *********************/
void Client::createOrder(Business business_temp)
{
    Order order_temp;
    order_temp.setOrder(*this,business_temp);

}

bool Client::findShopCart(QString name,QString& pixlocation,double& price,int& amount)
{
    int flag=0;
    QSettings settings(ShopCart_data,QSettings::IniFormat);
    QString temp=QString("%1/%2").arg(getName()).arg(name);

    QStringList allKeys = settings.allKeys();
    for (const QString &key : allKeys) {
        if (key.contains(temp)) {
            // 根据键的路径来获取相应的值

            if (key.endsWith("price")) {
                price = settings.value(key).toDouble();
                flag+=1;
                qDebug() << "Dish Price:" << price;
            }
            else if (key.endsWith("pixlocation")) {
                pixlocation = settings.value(key).toString();
                flag+=1;
                qDebug() << "Dish Picture Location:" << pixlocation;
            }
            else if (key.endsWith("amount")) {
                amount = settings.value(key).toInt();
                flag+=1;
                qDebug() << "Dish amount:" << amount;
            }
        }
    }
    if(flag==3)
        return true;
    else
        return false;
}
