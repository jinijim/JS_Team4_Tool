
// ToolView.cpp : CToolView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Tool.h"
#endif

#include "ToolDoc.h"
#include "ToolView.h"
#include "TextureMgr.h"
#include "MainFrm.h"
#include "MiniView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HWND		g_hWnd;


// CToolView

IMPLEMENT_DYNCREATE(CToolView, CScrollView)

BEGIN_MESSAGE_MAP(CToolView, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)


	ON_WM_LBUTTONDOWN()
	ON_WM_DESTROY()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CToolView ����/�Ҹ�

CToolView::CToolView()
	: m_pDevice(CDevice::Get_Instance())
	, m_ByDrawID(1)
	//, m_pSingle(nullptr)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CToolView::~CToolView()
{
	//Safe_Delete(m_pSingle);
	
}

void CToolView::Set_DrawID()
{
	CString strNumber(_T(""));
	for (int i = 0; i < m_strFileName.GetLength(); i++)
	{
		char ch = m_strFileName.GetAt(i);
		if (ch >= '0' && ch <= '9')
			strNumber += ch;
	}
	int temp = _ttoi(strNumber);
	m_ByDrawID = temp;
}

void CToolView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// SetScrollSizes: ��ũ�� ���� ����� �����ϴ� CScrollView�� ��� �Լ�
	// MM_TEXT : �ȼ� ������ ũ�⸦ �����ϰڴٴ� �ɼ�
	// CSize : ��ũ�� ����, ���� ������

	//CSize : mfc���� �����ϴ� ������� ���õ� �����͸� �����ϴ� Ŭ����

	SetScrollSizes(MM_TEXT, CSize(TILECX * TILEX, TILECY * TILEY / 2));

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	// AfxGetMainWnd : ���� ���� �����츦 ��ȯ�ϴ� ���� �Լ�
	// �θ�Ÿ���� ��ȯ�ϱ⿡ �ڽ� Ÿ������ �� ��ȯ�Ͽ� ���
	CMainFrame*		pMainFrm = (CMainFrame*)AfxGetMainWnd();

	RECT		rcWnd{};

	// GetWindowRect : ���� �������� RECT ������ ���� ������ִ� �Լ�
	pMainFrm->GetWindowRect(&rcWnd);

	// SetRect : ������ �μ��� RECT�� ������ ������ִ� �Լ�
	// ���� 0, 0 ��ǥ �������� �ٽ� RECT�� �����ϰ� �ִ�.
	SetRect(&rcWnd, 0, 0, rcWnd.right - rcWnd.left, rcWnd.bottom - rcWnd.top);

	RECT	rcMainView{};

	//GetClientRect : ���� viewâ�� RECT ������ ������ �Լ�
	GetClientRect(&rcMainView);

	// ���� â�� Viewâ�� ����, ���� ����� ���� ������ ����, ������ ���͹��� ����

	float	fRowFrm = float(rcWnd.right - rcMainView.right);
	float	fColFrm = float(rcWnd.bottom - rcMainView.bottom);

	//SetWindowPos : �μ���� ���Ӱ� ������ ��ġ�� ũ�⸦ �����ϴ� �Լ�
	// 1���� : ���� ������ ���ΰ�?
	// SWP_NOZORDER : ���� ������ �����ϰڴٴ� �÷���

	pMainFrm->SetWindowPos(nullptr, 0, 0, int(WINCX + fRowFrm), int(WINCY + fColFrm), SWP_NOZORDER);


	g_hWnd = m_hWnd;

	if (FAILED(m_pDevice->Initialize()))
	{
		AfxMessageBox(L"m_pDevice ���� ����");
		return;
	}

	if (FAILED(CTextureMgr::Get_Instance()->InsertTexture(L"../Texture/Cube.png", TEX_SINGLE, L"Cube")))
	{
		AfxMessageBox(L"Cube Image Insert failed");
		return;
	}

	m_pTerrain = new CTerrain;
	m_pTerrain->Initialize();
	m_pTerrain->Set_MainView(this);

}

// CToolView �׸���

void CToolView::OnDraw(CDC* /*pDC*/)
{
	CToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

	//pDC->Rectangle(100, 100, 200, 200);

#pragma region ����

	/*D3DXMATRIX		matWorld, matScale, matRotZ, matTrans;

	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(45.f));
	D3DXMatrixTranslation(&matTrans, 400.f, 300.f, 0.f);

	matWorld = matScale *  matTrans;

	CDevice::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);

	/ *float		fX = m_pSingle->Get_Texture()->tImgInfo.Width / 2.f;
	float		fY = m_pSingle->Get_Texture()->tImgInfo.Height / 2.f;* /

	//const TEXINFO*		pTexInfo = CTextureMgr::Get_Instance()->Get_Texture(L"Cube");

	const TEXINFO*		pTexInfo = CTextureMgr::Get_Instance()->Get_Texture(L"Terrain", L"Tile", 2);

	if (nullptr == pTexInfo)
		return;

	float		fX = pTexInfo->tImgInfo.Width / 2.f;
	float		fY = pTexInfo->tImgInfo.Height / 2.f;

	m_pDevice->Render_Begin();

	m_pDevice->Get_Sprite()->Draw(pTexInfo->pTexture,	// �׸����� �ϴ� �ؽ�ó
		nullptr, // ����� �̹��� ������ ���� rect ������, null�� ��� �̹����� 0, 0 �������� ���
		&D3DXVECTOR3(fX, fY, 0.f), // ����� �̹��� �߽� �࿡ ���� vec3 ����ü ������, null�� ��� 0, 0�� �߽� ��ǥ
		nullptr, // ��ġ ��ǥ�� ���� vec3 ����ü ������, null�� ��� ��ũ�� �� 0,0 ��ǥ�� ���
		D3DCOLOR_ARGB(255, 255, 255, 255)); //����� ���� �̹����� ���� ���� ��, ��� �� ���� ������ �ݿ�, 0xffffffff�� �Ѱ��ָ� ���� ���� ������ ���·� ���

	m_pDevice->Render_End();*/

#pragma endregion ����


	m_pDevice->Render_Begin();

	m_pTerrain->Render();
	
	m_pDevice->Render_End();

	
}

#pragma region ���ʿ�
BOOL CToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}


BOOL CToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CToolView ����

#ifdef _DEBUG
void CToolView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CToolView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CToolDoc* CToolView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolDoc)));
	return (CToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CToolView �޽��� ó����
#pragma endregion ���ʿ�

// CToolView �μ�


void CToolView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.



	CScrollView::OnLButtonDown(nFlags, point);

	m_pTerrain->Tile_Change(D3DXVECTOR3(float(point.x + GetScrollPos(0)), float(point.y + GetScrollPos(1)), 0.f), m_ByDrawID);

	// Invalidate : ȣ�� �� �����쿡 WM_PAINT�� WM_ERASEBKGND �޼����� �߻���Ŵ, �̶� OnDraw �Լ��� �ٽ� �� �� ȣ���ϰ� �ȴ�.

	/*�Ű� ������ FALSE �� �� : WM_PAINT�� �߻�
	�Ű� ������ TRUE �� �� : WM_PAINT�� WM_ERASEBKGND ���� �߻�

	WM_ERASEBKGND  : ����� ����� �޼���*/

	Invalidate(FALSE);


	CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CMiniView*		pMiniView = dynamic_cast<CMiniView*>(pMainFrm->m_SecondSplitter.GetPane(0, 0));

	pMiniView->Invalidate(FALSE);


}
void CToolView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CScrollView::OnMouseMove(nFlags, point);

	if (GetAsyncKeyState(VK_LBUTTON))
	{
		m_pTerrain->Tile_Change(D3DXVECTOR3(float(point.x + GetScrollPos(0)), float(point.y + GetScrollPos(1)), 0.f), m_ByDrawID);
		Invalidate(FALSE);

		CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
		CMiniView*		pMiniView = dynamic_cast<CMiniView*>(pMainFrm->m_SecondSplitter.GetPane(0, 0));

		pMiniView->Invalidate(FALSE);

	}


}


void CToolView::OnDestroy()
{
	CScrollView::OnDestroy();


	Safe_Delete<CTerrain*>(m_pTerrain);
	CTextureMgr::Get_Instance()->Destroy_Instance();
	m_pDevice->Destroy_Instance();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


