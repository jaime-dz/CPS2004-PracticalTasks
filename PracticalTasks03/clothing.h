#ifndef CLOTHING_H_
#define CLOTHING_H_
#include "product.h"

class Clothing : public Product
{
private:
    string size;
    string material;
    string brand;
    string season;
public:
    Clothing();
    Clothing(const string& n, double p, const string& id, const string& d,
             const string& sz, const string& mat, const string& br, const string& seas);

    void setSize(const string& sz);
    void setMaterial(const string& mat);
    void setBrand(const string& br);
    void setSeason(const string& seas);

    string getSize() const;
    string getMaterial() const;
    string getBrand() const;
    string getSeason() const;

    void display() const override;
};

#endif