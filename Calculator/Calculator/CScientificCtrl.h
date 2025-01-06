#pragma once

class CScientificCalcDlg;

class CScientificCtrl
{
private:
	CScientificCalcDlg* m_sDlg; // Pointer to the dialog
	CString m_strInput1, m_strInput2;
	double m_num1, m_num2;
	CString m_strInputDisp, m_strOutputDisp;
	bool m_isFirst;
	int m_opIdentifier;
	// Operations Identifier
	/*
	* 1 : Addition
	* 2 : Subtraction
	* 3 : Multiplication
	* 4 : Division
	* 5 : Modulus
	* 6 : Exponential
	* 7 : Root
	* 8 : Log
	*/

	// This will be used to any numbers being clicked
	// as there was a code clone for every numbers clicked
	void numbersClicked(int number);

public:
	// Constructor
	CScientificCtrl(CScientificCalcDlg* sDlg);

	// Numbers clicked
	void bnClickedButton0();
	void bnClickedButton1();
	void bnClickedButton2();
	void bnClickedButton3();
	void bnClickedButton4();
	void bnClickedButton5();
	void bnClickedButton6();
	void bnClickedButton7();
	void bnClickedButton8();
	void bnClickedButton9();
	void bnClickedButtonDot();

	// Equal Sign Clicked
	void bnClickedButtonEql();

	// Operations Clicked
	void bnClickedButtonAdd();
	void bnClickedButtonSub();
	void bnClickedButtonMul();
	void bnClickedButtonDiv();
	void bnClickedButtonMod();
	void bnClickedButtonExp();
	void bnClickedButtonRoot();
	void bnClickedButtonLog();

	// Clear and delete
	void bnClickedButtonClr();
	void bnClickedButtonDel();

	// Constants
	void bnClickedButtonRand();
	void bnClickedButtonPi();

	// Instant change functions
	void bnClickedButtonFac();
	void bnClickedButtonAbs();
	void bnClickedButtonInv();
	void bnClickedButtonCon();
	void bnClickedButton10x();
	void bnClickedButton2x();
	void bnClickedButtonE();
	void bnClickedButtonLn();

	// Trigonometry
	void bnClickedButtonSin();
	void bnClickedButtonCos();
	void bnClickedButtonTan();

	// KeyDown handler
	void HandleKeyDown(UINT nChar);
};