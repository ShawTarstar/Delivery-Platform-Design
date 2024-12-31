#ifndef DATA_H
#define DATA_H

#include <QMainWindow>
#include<QFile>
#include<QSettings>
#include<QDateTime>
#include<QDir>

class Client;
class Business;

QT_BEGIN_NAMESPACE
namespace Ui {
class data;
}
QT_END_NAMESPACE
class Dish
{
public:
    QString name;
    int amount;//购物车中的菜品数量，初始值由程序设定，用户无需处理
    double price;
    QString pixlocation;//图片地址


    Dish();

};


class Users
{public:
    QString name;
    QString account;
    QString password;
    int accountType; //新增：账号类型
    Users();
    void setName(QString s);

    void setAcoount(QString a);

    void setPasswrod(QString p);

    void setType(int n);

    int search();//登录时使用

    void saveFile();

};
class Order
{
public:
    Dish d[50];
    int num;//订单序号
    double sum;//订单总金额
    QString client_info;//购买人名
    QString business_info;//商家名

    Order();
    void setOrder(Client &client,Business &business);//设置订单信息
    void saveOrder(Client &client);
};
class Client:public Users
{public:
    Client();
    double discount[100];//优惠券
    Order orderList[100];

    Dish ShopCart[100];//购物车

    void addShopCart();//加入购物车
    void deleteShopCart();//删除购物车商品
    void createOrder();

};

class Business:public Users
{public:
    Business();
    Dish dishlist[100];
    void addDishList();
    void deleteDishList();
    void modifyDishList();

};

class Manager:public Users
{public:
    Manager();
};

//


class data : public QMainWindow
{
    Q_OBJECT

public:
    data(QWidget *parent = nullptr);
    ~data();

private:
    Ui::data *ui;
};
#endif // DATA_H
