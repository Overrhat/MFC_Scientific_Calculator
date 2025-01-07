#pragma once
#include <string>
class CNumberConverter
{
    /* 
    * The number systems converter that are used for
    * Programmer Calculator
    */
public:
    // I/O with numbers instead of string
    static CString decToBin(int input);
    static CString decToHex(int input);
    static CString decToOct(int input);
   

    /*
    * The Expressions converter that are used for
    * Sigma Calculator
    */
private:
    static bool isOperator(char c);
    static int precedence(char op);
    static double applyOp(double a, double b, char op);
    static std::string addSpacesAroundOperators(const std::string& expression);
public:
    static double evaluateExpression(const std::string& expression);
    static std::string substituteN(const std::string& expression, int n);
};

