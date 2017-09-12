#ifndef TABLE_H
#define TABLE_H
#include "menu.h"

class Table
{
public:
    Table(int ti, int ts = 0);
    Table(){}

    int getTableStatus();
    int setTableStatus(int ts);

    int getTableId() const;

    //void setW_Evaluation();
    int setTableWaiter_id(int id);      //设置服务该桌的服务员的编号
    int getTableWaiter_id();
    Menu m;                             //组合，每张桌子有一个菜单

private:
    int table_status;                   // 0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员
    int table_id;
    int table_waiter_id;

    //Waiter w;

};
#endif // TABLE_H
