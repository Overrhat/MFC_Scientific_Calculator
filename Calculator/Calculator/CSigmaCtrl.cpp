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
        m_sDlg->SetUpper(_T(""));
        m_sDlg->SetLower(_T(""));
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

    // Define the unwanted patterns for inputStr
    std::regex invalidInputStrPattern("[a-mo-zA-MO-Z]"); // Invalid characters in inputStr
    std::regex numberSpaceLetterPattern("\\d+\\s+[a-zA-Z]"); // A number followed by a space and a letter
    std::regex divisionByZeroPattern("/\\s*0");             // Division by zero

    // Define the unwanted patterns for upperLim and lowerLim
    std::regex invalidLimPattern("[a-zA-Z]|\\."); // Invalid characters in limits

    // Convert CString to std::string
    std::string inputStrStd = std::string(CT2A(inputStr));
    std::string upperLimStd = std::string(CT2A(upperLim));
    std::string lowerLimStd = std::string(CT2A(lowerLim));

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

