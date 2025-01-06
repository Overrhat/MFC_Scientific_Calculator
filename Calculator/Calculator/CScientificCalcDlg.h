#pragma once
#include "CScientificCtrl.h"

class CScientificCtrl;

// CScientificCalcDlg 대화 상자

class CScientificCalcDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CScientificCalcDlg)

public:
	CScientificCalcDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CScientificCalcDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCIENTIFICCALC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// Scientific Controller Pointer
	CScientificCtrl* scientific;

	// This is an input display
	CString m_strInput;
	// This is an output display
	CString m_strOutput;

	// Setters
	void SetOutput(const CString& output);
	void SetInput(const CString& input);
	// Setters with number input
	void SetOutput(const double& output);
	void SetInput(const double& input);

	// Numbers being clicked
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();

	// Operators being clicked
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonMod();
	afx_msg void OnBnClickedButtonExp();
	afx_msg void OnBnClickedButtonEql();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButtonRoot();

	// Clear and Delete
	afx_msg void OnBnClickedButtonClr();
	afx_msg void OnBnClickedButtonDel();

	// Constants
	afx_msg void OnBnClickedButtonRand();
	afx_msg void OnBnClickedButtonPi();

	// Instant change functions
	afx_msg void OnBnClickedButtonFac();
	afx_msg void OnBnClickedButtonAbs();
	afx_msg void OnBnClickedButtonInv();
	afx_msg void OnBnClickedButtonCon();
	afx_msg void OnBnClickedButton10x();
	afx_msg void OnBnClickedButton2x();
	afx_msg void OnBnClickedButtonE();
	afx_msg void OnBnClickedButtonLn();
	afx_msg void OnBnClickedButtonLog();

	// Trigonometry
	afx_msg void OnBnClickedButtonSin();
	afx_msg void OnBnClickedButtonCos();
	afx_msg void OnBnClickedButtonTan();

	// Key Click Handler
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	// PreTranslateMessage to capture key events
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
