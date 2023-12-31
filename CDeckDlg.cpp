// CDeckDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "main.h"
#include "CDeckDlg.h"
#include "afxdialogex.h"
#include "CCardDlg.h"
#include <fstream>
#include <string>
#include <iostream>

// CDeckDlg 대화 상자

IMPLEMENT_DYNAMIC(CDeckDlg, CDialog)

CDeckDlg::CDeckDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MAKEDLG, pParent)
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

	m_cardCode[0] = "100000";
	m_cardCode[1] = "100001";
	m_cardCode[2] = "100002";
	m_cardCode[3] = "100003";
	m_cardCode[4] = "100004";
	m_cardCode[5] = "100005";
	m_cardCode[6] = "100006";
	m_cardCode[7] = "101000";
	m_cardCode[8] = "101001";
	m_cardCode[9] = "101002";
	m_cardCode[10] = "101003";
	m_cardCode[11] = "101004";
	m_cardCode[12] = "101005";
	m_cardCode[13] = "101006";
	m_cardCode[14] = "102000";
	m_cardCode[15] = "102001";
	m_cardCode[16] = "102002";
	m_cardCode[17] = "102003";
	m_cardCode[18] = "102004";
	m_cardCode[19] = "102005";
	m_cardCode[20] = "102006";
	m_cardCode[21] = "103000";
	m_cardCode[22] = "103001";
	m_cardCode[23] = "103002";
	m_cardCode[24] = "103003";
	m_cardCode[25] = "103004";


}

CDeckDlg::~CDeckDlg()
{
}

void CDeckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DECK1, m_deck[0]);
	DDX_Control(pDX, IDC_DECK2, m_deck[1]);
	DDX_Control(pDX, IDC_DECK3, m_deck[2]);
	DDX_Control(pDX, IDC_DECK4, m_deck[3]);
	DDX_Control(pDX, IDC_DECK5, m_deck[4]);
	DDX_Control(pDX, IDC_DECK6, m_deck[5]);
	DDX_Control(pDX, IDC_DECK7, m_deck[6]);
	DDX_Control(pDX, IDC_DECK8, m_deck[7]);
	DDX_Control(pDX, IDC_DECK9, m_deck[8]);
	DDX_Control(pDX, IDC_DECK10, m_deck[9]);


}


BEGIN_MESSAGE_MAP(CDeckDlg, CDialog)
	ON_WM_WINDOWPOSCHANGING()
	ON_BN_CLICKED(IDC_DECK1, &CDeckDlg::OnBnClickedDeck1)
	ON_BN_CLICKED(IDC_DECK2, &CDeckDlg::OnBnClickedDeck2)
	ON_BN_CLICKED(IDC_DECK3, &CDeckDlg::OnBnClickedDeck3)
	ON_BN_CLICKED(IDC_DECK4, &CDeckDlg::OnBnClickedDeck4)
	ON_BN_CLICKED(IDC_DECK5, &CDeckDlg::OnBnClickedDeck5)
	ON_BN_CLICKED(IDC_DECK6, &CDeckDlg::OnBnClickedDeck6)
	ON_BN_CLICKED(IDC_DECK7, &CDeckDlg::OnBnClickedDeck7)
	ON_BN_CLICKED(IDC_DECK8, &CDeckDlg::OnBnClickedDeck8)
	ON_BN_CLICKED(IDC_DECK9, &CDeckDlg::OnBnClickedDeck9)
	ON_BN_CLICKED(IDC_DECK10, &CDeckDlg::OnBnClickedDeck10)
END_MESSAGE_MAP()


// CDeckDlg 메시지 처리기


void CDeckDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	int cnt = 0;
	CString str;
	for (int i = 0; i < 10; i++) {
		m_deck[i].GetWindowTextW(str);
		if (str.Compare(_T("비어 있음")) == 0) {
			cnt++;
		}
	}
	if (cnt == 0) {
		std::ofstream outfile("deck.txt");
		for (int i = 0; i < 10; i++) {
			m_deck[i].GetWindowTextW(str);
			for (int j = 0; j < 26; j++) {
				if (str.Compare(m_cardName[j]) == 0) {
					outfile << m_cardCode[j] << std::endl;
					break;
				}
			}
		}
		outfile.close();


		((CCardDlg*)GetParent())->m_dlg = NULL;

		this->DestroyWindow();
	}
	else {
		AfxMessageBox(_T("빈 덱이 있습니다."));
	}
	//CDialog::OnOK();
}


void CDeckDlg::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	((CCardDlg*)GetParent())->m_dlg = NULL;

	this->DestroyWindow();
	//CDialog::OnCancel();
}


void CDeckDlg::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	delete this;

	CDialog::PostNcDestroy();
}


BOOL CDeckDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CCardDlg* parent =
		(CCardDlg*)GetParent();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	/*m_deck[0].SetWindowText(_T("비어 있음"));
	m_deck[1].SetWindowText(_T("비어 있음"));
	m_deck[2].SetWindowText(_T("비어 있음"));
	m_deck[3].SetWindowText(_T("비어 있음"));
	m_deck[4].SetWindowText(_T("비어 있음"));
	m_deck[5].SetWindowText(_T("비어 있음"));
	m_deck[6].SetWindowText(_T("비어 있음"));
	m_deck[7].SetWindowText(_T("비어 있음"));
	m_deck[8].SetWindowText(_T("비어 있음"));
	m_deck[9].SetWindowText(_T("비어 있음"));*/

	CString cs;
	CString cs2;
	std::ifstream inputfile2("Deck.txt");
	if (inputfile2.is_open()) {
		int i = 0;
		while (!inputfile2.eof()) {
			inputfile2 >> deck[i];
			cs.Format(_T("%d"), deck[i]);
			for (int j = 0; j < 26; j++) {
				cs2 = m_cardCode[j].c_str();
				if (cs.Compare(cs2) == 0) {
					m_deck[i].SetWindowTextW(m_cardName[j]);
				}
			}
			i++;
		}
	}
	inputfile2.close();
	CString str;

	for (int i = 0; i < 10; i++) {
		m_deck[i].GetWindowTextW(str);
		if (str.Compare(_T("1번 카드")) == 0) {
			parent->m_inFlag[0] = false;
		}
		else if (str.Compare(_T("2번 카드")) == 0) {
			parent->m_inFlag[1] = false;
		}
		else if (str.Compare(_T("3번 카드")) == 0) {
			parent->m_inFlag[2] = false;
		}
		else if (str.Compare(_T("4번 카드")) == 0) {
			parent->m_inFlag[3] = false;
		}
		else if (str.Compare(_T("5번 카드")) == 0) {
			parent->m_inFlag[4] = false;
		}
		else if (str.Compare(_T("6번 카드")) == 0) {
			parent->m_inFlag[5] = false;
		}
		else if (str.Compare(_T("7번 카드")) == 0) {
			parent->m_inFlag[6] = false;
		}
		else if (str.Compare(_T("8번 카드")) == 0) {
			parent->m_inFlag[7] = false;
		}
		else if (str.Compare(_T("9번 카드")) == 0) {
			parent->m_inFlag[8] = false;
		}
		else if (str.Compare(_T("10번 카드")) == 0) {
			parent->m_inFlag[9] = false;
		}
		else if (str.Compare(_T("11번 카드")) == 0) {
			parent->m_inFlag[10] = false;
		}
		else if (str.Compare(_T("12번 카드")) == 0) {
			parent->m_inFlag[11] = false;
		}
		else if (str.Compare(_T("13번 카드")) == 0) {
			parent->m_inFlag[12] = false;
		}
		else if (str.Compare(_T("14번 카드")) == 0) {
			parent->m_inFlag[13] = false;
		}
		else if (str.Compare(_T("15번 카드")) == 0) {
			parent->m_inFlag[14] = false;
		}
		else if (str.Compare(_T("16번 카드")) == 0) {
			parent->m_inFlag[15] = false;
		}
		else if (str.Compare(_T("17번 카드")) == 0) {
			parent->m_inFlag[16] = false;
		}
		else if (str.Compare(_T("18번 카드")) == 0) {
			parent->m_inFlag[17] = false;
		}
		else if (str.Compare(_T("19번 카드")) == 0) {
			parent->m_inFlag[18] = false;
		}
		else if (str.Compare(_T("20번 카드")) == 0) {
			parent->m_inFlag[19] = false;
		}
		else if (str.Compare(_T("21번 카드")) == 0) {
			parent->m_inFlag[20] = false;
		}
		else if (str.Compare(_T("22번 카드")) == 0) {
			parent->m_inFlag[21] = false;
		}
		else if (str.Compare(_T("23번 카드")) == 0) {
			parent->m_inFlag[22] = false;
		}
		else if (str.Compare(_T("24번 카드")) == 0) {
			parent->m_inFlag[23] = false;
		}
		else if (str.Compare(_T("25번 카드")) == 0) {
			parent->m_inFlag[24] = false;
		}
		else if (str.Compare(_T("26번 카드")) == 0) {
			parent->m_inFlag[25] = false;
		}
	}


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDeckDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
	CDialog::OnWindowPosChanging(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CRect rect;
	((CCardDlg*)GetParent())->GetWindowRect(rect);
	this->MoveWindow(rect.right, rect.top, 264, 510);
	lpwndpos->flags |= SWP_NOMOVE;
}


void CDeckDlg::OnBnClickedDeck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCardDlg* parent =
		(CCardDlg*)GetParent();
	CString str;
	TRACE("%d", parent->m_inFlag[0]);

	m_deck[0].GetWindowTextW(str);
	if (str.Compare(_T("1번 카드")) == 0) {
		parent->m_inFlag[0] = true;
	}
	else if (str.Compare(_T("2번 카드")) == 0) {
		parent->m_inFlag[1] = true;
	}
	else if (str.Compare(_T("3번 카드")) == 0) {
		parent->m_inFlag[2] = true;
	}
	else if (str.Compare(_T("4번 카드")) == 0) {
		parent->m_inFlag[3] = true;
	}
	else if (str.Compare(_T("5번 카드")) == 0) {
		parent->m_inFlag[4] = true;
	}
	else if (str.Compare(_T("6번 카드")) == 0) {
		parent->m_inFlag[5] = true;
	}
	else if (str.Compare(_T("7번 카드")) == 0) {
		parent->m_inFlag[6] = true;
	}
	else if (str.Compare(_T("8번 카드")) == 0) {
		parent->m_inFlag[7] = true;
	}
	else if (str.Compare(_T("9번 카드")) == 0) {
		parent->m_inFlag[8] = true;
	}
	else if (str.Compare(_T("10번 카드")) == 0) {
		parent->m_inFlag[9] = true;
	}
	else if (str.Compare(_T("11번 카드")) == 0) {
		parent->m_inFlag[10] = true;
	}
	else if (str.Compare(_T("12번 카드")) == 0) {
		parent->m_inFlag[11] = true;
	}
	else if (str.Compare(_T("13번 카드")) == 0) {
		parent->m_inFlag[12] = true;
	}
	else if (str.Compare(_T("14번 카드")) == 0) {
		parent->m_inFlag[13] = true;
	}
	else if (str.Compare(_T("15번 카드")) == 0) {
		parent->m_inFlag[14] = true;
	}
	else if (str.Compare(_T("16번 카드")) == 0) {
		parent->m_inFlag[15] = true;
	}
	else if (str.Compare(_T("17번 카드")) == 0) {
		parent->m_inFlag[16] = true;
	}
	else if (str.Compare(_T("18번 카드")) == 0) {
		parent->m_inFlag[17] = true;
	}
	else if (str.Compare(_T("19번 카드")) == 0) {
		parent->m_inFlag[18] = true;
	}
	else if (str.Compare(_T("20번 카드")) == 0) {
		parent->m_inFlag[19] = true;
	}
	else if (str.Compare(_T("21번 카드")) == 0) {
		parent->m_inFlag[20] = true;
	}
	else if (str.Compare(_T("22번 카드")) == 0) {
		parent->m_inFlag[21] = true;
	}
	else if (str.Compare(_T("23번 카드")) == 0) {
		parent->m_inFlag[22] = true;
	}
	else if (str.Compare(_T("24번 카드")) == 0) {
		parent->m_inFlag[23] = true;
	}
	else if (str.Compare(_T("25번 카드")) == 0) {
		parent->m_inFlag[24] = true;
	}
	else if (str.Compare(_T("26번 카드")) == 0) {
		parent->m_inFlag[25] = true;
	}
	m_deck[0].SetWindowText(_T("비어 있음"));

}


void CDeckDlg::OnBnClickedDeck2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCardDlg* parent =
		(CCardDlg*)GetParent();
	CString str;
	m_deck[1].GetWindowTextW(str);
	if (str.Compare(_T("1번 카드")) == 0) {
		parent->m_inFlag[0] = true;
	}
	else if (str.Compare(_T("2번 카드")) == 0) {
		parent->m_inFlag[1] = true;
	}
	else if (str.Compare(_T("3번 카드")) == 0) {
		parent->m_inFlag[2] = true;
	}
	else if (str.Compare(_T("4번 카드")) == 0) {
		parent->m_inFlag[3] = true;
	}
	else if (str.Compare(_T("5번 카드")) == 0) {
		parent->m_inFlag[4] = true;
	}
	else if (str.Compare(_T("6번 카드")) == 0) {
		parent->m_inFlag[5] = true;
	}
	else if (str.Compare(_T("7번 카드")) == 0) {
		parent->m_inFlag[6] = true;
	}
	else if (str.Compare(_T("8번 카드")) == 0) {
		parent->m_inFlag[7] = true;
	}
	else if (str.Compare(_T("9번 카드")) == 0) {
		parent->m_inFlag[8] = true;
	}
	else if (str.Compare(_T("10번 카드")) == 0) {
		parent->m_inFlag[9] = true;
	}
	else if (str.Compare(_T("11번 카드")) == 0) {
		parent->m_inFlag[10] = true;
	}
	else if (str.Compare(_T("12번 카드")) == 0) {
		parent->m_inFlag[11] = true;
	}
	else if (str.Compare(_T("13번 카드")) == 0) {
		parent->m_inFlag[12] = true;
	}
	else if (str.Compare(_T("14번 카드")) == 0) {
		parent->m_inFlag[13] = true;
	}
	else if (str.Compare(_T("15번 카드")) == 0) {
		parent->m_inFlag[14] = true;
	}
	else if (str.Compare(_T("16번 카드")) == 0) {
		parent->m_inFlag[15] = true;
	}
	else if (str.Compare(_T("17번 카드")) == 0) {
		parent->m_inFlag[16] = true;
	}
	else if (str.Compare(_T("18번 카드")) == 0) {
		parent->m_inFlag[17] = true;
	}
	else if (str.Compare(_T("19번 카드")) == 0) {
		parent->m_inFlag[18] = true;
	}
	else if (str.Compare(_T("20번 카드")) == 0) {
		parent->m_inFlag[19] = true;
	}
	else if (str.Compare(_T("21번 카드")) == 0) {
		parent->m_inFlag[20] = true;
	}
	else if (str.Compare(_T("22번 카드")) == 0) {
		parent->m_inFlag[21] = true;
	}
	else if (str.Compare(_T("23번 카드")) == 0) {
		parent->m_inFlag[22] = true;
	}
	else if (str.Compare(_T("24번 카드")) == 0) {
		parent->m_inFlag[23] = true;
	}
	else if (str.Compare(_T("25번 카드")) == 0) {
		parent->m_inFlag[24] = true;
	}
	else if (str.Compare(_T("26번 카드")) == 0) {
		parent->m_inFlag[25] = true;
	}
	m_deck[1].SetWindowText(_T("비어 있음"));

}


void CDeckDlg::OnBnClickedDeck3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCardDlg* parent =
		(CCardDlg*)GetParent();
	CString str;
	m_deck[2].GetWindowTextW(str);
	TRACE(str);

	if (str.Compare(_T("1번 카드")) == 0) {
		parent->m_inFlag[0] = true;
	}
	else if (str.Compare(_T("2번 카드")) == 0) {
		parent->m_inFlag[1] = true;
	}
	else if (str.Compare(_T("3번 카드")) == 0) {
		parent->m_inFlag[2] = true;
	}
	else if (str.Compare(_T("4번 카드")) == 0) {
		parent->m_inFlag[3] = true;
	}
	else if (str.Compare(_T("5번 카드")) == 0) {
		parent->m_inFlag[4] = true;
	}
	else if (str.Compare(_T("6번 카드")) == 0) {
		parent->m_inFlag[5] = true;
	}
	else if (str.Compare(_T("7번 카드")) == 0) {
		parent->m_inFlag[6] = true;
	}
	else if (str.Compare(_T("8번 카드")) == 0) {
		parent->m_inFlag[7] = true;
	}
	else if (str.Compare(_T("9번 카드")) == 0) {
		parent->m_inFlag[8] = true;
	}
	else if (str.Compare(_T("10번 카드")) == 0) {
		parent->m_inFlag[9] = true;
	}
	else if (str.Compare(_T("11번 카드")) == 0) {
		parent->m_inFlag[10] = true;
	}
	else if (str.Compare(_T("12번 카드")) == 0) {
		parent->m_inFlag[11] = true;
	}
	else if (str.Compare(_T("13번 카드")) == 0) {
		parent->m_inFlag[12] = true;
	}
	else if (str.Compare(_T("14번 카드")) == 0) {
		parent->m_inFlag[13] = true;
	}
	else if (str.Compare(_T("15번 카드")) == 0) {
		parent->m_inFlag[14] = true;
	}
	else if (str.Compare(_T("16번 카드")) == 0) {
		parent->m_inFlag[15] = true;
	}
	else if (str.Compare(_T("17번 카드")) == 0) {
		parent->m_inFlag[16] = true;
	}
	else if (str.Compare(_T("18번 카드")) == 0) {
		parent->m_inFlag[17] = true;
	}
	else if (str.Compare(_T("19번 카드")) == 0) {
		parent->m_inFlag[18] = true;
	}
	else if (str.Compare(_T("20번 카드")) == 0) {
		parent->m_inFlag[19] = true;
	}
	else if (str.Compare(_T("21번 카드")) == 0) {
		parent->m_inFlag[20] = true;
	}
	else if (str.Compare(_T("22번 카드")) == 0) {
		parent->m_inFlag[21] = true;
	}
	else if (str.Compare(_T("23번 카드")) == 0) {
		parent->m_inFlag[22] = true;
	}
	else if (str.Compare(_T("24번 카드")) == 0) {
		parent->m_inFlag[23] = true;
	}
	else if (str.Compare(_T("25번 카드")) == 0) {
		parent->m_inFlag[24] = true;
	}
	else if (str.Compare(_T("26번 카드")) == 0) {
		parent->m_inFlag[25] = true;
	}

	m_deck[2].SetWindowText(_T("비어 있음"));

}


void CDeckDlg::OnBnClickedDeck4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCardDlg* parent =
		(CCardDlg*)GetParent();
	CString str;
	m_deck[3].GetWindowTextW(str);
	if (str.Compare(_T("1번 카드")) == 0) {
		parent->m_inFlag[0] = true;
	}
	else if (str.Compare(_T("2번 카드")) == 0) {
		parent->m_inFlag[1] = true;
	}
	else if (str.Compare(_T("3번 카드")) == 0) {
		parent->m_inFlag[2] = true;
	}
	else if (str.Compare(_T("4번 카드")) == 0) {
		parent->m_inFlag[3] = true;
	}
	else if (str.Compare(_T("5번 카드")) == 0) {
		parent->m_inFlag[4] = true;
	}
	else if (str.Compare(_T("6번 카드")) == 0) {
		parent->m_inFlag[5] = true;
	}
	else if (str.Compare(_T("7번 카드")) == 0) {
		parent->m_inFlag[6] = true;
	}
	else if (str.Compare(_T("8번 카드")) == 0) {
		parent->m_inFlag[7] = true;
	}
	else if (str.Compare(_T("9번 카드")) == 0) {
		parent->m_inFlag[8] = true;
	}
	else if (str.Compare(_T("10번 카드")) == 0) {
		parent->m_inFlag[9] = true;
	}
	else if (str.Compare(_T("11번 카드")) == 0) {
		parent->m_inFlag[10] = true;
	}
	else if (str.Compare(_T("12번 카드")) == 0) {
		parent->m_inFlag[11] = true;
	}
	else if (str.Compare(_T("13번 카드")) == 0) {
		parent->m_inFlag[12] = true;
	}
	else if (str.Compare(_T("14번 카드")) == 0) {
		parent->m_inFlag[13] = true;
	}
	else if (str.Compare(_T("15번 카드")) == 0) {
		parent->m_inFlag[14] = true;
	}
	else if (str.Compare(_T("16번 카드")) == 0) {
		parent->m_inFlag[15] = true;
	}
	else if (str.Compare(_T("17번 카드")) == 0) {
		parent->m_inFlag[16] = true;
	}
	else if (str.Compare(_T("18번 카드")) == 0) {
		parent->m_inFlag[17] = true;
	}
	else if (str.Compare(_T("19번 카드")) == 0) {
		parent->m_inFlag[18] = true;
	}
	else if (str.Compare(_T("20번 카드")) == 0) {
		parent->m_inFlag[19] = true;
	}
	else if (str.Compare(_T("21번 카드")) == 0) {
		parent->m_inFlag[20] = true;
	}
	else if (str.Compare(_T("22번 카드")) == 0) {
		parent->m_inFlag[21] = true;
	}
	else if (str.Compare(_T("23번 카드")) == 0) {
		parent->m_inFlag[22] = true;
	}
	else if (str.Compare(_T("24번 카드")) == 0) {
		parent->m_inFlag[23] = true;
	}
	else if (str.Compare(_T("25번 카드")) == 0) {
		parent->m_inFlag[24] = true;
	}
	else if (str.Compare(_T("26번 카드")) == 0) {
		parent->m_inFlag[25] = true;
	}
	m_deck[3].SetWindowText(_T("비어 있음"));
}


void CDeckDlg::OnBnClickedDeck5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCardDlg* parent =
		(CCardDlg*)GetParent();
	CString str;
	m_deck[4].GetWindowTextW(str);
	if (str.Compare(_T("1번 카드")) == 0) {
		parent->m_inFlag[0] = true;
	}
	else if (str.Compare(_T("2번 카드")) == 0) {
		parent->m_inFlag[1] = true;
	}
	else if (str.Compare(_T("3번 카드")) == 0) {
		parent->m_inFlag[2] = true;
	}
	else if (str.Compare(_T("4번 카드")) == 0) {
		parent->m_inFlag[3] = true;
	}
	else if (str.Compare(_T("5번 카드")) == 0) {
		parent->m_inFlag[4] = true;
	}
	else if (str.Compare(_T("6번 카드")) == 0) {
		parent->m_inFlag[5] = true;
	}
	else if (str.Compare(_T("7번 카드")) == 0) {
		parent->m_inFlag[6] = true;
	}
	else if (str.Compare(_T("8번 카드")) == 0) {
		parent->m_inFlag[7] = true;
	}
	else if (str.Compare(_T("9번 카드")) == 0) {
		parent->m_inFlag[8] = true;
	}
	else if (str.Compare(_T("10번 카드")) == 0) {
		parent->m_inFlag[9] = true;
	}
	else if (str.Compare(_T("11번 카드")) == 0) {
		parent->m_inFlag[10] = true;
	}
	else if (str.Compare(_T("12번 카드")) == 0) {
		parent->m_inFlag[11] = true;
	}
	else if (str.Compare(_T("13번 카드")) == 0) {
		parent->m_inFlag[12] = true;
	}
	else if (str.Compare(_T("14번 카드")) == 0) {
		parent->m_inFlag[13] = true;
	}
	else if (str.Compare(_T("15번 카드")) == 0) {
		parent->m_inFlag[14] = true;
	}
	else if (str.Compare(_T("16번 카드")) == 0) {
		parent->m_inFlag[15] = true;
	}
	else if (str.Compare(_T("17번 카드")) == 0) {
		parent->m_inFlag[16] = true;
	}
	else if (str.Compare(_T("18번 카드")) == 0) {
		parent->m_inFlag[17] = true;
	}
	else if (str.Compare(_T("19번 카드")) == 0) {
		parent->m_inFlag[18] = true;
	}
	else if (str.Compare(_T("20번 카드")) == 0) {
		parent->m_inFlag[19] = true;
	}
	else if (str.Compare(_T("21번 카드")) == 0) {
		parent->m_inFlag[20] = true;
	}
	else if (str.Compare(_T("22번 카드")) == 0) {
		parent->m_inFlag[21] = true;
	}
	else if (str.Compare(_T("23번 카드")) == 0) {
		parent->m_inFlag[22] = true;
	}
	else if (str.Compare(_T("24번 카드")) == 0) {
		parent->m_inFlag[23] = true;
	}
	else if (str.Compare(_T("25번 카드")) == 0) {
		parent->m_inFlag[24] = true;
	}
	else if (str.Compare(_T("26번 카드")) == 0) {
		parent->m_inFlag[25] = true;
	}
	m_deck[4].SetWindowText(_T("비어 있음"));
}


void CDeckDlg::OnBnClickedDeck6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCardDlg* parent =
		(CCardDlg*)GetParent();
	CString str;
	m_deck[5].GetWindowTextW(str);
	if (str.Compare(_T("1번 카드")) == 0) {
		parent->m_inFlag[0] = true;
	}
	else if (str.Compare(_T("2번 카드")) == 0) {
		parent->m_inFlag[1] = true;
	}
	else if (str.Compare(_T("3번 카드")) == 0) {
		parent->m_inFlag[2] = true;
	}
	else if (str.Compare(_T("4번 카드")) == 0) {
		parent->m_inFlag[3] = true;
	}
	else if (str.Compare(_T("5번 카드")) == 0) {
		parent->m_inFlag[4] = true;
	}
	else if (str.Compare(_T("6번 카드")) == 0) {
		parent->m_inFlag[5] = true;
	}
	else if (str.Compare(_T("7번 카드")) == 0) {
		parent->m_inFlag[6] = true;
	}
	else if (str.Compare(_T("8번 카드")) == 0) {
		parent->m_inFlag[7] = true;
	}
	else if (str.Compare(_T("9번 카드")) == 0) {
		parent->m_inFlag[8] = true;
	}
	else if (str.Compare(_T("10번 카드")) == 0) {
		parent->m_inFlag[9] = true;
	}
	else if (str.Compare(_T("11번 카드")) == 0) {
		parent->m_inFlag[10] = true;
	}
	else if (str.Compare(_T("12번 카드")) == 0) {
		parent->m_inFlag[11] = true;
	}
	else if (str.Compare(_T("13번 카드")) == 0) {
		parent->m_inFlag[12] = true;
	}
	else if (str.Compare(_T("14번 카드")) == 0) {
		parent->m_inFlag[13] = true;
	}
	else if (str.Compare(_T("15번 카드")) == 0) {
		parent->m_inFlag[14] = true;
	}
	else if (str.Compare(_T("16번 카드")) == 0) {
		parent->m_inFlag[15] = true;
	}
	else if (str.Compare(_T("17번 카드")) == 0) {
		parent->m_inFlag[16] = true;
	}
	else if (str.Compare(_T("18번 카드")) == 0) {
		parent->m_inFlag[17] = true;
	}
	else if (str.Compare(_T("19번 카드")) == 0) {
		parent->m_inFlag[18] = true;
	}
	else if (str.Compare(_T("20번 카드")) == 0) {
		parent->m_inFlag[19] = true;
	}
	else if (str.Compare(_T("21번 카드")) == 0) {
		parent->m_inFlag[20] = true;
	}
	else if (str.Compare(_T("22번 카드")) == 0) {
		parent->m_inFlag[21] = true;
	}
	else if (str.Compare(_T("23번 카드")) == 0) {
		parent->m_inFlag[22] = true;
	}
	else if (str.Compare(_T("24번 카드")) == 0) {
		parent->m_inFlag[23] = true;
	}
	else if (str.Compare(_T("25번 카드")) == 0) {
		parent->m_inFlag[24] = true;
	}
	else if (str.Compare(_T("26번 카드")) == 0) {
		parent->m_inFlag[25] = true;
	}
	m_deck[5].SetWindowText(_T("비어 있음"));
}


void CDeckDlg::OnBnClickedDeck7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCardDlg* parent =
		(CCardDlg*)GetParent();
	CString str;
	m_deck[6].GetWindowTextW(str);
	if (str.Compare(_T("1번 카드")) == 0) {
		parent->m_inFlag[0] = true;
	}
	else if (str.Compare(_T("2번 카드")) == 0) {
		parent->m_inFlag[1] = true;
	}
	else if (str.Compare(_T("3번 카드")) == 0) {
		parent->m_inFlag[2] = true;
	}
	else if (str.Compare(_T("4번 카드")) == 0) {
		parent->m_inFlag[3] = true;
	}
	else if (str.Compare(_T("5번 카드")) == 0) {
		parent->m_inFlag[4] = true;
	}
	else if (str.Compare(_T("6번 카드")) == 0) {
		parent->m_inFlag[5] = true;
	}
	else if (str.Compare(_T("7번 카드")) == 0) {
		parent->m_inFlag[6] = true;
	}
	else if (str.Compare(_T("8번 카드")) == 0) {
		parent->m_inFlag[7] = true;
	}
	else if (str.Compare(_T("9번 카드")) == 0) {
		parent->m_inFlag[8] = true;
	}
	else if (str.Compare(_T("10번 카드")) == 0) {
		parent->m_inFlag[9] = true;
	}
	else if (str.Compare(_T("11번 카드")) == 0) {
		parent->m_inFlag[10] = true;
	}
	else if (str.Compare(_T("12번 카드")) == 0) {
		parent->m_inFlag[11] = true;
	}
	else if (str.Compare(_T("13번 카드")) == 0) {
		parent->m_inFlag[12] = true;
	}
	else if (str.Compare(_T("14번 카드")) == 0) {
		parent->m_inFlag[13] = true;
	}
	else if (str.Compare(_T("15번 카드")) == 0) {
		parent->m_inFlag[14] = true;
	}
	else if (str.Compare(_T("16번 카드")) == 0) {
		parent->m_inFlag[15] = true;
	}
	else if (str.Compare(_T("17번 카드")) == 0) {
		parent->m_inFlag[16] = true;
	}
	else if (str.Compare(_T("18번 카드")) == 0) {
		parent->m_inFlag[17] = true;
	}
	else if (str.Compare(_T("19번 카드")) == 0) {
		parent->m_inFlag[18] = true;
	}
	else if (str.Compare(_T("20번 카드")) == 0) {
		parent->m_inFlag[19] = true;
	}
	else if (str.Compare(_T("21번 카드")) == 0) {
		parent->m_inFlag[20] = true;
	}
	else if (str.Compare(_T("22번 카드")) == 0) {
		parent->m_inFlag[21] = true;
	}
	else if (str.Compare(_T("23번 카드")) == 0) {
		parent->m_inFlag[22] = true;
	}
	else if (str.Compare(_T("24번 카드")) == 0) {
		parent->m_inFlag[23] = true;
	}
	else if (str.Compare(_T("25번 카드")) == 0) {
		parent->m_inFlag[24] = true;
	}
	else if (str.Compare(_T("26번 카드")) == 0) {
		parent->m_inFlag[25] = true;
	}
	m_deck[6].SetWindowText(_T("비어 있음"));
}


void CDeckDlg::OnBnClickedDeck8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCardDlg* parent =
		(CCardDlg*)GetParent();
	CString str;
	m_deck[7].GetWindowTextW(str);
	if (str.Compare(_T("1번 카드")) == 0) {
		parent->m_inFlag[0] = true;
	}
	else if (str.Compare(_T("2번 카드")) == 0) {
		parent->m_inFlag[1] = true;
	}
	else if (str.Compare(_T("3번 카드")) == 0) {
		parent->m_inFlag[2] = true;
	}
	else if (str.Compare(_T("4번 카드")) == 0) {
		parent->m_inFlag[3] = true;
	}
	else if (str.Compare(_T("5번 카드")) == 0) {
		parent->m_inFlag[4] = true;
	}
	else if (str.Compare(_T("6번 카드")) == 0) {
		parent->m_inFlag[5] = true;
	}
	else if (str.Compare(_T("7번 카드")) == 0) {
		parent->m_inFlag[6] = true;
	}
	else if (str.Compare(_T("8번 카드")) == 0) {
		parent->m_inFlag[7] = true;
	}
	else if (str.Compare(_T("9번 카드")) == 0) {
		parent->m_inFlag[8] = true;
	}
	else if (str.Compare(_T("10번 카드")) == 0) {
		parent->m_inFlag[9] = true;
	}
	else if (str.Compare(_T("11번 카드")) == 0) {
		parent->m_inFlag[10] = true;
	}
	else if (str.Compare(_T("12번 카드")) == 0) {
		parent->m_inFlag[11] = true;
	}
	else if (str.Compare(_T("13번 카드")) == 0) {
		parent->m_inFlag[12] = true;
	}
	else if (str.Compare(_T("14번 카드")) == 0) {
		parent->m_inFlag[13] = true;
	}
	else if (str.Compare(_T("15번 카드")) == 0) {
		parent->m_inFlag[14] = true;
	}
	else if (str.Compare(_T("16번 카드")) == 0) {
		parent->m_inFlag[15] = true;
	}
	else if (str.Compare(_T("17번 카드")) == 0) {
		parent->m_inFlag[16] = true;
	}
	else if (str.Compare(_T("18번 카드")) == 0) {
		parent->m_inFlag[17] = true;
	}
	else if (str.Compare(_T("19번 카드")) == 0) {
		parent->m_inFlag[18] = true;
	}
	else if (str.Compare(_T("20번 카드")) == 0) {
		parent->m_inFlag[19] = true;
	}
	else if (str.Compare(_T("21번 카드")) == 0) {
		parent->m_inFlag[20] = true;
	}
	else if (str.Compare(_T("22번 카드")) == 0) {
		parent->m_inFlag[21] = true;
	}
	else if (str.Compare(_T("23번 카드")) == 0) {
		parent->m_inFlag[22] = true;
	}
	else if (str.Compare(_T("24번 카드")) == 0) {
		parent->m_inFlag[23] = true;
	}
	else if (str.Compare(_T("25번 카드")) == 0) {
		parent->m_inFlag[24] = true;
	}
	else if (str.Compare(_T("26번 카드")) == 0) {
		parent->m_inFlag[25] = true;
	}
	m_deck[7].SetWindowText(_T("비어 있음"));
}


void CDeckDlg::OnBnClickedDeck9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCardDlg* parent =
		(CCardDlg*)GetParent();
	CString str;
	m_deck[8].GetWindowTextW(str);
	if (str.Compare(_T("1번 카드")) == 0) {
		parent->m_inFlag[0] = true;
	}
	else if (str.Compare(_T("2번 카드")) == 0) {
		parent->m_inFlag[1] = true;
	}
	else if (str.Compare(_T("3번 카드")) == 0) {
		parent->m_inFlag[2] = true;
	}
	else if (str.Compare(_T("4번 카드")) == 0) {
		parent->m_inFlag[3] = true;
	}
	else if (str.Compare(_T("5번 카드")) == 0) {
		parent->m_inFlag[4] = true;
	}
	else if (str.Compare(_T("6번 카드")) == 0) {
		parent->m_inFlag[5] = true;
	}
	else if (str.Compare(_T("7번 카드")) == 0) {
		parent->m_inFlag[6] = true;
	}
	else if (str.Compare(_T("8번 카드")) == 0) {
		parent->m_inFlag[7] = true;
	}
	else if (str.Compare(_T("9번 카드")) == 0) {
		parent->m_inFlag[8] = true;
	}
	else if (str.Compare(_T("10번 카드")) == 0) {
		parent->m_inFlag[9] = true;
	}
	else if (str.Compare(_T("11번 카드")) == 0) {
		parent->m_inFlag[10] = true;
	}
	else if (str.Compare(_T("12번 카드")) == 0) {
		parent->m_inFlag[11] = true;
	}
	else if (str.Compare(_T("13번 카드")) == 0) {
		parent->m_inFlag[12] = true;
	}
	else if (str.Compare(_T("14번 카드")) == 0) {
		parent->m_inFlag[13] = true;
	}
	else if (str.Compare(_T("15번 카드")) == 0) {
		parent->m_inFlag[14] = true;
	}
	else if (str.Compare(_T("16번 카드")) == 0) {
		parent->m_inFlag[15] = true;
	}
	else if (str.Compare(_T("17번 카드")) == 0) {
		parent->m_inFlag[16] = true;
	}
	else if (str.Compare(_T("18번 카드")) == 0) {
		parent->m_inFlag[17] = true;
	}
	else if (str.Compare(_T("19번 카드")) == 0) {
		parent->m_inFlag[18] = true;
	}
	else if (str.Compare(_T("20번 카드")) == 0) {
		parent->m_inFlag[19] = true;
	}
	else if (str.Compare(_T("21번 카드")) == 0) {
		parent->m_inFlag[20] = true;
	}
	else if (str.Compare(_T("22번 카드")) == 0) {
		parent->m_inFlag[21] = true;
	}
	else if (str.Compare(_T("23번 카드")) == 0) {
		parent->m_inFlag[22] = true;
	}
	else if (str.Compare(_T("24번 카드")) == 0) {
		parent->m_inFlag[23] = true;
	}
	else if (str.Compare(_T("25번 카드")) == 0) {
		parent->m_inFlag[24] = true;
	}
	else if (str.Compare(_T("26번 카드")) == 0) {
		parent->m_inFlag[25] = true;
	}
	m_deck[8].SetWindowText(_T("비어 있음"));
}


void CDeckDlg::OnBnClickedDeck10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCardDlg* parent =
		(CCardDlg*)GetParent();
	CString str;
	m_deck[9].GetWindowTextW(str);
	if (str.Compare(_T("1번 카드")) == 0) {
		parent->m_inFlag[0] = true;
	}
	else if (str.Compare(_T("2번 카드")) == 0) {
		parent->m_inFlag[1] = true;
	}
	else if (str.Compare(_T("3번 카드")) == 0) {
		parent->m_inFlag[2] = true;
	}
	else if (str.Compare(_T("4번 카드")) == 0) {
		parent->m_inFlag[3] = true;
	}
	else if (str.Compare(_T("5번 카드")) == 0) {
		parent->m_inFlag[4] = true;
	}
	else if (str.Compare(_T("6번 카드")) == 0) {
		parent->m_inFlag[5] = true;
	}
	else if (str.Compare(_T("7번 카드")) == 0) {
		parent->m_inFlag[6] = true;
	}
	else if (str.Compare(_T("8번 카드")) == 0) {
		parent->m_inFlag[7] = true;
	}
	else if (str.Compare(_T("9번 카드")) == 0) {
		parent->m_inFlag[8] = true;
	}
	else if (str.Compare(_T("10번 카드")) == 0) {
		parent->m_inFlag[9] = true;
	}
	else if (str.Compare(_T("11번 카드")) == 0) {
		parent->m_inFlag[10] = true;
	}
	else if (str.Compare(_T("12번 카드")) == 0) {
		parent->m_inFlag[11] = true;
	}
	else if (str.Compare(_T("13번 카드")) == 0) {
		parent->m_inFlag[12] = true;
	}
	else if (str.Compare(_T("14번 카드")) == 0) {
		parent->m_inFlag[13] = true;
	}
	else if (str.Compare(_T("15번 카드")) == 0) {
		parent->m_inFlag[14] = true;
	}
	else if (str.Compare(_T("16번 카드")) == 0) {
		parent->m_inFlag[15] = true;
	}
	else if (str.Compare(_T("17번 카드")) == 0) {
		parent->m_inFlag[16] = true;
	}
	else if (str.Compare(_T("18번 카드")) == 0) {
		parent->m_inFlag[17] = true;
	}
	else if (str.Compare(_T("19번 카드")) == 0) {
		parent->m_inFlag[18] = true;
	}
	else if (str.Compare(_T("20번 카드")) == 0) {
		parent->m_inFlag[19] = true;
	}
	else if (str.Compare(_T("21번 카드")) == 0) {
		parent->m_inFlag[20] = true;
	}
	else if (str.Compare(_T("22번 카드")) == 0) {
		parent->m_inFlag[21] = true;
	}
	else if (str.Compare(_T("23번 카드")) == 0) {
		parent->m_inFlag[22] = true;
	}
	else if (str.Compare(_T("24번 카드")) == 0) {
		parent->m_inFlag[23] = true;
	}
	else if (str.Compare(_T("25번 카드")) == 0) {
		parent->m_inFlag[24] = true;
	}
	else if (str.Compare(_T("26번 카드")) == 0) {
		parent->m_inFlag[25] = true;
	}
	m_deck[9].SetWindowText(_T("비어 있음"));
}


BOOL CDeckDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_ESCAPE) return TRUE;

	return CDialog::PreTranslateMessage(pMsg);
}
