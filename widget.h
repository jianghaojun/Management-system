#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QIcon>
#include <QPixmap>
#include <QPushButton>
#include <QString>
#include <QMultiHash>
#include <QHash>
#include <QMessageBox>
#include <QDebug>
#include <QHeaderView>
#include <QDoubleSpinBox>
#include <QProgressBar>
#include "food.h"
#include "table.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_back_pushButton_clicked();  //注销返回按钮

     void widgetshow();                 //自己显示

     void on_A1_pushButton_clicked();         //第X桌的“上座”按钮

     void on_A2_pushButton_clicked();

     void on_A3_pushButton_clicked();

     void on_A4_pushButton_clicked();

     void on_A5_pushButton_clicked();

     void on_A6_pushButton_clicked();

     void on_A7_pushButton_clicked();

     void on_A8_pushButton_clicked();

     void seatbutton_part(int i );            //上面A1-A8中重复的代码

     void add_button_clicked();               //点菜按钮，功能：将菜品添加到我的菜单里

     void delete_button_clicked();            //删除按钮，功能：删除我的菜单里已经添加的菜品

     void receive_customer_pn(QString pn);    //槽，功能：接收从登录界面传来的顾客账号信息

     void on_order_pushButton_clicked();      //下单按钮，功能：设置各个菜的状态为已下单（0），并设置进度显示

     void on_pay_pushButton_clicked();        //买单按钮，功能：显示总金额和支付方式以及设置评价表

     void on_query_pushButton_clicked();      //查询进度，功能：查看下单菜品的进度

     void on_water_pushButton_clicked();      //加水按钮，功能：向服务员发送加水的信息

     void on_querytable_pushButton_clicked(); //查询餐桌，功能：查看餐桌的空闲情况

     void on_hurry_pushButton_clicked();      //催菜按钮，功能：向服务员发送催菜的信息

private:
    Ui::Widget *ui;

signals:
    void login_dialogshow();                  //登录界面显示

    void addwater();                          //向服务员发送加水的信息

    void foodhurry();                         //向服务员发送催菜的信息

};

#endif // WIDGET_H
