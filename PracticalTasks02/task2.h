#ifndef TASK2
#define TASK2

class binops
{
private:
    double opnd1{0.0},opnd2{0.0};
    char op{'+'};
public:
    binops()=default;
    void setOpnd1(double o);
    void setOpnd2(double o);
    void setOp(char op);
    double getOpnd1() const;
    double getOpnd2() const;
    char getOp() const;
    double evaluate();
};

#endif