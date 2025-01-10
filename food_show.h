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
    void addfoodsData(const QString &foodname, const QString &amount, const QString &action);

private slots:
    void on_food_show_quit_clicked();
    void on_foodstable_cellActivated(int row, int column);

private:
    Ui::food_show *ui;



};

#endif // FOOD_SHOW_H
