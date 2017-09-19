#ifndef MENU_H
#define MENU_H
#include <QVector>
#include "food.h"

class Menu
{
public:
    Menu();

    void addFood(Food f);        //添加food到Menulist尾部
    void deleteFood();           //删除Menulist尾部的food
    int getSum();                //所点菜的总额，从Menulist里面计算

    QVector <Food> Menulist;     //储存每桌所点的菜
};

#endif // MENU_H
