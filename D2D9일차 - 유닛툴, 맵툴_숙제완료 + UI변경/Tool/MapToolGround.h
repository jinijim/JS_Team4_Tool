#pragma once
#include "afxwin.h"
#include "MapTool.h"



// CMapToolGround 폼 뷰입니다.

class CMapToolGround : public CFormView
{
	DECLARE_DYNCREATE(CMapToolGround)

protected:
	CMapToolGround();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CMapToolGround();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAPTOOLGROUND };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public :
	void	set_ImageMap(map<CString, CImage*>* _map) { m_pMapPngImg = _map; }

public:
	CStatic		m_TilePreview[10];
	afx_msg void OnButtonAddTile();


	map<CString, CImage*>*		m_pMapPngImg;

	CListBox	m_ListBox;
	CMapTool	m_MapTool;
	afx_msg void OnStnClickedPicture1();
	CString	m_strFileName;
	virtual void OnInitialUpdate();

	void		Draw_Picture();
	afx_msg void OnStnClickedPicture2();
	afx_msg void OnStnClickedPicture3();
	void		Set_PictureText();
	//CString		 m_PictureText;
	CString		m_PictureText[10];
	afx_msg void OnStnClickedPicture4();
	afx_msg void OnStnClickedPicture5();
	afx_msg void OnStnClickedPicture6();
	afx_msg void OnStnClickedPicture7();
	afx_msg void OnStnClickedPicture8();
	afx_msg void OnStnClickedPicture9();
	afx_msg void OnStnClickedPicture10();
};


