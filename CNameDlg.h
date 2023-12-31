#pragma once
#include "CMyEdit.h"

// CNameDlg 대화 상자

class CNameDlg : public CDialog
{
	DECLARE_DYNAMIC(CNameDlg)

public:
	CNameDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CNameDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NAMEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CMyEdit m_nameEdit;
	CString m_name;
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
