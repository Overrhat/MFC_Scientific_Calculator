#pragma once
#include "CProgrammerCalcDlg.h"

class CProgrammerCalcDlg;

class CProgrammerCtrl
{
private:
	CProgrammerCalcDlg* m_pDlg; // Pointer to the dialog
	CString m_strInput1, m_strInput2;
	int m_num1, m_num2;
	CString m_strInputDisp, m_strOutputDisp;
	CString m_strCurrentNumSys;
	bool m_isFirst;
	int m_opIdentifier;
	// Operations Identifier
	/*
	* 1 : Addition
	* 2 : Subtraction
	* 3 : Multiplication
	* 4 : Division
	* 5 : Modulus
	* 6 : Left Shift
	* 7: Right Shift
	*/

	// Preventing code clone
	void numbersClicked(CString digit);
	void numberSystemConvert(CString numberSystem);

public:
	// Constructor
	CProgrammerCtrl(CProgrammerCalcDlg* pDlg);

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

	// Letters Clicked
	void bnClickedButtonA();
	void bnClickedButtonB();
	void bnClickedButtonC();
	void bnClickedButtonD();
	void bnClickedButtonE();
	void bnClickedButtonF();

	// Number systems clicked
	void bnClickedButtonHex();
	void bnClickedButtonDec();
	void bnClickedButtonOct();
	void bnClickedButtonBin();

	// Equal Sign Clicked
	void bnClickedButtonEqual();

	// Operations Clicked
	void bnClickedButtonAdd();
	void bnClickedButtonSub();
	void bnClickedButtonMul();
	void bnClickedButtonDiv();
	void bnClickedButtonMod();
	void bnClickedButtonLsh();
	void bnClickedButtonRsh();

	// Clear and Delete
	void bnClickedButtonClr();
	void bnClickedButtonDel();

	// KeyDown handler
	void HandleKeyDown(UINT nChar);
};
