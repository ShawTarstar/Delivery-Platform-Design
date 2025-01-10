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
    void addOrderData(const QString &orderNumber, const QString &amount, const QString &time, const QString &operation);

private slots:

    void on_back_clicked();

    void on_ordertable_cellActivated(int row, int column);

private:
    Ui::all_order *ui;
};

#endif // ALL_ORDER_H
