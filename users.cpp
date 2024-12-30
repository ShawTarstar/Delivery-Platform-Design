#include "data.h"
#include "ui_data.h"
#include <QApplication>
#include <QSettings>
using namespace std;
/******************************************
 * 用户函数页cpp
 * 在文件users_info.ini中存储用户信息。
 * 格式为：
 *
 * 用户名处使用‘*’占位.
 * users_info初始存在一个用户Alice
 * ****************************************/
Users::Users(){}
//调用以保存用户名
void Users::setName(QString s)
{
    name=s;
}
//调用以保存用户账号
void Users:: setAcoount(QString a)
{
    account=a;
}

void Users:: setPasswrod(QString p)
{
    password=p;
}

void Users::setType(int n)
{
    accountType=n;
}

int Users::search()
{
    return 0;
}
void Users::saveFile()
{
    QSettings infoWrite=QSettings("users_info.ini",QSettings::IniFormat);
    // 获取当前总用户数
    int totalUsers = infoWrite.value("TotalUsers", 0).toInt();
    int currentID = totalUsers + 1;
    while(infoWrite.childGroups().contains(QString("User%1").arg(currentID))){
        currentID++;
    } //遍历获得下一个加入
    QString groupName = QString("User%1").arg(currentID);
    // 写入数据
    infoWrite.beginGroup(groupName);
    infoWrite.setValue("accountType", accountType);
    infoWrite.setValue("name", name);
    infoWrite.setValue("account", account);
    infoWrite.setValue("password", password);
    infoWrite.setValue("TotalUsers",currentID);
    infoWrite.endGroup();

}
