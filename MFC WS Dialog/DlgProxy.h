
// DlgProxy.h: header file
//

#pragma once

class CMFCWSDialogDlg;


// CMFCWSDialogDlgAutoProxy command target

class CMFCWSDialogDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CMFCWSDialogDlgAutoProxy)

	CMFCWSDialogDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CMFCWSDialogDlg* m_pDialog;

// Operations
public:

// Overrides
	public:
	virtual void OnFinalRelease();

// Implementation
protected:
	virtual ~CMFCWSDialogDlgAutoProxy();

	// Generated message map functions

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CMFCWSDialogDlgAutoProxy)

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

