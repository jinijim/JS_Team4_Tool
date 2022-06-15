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
	for (int i = 0; i < 10; ++i)
	{
		m_PictureText[i] = (_T(""));
	}

	pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	pToolView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));
}

CTab1::~CTab1()
{
}

void CTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_PICTURE, m_TilePreview[0]);
	DDX_Control(pDX, IDC_PICTURE2, m_TilePreview[1]);
	DDX_Control(pDX, IDC_PICTURE3, m_TilePreview[2]);
	DDX_Control(pDX, IDC_PICTURE4, m_TilePreview[3]);
	DDX_Control(pDX, IDC_PICTURE5, m_TilePreview[4]);
	DDX_Control(pDX, IDC_PICTURE6, m_TilePreview[5]);
	DDX_Control(pDX, IDC_PICTURE7, m_TilePreview[6]);
	DDX_Control(pDX, IDC_PICTURE8, m_TilePreview[7]);
	DDX_Control(pDX, IDC_PICTURE9, m_TilePreview[8]);
	DDX_Control(pDX, IDC_PICTURE10, m_TilePreview[9]);
	DDX_Control(pDX, IDC_PICTURE11, m_TilePreview[10]);
	DDX_Control(pDX, IDC_PICTURE12, m_TilePreview[11]);
	DDX_Control(pDX, IDC_PICTURE13, m_TilePreview[12]);
	DDX_Control(pDX, IDC_PICTURE14, m_TilePreview[13]);
	DDX_Control(pDX, IDC_PICTURE15, m_TilePreview[14]);
	DDX_Control(pDX, IDC_PICTURE16, m_TilePreview[15]);
	DDX_Control(pDX, IDC_PICTURE17, m_TilePreview[16]);
	DDX_Control(pDX, IDC_PICTURE18, m_TilePreview[17]);
	DDX_Control(pDX, IDC_PICTURE19, m_TilePreview[18]);

	DDX_Text(pDX, IDC_EDIT2, m_PictureText[0]);
	DDX_Text(pDX, IDC_EDIT3, m_PictureText[1]);
	DDX_Text(pDX, IDC_EDIT4, m_PictureText[2]);
	DDX_Text(pDX, IDC_EDIT5, m_PictureText[3]);
	DDX_Text(pDX, IDC_EDIT7, m_PictureText[4]);
	DDX_Text(pDX, IDC_EDIT8, m_PictureText[5]);
	DDX_Text(pDX, IDC_EDIT9, m_PictureText[6]);
	DDX_Text(pDX, IDC_EDIT10, m_PictureText[7]);
	DDX_Text(pDX, IDC_EDIT11, m_PictureText[8]);
	DDX_Text(pDX, IDC_EDIT12, m_PictureText[9]);
	DDX_Text(pDX, IDC_EDIT13, m_PictureText[10]);
	DDX_Text(pDX, IDC_EDIT14, m_PictureText[11]);
	DDX_Text(pDX, IDC_EDIT15, m_PictureText[12]);
	DDX_Text(pDX, IDC_EDIT16, m_PictureText[13]);
	DDX_Text(pDX, IDC_EDIT17, m_PictureText[14]);
	DDX_Text(pDX, IDC_EDIT18, m_PictureText[15]);
	DDX_Text(pDX, IDC_EDIT19, m_PictureText[16]);
	DDX_Text(pDX, IDC_EDIT20, m_PictureText[17]);
	DDX_Text(pDX, IDC_EDIT21, m_PictureText[18]);
	DDX_Text(pDX, IDC_EDIT22, m_PictureText[19]);
}


BEGIN_MESSAGE_MAP(CTab1, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CTab1::OnButtonAddTile)
	ON_STN_CLICKED(IDC_PICTURE, &CTab1::OnStnClickedPicture)
	ON_STN_CLICKED(IDC_PICTURE2, &CTab1::OnStnClickedPicture2)
	ON_STN_CLICKED(IDC_PICTURE3, &CTab1::OnStnClickedPicture3)
	ON_STN_CLICKED(IDC_PICTURE4, &CTab1::OnStnClickedPicture4)
	ON_STN_CLICKED(IDC_PICTURE5, &CTab1::OnStnClickedPicture5)
	ON_STN_CLICKED(IDC_PICTURE6, &CTab1::OnStnClickedPicture6)
	ON_STN_CLICKED(IDC_PICTURE7, &CTab1::OnStnClickedPicture7)
	ON_STN_CLICKED(IDC_PICTURE8, &CTab1::OnStnClickedPicture8)
	ON_STN_CLICKED(IDC_PICTURE9, &CTab1::OnStnClickedPicture9)
	ON_STN_CLICKED(IDC_PICTURE10, &CTab1::OnStnClickedPicture10)
	ON_STN_CLICKED(IDC_PICTURE11, &CTab1::OnStnClickedPicture11)
	ON_STN_CLICKED(IDC_PICTURE12, &CTab1::OnStnClickedPicture12)
	ON_STN_CLICKED(IDC_PICTURE13, &CTab1::OnStnClickedPicture13)
	ON_STN_CLICKED(IDC_PICTURE14, &CTab1::OnStnClickedPicture14)
	ON_STN_CLICKED(IDC_PICTURE15, &CTab1::OnStnClickedPicture15)
	ON_STN_CLICKED(IDC_PICTURE16, &CTab1::OnStnClickedPicture16)
	ON_STN_CLICKED(IDC_PICTURE17, &CTab1::OnStnClickedPicture17)
	ON_STN_CLICKED(IDC_PICTURE18, &CTab1::OnStnClickedPicture18)
	ON_STN_CLICKED(IDC_PICTURE19, &CTab1::OnStnClickedPicture19)
	ON_STN_CLICKED(IDC_PICTURE20, &CTab1::OnStnClickedPicture20)
END_MESSAGE_MAP()


// CTab1 메시지 처리기입니다.


void CTab1::Draw_Picture()
{
	UpdateData(TRUE);

	int iIndex = 0;
	for (auto& _iter : *m_pMapPngImg)
	{
		m_PictureText[iIndex] = _iter.first;
		m_TilePreview[iIndex].SetBitmap(*(_iter).second);
		iIndex += 1;
	}

	UpdateData(FALSE);
}

void CTab1::OnButtonAddTile()
{
	if (nullptr == m_MapTool.GetSafeHwnd())
		m_MapTool.Create(IDD_MAPTOOL);	// 해당 ID에 맞는 다이얼로그 생성

	m_MapTool.ShowWindow(SW_SHOW);
}


void CTab1::OnStnClickedPicture()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[0];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture2()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[1];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture3()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[2];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture4()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[3];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture5()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[4];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture6()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[5];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture7()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[6];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture8()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[7];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture9()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[8];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture10()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[9];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture11()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[10];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture12()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[11];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture13()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[12];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture14()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[13];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture15()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[14];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}

void CTab1::OnStnClickedPicture16()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[15];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture17()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[16];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture18()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[17];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture19()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[18];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CTab1::OnStnClickedPicture20()
{
	UpdateData(TRUE);

	m_strFileName = m_PictureText[19];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}
