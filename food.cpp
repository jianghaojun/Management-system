#include "food.h"
#include <iomanip>
#include <iostream>
using namespace std;

Food::Food(QString fn, int id, int fp,  int fs, double fe, int ci):
    food_name(fn), food_id(id), food_price(fp),  food_evaluation(fe), food_status(fs), chef_id(ci)
{
}

Food::Food(const Food &f)
{
    food_evaluation = f.food_evaluation;
    food_id = f.food_id;
    food_name = f.food_name;
    food_price = f.food_price;
    food_status =f.food_status;
}

int Food::setFood_Status(int fs)
{
    food_status = fs;
    return food_status;
}

int Food::getFood_Status() const
{
    return food_status;
}

double Food::getF_Evaluation() const
{
    return food_evaluation;
}

double Food::setF_Evaluation(double fe)
{
    static int cout = 1;
    static double sum = 0;
    sum += fe;
    food_evaluation = sum/cout;
    cout++;
    return food_evaluation;
}

int Food::getChef_id() const
{
    return chef_id;
}

int Food::setChef_id(int id)
{
    chef_id = id;
    return chef_id;
}

int Food::getPrice() const
{
    return food_price;
}

int Food::getID() const
{
    return food_id;
}

QString Food::getName() const
{
    return food_name;
}

bool operator == (Food f1, Food f2)
{
   if(f1.food_id == f2.food_id)
   {
       return true;
   }
   else
       return false;
}
