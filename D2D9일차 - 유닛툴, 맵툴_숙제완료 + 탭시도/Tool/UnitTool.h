#pragma once
#include "afxwin.h"

#include "Include.h"

// CUnitTool ��ȭ �����Դϴ�.

class CUnitTool : public CDialog
{
	DECLARE_DYNAMIC(CUnitTool)

public:
	CUnitTool(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CUnitTool();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UNITTOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:

	virtual BOOL OnInitDialog();

	afx_msg void OnPushString();
	afx_msg void OnAdd_Charactor();
	afx_msg void OnListBox();
	afx_msg void OnDestroy();
	afx_msg void OnDeleteData();
	afx_msg void OnSearchData();

public:
	// value
	CString m_strTemp;
	CString m_strCopy;
	CString m_strName;
	CString m_strSearchData;

	int m_iHp;
	int m_iAttack;

	// control
	CListBox m_ListBox;
	CButton m_Radio[3];
	CButton m_Check[3];
	CButton m_Bitmap;

	// general
	map<CString, UNITDATA*>			m_MapUnitData;


	afx_msg void OnSaveData();
	afx_msg void OnLoadData();
};

// ����, �ҷ�����, ����
// �˻� : ����Ʈ ��Ʈ�ѷ� ���ڿ��� �Է¹����� ����Ʈ �ڽ��� �ش� ���� ���õǾ������� ������