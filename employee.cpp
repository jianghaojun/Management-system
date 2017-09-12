#include "Employee.h"
#include <iomanip>

//Employee类的实现
employee::employee(int id, int e, int c, int s):id(id),evaluation(e),count(c),sum(s)
{}

inline int employee::get_Id() const
{
    return id;
}

inline double employee::get_Evaluation() const
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

//Waiter类的实现
Waiter::Waiter(int id, int e, int c, int s, int wt ):employee(id, e, c, s),waiter_table_id(wt)
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

inline int Waiter::getWaiterTable() const
{
    return waiter_table_id;
}


//Chef类的实现
Chef::Chef(int id, int e, int c, int s):employee(id, e, c, s)
{}

double Chef::set_Evaluation(int food_id, double e)
{
    cook_record.insert(food_id, e);
    sum += e;
    ++count;
    evaluation = sum / count;
    return evaluation;
}
