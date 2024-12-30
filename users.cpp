#include "data.h"
#include "ui_data.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
using namespace std;
/******************************************
 * 用户函数页cpp
 * 在文件users_info中存储用户信息。
 * 格式为：
 * 【序号】【账号类别】【用户名】【账号】【密码】
 * eg.00001,2,Alice*******,18288888888,123456
 *    00002,1,Bob*********,18222221111,123456
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

int Users::search()
{
    return 0;
}
void Users::saveFile()
{
    // 打开 users_info.txt 文件（读取模式）
    QFile inputFile("users_info.txt");
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件 users_info.txt";
        return;
    }

    QTextStream in(&inputFile);
    QString firstLine = in.readLine(); // 读取第一行
    inputFile.close();

    if (firstLine.isEmpty()) {
        qDebug() << "users_info.txt 文件为空或第一行为空";
        return;
    }

    // 将第一行内容写入 test_info.txt 文件
    QFile outputFile("test_info.txt");
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件 test_info.txt";
        return;
    }

    QTextStream out(&outputFile);
    out << firstLine; // 写入内容
    outputFile.close();

    qDebug() << "已将第一行写入 test_info.txt";
}
