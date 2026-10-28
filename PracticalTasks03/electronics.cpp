#include "electronics.h"

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