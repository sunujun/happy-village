
// mainDlg.h: 헤더 파일
//

#pragma once
#include "CNameDlg.h"

// CmainDlg 대화 상자
class CmainDlg : public CDialogEx
{
// 생성입니다.
public:
	CmainDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_mainPic;
	CString m_name;
	CString m_stage;
	virtual void OnCancel();
	afx_msg void OnBnClickedStartbtn();
	afx_msg void OnBnClickedMakebtn();
	afx_msg void OnBnClickedGetbtn();
	CStatic m_welcome;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
