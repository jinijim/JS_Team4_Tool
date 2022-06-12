// Tab1.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Tool.h"
#include "Tab1.h"
#include "afxdialogex.h"


// CTab1 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTab1, CDialog)

CTab1::CTab1(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CTab1::~CTab1()
{
}

void CTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTab1, CDialog)
END_MESSAGE_MAP()


// CTab1 메시지 처리기입니다.
