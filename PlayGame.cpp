// PlayGame.cpp: 구현 파일
//

#include "stdafx.h"
#include "main.h"
#include "PlayGame.h"
#include "afxdialogex.h"
#include <fstream>
#include <time.h>
#include "CStageDlg.h"


// PlayGame 대화 상자

IMPLEMENT_DYNAMIC(PlayGame, CDialog)

PlayGame::PlayGame(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, castle1(100)
	, castle2(100)
	, cost(0)
	, pop(0)
	, e_pop(0)
	, playtime(0)
	, e_u_info(0)
	, e_u_n(0)
	, timerflag(0)
{
	
	std::ifstream inputfile("CardInfo.txt");
	if (inputfile.is_open()) {
		inputfile >> cardNum;
		int a, d, e, f, g, h, i, j, k, l;
		std::string b, c;
		while (!inputfile.eof()) {
			inputfile >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
			card_info.push_back(Unit(a, b, c, d, e, f, g, h, i, j, k, l, 0, 0, 0));
		}
	}
	inputfile.close();

	std::ifstream inputfile2("Deck.txt");
	if (inputfile2.is_open()) {
		int i = 0;
		while (!inputfile2.eof()) {
			inputfile2 >> deck[i++];
		}
	}
	inputfile2.close();

	std::ifstream inputfile3("userinfo.txt");
	if (inputfile3.is_open()) {
		int i = 0;
		while (!inputfile3.eof()) {
			if (i == 0) {
				inputfile3 >> u_n;
			}
			else if (i == 1) {
				inputfile3 >> u_stage;
			}
			else if (i == 2) {
				inputfile3 >> u_pack;
			}
			else {
				inputfile3 >> u_card[i - 3][0] >> u_card[i - 3][1];
			}
			i++;
		}
	}
	inputfile3.close();

	//CString str = _T("");
	//for (int i = 0; i < 10; i++) {
	//	CString s;
	//	s.Format(_T("%d"), deck[i]);
	//	str = str + _T("코드:") + s + _T("\n\n");
	//}
	//AfxMessageBox(str);

	srand((unsigned int)time(NULL));

	int flg = 0;
	for (int i = 0; i < 4; i++) {
		int k = rand() % 10;
		for (int j = 0; j < i; j++) {
			if (deck[k] == hand[j].code) {
				flg = 1;
				break;
			}
		}
		if (flg == 1) {
			i--;
			flg = 0;
			continue;
		}
		int l = bit(deck[k]);
		hand[i].code = card_info[l / 2].code;
		hand[i].name = card_info[l / 2].name;
		hand[i].description = card_info[l / 2].description;
		hand[i].atk = card_info[l / 2].atk;
		hand[i].hp = card_info[l / 2].hp;
		hand[i].cost = card_info[l / 2].cost;
		hand[i].m_speed = card_info[l / 2].m_speed;
		hand[i].a_speed = card_info[l / 2].a_speed;
		hand[i].rarity = card_info[l / 2].rarity;
		hand[i].pos = card_info[l / 2].pos;
		hand[i].range = card_info[l / 2].range;
		hand[i].dis = card_info[l / 2].dis;


		

	}

	/*CString str = _T("");
	for (int i = 0; i < 4; i++) {
		CString s[12];
		s[0].Format(_T("%d"), hand[i].code);
		s[1] = hand[i].name.c_str();
		s[2] = hand[i].description.c_str();
		s[3].Format(_T("%d"), hand[i].atk);
		s[4].Format(_T("%d"), hand[i].hp);
		s[5].Format(_T("%d"), hand[i].cost);
		s[6].Format(_T("%d"), hand[i].m_speed);
		s[7].Format(_T("%d"), hand[i].a_speed);
		s[8].Format(_T("%d"), hand[i].rarity);
		s[9].Format(_T("%d"), hand[i].pos);
		s[10].Format(_T("%d"), hand[i].range);
		s[11].Format(_T("%d"), hand[i].dis);
		str = str + _T("코드:") + s[0] + _T(" 이름:") + s[1] + _T(" 설명:") + s[2] + _T(" 공격력:") + s[3] + _T(" 체력:") + s[4]
			+ _T(" 코스트:") + s[5] + _T("\n이동속도:") + s[6] + _T(" 공격속도:") + s[7] + _T(" 등급:") + s[8] + _T(" 공중/지상:")
			+ s[9] + _T(" 사거리:") + s[10] + (" 근거리/원거리:") + s[11] + _T("\n\n");
	}
	AfxMessageBox(str);*/

	/*CString str = _T("");
	for (int i = 0; i < cardNum; i++) {
		CString s[12];
		s[0].Format(_T("%d"), card_info[i].code);
		s[1] = card_info[i].name.c_str();
		s[2] = card_info[i].description.c_str();
		s[3].Format(_T("%d"), card_info[i].atk);
		s[4].Format(_T("%d"), card_info[i].hp);
		s[5].Format(_T("%d"), card_info[i].cost);
		s[6].Format(_T("%d"), card_info[i].m_speed);
		s[7].Format(_T("%d"), card_info[i].a_speed);
		s[8].Format(_T("%d"), card_info[i].rarity);
		s[9].Format(_T("%d"), card_info[i].pos);
		s[10].Format(_T("%d"), card_info[i].range);
		s[11].Format(_T("%d"), card_info[i].dis);
		str = str + _T("코드:") + s[0] + _T(" 이름:") + s[1] + _T(" 설명:") + s[2] + _T(" 공격력:") + s[3] + _T(" 체력:") +s[4]
			+ _T(" 코스트:") + s[5] + _T("\n이동속도:") + s[6] + _T(" 공격속도:") + s[7] + _T(" 등급:") + s[8] + _T(" 공중/지상:")
			+ s[9] + _T(" 사거리:") + s[10] + (" 근거리/원거리:") + s[11] + _T("\n\n");
	}
	AfxMessageBox(str);*/

	//int hos;
	//hos = 0;
	//unit1.push_back(Unit(card_info[hos].code, card_info[hos].name, card_info[hos].description, card_info[hos].atk, card_info[hos].hp, card_info[hos].cost, card_info[hos].m_speed, card_info[hos].a_speed, card_info[hos].rarity, card_info[hos].pos, card_info[hos].range, card_info[hos].dis, 100, 0, 0));
	//pop++;
	//unit1.push_back(Unit(card_info[0].code, card_info[0].name, card_info[0].description, card_info[0].atk, card_info[0].hp, card_info[0].cost, card_info[0].m_speed, card_info[0].a_speed, card_info[0].rarity, card_info[0].pos, card_info[0].range, card_info[0].dis, 700, 0, 0));
	//pop++;
	//unit2.push_back(Unit(card_info[hos].code, card_info[hos].name, card_info[hos].description, card_info[hos].atk, card_info[hos].hp, card_info[hos].cost, card_info[hos].m_speed, card_info[hos].a_speed, card_info[hos].rarity, card_info[hos].pos, card_info[hos].range, card_info[hos].dis, 920, 0, 0));
	//e_pop++;
	//unit2.push_back(Unit(card_info[0].code, card_info[0].name, card_info[0].description, card_info[0].atk, card_info[0].hp, card_info[0].cost, card_info[0].m_speed, card_info[0].a_speed, card_info[0].rarity, card_info[0].pos, card_info[0].range, card_info[0].dis, 700, 0, 0));
	//e_pop++;
	//unit2.push_back(Unit(card_info[0].code, card_info[0].name, card_info[0].description, card_info[0].atk, card_info[0].hp, card_info[0].cost, card_info[0].m_speed, card_info[0].a_speed, card_info[0].rarity, card_info[0].pos, card_info[0].range, card_info[0].dis, 400, 0, 0));
	//e_pop++;
}

PlayGame::~PlayGame()
{
}

void PlayGame::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PlayGame, CDialog)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// PlayGame 메시지 처리기


BOOL PlayGame::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect desk_rect;
	GetDesktopWindow()->GetWindowRect(&desk_rect);
	this->MoveWindow(desk_rect.left + (desk_rect.Width() / 2) - 540, desk_rect.bottom - (desk_rect.Height() / 2) - 324, 1080, 648);
	CStageDlg* parent =
		(CStageDlg*)GetParent();
	stage = parent->m_playStage;
	
	if (stage == 11) {
		ifstream inputfile11("11.txt");
		if (inputfile11.is_open()) {
			inputfile11 >> e_u_info;
			while (!inputfile11.eof()) {
				int a, b;
				inputfile11 >> a >> b;
				e_u.push_back(UnitTime(a, b));
			}
		}
		inputfile11.close();
	}
	else if (stage == 12) {
		ifstream inputfile12("12.txt");
		if (inputfile12.is_open()) {
			inputfile12 >> e_u_info;
			while (!inputfile12.eof()) {
				int a, b;
				inputfile12 >> a >> b;
				e_u.push_back(UnitTime(a, b));
			}
		}
		inputfile12.close();
	}
	else if (stage == 13) {
		ifstream inputfile13("13.txt");
		if (inputfile13.is_open()) {
			inputfile13 >> e_u_info;
			while (!inputfile13.eof()) {
				int a, b;
				inputfile13 >> a >> b;
				e_u.push_back(UnitTime(a, b));
			}
		}
		inputfile13.close();
	}
	else if (stage == 14) {
		ifstream inputfile14("14.txt");
		if (inputfile14.is_open()) {
			inputfile14 >> e_u_info;
			while (!inputfile14.eof()) {
				int a, b;
				inputfile14 >> a >> b;
				e_u.push_back(UnitTime(a, b));
			}
		}
		inputfile14.close();
	}
	else if (stage == 15) {
		ifstream inputfile15("15.txt");
		if (inputfile15.is_open()) {
			inputfile15 >> e_u_info;
			while (!inputfile15.eof()) {
				int a, b;
				inputfile15 >> a >> b;
				e_u.push_back(UnitTime(a, b));
			}
		}
		inputfile15.close();
	}
	SetTimer(1, 50, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void PlayGame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CDC memdc;
	CDC memdc2;
	CDC main_dc;
	CBitmap main_bmp;

	memdc.CreateCompatibleDC(&main_dc);
	memdc2.CreateCompatibleDC(&main_dc);
	main_dc.CreateCompatibleDC(&dc);
	main_bmp.CreateCompatibleBitmap(&dc, m_client.Width(), m_client.Height());
	main_dc.SelectObject(&main_bmp);

	CBitmap bg[2];
	BITMAP bg_info[2];
	bg[0].LoadBitmapW(IDB_BITMAP236);
	bg[0].GetBitmap(&bg_info[0]);
	bg[1].LoadBitmapW(IDB_BITMAP237);
	bg[1].GetBitmap(&bg_info[1]);
	memdc.SelectObject(&bg[0]);
	main_dc.TransparentBlt(0, 0, bg_info[0].bmWidth, bg_info[0].bmHeight, &memdc, 0, 0, bg_info[0].bmWidth, bg_info[0].bmHeight, RGB(0, 255, 0));
	memdc.SelectObject(&bg[1]);
	main_dc.TransparentBlt(0, 374, bg_info[1].bmWidth, bg_info[1].bmHeight, &memdc, 0, 0, bg_info[1].bmWidth, bg_info[1].bmHeight, RGB(0, 255, 0));

	main_dc.SetBkMode(TRANSPARENT);
	main_dc.SetTextColor(RGB(255, 255, 240));
	CString st;
	st.Format(_T("%d"), castle1);
	main_dc.TextOutW(65, 145, st);
	st.Format(_T("%d"), castle2);
	main_dc.TextOutW(995, 145, st);

	CBitmap castle;
	BITMAP castle_info;
	castle.LoadBitmapW(IDB_BITMAP238);
	castle.GetBitmap(&castle_info);
	memdc.SelectObject(&castle);
	main_dc.TransparentBlt(10, 165, castle_info.bmWidth, castle_info.bmHeight, &memdc, 0, 0, castle_info.bmWidth, castle_info.bmHeight, RGB(0, 255, 0));
	main_dc.TransparentBlt(940, 165, castle_info.bmWidth, castle_info.bmHeight, &memdc, 0, 0, castle_info.bmWidth, castle_info.bmHeight, RGB(0, 255, 0));

	CBitmap slot;
	BITMAP slot_info;
	slot.LoadBitmapW(IDB_BITMAP241);
	slot.GetBitmap(&slot_info);
	memdc.SelectObject(&slot);
	main_dc.TransparentBlt(550, 490, slot_info.bmWidth, slot_info.bmHeight, &memdc, 0, 0, slot_info.bmWidth, slot_info.bmHeight, RGB(0, 255, 0));
	main_dc.TransparentBlt(680, 490, slot_info.bmWidth, slot_info.bmHeight, &memdc, 0, 0, slot_info.bmWidth, slot_info.bmHeight, RGB(0, 255, 0));
	main_dc.TransparentBlt(810, 490, slot_info.bmWidth, slot_info.bmHeight, &memdc, 0, 0, slot_info.bmWidth, slot_info.bmHeight, RGB(0, 255, 0));
	main_dc.TransparentBlt(940, 490, slot_info.bmWidth, slot_info.bmHeight, &memdc, 0, 0, slot_info.bmWidth, slot_info.bmHeight, RGB(0, 255, 0));

	CString slot_unit_cost[4];
	for (int i = 0; i < 4; i++) {
		slot_unit_cost[i].Format(_T("%d"), hand[i].cost);
		slot_unit_cost[i] = _T("cost x ") + slot_unit_cost[i];
		main_dc.TextOutW(575 + (130 * i), 500, slot_unit_cost[i]);
	}

	CBitmap slot_unit[26];
	BITMAP slot_unit_info[26];
	for (int i = 0; i < 26; i++) {
		slot_unit[i].LoadBitmapW(IDB_BITMAP210 + i);
		slot_unit[i].GetBitmap(&slot_unit_info[i]);
	}

	for (int i = 0; i < 4; i++) {
		int j = (bit(hand[i].code) / 2);
		memdc.SelectObject(&slot_unit[j]);
		main_dc.TransparentBlt(556 + (130 * i), 527, slot_unit_info[j].bmWidth, slot_unit_info[j].bmHeight, &memdc, 0, 0, slot_unit_info[j].bmWidth, slot_unit_info[j].bmHeight, RGB(0, 255, 0));
	}



	CBitmap pop_icon;
	BITMAP pop_icon_info;
	pop_icon.LoadBitmapW(IDB_BITMAP240);
	pop_icon.GetBitmap(&pop_icon_info);
	memdc.SelectObject(&pop_icon);
	main_dc.TransparentBlt(25, 505, pop_icon_info.bmWidth, pop_icon_info.bmHeight, &memdc, 0, 0, pop_icon_info.bmWidth, pop_icon_info.bmHeight, RGB(0, 255, 0));

	CBitmap mana_icon;
	BITMAP mana_icon_info;
	mana_icon.LoadBitmapW(IDB_BITMAP239);
	mana_icon.GetBitmap(&mana_icon_info);
	memdc.SelectObject(&mana_icon);
	main_dc.TransparentBlt(20, 565, mana_icon_info.bmWidth, mana_icon_info.bmHeight, &memdc, 0, 0, mana_icon_info.bmWidth, mana_icon_info.bmHeight, RGB(0, 255, 0));

	CString spop, smana;
	spop.Format(_T("%d"), pop);
	smana.Format(_T("%d"), cost);
	spop = spop + L"/15";
	smana = smana + L"/10";
	main_dc.SetTextColor(RGB(0, 0, 0));
	main_dc.TextOutW(90, 520, spop);
	main_dc.TextOutW(90, 585, smana);

	CBitmap exit_icon;
	BITMAP exit_icon_info;
	exit_icon.LoadBitmapW(IDB_BITMAP242);
	exit_icon.GetBitmap(&exit_icon_info);
	memdc.SelectObject(&exit_icon);
	main_dc.TransparentBlt(1015, 10, exit_icon_info.bmWidth, exit_icon_info.bmHeight, &memdc, 0, 0, exit_icon_info.bmWidth, exit_icon_info.bmHeight, RGB(0, 255, 0));

	CBitmap move[52];
	BITMAP move_info[52];
	for (int i = 0; i < 52; i += 2) {
		move[i].LoadBitmapW(IDB_BITMAP1 + (i * 4));
		move[i].GetBitmap(&move_info[i]);
		move[i + 1].LoadBitmapW(IDB_BITMAP2 + (i * 4));
		move[i + 1].GetBitmap(&move_info[i + 1]);
	}

	CBitmap attack[52];
	BITMAP attack_info[52];
	for (int i = 0; i < 52; i += 2) {
		attack[i].LoadBitmapW(IDB_BITMAP3 + (i * 4));
		attack[i].GetBitmap(&attack_info[i]);
		attack[i + 1].LoadBitmapW(IDB_BITMAP4 + (i * 4));
		attack[i + 1].GetBitmap(&attack_info[i + 1]);
	}

	for (int i = 0; i < pop; i++) {
		if (unit1[i].isAttack == 0) {
			memdc.SelectObject(&move[unit1[i].count + bit(unit1[i].code)]);
			main_dc.TransparentBlt(unit1[i].x, 420 - move_info[unit1[i].count + bit(unit1[i].code)].bmHeight, move_info[unit1[i].count + bit(unit1[i].code)].bmWidth, move_info[unit1[i].count + bit(unit1[i].code)].bmHeight, &memdc, 0, 0, move_info[unit1[i].count + bit(unit1[i].code)].bmWidth, move_info[unit1[i].count + bit(unit1[i].code)].bmHeight, RGB(0, 255, 0));
		}
		else {
			memdc.SelectObject(&attack[unit1[i].count + bit(unit1[i].code)]);
			main_dc.TransparentBlt(unit1[i].x, 420 - attack_info[unit1[i].count + bit(unit1[i].code)].bmHeight, attack_info[unit1[i].count + bit(unit1[i].code)].bmWidth, attack_info[unit1[i].count + bit(unit1[i].code)].bmHeight, &memdc, 0, 0, attack_info[unit1[i].count + bit(unit1[i].code)].bmWidth, attack_info[unit1[i].count + bit(unit1[i].code)].bmHeight, RGB(0, 255, 0));
		}
	}

	CBitmap r_move[52];
	BITMAP r_move_info[52];
	for (int j = 0; j < 52; j += 2) {
		r_move[j].LoadBitmapW(IDB_BITMAP5 + (j * 4));
		r_move[j].GetBitmap(&r_move_info[j]);
		r_move[j + 1].LoadBitmapW(IDB_BITMAP6 + (j * 4));
		r_move[j + 1].GetBitmap(&r_move_info[j + 1]);
	}

	CBitmap r_attack[52];
	BITMAP r_attack_info[52];
	for (int j = 0; j < 52; j += 2) {
		r_attack[j].LoadBitmapW(IDB_BITMAP7 + (j * 4));
		r_attack[j].GetBitmap(&r_attack_info[j]);
		r_attack[j + 1].LoadBitmapW(IDB_BITMAP8 + (j * 4));
		r_attack[j + 1].GetBitmap(&r_attack_info[j + 1]);
	}

	for (int j = 0; j < e_pop; j++) {
		if (unit2[j].isAttack == 0) {
			memdc.SelectObject(&r_move[unit2[j].count + bit(unit2[j].code)]);
			main_dc.TransparentBlt(unit2[j].x + r_move_info[bit(unit2[j].code)].bmWidth - r_move_info[unit2[j].count + bit(unit2[j].code)].bmWidth, 420 - r_move_info[unit2[j].count + bit(unit2[j].code)].bmHeight, r_move_info[unit2[j].count + bit(unit2[j].code)].bmWidth, r_move_info[unit2[j].count + bit(unit2[j].code)].bmHeight, &memdc, 0, 0, r_move_info[unit2[j].count + bit(unit2[j].code)].bmWidth, r_move_info[unit2[j].count + bit(unit2[j].code)].bmHeight, RGB(0, 255, 0));
		}
		else {
			memdc.SelectObject(&r_attack[unit2[j].count + bit(unit2[j].code)]);
			main_dc.TransparentBlt(unit2[j].x + r_move_info[bit(unit2[j].code)].bmWidth - r_attack_info[unit2[j].count + bit(unit2[j].code)].bmWidth, 420 - r_attack_info[unit2[j].count].bmHeight, r_attack_info[unit2[j].count + bit(unit2[j].code)].bmWidth, r_attack_info[unit2[j].count + bit(unit2[j].code)].bmHeight, &memdc, 0, 0, r_attack_info[unit2[j].count + bit(unit2[j].code)].bmWidth, r_attack_info[unit2[j].count + bit(unit2[j].code)].bmHeight, RGB(0, 255, 0));
		}
	}



	dc.BitBlt(0, 0, m_client.Width(), m_client.Height(), &main_dc, 0, 0, SRCCOPY);
}


void PlayGame::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	GetClientRect(&m_client);
}

int PlayGame::bit(int code)
{
	switch (code) {
	case 100000:
		return 0;
		break;
	case 100001:
		return 2;
		break;
	case 100002:
		return 4;
		break;
	case 100003:
		return 6;
		break;
	case 100004:
		return 8;
		break;
	case 100005:
		return 10;
		break;
	case 100006:
		return 12;
		break;
	case 101000:
		return 14;
		break;
	case 101001:
		return 16;
		break;
	case 101002:
		return 18;
		break;
	case 101003:
		return 20;
		break;
	case 101004:
		return 22;
		break;
	case 101005:
		return 24;
		break;
	case 101006:
		return 26;
		break;
	case 102000:
		return 28;
		break;
	case 102001:
		return 30;
		break;
	case 102002:
		return 32;
		break;
	case 102003:
		return 34;
		break;
	case 102004:
		return 36;
		break;
	case 102005:
		return 38;
		break;
	case 102006:
		return 40;
		break;
	case 103000:
		return 42;
		break;
	case 103001:
		return 44;
		break;
	case 103002:
		return 46;
		break;
	case 103003:
		return 48;
		break;
	case 103004:
		return 50;
		break;
	default:
		return 0;
		break;
	}
}

void PlayGame::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int is_u = -1;

	if (point.x >= 1015 && point.x <= 1070 && point.y >= 10 && point.y <= 37) {
		KillTimer(1);
		OnCancel();
	}

	if (point.x >= 550 && point.x <= 662 && point.y >= 490 && point.y <= 632) {
		if (hand[0].cost <= cost && pop < 15) {
			cost -= hand[0].cost;
			unit1.push_back(Unit(hand[0].code, hand[0].name, hand[0].description, hand[0].atk, hand[0].hp, hand[0].cost, hand[0].m_speed, hand[0].a_speed, hand[0].rarity, hand[0].pos, hand[0].range, hand[0].dis, 100, 0, 0));
			pop++;
			is_u = 0;
		}
	}
	else if (point.x >= 680 && point.x <= 792 && point.y >= 490 && point.y <= 632) {
		if (hand[1].cost <= cost && pop < 15) {
			cost -= hand[1].cost;
			unit1.push_back(Unit(hand[1].code, hand[1].name, hand[1].description, hand[1].atk, hand[1].hp, hand[1].cost, hand[1].m_speed, hand[1].a_speed, hand[1].rarity, hand[1].pos, hand[1].range, hand[1].dis, 100, 0, 0));
			pop++;
			is_u = 1;
		}
	}
	else if (point.x >= 810 && point.x <= 922 && point.y >= 490 && point.y <= 632) {
		if (hand[2].cost <= cost && pop < 15) {
			cost -= hand[2].cost;
			unit1.push_back(Unit(hand[2].code, hand[2].name, hand[2].description, hand[2].atk, hand[2].hp, hand[2].cost, hand[2].m_speed, hand[2].a_speed, hand[2].rarity, hand[2].pos, hand[2].range, hand[2].dis, 100, 0, 0));
			pop++;
			is_u = 2;
		}
	}
	else if (point.x >= 940 && point.x <= 1052 && point.y >= 490 && point.y <= 632) {
		if (hand[3].cost <= cost && pop < 15) {
			cost -= hand[3].cost;
			unit1.push_back(Unit(hand[3].code, hand[3].name, hand[3].description, hand[3].atk, hand[3].hp, hand[3].cost, hand[3].m_speed, hand[3].a_speed, hand[3].rarity, hand[3].pos, hand[3].range, hand[3].dis, 100, 0, 0));
			pop++;
			is_u = 3;
		}
	}

	if (is_u == 0 || is_u == 1 || is_u == 2 || is_u == 3) {

		while (1) {
			int flg = 0;
			int k = rand() % 10;
			for (int i = 0; i < 4; i++) {
				if (deck[k] == hand[i].code) {
					flg = 1;
					break;
				}
			}
			if (flg == 1)
				continue;

			int l = bit(deck[k]);
			hand[is_u].code = card_info[l / 2].code;
			hand[is_u].name = card_info[l / 2].name;
			hand[is_u].description = card_info[l / 2].description;
			hand[is_u].atk = card_info[l / 2].atk;
			hand[is_u].hp = card_info[l / 2].hp;
			hand[is_u].cost = card_info[l / 2].cost;
			hand[is_u].m_speed = card_info[l / 2].m_speed;
			hand[is_u].a_speed = card_info[l / 2].a_speed;
			hand[is_u].rarity = card_info[l / 2].rarity;
			hand[is_u].pos = card_info[l / 2].pos;
			hand[is_u].range = card_info[l / 2].range;
			hand[is_u].dis = card_info[l / 2].dis;

			break;
		}
		is_u = -1;
	}

	Invalidate(false);


	CDialog::OnLButtonDown(nFlags, point);
}


BOOL PlayGame::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_ESCAPE) return TRUE;


	return CDialog::PreTranslateMessage(pMsg);
}


void PlayGame::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CDialog::OnCancel();
}


void PlayGame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (nIDEvent == 1) {
		playtime++;
		if (((playtime % 40) == 0) && (cost < 10))
			cost++;

		if (e_u_info > e_u_n)
			if (e_u[e_u_n].time == playtime) {
				unit2.push_back(Unit(card_info[e_u[e_u_n].nu].code, card_info[e_u[e_u_n].nu].name, card_info[e_u[e_u_n].nu].description, card_info[e_u[e_u_n].nu].atk, card_info[e_u[e_u_n].nu].hp, card_info[e_u[e_u_n].nu].cost, card_info[e_u[e_u_n].nu].m_speed, card_info[e_u[e_u_n].nu].a_speed, card_info[e_u[e_u_n].nu].rarity, card_info[e_u[e_u_n].nu].pos, card_info[e_u[e_u_n].nu].range, card_info[e_u[e_u_n].nu].dis, 920, 0, 0));
				e_pop++;
				e_u_n++;
			}
		int is_v = 0;

		for (int i = 0; i < pop; i++) {
			if (unit1[i].hp <= 0)
				continue;
			int find = 0;
			for (int j = 0; j < e_pop; j++) {
				if (unit1[i].dis == 1 && unit2[j].pos == 2)
					continue;
				if ((unit2[j].hp > 0) && (unit1[i].x + unit1[i].range >= unit2[j].x) && (unit1[i].x <= unit2[j].x)) {
					find++;
					unit1[i].isAttack = 1;
					wait[i] = (wait[i] + unit1[i].a_speed) % 12;
					unit1[i].count = wait[i] / 8;
					if (wait[i] == 8 || (unit1[i].a_speed == 3 && wait[i] == 9)) {
						unit2[j].hp -= unit1[i].atk;
					}
					break;
				}
			}

			if (find == 0 && (unit1[i].x + unit1[i].range >= 950)) {
				find++;
				unit1[i].isAttack = 1;
				wait[i] = (wait[i] + unit1[i].a_speed) % 12;
				unit1[i].count = wait[i] / 8;
				if (wait[i] == 8 || (unit1[i].a_speed == 3 && wait[i] == 9)) {
					castle2 -= unit1[i].atk;
					if (castle2 <= 0) {
						KillTimer(1);
						Invalidate(false);
						is_v = 1;
						break;
					}
				}
			}

			if (find == 0) {
				unit1[i].isAttack = 0;
				move[i] = (move[i] + 1) % 4;
				unit1[i].count = move[i] / 2;
				if (move[i] == 0 || move[i] == 2)
					unit1[i].x += unit1[i].m_speed;
				wait[i] = 0;
			}
		}

		if (is_v == 1) {
			is_v = 0;
			AfxMessageBox(L"Victory");

			if (stage == u_stage) {
				u_stage++;
				CStageDlg* parent =
					(CStageDlg*)GetParent();
				(parent->m_stage)++;
			}


			if (u_pack < 100)
				u_pack++;
			else
				AfxMessageBox(_T("카드팩은 100개까지 소지 가능합니다."));

			std::ofstream outfile("userinfo.txt");
			outfile << u_n << endl << u_stage << endl << u_pack;
			for (int fi = 0; fi < 26; fi++) {
				outfile << endl << u_card[fi][0] << " " << u_card[fi][1];
			}
			outfile.close();

			OnCancel();
		}

		int is_l = 0;

		for (int j = 0; j < e_pop; j++) {
			if (unit2[j].hp <= 0)
				continue;
			int find = 0;
			for (int i = 0; i < pop; i++) {
				if (unit2[j].dis == 1 && unit1[i].pos == 2)
					continue;
				if ((unit1[i].hp > 0) && (unit2[j].x - unit2[j].range <= unit1[i].x) && (unit2[j].x >= unit1[i].x)) {
					find++;
					unit2[j].isAttack = 1;
					wait2[j] = (wait2[j] + unit2[j].a_speed) % 12;
					unit2[j].count = wait2[j] / 8;
					if (wait2[j] == 8 || (unit2[j].a_speed == 3 && wait2[j] == 9)) {
						unit1[i].hp -= unit2[j].atk;
					}
					break;
				}
			}

			if (find == 0 && (unit2[j].x - unit2[j].range <= 70)) {
				find++;
				unit2[j].isAttack = 1;
				wait2[j] = (wait2[j] + unit2[j].a_speed) % 12;
				unit2[j].count = wait2[j] / 8;
				if (wait2[j] == 8 || (unit2[j].a_speed == 3 && wait2[j] == 9)) {
					castle1 -= unit2[j].atk;
					if (castle1 <= 0) {
						KillTimer(1);
						Invalidate(false);
						is_l = 1;
					}
				}
			}

			if (find == 0) {
				unit2[j].isAttack = 0;
				move2[j] = (move2[j] + 1) % 4;
				unit2[j].count = move2[j] / 2;
				if (move2[j] == 0 || move2[j] == 2)
					unit2[j].x -= unit2[j].m_speed;
				wait2[j] = 0;
			}
		}

		if (is_l == 1) {
			is_l = 0;
			AfxMessageBox(L"Lose");
			OnCancel();
		}


		for (int i = 0; i < pop; i++) {
			if (unit1[i].hp <= 0) {
				unit1.erase(unit1.begin() + i);
				i--;
				pop--;
			}
		}
		for (int j = 0; j < e_pop; j++) {
			if (unit2[j].hp <= 0) {
				unit2.erase(unit2.begin() + j);
				j--;
				e_pop--;
			}
		}
	}

	Invalidate(false);

	CDialog::OnTimer(nIDEvent);
}
