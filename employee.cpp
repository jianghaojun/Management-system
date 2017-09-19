#include "Employee.h"
#include <iomanip>

//Employee类的实现
employee::employee(int id, QString pn, QString pwd, int e, int c, double s):id(id),employee_pn(pn),
    employee_pwd(pwd), evaluation(e),count(c),sum(s)
{}

int employee::get_Id() const
{
    return id;
}

double employee::get_Evaluation() const
{
    return evaluation;
}

double employee::set_Evaluation(double e)
{
    sum += e;
    ++count;
    evaluation = sum/count;
    return evaluation;
}

int employee::get_Count() const
{
    return count;
}

double employee::get_Sum() const
{
    return sum;
}

QString employee::get_Employee_pn() const
{
    return employee_pn;
}

QString employee::get_Employee_pwd() const
{
    return employee_pwd;
}

//Waiter类的实现
Waiter::Waiter(int id, QString pn, QString pwd, int e, int c, double s, int wt ):
    employee(id, pn, pwd, e, c, s),waiter_table_id(wt)
{}

double Waiter::set_Evaluation(int table_id, double e)
{
    service_record.insert(table_id, e);
    sum += e;
    ++count;
    evaluation = sum / count;
    return evaluation;
}


int Waiter::setWaiterTable(int wt)
{
    waiter_table_id = wt;
    return waiter_table_id;
}

int Waiter::getWaiterTable() const
{
    return waiter_table_id;
}


//Chef类的实现
Chef::Chef(int id, QString pn, QString pwd, int e, int c, double s):employee(id, pn, pwd, e, c, s)
{}

double Chef::set_Evaluation(int food_id, double e)
{
    cook_record.insert(food_id, e);
    sum += e;
    ++count;
    evaluation = sum / count;
    return evaluation;
}
