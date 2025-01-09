#include "food_show.h"
#include "ui_food_show.h"
#include <QLabel>
#include <QPixmap>
#include <QFileDialog>
#include <QString>

food_show::food_show(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::food_show)

{
    ui->setupUi(this);


}

food_show::~food_show()
{
    delete ui;
}

void food_show::on_food_show_quit_clicked()
{
    (this)->close();
}


void food_show::on_food_pho1_linkActivated(const QString &link)
{



}





void food_show::on_food_add_1_clicked()
{

}


void food_show::on_food_pho2_linkActivated(const QString &link)
{

}





void food_show::on_food_add_2_clicked()
{

}


void food_show::on_food_pho3_linkActivated(const QString &link)
{

}





void food_show::on_food_add_3_clicked()
{

}


void food_show::on_food_pho4_linkActivated(const QString &link)
{

}



void food_show::on_food_add_4_clicked()
{

}


void food_show::on_pushButton_clicked()
{

}


void food_show::on_pushButton_2_clicked()
{

}


void food_show::on_food_name_1_label_linkActivated(const QString &link)
{

}


void food_show::on_food_name_2_label__linkActivated(const QString &link)
{

}


void food_show::on_food_name_2_label_linkActivated(const QString &link)
{

}


void food_show::on_food_name_4_label_linkActivated(const QString &link)
{

}

