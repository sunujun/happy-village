#pragma once


// CResultDlg 대화 상자

class CResultDlg : public CDialog
{
	DECLARE_DYNAMIC(CResultDlg)

public:
	CResultDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CResultDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPENDLG };
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
	CBitmapButton m_getCard[5];
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
