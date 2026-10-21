#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <string>

using namespace std;

class binops
{
private:
    double opnd1{0.0},opnd2{0.0};
    char op{'+'};
public:
    binops()=default;
    void setOpnd1(double o)
    {
        opnd1=o;
    }
    void setOpnd2(double o)
    {
        opnd2=o;
    }
    void setOp(char op)
    {
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            throw std::invalid_argument("Invalid operator. Must be +, -, * o /.");
        }
        this->op=op;
    }
    double getOpnd1() const
    {
        return opnd1;
    }
    double getOpnd2() const
    {
        return opnd2;
    }
    char getOp() const
    {
        return op;
    }
    double evaluate()
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
};

int main()
{
    const int CAPACITY=5;
    binops* expressions=new binops[CAPACITY];
    int count=0;
    //std::string line;

    while(count<CAPACITY)
    {
        double op1,op2;
        char op;
        std::cout << "Expresion [" << count + 1 << "/" << CAPACITY << "]: ";
        std::cin >> op1 >> op >> op2;

        if (!std::cin) { 
            if (std::cin.eof()) break;

            std::cout << "Invalid input. Expected format: <num> <op> <num>\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        try {
            expressions[count].setOpnd1(op1);
            expressions[count].setOp(op);
            expressions[count].setOpnd2(op2);
            count++;
        } catch (const std::exception& e) {
            std::cout << "Validation error: " << e.what() << "\n";
        }
    }

    std::ofstream outFile("results.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < count; ++i) {
            try {
                double result = expressions[i].evaluate();
                outFile << expressions[i].getOpnd1() << " " 
                        << expressions[i].getOp() << " " 
                        << expressions[i].getOpnd2() << " -> " 
                        << result << "\n";
            } catch (const std::exception& e) {
                outFile << expressions[i].getOpnd1() << " " 
                        << expressions[i].getOp() << " " 
                        << expressions[i].getOpnd2() << " -> ERROR: " 
                        << e.what() << "\n";
            }
        }
        outFile.close();
        std::cout << "\nResults stored in 'results.txt'.\n";
    }

    delete[] expressions;
    return 0;

    /*
    while (count < CAPACITY) {
        std::cout << "Expresion [" << count + 1 << "/" << CAPACITY << "]: ";
        if (!std::getline(std::cin, line)) break;

        if (line.empty()) continue;

        std::istringstream iss(line);
        double op1, op2;
        char op;

        if (iss >> op1 >> op >> op2) {
            if (iss >> extra) {
                std::cout << "Error: Extra characters at the end.\n";
                continue;
            }

            try {
                expressions[count].setOpnd1(op1);
                expressions[count].setOp(op);
                expressions[count].setOpnd2(op2);
                count++;
            } catch (const std::exception& e) {
                std::cout << "Validation error: " << e.what() << "\n";
            }
        } else {
            std::cout << "Parsing error. Expected format: <num> <op> <num>\n";
        }
    }

    std::ofstream outFile("results.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < count; ++i) {
            try {
                double result = expressions[i].evaluate();
                outFile << expressions[i].getOpnd1() << " " 
                        << expressions[i].getOp() << " " 
                        << expressions[i].getOpnd2() << " -> " 
                        << result << "\n";
            } catch (const std::exception& e) {
                outFile << expressions[i].getOpnd1() << " " 
                        << expressions[i].getOp() << " " 
                        << expressions[i].getOpnd2() << " -> ERROR: " 
                        << e.what() << "\n";
            }
        }
        outFile.close();
        std::cout << "\nResultados guardados en 'results.txt'.\n";
    }

    delete[] expressions;
    return 0;
    */
}