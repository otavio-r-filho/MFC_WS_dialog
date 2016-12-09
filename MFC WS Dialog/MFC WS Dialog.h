
// MFC WS Dialog.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCWSDialogApp:
// See MFC WS Dialog.cpp for the implementation of this class
//

class CMFCWSDialogApp : public CWinApp
{
public:
	CMFCWSDialogApp();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCWSDialogApp theApp;