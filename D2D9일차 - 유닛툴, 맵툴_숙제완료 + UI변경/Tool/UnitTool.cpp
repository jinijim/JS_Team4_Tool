// UnitTool.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tool.h"
#include "UnitTool.h"
#include "afxdialogex.h"


// CUnitTool ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CUnitTool, CDialog)

CUnitTool::CUnitTool(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_UNITTOOL, pParent)
	, m_strTemp(_T(""))
	, m_strCopy(_T(""))
	, m_strName(_T(""))
	, m_iHp(0)
	, m_iAttack(0)
	, m_strSearchData(_T(""))
{

}

CUnitTool::~CUnitTool()
{
}

void CUnitTool::DoDataExchange(CDataExchange* pDX)
{
	// DoDataExchange : UpdateData�Լ��� ȣ���� ������ �ڵ�ȣ��Ǵ� �Լ�


	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, m_strTemp);
	DDX_Text(pDX, IDC_EDIT2, m_strCopy);
	DDX_Text(pDX, IDC_EDIT3, m_strName);
	DDX_Text(pDX, IDC_EDIT4, m_iHp);
	DDX_Text(pDX, IDC_EDIT5, m_iAttack);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_RADIO1, m_Radio[0]);
	DDX_Control(pDX, IDC_RADIO2, m_Radio[1]);
	DDX_Control(pDX, IDC_RADIO3, m_Radio[2]);

	DDX_Control(pDX, IDC_CHECK1, m_Check[0]);
	DDX_Control(pDX, IDC_CHECK2, m_Check[1]);
	DDX_Control(pDX, IDC_CHECK3, m_Check[2]);
	DDX_Control(pDX, IDC_BUTTON3, m_Bitmap);
	DDX_Text(pDX, IDC_EDIT6, m_strSearchData);
}


BEGIN_MESSAGE_MAP(CUnitTool, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CUnitTool::OnPushString)
	ON_BN_CLICKED(IDC_BUTTON2, &CUnitTool::OnAdd_Charactor)
	ON_LBN_SELCHANGE(IDC_LIST1, &CUnitTool::OnListBox)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON4, &CUnitTool::OnDeleteData)
	ON_EN_CHANGE(IDC_EDIT6, &CUnitTool::OnSearchData)
	ON_BN_CLICKED(IDC_BUTTON5, &CUnitTool::OnSaveData)
	ON_BN_CLICKED(IDC_BUTTON6, &CUnitTool::OnLoadData)
END_MESSAGE_MAP()


// CUnitTool �޽��� ó�����Դϴ�.


void CUnitTool::OnPushString()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	UpdateData(TRUE);  // ���̾�α� �ڽ��κ��� �Է��� ������ ����
		
	m_strCopy = m_strTemp;

	UpdateData(FALSE);  // ������ ����� ������ ���̾�α� �ڽ��� �ݿ�

}


void CUnitTool::OnAdd_Charactor()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	UNITDATA*		pUnit = new UNITDATA;

	pUnit->strName = m_strName;
	pUnit->iAttack = m_iAttack;
	pUnit->iHp = m_iHp;

	for (int i = 0; i < 3; ++i)
	{
		// GetCheck : ���� ���� ��ư�� üũ�Ǿ��ִ��� ���� �Ǵ�
		if (m_Radio[i].GetCheck())
		{
			pUnit->byJobIndex = i;
			break;
		}
	}

	pUnit->byItem = 0x00;

	if (m_Check[0].GetCheck())
		pUnit->byItem |= RUBY;

	if (m_Check[1].GetCheck())
		pUnit->byItem |= DIAMOND;

	if (m_Check[2].GetCheck())
		pUnit->byItem |= SAPPHIRE;



	// AddString : ����Ʈ �ڽ��� ���ڿ��� �߰� ��
	m_ListBox.AddString(pUnit->strName);

	m_MapUnitData.insert({pUnit->strName, pUnit});

	UpdateData(FALSE);
}


void CUnitTool::OnListBox()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CString		strFindName;

	// GetCurSel : ���� ����Ʈ �ڽ����� ���õ� ���� �ε��� ���� ��ȯ
	int iSelect = m_ListBox.GetCurSel();

	// GetText : ���� �ε����� �ش��ϴ� ���ڿ��� ����Ʈ �ڽ��κ��� ����
	m_ListBox.GetText(iSelect, strFindName);

	auto	iter = m_MapUnitData.find(strFindName);

	if (iter == m_MapUnitData.end())
		return;

	m_strName = iter->second->strName;
	m_iAttack = iter->second->iAttack;
	m_iHp = iter->second->iHp;

	for (int i = 0; i < 3; ++i)
		m_Radio[i].SetCheck(FALSE);	// ��� ���� ��ư üũ ����

	m_Radio[iter->second->byJobIndex].SetCheck(TRUE);

	for (int i = 0; i < 3; ++i)
		m_Check[i].SetCheck(FALSE);


	if (iter->second->byItem & RUBY)
		m_Check[0].SetCheck(TRUE);

	if (iter->second->byItem & DIAMOND)
		m_Check[1].SetCheck(TRUE);

	if (iter->second->byItem & SAPPHIRE)
		m_Check[2].SetCheck(TRUE);


	UpdateData(FALSE);
}


void CUnitTool::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	for_each(m_MapUnitData.begin(), m_MapUnitData.end(), CDeleteMap());
	m_MapUnitData.clear();

}


BOOL CUnitTool::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_Radio[0].SetCheck(TRUE);

	HBITMAP		hBitMap = (HBITMAP)LoadImage(nullptr, L"../Texture/JusinLogo1.bmp", IMAGE_BITMAP, 100, 50, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	m_Bitmap.SetBitmap(hBitMap);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CUnitTool::OnDeleteData()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CString		strFineName = L"";

	int		iSelect = m_ListBox.GetCurSel();

	if (LB_ERR == iSelect)
		return;

	m_ListBox.GetText(iSelect, strFineName);

	auto&	iter = m_MapUnitData.find(strFineName);

	if (iter == m_MapUnitData.end())
		return;

	Safe_Delete<UNITDATA*>(iter->second);
	m_MapUnitData.erase(strFineName);

	// �ε����� �ش��ϴ� ����Ʈ �ڽ� �� ���ڿ��� ����
	m_ListBox.DeleteString(iSelect);
	
	UpdateData(FALSE);
}


void CUnitTool::OnSearchData()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	auto&		iter = m_MapUnitData.find(m_strSearchData);

	if (iter == m_MapUnitData.end())
		return;

	// FindString : edit control�� �Էµ� ���ڿ��� ��ġ�ϴ� ����Ʈ �ڽ��� ���ڿ��� ã�Ƽ� �� �ε��� ���� ��ȯ
	int	iIndex = m_ListBox.FindString(0, m_strSearchData);

	if (LB_ERR == iIndex)
		return;

	// ���� �ε����� ���õǵ��� �� ��ġ�� ����
	m_ListBox.SetCurSel(iIndex);

	m_strName = iter->second->strName;
	m_iAttack = iter->second->iAttack;
	m_iHp = iter->second->iHp;

	for (int i = 0; i < 3; ++i)
		m_Radio[i].SetCheck(FALSE);	// ��� ���� ��ư üũ ����

	m_Radio[iter->second->byJobIndex].SetCheck(TRUE);

	for (int i = 0; i < 3; ++i)
		m_Check[i].SetCheck(FALSE);

	if (iter->second->byItem & RUBY)
		m_Check[0].SetCheck(TRUE);

	if (iter->second->byItem & DIAMOND)
		m_Check[1].SetCheck(TRUE);

	if (iter->second->byItem & SAPPHIRE)
		m_Check[2].SetCheck(TRUE);

	UpdateData(FALSE);
}


void CUnitTool::OnSaveData()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	// CFileDialog : ���� ���� �Ǵ� ���� �۾��� �ʿ��� ��ȭ���ڸ� �����ϴ� ��ü
/*

	1. TRUE(����), FALSE(�ٸ� �̸����� ����) ��� ����
	2. L"dat" : default ���� Ȯ���� ��, ���� �� Ȯ����� ��� �����ָ� ���⼭ ������ Ȯ����� ���
	3. ��ȭ ���ڿ� ǥ�õ� ���� ���ϸ�
	4. OFN_HIDEREADONLY : �б����� üũ�ڽ� ����, OFN_OVERWRITEPROMPT : �ߺ����� ���� �� ��� �޼��� ����
	5. ��ȭ ���ڿ� ǥ���� ���� ���� "�޺� �ڽ��� ��µ� ���ڿ� | ���� ����� ���͸� ���ڿ� ||"
	6. �θ� ������ �ּ�*/

	CFileDialog		Dlg(FALSE,
						L"dat",
						L"*.dat", 
						OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
						L"Data Files(*.dat)|*.dat||", 
						this);

	TCHAR	szPath[MAX_PATH] = L"";

	// ���� ������Ʈ ��θ� ������ �Լ�
	GetCurrentDirectory(MAX_PATH, szPath);


	// ��ü ��ο��� ���� �̸��� �߶��ִ� �Լ�, ���� ��� �� ���ϸ��� ���ٸ� ���� ������ �������� �߶󳽴�.
	PathRemoveFileSpec(szPath);

	// data �������� �߶� ��ο� �ռ�
	lstrcat(szPath, L"\\Data");

	// ��ȭ���ڸ� ������ �� ���̴� �⺻ ��η� ����
	Dlg.m_ofn.lpstrInitialDir = szPath;


	if (IDOK == Dlg.DoModal())
	{
		// GetPathName : ���õ� ��θ� ��ȯ
		CString		str = Dlg.GetPathName();

		// GetString ���� ���ڿ��� ��ȯ�ϴ� �Լ�
		const TCHAR* pGetPath = str.GetString();

		HANDLE		hFile = CreateFile(pGetPath, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

		if (INVALID_HANDLE_VALUE == hFile)
			return;

		DWORD	dwStrByte = 0;
		DWORD	dwByte = 0;

		for (auto& Pair : m_MapUnitData)
		{
			// key�� ����
			dwStrByte = sizeof(TCHAR) * (Pair.first.GetLength() + 1);

			WriteFile(hFile, &dwStrByte, sizeof(DWORD), &dwByte, nullptr);
			WriteFile(hFile, Pair.first.GetString(), dwStrByte, &dwByte, nullptr);

			// value ����

			WriteFile(hFile, &(Pair.second->byItem), sizeof(BYTE), &dwByte, nullptr);
			WriteFile(hFile, &(Pair.second->byJobIndex), sizeof(BYTE), &dwByte, nullptr);
			WriteFile(hFile, &(Pair.second->iHp), sizeof(int), &dwByte, nullptr);
			WriteFile(hFile, &(Pair.second->iAttack), sizeof(int), &dwByte, nullptr);

		}

		CloseHandle(hFile);
	}

}


void CUnitTool::OnLoadData()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	UpdateData(TRUE);

	CFileDialog		Dlg(TRUE,
		L"dat",
		L"*.dat",
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		L"Data Files(*.dat)|*.dat||",
		this);

	TCHAR	szPath[MAX_PATH] = L"";

	// ���� ������Ʈ ��θ� ������ �Լ�
	GetCurrentDirectory(MAX_PATH, szPath);


	// ��ü ��ο��� ���� �̸��� �߶��ִ� �Լ�, ���� ��� �� ���ϸ��� ���ٸ� ���� ������ �������� �߶󳽴�.
	PathRemoveFileSpec(szPath);

	// data �������� �߶� ��ο� �ռ�
	lstrcat(szPath, L"\\Data");

	// ��ȭ���ڸ� ������ �� ���̴� �⺻ ��η� ����
	Dlg.m_ofn.lpstrInitialDir = szPath;


	if (IDOK == Dlg.DoModal())
	{
		for (auto& Pair : m_MapUnitData)
			delete Pair.second;

		m_MapUnitData.clear();

		// ������ ����Ʈ�ڽ� ����� �ʱ�ȭ
		m_ListBox.ResetContent();


		// GetPathName : ���õ� ��θ� ��ȯ
		CString		str = Dlg.GetPathName();

		// GetString ���� ���ڿ��� ��ȯ�ϴ� �Լ�
		const TCHAR* pGetPath = str.GetString();

		HANDLE		hFile = CreateFile(pGetPath, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

		if (INVALID_HANDLE_VALUE == hFile)
			return;

		DWORD		dwStrByte = 0;
		DWORD		dwByte = 0;
		UNITDATA	tData{};

		while (true)
		{
			// Key �� �ε�
			ReadFile(hFile, &dwStrByte, sizeof(DWORD), &dwByte, nullptr);
			
			TCHAR*	pName = nullptr;
			pName = new TCHAR[dwStrByte];

			ReadFile(hFile, pName, dwStrByte, &dwByte, nullptr);

			// value �� �ε�

			ReadFile(hFile, &(tData.byItem), sizeof(BYTE), &dwByte, nullptr);
			ReadFile(hFile, &(tData.byJobIndex), sizeof(BYTE), &dwByte, nullptr);
			ReadFile(hFile, &(tData.iHp), sizeof(int), &dwByte, nullptr);
			ReadFile(hFile, &(tData.iAttack), sizeof(int), &dwByte, nullptr);

			if (0 == dwByte)
			{
				delete[] pName;
				break;
			}

			UNITDATA*	pUnit = new UNITDATA;
			
			pUnit->strName = pName;
			delete[] pName;

			pUnit->byItem = tData.byItem;
			pUnit->byJobIndex = tData.byJobIndex;
			pUnit->iHp = tData.iHp;
			pUnit->iAttack = tData.iAttack;

			m_MapUnitData.insert({ pUnit->strName, pUnit });

			m_ListBox.AddString(pUnit->strName);
		}

		CloseHandle(hFile);
	}

	UpdateData(FALSE);
}
