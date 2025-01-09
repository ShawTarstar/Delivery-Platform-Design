#ifndef SEVER_GOODS_H
#define SEVER_GOODS_H

#include <QWidget>
//#include "data.h"

namespace Ui {
class sever_goods;
}

class sever_goods : public QWidget
{
    Q_OBJECT

signals:
    void deletesignal(QString idx);

public:
    explicit sever_goods(QWidget *parent = nullptr);
    ~sever_goods();
    QString getbusinessName();

private slots:
    void on_back_clicked();

    void on_add_clicked();

    void deletefood(QString idx);

private:
    Ui::sever_goods *ui;

    QString idx;
};

#endif // SEVER_GOODS_H
