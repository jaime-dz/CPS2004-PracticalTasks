#include <stdexcept>
#include "task2.h"

using namespace std;

void binops::setOpnd1(double o)
{
    opnd1=o;
}

void binops::setOpnd2(double o)
{
    opnd2=o;
}

void binops::setOp(char op)
{
    if (op != '+' && op != '-' && op != '*' && op != '/') {
        throw std::invalid_argument("Invalid operator. Must be +, -, * o /.");
    }
    this->op=op;
}

double binops::getOpnd1() const
{
    return opnd1;
}

double binops::getOpnd2() const
{
    return opnd2;
}

char binops::getOp() const
{
    return op;
}

double binops::evaluate()
{
    switch(op)
    {
        case '+':
            return opnd1+opnd2;
            break;
        case '-':
            return opnd1-opnd2;
            break;
        case '*':
            return opnd1*opnd2;
            break;
        case '/':
            if (opnd2 == 0.0) {
                throw std::runtime_error("Cannot divide by 0.");
            }
            return opnd1 / opnd2;
            break;
        default:
            throw std::invalid_argument("Unknown operator");
            break;
    }
}