#include "account_list.h"
#include "database.h"
#include <QDebug>

//初始化列表:

void Customer_set(QHash <QString, QString> &hash)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("select * from customer");
    while(query.next())
    {
        QString pn;
        QString pwd;
        pn = query.value(0).toString();
        pwd = query.value(1).toString();
        hash.insert(pn, pwd);
    }
}

void Employee_set(QHash <QString, QString> &hash)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("select * from employee");
    while(query.next())
    {
        QString pn;
        QString pwd;
        pn = query.value(0).toString();
        pwd = query.value(1).toString();
        hash.insert(pn, pwd);
    }
}

void Manager_set(QHash <QString, QString> &hash)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("select * from manager");
    while(query.next())
    {
        QString pn;
        QString pwd;
        pn = query.value(0).toString();
        pwd = query.value(1).toString();
        hash.insert(pn, pwd);
    }
}

void System_manager_set(QHash <QString, QString> &hash)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("select * from system_manager");
    while(query.next())
    {
        QString pn;
        QString pwd;
        pn = query.value(0).toString();
        pwd = query.value(1).toString();
        hash.insert(pn, pwd);
    }
}

void Waiter_set(QVector <Waiter> &vector)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("select * from waiter");
    while(query.next())
    {
        QString pn;
        QString pwd;
        int id;
        double evaluate;
        int count;
        double sum;
        pn = query.value(0).toString();
        pwd = query.value(1).toString();
        id = query.value(2).toInt();
        evaluate= query.value(3).toDouble();
        count = query.value(4).toInt();
        sum = query.value(5).toDouble();
        Waiter w(id, pn, pwd, evaluate, count, sum);
        vector.push_back(w);
    }
}

void Chef_set(QVector <Chef> &vector)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("select * from chef");
    while(query.next())
    {
        QString pn;
        QString pwd;
        int id;
        double evaluate;
        int count;
        double sum;
        pn = query.value(0).toString();
        pwd = query.value(1).toString();
        id = query.value(2).toInt();
        evaluate= query.value(3).toDouble();
        count = query.value(4).toInt();
        sum = query.value(5).toDouble();
        Chef c(id, pn, pwd, evaluate, count, sum);
        vector.push_back(c);
    }
}

void Food_picture_list_set(QVector<QString> &list)
{
    QString p1 = ":/image/images/salad.png";
    QString p2 = ":/image/images/tofu.png";
    QString p3 = ":/image/images/beef.png";
    QString p4 = ":/image/images/fish.png";
    QString p5 = ":/image/images/seafood.png";
    QString p6 = ":/image/images/borscht.png";
    list.push_back(p1);
    list.push_back(p2);
    list.push_back(p3);
    list.push_back(p4);
    list.push_back(p5);
    list.push_back(p6);
}

void Table_list_set(QVector<Table> &list)
{
    Table t1(1);
    Table t2(2);
    Table t3(3);
    Table t4(4);
    Table t5(5);
    Table t6(6);
    Table t7(7);
    Table t8(8);
    list.push_back(t1);
    list.push_back(t2);
    list.push_back(t3);
    list.push_back(t4);
    list.push_back(t5);
    list.push_back(t6);
    list.push_back(t7);
    list.push_back(t8);
}

//将储存在QHash表中的顾客账户数据回传给数据库:

void Customer_Upload(QHash <QString, QString> hash)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("delete from customer");

    QHash<QString, QString>::const_iterator i = hash.constBegin();
    while (i != hash.constEnd())
    {
        QString pn;
        QString pwd;
        pn = i.key();
        pwd = i.value();
        query.prepare("insert into customer(phone_number, password) values(?, ?)");
        query.addBindValue(pn);
        query.addBindValue(pwd);
        query.exec();
        ++i;
    }
}

void Employee_Upload(QHash <QString, QString> hash)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("delete from employee");

    QHash<QString, QString>::const_iterator i = hash.constBegin();
    while (i != hash.constEnd())
    {
        QString pn;
        QString pwd;
        pn = i.key();
        pwd = i.value();
        query.prepare("insert into employee(phone_number, password) values(?, ?)");
        query.addBindValue(pn);
        query.addBindValue(pwd);
        query.exec();
        ++i;
    }
}

void Manager_Upload(QHash<QString, QString> hash)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("delete from manager");

    QHash<QString, QString>::const_iterator i = hash.constBegin();
    while (i != hash.constEnd())
    {
        QString pn;
        QString pwd;
        pn = i.key();
        pwd = i.value();
        query.prepare("insert into manager(phone_number, password) values(?, ?)");
        query.addBindValue(pn);
        query.addBindValue(pwd);
        query.exec();
        ++i;
    }
}

void System_manager_Upload(QHash<QString, QString> hash)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("delete from system_manager");

    QHash<QString, QString>::const_iterator i = hash.constBegin();
    while (i != hash.constEnd())
    {
        QString pn;
        QString pwd;
        pn = i.key();
        pwd = i.value();
        query.prepare("insert into system_manager(phone_number, password) values(?, ?)");
        query.addBindValue(pn);
        query.addBindValue(pwd);
        query.exec();
        ++i;
    }
}

void Waiter_Upload(QVector<Waiter> vector)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("delete from waiter");

    for(int i = 0; i < vector.size(); ++i)
    {
        QString pn;
        QString pwd;
        QString id;
        QString evaluate;
        int count;
        double sum;
        pn = vector[i].get_Employee_pn();
        pwd = vector[i].get_Employee_pwd();
        id = QString::number(vector[i].get_Id());
        evaluate = QString::number(vector[i].get_Evaluation(),10,2);
        count = vector[i].get_Count();
        sum = vector[i].get_Sum();
        query.prepare("insert into waiter(phone_number, password, id, evaluate, count, sum) values(?, ?, ?, ?, ?, ?)");
        query.addBindValue(pn);
        query.addBindValue(pwd);
        query.addBindValue(id);
        query.addBindValue(evaluate);
        query.addBindValue(count);
        query.addBindValue(sum);
        query.exec();
    }
}

void Chef_Upload(QVector<Chef> vector)
{
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("delete from chef");

    for(int i = 0; i < vector.size(); ++i)
    {
        QString pn;
        QString pwd;
        QString id;
        QString evaluate;
        int count;
        double sum;
        pn = vector[i].get_Employee_pn();
        pwd = vector[i].get_Employee_pwd();
        id = QString::number(vector[i].get_Id());
        evaluate = QString::number(vector[i].get_Evaluation(),10,2);
        count = vector[i].get_Count();
        sum = vector[i].get_Sum();
        query.prepare("insert into chef(phone_number, password, id, evaluate, count, sum) values(?, ?, ?, ?, ?, ?)");
        query.addBindValue(pn);
        query.addBindValue(pwd);
        query.addBindValue(id);
        query.addBindValue(evaluate);
        query.addBindValue(count);
        query.addBindValue(sum);
        query.exec();
    }
}

//查找某一特定用户的信息：

bool search_account(QHash <QString, QString> hash, QString pn, QString pwd)
{
    QHash<QString, QString>::iterator i = hash.find(pn);
    if(i != hash.end() && i.key() == pn && i.value() == pwd)
    {
        qDebug()<< "Found" << endl;
        return true;
    }
    else
    {
        qDebug()<< "Not Found" << endl;
        return false;
    }
}

bool search_account(QVector <Waiter> vector, QString pn, QString pwd)
{
    for(int i = 0; i < vector.size(); ++i)
    {
        if(vector[i].get_Employee_pn() == pn && vector[i].get_Employee_pwd() == pwd)
        {
            qDebug()<< "Found" << endl;
            return true;
        }
    }
    return false;
}

bool search_account(QVector <Chef> vector, QString pn, QString pwd)
{
    for(int i = 0; i < vector.size(); ++i)
    {
        if(vector[i].get_Employee_pn() == pn && vector[i].get_Employee_pwd() == pwd)
        {
            qDebug()<< "Found" << endl;
            return true;
        }
    }
    return false;
}


bool search_account(QVector<Waiter> vector, QString pn, int id)
{
    for(int i = 0; i < vector.size(); ++i)
    {
        if(vector[i].get_Employee_pn() == pn || vector[i].get_Id() == id)
        {
            qDebug()<< "Found" << endl;
            return true;
        }
    }
    return false;
}

bool search_account(QVector<Chef> vector, QString pn, int id)
{
    for(int i = 0; i < vector.size(); ++i)
    {
        if(vector[i].get_Employee_pn() == pn || vector[i].get_Id() == id)
        {
            qDebug()<< "Found" << endl;
            return true;
        }
    }
    return false;
}


bool search_account(QHash <QString, QString> hash, QString pn)
{
    QHash<QString, QString>::iterator i = hash.find(pn);
    if(i != hash.end() && i.key() == pn)
    {
        qDebug()<< "Found" << endl;
        return true;
    }
    else
    {
        qDebug()<< "Not Found" << endl;
        return false;
    }
}

bool search_account(QVector <Waiter> vector, QString pn)
{
    for(int i = 0; i < vector.size(); ++i)
    {
        if(vector[i].get_Employee_pn() == pn)
        {
            qDebug()<< "Found" << endl;
            return true;
        }
    }
    return false;
}

bool search_account(QVector <Chef> vector, QString pn)
{
    for(int i = 0; i < vector.size(); ++i)
    {
        if(vector[i].get_Employee_pn() == pn)
        {
            qDebug()<< "Found" << endl;
            return true;
        }
    }
    return false;
}

//查找某一特定用户的密码：

QString search_account_pwd(QHash <QString, QString> hash, QString pn)
{
    QHash<QString, QString>::iterator i = hash.find(pn);
    return i.value();
}

QString search_account_pwd(QVector <Waiter> vector, QString pn)
{
    for(int i = 0; i < vector.size(); ++i)
    {
        if(vector[i].get_Employee_pn() == pn)
        {
            qDebug()<< "Found" << endl;
            return vector[i].get_Employee_pwd();
        }
    }
}

QString search_account_pwd(QVector <Chef> vector, QString pn)
{
    for(int i = 0; i < vector.size(); ++i)
    {
        if(vector[i].get_Employee_pn() == pn)
        {
            qDebug()<< "Found" << endl;
            return vector[i].get_Employee_pwd();
        }
    }
}
