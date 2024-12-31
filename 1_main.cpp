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

    Business b;
    b.addDishList();
    b.deleteDishList();

    return a.exec();
}
