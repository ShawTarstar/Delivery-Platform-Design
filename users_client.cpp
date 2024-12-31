#include "data.h"
#include "ui_data.h"

QString ShopCart_data="ShopCart_data.ini";

void Client::addShopCart()
{
    QSettings settings(ShopCart_data,QSettings::IniFormat);
    settings.beginGroup(getName());

    //点击一次+，加入一件该菜品到购物车
    Dish dish;//此处调用该处菜品信息

    //第一遍检查购物车中是否已有该商品，有则直接加数量
    //
    for(int i=0;i<100;i++)
    {
        if(ShopCart[i].name==dish.name&&!ShopCart[i].name.isEmpty())
        {
            ShopCart[i].amount++;
            QString title=QString("%1/%2").arg(getName()).arg(ShopCart[i].name);

            settings.setValue(title+"name",ShopCart[i].name);
            settings.setValue(title+"amount",ShopCart[i].amount);
            settings.setValue(title+"price",ShopCart[i].price);
            settings.setValue(title+"pixlocation",ShopCart[i].pixlocation);
            settings.sync();

            qDebug()<<"sucessfully set "<<ShopCart[i].name;

            return;
        }
    }

    //第二遍增加新商品
    for(int i=0;i<100;i++)
    {
        if(ShopCart[i].name.isEmpty())
        {
            ShopCart[i]=dish;
            ShopCart[i].amount=1;

            QString title=QString("%1/%2").arg(getName()).arg(ShopCart[i].name);

            settings.setValue(title+"name",ShopCart[i].name);
            settings.setValue(title+"amount",ShopCart[i].amount);
            settings.setValue(title+"price",ShopCart[i].price);
            settings.setValue(title+"pixlocation",ShopCart[i].pixlocation);
            settings.sync();

            qDebug()<<"sucessfully set "<<ShopCart[i].name;
            return;
        }
    }

    qDebug()<<"购物车已满";
}


void Client::deleteShopCart()
{
    QSettings settings(ShopCart_data,QSettings::IniFormat);
    settings.beginGroup(getName());

    Dish dish;//此处调用该菜品信息

    for(int i=0;i<100;i++)
    {
        if(ShopCart[i].name==dish.name&&!ShopCart[i].name.isEmpty())
        {
            if(ShopCart[i].amount>1)
            {
                ShopCart[i].amount--;
                QString title=QString("%1/%2").arg(getName()).arg(ShopCart[i].name);

                settings.setValue(title+"name",ShopCart[i].name);
                settings.setValue(title+"amount",ShopCart[i].amount);
                settings.setValue(title+"price",ShopCart[i].price);
                settings.setValue(title+"pixlocation",ShopCart[i].pixlocation);
                settings.sync();

                return;
            }
            else//购物车该商品数量为1，再删除一次则需删除购物车中该商品信息
            {
                ShopCart[i].name.clear();

                QString title=QString("%1/%2").arg(getName()).arg(ShopCart[i].name);

                settings.remove(title);

                qDebug()<<"remove "<<title;
                return;
            }
        }
    }

    qDebug()<<"找不到该商品！";
}


void Client::createOrder()
{
    Order order_temp;
    Business business_temp;//此处获取该店铺商家
    order_temp.setOrder(*this,business_temp);

}
