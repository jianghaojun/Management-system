#include "menu.h"
#include <QVector>
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

int Menu::getSum()
{
    int sum = 0;
    for( auto i : Menulist )
    {
        sum += i.getPrice();
    }
    return sum;
}
