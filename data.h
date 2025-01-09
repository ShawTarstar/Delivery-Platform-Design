#ifndef DATA_H
#define DATA_H

#include <QMainWindow>
#include<QFile>
#include<QSettings>
#include<QDateTime>
#include<QDir>

#include"message_login.h"
#include"rigister.h"
#include"sever_mainp.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class data;
}
QT_END_NAMESPACE
class Client;
class Order;
class Business;

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
{private:
    QString name;
    QString account;
    QString password;
    int accountType; //1:顾客 2:商家 3:管理员
public:
    static QString currentAccount;
    Users();
    void setName(QString s);
    void setAcoount(QString a);
    void setPasswrod(QString p);
    void setType(int n);
    QString getName(void);
    QString getAccount(void);
    QString getPassword(void);
    int getType(void);
    int search();//登录时使用

    void saveFile();

};

class Business:public Users
{public:
    Business();
    void addDishList(QString name,QString pixlocation,double price);
    void deleteDishList(QString);
    void modifyDishList(QString name,QString pixlocation,double price);
    bool findDishList(QString name,QString &pixlocation,double &price);
};

class Manager:public Users
{public:
    Manager();
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
    //Client();

    void addShopCart(QString name,QString pixlocation,double price,int amount);//加入购物车
    void deleteShopCart(QString name);//删除购物车商品
    void createOrder(Business business_temp);
    bool findShopCart(QString name,QString& pixlocation,double& price,int& amount);

};




class data : public QMainWindow
{
    Q_OBJECT

public:
    data(QWidget *parent = nullptr);
    ~data();

private slots:
    void on_register_Button_clicked();

    void on_confirm_Button_clicked();

    void on_message_Button_clicked();

private:
    Ui::data *ui;
};
#endif // DATA_H
