#include "electronics.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Electronics::Electronics() : Product(),brand(""),model(""),voltage(0.0),warrantyMonths(0),color(""){}

Electronics::Electronics(const string& n,double p,const string& id,const string& d,const string& br, const string& model,double volt,int warrantyM,const string& color) : Product(n,p,id,d),brand(br),model(model),voltage(volt), warrantyMonths(warrantyM),color(color){}

void Electronics::setBrand(const string& b)
{
    brand=b;
}

void Electronics::setModel(const string& m)
{
    model=m;
}

void Electronics::setVoltage(double v)
{
    voltage=v;
}

void Electronics::setWarrantyMonths(int wm)
{
    warrantyMonths=wm;
}

void Electronics::setColor(const string& color)
{
    this->color=color;
}

string Electronics::getBrand() const
{
    return brand;
}

string Electronics::getModel() const
{
    return model;
}

double Electronics::getVoltage() const
{
    return voltage;
}

int Electronics::getWarrantyMonths() const
{
    return warrantyMonths;
}

string Electronics::getColor() const
{
    return color;
}

void Electronics::display() const
{
    Product::display();
    cout<<"Brand: "<<brand<<"\nModel: "<<model<<"\nVoltage: "<<voltage<<"V\nWarranty Months: "<<warrantyMonths<<"\nColor: "<<color<<endl;
}

void Electronics::persist(ofstream& out) const
{
    out<<"ELECTRONICS|"<<name<<"|"<<price<<"|"<<id<<"|"<<description<<"|"<<brand<<"|"<<model<<"|"<<voltage<<"|"<<warrantyMonths<<"|"<<color<<endl;
}

Electronics* Electronics::restoreFromStream(stringstream& ss)
{
    string name, price, id, desc, brand, model, voltage, warrantyMonths, color;
    std::getline(ss,name,'|');
    std::getline(ss,price,'|');
    std::getline(ss,id,'|');
    std::getline(ss,desc,'|');
    std::getline(ss,brand,'|');
    std::getline(ss,model,'|');
    std::getline(ss,voltage,'|');
    std::getline(ss,warrantyMonths,'|');
    std::getline(ss,color);
    return new Electronics(name, std::stod(price),id, desc, brand, model,std::stod(voltage),std::stod(warrantyMonths),color);
}