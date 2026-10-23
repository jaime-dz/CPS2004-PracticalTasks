#include "task2.h"
#include <limits>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

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

