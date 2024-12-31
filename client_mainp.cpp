#include "client_mainp.h"
#include "ui_client_mainp.h"

Client_mainp::Client_mainp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Client_mainp)
{
    ui->setupUi(this);
}

Client_mainp::~Client_mainp()
{
    delete ui;
}
