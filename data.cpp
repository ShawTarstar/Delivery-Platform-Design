#include "data.h"
#include "ui_data.h"
#include <QRadioButton>
#include <QMessageBox>
#include "message_login.h"

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
    message_login* mess_log=new message_login(this);
    mess_log->show();
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

    if(ui->admin_Button->isChecked()){
        ////跳转到管理员界面


    }else if(ui->client_Button->isChecked()){
        ////跳转到顾客界面


    }
    else if(ui->sever_Button->isChecked()){
        ////跳转到商家界面


    }else{
        QMessageBox::information(this,"错误","请选择身份!");
    }
}

