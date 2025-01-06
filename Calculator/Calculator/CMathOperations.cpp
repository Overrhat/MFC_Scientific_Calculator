#include <cmath>
#include <math.h>
#include "pch.h"
#include <string>
#include <sstream>
#include <iomanip>
#include "CMathOperations.h"
#include "CNumberConverter.h"
#include <limits>
#define NOMINMAX

CString CMathOperations::DoubleToCString(double value) {
    std::ostringstream oss;
    oss << std::setprecision(12) << std::noshowpoint << std::fixed << value; 

    std::string str = oss.str();

    // Remove trailing zeros and the decimal point if not needed
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    if (str.back() == '.') {
        str.pop_back();
    }

    return CString(str.c_str());
}

double CMathOperations::factorialOp(double value) {
    if (isInteger(value)) {
        int num = (int)value;
        int answer = 1;
        for (int i = 1; i <= num; i++) {
            answer *= i;
        }
        return (double)answer;
    }
    double ans = pow(2 * CMathOperations::piEstimate(10000000) * value, 0.5);
    ans = ans * (pow((value / CMathOperations::eulerEstimate(32.0)), value));
    return ans;
}

bool CMathOperations::isInteger(double value) {
    return floor(value) == value;
}

bool CMathOperations::isNegative(CString input) {
    double num = _tstof(input);

    return (num < 0);
}

double CMathOperations::eulerEstimate(int estimationNumber) {
    double ans = 1.0;
    for (int i = 1; i <= estimationNumber; i++) {
        ans += 1.0 / (CMathOperations::factorialOp(i));
    }
    return ans;
}

double CMathOperations::piEstimate(int estimationNumber) {
    double estimate = 0;
    for (int i = 0; i <= estimationNumber; i++) {
        estimate += pow(-1.0, i) / (2.0 * i + 1.0);
    }
    return (4.0 * estimate);
}

double CMathOperations::sinEstimate(double value, int estimationNumber) {
    double piVal = CMathOperations::piEstimate(10000000);
    // fmod ensures the value stays within -2pi to +2pi
    value = fmod(value, 2 * piVal);
    if (value > piVal) {
        value -= 2 * piVal;
    }

    double estimate = 0;
    bool isNegative = false; // To alternate the signs
    for (int i = 1; i < estimationNumber; i = i + 2) {
        double term = (pow(value, i)) / (CMathOperations::factorialOp(i));
        if (isNegative) {
            estimate -= term; 
        }
        else {
            estimate += term; 
        }
        isNegative = !isNegative;
    }
    return estimate;
}

double CMathOperations::lnEstimate(double value, int estimationNumber) {
    if (value == 1) {
        return 0.0;
    }

    // Hardcoded value of ln(2)
    const double LN2 = 0.69314718056; 

    int k = 0;
    while (value > 2.0) {
        value /= 2.0;
        k++;
    }
    while (value < 1.0) {
        value *= 2.0;
        k--;
    }

    double estimate = 0.0;
    double term = value - 1.0; 
    double xMinus1 = value - 1.0;
    for (int i = 1; i <= estimationNumber; i++) {
        if (i % 2 == 1) {
            estimate += term / i;
        }
        else {
            estimate -= term / i; 
        }
        term *= xMinus1; // Increment the power
    }

    return estimate + k * LN2;
}

double CMathOperations::logEstimate(double value, double base, int estimationNumber) {
    CString temp = _T("");
    int num1 = 0;
    while ((value / base) >= 1) {
        num1++;
        value /= base;
    }

    CString decimal;
    decimal.Format(_T("%d"), num1);

    temp = temp + decimal + _T(".");

    value = pow(value, base);

    for (int i = 0; i < estimationNumber; i++) {
        int num2 = 0;
        while ((value / base) >= 1) {
            num2++;
            value /= base;
        }

        CString addOn;
        addOn.Format(_T("%d"), num2);

        temp += addOn;

        value = pow(value, base);
    }

    return _tstof(temp);
}

double CMathOperations::addition(double input1, double input2) {
    return input1 + input2;
}

int CMathOperations::addition(int input1, int input2) {
    return input1 + input2;
}

double CMathOperations::submation(double input1, double input2) {
    return input1 - input2;
}

int CMathOperations::submation(int input1, int input2) {
    return input1 - input2;
}

double CMathOperations::multiplication(double input1, double input2) {
    return input1 * input2;
}

int CMathOperations::multiplication(int input1, int input2) {
    return input1 * input2;
}

double CMathOperations::division(double input1, double input2) {
    return input1 / input2;
}

int CMathOperations::division(int input1, int input2) {
    return input1 / input2;
}

double CMathOperations::modulus(double input1, double input2) {
    return fmod(input1, input2);
}

int CMathOperations::modulus(int input1, int input2) {
    return input1 % input2;
}

int CMathOperations::leftShift(int input1, int input2) {
    return input1 * (int)(pow(2, input2));
}

int CMathOperations::rightShift(int input1, int input2) {
    return input1 / (int)(pow(2, input2));
}

double CMathOperations::exponential(double input1, double input2) {
    return pow(input1, input2);
}

double CMathOperations::piNumber(int n) {
    return CMathOperations::piEstimate(n);
}

double CMathOperations::randNum() {
    double randomNum = rand() % 1000000;

    return (1 / randomNum);
}

double CMathOperations::absoluteNum(double input) {
    if (input < 0) {
        input *= -1;
    }

    return input;
}

double CMathOperations::signConversion(double input) {
    return (input *= -1);
}

double CMathOperations::inversion(double input) {
    return (1 / input);
}

double CMathOperations::exponentialBase2(double input) {
    return pow(2, input);
}

double CMathOperations::exponentialBase10(double input) {
    return pow(10, input);
}

double CMathOperations::exponentialEuler(double input) {
    return pow(eulerEstimate(32.0), input);
}

double CMathOperations::naturalLog(double input) {
    return lnEstimate(input, 32);
}

double CMathOperations::root(double input1, double input2) {
    return pow(input1, (1 / input2));
}

double CMathOperations::logFunction(double value, double base) {
    return logEstimate(value, base, 16);
}

double CMathOperations::factorial(double input) {
    return factorialOp(input);
}

double CMathOperations::sinFunction(double input) {
    return sinEstimate(input, 24);
}

double CMathOperations::cosFunction(double input) {
    return sinEstimate(piEstimate(10000000) / 2 - input, 24);
}

double CMathOperations::tanFunction(double input) {
    double sinNum = CMathOperations::sinEstimate(input, 24);
    double cosNum = CMathOperations::sinEstimate(piEstimate(10000000) / 2 - input, 24);
    if (cosNum == 0) {
        AfxMessageBox(_T("Error caused!"));
        return 0;
    }

    return sinNum / cosNum;
}

double CMathOperations::sigma(int upperLim, int lowerLim, CString equation) {
    // Evaluate
    double ans = 0.0;
   
    for (int i = lowerLim; i <= upperLim; i++) {
        std::string cloneStr = std::string(CT2CA(equation));

        // Substitute variables
        cloneStr = CNumberConverter::substituteN(cloneStr, i);
        
        // Evaluate the substituted expression
        double result = CNumberConverter::evaluateExpression(cloneStr);

        // Overflow detection 
        if ((result > 0 && ans > INT_MAX - result) ||
            (result < 0 && ans < INT_MIN - result)) {
            AfxMessageBox(_T("Overflow occurred during calculation."));
            return (result > 0) ? INT_MAX : INT_MIN; // if positive then max if negative then min
        }

        // Accumulate the result
        ans += result;
    }

    return ans;
}

CString CMathOperations::sigmaWorkings(int upperLim, int lowerLim, CString equation) {
    // Evaluate
    CString working;

    for (int i = lowerLim; i <= upperLim; i++) {
        std::string cloneStr = std::string(CT2CA(equation));

        // Substitute variables
        cloneStr = CNumberConverter::substituteN(cloneStr, i);
       
        // Evaluate the substituted expression
        double result = CNumberConverter::evaluateExpression(cloneStr);

        // Convert result to CString and update working
        CString workingAdd = DoubleToCString(result);
        if (!working.IsEmpty()) {
            working += _T(" + ");
        }
        working += workingAdd;

    }

    // Display everything needed
    // (Truncate is usually a function that is used for integers but
    // this limits the length to be shorter than the input)
    working.Truncate(working.GetLength()); 
    return working;
}