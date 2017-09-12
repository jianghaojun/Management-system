#include "Table_and_Menu.h"
#include "food.h"
#include <iostream>
#include <QString>
using namespace std;

Menu::Menu(){}

void Menu::addFood(Food f)
{
    Menulist.push_back(f);
}

void Menu::deleteFood()
{
    Menulist.pop_back();
}


void Menu::getMenu()
{
    for(int i = 0; i < Menulist.size(); i++)
    {
        //cout<< i+1 << " " << Menulist[i].getName();
    }
}

int Menu::getSum() const
{
    int sum = 0;
    for( auto i : Menulist )
    {
        sum += i.getPrice();
    }
    return sum;
}

//Table





