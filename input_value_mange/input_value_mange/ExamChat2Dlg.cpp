
// ExamChat2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ExamChat2.h"
#include "ExamChat2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamChat2Dlg dialog



CExamChat2Dlg::CExamChat2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXAMCHAT2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExamChat2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExamChat2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOW_BTN, &CExamChat2Dlg::OnBnClickedShowBtn)
END_MESSAGE_MAP()


// CExamChat2Dlg message handlers

BOOL CExamChat2Dlg::OnInitDialog()
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

void CExamChat2Dlg::OnPaint()
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
HCURSOR CExamChat2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExamChat2Dlg::OnBnClickedShowBtn()
{
	int num[11], i;
	for (i = 0; i < 5; ++i)
	{
		num[i] = GetDlgItemInt(IDC_EDIT1 + i);
	}

	CString str, total_str;
	CComboBox* p_combo;
	int index;
	for (i = 0; i < 6; ++i)
	{
		p_combo = (CComboBox *)GetDlgItem(IDC_COMBO1 + i);
		index = p_combo->GetCurSel();
		if (index != CB_ERR)
		{
			p_combo->GetLBText(index, str);
			num[5 + i] = _wtoi(str);
		}
		else
		{
			num[5 + i] = 0;
		}
	}

	for (i = 0; i < 11; ++i)
	{
		str.Format(L"%d, ", num[i]);
		total_str += str;
	}

	SetDlgItemText(IDC_NUM_EDIT, total_str);
}
