#ifndef ADMINISTRATOR_WIDGET_H
#define ADMINISTRATOR_WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include "account_list.h"
#include "food.h"
#include "menu_total.h"

namespace Ui {
class Administrator_widget;
}

class Administrator_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Administrator_widget(QWidget *parent = 0);
    ~Administrator_widget();

private:
    Ui::Administrator_widget *ui;

    void showmenu_part(QMultiHash <QString, Food> hash, QString food_type);

private slots:
    void widgetshow();   //自己显示

    void on_back_pushButton_clicked();      //返回登录界面，并且把修改数据返回到本地数据库中去！！！！！！！！！！！！

    void on_showC_pushButton_clicked();     //显示顾客账户

    void on_showE_pushButton_clicked();     //显示雇员账户

    void on_search_pushButton_clicked();    //查询账户

    void on_add_pushButton_clicked();       //添加账户

    void on_delete_pushButton_clicked();    //删除账户

    void on_upload_pushButton_clicked();    //上传数据

    void on_showmenu_pushButton_clicked();  //显示菜单

    void on_searchfood_pushButton_clicked();//查找菜品

    void on_addfood_pushButton_clicked();   //添加菜品

    void on_deletefood_pushButton_clicked();//删除菜品

    void on_uploadfood_pushButton_clicked();//上传数据

signals:
    void login_dialogshow();             //登录界面显示

    void ad_search_dialogshow();         //查询账号界面显示

    void ad_add_dialogshow();            //添加账号界面显示

    void ad_delete_dialogshow();         //删除账号界面显示

    void ad_searchmenu_dialogshow();     //查询菜品界面显示

};

#endif // ADMINISTRATOR_WIDGET_H
