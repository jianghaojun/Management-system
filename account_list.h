#ifndef ACCOUNT_LIST_H
#define ACCOUNT_LIST_H

#include <QHash>
#include <QMultiHash>
#include <QString>
#include <QDebug>

//系统管理员管理的账户列表,分成两个一个是顾客 Customer,另一个是雇员（服务员，厨师，经理）Employee

//QHash <QString, QString> Customer;    //第一个QString为手机号，第二个为密码，一一对应
//QHash <QString, QString> Employee;

//用数据库里面的数据初始化顾客账户列表:
void Customer_set(QHash <QString, QString> &hash);
void Employee_set(QHash <QString, QString> &hash);

//将储存在QHash表中的数据回传给数据库
void Customer_Upload(QHash <QString, QString> hash);
void Employee_Upload(QHash <QString, QString> hash);

//查看所有账户：
void showCaccount(QHash <QString, QString> hash);   //查看顾客账户信息
void showEaccount(QHash <QString, QString> hash);  //查看雇员账户信息

//查找某一特定用户的信息：
bool search_account(QHash <QString, QString> hash, QString pn, QString pwd);
bool search_account(QHash <QString, QString> hash, QString pn);                    //函数重载

//查找某一特定用户的密码：
QString search_account_pwd(QHash <QString, QString> hash, QString pn);

//重置密码：直接调用 iterator QHash::insert(const Key &key, const T &value) 旧的value会被覆盖

//增加（注册）账户：直接调用 iterator QHash::insert(const Key &key, const T &value)

//删除账户：直接调用 int QHash::remove(const Key &key)



#endif // ACCOUNT_LIST_H


