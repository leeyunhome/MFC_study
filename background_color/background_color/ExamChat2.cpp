
// ExamChat2.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "ExamChat2.h"
#include "ExamChat2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamChat2App

BEGIN_MESSAGE_MAP(CExamChat2App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CExamChat2App construction

CExamChat2App::CExamChat2App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CExamChat2App object

CExamChat2App theApp;


// CExamChat2App initialization

BOOL CExamChat2App::InitInstance()
{

	CWinApp::InitInstance();

	//SetDialogBkColor(RGB(0, 200, 255), RGB(0, 0, 128));
	
	CExamChat2Dlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}

