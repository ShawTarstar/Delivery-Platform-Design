#include "data.h"
#include "ui_data.h"
#include <QApplication>
#include <QSettings>
using namespace std;
/******************************************
 * 用户函数页cpp 邵倍溪
 * 将用户信息存在users_info.ini文件中，格式为
 * totalUsers=2
 * [User1]
 * accountType=1
 * name="Alice"
 * account="18211111111"
 * password="123456"
 * [User2]
 * accountType=3
 * name="Bob"
 * account="18212221111"
 * password="456789"
 * ****************************************/
Users::Users(){
}
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
//调用以保存用户密码
void Users:: setPasswrod(QString p)
{
    password=p;
}

void Users::setType(int n)
{
    accountType=n;
}
QString Users::getAccount(void)
{
    return account;
}
QString Users::getName(void)
{
    return name;
}
QString Users::getPassword(void)
{
    return password;
}
int Users::getType(void)
{
    return accountType;
}
/******************************************
 * 函数search
 * 使用类中的数据对文件users_info中的数据进行搜索。
 * 使用前务必设置好类中数据account和password。
 ******************************************/
int Users::search()
{
    //遍历用户组，如果找到与account和password匹配的数据，则返回账户类型（1,2,3）
    //如果找不到匹配数据，返回0
    QSettings infoRead("users_info.ini", QSettings::IniFormat);
    QStringList groups = infoRead.childGroups();
    // 遍历每个用户组
    for (const QString &group : groups) {
        infoRead.beginGroup(group);

        QString currentAccount = infoRead.value("account").toString();
        QString currentPassword = infoRead.value("password").toString();

        if (currentAccount == account && currentPassword == password) {
            int type = infoRead.value("accountType").toInt();
            infoRead.endGroup();
            return type;
        }
        infoRead.endGroup();
    }
    return 0;
}
/******************************************
 * 函数saveFile
 * 使用类中的数据对文件users_info中的数据进行搜索。
 * 使用前务必设置好类中全部的数据以便保存。
 ******************************************/
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
