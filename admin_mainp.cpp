#include "admin_mainp.h"
#include "ui_admin_mainp.h"
#include "data.h"
#include "amount.h"

#include <QApplication>
#include <QFile>
#include <QLabel>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QSettings>

Admin_mainp::Admin_mainp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Admin_mainp)
{
    ui->setupUi(this);
    QString filepath="users_info.ini";
    QSettings settings(filepath,QSettings::IniFormat);
    //读入数据
    //QString AdminAccount=Users::currentAccount;
    double Money=amount();
    int People=settings.value("totalUsers").toInt();
    //显示数据
    //ui->lab_ShowAccount->setText(AdminAccount);
    ui->lab_ShowMoney->setText(QString::number(Money,'f',2));
    ui->lab_ShowPeople->setText(QString::number(People));
}

Admin_mainp::~Admin_mainp()
{
    delete ui;
}

void Admin_mainp::on_pbt_exit_clicked()
{
    this->close();
}
