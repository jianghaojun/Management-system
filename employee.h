#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QHash>
#include <QMultiHash>

//设置一个employee的基类

class employee
{
public:
    employee(int id, int e = 0, int c = 0, int s = 0);
    employee(){}

    int get_Id() const;

    double get_Evaluation() const;
    virtual double set_Evaluation(double e);

    //void show_Evaluation() const;
    //int get_Status() const;
    //int set_Status(int s);

protected:
    int id;
    double evaluation;        //评分0-5分
    int count;                //记录评价的次数
    int sum;                  //记录评分总和
    //int status;             //当前状态 0->空闲  其他整数代表服务的桌号

};


//Waiter类

class Waiter : public employee
{
public:
    Waiter(int id, int e = 0, int c = 0, int s = 0, int wt = 0);
    Waiter(){}

    virtual double set_Evaluation(int table_id,double e);

    int setWaiterTable(int wt);
    int getWaiterTable() const;

    QMultiHash<int, double> service_record;  //记录当天服务的桌号和评价

private:
    int waiter_table_id;                     //服务的桌号


};


//Chef类

class Chef : public employee
{
public:
    Chef(int id, int e = 0, int c = 0, int s = 0);
    Chef(){}

    virtual double set_Evaluation(int food_id,double e);

    QMultiHash<int, double> cook_record;  //记录当天所作的菜（编号）和评价
};

#endif // EMPLOYEE_H
