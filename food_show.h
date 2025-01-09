#ifndef FOOD_SHOW_H
#define FOOD_SHOW_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class food_show;
}

class food_show : public QWidget
{
    Q_OBJECT

public:
    explicit food_show(QWidget *parent = nullptr);
    ~food_show();

private slots:
    void on_food_show_quit_clicked();

    void on_food_pho1_linkActivated(const QString &link);



    void on_food_add_1_clicked();

    void on_food_pho2_linkActivated(const QString &link);



    void on_food_add_2_clicked();

    void on_food_pho3_linkActivated(const QString &link);



    void on_food_add_3_clicked();

    void on_food_pho4_linkActivated(const QString &link);



    void on_food_add_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_food_name_1_label_linkActivated(const QString &link);

    void on_food_name_2_label__linkActivated(const QString &link);

    void on_food_name_2_label_linkActivated(const QString &link);

    void on_food_name_4_label_linkActivated(const QString &link);

private:
    Ui::food_show *ui;



};

#endif // FOOD_SHOW_H
