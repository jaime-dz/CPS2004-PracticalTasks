#include <iostream>
#include <fstream>

using namespace std;

struct binops
{
    double opnd1,opnd2;
    char op;
};

double evaluate(const binops& expr)
{
    switch(expr.op)
    {
        case '+':
            return expr.opnd1+expr.opnd2;
            break;
        case '-':
            return expr.opnd1-expr.opnd2;
            break;
        case '*':
            return expr.opnd1*expr.opnd2;
            break;
        case '/':
            if(expr.opnd2!=0)
                return expr.opnd1/expr.opnd2;
            cerr<<"Error: Cannot divide by 0\n";
            return 0.0;
            break;
        default:
            cerr<<"Error: Invalid operand '"<<expr.op<<"'\n";
            return 0.0;
            break;
    }
}

int main()
{
    const int SIZE=5;

    binops* expressions=new binops[SIZE];
    cout<<"Enter up to "<<SIZE<<" expressions: ";
    
    int count=0;
    while(count<SIZE && (cin>>expressions[count].opnd1>>expressions[count].op>>expressions[count].opnd2))
    {
        count++;
    }

    ofstream outputFile("results.txt");
    if(!outputFile.is_open())
    {
        cerr<<"Could not create file\n";
        delete[] expressions;
        return 1;
    }
    for(int i=0;i<count;++i)
    {
        double value=evaluate(expressions[i]);
        outputFile<<expressions[i].opnd1<<" "<<expressions[i].op<<" "<<expressions[i].opnd2<<" -> "<<value<<endl;
    }

    outputFile.close();
    delete[] expressions;

    return 0;
}