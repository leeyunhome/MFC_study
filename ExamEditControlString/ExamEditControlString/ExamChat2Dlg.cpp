
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
	ON_BN_CLICKED(IDC_TEST_BTN, &CExamChat2Dlg::OnBnClickedTestBtn)
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



void CExamChat2Dlg::OnBnClickedTestBtn()
{
	/*HWND h_find_wnd = NULL;
	while (h_find_wnd = ::FindWindowEx(m_hWnd, h_find_wnd, L"buTton", NULL))
	{
		::SetWindowText(h_find_wnd, L"Hello");
	}*/

	/*HWND h_find_wnd = NULL;
	CWnd* p_find_wnd = FindWindowEx(m_hWnd, NULL, L"buTton", NULL);
	while (p_find_wnd != NULL)
	{
		p_find_wnd->SetWindowText(L"Hello");
		p_find_wnd = FindWindowEx(m_hWnd, p_find_wnd->m_hWnd, L"buTton", NULL);
	}*/

	/*CWnd* p_find_wnd;
	HWND h_find_wnd = NULL;
	while (p_find_wnd = FindWindowEx(m_hWnd, h_find_wnd, L"buTton", NULL))
	{
		p_find_wnd->SetWindowText(L"Hello");
		h_find_wnd = p_find_wnd->m_hWnd;
	}*/


	/*CWnd* p_find_wnd;
	HWND h_find_wnd = NULL;
	while (h_find_wnd = ::FindWindowEx(m_hWnd, h_find_wnd, L"buTton", NULL))
	{
		p_find_wnd = CWnd::FromHandle(h_find_wnd);
		p_find_wnd->SetWindowText(L"Hello");
	}*/

	CWnd find_wnd;
	HWND h_find_wnd = NULL;
	while (h_find_wnd = ::FindWindowEx(m_hWnd, h_find_wnd, L"buTton", NULL))
	{
		find_wnd.Attach(h_find_wnd);
		find_wnd.SetWindowText(L"Hello");
		find_wnd.Detach();
	}
}
