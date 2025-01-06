// CScientificCalcDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Calculator.h"
#include "CScientificCalcDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "CMathOperations.h"


// CScientificCalcDlg 대화 상자

IMPLEMENT_DYNAMIC(CScientificCalcDlg, CDialogEx)

CScientificCalcDlg::CScientificCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCIENTIFICCALC_DIALOG, pParent)
	, m_strInput(_T(""))
	, m_strOutput(_T(""))
{
	// Initialise this scientific
	scientific = new CScientificCtrl(this);
}

CScientificCalcDlg::~CScientificCalcDlg()
{
}

void CScientificCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUT_DISP, m_strInput);
	DDX_Text(pDX, IDC_OUTPUT_DISP, m_strOutput);
}


BEGIN_MESSAGE_MAP(CScientificCalcDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_0, &CScientificCalcDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CScientificCalcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CScientificCalcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CScientificCalcDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CScientificCalcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CScientificCalcDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CScientificCalcDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CScientificCalcDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CScientificCalcDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CScientificCalcDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CScientificCalcDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CScientificCalcDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CScientificCalcDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CScientificCalcDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_MOD, &CScientificCalcDlg::OnBnClickedButtonMod)
	ON_BN_CLICKED(IDC_BUTTON_EXP, &CScientificCalcDlg::OnBnClickedButtonExp)
	ON_BN_CLICKED(IDC_BUTTON_EQL, &CScientificCalcDlg::OnBnClickedButtonEql)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CScientificCalcDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_CLR, &CScientificCalcDlg::OnBnClickedButtonClr)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CScientificCalcDlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_RAND, &CScientificCalcDlg::OnBnClickedButtonRand)
	ON_BN_CLICKED(IDC_BUTTON_PI, &CScientificCalcDlg::OnBnClickedButtonPi)
	ON_BN_CLICKED(IDC_BUTTON_FAC, &CScientificCalcDlg::OnBnClickedButtonFac)
	ON_BN_CLICKED(IDC_BUTTON_ABS, &CScientificCalcDlg::OnBnClickedButtonAbs)
	ON_BN_CLICKED(IDC_BUTTON_INV, &CScientificCalcDlg::OnBnClickedButtonInv)
	ON_BN_CLICKED(IDC_BUTTON_CON, &CScientificCalcDlg::OnBnClickedButtonCon)
	ON_BN_CLICKED(IDC_BUTTON_10X, &CScientificCalcDlg::OnBnClickedButton10x)
	ON_BN_CLICKED(IDC_BUTTON_2X, &CScientificCalcDlg::OnBnClickedButton2x)
	ON_BN_CLICKED(IDC_BUTTON_E, &CScientificCalcDlg::OnBnClickedButtonE)
	ON_BN_CLICKED(IDC_BUTTON_SIN, &CScientificCalcDlg::OnBnClickedButtonSin)
	ON_BN_CLICKED(IDC_BUTTON_COS, &CScientificCalcDlg::OnBnClickedButtonCos)
	ON_BN_CLICKED(IDC_BUTTON_TAN, &CScientificCalcDlg::OnBnClickedButtonTan)
	ON_BN_CLICKED(IDC_BUTTON_LN, &CScientificCalcDlg::OnBnClickedButtonLn)
	ON_BN_CLICKED(IDC_BUTTON_ROOT, &CScientificCalcDlg::OnBnClickedButtonRoot)
	ON_BN_CLICKED(IDC_BUTTON_LOG, &CScientificCalcDlg::OnBnClickedButtonLog)
END_MESSAGE_MAP()


// CScientificCalcDlg 메시지 처리기
void CScientificCalcDlg::SetOutput(const CString& output)
{
	m_strOutput = output;

	UpdateData(FALSE);
}

void CScientificCalcDlg::SetInput(const CString& input)
{
	m_strInput = input;

	UpdateData(FALSE);
}

void CScientificCalcDlg::SetOutput(const double& output)
{
	m_strOutput = CMathOperations::DoubleToCString(output);

	UpdateData(FALSE);
}

void CScientificCalcDlg::SetInput(const double& input)
{
	m_strInput = CMathOperations::DoubleToCString(input);

	UpdateData(FALSE);
}


void CScientificCalcDlg::OnBnClickedButton0()
{
	scientific->bnClickedButton0();
}


void CScientificCalcDlg::OnBnClickedButton1()
{
	scientific->bnClickedButton1();
}


void CScientificCalcDlg::OnBnClickedButton2()
{
	scientific->bnClickedButton2();
}


void CScientificCalcDlg::OnBnClickedButton3()
{
	scientific->bnClickedButton3();
}


void CScientificCalcDlg::OnBnClickedButton4()
{
	scientific->bnClickedButton4();
}


void CScientificCalcDlg::OnBnClickedButton5()
{
	scientific->bnClickedButton5();
}


void CScientificCalcDlg::OnBnClickedButton6()
{
	scientific->bnClickedButton6();
}


void CScientificCalcDlg::OnBnClickedButton7()
{
	scientific->bnClickedButton7();
}


void CScientificCalcDlg::OnBnClickedButton8()
{
	scientific->bnClickedButton8();
}


void CScientificCalcDlg::OnBnClickedButton9()
{
	scientific->bnClickedButton9();
}


void CScientificCalcDlg::OnBnClickedButtonAdd()
{
	scientific->bnClickedButtonAdd();
}


void CScientificCalcDlg::OnBnClickedButtonSub()
{
	scientific->bnClickedButtonSub();
}


void CScientificCalcDlg::OnBnClickedButtonMul()
{
	scientific->bnClickedButtonMul();
}


void CScientificCalcDlg::OnBnClickedButtonDiv()
{
	scientific->bnClickedButtonDiv(); 
}


void CScientificCalcDlg::OnBnClickedButtonMod()
{
	scientific->bnClickedButtonMod();
}


void CScientificCalcDlg::OnBnClickedButtonExp()
{
	scientific->bnClickedButtonExp();
}


void CScientificCalcDlg::OnBnClickedButtonEql()
{
	scientific->bnClickedButtonEql();
}


void CScientificCalcDlg::OnBnClickedButtonDot()
{
	scientific->bnClickedButtonDot();
}


void CScientificCalcDlg::OnBnClickedButtonClr()
{
	scientific->bnClickedButtonClr();
}


void CScientificCalcDlg::OnBnClickedButtonDel()
{
	scientific->bnClickedButtonDel();
}


void CScientificCalcDlg::OnBnClickedButtonRand()
{
	scientific->bnClickedButtonRand();
}


void CScientificCalcDlg::OnBnClickedButtonPi()
{
	scientific->bnClickedButtonPi();
}


void CScientificCalcDlg::OnBnClickedButtonFac()
{
	scientific->bnClickedButtonFac();
}


void CScientificCalcDlg::OnBnClickedButtonAbs()
{
	scientific->bnClickedButtonAbs();
}


void CScientificCalcDlg::OnBnClickedButtonInv()
{
	scientific->bnClickedButtonInv();
}


void CScientificCalcDlg::OnBnClickedButtonCon()
{
	scientific->bnClickedButtonCon();
}


void CScientificCalcDlg::OnBnClickedButton10x()
{
	scientific->bnClickedButton10x();
}


void CScientificCalcDlg::OnBnClickedButton2x()
{
	scientific->bnClickedButton2x();
}


void CScientificCalcDlg::OnBnClickedButtonE()
{
	scientific->bnClickedButtonE();
}


void CScientificCalcDlg::OnBnClickedButtonSin()
{
	scientific->bnClickedButtonSin();
}


void CScientificCalcDlg::OnBnClickedButtonCos()
{
	scientific->bnClickedButtonCos();
}


void CScientificCalcDlg::OnBnClickedButtonTan()
{
	scientific->bnClickedButtonTan();
}


void CScientificCalcDlg::OnBnClickedButtonLn()
{
	scientific->bnClickedButtonLn();
}


void CScientificCalcDlg::OnBnClickedButtonRoot()
{
	scientific->bnClickedButtonRoot();
}


void CScientificCalcDlg::OnBnClickedButtonLog()
{
	scientific->bnClickedButtonLog();
}

afx_msg void CScientificCalcDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// Forward the key event to ProgrammerCalc
	scientific->HandleKeyDown(nChar);
}

BOOL CScientificCalcDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		OnKeyDown(pMsg->wParam, pMsg->lParam, 0); // Forward the keydown message
		return TRUE; // Indicate that the message was handled
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
