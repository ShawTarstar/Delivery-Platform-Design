#include "data.h"
#include "ui_data.h"
#include <QRadioButton>
#include <QMessageBox>
#include "message_login.h"
#include "rigister.h"
#include "client_mainp.h"
#include "admin_mainp.h"


/************
 * user_temp.ini
 * 用于存储当前使用页面者的基本信息
 * [User1]
 * accountType=1
 * name="Alice"
 * account="18211111111"
 * password="123456"
 **************/
QString user_temp="user_temp.ini";

data::data(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::data)
{
    ui->setupUi(this);
}

data::~data()
{
    delete ui;
}
void data::on_message_Button_clicked()
{
    message_login* mess_log=new message_login;
    mess_log->show();
}
void data::on_register_Button_clicked()
{
    rigister* reg=new rigister;
    reg->show();
}

void data::on_confirm_Button_clicked()
{
    QString id=ui->userID_lineEdit->text();
    QString password=ui->user_password_lineEdit->text();

    if(id.isEmpty()||password.isEmpty()){
        QMessageBox::information(this,"错误","信息不能为空!");
        return;
    }
    if(!1){  ///此处填写信号
        QMessageBox::information(this,"错误","账号或密码错误!");
        return;
    }
    Users u;
    u.setAcoount(id);
    u.setPasswrod(password);
<<<<<<< HEAD

    int flag=u.search();
=======
    QString findname="0";
    int flag=u.search(findname);
    u.setName(findname);
>>>>>>> 607358d0f8788a7c5d5e884324ac7fc268ac7169
    if(flag==0){
        QMessageBox::information(this,"错误","账号或密码错误");
    }
    else if(flag==1){
        QMessageBox::information(this,"成功","欢迎顾客进入系统");
        QSettings settings(user_temp,QSettings::IniFormat);
        settings.beginGroup(id);
        settings.setValue("accountType", u.getAccount());
        settings.setValue("name",u.getName());
        settings.setValue("account", u.getAccount());
        settings.setValue("password", u.getPassword());
        settings.endGroup();
        client_mainp* c_m=new client_mainp;
        c_m->show();
        //this->close();
    }
    else if(flag==2){
        QMessageBox::information(this,"成功","欢迎商家进入系统");
        QSettings settings(user_temp,QSettings::IniFormat);
        settings.beginGroup(id);
        settings.setValue("accountType", u.getAccount());
        settings.setValue("name",u.getName());
        settings.setValue("account", u.getAccount());
        settings.setValue("password", u.getPassword());
        settings.endGroup();

        sever_mainp* s_m=new sever_mainp;
        s_m->show();
        //this->close();
    }
    else if(flag==3){
        QMessageBox::information(this,"成功","欢迎管理员进入系统");
        Admin_mainp* a_m=new Admin_mainp;
        a_m->show();
    }
}

