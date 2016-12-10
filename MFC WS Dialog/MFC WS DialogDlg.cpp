
// MFC WS DialogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC WS Dialog.h"
#include "MFC WS DialogDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCWSDialogDlg dialog


IMPLEMENT_DYNAMIC(CMFCWSDialogDlg, CDialogEx);

CMFCWSDialogDlg::CMFCWSDialogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCWSDIALOG_DIALOG, pParent)
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CMFCWSDialogDlg::~CMFCWSDialogDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CMFCWSDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCREEN_TITLE, screen_title);
	DDX_Control(pDX, IDC_LIST1, param_list);
	DDX_Control(pDX, IDC_PARAM_LIST, param_list);
}

BEGIN_MESSAGE_MAP(CMFCWSDialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_PARAM, &CMFCWSDialogDlg::OnBnClickedAddParam)
	ON_BN_CLICKED(IDC_REMOVE_PARAM, &CMFCWSDialogDlg::OnBnClickedRemoveParam)
END_MESSAGE_MAP()


// CMFCWSDialogDlg message handlers

BOOL CMFCWSDialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//ShowWindow(SW_MAXIMIZE);
	ShowWindow(SW_NORMAL);

	// TODO: Add extra initialization here

	screen_title_font.CreateFont(20, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Microsoft Sans Serif"));

	screen_title.SetFont(&screen_title_font);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCWSDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCWSDialogDlg::OnPaint()
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
HCURSOR CMFCWSDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CMFCWSDialogDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CMFCWSDialogDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CMFCWSDialogDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CMFCWSDialogDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}


void CMFCWSDialogDlg::OnBnClickedAddParam()
{
	add_param_dlg.DoModal();

	if (!add_param_dlg.param_name.IsEmpty() && !add_param_dlg.param_value.IsEmpty()) {
		CString full_param = add_param_dlg.param_name + "=" + add_param_dlg.param_value;

		add_param_dlg.param_name = "";
		add_param_dlg.param_value = "";

		param_list.AddString(full_param);
	}	
}


void CMFCWSDialogDlg::OnBnClickedRemoveParam()
{
	int item = param_list.GetCurSel();
	param_list.DeleteString(item);
}
