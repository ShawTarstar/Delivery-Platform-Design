#include "message_login.h"
#include "ui_message_login.h"

message_login::message_login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::message_login)
{
    ui->setupUi(this);
}

message_login::~message_login()
{
    delete ui;
}

void message_login::on_pushButton_2_clicked()
{
    this->close();
}
