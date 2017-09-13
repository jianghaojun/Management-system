#include <QMultiHash>
#include <QString>
#include <QList>
#include <iostream>

#include "food.h"
#include "menu_total.h"


//系统管理员管理的总菜单 Menu_total;

//总菜单的初始化，写在头文件中免得main.cpp中代码过多
void menu_set(QMultiHash <QString, Food> &hash)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("select * from menu_total");

    while(query.next())
    {
        int id;
        QString food_type;
        QString food_name;
        int food_price;
        double food_evaluation;
        id = query.value(0).toInt();
        food_type = query.value(1).toString();
        food_name = query.value(2).toString();
        food_price = query.value(3).toInt();
        food_evaluation = query.value(4).toDouble();
        Food f(food_name, id, food_price, food_evaluation);
        hash.insert(food_type, f);
    }
    /*
    query.exec("create table menu_total (id int primary key, food_type varchar,"
               "food_name varchar, food_price int, food_evaluation double)");
    query.exec("insert into menu_total values(1, 'Cold Dish', 'Salad', 20, 0)");
    query.exec("insert into menu_total values(2, 'Cold Dish', 'Tofu', 50, 0)");

    query.exec("insert into menu_total values(3, 'Main Course', 'Beef', 50, 0)");
    query.exec("insert into menu_total values(4, 'Main Course', 'Fish', 40, 0)");

    query.exec("insert into menu_total values(5, 'Soup', 'Seafood', 100, 0)");
    query.exec("insert into menu_total values(6, 'Soup', 'Borscht', 30, 0)");

    hash.insert("冷菜类", Food("沙拉", 1, 20));
    hash.insert("冷菜类", Food("凉拌海蜇", 2, 50));

    hash.insert("主菜类", Food("牛排", 3, 50));
    hash.insert("主菜类", Food("烤鱼", 4, 40));

    hash.insert("汤类", Food("海鲜汤", 5, 100));
    hash.insert("汤类", Food("罗宋汤", 6, 30));
    */
}

void menu_replace(QMultiHash <QString, Food> &hash, QString type, Food oldf, Food newf)
{
    hash.remove(type, oldf);
    hash.insert(type, newf);
    //cout<<"Succeed!"<<endl;
}

void menu_show(QMultiHash <QString, Food> hash)
{
    /*
    QMultiHash<QString, Food>::iterator i = hash.begin();
    while(i != hash.end())
    {
        Food f = i.value();
        qDebug() << i.key() <<endl;
        qDebug() << f.getName() <<endl;
        ++i;
    }
    */

    qDebug() << "<Cold Dish> :" << endl;
    QMultiHash<QString, Food>::iterator i1 = hash.find("Cold Dish");
    while (i1 != hash.end() && i1.key() == "Cold Dish")
    {
        Food f = i1.value();
        qDebug() << f.getName() << endl;
        ++i1;
    }

    qDebug() << "<Main Course> :" << endl;
    QMultiHash<QString, Food>::iterator i2 = hash.find("Main Course");
    while (i2 != hash.end() && i2.key() == "Main Course")
    {
        Food f = i2.value();
        qDebug() << f.getName() << endl;
        ++i2;
    }

    qDebug() << "<Soup> :" << endl;
    QMultiHash<QString, Food>::iterator i3 = hash.find("Soup");
    while (i3 != hash.end() && i3.key() == "Soup")
    {
        Food f = i3.value();
        qDebug() << f.getName() << endl;
        ++i3;
    }
}

bool search_food_id(QMultiHash<QString, Food> hash, QString food_type, int id)
{
    QMultiHash<QString, Food>::iterator i = hash.find(food_type);
    while (i != hash.end() && i.key() == food_type)
    {
        Food f = i.value();
        if(f.getID() == id)
        {
            return true;
        }
        ++i;
    }
    return false;
}

bool search_food(QMultiHash<QString, Food> hash, int id, QString food_name)
{
    QMultiHash<QString, Food>::iterator i = hash.begin();
    while (i != hash.end())
    {
        Food f = i.value();
        if(f.getID() == id || f.getName() == food_name)
        {
            return true;
        }
        ++i;
    }
    return false;
}

int search_food_price(QMultiHash<QString, Food> hash, QString food_type, int id)
{
    QMultiHash<QString, Food>::iterator i = hash.find(food_type);
    while (i != hash.end() && i.key() == food_type)
    {
        Food f = i.value();
        if(f.getID() == id)
        {
            return f.getPrice();
        }
        ++i;
    }
    return 0;
}

QString search_food_name(QMultiHash<QString, Food> hash, QString food_type, int id)
{
    QMultiHash<QString, Food>::iterator i = hash.find(food_type);
    QString s = "Not Exist!";
    while (i != hash.end() && i.key() == food_type)
    {
        Food f = i.value();
        if(f.getID() == id)
        {
            return f.getName();
        }
        ++i;
    }
    return s;
}

void menu_upload(QMultiHash<QString, Food> hash)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("delete from menu_total");

    QHash<QString, Food>::const_iterator i = hash.constBegin();
    while(i != hash.constEnd())
    {
        QString food_type = i.key();
        Food f = i.value();

        int id = f.getID();
        QString food_name = f.getName();
        int food_price = f.getPrice();
        double food_evaluation = f.getF_Evaluation();

        query.prepare("insert into menu_total(id, food_type, food_name, food_price,"
                      "food_evaluation) values(?, ?, ?, ?, ?)");
        query.addBindValue(id);
        query.addBindValue(food_type);
        query.addBindValue(food_name);
        query.addBindValue(food_price);
        query.addBindValue(food_evaluation);
        query.exec();
        ++i;
    }
}
