#ifndef MESSAGE_LOGIN_H
#define MESSAGE_LOGIN_H

#include <QWidget>

namespace Ui {
class message_login;
}

class message_login : public QWidget
{
    Q_OBJECT

public:
    explicit message_login(QWidget *parent = nullptr);
    ~message_login();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::message_login *ui;
};

#endif // MESSAGE_LOGIN_H
