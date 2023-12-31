// CStageDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "main.h"
#include "CStageDlg.h"
#include "afxdialogex.h"
#include "mainDlg.h"


// CStageDlg 대화 상자

IMPLEMENT_DYNAMIC(CStageDlg, CDialog)

CStageDlg::CStageDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_STAGEDLG, pParent)
{

}

CStageDlg::~CStageDlg()
{
}

void CStageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STAGEPIC, m_stagePic);

}


BEGIN_MESSAGE_MAP(CStageDlg, CDialog)
	ON_BN_CLICKED(IDC_STAGE11, &CStageDlg::OnBnClickedStage11)
	ON_BN_CLICKED(IDC_STAGE12, &CStageDlg::OnBnClickedStage12)
	ON_BN_CLICKED(IDC_STAGE13, &CStageDlg::OnBnClickedStage13)
	ON_BN_CLICKED(IDC_STAGE14, &CStageDlg::OnBnClickedStage14)
	ON_BN_CLICKED(IDC_STAGE15, &CStageDlg::OnBnClickedStage15)
END_MESSAGE_MAP()


// CStageDlg 메시지 처리기


BOOL CStageDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CmainDlg* parent =
		(CmainDlg*)GetParent();
	parent->ShowWindow(SW_HIDE);

	m_stagePic.SetEnhMetaFile(GetEnhMetaFile(_T("stage.emf")));


	int stage = _ttoi(parent->m_stage);
	m_stage = stage;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CStageDlg::OnBnClickedStage11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//게임에 11이라고 int값으로 전송
	//그 후, 게임 실행
	
	TRACE(_T("%d", m_stage));

	if (11 <= m_stage) {
		m_playStage = 11;
		PlayGame pg11;
		pg11.DoModal();
	}
}


void CStageDlg::OnBnClickedStage12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (12 <= m_stage) {
		m_playStage = 12;

		PlayGame pg11;
		pg11.DoModal();
	}
}


void CStageDlg::OnBnClickedStage13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	if (13 <= m_stage) {
		m_playStage = 13;

		PlayGame pg11;
		pg11.DoModal();
	}
}


void CStageDlg::OnBnClickedStage14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	if (14 <= m_stage) {
		m_playStage = 14;

		PlayGame pg11;
		pg11.DoModal();
	}
}


void CStageDlg::OnBnClickedStage15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	if (15 <= m_stage) {
		m_playStage = 15;

		PlayGame pg11;
		pg11.DoModal();
	}
}


BOOL CStageDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_ESCAPE) return TRUE;

	return CDialog::PreTranslateMessage(pMsg);
}


void CStageDlg::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CmainDlg* parent =
		(CmainDlg*)GetParent();
	std::string ss;
	std::ifstream inputfile3("userinfo.txt");
	if (inputfile3.is_open()) {
		int i = 0;

		while (!inputfile3.eof()) {
			if (i == 0) {
				inputfile3 >> ss;
				parent->m_name = ss.c_str();
			}
			if (i == 1) {
				inputfile3 >> ss;
				parent->m_stage = ss.c_str();
				break;
			}
			i++;
		}
	}
	inputfile3.close();
	CDialog::OnCancel();
}
