#pragma once
#include "afxwin.h"


// CMapTool 대화 상자입니다.

class CMapTool : public CDialog
{
	DECLARE_DYNAMIC(CMapTool)

public:
	CMapTool(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMapTool();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAPTOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public : 
	CString	Get_FileName() { return m_strFileName; }
	map<CString, CImage*>*	Get_ImageMap() { return &m_MapPngImg; }

public:
	afx_msg void OnListBox();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnButtonSelectTileImage();
	afx_msg void OnSaveData();

public:
	void		Horizontal_Scroll(void);

public:
	// control
	CListBox m_ListBox;

	//CImage : jpeg, gif, bmp, png 형식을 지원하는 클래스
	map<CString, CImage*>		m_MapPngImg;
	
	CStatic m_Picture;

	CString	m_strFileName;
};
