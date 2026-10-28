#include "grocery.h"

Grocery::Grocery() : Product(), category(""), weight(-1){}

Grocery::Grocery(const string& n,double p,const string& id,const string& d,const string& c, double w) : Product(n,p,id,d), category(c),weight(w){}

void Grocery::setCategory(const string& c)
{
    category=c;
}

void Grocery::setWeight(double w)
{
    weight=w;
}

string Grocery::getCategory() const
{
    return category;
}

double Grocery::getWeight() const
{
    return weight;
}

void Grocery::display() const
{
    Product::display();
    cout<<"Category: "<<category<<"\nWeight: "<<weight<<"kg"<<endl;
}