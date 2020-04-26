
// ExamMFC001Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ExamMFC001.h"
#include "ExamMFC001Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamMFC001Dlg dialog



CExamMFC001Dlg::CExamMFC001Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXAMMFC001_DIALOG, pParent)
	//, m_my_string(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExamMFC001Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT1, m_my_string);
}

BEGIN_MESSAGE_MAP(CExamMFC001Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_READ_BTN, &CExamMFC001Dlg::OnBnClickedReadBtn)
	ON_BN_CLICKED(IDC_WRITE_BTN, &CExamMFC001Dlg::OnBnClickedWriteBtn)
END_MESSAGE_MAP()


// CExamMFC001Dlg message handlers

BOOL CExamMFC001Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CExamMFC001Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CExamMFC001Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExamMFC001Dlg::OnBnClickedReadBtn()
{
	// TODO: Add your control notification handler code here
	//CString str;
	//int value = GetDlgItemInt(IDC_EDIT1);
	//str.Format(L"%d", value);
	//AfxMessageBox(str);

	//wchar_t str[4];
	//GetDlgItemText(IDC_EDIT1, str, 4);

	//CWnd* p = GetDlgItem(IDC_EDIT1);
	//int len = p->SendMessage(WM_GETTEXTLENGTH);
	//int len = p->GetWindowTextLengthW();
	
	//CEdit* p_edit = (CEdit*)p;
	//CEdit* p_edit = (CEdit*)GetDlgItem(IDC_EDIT1);

	if (GetDlgItem(IDC_EDIT1)->GetWindowTextLength() > 3)
	{
		AfxMessageBox(L"너무 길게 입력했습니다!");
	}
	else
	{
		wchar_t str[4];

		GetDlgItemText(IDC_EDIT1, str, 4);

		AfxMessageBox(str);
	}

}


void CExamMFC001Dlg::OnBnClickedWriteBtn()
{
	// TODO: Add your control notification handler code here
	CString str;
	str = L"leehyerim";
	SetDlgItemInt(IDC_EDIT1, 5);

}
