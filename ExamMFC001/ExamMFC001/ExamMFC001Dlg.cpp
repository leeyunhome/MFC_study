
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
}

BEGIN_MESSAGE_MAP(CExamMFC001Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
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


//
//LRESULT CExamMFC001Dlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
//{
//	// TODO: Add your specialized code here and/or call the base class
//	if (message == WM_LBUTTONDOWN) {
//		CClientDC dc(this);
//
//		int x = LOWORD(lParam);
//		int y = HIWORD(lParam);
//
//		if (wParam & MK_CONTROL)
//		{
//			dc.Ellipse(x - 10, y - 10, x + 10, y + 10);
//		}
//		else
//		{
//			dc.Rectangle(x - 10, y - 10, x + 10, y + 10);
//		}
//
//		
//		// Win32!
//		//HDC h_dc = ::GetDC(m_hWnd);
//		//Rectangle(h_dc, 10, 10, 100, 100);
//		//::ReleaseDC(m_hWnd, h_dc);
//
//		// MFC �⺻ �ڵ�
//		//CDC *p_dc = GetDC();
//		//p_dc->Rectangle(10, 10, 100, 100);
//		//ReleaseDC(p_dc);
//	}
//	return CDialogEx::WindowProc(message, wParam, lParam);
//}


void CExamMFC001Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// point.x, point.y
	CClientDC dc(this);
	if (nFlags & MK_CONTROL)
	{
		dc.Ellipse(point.x - 30, point.y - 30, point.x + 30, point.y + 30);
	}
	else
	{
		dc.Rectangle(point.x - 30, point.y - 30, point.x + 30, point.y + 30);
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}
