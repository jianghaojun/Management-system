#include "account_list.h"
#include "database.h"

//初始化顾客账户列表:

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

//将储存在QHash表中的顾客账户数据回传给数据库
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
        qDebug()<<pn<<pwd;
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
        qDebug()<<pn<<pwd;
        query.prepare("insert into employee(phone_number, password) values(?, ?)");
        query.addBindValue(pn);
        query.addBindValue(pwd);
        query.exec();
        ++i;
    }
}


//查看所有账户：
void showCaccount(QHash <QString, QString> hash)   //查看顾客账户信息
{
    qDebug()<< "   < Customer Accounts Info >" << endl;
    qDebug()<< "< Phone_Number >    < Password >" << endl;
    QHash<QString, QString>::const_iterator i = hash.constBegin();
    while(i != hash.constEnd())
    {
        qDebug()<< i.key() << "   " <<i.value()<<endl;
        ++i;
    }
}

void showEaccount(QHash <QString, QString> hash)  //查看雇员账户信息
{
    qDebug()<< "   < Employee Accounts Info >" << endl;
    qDebug()<< "< Phone_Number >    < Password >" << endl;
    QHash<QString, QString>::const_iterator i = hash.constBegin();
    while(i != hash.constEnd())
    {
        qDebug()<< i.key() << "   " << i.value() << endl;
        ++i;
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

//查找某一特定用户的密码：
QString search_account_pwd(QHash <QString, QString> hash, QString pn)
{
    QHash<QString, QString>::iterator i = hash.find(pn);
    return i.value();
}
