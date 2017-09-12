#include "table.h"

Table::Table(int ti, int ts):table_status(ts), table_id(ti)
{}

inline int Table::getTableStatus()
{
    return table_status;
}

int Table::setTableStatus(int ts)
{
    table_status = ts;
    return table_status;
}

inline int Table::getTableId() const
{
    return table_id;
}

int Table::setTableWaiter_id(int id)
{
    table_waiter_id = id;
    return table_waiter_id;
}

int Table::getTableWaiter_id()
{
    return table_waiter_id;
}
