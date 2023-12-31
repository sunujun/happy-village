#pragma once
#include "CDeckDlg.h"
#include <fstream>
#include <string>
#include <iostream>
// CCardDlg 대화 상자

class CCardDlg : public CDialog
{
	DECLARE_DYNAMIC(CCardDlg)

public:
	CCardDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCardDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CARDDlG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedMakebtn();
	CDeckDlg* m_dlg;
	afx_msg void OnMove(int x, int y);
	int m_left;
	int m_right;
	afx_msg void OnBnClickedLeftbtn();
	afx_msg void OnBnClickedRightbtn();
	CButton m_leftBtn;
	CButton m_rightBtn;
	CBitmapButton m_card1;
	CBitmapButton m_card2;
	CBitmapButton m_card3;
	CBitmapButton m_card4;
	CBitmapButton m_card5;
	CBitmapButton m_card6;
	CBitmapButton m_card7;
	CBitmapButton m_card8;
	CString m_str1;
	CString m_str2;
	CString m_str3;
	CString m_str4;
	CString m_str5;
	CString m_str6;
	CString m_str7;
	CString m_str8;
	CStatic m_cardCnt[26];
	bool m_inFlag[26];
	bool m_cntFlag[26];
	int m_card[26][2];

	afx_msg void OnBnClickedCard1();
	afx_msg void OnBnClickedCard2();
	afx_msg void OnBnClickedCard3();
	afx_msg void OnBnClickedCard4();
	afx_msg void OnBnClickedCard5();
	afx_msg void OnBnClickedCard6();
	afx_msg void OnBnClickedCard7();
	afx_msg void OnBnClickedCard8();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
