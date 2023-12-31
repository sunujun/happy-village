// CCardDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "main.h"
#include "CCardDlg.h"
#include "afxdialogex.h"
#include "mainDlg.h"
// CCardDlg 대화 상자

IMPLEMENT_DYNAMIC(CCardDlg, CDialog)

CCardDlg::CCardDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CARDDlG, pParent), m_dlg(NULL), m_left(0), m_right(3)
{

	std::string dummy;
	std::ifstream inputfile3("userinfo.txt");
	if (inputfile3.is_open()) {
		int i = 0;
		while (!inputfile3.eof()) {
			if (i == 0) {
				inputfile3 >> dummy;
			}
			else if (i == 1) {
				inputfile3 >> dummy;
			}
			else if (i == 2) {
				inputfile3 >> dummy;
			}
			else {
				inputfile3 >> m_card[i - 3][0] >> m_card[i - 3][1];
			}
			i++;
		}
	}
	inputfile3.close();

	for (int i = 0; i < 26; i++) {
		if (m_card[i][1] > 0) {
			m_inFlag[i] = true;
			m_cntFlag[i] = true;
		}
		else {
			m_inFlag[i] = false;
			m_cntFlag[i] = false;
		}
	}
}

CCardDlg::~CCardDlg()
{
}

void CCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LEFTBTN, m_leftBtn);
	DDX_Control(pDX, IDC_RIGHTBTN, m_leftBtn);
	DDX_Control(pDX, IDC_CARD1, m_card1);
	DDX_Control(pDX, IDC_CARD2, m_card2);
	DDX_Control(pDX, IDC_CARD3, m_card3);
	DDX_Control(pDX, IDC_CARD4, m_card4);
	DDX_Control(pDX, IDC_CARD5, m_card5);
	DDX_Control(pDX, IDC_CARD6, m_card6);
	DDX_Control(pDX, IDC_CARD7, m_card7);
	DDX_Control(pDX, IDC_CARD8, m_card8);
	//for (int i = 0; i < 26; i++) {
	//	DDX_Control(pDX, IDC_CNT1+i, m_cardCnt[i]);
	//}



}


BEGIN_MESSAGE_MAP(CCardDlg, CDialog)
	ON_BN_CLICKED(IDC_MAKEBTN, &CCardDlg::OnBnClickedMakebtn)
	ON_WM_MOVE()
	ON_BN_CLICKED(IDC_LEFTBTN, &CCardDlg::OnBnClickedLeftbtn)
	ON_BN_CLICKED(IDC_RIGHTBTN, &CCardDlg::OnBnClickedRightbtn)
	ON_BN_CLICKED(IDC_RIGHTBTN, &CCardDlg::OnBnClickedRightbtn)

	ON_BN_CLICKED(IDC_CARD1, &CCardDlg::OnBnClickedCard1)
	ON_BN_CLICKED(IDC_CARD2, &CCardDlg::OnBnClickedCard2)
	ON_BN_CLICKED(IDC_CARD3, &CCardDlg::OnBnClickedCard3)
	ON_BN_CLICKED(IDC_CARD4, &CCardDlg::OnBnClickedCard4)
	ON_BN_CLICKED(IDC_CARD5, &CCardDlg::OnBnClickedCard5)
	ON_BN_CLICKED(IDC_CARD6, &CCardDlg::OnBnClickedCard6)
	ON_BN_CLICKED(IDC_CARD7, &CCardDlg::OnBnClickedCard7)
	ON_BN_CLICKED(IDC_CARD8, &CCardDlg::OnBnClickedCard8)
END_MESSAGE_MAP()


// CCardDlg 메시지 처리기


BOOL CCardDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CmainDlg* parent =
		(CmainDlg*)AfxGetMainWnd();
	parent->ShowWindow(SW_HIDE);
	m_str1.Format(_T("%d번 카드"), m_left * 8 + 1);
	m_str2.Format(_T("%d번 카드"), m_left * 8 + 2);
	m_str3.Format(_T("%d번 카드"), m_left * 8 + 3);
	m_str4.Format(_T("%d번 카드"), m_left * 8 + 4);
	m_str5.Format(_T("%d번 카드"), m_left * 8 + 5);
	m_str6.Format(_T("%d번 카드"), m_left * 8 + 6);
	m_str7.Format(_T("%d번 카드"), m_left * 8 + 7);
	m_str8.Format(_T("%d번 카드"), m_left * 8 + 8);
	m_card1.SetWindowText(m_str1);
	m_card2.SetWindowText(m_str2);
	m_card3.SetWindowText(m_str3);
	m_card4.SetWindowText(m_str4);
	m_card5.SetWindowText(m_str5);
	m_card6.SetWindowText(m_str6);
	m_card7.SetWindowText(m_str7);
	m_card8.SetWindowText(m_str8);

	m_card1.LoadBitmaps(IDB_BITMAP210, IDB_BITMAP210, IDB_BITMAP210, IDB_BITMAP210);
	m_card1.SizeToContent();
	m_card2.LoadBitmaps(IDB_BITMAP211, IDB_BITMAP211, IDB_BITMAP211, IDB_BITMAP211);
	m_card2.SizeToContent();
	m_card3.LoadBitmaps(IDB_BITMAP212, IDB_BITMAP212, IDB_BITMAP212, IDB_BITMAP212);
	m_card3.SizeToContent();
	m_card4.LoadBitmaps(IDB_BITMAP213, IDB_BITMAP213, IDB_BITMAP213, IDB_BITMAP213);
	m_card4.SizeToContent();
	m_card5.LoadBitmaps(IDB_BITMAP214, IDB_BITMAP214, IDB_BITMAP214, IDB_BITMAP214);
	m_card5.SizeToContent();
	m_card6.LoadBitmaps(IDB_BITMAP215, IDB_BITMAP215, IDB_BITMAP215, IDB_BITMAP215);
	m_card6.SizeToContent();
	m_card7.LoadBitmaps(IDB_BITMAP216, IDB_BITMAP216, IDB_BITMAP216, IDB_BITMAP216);
	m_card7.SizeToContent();
	m_card8.LoadBitmaps(IDB_BITMAP217, IDB_BITMAP217, IDB_BITMAP217, IDB_BITMAP217);
	m_card8.SizeToContent();

	/*CString cs;
	for (int i = 0; i < 8; i++) {
		cs.Format(_T("%d"), m_card[i][1]);
		m_cardCnt[i].SetWindowTextW(cs);
	}*/



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CCardDlg::OnBnClickedMakebtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를	 추가합니다.
	UpdateData(true);
	if (m_dlg == NULL) {
		m_dlg = new CDeckDlg();
		m_dlg->Create(IDD_MAKEDLG, this);
		m_dlg->ShowWindow(SW_SHOW);
	}
	else {
		m_dlg->SetFocus();
		m_dlg->UpdateData(false);
	}

}


void CCardDlg::OnMove(int x, int y)
{
	CDialog::OnMove(x, y);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_dlg != NULL) {
		CRect rect;
		this->GetWindowRect(rect);
		m_dlg->MoveWindow(rect.right, rect.top, 264, 510);
	}
}


void CCardDlg::OnBnClickedLeftbtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_left - 1 >= 0) {
		m_left--;
		m_right++;
		Invalidate(true);

	}
	m_str1.Format(_T("%d번 카드"), m_left * 8 + 1);
	m_str2.Format(_T("%d번 카드"), m_left * 8 + 2);
	m_str3.Format(_T("%d번 카드"), m_left * 8 + 3);
	m_str4.Format(_T("%d번 카드"), m_left * 8 + 4);
	m_str5.Format(_T("%d번 카드"), m_left * 8 + 5);
	m_str6.Format(_T("%d번 카드"), m_left * 8 + 6);
	m_str7.Format(_T("%d번 카드"), m_left * 8 + 7);
	m_str8.Format(_T("%d번 카드"), m_left * 8 + 8);
	m_card1.SetWindowText(m_str1);
	m_card2.SetWindowText(m_str2);
	m_card3.SetWindowText(m_str3);
	m_card4.SetWindowText(m_str4);
	m_card5.SetWindowText(m_str5);
	m_card6.SetWindowText(m_str6);
	m_card7.SetWindowText(m_str7);
	m_card8.SetWindowText(m_str8);
	TRACE("%d", m_left);
	TRACE("%d", m_right);

	if (m_cntFlag[m_left * 8] == true) {
		m_card1.LoadBitmaps(IDB_BITMAP210 + m_left * 8, IDB_BITMAP210 + m_left * 8, IDB_BITMAP210 + m_left * 8, IDB_BITMAP210 + m_left * 8);
		m_card1.SizeToContent();
	}
	else {
		m_card1.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card1.SizeToContent();
	}
	if (m_cntFlag[m_left * 8 + 1] == true) {
		m_card2.LoadBitmaps(IDB_BITMAP211 + m_left * 8, IDB_BITMAP211 + m_left * 8, IDB_BITMAP211 + m_left * 8, IDB_BITMAP211 + m_left * 8);
		m_card2.SizeToContent();
	}
	else {
		m_card2.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card2.SizeToContent();
	}
	if (m_cntFlag[m_left * 8 + 2] == true) {
		m_card3.LoadBitmaps(IDB_BITMAP212 + m_left * 8, IDB_BITMAP212 + m_left * 8, IDB_BITMAP212 + m_left * 8, IDB_BITMAP212 + m_left * 8);
		m_card3.SizeToContent();
	}
	else {
		m_card3.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card3.SizeToContent();
	}
	if (m_cntFlag[m_left * 8 + 3] == true) {
		m_card4.LoadBitmaps(IDB_BITMAP213 + m_left * 8, IDB_BITMAP213 + m_left * 8, IDB_BITMAP213 + m_left * 8, IDB_BITMAP213 + m_left * 8);
		m_card4.SizeToContent();
	}
	else {
		m_card4.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card4.SizeToContent();
	}
	if (m_cntFlag[m_left * 8 + 4] == true) {
		m_card5.LoadBitmaps(IDB_BITMAP214 + m_left * 8, IDB_BITMAP214 + m_left * 8, IDB_BITMAP214 + m_left * 8, IDB_BITMAP214 + m_left * 8);
		m_card5.SizeToContent();
	}
	else {
		m_card5.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card5.SizeToContent();
	}
	if (m_cntFlag[m_left * 8 + 5] == true) {
		m_card6.LoadBitmaps(IDB_BITMAP215 + m_left * 8, IDB_BITMAP215 + m_left * 8, IDB_BITMAP215 + m_left * 8, IDB_BITMAP215 + m_left * 8);
		m_card6.SizeToContent();
	}
	else {
		m_card6.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card6.SizeToContent();
	}
	if (m_cntFlag[m_left * 8 + 6] == true) {
		m_card7.LoadBitmaps(IDB_BITMAP216 + m_left * 8, IDB_BITMAP216 + m_left * 8, IDB_BITMAP216 + m_left * 8, IDB_BITMAP216 + m_left * 8);
		m_card7.SizeToContent();
	}
	else {
		m_card7.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card7.SizeToContent();
	}
	if (m_cntFlag[m_left * 8 + 7] == true) {
		m_card8.LoadBitmaps(IDB_BITMAP217 + m_left * 8, IDB_BITMAP217 + m_left * 8, IDB_BITMAP217 + m_left * 8, IDB_BITMAP217 + m_left * 8);
		m_card8.SizeToContent();
	}
	else {
		m_card8.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card8.SizeToContent();
	}

}


void CCardDlg::OnBnClickedRightbtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_right - 1 >= 0) {
		m_left++;
		m_right--;
		Invalidate(true);
	}
	m_str1.Format(_T("%d번 카드"), m_left * 8 + 1);
	m_str2.Format(_T("%d번 카드"), m_left * 8 + 2);
	m_str3.Format(_T("%d번 카드"), m_left * 8 + 3);
	m_str4.Format(_T("%d번 카드"), m_left * 8 + 4);
	m_str5.Format(_T("%d번 카드"), m_left * 8 + 5);
	m_str6.Format(_T("%d번 카드"), m_left * 8 + 6);
	m_str7.Format(_T("%d번 카드"), m_left * 8 + 7);
	m_str8.Format(_T("%d번 카드"), m_left * 8 + 8);
	m_card1.SetWindowText(m_str1);
	m_card2.SetWindowText(m_str2);
	m_card3.SetWindowText(m_str3);
	m_card4.SetWindowText(m_str4);
	m_card5.SetWindowText(m_str5);
	m_card6.SetWindowText(m_str6);
	m_card7.SetWindowText(m_str7);
	m_card8.SetWindowText(m_str8);
	TRACE("%d", m_left);
	TRACE("%d", m_right);

	if (m_left == 3) {
		if (m_cntFlag[m_left * 8] == true) {
			m_card1.LoadBitmaps(IDB_BITMAP210 + m_left * 8, IDB_BITMAP210 + m_left * 8, IDB_BITMAP210 + m_left * 8, IDB_BITMAP210 + m_left * 8);
			m_card1.SizeToContent();
		}
		else {
			m_card1.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
			m_card1.SizeToContent();
		}
		if (m_cntFlag[m_left * 8 + 1] == true) {
			m_card2.LoadBitmaps(IDB_BITMAP211 + m_left * 8, IDB_BITMAP211 + m_left * 8, IDB_BITMAP211 + m_left * 8, IDB_BITMAP211 + m_left * 8);
			m_card2.SizeToContent();
		}
		else {
			m_card2.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
			m_card2.SizeToContent();
		}
		m_card3.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card3.SizeToContent();
		m_card4.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card4.SizeToContent();
		m_card5.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card5.SizeToContent();
		m_card6.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card6.SizeToContent();
		m_card7.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card7.SizeToContent();
		m_card8.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
		m_card8.SizeToContent();
	}

	else {
		if (m_cntFlag[m_left * 8] == true) {
			m_card1.LoadBitmaps(IDB_BITMAP210 + m_left * 8, IDB_BITMAP210 + m_left * 8, IDB_BITMAP210 + m_left * 8, IDB_BITMAP210 + m_left * 8);
			m_card1.SizeToContent();
		}
		else {
			m_card1.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
			m_card1.SizeToContent();
		}
		if (m_cntFlag[m_left * 8 + 1] == true) {
			m_card2.LoadBitmaps(IDB_BITMAP211 + m_left * 8, IDB_BITMAP211 + m_left * 8, IDB_BITMAP211 + m_left * 8, IDB_BITMAP211 + m_left * 8);
			m_card2.SizeToContent();
		}
		else {
			m_card2.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
			m_card2.SizeToContent();
		}
		if (m_cntFlag[m_left * 8 + 2] == true) {
			m_card3.LoadBitmaps(IDB_BITMAP212 + m_left * 8, IDB_BITMAP212 + m_left * 8, IDB_BITMAP212 + m_left * 8, IDB_BITMAP212 + m_left * 8);
			m_card3.SizeToContent();
		}
		else {
			m_card3.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
			m_card3.SizeToContent();
		}
		if (m_cntFlag[m_left * 8 + 3] == true) {
			m_card4.LoadBitmaps(IDB_BITMAP213 + m_left * 8, IDB_BITMAP213 + m_left * 8, IDB_BITMAP213 + m_left * 8, IDB_BITMAP213 + m_left * 8);
			m_card4.SizeToContent();
		}
		else {
			m_card4.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
			m_card4.SizeToContent();
		}
		if (m_cntFlag[m_left * 8 + 4] == true) {
			m_card5.LoadBitmaps(IDB_BITMAP214 + m_left * 8, IDB_BITMAP214 + m_left * 8, IDB_BITMAP214 + m_left * 8, IDB_BITMAP214 + m_left * 8);
			m_card5.SizeToContent();
		}
		else {
			m_card5.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
			m_card5.SizeToContent();
		}
		if (m_cntFlag[m_left * 8 + 5] == true) {
			m_card6.LoadBitmaps(IDB_BITMAP215 + m_left * 8, IDB_BITMAP215 + m_left * 8, IDB_BITMAP215 + m_left * 8, IDB_BITMAP215 + m_left * 8);
			m_card6.SizeToContent();
		}
		else {
			m_card6.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
			m_card6.SizeToContent();
		}
		if (m_cntFlag[m_left * 8 + 6] == true) {
			m_card7.LoadBitmaps(IDB_BITMAP216 + m_left * 8, IDB_BITMAP216 + m_left * 8, IDB_BITMAP216 + m_left * 8, IDB_BITMAP216 + m_left * 8);
			m_card7.SizeToContent();
		}
		else {
			m_card7.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
			m_card7.SizeToContent();
		}
		if (m_cntFlag[m_left * 8 + 7] == true) {
			m_card8.LoadBitmaps(IDB_BITMAP217 + m_left * 8, IDB_BITMAP217 + m_left * 8, IDB_BITMAP217 + m_left * 8, IDB_BITMAP217 + m_left * 8);
			m_card8.SizeToContent();
		}
		else {
			m_card8.LoadBitmaps(IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209, IDB_BITMAP209);
			m_card8.SizeToContent();
		}
	}

}


void CCardDlg::OnBnClickedCard1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(FALSE);
	TRACE("%d", m_inFlag[m_left * 8]);
	if (m_dlg != NULL && m_inFlag[m_left * 8] == true) {
		CString str;
		str.Format(_T("%d번 카드"), m_left * 8 + 1);
		CString deckStr;
		int deckEmpty;
		for (int i = 0; i < 10; i++) {
			m_dlg->m_deck[i].GetWindowTextW(deckStr);
			deckEmpty = deckStr.Compare(_T("비어 있음"));
			if (deckEmpty == 0) {
				m_dlg->m_deck[i].SetWindowTextW(str);
				m_inFlag[m_left * 8] = false;
				break;
			}
			else {
				continue;
			}
		}
	}
}


void CCardDlg::OnBnClickedCard2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_dlg != NULL && m_inFlag[m_left * 8 + 1] == true) {
		CString str;
		str.Format(_T("%d번 카드"), m_left * 8 + 2);
		CString deckStr;
		int deckEmpty;
		for (int i = 0; i < 10; i++) {
			m_dlg->m_deck[i].GetWindowTextW(deckStr);
			deckEmpty = deckStr.Compare(_T("비어 있음"));
			if (deckEmpty == 0) {
				m_dlg->m_deck[i].SetWindowTextW(str);
				m_inFlag[m_left * 8 + 1] = false;
				break;
			}
			else {
				continue;
			}
		}
	}
}


void CCardDlg::OnBnClickedCard3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_dlg != NULL && m_inFlag[m_left * 8 + 2] == true) {
		CString str;
		str.Format(_T("%d번 카드"), m_left * 8 + 3);
		CString deckStr;
		int deckEmpty;
		if (m_left == 3) {
			return;
		}
		for (int i = 0; i < 10; i++) {
			m_dlg->m_deck[i].GetWindowTextW(deckStr);
			deckEmpty = deckStr.Compare(_T("비어 있음"));
			if (deckEmpty == 0) {
				m_dlg->m_deck[i].SetWindowTextW(str);
				m_inFlag[m_left * 8 + 2] = false;
				break;
			}
			else {
				continue;
			}
		}
	}
}


void CCardDlg::OnBnClickedCard4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_dlg != NULL && m_inFlag[m_left * 8 + 3] == true) {
		CString str;
		str.Format(_T("%d번 카드"), m_left * 8 + 4);
		CString deckStr;
		int deckEmpty;
		if (m_left == 3) {
			return;
		}
		for (int i = 0; i < 10; i++) {
			m_dlg->m_deck[i].GetWindowTextW(deckStr);
			deckEmpty = deckStr.Compare(_T("비어 있음"));
			if (deckEmpty == 0) {
				m_dlg->m_deck[i].SetWindowTextW(str);
				m_inFlag[m_left * 8 + 3] = false;
				break;
			}
			else {
				continue;
			}
		}
	}
}


void CCardDlg::OnBnClickedCard5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_dlg != NULL && m_inFlag[m_left * 8 + 4] == true) {
		CString str;
		str.Format(_T("%d번 카드"), m_left * 8 + 5);
		CString deckStr;
		int deckEmpty;
		if (m_left == 3) {
			return;
		}
		for (int i = 0; i < 10; i++) {
			m_dlg->m_deck[i].GetWindowTextW(deckStr);
			deckEmpty = deckStr.Compare(_T("비어 있음"));
			if (deckEmpty == 0) {
				m_dlg->m_deck[i].SetWindowTextW(str);
				m_inFlag[m_left * 8 + 4] = false;
				break;
			}
			else {
				continue;
			}
		}
	}
}


void CCardDlg::OnBnClickedCard6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_dlg != NULL && m_inFlag[m_left * 8 + 5] == true) {
		CString str;
		str.Format(_T("%d번 카드"), m_left * 8 + 6);
		CString deckStr;
		int deckEmpty;
		if (m_left == 3) {
			return;
		}
		for (int i = 0; i < 10; i++) {
			m_dlg->m_deck[i].GetWindowTextW(deckStr);
			deckEmpty = deckStr.Compare(_T("비어 있음"));
			if (deckEmpty == 0) {
				m_dlg->m_deck[i].SetWindowTextW(str);
				m_inFlag[m_left * 8 + 5] = false;
				break;
			}
			else {
				continue;
			}
		}
	}
}


void CCardDlg::OnBnClickedCard7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_dlg != NULL && m_inFlag[m_left * 8 + 6] == true) {
		CString str;
		str.Format(_T("%d번 카드"), m_left * 8 + 7);
		CString deckStr;
		int deckEmpty;
		if (m_left == 3) {
			return;
		}
		for (int i = 0; i < 10; i++) {
			m_dlg->m_deck[i].GetWindowTextW(deckStr);
			deckEmpty = deckStr.Compare(_T("비어 있음"));
			if (deckEmpty == 0) {
				m_dlg->m_deck[i].SetWindowTextW(str);
				m_inFlag[m_left * 8 + 6] = false;
				break;
			}
			else {
				continue;
			}
		}
	}
}


void CCardDlg::OnBnClickedCard8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_dlg != NULL && m_inFlag[m_left * 8 + 7] == true) {
		CString str;
		str.Format(_T("%d번 카드"), m_left * 8 + 8);
		CString deckStr;
		int deckEmpty;
		if (m_left == 3) {
			return;
		}

		for (int i = 0; i < 10; i++) {
			m_dlg->m_deck[i].GetWindowTextW(deckStr);
			deckEmpty = deckStr.Compare(_T("비어 있음"));
			if (deckEmpty == 0) {
				m_dlg->m_deck[i].SetWindowTextW(str);
				m_inFlag[m_left * 8 + 7] = false;
				break;
			}
			else {
				continue;
			}
		}
	}
}


BOOL CCardDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_ESCAPE) return TRUE;

	return CDialog::PreTranslateMessage(pMsg);
}
