#ifndef CLIENT_MAINP_H
#define CLIENT_MAINP_H

#include <QWidget>

namespace Ui {
class Client_mainp;
}

class Client_mainp : public QWidget
{
    Q_OBJECT

public:
    explicit Client_mainp(QWidget *parent = nullptr);
    ~Client_mainp();

private:
    Ui::Client_mainp *ui;
};

#endif // CLIENT_MAINP_H
