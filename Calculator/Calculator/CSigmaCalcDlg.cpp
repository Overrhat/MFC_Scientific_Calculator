// CSigmaCalcDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Calculator.h"
#include "CSigmaCalcDlg.h"
#include "afxdialogex.h"
#include "resource.h"

// CSigmaCalcDlg 대화 상자

IMPLEMENT_DYNAMIC(CSigmaCalcDlg, CDialogEx)

CSigmaCalcDlg::CSigmaCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SIGMACALC_DIALOG, pParent)
    , m_strWorking(_T(""))
    , m_strOutput(_T(""))
    , m_strUpper(_T("10"))
    , m_strLower(_T("1"))
    , m_strInput(_T(""))
{
    // Initialise new Sigma
    sigma = new CSigmaCtrl(this);
}

CSigmaCalcDlg::~CSigmaCalcDlg()
{
}

void CSigmaCalcDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_WORKING_DISP, m_strWorking);
    DDX_Text(pDX, IDC_OUTPUT_DISP, m_strOutput);
    DDX_Text(pDX, IDC_EDIT_UPPER, m_strUpper);
    DDX_Text(pDX, IDC_EDIT_LOWER, m_strLower);
    DDX_Text(pDX, IDC_EDIT_INPUT, m_strInput);
}


BEGIN_MESSAGE_MAP(CSigmaCalcDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_ANS, &CSigmaCalcDlg::OnBnClickedButtonAns)
END_MESSAGE_MAP()


// CSigmaCalcDlg 메시지 처리기

BOOL CSigmaCalcDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // Initialize the font with a larger size
    m_largeFont.CreatePointFont(1000, _T("Arial")); // 200 = 20pt font size
    GetDlgItem(IDC_STATIC_SIGMA)->SetFont(&m_largeFont);

    return TRUE;  // return TRUE unless you set the focus to a control
}

void CSigmaCalcDlg::OnBnClickedButtonAns()
{
    UpdateData(TRUE);
    // Evaluate
    sigma->bnClickedAns(m_strUpper, m_strLower, m_strInput);
}

void CSigmaCalcDlg::SetOutput(const CString& output)
{
    m_strOutput = output;

    UpdateData(FALSE);
}

void CSigmaCalcDlg::SetInput(const CString& input)
{
    m_strInput = input;

    UpdateData(FALSE);
}

void CSigmaCalcDlg::SetWorking(const CString& working)
{
    m_strWorking = working;

    UpdateData(FALSE);
}

void CSigmaCalcDlg::SetLower(const CString& lower)
{
    m_strLower = lower;

    UpdateData(FALSE);
}

void CSigmaCalcDlg::SetUpper(const CString& upper)
{
    m_strUpper = upper;

    UpdateData(FALSE);
}

void CSigmaCalcDlg::SetOutput(const int& output)
{
    m_strOutput.Format(_T("%d"), output);

    UpdateData(FALSE);
}

