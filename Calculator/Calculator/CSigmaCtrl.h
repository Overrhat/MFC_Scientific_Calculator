#pragma once
#include "CSigmaCalcDlg.h"

class CSigmaCalcDlg;

class CSigmaCtrl
{
private:
	// Member Variables
	CSigmaCalcDlg* m_sDlg; // Pointer to the dialog
	CString m_strLowerDisp, m_strUpperDisp, m_strInputDisp;
	CString m_strWorkingDisp, m_strOutputDisp;

	// Local Functions
	bool isOnlyNumber();
	bool isInputValid(const CString& inputStr, const CString& upperLim, const CString& lowerLim);
public:
	// Constructor
	CSigmaCtrl(CSigmaCalcDlg* pDlg);

	void bnClickedAns(CString upperLim, CString lowerLim, CString inputStr);
};

