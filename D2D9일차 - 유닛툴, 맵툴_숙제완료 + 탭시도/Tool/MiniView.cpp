// MiniView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tool.h"
#include "MiniView.h"
#include "Device.h"
#include "MainFrm.h"
#include "ToolView.h"


// CMiniView

IMPLEMENT_DYNCREATE(CMiniView, CView)

CMiniView::CMiniView()
{

}

CMiniView::~CMiniView()
{
}

BEGIN_MESSAGE_MAP(CMiniView, CView)
END_MESSAGE_MAP()


// CMiniView �׸����Դϴ�.

void CMiniView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.

	CDevice::Get_Instance()->Render_Begin();

	// AfxGetMainWnd : ���� ������κ��� wnd�� ��ȯ�Ѵ�.
	// ���� �����尡 ���� �������� ��쿡 MainFrameWnd�� ��ȯ�ϰ� �Ǵµ� ���� �ٸ� �����尡 �����ǰ� �ִٸ� �߸��� ������ ��ȯ�� �� �ִ�.
	//CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());

	// AfxGetApp : ���� �����尡 ���� �ִ� ���� ���� app�� ��ȯ
	CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());

	// GetParentFrame : ���� view�� �ѷ��ΰ� �ִ� ���� FrameWnd�� ��ȯ
	// CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(GetParentFrame());

	CToolView*		pView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));
	CTerrain*		pTerrain = pView->Get_Terrain();

	pTerrain->Mini_Render();


	CDevice::Get_Instance()->Render_End(m_hWnd);

}


// CMiniView �����Դϴ�.

#ifdef _DEBUG
void CMiniView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMiniView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMiniView �޽��� ó�����Դϴ�.
