#ifndef ACCOUNT_LIST_H
#define ACCOUNT_LIST_H

#include <QHash>
#include <QMultiHash>
#include <QString>
#include <QDebug>
#include <QVector>
#include "employee.h"
#include "table.h"

//系统管理员管理的账户列表

//QHash <QString, QString> Customer;         第一个QString为手机号，第二个为密码，一一对应
//QHash <QString, QString> Employee;
//QHash <QString, QString> Manager;          存经理的账户
//QHash <QString, QString> System_manager;   存系统管理员的账户

//用数据库里面的数据初始化列表:
void Customer_set(QHash <QString, QString> &hash);
void Employee_set(QHash <QString, QString> &hash);
void Manager_set(QHash <QString, QString> &hash);
void System_manager_set(QHash <QString, QString> &hash);
void Waiter_set(QVector <Waiter> &vector);
void Chef_set(QVector <Chef> &vector);
void Food_picture_list_set(QVector <QString> &list);
void Table_list_set(QVector <Table> &list);

//将储存在QHash表中的数据回传给数据库
void Customer_Upload(QHash <QString, QString> hash);
void Employee_Upload(QHash <QString, QString> hash);
void Manager_Upload(QHash <QString, QString> hash);
void System_manager_Upload(QHash <QString, QString> hash);
void Waiter_Upload(QVector <Waiter> vector);
void Chef_Upload(QVector <Chef> vector);

//查找某一特定用户的信息（函数重载）：
bool search_account(QHash <QString, QString> hash, QString pn, QString pwd);
bool search_account(QVector <Waiter> vector, QString pn, QString pwd);
bool search_account(QVector <Chef> vector, QString pn, QString pwd);

bool search_account(QVector <Waiter> vector, QString pn, int id);
bool search_account(QVector <Chef> vector, QString pn, int id);

bool search_account(QHash <QString, QString> hash, QString pn);
bool search_account(QVector <Waiter> vector, QString pn);
bool search_account(QVector <Chef> vector, QString pn);

//查找某一特定用户的密码（函数重载）：
QString search_account_pwd(QHash <QString, QString> hash, QString pn);
QString search_account_pwd(QVector <Waiter> vector, QString pn);
QString search_account_pwd(QVector <Chef> vector, QString pn);


//重置密码：直接调用 iterator QHash::insert(const Key &key, const T &value) 旧的value会被覆盖

//增加（注册）账户：直接调用 iterator QHash::insert(const Key &key, const T &value)

//删除账户：直接调用 int QHash::remove(const Key &key)

//查看所有账户：
//void showCaccount(QHash <QString, QString> hash);   //查看顾客账户信息
//void showEaccount(QHash <QString, QString> hash);  //查看雇员账户信息

#endif // ACCOUNT_LIST_H


