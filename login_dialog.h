#ifndef LOGIN_DIALOG_H
#define LOGIN_DIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class login_Dialog;
}

class login_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit login_Dialog(QWidget *parent = 0);
    ~login_Dialog();

private slots:
    void on_loginpushButton_clicked();      //登录按钮

    void on_registerpushButton_clicked();   //注册按钮

    void on_quitpushButton_clicked();       //退出按钮

    void dialogshow();

private:
    Ui::login_Dialog *ui;

signals:
    void cs_widgetshow();             //顾客界面显示

    void register_dialogshow();       //注册界面显示

    void administrator_widgetshow();  //系统管理员的界面显示

    void waiter_widgetshow();         //服务员界面显示

    void chef_widgetshow();           //厨师界面显示

    void send_customer_pn(QString);   //向顾客界面传送顾客的手机号
};

#endif // LOGIN_DIALOG_H
