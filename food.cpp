#include "food.h"
#include <iomanip>
#include <iostream>
using namespace std;


Food::Food(QString fn, int id, int fp, int fe,  double fs):
    food_name(fn), food_id(id), food_price(fp),  food_evaluation(fe), food_status(fs)
{
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
