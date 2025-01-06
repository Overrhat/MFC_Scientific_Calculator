#pragma once
#include "CSigmaCtrl.h"

class CSigmaCtrl;


// CSigmaCalcDlg 대화 상자

class CSigmaCalcDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSigmaCalcDlg)

public:
	CSigmaCalcDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSigmaCalcDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIGMACALC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	CFont m_largeFont;
public:
	// This shows the working of the outcome
	CString m_strWorking;
	// This shows the answer
	CString m_strOutput;
	
	// This is for the answer button
	afx_msg void OnBnClickedButtonAns();

	// Upper Limit input
	CString m_strUpper;
	// Lower Limit Input
	CString m_strLower;
	// The Main Input
	CString m_strInput;

	// Setters 
	void SetOutput(const CString& output);
	void SetInput(const CString& input);
	void SetWorking(const CString& working);
	void SetLower(const CString& lower);
	void SetUpper(const CString& upper);
	void SetOutput(const int& output);

	// Sigma pointer
	CSigmaCtrl* sigma;
};
