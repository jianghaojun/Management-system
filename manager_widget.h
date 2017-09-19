#ifndef MANAGER_WIDGET_H
#define MANAGER_WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>
#include <QTimer>
#include <QTime>
#include "employee.h"
#include "food.h"
#include "account_list.h"
#include "menu_total.h"

namespace Ui {
class manager_widget;
}

class manager_widget : public QWidget
{
    Q_OBJECT

public:
    explicit manager_widget(QWidget *parent = 0);
    ~manager_widget();

private:
    Ui::manager_widget *ui;

    void clear_waiterwidget();

    void clear_chefwidget();

    void closeEvent(QCloseEvent *event);     //关闭程序事件：在确认关闭时将数据上传

private slots:
    void on_back_pushButton_clicked();  //注销返回按钮

    void widgetshow();                  //自己显示

    void on_query_pushButton_clicked(); //查询按钮

    void showTime();                    //槽函数：时钟显示时间

signals:
    void login_dialogshow();            //登录界面显示
};

#endif // MANAGER_WIDGET_H
