// Tab2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Tool.h"
#include "Tab2.h"
#include "afxdialogex.h"


// CTab2 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTab2, CDialog)

CTab2::CTab2(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

CTab2::~CTab2()
{
}

void CTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTab2, CDialog)
END_MESSAGE_MAP()


// CTab2 메시지 처리기입니다.
