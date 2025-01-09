#include "data.h"
#include<QCoreApplication>
#include<QSettings>
#include<QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    data w;
    w.show();
    Client c;
    c.setName("mike");
    c.addShopCart();
    c.createOrder();


    return a.exec();
}
