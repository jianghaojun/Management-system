#ifndef WAITER_WIDGET_H
#define WAITER_WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QProgressBar>
#include <QHeaderView>
#include <QCloseEvent>
#include <QMouseEvent>
#include "table.h"
#include "food.h"
#include "employee.h"
#include "account_list.h"
#include "menu_total.h"

namespace Ui {
class waiter_widget;
}

class waiter_widget : public QWidget
{
    Q_OBJECT

public:
    explicit waiter_widget(QWidget *parent = 0);
    ~waiter_widget();

    void serverbutton_part(int i);                  //上面A1-A8中重复的代码

    void show_cs_menu(int table_number);            //显示顾客的菜单

    void clear_cs_menu();                           //清除顾客的菜单

private:
    Ui::waiter_widget *ui;

    void closeEvent(QCloseEvent *event);            //关闭程序事件：在确认关闭时将数据上传

private slots:
    void widgetshow();                              //自己显示

    void on_searchtable_pushButton_clicked();       //查询餐桌的状态

    void on_back_pushButton_clicked();              //注销按钮返回登录界面

    void on_A1_pushButton_clicked();                //第X桌的“服务”按钮

    void on_A2_pushButton_clicked();

    void on_A3_pushButton_clicked();

    void on_A4_pushButton_clicked();

    void on_A5_pushButton_clicked();

    void on_A6_pushButton_clicked();

    void on_A7_pushButton_clicked();

    void on_A8_pushButton_clicked();

    void addwater_message(QString table_number);    //槽函数：接受来自顾客加水的信息，服务员只接收自己服务桌子的信息

    void foodhurry_message(QString table_number);   //槽函数：接受来自顾客催菜的信息，服务员只接收自己服务桌子的信息

    void showTime();                                //槽函数：时钟显示时间

    void on_query_pushButton_clicked();             //查询进度

    void receive_waiter_pn(QString pn);             //槽，功能：接收从登录界面传来的手机号信息

signals:
    void login_dialogshow();                        //登录界面显示

};

#endif // WAITER_WIDGET_H
