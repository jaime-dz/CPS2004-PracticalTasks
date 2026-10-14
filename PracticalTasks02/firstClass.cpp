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
    const int NUM=3;
    firstClass f1;
    firstClass f2(34,"Jaime");

    f1.setName("Ferdinand");
    f1.setNumber(23);
    cout<<f2.getName()<<endl;
    cout<<f2.getNumber()<<endl;

    firstClass stackArray[NUM];
    for(int i=0;i<NUM;i++)
    {
        stackArray[i].setName(to_string(i));
        stackArray[i].setNumber(i);
    }
    for(int i=0;i<NUM;i++)
    {
        cout<<"Instance "<<i+1<<endl;
        cout<<"Name: "<<stackArray[i].getName()<<endl;
        cout<<"Number: "<<stackArray[i].getNumber()<<endl;
    }

    firstClass* heapArray=new firstClass[NUM];
    for(int j=0;j<NUM;j++)
    {
        heapArray[j].setName("a");
        heapArray[j].setNumber(2);
    }
    for(int j=0;j<NUM;j++)
    {
        cout<<"Instance "<<j+1<<endl;
        cout<<"Name: "<<heapArray[j].getName()<<endl;
        cout<<"Number: "<<heapArray[j].getNumber()<<endl;
    }

    return 0;
}