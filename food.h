#ifndef FOOD_H
#define FOOD_H
#include <QString>

class Food
{
public:
    Food(QString fn, int id, int fp, int fs = 0, double fe = 0, int ci = 0);    //构造函数
    Food(){}
    Food(const Food &f);

    int setFood_Status(int fs);   //设置食物的状态（0->未下单，1->下单尚未被认领，2->厨师认领并已开始做菜，3->准备上菜）
    int getFood_Status() const;

    double getF_Evaluation() const;      //获取以往顾客对食物的评价
    double setF_Evaluation(double fe);     //设置新的评价（最好是用一个函数能够取平均值）

    int getChef_id() const;
    int setChef_id(int id);

    int getPrice() const;
    int getID() const;
    QString getName() const;

    friend bool operator == (Food f1, Food f2);      //为food类重载运算符 “ == ” 声明为友元函数

private:
    int food_status;              //食物的状态（0->未下单，1->下单尚未被认领，2->厨师认领并已开始做菜，3->准备上菜）
    double food_evaluation;       //顾客评价
    int food_price;
    int food_id;
    int chef_id;                  //制作厨师的id
    QString food_name;
    //QString food_picture;         //食物对应图片的资源地址

};

#endif // FOOD_H
