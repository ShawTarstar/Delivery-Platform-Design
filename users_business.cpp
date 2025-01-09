#include "data.h"
#include "ui_data.h"

/*****************
 * 林桐舟
[bob]
bob\luosifen\name=luosifen
bob\luosifen\price=12.5
bob\luosifen\pixlocation=12345
*****************/


QString busi_data="business_dish_data.ini";

Business::Business(){
    setName("A");
}
/***********************
 * 调用时，按照如下规则调用：
 * addDishList("菜名","图片地址","价格")
 * 功能：为文件添加一个菜品。
 * *********************/
void Business::addDishList(QString name,QString pixlocation,double price)
{
    QSettings busi_settings(busi_data,QSettings::IniFormat);

    busi_settings.beginGroup(getName());

    for(int i=0;i<100;i++)
    {
        if(dishlist[i].name.isEmpty())//存在空位，存入数据
        {
        //QString temp1="luosifen",temp4="12345";
        //double temp3=12.5;
        dishlist[i].name=name;
        dishlist[i].price=price;
        dishlist[i].pixlocation=pixlocation;

        QString groupname=QString("%1/%2").arg(getName()).arg(dishlist[i].name);
        busi_settings.beginGroup(groupname);
        busi_settings.setValue("name",dishlist[i].name);
        busi_settings.setValue("price",dishlist[i].price);
        busi_settings.setValue("pixlocation",dishlist[i].pixlocation);
        busi_settings.endGroup();

        qDebug() << "Dish saved successfully to business_data.ini!";
        break;
        }
    }
}
/***********************
 * 调用时，按照如下规则调用：
 * deleteDishList("菜名")
 * 功能：通过对菜品名的查找为文件删除一个菜品。
 * *********************/

void Business::deleteDishList(QString dishName)
{
    //QString dishName="luosifen";//此处接入需要删除的菜品名

    for(int i=0;i<100;i++)
    {
        if(dishlist[i].name==dishName)
        {
            //清空内存中的dish信息
            dishlist[i]=Dish();

            //删除ini文件中的对应项
             QSettings busi_settings(busi_data,QSettings::IniFormat);
            busi_settings.beginGroup(getName());

            QString remove_dishName=QString("%1/%2").arg(getName()).arg(dishName);
            busi_settings.remove(remove_dishName);

            qDebug()<<"Dish deleted: "<<dishName;
            return;
        }
    }

    qDebug()<<"not found";
}
/***********************
 * 调用时，按照如下规则调用：
 * modifyDishList("菜名","图片地址","价格")
 * 功能：通过对菜品名的查找和函数中提供的信息对文件中的菜品信息进行更改。
 * *********************/
void Business::modifyDishList(QString name,QString pixlocation,double price)
{
    Dish dish;
    dish.name=name;
    dish.price=price;
    dish.pixlocation=pixlocation;
    for(int i=0;i<100;i++)
    {
        if(dishlist[i].name==dish.name)
        {
            QSettings settings(busi_data,QSettings::IniFormat);
            QString keyPrefix=QString("%1/%2").arg(getName()).arg(dish.name);

            settings.setValue(keyPrefix+"/name",dish.name);
            settings.setValue(keyPrefix+ "/price",dish.price);
            settings.setValue(keyPrefix+"/pixlocation",dish.pixlocation);
            settings.sync();

            qDebug()<<"dish modify:"<<dish.name;
            return;
        }
    }

    qDebug()<<"not found";
}

void Business::findDishList(QString name,QString &pixlocation,double &price,int &amount)
{
    bool flag=0;
    for(int i=0;i<100;i++)
    {
        if(dishlist[i].name==name)
        {
            amount=dishlist[i].amount;
            price=dishlist[i].price;
            pixlocation=dishlist[i].pixlocation;
            flag=1;
            return;
        }
    }
    if(!flag) qDebug()<<"not found";
    return;
}
