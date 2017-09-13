#include "food.h"
#include <iomanip>
#include <iostream>
using namespace std;

Food::Food(QString fn, int id, int fp,  int fs, double fe):
    food_name(fn), food_id(id), food_price(fp),  food_evaluation(fe), food_status(fs)
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

int Food::getFood_Status()
{
    return food_status;
}

double Food::getF_Evaluation()
{
    return food_evaluation;
}

void Food::showF_Evaluation()
{
    cout<<fixed<<setprecision(2)<<food_evaluation<<endl;
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

int Food::getPrice()
{
    return food_price;
}

int Food::getID()
{
    return food_id;
}

QString Food::getName()
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
