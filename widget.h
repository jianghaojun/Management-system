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

     void on_A1_pushButton_clicked();

     void on_A2_pushButton_clicked();

     void on_A3_pushButton_clicked();

     void on_A4_pushButton_clicked();

     void on_A5_pushButton_clicked();

     void on_A6_pushButton_clicked();

     void on_A7_pushButton_clicked();

     void on_A8_pushButton_clicked();

     void add_button_clicked();

     void delete_button_clicked();

     void receive_customer_pn(QString pn);    //接收从登录界面传来的顾客账号信息

     void on_order_pushButton_clicked();

     void on_pay_pushButton_clicked();

private:
    Ui::Widget *ui;

signals:
    void login_dialogshow();            //登录界面显示

};

#endif // WIDGET_H
