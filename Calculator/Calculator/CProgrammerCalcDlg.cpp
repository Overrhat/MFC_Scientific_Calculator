// CProgrammerCalcDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Calculator.h"
#include "CProgrammerCalcDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "CNumberConverter.h"


// CProgrammerCalcDlg 대화 상자

IMPLEMENT_DYNAMIC(CProgrammerCalcDlg, CDialogEx)

CProgrammerCalcDlg::CProgrammerCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROGRAMMERCALC_DIALOG, pParent)
	, m_strInput(_T(""))
	, m_strOutput(_T(""))
	, m_strNumSys(_T("Decimal"))
{
	// Initialise new Programmer
	programmer = new CProgrammerCtrl(this);
}

CProgrammerCalcDlg::~CProgrammerCalcDlg()
{
}

void CProgrammerCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUT_DISP, m_strInput);
	DDX_Text(pDX, IDC_OUTPUT_DISP, m_strOutput);
	DDX_Text(pDX, IDC_NUMSYS, m_strNumSys);
}


BEGIN_MESSAGE_MAP(CProgrammerCalcDlg, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON_0, &CProgrammerCalcDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CProgrammerCalcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CProgrammerCalcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CProgrammerCalcDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CProgrammerCalcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CProgrammerCalcDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CProgrammerCalcDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CProgrammerCalcDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CProgrammerCalcDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CProgrammerCalcDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_A, &CProgrammerCalcDlg::OnBnClickedButtonA)
	ON_BN_CLICKED(IDC_BUTTON_B, &CProgrammerCalcDlg::OnBnClickedButtonB)
	ON_BN_CLICKED(IDC_BUTTON_C, &CProgrammerCalcDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_D, &CProgrammerCalcDlg::OnBnClickedButtonD)
	ON_BN_CLICKED(IDC_BUTTON_E, &CProgrammerCalcDlg::OnBnClickedButtonE)
	ON_BN_CLICKED(IDC_BUTTON_F, &CProgrammerCalcDlg::OnBnClickedButtonF)
	ON_BN_CLICKED(IDC_BUTTON_HEX, &CProgrammerCalcDlg::OnBnClickedButtonHex)
	ON_BN_CLICKED(IDC_BUTTON_DEC, &CProgrammerCalcDlg::OnBnClickedButtonDec)
	ON_BN_CLICKED(IDC_BUTTON_OCT, &CProgrammerCalcDlg::OnBnClickedButtonOct)
	ON_BN_CLICKED(IDC_BUTTON_BIN, &CProgrammerCalcDlg::OnBnClickedButtonBin)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CProgrammerCalcDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CProgrammerCalcDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CProgrammerCalcDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CProgrammerCalcDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_MOD, &CProgrammerCalcDlg::OnBnClickedButtonMod)
	ON_BN_CLICKED(IDC_BUTTON_LSH, &CProgrammerCalcDlg::OnBnClickedButtonLsh)
	ON_BN_CLICKED(IDC_BUTTON_RSH, &CProgrammerCalcDlg::OnBnClickedButtonRsh)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CProgrammerCalcDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_CLR, &CProgrammerCalcDlg::OnBnClickedButtonClr)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CProgrammerCalcDlg::OnBnClickedButtonDel)
END_MESSAGE_MAP()


// CProgrammerCalcDlg 메시지 처리기


void CProgrammerCalcDlg::OnBnClickedButton0()
{
	programmer->bnClickedButton0();
}


void CProgrammerCalcDlg::OnBnClickedButton1()
{
	programmer->bnClickedButton1();
}


void CProgrammerCalcDlg::OnBnClickedButton2()
{
	programmer->bnClickedButton2();
}


void CProgrammerCalcDlg::OnBnClickedButton3()
{
	programmer->bnClickedButton3();
}


void CProgrammerCalcDlg::OnBnClickedButton4()
{
	programmer->bnClickedButton4();
}


void CProgrammerCalcDlg::OnBnClickedButton5()
{
	programmer->bnClickedButton5();
}


void CProgrammerCalcDlg::OnBnClickedButton6()
{
	programmer->bnClickedButton6();
}


void CProgrammerCalcDlg::OnBnClickedButton7()
{
	programmer->bnClickedButton7();
}


void CProgrammerCalcDlg::OnBnClickedButton8()
{
	programmer->bnClickedButton8();
}


void CProgrammerCalcDlg::OnBnClickedButton9()
{
	programmer->bnClickedButton9();
}


void CProgrammerCalcDlg::OnBnClickedButtonA()
{
	programmer->bnClickedButtonA();
}


void CProgrammerCalcDlg::OnBnClickedButtonB()
{
	programmer->bnClickedButtonB();
}


void CProgrammerCalcDlg::OnBnClickedButtonC()
{
	programmer->bnClickedButtonC();
}


void CProgrammerCalcDlg::OnBnClickedButtonD()
{
	programmer->bnClickedButtonD();
}


void CProgrammerCalcDlg::OnBnClickedButtonE()
{
	programmer->bnClickedButtonE();
}


void CProgrammerCalcDlg::OnBnClickedButtonF()
{
	programmer->bnClickedButtonF();
}


void CProgrammerCalcDlg::OnBnClickedButtonHex()
{
	programmer->bnClickedButtonHex();
}


void CProgrammerCalcDlg::OnBnClickedButtonDec()
{
	programmer->bnClickedButtonDec();
}


void CProgrammerCalcDlg::OnBnClickedButtonOct()
{
	programmer->bnClickedButtonOct();
}


void CProgrammerCalcDlg::OnBnClickedButtonBin()
{
	programmer->bnClickedButtonBin();
}


void CProgrammerCalcDlg::OnBnClickedButtonAdd()
{
	programmer->bnClickedButtonAdd();
}


void CProgrammerCalcDlg::OnBnClickedButtonSub()
{
	programmer->bnClickedButtonSub();
}


void CProgrammerCalcDlg::OnBnClickedButtonMul()
{
	programmer->bnClickedButtonMul();
}


void CProgrammerCalcDlg::OnBnClickedButtonDiv()
{
	programmer->bnClickedButtonDiv();
}


void CProgrammerCalcDlg::OnBnClickedButtonMod()
{
	programmer->bnClickedButtonMod();
}


void CProgrammerCalcDlg::OnBnClickedButtonLsh()
{
	programmer->bnClickedButtonLsh();
}


void CProgrammerCalcDlg::OnBnClickedButtonRsh()
{
	programmer->bnClickedButtonRsh();
}


void CProgrammerCalcDlg::OnBnClickedButtonEqual()
{
	programmer->bnClickedButtonEqual();
}


void CProgrammerCalcDlg::OnBnClickedButtonClr()
{
	programmer->bnClickedButtonClr();
}


void CProgrammerCalcDlg::OnBnClickedButtonDel()
{
	programmer->bnClickedButtonDel();
}

void CProgrammerCalcDlg::SetOutput(const CString& output)
{
	m_strOutput = output;

	UpdateData(FALSE);
}

void CProgrammerCalcDlg::SetInput(const CString& input)
{
	m_strInput = input;

	UpdateData(FALSE);
}

void CProgrammerCalcDlg::SetNumSys(const CString& numSys)
{
	m_strNumSys = numSys;

	UpdateData(FALSE);
}

void CProgrammerCalcDlg::SetOutput(const int& output, const CString& numSys)
{
	if (numSys == _T("Decimal")) {
		m_strOutput.Format(_T("%d"), output);
	}
	else if (numSys == _T("Hexadecimal")) {
		m_strOutput = CNumberConverter::decToHex(output);
	}
	else if (numSys == _T("Binary")) {
		m_strOutput = CNumberConverter::decToBin(output);
	}
	else if (numSys == _T("Octal")) {
		m_strOutput = CNumberConverter::decToOct(output);
	}

	UpdateData(FALSE);
}

void CProgrammerCalcDlg::SetInput(const int& input, const CString& numSys)
{
	if (numSys == _T("Decimal")) {
		m_strInput.Format(_T("%d"), input);
	}
	else if (numSys == _T("Hexadecimal")) {
		m_strInput = CNumberConverter::decToHex(input);
	}
	else if (numSys == _T("Binary")) {
		m_strInput = CNumberConverter::decToBin(input);
	}
	else if (numSys == _T("Octal")) {
		m_strInput = CNumberConverter::decToOct(input);
	}

	UpdateData(FALSE);
}

afx_msg void CProgrammerCalcDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// Forward the key event to ProgrammerCalc
	programmer->HandleKeyDown(nChar);
}

BOOL CProgrammerCalcDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		OnKeyDown(pMsg->wParam, pMsg->lParam, 0); // Forward the keydown message
		return TRUE; // Indicate that the message was handled
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
