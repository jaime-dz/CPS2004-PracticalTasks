#ifndef TOY_H_
#define TOY_H_
#include "product.h"

class Toy : public Product
{
private:
    string material;
    int pieces;
    int minAge;
    string dimensions;

public:
    Toy();
    Toy(const string& n, double p, const string& id, const string& d,
        const string& mat, int pc, int age, const string& dim);

    void setMaterial(const string& mat);
    void setPieces(int pc);
    void setMinAge(int age);
    void setDimensions(const string& dim);

    string getMaterial() const;
    int getPieces() const;
    int getMinAge() const;
    string getDimensions() const;

    void display() const override;
    void persist(ofstream& out) const override;
    static Toy* restoreFromStream(stringstream& ss);
};

#endif