#ifndef MASTER_MENU_H
#define MASTER_MENU_H

#include <QMultiHash>
#include <QString>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include "Food.h"

//系统管理员管理的总菜单 Menu_total;

//总菜单的初始化，写在头文件中免得main.cpp中代码过多
void menu_set(QMultiHash <QString, Food> &hash);

//上传数据库
void menu_upload(QMultiHash <QString, Food> hash);

//修改：修改其中的一道菜，先删除原来的记录，再重新插入一条记录
void menu_replace(QMultiHash <QString, Food> &hash, QString type, Food oldf, Food newf);

//显示：输出菜单内的所有菜品
void menu_show(QMultiHash <QString, Food> hash);

//查找某一食物
bool search_food_id(QMultiHash <QString, Food> hash, QString food_type, int id);

bool search_food(QMultiHash <QString, Food> hash, int id, QString food_name);

int search_food_price(QMultiHash <QString, Food> hash, QString food_type, int id);

QString search_food_name(QMultiHash <QString, Food> hash, QString food_type, int id);

//增加：直接调用QMultiHash里的函数 insert（Key，Value）

//删除：直接调用QMultiHash里的函数 remove（Key，Value）


#endif // MASTER_MENU_H
