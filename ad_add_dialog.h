#ifndef AD_ADD_DIALOG_H
#define AD_ADD_DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "account_list.h"

namespace Ui {
class ad_add_Dialog;
}

class ad_add_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit ad_add_Dialog(QWidget *parent = 0);
    ~ad_add_Dialog();

private:
    Ui::ad_add_Dialog *ui;

    void addpart(QHash <QString, QString> &hash, QString pn, QString pwd);   //添加按钮的部分代码，模块化

private slots:
    void dialogshow();                 //自己界面显示

    void on_back_pushButton_clicked(); //返回到系统管理员界面

    void on_add_pushButton_clicked();  //添加账户

signals:
    void administrator_widgetshow();  //系统管理员的界面显示
};

#endif // AD_ADD_DIALOG_H
