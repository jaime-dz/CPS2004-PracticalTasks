#include "clothing.h"

Clothing::Clothing() : Product(), size(""), material(""), brand(""), season("") {}

Clothing::Clothing(const string& n, double p, const string& id, const string& d, const string& sz, const string& mat, const string& br, const string& seas)
    : Product(n,p,id,d), size(sz), material(mat), brand(br), season(seas) {}

void Clothing::setSize(const string& sz)
{
    size=sz;
}

void Clothing::setMaterial(const string& mat)
{
    material=mat;
}

void Clothing::setBrand(const string& br)
{
    brand=br;
}

void Clothing::setSeason(const string& seas)
{
    season=seas;
}

string Clothing::getSize() const
{
    return size;
}

string Clothing::getMaterial() const
{
    return material;
}

string Clothing::getBrand() const
{
    return brand;
}

string Clothing::getSeason() const
{
    return season;
}

void Clothing::display() const
{
    Product::display();
    cout<<"Size: "<<size<<"\nMaterial: "<<material<<"\nBrand: "<<brand<<"\nSeason: "<<season<<endl;
}