#include "pch.h"
#include "CScientificCtrl.h"
#include "CScientificCalcDlg.h"
#include "CMathOperations.h"

CScientificCtrl::CScientificCtrl(CScientificCalcDlg* sDlg) {
	// Initialization

	// Strings for inputs
	m_strInput1 = _T("");
	m_strInput2 = _T("");

	// Input numbers stored as double values
	m_num1 = 0.0;
	m_num2 = 0.0;

	// Strings that will be used for display
	m_strInputDisp = _T("");
	m_strOutputDisp = _T("");

	// Identifier that decides if currernt input is for the first value or the second
	m_isFirst = true;

	// Identifier that decides which operation that will terminate when equal sign is clicekd
	m_opIdentifier = 1;

	// The instance of the dialog class
	m_sDlg = sDlg;
}

void CScientificCtrl::bnClickedButton0() {
	this->numbersClicked(0);
}

void CScientificCtrl::bnClickedButton1() {
	this->numbersClicked(1);
}

void CScientificCtrl::bnClickedButton2() {
	this->numbersClicked(2);
}

void CScientificCtrl::bnClickedButton3() {
	this->numbersClicked(3);
}

void CScientificCtrl::bnClickedButton4() {
	this->numbersClicked(4);
}

void CScientificCtrl::bnClickedButton5() {
	this->numbersClicked(5);
}

void CScientificCtrl::bnClickedButton6() {
	this->numbersClicked(6);
}

void CScientificCtrl::bnClickedButton7() {
	this->numbersClicked(7);
}

void CScientificCtrl::bnClickedButton8() {
	this->numbersClicked(8);
}

void CScientificCtrl::bnClickedButton9() {
	this->numbersClicked(9);
}

void CScientificCtrl::bnClickedButtonDot() {
	if (m_isFirst) {
		// When there is an output then make the str1 empty
		if (m_strOutputDisp != _T("")) {
			m_strInput1 = _T("");
			m_strOutputDisp = _T("");
		}

		// Check if a decimal point already exists in the input
		if (m_strInput1.Find(_T(".")) == -1) {
			m_strInput1 += _T(".");
		}

		m_strInputDisp = m_strInput1;
	}
	else {
		// Check if a decimal point already exists in the input
		if (m_strInput2.Find(_T(".")) == -1) {
			m_strInput2 += _T(".");
		}

		m_strInputDisp = m_strInput2;
	}
	// Set the data
	m_sDlg->SetInput(m_strInputDisp);
	m_sDlg->SetOutput(m_strOutputDisp);
}

void CScientificCtrl::bnClickedButtonEql()
{
	switch (m_opIdentifier) {
	case 1: // Addition
		m_num1 = CMathOperations::addition(m_num1, m_num2);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strOutputDisp = m_strInput1;

		// Update
		m_strInputDisp = _T("");
		m_sDlg->SetInput(m_strInputDisp);
		m_strInput2 = _T("");
		m_num2 = 0.0;
		m_sDlg->SetOutput(m_strOutputDisp);
		break;
	case 2: // Submation
		m_num1 = CMathOperations::submation(m_num1, m_num2);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strOutputDisp = m_strInput1;

		// Update
		m_strInputDisp = _T("");
		m_sDlg->SetInput(m_strInputDisp);
		m_strInput2 = _T("");
		m_num2 = 0.0;
		m_sDlg->SetOutput(m_strOutputDisp);
		break;
	case 3: // Multiplication
		m_num1 = CMathOperations::multiplication(m_num1, m_num2);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strOutputDisp = m_strInput1;

		// Update
		m_strInputDisp = _T("");
		m_sDlg->SetInput(m_strInputDisp);
		m_strInput2 = _T("");
		m_num2 = 0.0;
		m_sDlg->SetOutput(m_strOutputDisp);
		break;
	case 4: // Division
		// Handle the division by 0
		if (m_strInput2 == _T("0") || m_strInput2 == _T("") || m_strInput2 == _T("00") || m_num2 == 0) {
			// Update
			m_strInputDisp = _T("");
			m_sDlg->SetInput(m_strInputDisp);
			m_strInput1 = m_strInputDisp;
			m_strInput2 = _T("");
			m_num1 = 0.0;
			m_num2 = 0.0;
			m_strOutputDisp = ("Can't divide by 0!");
			m_sDlg->SetOutput(m_strOutputDisp);
			break;
		}

		m_num1 = CMathOperations::division(m_num1, m_num2);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strOutputDisp = m_strInput1;

		// Update
		m_strInputDisp = _T("");
		m_sDlg->SetInput(m_strInputDisp);
		m_strInput2 = _T("");
		m_num2 = 0.0;
		m_sDlg->SetOutput(m_strOutputDisp);
		break;
	case 5: // Modulus
		// Handle the modulo by 0
		if (m_strInput2 == _T("0") || m_strInput2 == _T("") || m_strInput2 == _T("00") || m_num2 == 0) {
			// Update
			m_strInputDisp = _T("");
			m_sDlg->SetInput(m_strInputDisp);
			m_strInput1 = m_strInputDisp;
			m_strInput2 = _T("");
			m_num1 = 0.0;
			m_num2 = 0.0;
			m_strOutputDisp = ("Modulo by 0 is Invalid");
			m_sDlg->SetOutput(m_strOutputDisp);
			break;
		}

		m_num1 = CMathOperations::modulus(m_num1, m_num2);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strOutputDisp = m_strInput1;

		// Update
		m_strInputDisp = _T("");
		m_sDlg->SetInput(m_strInputDisp);
		m_strInput2 = _T("");
		m_num2 = 0.0;
		m_sDlg->SetOutput(m_strOutputDisp);
		break;
	case 6: // Exponential
		// Handle 0^0
		if ((m_num1 == 0 && m_num2 == 0) || (m_num1 == 0 && m_num2 < 0)) {
			// Update
			m_strInputDisp = _T("");
			m_sDlg->SetInput(m_strInputDisp);
			m_strInput1 = m_strInputDisp;
			m_strInput2 = _T("");
			m_num1 = 0.0;
			m_num2 = 0.0;
			m_strOutputDisp = ("Undefined");
			m_sDlg->SetOutput(m_strOutputDisp);
			break;
		}

		m_num1 = CMathOperations::exponential(m_num1, m_num2);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strOutputDisp = m_strInput1;

		// Update
		m_strInputDisp = _T("");
		m_sDlg->SetInput(m_strInputDisp);
		m_strInput2 = _T("");
		m_num2 = 0.0;
		m_sDlg->SetOutput(m_strOutputDisp);
		break;
	case 7: // Root
		// Handle the negative roots
		if (CMathOperations::isNegative(m_strInput1) || m_num1 < 0) {
			// Update
			m_strInputDisp = _T("");
			m_sDlg->SetInput(m_strInputDisp);
			m_strInput1 = m_strInputDisp;
			m_strInput2 = _T("");
			m_num1 = 0.0;
			m_num2 = 0.0;
			m_strOutputDisp = ("Can't have negative roots!");
			m_sDlg->SetOutput(m_strOutputDisp);
			break;
		}

		m_num1 = CMathOperations::root(m_num1, m_num2);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strOutputDisp = m_strInput1;

		// Update
		m_strInputDisp = _T("");
		m_sDlg->SetInput(m_strInputDisp);
		m_strInput2 = _T("");
		m_num2 = 0.0;
		m_sDlg->SetOutput(m_strOutputDisp);
		break;
	case 8: // Log
		// Handle the negative roots
		if (CMathOperations::isNegative(m_strInput1) || m_strInput2 == _T("1") || 
			m_strInput2 == _T("0") || m_num1 < 0 || m_num2 == 1 || m_num2 == 0 || m_num2 < 0) {
			// Update
			m_strInputDisp = _T("");
			m_sDlg->SetInput(m_strInputDisp);
			m_strInput1 = m_strInputDisp;
			m_strInput2 = _T("");
			m_num1 = 0.0;
			m_num2 = 0.0;
			m_strOutputDisp = ("Invalid input!");
			m_sDlg->SetOutput(m_strOutputDisp);
			break;
		}

		m_num1 = CMathOperations::logFunction(m_num1, m_num2);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strOutputDisp = m_strInput1;

		// Update
		m_strInputDisp = _T("");
		m_sDlg->SetInput(m_strInputDisp);
		m_strInput2 = _T("");
		m_num2 = 0.0;
		m_sDlg->SetOutput(m_strOutputDisp);
		break;
	default:
		AfxMessageBox(_T("Error! Please restart!"));
	}
	m_isFirst = true; // Bringing back to the first input after equal button
}

void CScientificCtrl::bnClickedButtonAdd() {
	if (m_strInput1 != _T("") && m_strInput2 != _T("")) {
		CScientificCtrl::bnClickedButtonEql();
	}

	m_strInputDisp = _T("+");
	m_sDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 1;
}

void CScientificCtrl::bnClickedButtonSub() {
	if (m_strInput1 != _T("") && m_strInput2 != _T("")) {
		CScientificCtrl::bnClickedButtonEql();
	}

	m_strInputDisp = _T("-");
	m_sDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 2;
}

void CScientificCtrl::bnClickedButtonMul() {
	if (m_strInput1 != _T("") && m_strInput2 != _T("")) {
		CScientificCtrl::bnClickedButtonEql();
	}

	m_strInputDisp = _T("X");
	m_sDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 3;
}

void CScientificCtrl::bnClickedButtonDiv() {
	if (m_strInput1 != _T("") && m_strInput2 != _T("")) {
		CScientificCtrl::bnClickedButtonEql();
	}

	m_strInputDisp = _T("/");
	m_sDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 4;
}

void CScientificCtrl::bnClickedButtonMod() {
	if (m_strInput1 != _T("") && m_strInput2 != _T("")) {
		CScientificCtrl::bnClickedButtonEql();
	}

	m_strInputDisp = _T("%");
	m_sDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 5;
}

void CScientificCtrl::bnClickedButtonExp() {
	if (m_strInput1 != _T("") && m_strInput2 != _T("")) {
		CScientificCtrl::bnClickedButtonEql();
	}

	m_strInputDisp = _T("^");
	m_sDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 6;
}

void CScientificCtrl::bnClickedButtonClr() {
	m_strInput1 = _T("");
	m_strInput2 = _T("");
	m_num1 = 0.0;
	m_num2 = 0.0;
	m_strInputDisp = m_strInput1;
	m_strOutputDisp = m_strInput1;
	m_opIdentifier = 1;
	m_isFirst = true;

	m_sDlg->SetInput(m_strInputDisp);
	m_sDlg->SetOutput(m_strOutputDisp);
}

void CScientificCtrl::bnClickedButtonDel() {
	if (m_isFirst) {
		m_strInput1.Delete(m_strInput1.GetLength() - 1, 1);
		m_num1 = _tstof(m_strInput1);
		m_strInputDisp = m_strInput1;
	}
	else {
		m_strInput2.Delete(m_strInput2.GetLength() - 1, 1);
		m_num2 = _tstof(m_strInput2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButtonRand() {
	if (m_isFirst) {
		m_num1 = CMathOperations::randNum();
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strInputDisp = m_strInput1;
	}
	else {
		m_num2 = CMathOperations::randNum();
		m_strInput2 = CMathOperations::DoubleToCString(m_num2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButtonPi() {
	if (m_isFirst) {
		m_num1 = CMathOperations::piNumber(1000000);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strInputDisp = m_strInput1;
	}
	else {
		m_num2 = CMathOperations::piNumber(1000000);
		m_strInput2 = CMathOperations::DoubleToCString(m_num2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButtonFac() {
	if (m_isFirst) {
		// Check if it is a negative input
		if (CMathOperations::isNegative(m_strInput1)) {
			AfxMessageBox(_T("Invalid number for factorial!"));
			CScientificCtrl::bnClickedButtonClr();
			return;
		}

		m_num1 = CMathOperations::factorial(m_num1);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strInputDisp = m_strInput1;
	}
	else {
		// Check if it is a negative input
		if (CMathOperations::isNegative(m_strInput2)) {
			AfxMessageBox(_T("Invalid number for factorial!"));
			CScientificCtrl::bnClickedButtonClr();
			return;
		}

		m_num2 = CMathOperations::factorial(m_num2);
		m_strInput2 = CMathOperations::DoubleToCString(m_num2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButtonAbs() {
	if (m_isFirst) {
		m_num1 = CMathOperations::absoluteNum(m_num1);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strInputDisp = m_strInput1;
	}
	else {
		m_num2 = CMathOperations::absoluteNum(m_num2);
		m_strInput2 = CMathOperations::DoubleToCString(m_num2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButtonInv() {
	if (m_isFirst) {
		if (CMathOperations::isNegative(m_strInput2)) {
			AfxMessageBox(_T("Invalid number for inversion!"));
			bnClickedButtonClr();
			return;
		}

		m_num1 = CMathOperations::inversion(m_num1);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strInputDisp = m_strInput1;
	}
	else {
		if (CMathOperations::isNegative(m_strInput2)) {
			AfxMessageBox(_T("Invalid number for inversion!"));
			bnClickedButtonClr();
			return;
		}

		m_num2 = CMathOperations::inversion(m_num2);
		m_strInput2 = CMathOperations::DoubleToCString(m_num2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButtonCon() {
	if (m_isFirst) {
		m_num1 = CMathOperations::signConversion(m_num1);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strInputDisp = m_strInput1;
	}
	else {
		m_num2 = CMathOperations::signConversion(m_num2);
		m_strInput2 = CMathOperations::DoubleToCString(m_num2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButton10x() {
	if (m_isFirst) {
		m_num1 = CMathOperations::exponentialBase10(m_num1);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strInputDisp = m_strInput1;
	}
	else {
		m_num2 = CMathOperations::exponentialBase10(m_num2);
		m_strInput2 = CMathOperations::DoubleToCString(m_num2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButton2x() {
	if (m_isFirst) {
		m_num1 = CMathOperations::exponentialBase2(m_num1);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strInputDisp = m_strInput1;
	}
	else {
		m_num2 = CMathOperations::exponentialBase2(m_num2);
		m_strInput2 = CMathOperations::DoubleToCString(m_num2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButtonE() {
	if (m_isFirst) {
		m_num1 = CMathOperations::exponentialEuler(m_num1);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strInputDisp = m_strInput1;
	}
	else {
		m_num2 = CMathOperations::exponentialEuler(m_num2);
		m_strInput2 = CMathOperations::DoubleToCString(m_num2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButtonSin() {
	if (m_isFirst) {
		m_num1 = CMathOperations::sinFunction(m_num1);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strInputDisp = m_strInput1;
	}
	else {
		m_num2 = CMathOperations::sinFunction(m_num2);
		m_strInput2 = CMathOperations::DoubleToCString(m_num2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButtonCos() {
	if (m_isFirst) {
		m_num1 = CMathOperations::cosFunction(m_num1);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strInputDisp = m_strInput1;
	}
	else {
		m_num2 = CMathOperations::cosFunction(m_num2);
		m_strInput2 = CMathOperations::DoubleToCString(m_num2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButtonTan() {
	if (m_isFirst) {
		m_num1 = CMathOperations::tanFunction(m_num1);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strInputDisp = m_strInput1;
	}
	else {
		m_num2 = CMathOperations::tanFunction(m_num2);
		m_strInput2 = CMathOperations::DoubleToCString(m_num2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButtonLn() {
	if (m_isFirst) {
		// Check if it is a negative input
		if (CMathOperations::isNegative(m_strInput1) || m_strInput1 == _T("") || m_strInput1 == _T("0")) {
			AfxMessageBox(_T("Invalid number for Natural Log!"));
			CScientificCtrl::bnClickedButtonClr();
			return;
		}

		m_num1 = CMathOperations::naturalLog(m_num1);
		m_strInput1 = CMathOperations::DoubleToCString(m_num1);
		m_strInputDisp = m_strInput1;
	}
	else {
		// Check if it is a negative input
		if (CMathOperations::isNegative(m_strInput2)) {
			AfxMessageBox(_T("Invalid number for Natural Log!") || m_strInput2 == _T("") || m_strInput2 == _T("0"));
			CScientificCtrl::bnClickedButtonClr();
			return;
		}

		m_num2 = CMathOperations::naturalLog(m_num2);
		m_strInput2 = CMathOperations::DoubleToCString(m_num2);
		m_strInputDisp = m_strInput2;
	}
	m_sDlg->SetInput(m_strInputDisp);
}

void CScientificCtrl::bnClickedButtonRoot() {
	m_strInputDisp = _T("ROOT");
	m_sDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 7;
}

void CScientificCtrl::bnClickedButtonLog() {
	m_strInputDisp = _T("log");
	m_sDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 8;
}

void CScientificCtrl::HandleKeyDown(UINT nChar)
{
	// For Debugging puposes
	CString message;
	message.Format(_T("Key pressed: %c (nChar = %d)\n"), nChar, nChar);
	OutputDebugString(message);

	// Event Handle for different Keys
	if (nChar == VK_RETURN) // Handle Enter key
	{
		bnClickedButtonEql();
	}
	else if (nChar == VK_BACK) // Handle Backspace key
	{
		bnClickedButtonDel();
	}
	else if (nChar == VK_OEM_PLUS || nChar == 'k') // Handle addition
	{
		bnClickedButtonAdd();
	}
	else if (nChar == VK_OEM_MINUS || nChar == 'm') // Handle subtraction
	{
		bnClickedButtonSub();
	}
	else if (nChar == 'j') // Handle multiplication on Keypad
	{
		bnClickedButtonMul();
	}
	else if (nChar == 'o') // Handle division on Keypad
	{
		bnClickedButtonDiv();
	}
	else if (nChar == 48 || nChar == 96) // Handle 0 clicked 
	{
		bnClickedButton0();
	}
	else if (nChar == 49 || nChar == 97) // Handle 1 clicked 
	{
		bnClickedButton1();
	}
	else if (nChar == 50 || nChar == 98) // Handle 2 clicked 
	{
		bnClickedButton2();
	}
	else if (nChar == 51 || nChar == 99) // Handle 3 clicked 
	{
		bnClickedButton3();
	}
	else if (nChar == 52 || nChar == 100) // Handle 4 clicked 
	{
		bnClickedButton4();
	}
	else if (nChar == 53 || nChar == 101) // Handle 5 clicked 
	{
		bnClickedButton5();
	}
	else if (nChar == 54 || nChar == 102) // Handle 6 clicked 
	{
		bnClickedButton6();
	}
	else if (nChar == 55 || nChar == 103) // Handle 7 clicked 
	{
		bnClickedButton7();
	}
	else if (nChar == 56 || nChar == 104) // Handle 8 clicked 
	{
		bnClickedButton8();
	}
	else if (nChar == 57 || nChar == 105) // Handle 9 clicked 
	{
		bnClickedButton9();
	}
	else if (nChar == 46 || nChar == VK_ESCAPE) // Handle Clear
	{
		bnClickedButtonClr();
	}
	else if (nChar == 77) // Handle Modulus
	{
		bnClickedButtonMod();
	}
	else if (nChar == 110 || nChar == 190) // Handle dot '.'
	{
		bnClickedButtonDot();
	}
}

void CScientificCtrl::numbersClicked(int number) {
	CString digit;
	digit.Format(_T("%d"), number);
	if (m_isFirst) {
		// Prevent Overflow
		if (m_strInput1.GetLength() > 15) {
			return;
		}

		// When there is an output then make the str1 empty
		if (m_strOutputDisp != _T("")) {
			m_strInput1 = _T("");
			m_num1 = 0.0;
			m_strOutputDisp = _T("");
		}

		// Update the input display for first input
		m_strInput1 += digit;
		m_num1 = _tstof(m_strInput1);
		m_strInputDisp = m_strInput1;
	}
	else {
		// Prevent overflow
		if (m_strInput2.GetLength() > 15) {
			return;
		}

		// Update the input display for second input
		m_strInput2 += digit;
		m_num2 = _tstof(m_strInput2);
		m_strInputDisp = m_strInput2;
	}
	// Set the data
	m_sDlg->SetInput(m_strInputDisp);
	m_sDlg->SetOutput(m_strOutputDisp);
}