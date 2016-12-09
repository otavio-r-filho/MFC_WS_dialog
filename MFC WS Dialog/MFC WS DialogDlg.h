
// MFC WS DialogDlg.h : header file
//

#pragma once
#include "afxwin.h"

class CMFCWSDialogDlgAutoProxy;


// CMFCWSDialogDlg dialog
class CMFCWSDialogDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMFCWSDialogDlg);
	friend class CMFCWSDialogDlgAutoProxy;

// Construction
public:
	CMFCWSDialogDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CMFCWSDialogDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCWSDIALOG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	CMFCWSDialogDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	// Control of the scree tittle
	CStatic screen_title;
};
