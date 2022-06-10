// MapTool.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tool.h"
#include "MapTool.h"
#include "afxdialogex.h"

#include "FileInfo.h"
#include "MainFrm.h"
#include "ToolView.h"
#include "MapToolGround.h"


// CMapTool ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CMapTool, CDialog)

CMapTool::CMapTool(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MAPTOOL, pParent)
{
}

CMapTool::~CMapTool()
{
	for_each(m_MapPngImg.begin(), m_MapPngImg.end(), [](auto& Pair)
	{
		Pair.second->Destroy();
		Safe_Delete<CImage*>(Pair.second);
	});

	m_MapPngImg.clear();
}

void CMapTool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_PICTURE, m_Picture);
}


BEGIN_MESSAGE_MAP(CMapTool, CDialog)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMapTool::OnListBox)
	ON_WM_DROPFILES()
	ON_BN_CLICKED(IDOK, &CMapTool::OnButtonSelectTileImage)
END_MESSAGE_MAP()


// CMapTool �޽��� ó�����Դϴ�.


void CMapTool::OnListBox()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CString		strSelectName;

	int iSelect = m_ListBox.GetCurSel();

	m_ListBox.GetText(iSelect, strSelectName);

	auto	iter = m_MapPngImg.find(strSelectName);

	if (iter == m_MapPngImg.end())
		return;

	m_Picture.SetBitmap(*(iter->second));


	UpdateData(FALSE);
}


void CMapTool::OnDropFiles(HDROP hDropInfo)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	UpdateData(TRUE);

	CDialog::OnDropFiles(hDropInfo);

	TCHAR		szFilePath[MAX_PATH] = L"";
	TCHAR		szFileName[MAX_STR] = L"";

	// DragQueryFile : ��ӵ� ������ ������ ������ �Լ�(0�� ���ؽ��� �ش��ϴ� ������ ��ü ��θ� ���´�)
	// �ι�° ���ڰ� 0xffffffff(-1)�� �����ϸ� ��ӵ� ������ ������ ��ȯ

	int			iFileCnt = DragQueryFile(hDropInfo, 0xffffffff, nullptr, 0);

	for(int i = 0; i < iFileCnt; ++i)
	{
		DragQueryFile(hDropInfo, i, szFilePath, MAX_PATH);

		CString	strRelative = CFileInfo::ConvertRelativePath(szFilePath);

		// PathFindFileName : ��� �� ���� �̸��� ����� ��� �����ϴ� �Լ�
		CString	strFileName = PathFindFileName(strRelative);

		lstrcpy(szFileName, strFileName.GetString());

		// ������ Ȯ���� ���� �����ϴ� �Լ�
		PathRemoveExtension(szFileName);

		strFileName = szFileName;

		auto	iter = m_MapPngImg.find(strFileName);

		if (iter == m_MapPngImg.end())
		{
			CImage*		pPngImg = new CImage;

			pPngImg->Load(strRelative);	// �ش� ����� �̹��� �ε�

			m_MapPngImg.insert({ strFileName, pPngImg });
			m_ListBox.AddString(szFileName);
		}
	}
	
	Horizontal_Scroll();

	UpdateData(FALSE);
}

void CMapTool::Horizontal_Scroll(void)
{

	CString		strName;
	CSize		size;

	int		iWidth = 0;

	// ����Ʈ �ڽ� ���� DC��� ����̱� ������ ȭ�� DC�� ���� �� �ִ�.
	CDC*		pDC = m_ListBox.GetDC();

	// GetCount : ����Ʈ �ڽ��� �ִ� ����� ���� ��ȯ
	for (int i = 0; i < m_ListBox.GetCount(); ++i)
	{
		m_ListBox.GetText(i, strName);

		// ���� ���ڿ��� ���̸� �ȼ� ������ ��ȯ
		size = pDC->GetTextExtent(strName);

		if (size.cx > iWidth)
			iWidth = size.cx;
	}

	m_ListBox.ReleaseDC(pDC);

	// GetHorizontalExtent : ����Ʈ �ڽ��� ���η� ��ũ�� �� �� �ִ� �ִ� ������ ������ �Լ�
	if (iWidth > m_ListBox.GetHorizontalExtent())
		m_ListBox.SetHorizontalExtent(iWidth);

}


void CMapTool::OnButtonSelectTileImage()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialog::OnOK();
	UpdateData(TRUE);

	int iIndex = m_ListBox.GetCurSel();
	m_ListBox.GetText(iIndex, m_strFileName);


	CMainFrame*		pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CToolView*		pToolView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));

	pToolView->Set_TileName(m_strFileName);
	pToolView->Set_DrawID();


	// ��ġ Ȯ�� �ʿ�
	//CMainFrame*			pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CMapToolGround*		pMapToolGround = dynamic_cast<CMapToolGround*>(pMainFrm->m_SecondSplitter.GetPane(2, 0));
	//m_pMapPngImg = pMapToolGround->Get_ImageMap();
	pMapToolGround->set_ImageMap(&m_MapPngImg);
	pMapToolGround->Draw_Picture();

	UpdateData(FALSE);
}
