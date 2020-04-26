
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
	m_pBtn = NULL;
}

void CExamChat2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExamChat2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_COMMAND_RANGE(BTN_ID_1, BTN_ID_5, OnButtonEvent)
END_MESSAGE_MAP()


// CExamChat2Dlg message handlers

BOOL CExamChat2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_pBtn = new CButton * [MAX_BTN];

	CString caption = _T("");
	for (int i = 0; i < MAX_BTN; i++)
	{
		m_pBtn[i] = new CButton();
		caption.Format(_T("%d Button"), i);
		m_pBtn[i]->Create(caption, WS_CHILD | WS_VISIBLE |
			BS_PUSHBUTTON, CRect(10, 10 + (50 * i), 100, 50 + (50 * i)), this,
			BTN_ID_1 + i);
	}

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

void CExamChat2Dlg::OnButtonEvent(UINT ID)
{
	CString msg = _T("");
	msg.Format(_T("%d Button Click!"), ID - BTN_ID_1);

	AfxMessageBox(msg);
}


void CExamChat2Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_pBtn != NULL)
	{
		for (int i = 0; i < MAX_BTN; i++)
		{
			delete m_pBtn[i];
			m_pBtn[i] = NULL;
		}
		delete[] m_pBtn;
	}
}
