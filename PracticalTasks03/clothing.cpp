#include "clothing.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

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

void Clothing::persist(ofstream& out) const
{
    out<<"CLOTHING|"<<name<<"|"<<price<<"|"<<id<<"|"<<description<<"|"<<size<<"|"<<material<<"|"<<brand<<"|"<<season<<endl;
}

Clothing* Clothing::restoreFromStream(stringstream& ss)
{
    string name, price, id, desc, size, material, brand, season;
    std::getline(ss, name, '|');
    std::getline(ss, price, '|');
    std::getline(ss, id, '|');
    std::getline(ss, desc, '|');
    std::getline(ss, size, '|');
    std::getline(ss, material, '|');
    std::getline(ss, brand, '|');
    std::getline(ss, season);
    return new Clothing(name, std::stod(price),id, desc, size, material, brand, season);
}