#include<cmath>
#include "pch.h"
#include "CNumberConverter.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <regex>


using namespace std;

bool CNumberConverter::isOperator(char c) {
    // Returns true if the character is an operator
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int CNumberConverter::precedence(char op) {
    // Returns the precedence of the operator
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

double CNumberConverter::applyOp(double a, double b, char op) {
    // Apply the operation to two operands
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return pow(a, b);
    default:
        throw invalid_argument("Invalid operator");
    }
}

string CNumberConverter::addSpacesAroundOperators(const std::string& expression) {
    std::string spacedExpression;

    size_t i = 0;

    // Check if the first character is a negative sign
    if (!expression.empty() && expression[0] == '-') {
        spacedExpression += "0 - ";
        i++; // Skip the negative sign as it's already processed
    }

    // Process the rest of the expression
    for (; i < expression.size(); ++i) {
        char current = expression[i];

        // Check if the current character is an operator or a parenthesis
        if (current == '+' || current == '-' || current == '*' || current == '/' ||
            current == '(' || current == ')') {
            // Add a space before the operator, unless it's the first character
            if (!spacedExpression.empty() && !isspace(spacedExpression.back())) {
                spacedExpression += ' ';
            }
            // Add the operator/parenthesis
            spacedExpression += current;
            // Add a space after the operator/parenthesis
            if (i + 1 < expression.size() && !isspace(expression[i + 1])) {
                spacedExpression += ' ';
            }
        }
        else {
            // Add the current character (numbers, letters, etc.)
            spacedExpression += current;
        }
    }

    // Normalize spaces (remove extra spaces if any)
    std::string finalExpression;
    bool lastWasSpace = false;
    for (char c : spacedExpression) {
        if (isspace(c)) {
            if (!lastWasSpace) {
                finalExpression += ' ';
                lastWasSpace = true;
            }
        }
        else {
            finalExpression += c;
            lastWasSpace = false;
        }
    }

    return finalExpression;
}

string CNumberConverter::substituteN(const std::string& expression, int n) {
    std::string substitutedExpression;
    size_t i = 0;

    while (i < expression.size()) {
        if (isdigit(expression[i])) {
            // Parse coefficient
            std::string coefficient;
            while (i < expression.size() && isdigit(expression[i])) {
                coefficient += expression[i];
                i++;
            }

            // Check if followed by 'n'
            if (i < expression.size() && expression[i] == 'n') {
                substitutedExpression += coefficient + "*" + std::to_string(n); // Removed spaces
                i++;
            }
            else {
                substitutedExpression += coefficient;
            }
        }
        else if (expression[i] == 'n') {
            // Handle standalone 'n'
            substitutedExpression += "1*" + std::to_string(n); // Removed spaces
            i++;
        }
        else if (expression[i] == '-' && (i + 1 < expression.size() && expression[i + 1] == 'n')) {
            // Handle `-n` explicitly
            substitutedExpression += "-1*" + std::to_string(n); // Removed spaces
            i += 2; // Skip over `-` and `n`
        }
        else if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*' || expression[i] == '/') {
            // Directly append the operator without adding spaces
            substitutedExpression += expression[i];
            i++;
        }
        else if (expression[i] == '(' || expression[i] == ')') {
            // Directly append parentheses without adding spaces
            substitutedExpression += expression[i];

            // Check for multiplication after closing parenthesis
            if (expression[i] == ')' && i + 1 < expression.size() && expression[i + 1] == 'n') {
                substitutedExpression += "*";
            }
            i++;
        }
        else if (isspace(expression[i])) {
            // Skip extra spaces
            i++;
        }
        else {
            // Handle other characters
            substitutedExpression += expression[i];
            i++;
        }
    }

    // No need to normalize spaces since we're not adding unnecessary ones
    return substitutedExpression;
}

double CNumberConverter::evaluateExpression(const string& expression) {
    stack<char> operators;    // Stack to hold operators
    stack<double> operands;   // Stack to hold operands (double instead of int)
    string equation = addSpacesAroundOperators(expression);

    stringstream ss(equation);
    string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1])) || token.find('.') != string::npos) {
            // Handle numbers (positive, negative, or decimal)
            double num;
            stringstream(token) >> num;
            operands.push(num);
        }
        else if (isOperator(token[0])) {
            char op = token[0];

            // Apply operators with higher or equal precedence
            while (!operators.empty() && precedence(operators.top()) >= precedence(op)) {
                double b = operands.top();
                operands.pop();
                double a = operands.top();
                operands.pop();
                char topOp = operators.top();
                operators.pop();

                operands.push(applyOp(a, b, topOp));
            }
            operators.push(op);
        }
        else if (token == "(") {
            operators.push('(');
        }
        else if (token == ")") {
            // Apply operators until matching '(' is found
            while (!operators.empty() && operators.top() != '(') {
                double b = operands.top();
                operands.pop();
                double a = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                operands.push(applyOp(a, b, op));
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop(); // Remove '('
            }
        }
    }

    // Apply remaining operators
    while (!operators.empty()) {
        double b = operands.top();
        operands.pop();
        double a = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();

        operands.push(applyOp(a, b, op));
    }

    return operands.top();
}

CString CNumberConverter::decToHex(int input)
{
    CString hexString;
    if (input == 0) {
        hexString = "0";
        return hexString;
    }

    char hexDigits[] = "0123456789ABCDEF";
    CString result;

    while (input > 0) {
        result.Insert(0, hexDigits[input % 16]);
        input /= 16;
    }

    return result;
}

CString CNumberConverter::decToBin(int input)
{
    CString hexString;
    if (input == 0) {
        hexString = "0";
        return hexString;
    }

    char hexDigits[] = "01";
    CString result;

    while (input > 0) {
        result.Insert(0, hexDigits[input % 2]);
        input /= 2;
    }

    return result;
}

CString CNumberConverter::decToOct(int input)
{
    CString hexString;
    if (input == 0) {
        hexString = "0";
        return hexString;
    }

    char hexDigits[] = "01234567";
    CString result;

    while (input > 0) {
        result.Insert(0, hexDigits[input % 8]);
        input /= 8;
    }

    return result;
}