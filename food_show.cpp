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
    ui->foodstable->setColumnCount(3);
    QStringList foodList;
    foodList << "名称";
    foodList << "价格";
    foodList << "操作";
    ui->foodstable->setHorizontalHeaderLabels(foodList);
    ui->foodstable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); ///设置列宽


}

food_show::~food_show()
{
    delete ui;
}

void food_show::on_food_show_quit_clicked()
{
    (this)->close();
}





void food_show::on_foodstable_cellActivated(int row, int column)
{

}

