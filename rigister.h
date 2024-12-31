#ifndef RIGISTER_H
#define RIGISTER_H

#include <QWidget>
#include "data.h"


namespace Ui {
class rigister;
}

class rigister : public QWidget
{
    Q_OBJECT

public:
    explicit rigister(QWidget *parent = nullptr);
    ~rigister();

private slots:
    void on_back_clicked();

    void on_confirm_Button_clicked();

private:
    Ui::rigister *ui;
};

#endif // RIGISTER_H
