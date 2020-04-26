
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
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExamMFC001Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHAT_LIST, m_chat_list);
}

BEGIN_MESSAGE_MAP(CExamMFC001Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BTN, &CExamMFC001Dlg::OnBnClickedAddBtn)
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



void CExamMFC001Dlg::OnBnClickedAddBtn()
{
	CString str;
	GetDlgItemText(IDC_CHAT_EDIT, str);
	SetDlgItemText(IDC_CHAT_EDIT, L"");

	int index = m_chat_list.InsertString(-1, str);
	m_chat_list.SetCurSel(index);
}
