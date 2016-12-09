
// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "MFC WS Dialog.h"
#include "DlgProxy.h"
#include "MFC WS DialogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCWSDialogDlgAutoProxy

IMPLEMENT_DYNCREATE(CMFCWSDialogDlgAutoProxy, CCmdTarget)

CMFCWSDialogDlgAutoProxy::CMFCWSDialogDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CMFCWSDialogDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CMFCWSDialogDlg)))
		{
			m_pDialog = reinterpret_cast<CMFCWSDialogDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CMFCWSDialogDlgAutoProxy::~CMFCWSDialogDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CMFCWSDialogDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CMFCWSDialogDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMFCWSDialogDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// Note: we add support for IID_IMFCWSDialog to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {984E0B16-4012-4254-8673-016C81AC60C0}
static const IID IID_IMFCWSDialog =
{ 0x984E0B16, 0x4012, 0x4254, { 0x86, 0x73, 0x1, 0x6C, 0x81, 0xAC, 0x60, 0xC0 } };

BEGIN_INTERFACE_MAP(CMFCWSDialogDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CMFCWSDialogDlgAutoProxy, IID_IMFCWSDialog, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {C0E76DFE-B827-45AA-8E7D-610E14DCD7F6}
IMPLEMENT_OLECREATE2(CMFCWSDialogDlgAutoProxy, "MFCWSDialog.Application", 0xc0e76dfe, 0xb827, 0x45aa, 0x8e, 0x7d, 0x61, 0xe, 0x14, 0xdc, 0xd7, 0xf6)


// CMFCWSDialogDlgAutoProxy message handlers
