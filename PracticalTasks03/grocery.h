#ifndef GROCERY_H_
#define GROCERY_H_
#include "product.h"

class Grocery:public Product
{
private:
    string category;
    double weight;
public:
    Grocery();
    Grocery(const string& n,double p,const string& id,const string& d,const string& c, double w);
    void setCategory(const string& c);
    void setWeight(double w);
    string getCategory() const;
    double getWeight() const;

    void display() const override;
    void persist(ofstream& out) const override;
    static Grocery* restoreFromStream(stringstream& ss);
};

#endif