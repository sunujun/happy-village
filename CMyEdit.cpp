// CMyEdit.cpp: 구현 파일
//

#include "stdafx.h"
#include "main.h"
#include "CMyEdit.h"


// CMyEdit

IMPLEMENT_DYNAMIC(CMyEdit, CEdit)

CMyEdit::CMyEdit()
{

}

CMyEdit::~CMyEdit()
{
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CMyEdit 메시지 처리기




void CMyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if ((nChar >= '0'&&nChar <= '9') || (nChar >= 'a'&&nChar <= 'z') || nChar >= 'A'&&nChar <= 'Z' || nChar == 8)
	CEdit::OnChar(nChar, nRepCnt, nFlags);
}
