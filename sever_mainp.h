#ifndef SEVER_MAINP_H
#define SEVER_MAINP_H

#include <QWidget>
#include "sever_goods.h"
#include "sever_order.h"

namespace Ui {
class sever_mainp;
}

class sever_mainp : public QWidget
{
    Q_OBJECT

public:
    explicit sever_mainp(QWidget *parent = nullptr);
    ~sever_mainp();

private slots:
    void on_food_manage_clicked();

    void on_order_manage_clicked();

private:
    Ui::sever_mainp *ui;

    sever_goods goodsPage;
    sever_order orderPage;
};

#endif // SEVER_MAINP_H
