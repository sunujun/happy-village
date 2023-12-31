#pragma once
#include<fstream>
#include<string>
#include<iostream>
#include "PlayGame.h"

// CStageDlg 대화 상자

class CStageDlg : public CDialog
{
	DECLARE_DYNAMIC(CStageDlg)

public:
	CStageDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CStageDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STAGEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CStatic m_stagePic;
	std::string m_string;
	afx_msg void OnBnClickedStage11();
	afx_msg void OnBnClickedStage12();
	afx_msg void OnBnClickedStage13();
	afx_msg void OnBnClickedStage14();
	afx_msg void OnBnClickedStage15();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_stage;
	int m_playStage;
	virtual void OnCancel();
};
