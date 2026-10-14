#include <iostream>

using namespace std;

class firstClass
{
private:
    double number;
    string name;
public:
    firstClass():number(18),name("Adam")
    {
        cout<<"Default constructor called"<<endl;
    }

    firstClass(int n,string na):number(n),name(na)
    {
        cout<<"Parameterized constructor was called"<<endl;
    }

    int getNumber() const
    {
        return number;
    }
    string getName() const
    {
        return name;
    }
    void setNumber(int n)
    {
        number=n;
    }
    void setName(string name)
    {
        this->name=name;
    }
};

int main()
{
    firstClass f1;
    firstClass f2(34,"Jaime");

    f1.setName("Ferdinand");
    f1.setNumber(23);
    cout<<f2.getName()<<endl;
    cout<<f2.getNumber()<<endl;

    return 0;
}