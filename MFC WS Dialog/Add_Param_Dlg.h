#pragma once
#include "afxwin.h"


// CAdd_Param_Dlg dialog

class CAdd_Param_Dlg : public CDialog
{
	DECLARE_DYNAMIC(CAdd_Param_Dlg)

public:
	CAdd_Param_Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAdd_Param_Dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_PARAM_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit param_name_control;
	CEdit param_value_control;
	CString param_name;
	CString param_value;
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedCancelButton();
};
