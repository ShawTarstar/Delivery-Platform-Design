#ifndef SEVER_ORDER_H
#define SEVER_ORDER_H

#include <QWidget>
#include "sever_horder.h"

namespace Ui {
class sever_order;
}

class sever_order : public QWidget
{
    Q_OBJECT

public:
    explicit sever_order(QWidget *parent = nullptr);
    ~sever_order();

private slots:
    void on_pushButton_clicked();

    void on_back_clicked();

    void on_pushButton_2_clicked();

    void addline(int n,double price,int time);

private:
    Ui::sever_order *ui;

    sever_horder horderPage;
};

#endif // SEVER_ORDER_H
