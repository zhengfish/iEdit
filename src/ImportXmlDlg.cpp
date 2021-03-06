﻿// ImportXmlDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "iEdit.h"
#include "ImportXmlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ImportXmlDlg ダイアログ

ImportXmlDlg::ImportXmlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ImportXmlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ImportXmlDlg)
	m_importMode = -1;
	//}}AFX_DATA_INIT
}

void ImportXmlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ImportXmlDlg)
	DDX_Radio(pDX, IDC_RD_REP, m_importMode);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(ImportXmlDlg, CDialog)
	//{{AFX_MSG_MAP(ImportXmlDlg)
	ON_BN_CLICKED(IDC_RD_REP, OnRdRep)
	ON_BN_CLICKED(IDC_RD_SUB, OnRdSub)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////

void ImportXmlDlg::OnRdRep()
{
	m_importMode = 0;
}

void ImportXmlDlg::OnRdSub()
{
	m_importMode = 1;
}

BOOL ImportXmlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	if (m_titleMessage != L"") {
		SetWindowText(m_titleMessage);
	}
	return TRUE;
}
