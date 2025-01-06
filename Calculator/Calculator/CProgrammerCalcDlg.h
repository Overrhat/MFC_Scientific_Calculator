#pragma once
#include "CProgrammerCtrl.h"

class CProgrammerCtrl;

// CProgrammerCalcDlg 대화 상자

class CProgrammerCalcDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProgrammerCalcDlg)

public:
	CProgrammerCalcDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CProgrammerCalcDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRAMMERCALC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.


	DECLARE_MESSAGE_MAP();

public:

	// Input Display
	CString m_strInput;
	// Output Display
	CString m_strOutput;
	// Number System Display
	CString m_strNumSys;

	// Numbers Clicked
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

	// Letters Clicked
	afx_msg void OnBnClickedButtonA();
	afx_msg void OnBnClickedButtonB();
	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonD();
	afx_msg void OnBnClickedButtonE();
	afx_msg void OnBnClickedButtonF();

	// Number Systems Clicked
	afx_msg void OnBnClickedButtonHex();
	afx_msg void OnBnClickedButtonDec();
	afx_msg void OnBnClickedButtonOct();
	afx_msg void OnBnClickedButtonBin();

	// Operations Clicked
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonMod();
	afx_msg void OnBnClickedButtonLsh();
	afx_msg void OnBnClickedButtonRsh();

	afx_msg void OnBnClickedButtonEqual();

	// Clear and Delete
	afx_msg void OnBnClickedButtonClr();
	afx_msg void OnBnClickedButtonDel();

	// Setters
	void SetOutput(const CString& output);
	void SetInput(const CString& input);
	void SetNumSys(const CString& numSys);
	// Setters with number input
	void SetOutput(const int& output, const CString& numSys);
	void SetInput(const int& input, const CString& numSys);

	// Programmer Pointer
	CProgrammerCtrl* programmer;

	// Key Click Handler
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	// PreTranslateMessage to capture key events
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
