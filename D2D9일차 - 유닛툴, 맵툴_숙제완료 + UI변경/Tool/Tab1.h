#pragma once
#include "Resource.h"
#include "MapTool.h"
#include "MainFrm.h"
#include "ToolView.h"
#include "afxwin.h"

// CTab1 대화 상자입니다.

class CTab1 : public CDialog
{
	DECLARE_DYNAMIC(CTab1)

public:
	CTab1(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTab1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	void		set_ImageMap(map<CString, CImage*>* _map) { m_pMapPngImg = _map; }
	void		Draw_Picture();

public:
	afx_msg void OnButtonAddTile();
	afx_msg void OnStnClickedPicture();
	afx_msg void OnStnClickedPicture2();
	afx_msg void OnStnClickedPicture3();
	afx_msg void OnStnClickedPicture4();
	afx_msg void OnStnClickedPicture5();
	afx_msg void OnStnClickedPicture6();
	afx_msg void OnStnClickedPicture7();
	afx_msg void OnStnClickedPicture8();
	afx_msg void OnStnClickedPicture9();
	afx_msg void OnStnClickedPicture10();

public:

	CStatic		m_TilePreview[20];
	CString		m_PictureText[20];

	map<CString, CImage*>*		m_pMapPngImg;

	CMapTool	m_MapTool;

	CMainFrame*		pMainFrm;
	CToolView*		pToolView;
	CString			m_strFileName;
	
	
	CEdit m_PictureText1;
	afx_msg void OnStnClickedPicture11();
	afx_msg void OnStnClickedPicture12();
	afx_msg void OnStnClickedPicture13();
	afx_msg void OnStnClickedPicture14();
	afx_msg void OnStnClickedPicture15();
	afx_msg void OnStnClickedPicture16();
	afx_msg void OnStnClickedPicture17();
	afx_msg void OnStnClickedPicture18();
	afx_msg void OnStnClickedPicture19();
	afx_msg void OnStnClickedPicture20();
};
