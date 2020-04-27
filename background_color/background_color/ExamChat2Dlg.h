
// ExamChat2Dlg.h : header file
//

#pragma once


// CExamChat2Dlg dialog
class CExamChat2Dlg : public CDialogEx
{
private:
	CBrush m_bk_brush;

// Construction
public:
	CExamChat2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXAMCHAT2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	HRESULT OnCtrlColorDlg(WPARAM wParam, LPARAM lParam);
};
