#include "toy.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Toy::Toy() : Product(), material(""), pieces(0), minAge(0), dimensions("") {}

Toy::Toy(const string& n, double p, const string& id, const string& d, const string& mat, int pc, int age, const string& dim)
    : Product(n,p,id,d), material(mat), pieces(pc), minAge(age), dimensions(dim) {}

void Toy::setMaterial(const string& mat)
{
    material=mat;
}

void Toy::setPieces(int pc)
{
    pieces=pc;
}

void Toy::setMinAge(int age)
{
    minAge=age;
}

void Toy::setDimensions(const string& dim)
{
    dimensions=dim;
}

string Toy::getMaterial() const
{
    return material;
}

int Toy::getPieces() const
{
    return pieces;
}

int Toy::getMinAge() const
{
    return minAge;
}

string Toy::getDimensions() const
{
    return dimensions;
}

void Toy::display() const
{
    Product::display();
    cout<<"Material: "<<material<<"\nPieces: "<<pieces<<"\nMin Age: "<<minAge<<"\nDimensions: "<<dimensions<<endl;
}

void Toy::persist(ofstream& out) const
{
    out<<"TOY|"<<name<<"|"<<price<<"|"<<id<<"|"<<description<<"|"<<material<<"|"<<pieces<<"|"<<minAge<<"|"<<dimensions<<endl;
}
Toy* Toy::restoreFromStream(stringstream& ss)
{
    string name, price, id, desc, material, pieces, minAge, dimensions;
    std::getline(ss, name, '|');
    std::getline(ss, price, '|');
    std::getline(ss, id, '|');
    std::getline(ss, desc, '|');
    std::getline(ss, material, '|');
    std::getline(ss, pieces, '|');
    std::getline(ss, minAge, '|');
    std::getline(ss, dimensions);
    return new Toy(name, std::stod(price), id, desc, material, std::stod(pieces), std::stod(minAge), dimensions);
}