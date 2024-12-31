#include "data.h"
#include "ui_data.h"

QString busi_data="business_dish_data.ini";

Business::Business(){

}

void Business::addDishList()
{
    QSettings busi_settings(busi_data,QSettings::IniFormat);

    busi_settings.beginGroup(getName());

    for(int i=0;i<100;i++)
    {
        if(dishlist[i].name.isEmpty())//存在空位，存入数据
        {
        QString temp1="luosifen",temp4="12345";
        double temp3=12.5;
        dishlist[i].name=temp1;
        dishlist[i].price=temp3;
        dishlist[i].pixlocation=temp4;

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

void Business::deleteDishList()
{
    QString dishName="luosifen";//此处接入需要删除的菜品名

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

void Business::modifyDishList()
{
    Dish dish;
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
