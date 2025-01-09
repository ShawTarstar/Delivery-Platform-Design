#ifndef ALL_ORDER_H
#define ALL_ORDER_H

#include <QWidget>

namespace Ui {
class all_order;
}

class all_order : public QWidget
{
    Q_OBJECT

public:
    explicit all_order(QWidget *parent = nullptr);
    ~all_order();

private slots:


    void on_food_pho_1_linkActivated(const QString &link);

    void on_food_name_1_linkActivated(const QString &link);

    void on_food_sumprice_label_linkActivated(const QString &link);

    void on_pay_stage_1_label_linkActivated(const QString &link);

    void on_food_pho_2_linkActivated(const QString &link);

    void on_food_name_2_linkActivated(const QString &link);

    void on_food_sumprice_2_linkActivated(const QString &link);

    void on_pay_stage_2_label_linkActivated(const QString &link);

    void on_back_to_main_Button_clicked();

private:
    Ui::all_order *ui;
};

#endif // ALL_ORDER_H
