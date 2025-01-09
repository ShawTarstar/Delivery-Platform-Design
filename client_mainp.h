#ifndef CLIENT_MAINP_H
#define CLIENT_MAINP_H

#include <QWidget>
#include "food_show.h"
#include "shopcar.h"
#include "all_order.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class client_mainp;
}
QT_END_NAMESPACE

class client_mainp : public QWidget
{
    Q_OBJECT

public:
    client_mainp(QWidget *parent = nullptr);
    ~client_mainp();

private slots:
    void on_quitButton_clicked();



    void on_foodchoice_Button_clicked();

    void on_shopcar_Button_clicked();

    void on_ordermng_Button_clicked();



    void on_Client_id_label_linkActivated(const QString &link);

private:
    Ui::client_mainp *ui;
    food_show clint_food_show;
    shopcar clint_shopcar;
    all_order clint_all_order;

};
#endif // CLIENT_MAINP_H
