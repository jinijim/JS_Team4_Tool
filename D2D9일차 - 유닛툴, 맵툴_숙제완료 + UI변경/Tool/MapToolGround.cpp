// MapToolGround.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Tool.h"
#include "MapToolGround.h"
#include "MainFrm.h"
#include "ToolView.h"

// CMapToolGround

IMPLEMENT_DYNCREATE(CMapToolGround, CFormView)

CMapToolGround::CMapToolGround()
	: CFormView(IDD_MAPTOOLGROUND)
	, m_pTabDialog1(NULL)
	, m_pTabDialog2(NULL)
{
	for (int i = 0; i < 10; ++i)
	{
		m_PictureText[i] = (_T(""));
	}
}

CMapToolGround::~CMapToolGround()
{
	Safe_Delete(m_pTabDialog1);
	Safe_Delete(m_pTabDialog2);
}

void CMapToolGround::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_TAB1, m_Tab);
}

BEGIN_MESSAGE_MAP(CMapToolGround, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMapToolGround::OnButtonAddTile)
	ON_STN_CLICKED(IDC_PICTURE, &CMapToolGround::OnStnClickedPicture1)
	ON_STN_CLICKED(IDC_PICTURE2, &CMapToolGround::OnStnClickedPicture2)
	ON_STN_CLICKED(IDC_PICTURE3, &CMapToolGround::OnStnClickedPicture3)
	ON_STN_CLICKED(IDC_PICTURE4, &CMapToolGround::OnStnClickedPicture4)
	ON_STN_CLICKED(IDC_PICTURE5, &CMapToolGround::OnStnClickedPicture5)
	ON_STN_CLICKED(IDC_PICTURE6, &CMapToolGround::OnStnClickedPicture6)
	ON_STN_CLICKED(IDC_PICTURE7, &CMapToolGround::OnStnClickedPicture7)
	ON_STN_CLICKED(IDC_PICTURE8, &CMapToolGround::OnStnClickedPicture8)
	ON_STN_CLICKED(IDC_PICTURE9, &CMapToolGround::OnStnClickedPicture9)
	ON_STN_CLICKED(IDC_PICTURE10, &CMapToolGround::OnStnClickedPicture10)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMapToolGround::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CMapToolGround 진단입니다.

#ifdef _DEBUG
void CMapToolGround::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMapToolGround::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMapToolGround 메시지 처리기입니다.


void CMapToolGround::OnButtonAddTile()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (nullptr == m_MapTool.GetSafeHwnd())
		m_MapTool.Create(IDD_MAPTOOL);	// 해당 ID에 맞는 다이얼로그 생성

	m_MapTool.ShowWindow(SW_SHOW);
}


void CMapToolGround::OnStnClickedPicture1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CToolView*		pToolView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));
	
	m_strFileName = m_PictureText[0];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CMapToolGround::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	m_Tab.DeleteAllItems();
	m_Tab.InsertItem(0, L"Tile");
	m_Tab.InsertItem(1, L"Object");

	CRect rect;

	m_pTabDialog1 = new CTab1;
	m_pTabDialog1->Create(IDD_DIALOG1, &m_Tab);
	m_pTabDialog1->GetWindowRect(&rect);
	m_pTabDialog1->MoveWindow(5, 25, rect.Width(), rect.Height());
	m_pTabDialog1->ShowWindow(SW_SHOW);


	m_pTabDialog2 = new CTab2;
	m_pTabDialog2->Create(IDD_DIALOG2, &m_Tab);
	m_pTabDialog2->GetWindowRect(&rect);
	m_pTabDialog2->MoveWindow(5, 25, rect.Width(), rect.Height());
	//m_pTabDialog2->ShowWindow(SW_SHOW);	// 탭2를 SHOW 해버리면 탭1이 처음에 가려짐

}

void CMapToolGround::Draw_Picture()
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


void CMapToolGround::OnStnClickedPicture2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CToolView*		pToolView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));

	m_strFileName = m_PictureText[1];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CMapToolGround::OnStnClickedPicture3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CToolView*		pToolView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));

	m_strFileName = m_PictureText[2];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CMapToolGround::OnStnClickedPicture4()
{
	UpdateData(TRUE);

	CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CToolView*		pToolView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));

	m_strFileName = m_PictureText[3];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CMapToolGround::OnStnClickedPicture5()
{
	UpdateData(TRUE);

	CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CToolView*		pToolView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));

	m_strFileName = m_PictureText[4];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CMapToolGround::OnStnClickedPicture6()
{
	UpdateData(TRUE);

	CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CToolView*		pToolView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));

	m_strFileName = m_PictureText[5];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CMapToolGround::OnStnClickedPicture7()
{
	UpdateData(TRUE);

	CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CToolView*		pToolView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));

	m_strFileName = m_PictureText[6];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CMapToolGround::OnStnClickedPicture8()
{
	UpdateData(TRUE);

	CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CToolView*		pToolView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));

	m_strFileName = m_PictureText[7];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CMapToolGround::OnStnClickedPicture9()
{
	UpdateData(TRUE);

	CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CToolView*		pToolView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));

	m_strFileName = m_PictureText[8];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CMapToolGround::OnStnClickedPicture10()
{
	UpdateData(TRUE);

	CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CToolView*		pToolView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));

	m_strFileName = m_PictureText[9];
	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();

	UpdateData(FALSE);
}


void CMapToolGround::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int select = m_Tab.GetCurSel();

	switch (select)
	{
	case 0:
		m_pTabDialog1->ShowWindow(SW_SHOW);
		m_pTabDialog2->ShowWindow(SW_HIDE);
		break;
	case 1:
		m_pTabDialog1->ShowWindow(SW_HIDE);
		m_pTabDialog2->ShowWindow(SW_SHOW);
		break;
	}
	*pResult = 0;
}
