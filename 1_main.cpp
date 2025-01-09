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
    //c.setName("mike");
    //c.addShopCart();
   // c.createOrder();

    // Client c;
    // c.setName("mike");
    // c.addShopCart();
    // c.createOrder();
    // Business b;
    // b.setName("bob");
    // b.addDishList();


    return a.exec();
}
