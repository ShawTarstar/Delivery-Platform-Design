#ifndef SEVER_HORDER_H
#define SEVER_HORDER_H

#include <QWidget>

namespace Ui {
class sever_horder;
}

class sever_horder : public QWidget
{
    Q_OBJECT

public:
    explicit sever_horder(QWidget *parent = nullptr);
    ~sever_horder();

private slots:
    void on_back_clicked();

private:
    Ui::sever_horder *ui;
};

#endif // SEVER_HORDER_H
