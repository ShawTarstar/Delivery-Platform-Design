#include "data.h"
#include "ui_data.h"
#include <QSettings>

/*****************
 * 林桐舟
[bob]
bob\luosifen\name=luosifen
bob\luosifen\price=12.5
bob\luosifen\pixlocation=12345
*****************/


QString busi_data="business_dish_data.ini";
QString filepath="user_temp.ini";
QSettings settings(filepath,QSettings::IniFormat);
QString severAccount;
Business::Business(){
    setName("A");
    QStringList groups = settings.childGroups();
    if (!groups.isEmpty()) {
        // 进入第一个节
        QString firstSection = groups.first();
        settings.beginGroup(firstSection);
        severAccount=settings.value("name").toString();

        settings.endGroup(); // 结束访问组
    } else {
        qDebug() << "INI 文件中没有任何节。";
    }
}
/***********************
 * 调用时，按照如下规则调用：
 * addDishList("菜名","图片地址","价格")
 * 功能：为文件添加一个菜品。
 * *********************/
void Business::addDishList(QString name,QString pixlocation,double price)
{
    QSettings busi_settings(busi_data,QSettings::IniFormat);
    busi_settings.beginGroup(severAccount);
    QString groupname=QString("%1/%2").arg(severAccount).arg(name);
    busi_settings.beginGroup(groupname);
    busi_settings.setValue("name",name);
    busi_settings.setValue("price",price);
    busi_settings.setValue("pixlocation",pixlocation);
    busi_settings.endGroup();

    qDebug() << "Dish saved successfully to business_data.ini!";

}
/***********************
 * 调用时，按照如下规则调用：
 * deleteDishList("菜名")
 * 功能：通过对菜品名的查找为文件删除一个菜品。
 * *********************/

void Business::deleteDishList(QString dishName)
{
    //QString dishName="luosifen";//此处接入需要删除的菜品名
    QSettings busi_settings(busi_data,QSettings::IniFormat);
    busi_settings.beginGroup(severAccount);
    double price;
    QString pix;

    if(findDishList(dishName,pix,price)==1)
    {
        QString remove_dishName=QString("%1/%2").arg(severAccount).arg(dishName);
        busi_settings.remove(remove_dishName);

        qDebug()<<"Dish deleted: "<<dishName;
        return;
    }
    else
    {
        qDebug()<<"not found";
        return;
    }

}
/***********************
 * 调用时，按照如下规则调用：
 * modifyDishList("菜名","图片地址","价格")
 * 功能：通过对菜品名的查找和函数中提供的信息对文件中的菜品信息进行更改。
 * *********************/
void Business::modifyDishList(QString name,QString pixlocation,double price)
{
    if(findDishList(name,pixlocation,price)==1)
    {
        QSettings settings(busi_data,QSettings::IniFormat);
        QString keyPrefix=QString("%1/%2").arg(severAccount).arg(name);

        settings.setValue(keyPrefix+"/name",name);
        settings.setValue(keyPrefix+ "/price",price);
        settings.setValue(keyPrefix+"/pixlocation",pixlocation);
        settings.sync();

        qDebug()<<"dish modify:"<<name;
        return;
    }


    qDebug()<<"not found";
}

bool Business::findDishList(QString name,QString &pixlocation,double &price)
{
    int flag=0;


    QString temp=QString("%1/%2").arg(severAccount).arg(name);
    //商家名（getname()）是调用该函数的商家，name是菜品名
    //可以将getname处更改成要查询的商家名，name处更改成菜品名
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
        }
    }
    if(flag==2)
        return true;
    else
        return false;
}

