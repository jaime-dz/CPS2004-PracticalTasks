#include "product.h"

Product::Product() : name(""), price(-1), id(""), description(""){}

Product::Product(const string& n, double p, const string& id, const string& d) : name(n),price(p),id(id),description(d){}

void Product::setName(const string& n)
{
    name=n;
}

void Product::setPrice(double p)
{
    price=p;
}

void Product::setId(const string& id)
{
    this->id=id;
}

void Product::setDescription(const string& d)
{
    description=d;
}

string Product::getName() const
{
    return name;
}

double Product::getPrice() const
{
    return price;
}

string Product::getId() const
{
    return id;
}

string Product::getDescription() const
{
    return description;
}

void Product::display() const
{
    cout<<"ID: "<<id<<" | Name: "<<name<<" | Price: €"<<price<<" | Description: "<<description<<endl;
}