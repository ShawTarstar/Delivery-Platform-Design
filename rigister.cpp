#include "rigister.h"
#include "ui_rigister.h"
#include <QString>
#include <QMessageBox>

rigister::rigister(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::rigister)
{
    ui->setupUi(this);
}

rigister::~rigister()
{
    delete ui;
}

void rigister::on_back_clicked()
{
    this->close();
}

void rigister::on_confirm_Button_clicked()
{
    QString name=ui->name_lineEdit->text();
    QString password=ui->password_lineEdit->text();
    QString password2=ui->password2_lineEdit->text();
    QString tele=ui->tele_lineEdit->text();
    QString info=ui->captcha_lineEdit->text();

    if(name.isEmpty()||password.isEmpty()||password2.isEmpty()||tele.isEmpty()||info.isEmpty()){
        QMessageBox::information(this,"错误","信息不能为空!");
        return;
    }
    else if(password!=password2){
        QMessageBox::information(this,"错误","两次输入密码不一致!");
        return;
    }

    for(auto x:tele){
        if(x>'9'||x<'1'){
            QMessageBox::information(this,"错误","电话号码格式有误!");
            return;
        }
    }
    if(tele[0]!='1'||tele.size()!=11){
        QMessageBox::information(this,"错误","电话号码格式有误!");
        return;
    }

    for(auto x:password){
        if((x>='a'&&x<='z')||(x>='A'||x<='Z')||(x>='0'&&x<='9')||x=='_'||x=='.')continue;
        QMessageBox::information(this,"错误","密码只包含大小写字母、数字、下划线、小数点!");
        return;
    }

    if(!1){    ///此处填写信号
        QMessageBox::information(this,"提示","注册成功!");
        this->close();
    }

}

