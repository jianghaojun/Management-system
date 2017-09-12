#include "list.h"

void table_list_set(QVector<Table> &list)
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

void waiter_list_set(QVector<Waiter> &list)
{

    Waiter w1(1);
    Waiter w2(2);
    Waiter w3(3);
    Waiter w4(4);
    list.push_back(w1);
    list.push_back(w2);
    list.push_back(w3);
    list.push_back(w4);
}

void chef_list_set(QVector<Chef> &list)
{
    Chef c1(1);
    Chef c2(2);
    Chef c3(3);
    Chef c4(4);
    list.push_back(c1);
    list.push_back(c2);
    list.push_back(c3);
    list.push_back(c4);
}

