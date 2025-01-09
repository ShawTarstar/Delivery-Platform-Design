#ifndef ADMIN_MAINP_H
#define ADMIN_MAINP_H

#include <QWidget>

namespace Ui {
class Admin_mainp;
}

class Admin_mainp : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_mainp(QWidget *parent = nullptr);
    ~Admin_mainp();

private slots:
    void on_pbt_exit_clicked();

private:
    Ui::Admin_mainp *ui;
};

#endif // ADMIN_MAINP_H
