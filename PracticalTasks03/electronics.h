#ifndef ELECTRONICS_H_
#define ELECTRONICS_H_
#include "product.h"

class Electronics : public Product
{
private:
    string brand;
    string model;
    double voltage;
    int warrantyMonths;
    string color;
public:
    Electronics();
    Electronics(const string& n,double p,const string& id,const string& d,const string& br, const string& model,double volt,int warrantyM,const string& color);
    void setBrand(const string& b);
    void setModel(const string& m);
    void setVoltage(double v);
    void setWarrantyMonths(int wm);
    void setColor(const string& color);

    string getBrand() const;
    string getModel() const;
    double getVoltage() const;
    int getWarrantyMonths() const;
    string getColor() const;

    void display() const override;
};

#endif