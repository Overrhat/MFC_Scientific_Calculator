#pragma once
class CMathOperations
{
private:
    // Private functions that are being used as calculations
    static double factorialOp(double value);
    static bool isInteger(double value);
    static double eulerEstimate(int estimationNumber);
    static double piEstimate(int estimationNumber);
    static double sinEstimate(double value, int estimationNumber); 
    static double lnEstimate(double value, int estimationNumber); 
    static double logEstimate(double value, double base, int estimationNumber);

public:
    static bool isNegative(CString input1);
    static CString DoubleToCString(double value);

    // Overload the functions being used for both integer and double
    static double addition(double input1, double input2);
    static int addition(int input1, int input2);
    static double submation(double input1, double input2);
    static int submation(int input1, int input2);
    static double multiplication(double input1, double input2);
    static int multiplication(int input1, int input2);
    static double division(double input1, double input2);
    static int division(int input1, int input2);
    static double modulus(double input1, double input2);
    static int modulus(int input1, int input2);

    // Trigonometry
    static double sinFunction(double input);
    static double cosFunction(double input);
    static double tanFunction(double input);

    // Use numbers instead of string
    static int leftShift(int input1, int input2);
    static int rightShift(int input1, int input2);
    static double exponential(double input1, double input2);

    // Double number generator
    static double piNumber(int n);
    static double randNum();

    // Other operators
    static double factorial(double input);
    static double absoluteNum(double input);
    static double inversion(double input);
    static double signConversion(double input);
    static double exponentialBase2(double input);
    static double exponentialBase10(double input);
    static double exponentialEuler(double input);
    static double naturalLog(double input);
    static double root(double input1, double input2);
    static double logFunction(double value, double base);

    // Functions for Sigma Calculation
    static CString sigmaWorkings(int upperLim, int lowerLim, CString equation);
    static double sigma(int upperLim, int lowerLim, CString equation);
};