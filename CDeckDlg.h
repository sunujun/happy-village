#pragma once
#include <string>

// CDeckDlg 대화 상자

class CDeckDlg : public CDialog
{
	DECLARE_DYNAMIC(CDeckDlg)

public:
	CDeckDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDeckDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAKEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
	virtual void PostNcDestroy();
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	CButton m_deck[10];

	/*CString m_str1;
	CString m_str2;
	CString m_str3;
	CString m_str4;
	CString m_str5;
	CString m_str6;
	CString m_str7;
	CString m_str8;*/
	CString m_cardName[26];
	std::string m_cardCode[26];
	int deck[10];
	afx_msg void OnBnClickedDeck1();
	afx_msg void OnBnClickedDeck2();
	afx_msg void OnBnClickedDeck3();
	afx_msg void OnBnClickedDeck4();
	afx_msg void OnBnClickedDeck5();
	afx_msg void OnBnClickedDeck6();
	afx_msg void OnBnClickedDeck7();
	afx_msg void OnBnClickedDeck8();
	afx_msg void OnBnClickedDeck9();
	afx_msg void OnBnClickedDeck10();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
