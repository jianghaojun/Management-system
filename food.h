#ifndef FOOD_H
#define FOOD_H
#include <QString>
using namespace std;

//done

class Food
{
public:
    Food(QString fn, int id, int fp, int fe = 0, double fs = 0);    //构造函数
    Food(){}

    int setFood_Status(int fs);   //设置食物的状态（0->未被厨师认领，1->厨师认领并已开始做菜，2->已上菜）
    int getFood_Status();

    double getF_Evaluation();     //获取以往顾客对食物的评价
    void showF_Evaluation();
    double setF_Evaluation(double fe);     //设置新的评价（最好是用一个函数能够取平均值）

    int getPrice();
    int getID();
    QString getName();

    friend bool operator == (Food f1, Food f2);      //为food类重载运算符 “ == ” 声明为友元函数

private:
    int food_status;              //食物的状态（0->未下单，1->已经下单，2->未开始制作，3->已开始，4->已上菜）
    double food_evaluation;       //顾客评价
    int food_price;
    int food_id;
    QString food_name;
    //QString food_picture;         //食物对应图片的资源地址

};


#endif // FOOD_H