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
{
	for (int i = 0; i < 10; ++i)
	{
		m_PictureText[i] = (_T(""));
	}
}

CMapToolGround::~CMapToolGround()
{
	//for_each(m_pMapPngImg->begin(), m_pMapPngImg->end(), [](auto& Pair)
	//{
	//	Pair.second->Destroy();
	//	Safe_Delete<CImage*>(Pair.second);
	//});

	//m_pMapPngImg->clear();
}

void CMapToolGround::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
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

//	DDX_Control(pDX, IDC_EDIT2, m_PictureText);
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

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	//UpdateData(TRUE);

	//int iIndex = 0;
	//for (auto& _iter : *m_pMapPngImg)
	//{
	//	m_TilePreview[iIndex].SetBitmap(*(_iter).second);
	//}

	//UpdateData(FALSE);

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
