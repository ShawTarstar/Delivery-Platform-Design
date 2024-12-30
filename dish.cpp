#include "data.h"
#include "ui_data.h"

QString dish_data ="dish_data.ini";

Dish::Dish(){}

    //[luosifen]
    // name=luosifen
    // amount=0
    // price=12.5
    // pixlocation=12345

void Dish::setDish()
{
//读取文本框
    QString temp1="luosifen",temp4="12345";
    double temp3=12.5;
    name=temp1;
    price=temp3;
    pixlocation=temp4;

    //saveDish();
}


void Dish::deleteDish()
{
    QSettings dish_settings(dish_data,QSettings::IniFormat);

    if(dish_settings.childGroups().contains(name))
    {
        dish_settings.beginGroup(name);
        dish_settings.remove("");
        dish_settings.endGroup();
        qDebug() << "Dish with name" << name << "deleted successfully!";
    }
    else
    {
        qDebug() << "Dish with name" << name << "not found in dish_data.ini.";
    }

}



void Dish::saveDish()
{
    QSettings dish_settings(dish_data,QSettings::IniFormat);

    dish_settings.beginGroup(name);
    dish_settings.setValue("name",name);
    dish_settings.setValue("amount",amount);
    dish_settings.setValue("price",price);
    dish_settings.setValue("pixlocation",pixlocation);
    dish_settings.endGroup();

    qDebug() << "Dish saved successfully to dish_data.ini!";
}
