#include "data.h"
#include "ui_data.h"

void Client::addShopCart()
{
    //点击一次+，加入一件该菜品到购物车
    Dish dish;//此处调用该处菜品信息

    //第一遍检查购物车中是否已有该商品，有则直接加数量
    for(int i=0;i<100;i++)
    {
        if(ShopCart[i].name==dish.name&&!ShopCart[i].name.isEmpty())
        {
            ShopCart[i].amount++;
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
            return;
        }
    }

    qDebug()<<"购物车已满";
}


void Client::deleteShopCart()
{
    Dish dish;//此处调用该菜品信息

    for(int i=0;i<100;i++)
    {
        if(ShopCart[i].name==dish.name&&!ShopCart[i].name.isEmpty())
        {
            if(ShopCart[i].amount>1)
            {
                ShopCart[i].amount--;
                return;
            }
            else//购物车该商品数量为1，再删除一次则需删除购物车中该商品信息
            {
                ShopCart[i].name.clear();
                return;
            }
        }
    }

    qDebug()<<"找不到该商品！";
}
