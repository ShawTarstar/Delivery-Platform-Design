#ifndef SHOPCAR_H
#define SHOPCAR_H

#include <QWidget>
#include <pay_success.h>

namespace Ui {
class shopcar;
}

class shopcar : public QWidget
{
    Q_OBJECT

public:
    explicit shopcar(QWidget *parent = nullptr);
    ~shopcar();

private slots:




    void on_server_name_1_linkActivated(const QString &link);

    void on_add_1_clicked();

    void on_food_pho_1_linkActivated(const QString &link);

    void on_food_name_1_linkActivated(const QString &link);

    void on_food_perprice_1_linkActivated(const QString &link);

    void on_food_num_1_linkActivated(const QString &link);

    void on_radioButton_2_clicked();

    void on_food_pho_2_linkActivated(const QString &link);

    void on_food_name_2_linkActivated(const QString &link);

    void on_food_perpri_2_linkActivated(const QString &link);

    void on_food_num_2_linkActivated(const QString &link);

    void on_all_choose_button_clicked();

    void on_sum_price_linkActivated(const QString &link);

    void on_pay_button_clicked();

    void on_back_to_mainp_button_clicked();

    void on_manage_Button_clicked();

private:
    Ui::shopcar *ui;
    pay_success client_pay_success;
};

#endif // SHOPCAR_H
