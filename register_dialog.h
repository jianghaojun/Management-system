#ifndef REGISTER_DIALOG_H
#define REGISTER_DIALOG_H

#include <QDialog>
#include "account_list.h"

namespace Ui {
class register_Dialog;
}

class register_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit register_Dialog(QWidget *parent = 0);
    ~register_Dialog();

private slots:
    void on_repushButton_clicked();    //注册按钮

    void dialogshow();                 //自己显示

    void on_backpushButton_clicked();  //返回按钮

private:
    Ui::register_Dialog *ui;

    void registerpart(QHash <QString, QString> &hash, QString pn, QString pwd);  //注册按钮的部分代码，模块化

signals:
    void login_dialogshow();          //登录界面显示

};

#endif // REGISTER_DIALOG_H
