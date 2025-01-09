#ifndef PAY_SUCCESS_H
#define PAY_SUCCESS_H

#include <QWidget>
#include <all_order.h>

namespace Ui {
class pay_success;
}

class pay_success : public QWidget
{
    Q_OBJECT

public:
    explicit pay_success(QWidget *parent = nullptr);
    ~pay_success();

private slots:
    void on_back_mainp_button_clicked();

    void on_look_order_button_clicked();

private:
    Ui::pay_success *ui;
    all_order client_pay_success;

};

#endif // PAY_SUCCESS_H
