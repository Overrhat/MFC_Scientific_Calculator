#include "pch.h"
#include "CSigmaCtrl.h"
#include "CNumberConverter.h"
#include <regex>
#include <string>
#include <cctype>
#include "CMathOperations.h"

CSigmaCtrl::CSigmaCtrl(CSigmaCalcDlg* sDlg) {
	// Initialization
	m_strUpperDisp = _T("");
	m_strLowerDisp = _T("");
	m_strInputDisp = _T("");
	m_strOutputDisp = _T("");
	m_strWorkingDisp = _T("");
	m_sDlg = sDlg;
}

void CSigmaCtrl::bnClickedAns(CString upperLim, CString lowerLim, CString inputStr) {
    // Initialization
    m_strUpperDisp = upperLim;
    m_strLowerDisp = lowerLim;
    m_strInputDisp = inputStr;
    CString answerStr;
    CString workingStr;
    int upperLimNum = _ttoi(upperLim);
    int lowerLimNum = _ttoi(lowerLim);

     // Check if the inputs are valid or not 
    if (!(this->isInputValid(m_strInputDisp, m_strUpperDisp, m_strLowerDisp))) {
        AfxMessageBox(_T("Invalid Input! Please try again!"), MB_ICONWARNING | MB_OK);
        m_sDlg->SetInput(_T(""));
        m_sDlg->SetUpper(_T("10"));
        m_sDlg->SetLower(_T("1"));
        return;
    }

    // If only numbers then return just the answer
    if (CSigmaCtrl::isOnlyNumber()) {
        m_sDlg->SetWorking(m_strInputDisp);
        std::string temp = std::string(CT2CA(m_strInputDisp));
        double tempNum = CNumberConverter::evaluateExpression(temp);
        CString ans = CMathOperations::DoubleToCString(tempNum);
        m_sDlg->SetOutput(ans);
        return;
    }

    // Get the answer
    answerStr = CMathOperations::DoubleToCString(CMathOperations::sigma(upperLimNum, lowerLimNum, inputStr));
    workingStr = CMathOperations::sigmaWorkings(upperLimNum, lowerLimNum, inputStr);

    m_sDlg->SetWorking(workingStr);
    m_sDlg->SetOutput(answerStr);
}

bool CSigmaCtrl::isOnlyNumber() {
	int checking = m_strInputDisp.Find(_T('n'));

	return (checking == -1);
}

bool CSigmaCtrl::isInputValid(const CString& inputStr, const CString& upperLim, const CString& lowerLim) {
    // If any of the input is empty then it's invalid
    if (inputStr == _T("") || upperLim == _T("") || lowerLim == _T("")) {
        return false;
    }

    // Convert CString to std::string
    std::string inputStrStd = std::string(CT2A(inputStr));
    std::string upperLimStd = std::string(CT2A(upperLim));
    std::string lowerLimStd = std::string(CT2A(lowerLim));

    // Check if the number of opening and closing brackets are the same
    int bracketCount = 0;
    for (char ch : inputStrStd) {
        if (ch == '(') {
            bracketCount++;
        }
        else if (ch == ')') {
            bracketCount--;
        }
        if (bracketCount < 0) { // More closing brackets than opening brackets
            return false;
        }
    }
    if (bracketCount != 0) { // Unbalanced brackets
        return false;
    }

    // Check for consecutive operators
    const std::string operators = "+-*/";
    for (size_t i = 1; i < inputStrStd.size(); ++i) {
        if (operators.find(inputStrStd[i - 1]) != std::string::npos &&
            operators.find(inputStrStd[i]) != std::string::npos) {
            return false; // Found consecutive operators
        }
    }

    // Check the number of operators vs operands
    int operandCount = 0, operatorCount = 0;
    bool firstIsNegative = false;
    int i = 0;

    // Checking if the first occurence is negative number
    while (!firstIsNegative) {
        char ch = inputStrStd[i];
        if (ch == '(') {
            i++;
            continue;
        }
        else if (ch == '-') {
            firstIsNegative = true;
        }
        else {
            break;
        }
    }

    // Identify operands and operators
    bool lastWasDigit = false;
    for (size_t i = 0; i < inputStrStd.size(); ++i) {
        char ch = inputStrStd[i];
        if (isdigit(ch) || ch == 'n') {
            if (!lastWasDigit) { // New operand starts
                operandCount++;
            }
            lastWasDigit = true;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            operatorCount++;
            lastWasDigit = false;
        }
        else {
            lastWasDigit = false; // Reset for non-digit characters
        }
    }

    // Validate operator and operand counts
    if (firstIsNegative) {
        if (operatorCount > operandCount) { // Allow operators == operands in this case
            return false;
        }
    }
    else {
        if (operatorCount >= operandCount) { // Strictly fewer operators than operands
            return false;
        }
    }

    // Define the unwanted patterns for inputStr
    std::regex invalidInputStrPattern("[a-mp-zA-MP-Z]"); // Invalid characters in inputStr
    std::regex numberSpaceLetterPattern("\\d+\\s+[a-zA-Z]"); // A number followed by a space and a letter
    std::regex divisionByZeroPattern("/\\s*0");             // Division by zero

    // Define the unwanted patterns for upperLim and lowerLim
    std::regex invalidLimPattern("[a-zA-Z]|\\."); // Invalid characters in limits

    // Check inputStr for invalid characters or number-space-letter pattern
    if (std::regex_search(inputStrStd, invalidInputStrPattern) ||
        std::regex_search(inputStrStd, numberSpaceLetterPattern) ||
        std::regex_search(inputStrStd, divisionByZeroPattern)) {
        return false;
    }

    // Check upperLim for invalid characters
    if (std::regex_search(upperLimStd, invalidLimPattern)) {
        return false;
    }

    // Check lowerLim for invalid characters
    if (std::regex_search(lowerLimStd, invalidLimPattern)) {
        return false;
    }

    // Checking if the lower limit is larger than the upper limit
    int up = _ttoi(upperLim);
    int low = _ttoi(lowerLim);
    if (low > up) {
        return false;
    }

    // Checking if the boundaries are positive numbers
    if (low < 0 || up < 0) {
        return false;
    }

    // Checking if the numbers are too large
    if (low > INT_MAX - 2 || up > INT_MAX - 2) {
        return false;
    }

    // Checking if the range is too big
    if (up - low > 10000) {
        return false;
    }

    return true;
}
