#include "data.h"
#include "ui_data.h"

/*************
 *[mike]
1003487984\num=1003487984
1003487984\sum=1.58e-321
1003487984\client_info=mike
1003487984\business_info=
1003487984\luosifen\name=luosifen
1003487984\luosifen\amount=1
1003487984\luosifen\price=12
1003487984\luosifen\pixlocation=123456
***********************/


QString order_data="order_data.ini";
QString temppath="user_temp.ini";
QSettings tempsettings(temppath,QSettings::IniFormat);

Order::Order()
{
    //通过时间戳生成订单编号
    QDateTime currentTime = QDateTime::currentDateTime();
    QString num = currentTime.toString("yyyyMMddhhmmss"); // 例如：20241230123045
}

void Order::setOrder(Client &client,Business &business)//设置订单信息
{//遍历购物车，如果勾选了就加入order.d[]
    double sum=0;//初始化订单总金额
    client_info=client.getName();
    business_info=business.getName();

    int dishIndex=0;

    for(int i=0;i<100;i++)
    {
        Dish dish_temp;
        //读入数据到dish_temp
        client.findShopCart(dish_temp.name,dish_temp.pixlocation,dish_temp.price,dish_temp.amount);

        bool isSelected=1;//此处连接购物车的checkbox信号

        if(!dish_temp.name.isEmpty()&&isSelected)
        {
            if(dishIndex<50)
            {
                d[dishIndex]=dish_temp;
                sum+=dish_temp.price*dish_temp.amount;
                dishIndex++;
            }
            else
            {
                qDebug()<<"超出订单数量限制";
                break;
            }
        }
    }
    qDebug() << "Order set successfully! Total dishes:" << dishIndex << "Total amount:" << sum;
    saveOrder();
}


void Order::saveOrder(void)
{
    QString severAccount;
    QStringList groups = tempsettings.childGroups();
    if (!groups.isEmpty()) {
        // 进入第一个节
        QString firstSection = groups.first();
        tempsettings.beginGroup(firstSection);
        severAccount=tempsettings.value("name").toString();

        tempsettings.endGroup(); // 结束访问组
    } else {
        qDebug() << "INI 文件中没有任何节。";
    }
    QSettings order_settings(order_data,QSettings::IniFormat);
    QString title=QString("%1/%2").arg(severAccount).arg(num);

    order_settings.beginGroup(title);
    order_settings.setValue("num",num);
    order_settings.setValue("sum",sum);
    order_settings.setValue("client_info",client_info);
    order_settings.setValue("business_info",business_info);

    for (int i = 0; i < 50 && !d[i].name.isEmpty(); ++i)
    {
        order_settings.beginGroup(d[i].name);
        order_settings.setValue("name",d[i].name);
        order_settings.setValue("amount",d[i].amount);
        order_settings.setValue("price",d[i].price);
        order_settings.setValue("pixlocation",d[i].pixlocation);
        order_settings.endGroup();
    }

    order_settings.endGroup();
    qDebug()<<"order saved succefully!";
}

/***********************
 * 调用时，按照如下规则调用：
 * findOrderInfo(商家名，订单编号，订单总金额)
 * 功能：遍历查找该商家的所有订单
 * *********************/
void Order::findOrderInfo(const QString &businessInfo,QString& num,double& sum)
{
    QSettings settings(order_data, QSettings::IniFormat);

    // 遍历所有 section
    foreach (const QString &group, settings.childGroups()) {
        settings.beginGroup(group);

        // 遍历所有键
        foreach (const QString &key, settings.childKeys()) {
            // 查找 'business_info' 是否有值，若有则继续查找相关信息
            if (key.contains("business_info") && settings.value(key).toString() == businessInfo)
            {
                num= key.split("/")[0];
                sum=settings.value(num+"/sum").toDouble();
                qDebug() <<"succefully get orderinfo";
            }
        }

        settings.endGroup();
    }
}
