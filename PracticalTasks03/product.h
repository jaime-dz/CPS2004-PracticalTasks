#ifndef PRODUCT
#define PRODUCT
#include <iostream>
#include <string>
using namespace std;
class Product
{
protected:
    string name;
    double price;
    string id;
    string description;
public:
    Product();
    Product(const string& n,double p, const string& i, const string& d);
    void setPrice(double p);
    void setName(const string& n);
    void setId(const string& id);
    void setDescription(const string& d);
    string getName() const;
    double getPrice() const;
    string getId() const;
    string getDescription() const;
    virtual ~Product()=default;
    virtual void display() const;
};

#endif