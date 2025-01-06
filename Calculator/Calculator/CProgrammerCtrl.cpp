#include "pch.h"
#include "CProgrammerCtrl.h"
#include "CMathOperations.h"
#include "CNumberConverter.h"

CProgrammerCtrl::CProgrammerCtrl(CProgrammerCalcDlg* pDlg) {
	// Initialization

	// Strings for inputs
	m_strInput1 = _T("");
	m_strInput2 = _T("");

	// Input numbers stored as double values
	m_num1 = 0;
	m_num2 = 0;

	// Strings that will be used for display
	m_strInputDisp = _T("");
	m_strOutputDisp = _T("");

	// Identifier / Display for the number systems
	m_strCurrentNumSys = _T("Decimal");

	// Identifier that decides if currernt input is for the first value or the second
	m_isFirst = true;

	// Identifier that decides which operation that will terminate when equal sign is clicekd
	m_opIdentifier = 1;
	
	// The instance of the dialog class
	m_pDlg = pDlg;
}

void CProgrammerCtrl::bnClickedButton0() {
	this->numbersClicked(_T("0"));
}

void CProgrammerCtrl::bnClickedButton1() {
	this->numbersClicked(_T("1"));
}

void CProgrammerCtrl::bnClickedButton2() {
	// Ignore clicks of non related number system
	if (m_strCurrentNumSys == _T("Binary")) {
		return;
	}

	this->numbersClicked(_T("2"));
}

void CProgrammerCtrl::bnClickedButton3() {
	// Ignore clicks of non related number system
	if (m_strCurrentNumSys == _T("Binary")) {
		return;
	}

	this->numbersClicked(_T("3"));
}

void CProgrammerCtrl::bnClickedButton4() {
	// Ignore clicks of non related number system
	if (m_strCurrentNumSys == _T("Binary")) {
		return;
	}

	this->numbersClicked(_T("4"));
}

void CProgrammerCtrl::bnClickedButton5() {
	// Ignore clicks of non related number system
	if (m_strCurrentNumSys == _T("Binary")) {
		return;
	}

	this->numbersClicked(_T("5"));
}

void CProgrammerCtrl::bnClickedButton6() {
	// Ignore clicks of non related number system
	if (m_strCurrentNumSys == _T("Binary")) {
		return;
	}

	this->numbersClicked(_T("6"));
}

void CProgrammerCtrl::bnClickedButton7() {
	// Ignore clicks of non related number system
	if (m_strCurrentNumSys == _T("Binary")) {
		return;
	}

	this->numbersClicked(_T("7"));
}

void CProgrammerCtrl::bnClickedButton8() {
	// Ignore clicks of non related number system
	if ((m_strCurrentNumSys == _T("Octal") || m_strCurrentNumSys == _T("Binary"))) {
		return;
	}

	this->numbersClicked(_T("8"));
}

void CProgrammerCtrl::bnClickedButton9() {
	// Ignore clicks of non related number system
	if ((m_strCurrentNumSys == _T("Octal") || m_strCurrentNumSys == _T("Binary"))) {
		return;
	}

	this->numbersClicked(_T("9"));
}

void CProgrammerCtrl::bnClickedButtonA() {
	// Ignore clicks of non related number system
	if ((m_strCurrentNumSys == _T("Octal") || m_strCurrentNumSys == _T("Binary") || m_strCurrentNumSys == _T("Decimal"))) {
		return;
	}

	this->numbersClicked(_T("A"));
}

void CProgrammerCtrl::bnClickedButtonB() {
	// Ignore clicks of non related number system
	if ((m_strCurrentNumSys == _T("Octal") || m_strCurrentNumSys == _T("Binary") || m_strCurrentNumSys == _T("Decimal"))) {
		return;
	}

	this->numbersClicked(_T("B"));
}

void CProgrammerCtrl::bnClickedButtonC() {
	// Ignore clicks of non related number system
	if ((m_strCurrentNumSys == _T("Octal") || m_strCurrentNumSys == _T("Binary") || m_strCurrentNumSys == _T("Decimal"))) {
		return;
	}

	this->numbersClicked(_T("C"));
}

void CProgrammerCtrl::bnClickedButtonD() {
	// Ignore clicks of non related number system
	if ((m_strCurrentNumSys == _T("Octal") || m_strCurrentNumSys == _T("Binary") || m_strCurrentNumSys == _T("Decimal"))) {
		return;
	}

	this->numbersClicked(_T("D"));
}

void CProgrammerCtrl::bnClickedButtonE() {
	// Ignore clicks of non related number system
	if ((m_strCurrentNumSys == _T("Octal") || m_strCurrentNumSys == _T("Binary") || m_strCurrentNumSys == _T("Decimal"))) {
		return;
	}

	this->numbersClicked(_T("E"));
}

void CProgrammerCtrl::bnClickedButtonF() {
	// Ignore clicks of non related number system
	if ((m_strCurrentNumSys == _T("Octal") || m_strCurrentNumSys == _T("Binary") || m_strCurrentNumSys == _T("Decimal"))) {
		return;
	}

	this->numbersClicked(_T("F"));
}

void CProgrammerCtrl::bnClickedButtonHex() {
	// If it's already hexadecimal then just return for better time complexity and memory use
	if (m_strCurrentNumSys == _T("Hexadecimal")) {
		return;
	}

	this->numberSystemConvert(_T("Hexadecimal"));
}

void CProgrammerCtrl::bnClickedButtonDec() {
	// If it's already Decimal then just return for better time complexity and memory use
	if (m_strCurrentNumSys == _T("Decimal")) {
		return;
	}

	this->numberSystemConvert(_T("Decimal"));
}

void CProgrammerCtrl::bnClickedButtonOct() {
	// If it's already Octal then just return for better time complexity and memory use
	if (m_strCurrentNumSys == _T("Octal")) {
		return;
	}

	this->numberSystemConvert(_T("Octal"));
}

void CProgrammerCtrl::bnClickedButtonBin() {
	// If it's already Binary then just return for better time complexity and memory use
	if (m_strCurrentNumSys == _T("Binary")) {
		return;
	}

	this->numberSystemConvert(_T("Binary"));
}

void CProgrammerCtrl::bnClickedButtonEqual() {
	switch (m_opIdentifier) {
	case 1: // Addition
		// Depends on what number systems
		if (m_strCurrentNumSys == _T("Decimal")) {
			m_num1 = CMathOperations::addition(m_num1, m_num2);
			m_strOutputDisp.Format(_T("%d"), m_num1);
		}
		else if (m_strCurrentNumSys == _T("Binary")) {
			m_num1 = CMathOperations::addition(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToBin(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Hexadecimal")) {
			m_num1 = CMathOperations::addition(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Octal")) {
			m_num1 = CMathOperations::addition(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}

		// Update
		m_strInputDisp = _T("");
		m_pDlg->SetInput(m_strInputDisp);
		m_strInput1 = m_strOutputDisp;
		m_strInput2 = _T("");
		m_num2 = 0;
		m_pDlg->SetOutput(m_strOutputDisp);
		break;
	case 2: // Submation
		// Depends on what number systems
		if (m_strCurrentNumSys == _T("Decimal")) {
			m_num1 = CMathOperations::submation(m_num1, m_num2);
			m_strOutputDisp.Format(_T("%d"), m_num1);
		}
		else if (m_strCurrentNumSys == _T("Binary")) {
			m_num1 = CMathOperations::submation(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToBin(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Hexadecimal")) {
			m_num1 = CMathOperations::submation(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Octal")) {
			m_num1 = CMathOperations::submation(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}

		// Update
		m_strInputDisp = _T("");
		m_pDlg->SetInput(m_strInputDisp);
		m_strInput1 = m_strOutputDisp;
		m_strInput2 = _T("");
		m_num2 = 0;
		m_pDlg->SetOutput(m_strOutputDisp);
		break;
	case 3: // Multiplication
		// Depends on what number systems
		if (m_strCurrentNumSys == _T("Decimal")) {
			m_num1 = CMathOperations::multiplication(m_num1, m_num2);
			m_strOutputDisp.Format(_T("%d"), m_num1);
		}
		else if (m_strCurrentNumSys == _T("Binary")) {
			m_num1 = CMathOperations::multiplication(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToBin(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Hexadecimal")) {
			m_num1 = CMathOperations::multiplication(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Octal")) {
			m_num1 = CMathOperations::multiplication(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}

		// Update
		m_strInputDisp = _T("");
		m_pDlg->SetInput(m_strInputDisp);
		m_strInput1 = m_strOutputDisp;
		m_strInput2 = _T("");
		m_num2 = 0;
		m_pDlg->SetOutput(m_strOutputDisp);
		break;
	case 4: // Division
		// Handle the division by 0
		if (m_strInput2 == _T("0") || m_strInput2 == _T("") || m_strInput2 == _T("00") || m_num2 == 0) {
			// Update
			m_strInputDisp = _T("");
			m_pDlg->SetInput(m_strInputDisp);
			m_strInput1 = m_strInputDisp;
			m_strInput2 = _T("");
			m_num1 = 0;
			m_num2 = 0;
			m_strOutputDisp = ("Can't divide by 0!");
			m_pDlg->SetOutput(m_strOutputDisp);
			break;
		}

		// Depends on what number systems
		if (m_strCurrentNumSys == _T("Decimal")) {
			m_num1 = CMathOperations::division(m_num1, m_num2);
			m_strOutputDisp.Format(_T("%d"), m_num1);
		}
		else if (m_strCurrentNumSys == _T("Binary")) {
			m_num1 = CMathOperations::division(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToBin(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Hexadecimal")) {
			m_num1 = CMathOperations::division(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Octal")) {
			m_num1 = CMathOperations::division(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}

		// Update
		m_strInputDisp = _T("");
		m_pDlg->SetInput(m_strInputDisp);
		m_strInput1 = m_strOutputDisp;
		m_strInput2 = _T("");
		m_num2 = 0;
		m_pDlg->SetOutput(m_strOutputDisp);
		break;
	case 5: // Modulus
		// Handle the modulo by 0
		if (m_strInput2 == _T("0") || m_strInput2 == _T("") || m_strInput2 == _T("00") || m_num2 == 0) {
			// Update
			m_strInputDisp = _T("");
			m_pDlg->SetInput(m_strInputDisp);
			m_strInput1 = m_strInputDisp;
			m_strInput2 = _T("");
			m_num1 = 0;
			m_num2 = 0;
			m_strOutputDisp = ("Modulo by 0 is Invalid");
			m_pDlg->SetOutput(m_strOutputDisp);
			break;
		}

		// Depends on what number systems
		if (m_strCurrentNumSys == _T("Decimal")) {
			m_num1 = CMathOperations::modulus(m_num1, m_num2);
			m_strOutputDisp.Format(_T("%d"), m_num1);
		}
		else if (m_strCurrentNumSys == _T("Binary")) {
			m_num1 = CMathOperations::modulus(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToBin(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Hexadecimal")) {
			m_num1 = CMathOperations::modulus(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Octal")) {
			m_num1 = CMathOperations::modulus(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}

		// Update
		m_strInputDisp = _T("");
		m_pDlg->SetInput(m_strInputDisp);
		m_strInput1 = m_strOutputDisp;
		m_strInput2 = _T("");
		m_num2 = 0;
		m_pDlg->SetOutput(m_strOutputDisp);
		break;
	case 6: // Left Shift
		// Depends on what number systems
		if (m_strCurrentNumSys == _T("Decimal")) {
			m_num1 = CMathOperations::leftShift(m_num1, m_num2);
			m_strOutputDisp.Format(_T("%d"), m_num1);
		}
		else if (m_strCurrentNumSys == _T("Binary")) {
			m_num1 = CMathOperations::leftShift(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToBin(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Hexadecimal")) {
			m_num1 = CMathOperations::leftShift(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Octal")) {
			m_num1 = CMathOperations::leftShift(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}

		// Update
		m_strInputDisp = _T("");
		m_pDlg->SetInput(m_strInputDisp);
		m_strInput1 = m_strOutputDisp;
		m_strInput2 = _T("");
		m_num2 = 0;
		m_pDlg->SetOutput(m_strOutputDisp);
		break;
	case 7: // Right Shift
		// Depends on what number systems
		if (m_strCurrentNumSys == _T("Decimal")) {
			m_num1 = CMathOperations::rightShift(m_num1, m_num2);
			m_strOutputDisp.Format(_T("%d"), m_num1);
		}
		else if (m_strCurrentNumSys == _T("Binary")) {
			m_num1 = CMathOperations::rightShift(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToBin(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Hexadecimal")) {
			m_num1 = CMathOperations::rightShift(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}
		else if (m_strCurrentNumSys == _T("Octal")) {
			m_num1 = CMathOperations::rightShift(m_num1, m_num2);
			m_strOutputDisp = CNumberConverter::decToHex(m_num1);
		}

		// Update
		m_strInputDisp = _T("");
		m_pDlg->SetInput(m_strInputDisp);
		m_strInput1 = m_strOutputDisp;
		m_strInput2 = _T("");
		m_num2 = 0;
		m_pDlg->SetOutput(m_strOutputDisp);
		break;
	}
	m_isFirst = true; // Bringing back to the first input after equal button
}

void CProgrammerCtrl::bnClickedButtonAdd() {
	if (m_strInput1 != _T("") && m_strInput2 != _T("")) {
		CProgrammerCtrl::bnClickedButtonEqual();
	}

	m_strInputDisp = _T("+");
	m_pDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 1;
}

void CProgrammerCtrl::bnClickedButtonSub() {
	if (m_strInput1 != _T("") && m_strInput2 != _T("")) {
		CProgrammerCtrl::bnClickedButtonEqual();
	}

	m_strInputDisp = _T("-");
	m_pDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 2;
}

void CProgrammerCtrl::bnClickedButtonMul() {
	if (m_strInput1 != _T("") && m_strInput2 != _T("")) {
		CProgrammerCtrl::bnClickedButtonEqual();
	}

	m_strInputDisp = _T("X");
	m_pDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 3;
}

void CProgrammerCtrl::bnClickedButtonDiv() {
	if (m_strInput1 != _T("") && m_strInput2 != _T("")) {
		CProgrammerCtrl::bnClickedButtonEqual();
	}

	m_strInputDisp = _T("/");
	m_pDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 4;
}

void CProgrammerCtrl::bnClickedButtonMod() {
	if (m_strInput1 != _T("") && m_strInput2 != _T("")) {
		CProgrammerCtrl::bnClickedButtonEqual();
	}

	m_strInputDisp = _T("%");
	m_pDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 5;
}

void CProgrammerCtrl::bnClickedButtonLsh() {
	if (m_strInput1 != _T("") && m_strInput2 != _T("")) {
		CProgrammerCtrl::bnClickedButtonEqual();
	}

	m_strInputDisp = _T("<<");
	m_pDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 6;
}

void CProgrammerCtrl::bnClickedButtonRsh() {
	if (m_strInput1 != _T("") && m_strInput2 != _T("")) {
		CProgrammerCtrl::bnClickedButtonEqual();
	}

	m_strInputDisp = _T(">>");
	m_pDlg->SetInput(m_strInputDisp);

	m_isFirst = false;
	m_opIdentifier = 7;
}

void CProgrammerCtrl::bnClickedButtonClr() {
	m_strInput1 = _T("");
	m_strInput2 = _T("");
	m_strInputDisp = m_strInput1;
	m_strOutputDisp = m_strInput1;
	m_num1 = 0;
	m_num2 = 0;
	m_opIdentifier = 1;
	m_isFirst = true;

	m_pDlg->SetInput(m_strInputDisp);
	m_pDlg->SetOutput(m_strOutputDisp);
}

void CProgrammerCtrl::bnClickedButtonDel() {
	if (m_isFirst) {
		// Ignore if there is nothing
		if (m_num1 == 0 || m_strInput1 == _T("")) {
			return;
		}

		TCHAR lastChar = m_strInput1.GetAt(m_strInput1.GetLength() - 1);
		
		if (lastChar == _T('A')) {
			m_num1 -= 10;
		}
		else if (lastChar == _T('B')) {
			m_num1 -= 11;
		}
		else if (lastChar == _T('C')) {
			m_num1 -= 12;
		}
		else if (lastChar == _T('D')) {
			m_num1 -= 13;
		}
		else if (lastChar == _T('E')) {
			m_num1 -= 14;
		}
		else if (lastChar == _T('F')) {
			m_num1 -= 15;
		}
		else {
			CString strLastChar(lastChar); // Convert TCHAR to CString
			int lastDigit = _ttoi(strLastChar);
			m_num1 -= lastDigit;
		}

		m_strInput1.Delete(m_strInput1.GetLength() - 1, 1);
		m_strInputDisp = m_strInput1;

		if (m_strCurrentNumSys == _T("Decimal")) {
			m_num1 /= 10;
		}
		else if (m_strCurrentNumSys == _T("Binary")) {
			m_num1 /= 2;
		}
		else if (m_strCurrentNumSys == _T("Hexadecimal")) {
			m_num1 /= 16;
		}
		else if (m_strCurrentNumSys == _T("Octal")) {
			m_num1 /= 8;
		}
	}
	else {
		// Ignore if there is nothing
		if (m_num2 == 0 || m_strInput2 == _T("")) {
			return;
		}

		TCHAR lastChar = m_strInput2.GetAt(m_strInput2.GetLength() - 1);

		if (lastChar == _T('A')) {
			m_num2 -= 10;
		}
		else if (lastChar == _T('B')) {
			m_num2 -= 11;
		}
		else if (lastChar == _T('C')) {
			m_num2 -= 12;
		}
		else if (lastChar == _T('D')) {
			m_num2 -= 13;
		}
		else if (lastChar == _T('E')) {
			m_num2 -= 14;
		}
		else if (lastChar == _T('F')) {
			m_num2 -= 15;
		}
		else {
			CString strLastChar(lastChar); // Convert TCHAR to CString
			int lastDigit = _ttoi(strLastChar);
			m_num2 -= lastDigit;
		}

		m_strInput2.Delete(m_strInput2.GetLength() - 1, 1);
		m_strInputDisp = m_strInput2;

		if (m_strCurrentNumSys == _T("Decimal")) {
			m_num2 /= 10;
		}
		else if (m_strCurrentNumSys == _T("Binary")) {
			m_num2 /= 2;
		}
		else if (m_strCurrentNumSys == _T("Hexadecimal")) {
			m_num2 /= 16;
		}
		else if (m_strCurrentNumSys == _T("Octal")) {
			m_num2 /= 8;
		}
	}
	m_pDlg->SetInput(m_strInputDisp);
}

void CProgrammerCtrl::HandleKeyDown(UINT nChar)
{
	// For Debugging puposes
	CString message;
	message.Format(_T("Key pressed: %c (nChar = %d)\n"), nChar, nChar);
	OutputDebugString(message);

	// Event Handle for different Keys
	if (nChar == VK_RETURN) // Handle Enter key
	{
		bnClickedButtonEqual();
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
	else if (nChar == 65) // Handle A clicked 
	{
		bnClickedButtonA();
	}
	else if (nChar == 66) // Handle B clicked 
	{
		bnClickedButtonB();
	}
	else if (nChar == 67) // Handle C clicked 
	{
		bnClickedButtonC();
	}
	else if (nChar == 68) // Handle D clicked 
	{
		bnClickedButtonD();
	}
	else if (nChar == 69) // Handle E clicked 
	{
		bnClickedButtonE();
	}
	else if (nChar == 70) // Handle F clicked 
	{
		bnClickedButtonF();
	}
	else if (nChar == 46 || nChar == VK_ESCAPE) // Handle Clear
	{
		bnClickedButtonClr();
	}
	else if (nChar == 77) // Handle Modulus
	{
		bnClickedButtonMod();
	}
}

void CProgrammerCtrl::numbersClicked(CString digit) {
	int temp = 0;

	// Finding the correct integer value for the new digit
	if (digit == _T("A")) {
		temp = 10;
	}
	else if (digit == _T("B")) {
		temp = 11;
	}
	else if (digit == _T("C")) {
		temp = 12;
	}
	else if (digit == _T("D")) {
		temp = 13;
	}
	else if (digit == _T("E")) {
		temp = 14;
	}
	else if (digit == _T("F")) {
		temp = 15;
	}
	else {
		temp = _ttoi(digit);
	}

	// Appending the new input
	if (m_isFirst) {
		// Prevent overflow
		if (m_num1 > 99999999) {
			return;
		}

		// When there is an output then make the str1 empty
		if (m_strOutputDisp != _T("")) {
			m_strInput1 = _T("");
			m_num1 = 0;
			m_strOutputDisp = _T("");
		}

		// Update the input display for first input
		m_strInput1 += digit;
		if (m_strCurrentNumSys == _T("Decimal")) {
			m_num1 *= 10;
		}
		else if (m_strCurrentNumSys == _T("Binary")) {
			m_num1 *= 2;
		}
		else if (m_strCurrentNumSys == _T("Hexadecimal")) {
			m_num1 *= 16;
		}
		else if (m_strCurrentNumSys == _T("Octal")) {
			m_num1 *= 8;
		}
		m_num1 += temp;
		m_strInputDisp = m_strInput1;
	}
	else {
		// Prevent overflow
		if (m_num2 > 99999999) {
			return;
		}

		// Update the input display for second input
		m_strInput2 += digit;
		if (m_strCurrentNumSys == _T("Decimal")) {
			m_num2 *= 10;
		}
		else if (m_strCurrentNumSys == _T("Binary")) {
			m_num2 *= 2;
		}
		else if (m_strCurrentNumSys == _T("Hexadecimal")) {
			m_num2 *= 16;
		}
		else if (m_strCurrentNumSys == _T("Octal")) {
			m_num2 *= 8;
		}
		m_num2 += temp;
		m_strInputDisp = m_strInput2;
	}
	// Set the data
	m_pDlg->SetInput(m_strInputDisp);
	m_pDlg->SetOutput(m_strOutputDisp);
}

void CProgrammerCtrl::numberSystemConvert(CString numberSystem) {
	if (numberSystem == _T("Decimal")) {
		// When the output is not empty then use the output instead
		if (m_strOutputDisp != _T("")) {
			m_strInput1.Format(_T("%d"), m_num1);

			// Update the Number Systems display
			m_strInputDisp = m_strInput1;
			m_strCurrentNumSys = numberSystem;
			m_strOutputDisp = _T("");
			m_pDlg->SetInput(m_strInputDisp);
			m_pDlg->SetOutput(m_strOutputDisp);
			m_pDlg->SetNumSys(m_strCurrentNumSys);
			return;
		}

		m_strInput1.Format(_T("%d"), m_num1);
		m_strInput2.Format(_T("%d"), m_num2);
	}
	else if (numberSystem == _T("Hexadecimal")) {
		// When the output is not empty then use the output instead
		if (m_strOutputDisp != _T("")) {
			m_strInput1 = CNumberConverter::decToHex(m_num1);

			// Update the Number Systems display
			m_strInputDisp = m_strInput1;
			m_strCurrentNumSys =numberSystem;
			m_strOutputDisp = _T("");
			m_pDlg->SetInput(m_strInputDisp);
			m_pDlg->SetOutput(m_strOutputDisp);
			m_pDlg->SetNumSys(m_strCurrentNumSys);
			return;
		}

		m_strInput1 = CNumberConverter::decToHex(m_num1);
		m_strInput2 = CNumberConverter::decToHex(m_num2);
	}
	else if (numberSystem == _T("Octal")) {
		// When the output is not empty then use the output instead
		if (m_strOutputDisp != _T("")) {
			m_strInput1 = CNumberConverter::decToOct(m_num1);

			// Update the Number Systems display
			m_strInputDisp = m_strInput1;
			m_strCurrentNumSys = numberSystem;
			m_strOutputDisp = _T("");
			m_pDlg->SetInput(m_strInputDisp);
			m_pDlg->SetOutput(m_strOutputDisp);
			m_pDlg->SetNumSys(m_strCurrentNumSys);
			return;
		}

		m_strInput1 = CNumberConverter::decToOct(m_num1);
		m_strInput2 = CNumberConverter::decToOct(m_num2);
	}
	else if (numberSystem == _T("Binary")) {
		// When the output is not empty then use the output instead
		if (m_strOutputDisp != _T("")) {
			m_strInput1 = CNumberConverter::decToBin(m_num1);

			// Update the Number Systems display
			m_strInputDisp = m_strInput1;
			m_strCurrentNumSys = numberSystem;
			m_strOutputDisp = _T("");
			m_pDlg->SetInput(m_strInputDisp);
			m_pDlg->SetOutput(m_strOutputDisp);
			m_pDlg->SetNumSys(m_strCurrentNumSys);
			return;
		}

		m_strInput1 = CNumberConverter::decToBin(m_num1);
		m_strInput2 = CNumberConverter::decToBin(m_num2);
	}

	if (m_isFirst) {
		if (m_num1 == 0) {
			m_strInput1 = _T("");
		}
		m_strInputDisp = m_strInput1;
	}
	else {
		m_strInputDisp = m_strInput2;
	}

	// Update the Number Systems display
	m_strCurrentNumSys = numberSystem;
	m_pDlg->SetNumSys(m_strCurrentNumSys);
	m_strOutputDisp = _T("");
	m_pDlg->SetInput(m_strInputDisp);
	m_pDlg->SetOutput(m_strOutputDisp);
}

