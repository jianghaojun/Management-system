#include <QApplication>
#include <iostream>
#include <QString>
#include <QChar>
#include <QTextStream>
#include <QObject>
#include <QFile>

#include "table.h"
#include "employee.h"
#include "food.h"
#include "menu_total.h"
#include "account_list.h"
#include "database.h"
#include "widget.h"
#include "login_dialog.h"
#include "register_dialog.h"
#include "administrator_widget.h"
#include "ad_search_dialog.h"
#include "ad_add_dialog.h"
#include "ad_delete_dialog.h"
#include "ad_searchmenu_dialog.h"
#include "waiter_widget.h"
#include "chef_widget.h"
#include "manager_widget.h"
#include "ad_addmenu_dialog.h"
#include "ad_deletemenu_dialog.h"

QHash <QString, QString> Customer;       //存顾客账户
QHash <QString, QString> Manager;        //存经理的账户
QHash <QString, QString> System_manager; //存系统管理员的账户

QMultiHash <QString, Food> Menu_total;   //存总的菜单
QVector <QString> Food_picture_list;     //存对应食物的图片资源地址信息
QVector <Table> Table_list;              //存所有的桌子对象
QVector <Waiter> Waiter_list;            //存所有服务员对象
QVector <Chef> Chef_list;                //存所有厨师对象

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //初始化操作
    createdatabase();

    //账号信息表初始化
    Customer_set(Customer);
    Manager_set(Manager);
    System_manager_set(System_manager);

    //总菜单初始化
    Menu_set(Menu_total);
    Food_picture_list_set(Food_picture_list);

    //对象列表初始化
    Table_list_set(Table_list);
    Waiter_set(Waiter_list);
    Chef_set(Chef_list);

    //界面对象:
    login_Dialog logindialog;                   //登录界面
    register_Dialog registerdialog;             //注册界面
    Administrator_widget ad_widget;             //系统管理员界面
    ad_search_Dialog ad_search_dialog;          //系统管理员搜索账号界面
    ad_add_Dialog ad_add_dialog;                //系统管理员添加账号界面
    ad_delete_Dialog ad_delete_dialog;          //系统管理员删除账号界面
    ad_searchmenu_Dialog ad_searchmenu_dialog;  //系统管理员搜索菜品界面
    ad_addmenu_Dialog ad_addmenu_dialog;        //系统管理员添加菜品界面
    ad_deletemenu_Dialog ad_deletemenu_dialog;  //系统管理员删除菜品界面
    Widget cs_widget;                           //顾客界面
    waiter_widget waiterwidget;                 //服务员界面
    chef_widget chefwidget;                     //厨师界面
    manager_widget managerwidget;               //经理界面

    logindialog.show();

    //界面之间的信号与槽连接
    QObject::connect(&logindialog, SIGNAL(cs_widgetshow()), &cs_widget, SLOT(widgetshow()));             //登录界面到顾客界面
    QObject::connect(&logindialog, SIGNAL(register_dialogshow()), &registerdialog, SLOT(dialogshow()));  //登录界面到注册界面
    QObject::connect(&logindialog, SIGNAL(administrator_widgetshow()), &ad_widget, SLOT(widgetshow()));  //登录界面到系统管理员界面
    QObject::connect(&logindialog, SIGNAL(waiter_widgetshow()), &waiterwidget, SLOT(widgetshow()));      //登录界面到服务员界面
    QObject::connect(&logindialog, SIGNAL(chef_widgetshow()), &chefwidget, SLOT(widgetshow()));          //登录界面到厨师界面
    QObject::connect(&logindialog, SIGNAL(manager_widgetshow()), &managerwidget, SLOT(widgetshow()));    //登录界面到经理界面
    QObject::connect(&logindialog, SIGNAL(send_customer_pn(QString)), &cs_widget, SLOT(receive_customer_pn(QString)));  //登录界面给顾客界面传手机号
    QObject::connect(&logindialog, SIGNAL(send_waiter_pn(QString)), &waiterwidget, SLOT(receive_waiter_pn(QString)));   //登录界面给服务员界面传手机号
    QObject::connect(&logindialog, SIGNAL(send_chef_pn(QString)), &chefwidget, SLOT(receive_chef_pn(QString)));         //登录界面给厨师界面传手机号


    QObject::connect(&registerdialog, SIGNAL(login_dialogshow()), &logindialog, SLOT(dialogshow()));     //注册界面到登录界面
    QObject::connect(&cs_widget, SIGNAL(login_dialogshow()), &logindialog, SLOT(dialogshow()));          //顾客界面到登录界面
    QObject::connect(&waiterwidget, SIGNAL(login_dialogshow()), &logindialog, SLOT(dialogshow()));       //服务员界面到登录界面
    QObject::connect(&chefwidget, SIGNAL(login_dialogshow()), &logindialog, SLOT(dialogshow()));         //厨师界面到登录界面
    QObject::connect(&managerwidget, SIGNAL(login_dialogshow()), &logindialog, SLOT(dialogshow()));      //经理界面到登录界面

    QObject::connect(&ad_widget, SIGNAL(login_dialogshow()), &logindialog, SLOT(dialogshow()));                  //系统管理员界面到登录界面
    QObject::connect(&ad_widget, SIGNAL(ad_search_dialogshow()), &ad_search_dialog, SLOT(dialogshow()));         //系统管理员界面到查询账号界面
    QObject::connect(&ad_widget, SIGNAL(ad_add_dialogshow()), &ad_add_dialog, SLOT(dialogshow()));               //系统管理员界面到添加账号界面
    QObject::connect(&ad_widget, SIGNAL(ad_delete_dialogshow()), &ad_delete_dialog, SLOT(dialogshow()));         //系统管理员界面到删除账号界面

    QObject::connect(&ad_widget, SIGNAL(ad_searchmenu_dialogshow()), &ad_searchmenu_dialog, SLOT(dialogshow())); //系统管理员界面到查询菜品界面
    QObject::connect(&ad_widget, SIGNAL(ad_addmenu_dialogshow()), &ad_addmenu_dialog, SLOT(dialogshow()));       //系统管理员界面到添加菜品界面
    QObject::connect(&ad_widget, SIGNAL(ad_deletemenu_dialogshow()), &ad_deletemenu_dialog, SLOT(dialogshow())); //系统管理员界面到删除菜品界面

    QObject::connect(&ad_search_dialog, SIGNAL(administrator_widgetshow()), &ad_widget, SLOT(widgetshow()));     //查询账号界面到系统管理员界面
    QObject::connect(&ad_add_dialog, SIGNAL(administrator_widgetshow()), &ad_widget, SLOT(widgetshow()));        //添加账号界面到系统管理员界面
    QObject::connect(&ad_delete_dialog, SIGNAL(administrator_widgetshow()), &ad_widget, SLOT(widgetshow()));     //删除账号界面到系统管理员界面
    QObject::connect(&ad_searchmenu_dialog, SIGNAL(administrator_widgetshow()), &ad_widget, SLOT(widgetshow())); //查询菜品界面到系统管理员界面

    QObject::connect(&cs_widget, SIGNAL(addwater(QString)), &waiterwidget, SLOT(addwater_message(QString)));     //顾客发送加水的信息
    QObject::connect(&cs_widget, SIGNAL(foodhurry(QString)), &waiterwidget, SLOT(foodhurry_message(QString)));   //顾客发送催菜的信息

    return a.exec();
}
