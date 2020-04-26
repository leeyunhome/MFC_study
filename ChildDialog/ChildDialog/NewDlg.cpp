// NewDlg.cpp : implementation file
//

#include "pch.h"
#include "NewDlg.h"
#include "afxdialogex.h"
#include "resource.h"


// NewDlg dialog

IMPLEMENT_DYNAMIC(NewDlg, CDialogEx)

NewDlg::NewDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEW_DLG, pParent)
{

}

NewDlg::~NewDlg()
{
}

void NewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NewDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &NewDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_EXIT_BTN, &NewDlg::OnBnClickedExitBtn)
END_MESSAGE_MAP()


// NewDlg message handlers


BOOL NewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetDlgItemInt(IDC_CHILD_NUM_EDIT, m_num);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void NewDlg::OnBnClickedOk()
{
	m_num = GetDlgItemInt(IDC_CHILD_NUM_EDIT);

	CDialogEx::OnOK();	// EndDialog(IDOK);
}

int NewDlg::GetNum()
{
	return m_num;
}


void NewDlg::OnBnClickedExitBtn()
{
	EndDialog(20);
}
