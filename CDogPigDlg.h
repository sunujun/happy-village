#pragma once
#include "CResultDlg.h"
#include <fstream>
#include <string>
#include <iostream>

// CDogPigDlg 대화 상자

class CDogPigDlg : public CDialog
{
	DECLARE_DYNAMIC(CDogPigDlg)

public:
	CDogPigDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDogPigDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOGPIGDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CResultDlg* m_dlg;
	afx_msg void OnBnClickedOpenbtn();
	afx_msg void OnMove(int x, int y);
	CStatic m_packPic;
	CStatic m_packNum;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_card[26][2];
	int packCnt;
	CString m_cardName[26];
	std::string name;
	std::string stage;



	virtual void OnCancel();
};
