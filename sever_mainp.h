#ifndef SEVER_MAINP_H
#define SEVER_MAINP_H

#include <QWidget>

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
    void on_back_clicked();

private:
    Ui::sever_mainp *ui;
};

#endif // SEVER_MAINP_H
