#include "amount.h"
#include <QSettings>
#include <QString>
double amount()
{
    double money=0;
    QSettings infoRead("order_data.ini", QSettings::IniFormat);
    QStringList groups = infoRead.childGroups();
    // 遍历每个订单组
    for (const QString &group : groups)
    {
        infoRead.beginGroup(group);
        double sum = infoRead.value("sum").toDouble();
        money += sum;
    }
    infoRead.endGroup();
    return money;
}
