#include "database.h"

void createdatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE" ,"DB");

    db.setDatabaseName("database.db");

    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);

    //Customer账户信息表
    query.exec("create table customer ( phone_number varchar primary key,"
                " password varchar)");
    query.exec("insert into customer values('13051327250', '123456')");
    query.exec("insert into customer values('18810301889', '123456')");
    query.exec("insert into customer values('1', '1')");

    //Waiter账户信息表
    query.exec("create table waiter ( phone_number varchar,"
                " password varchar, id varchar primary key, evaluate varchar, count int, sum double)");
    query.exec("insert into waiter values('1', '1', '1','0', 0, 0)");
    query.exec("insert into waiter values('2', '1', '2','0', 0, 0)");
    query.exec("insert into waiter values('13051327250', '123456', '3', '0', 0, 0)");

    //Chef账户信息表
    query.exec("create table chef ( phone_number varchar,"
               " password varchar, id varchar primary key, evaluate varchar, count int, sum double)");
    query.exec("insert into chef values('3', '1', '1', '0', 0, 0)");
    query.exec("insert into chef values('4', '1', '2', '0', 0, 0)");
    query.exec("insert into chef values('18810301889', '123456', '3', '0', 0, 0)");

    //Manager账户信息表
    query.exec("create table manager ( phone_number varchar primary key,"
                " password varchar)");
    query.exec("insert into manager values('5', '1')");

    //System Manager 账户信息表
    query.exec("create table system_manager ( phone_number varchar primary key,"
                " password varchar)");
    query.exec("insert into system_manager values('6', '1')");

    //总菜单表
    query.exec("create table menu_total (id int primary key, food_type varchar,"
               "food_name varchar, food_price int, food_evaluation double)");
    query.exec("insert into menu_total values(1, 'Cold Dish', 'Salad', 20, 0)");
    query.exec("insert into menu_total values(2, 'Cold Dish', 'Tofu', 50, 0)");

    query.exec("insert into menu_total values(3, 'Main Course', 'Beef', 50, 0)");
    query.exec("insert into menu_total values(4, 'Main Course', 'Fish', 40, 0)");

    query.exec("insert into menu_total values(5, 'Soup', 'Seafood', 100, 0)");
    //query.exec("insert into menu_total values(6, 'Soup', 'Borscht', 30, 0)");
}
