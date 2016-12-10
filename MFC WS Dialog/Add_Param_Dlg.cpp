// Add_Param_Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC WS Dialog.h"
#include "Add_Param_Dlg.h"
#include "afxdialogex.h"


// CAdd_Param_Dlg dialog

IMPLEMENT_DYNAMIC(CAdd_Param_Dlg, CDialog)

CAdd_Param_Dlg::CAdd_Param_Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ADD_PARAM_DLG, pParent)
	, param_name(_T(""))
	, param_value(_T(""))
{

}

CAdd_Param_Dlg::~CAdd_Param_Dlg()
{
}

void CAdd_Param_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PARAM_NAME_EDIT, param_name_control);
	DDX_Control(pDX, IDC_PARAM_VALUE_EDIT, param_value_control);
	DDX_Text(pDX, IDC_PARAM_NAME_EDIT, param_name);
	DDX_Text(pDX, IDC_PARAM_VALUE_EDIT, param_value);
}


BEGIN_MESSAGE_MAP(CAdd_Param_Dlg, CDialog)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CAdd_Param_Dlg::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_CANCEL_BUTTON, &CAdd_Param_Dlg::OnBnClickedCancelButton)
END_MESSAGE_MAP()


// CAdd_Param_Dlg message handlers


void CAdd_Param_Dlg::OnBnClickedAddButton()
{
	UpdateData(true);
	UpdateData(false);
	CDialog::OnOK();
}


void CAdd_Param_Dlg::OnBnClickedCancelButton()
{
	UpdateData(false);
	CDialog::OnCancel();
}
