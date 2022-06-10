#pragma once
#include "afxwin.h"


// CMapTool ��ȭ �����Դϴ�.

class CMapTool : public CDialog
{
	DECLARE_DYNAMIC(CMapTool)

public:
	CMapTool(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMapTool();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAPTOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public : 
	CString	Get_FileName() { return m_strFileName; }
	map<CString, CImage*>*	Get_ImageMap() { return &m_MapPngImg; }

public:
	afx_msg void OnListBox();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnButtonSelectTileImage();

public:
	void		Horizontal_Scroll(void);

public:
	// control
	CListBox m_ListBox;

	//CImage : jpeg, gif, bmp, png ������ �����ϴ� Ŭ����
	map<CString, CImage*>		m_MapPngImg;
	
	CStatic m_Picture;

	CString	m_strFileName;
};
