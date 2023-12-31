// CDogPigDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "main.h"
#include "CDogPigDlg.h"
#include "afxdialogex.h"
#include "mainDlg.h"

// CDogPigDlg 대화 상자

IMPLEMENT_DYNAMIC(CDogPigDlg, CDialog)

CDogPigDlg::CDogPigDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DOGPIGDLG, pParent), m_dlg(NULL)
{
	m_cardName[0] = _T("1번 카드");
	m_cardName[1] = _T("2번 카드");
	m_cardName[2] = _T("3번 카드");
	m_cardName[3] = _T("4번 카드");
	m_cardName[4] = _T("5번 카드");
	m_cardName[5] = _T("6번 카드");
	m_cardName[6] = _T("7번 카드");
	m_cardName[7] = _T("8번 카드");
	m_cardName[8] = _T("9번 카드");
	m_cardName[9] = _T("10번 카드");
	m_cardName[10] = _T("11번 카드");
	m_cardName[11] = _T("12번 카드");
	m_cardName[12] = _T("13번 카드");
	m_cardName[13] = _T("14번 카드");
	m_cardName[14] = _T("15번 카드");
	m_cardName[15] = _T("16번 카드");
	m_cardName[16] = _T("17번 카드");
	m_cardName[17] = _T("18번 카드");
	m_cardName[18] = _T("19번 카드");
	m_cardName[19] = _T("20번 카드");
	m_cardName[20] = _T("21번 카드");
	m_cardName[21] = _T("22번 카드");
	m_cardName[22] = _T("23번 카드");
	m_cardName[23] = _T("24번 카드");
	m_cardName[24] = _T("25번 카드");
	m_cardName[25] = _T("26번 카드");


	std::string dummy;
	std::ifstream inputfile3("userinfo.txt");
	if (inputfile3.is_open()) {
		int i = 0;
		while (!inputfile3.eof()) {
			if (i == 0) {
				inputfile3 >> name;
			}
			else if (i == 1) {
				inputfile3 >> stage;
			}
			else if (i == 2) {
				inputfile3 >> dummy;
				packCnt = atoi(dummy.c_str());
			}
			else {
				inputfile3 >> m_card[i - 3][0] >> m_card[i - 3][1];
			}
			i++;
		}
	}
	inputfile3.close();

}

CDogPigDlg::~CDogPigDlg()
{
}

void CDogPigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PACK, m_packPic);
	DDX_Control(pDX, IDC_PACKNUM, m_packNum);

}


BEGIN_MESSAGE_MAP(CDogPigDlg, CDialog)
	ON_BN_CLICKED(IDC_OPENBTN, &CDogPigDlg::OnBnClickedOpenbtn)
	ON_WM_MOVE()
END_MESSAGE_MAP()


// CDogPigDlg 메시지 처리기


BOOL CDogPigDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CmainDlg* parent =
		(CmainDlg*)AfxGetMainWnd();
	parent->ShowWindow(SW_HIDE);

	m_packPic.SetEnhMetaFile(GetEnhMetaFile(_T("pack.emf")));
	CString p;
	p.Format(_T("%d"), packCnt);
	m_packNum.SetWindowTextW(p);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDogPigDlg::OnBnClickedOpenbtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (packCnt > 0&& m_dlg == NULL) {
		packCnt--;
		CString p;
		p.Format(_T("%d"), packCnt);
		m_packNum.SetWindowTextW(p);
		if (m_dlg == NULL) {
			m_dlg = new CResultDlg();
			m_dlg->Create(IDD_OPENDLG, this);
			m_dlg->ShowWindow(SW_SHOW);
		}
		else {
			m_dlg->SetFocus();
			m_dlg->UpdateData(false);
		}
	}
}


void CDogPigDlg::OnMove(int x, int y)
{
	CDialog::OnMove(x, y);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_dlg != NULL) {
		CRect rect;
		this->GetWindowRect(rect);
		m_dlg->MoveWindow(rect.left - 202, rect.bottom, 810, 300);
	}
}


BOOL CDogPigDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_ESCAPE) return TRUE;

	return CDialog::PreTranslateMessage(pMsg);
}


void CDogPigDlg::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (m_dlg == NULL) {

	CDialog::OnCancel();
	}
}
