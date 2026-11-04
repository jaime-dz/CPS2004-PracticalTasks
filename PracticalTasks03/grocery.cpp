#include "grocery.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

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

void Grocery::persist(ofstream& out) const
{
    out<<"GROCERY|"<<name<<"|"<<price<<"|"<<id<<"|"<<description<<"|"<<category<<"|"<<weight<<endl;
}

Grocery* Grocery::restoreFromStream(stringstream& ss)
{
    string name, priceStr, id, desc, cat, weight;
    std::getline(ss,name,'|');
    std::getline(ss,priceStr,'|');
    std::getline(ss,id,'|');
    std::getline(ss,desc,'|');
    std::getline(ss,cat,'|');
    std::getline(ss,weight);
    return new Grocery(name, std::stod(priceStr),id,desc,cat,std::stod(weight));
}