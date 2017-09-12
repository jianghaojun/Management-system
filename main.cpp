#include <QApplication>
#include <iostream>
#include <QString>
#include <QChar>
#include <QTextStream>
#include <QObject>

#include "table.h"
#include "employee.h"
#include "Food.h"
#include "menu_total.h"
#include "account_list.h"
#include "list.h"
#include "database.h"
#include "widget.h"
#include "login_dialog.h"
#include "register_dialog.h"
#include "administrator_widget.h"
#include "ad_search_dialog.h"
#include "ad_add_dialog.h"
#include "ad_delete_dialog.h"
#include "ad_searchmenu_dialog.h"

//QTextStream cin(stdin, QIODevice::ReadOnly);
//QTextStream cout(stdout, QIODevice::WriteOnly);

QHash <QString, QString> Customer;       //存顾客账户
QHash <QString, QString> Employee;       //存雇员账户
QMultiHash <QString, Food> Menu_total;   //存总的菜单
QVector <Table> Table_list;              //存所有的桌子
QVector <Waiter> Waiter_list;
QVector <Chef> Chef_list;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    createdatabase();
    Customer_set(Customer);
    Employee_set(Employee);
    menu_set(Menu_total);
    table_list_set(Table_list);
    waiter_list_set(Waiter_list);
    chef_list_set(Chef_list);


    //界面对象:
    Widget cs_widget;                           //顾客界面
    login_Dialog logindialog;                   //登录界面
    register_Dialog registerdialog;             //注册界面
    Administrator_widget ad_widget;             //系统管理员界面
    ad_search_Dialog ad_search_dialog;          //系统管理员搜索账号界面
    ad_add_Dialog ad_add_dialog;                //系统管理员添加账号界面
    ad_delete_Dialog ad_delete_dialog;          //系统管理员删除账号界面
    ad_searchmenu_Dialog ad_searchmenu_dialog;  //系统管理员搜索菜品界面

    //logindialog.show();
    cs_widget.show();

    QObject::connect(&logindialog, SIGNAL(cs_widgetshow()), &cs_widget, SLOT(widgetshow()));             //登录界面到顾客界面
    QObject::connect(&logindialog, SIGNAL(send_customer_pn(QString)), &cs_widget, SLOT(receive_customer_pn(QString)));  //登录界面给顾客界面传手机号
    QObject::connect(&logindialog, SIGNAL(register_dialogshow()), &registerdialog, SLOT(dialogshow()));  //登录界面到注册界面
    QObject::connect(&logindialog, SIGNAL(administrator_widgetshow()), &ad_widget, SLOT(widgetshow()));  //登录界面到系统管理员界面

    QObject::connect(&registerdialog, SIGNAL(login_dialogshow()), &logindialog, SLOT(dialogshow()));     //注册界面到登录界面

    QObject::connect(&cs_widget, SIGNAL(login_dialogshow()), &logindialog, SLOT(dialogshow()));          //顾客界面到登录界面

    QObject::connect(&ad_widget, SIGNAL(login_dialogshow()), &logindialog, SLOT(dialogshow()));                  //系统管理员界面到登录界面
    QObject::connect(&ad_widget, SIGNAL(ad_search_dialogshow()), &ad_search_dialog, SLOT(dialogshow()));         //系统管理员界面到查询账号界面
    QObject::connect(&ad_widget, SIGNAL(ad_add_dialogshow()), &ad_add_dialog, SLOT(dialogshow()));               //系统管理员界面到添加账号界面
    QObject::connect(&ad_widget, SIGNAL(ad_delete_dialogshow()), &ad_delete_dialog, SLOT(dialogshow()));         //系统管理员界面到删除账号界面
    QObject::connect(&ad_widget, SIGNAL(ad_searchmenu_dialogshow()), &ad_searchmenu_dialog, SLOT(dialogshow())); //系统管理员界面到查询账号界面

    QObject::connect(&ad_search_dialog, SIGNAL(administrator_widgetshow()), &ad_widget, SLOT(widgetshow()));     //查询账号界面到系统管理员界面
    QObject::connect(&ad_add_dialog, SIGNAL(administrator_widgetshow()), &ad_widget, SLOT(widgetshow()));        //添加账号界面到系统管理员界面
    QObject::connect(&ad_delete_dialog, SIGNAL(administrator_widgetshow()), &ad_widget, SLOT(widgetshow()));     //删除账号界面到系统管理员界面
    QObject::connect(&ad_searchmenu_dialog, SIGNAL(administrator_widgetshow()), &ad_widget, SLOT(widgetshow())); //查询菜品界面到系统管理员界面

    return a.exec();
}
