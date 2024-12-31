#include "sever_mainp.h"
#include "ui_sever_mainp.h"

sever_mainp::sever_mainp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sever_mainp)
{
    ui->setupUi(this);
}

sever_mainp::~sever_mainp()
{
    delete ui;
}
