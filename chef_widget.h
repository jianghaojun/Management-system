#ifndef CHEF_WIDGET_H
#define CHEF_WIDGET_H

#include <QWidget>
#include <QHeaderView>
#include <QMessageBox>
#include <QPushButton>
#include <QCloseEvent>
#include <QTimer>
#include <QTime>
#include "food.h"
#include "table.h"
#include "employee.h"
#include "account_list.h"
#include "menu_total.h"

namespace Ui {
class chef_widget;
}

class chef_widget : public QWidget
{
    Q_OBJECT

public:
    explicit chef_widget(QWidget *parent = 0);
    ~chef_widget();

private:
    Ui::chef_widget *ui;

    void clear_csmenu();                        //清空表格

    void clear_mymenu();

    void clear_donemennu();

    void closeEvent(QCloseEvent *event);        //关闭程序事件：在确认关闭时将数据上传

private slots:
    void widgetshow();                          //自己显示

    void on_back_pushButton_clicked();          //返回到登录界面

    void on_query_pushButton_clicked();         //查询餐桌菜单

    void claim_button_clicked();                //认领按钮，功能：将菜品添加到厨师的认领菜单中，并设置相应的食物状态为2，并设置食物的chef_id

    void finish_button_clicked();               //完成按钮，功能：将菜品从厨师的认领菜单中清除，添加到历史记录（donemenu）里面，设置相应的食物状态为3

    void on_searchtable_pushButton_clicked();   //查询餐桌按钮

    void on_clear_pushButton_2_clicked();       //清空表格按钮

    void on_clear_pushButton_clicked();         //清空表格按钮

    void receive_chef_pn(QString pn);           //槽，功能：接收从登录界面传来的手机号信息

    void showTime();                            //槽函数：时钟显示时间

signals:
    void login_dialogshow();                    //登录界面显示
};

#endif // CHEF_WIDGET_H
