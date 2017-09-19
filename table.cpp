#include "table.h"

Table::Table(int ti, int ts, int twi):table_status(ts), table_id(ti),table_waiter_id(twi)
{}

int Table::getTableStatus() const
{
    return table_status;
}

int Table::setTableStatus(int ts)
{
    table_status = ts;
    return table_status;
}

int Table::getTableId() const
{
    return table_id;
}

int Table::setTableWaiter_id(int id)
{
    table_waiter_id = id;
    return table_waiter_id;
}

int Table::getTableWaiter_id() const
{
    return table_waiter_id;
}

QString Table::getTableCustomer_pn() const
{
    return customer_pn;
}

QString Table::setTableCustomer_pn(QString pn)
{
    customer_pn = pn;
    return customer_pn;
}
