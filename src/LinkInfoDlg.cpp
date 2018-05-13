﻿// LinkPropertiesDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "iEdit.h"
#include "iLink.h"
#include "LinkInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LinkPropertiesDlg ダイアログ


LinkPropertiesDlg::LinkPropertiesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(LinkPropertiesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(LinkPropertiesDlg)
	//}}AFX_DATA_INIT
}


void LinkPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LinkPropertiesDlg)
	DDX_Control(pDX, IDC_CMB_LINE, m_cmbLineStyle);
	DDX_Control(pDX, IDC_LINKTO, m_LabelTo);
	DDX_Control(pDX, IDC_LINKFROM, m_LabelFrom);
	DDX_Control(pDX, IDC_EDIT, m_edit);
	DDX_Control(pDX, IDC_COMBO, m_combo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LinkPropertiesDlg, CDialog)
	//{{AFX_MSG_MAP(LinkPropertiesDlg)
	ON_CBN_SELCHANGE(IDC_COMBO, OnSelchangeCombo)
	ON_BN_CLICKED(IDC_BTN_COLOR, OnBtnColor)
	ON_BN_CLICKED(IDC_BTN_FONT, OnBtnFont)
	ON_CBN_SELCHANGE(IDC_CMB_LINE, OnSelchangeCmbLine)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LinkPropertiesDlg メッセージ ハンドラ

BOOL LinkPropertiesDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	m_LabelFrom.SetWindowText(strFrom);
	m_LabelTo.SetWindowText(strTo);
	switch (styleArrow) {
	case iLink::line:
	case iLink::arrow:
	case iLink::arrow2:
		m_combo.SetCurSel(styleArrow);
		break;
	case iLink::depend:
		m_combo.SetCurSel(3);
		break;
	case iLink::depend2:
		m_combo.SetCurSel(4);
		break;
	case iLink::inherit:
		m_combo.SetCurSel(5);
		break;
	case iLink::aggregat:
		m_combo.SetCurSel(6);
		break;
	case iLink::composit:
		m_combo.SetCurSel(7);
		break;
	default:
		m_combo.SetCurSel(0);
	}
	
	m_edit.ReplaceSel(strComment);
	
	if (styleLine == PS_DOT) {
		m_cmbLineStyle.SetCurSel(5);
	} else {
		if (lineWidth == 0) {
			m_cmbLineStyle.SetCurSel(0);
		} else {
			m_cmbLineStyle.SetCurSel(lineWidth - 1);
		}
	}
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void LinkPropertiesDlg::OnSelchangeCombo() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	switch (m_combo.GetCurSel()) {
	case 0:
		styleArrow = iLink::line;
		break;
	case 1:
		styleArrow = iLink::arrow;
		break;
	case 2:
		styleArrow = iLink::arrow2;
		break;
	case 3:
		styleArrow = iLink::depend;
		break;
	case 4:
		styleArrow = iLink::depend2;
		break;
	case 5:
		styleArrow = iLink::inherit;
		break;
	case 6:
		styleArrow = iLink::aggregat;
		break;
	case 7:
		styleArrow = iLink::composit;
		break;
	}
}

void LinkPropertiesDlg::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	m_edit.GetWindowText(strComment);
	CDialog::OnOK();
}


void LinkPropertiesDlg::OnBtnColor() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	CColorDialog dlg(colorLine);
	if (dlg.DoModal() != IDOK) return;
	colorLine = dlg.GetColor();
}

void LinkPropertiesDlg::OnBtnFont() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	CFontDialog dlg(&lf);
	dlg.m_cf.Flags |= CF_SELECTSCRIPT;
	if (dlg.DoModal() != IDOK) return;
}

void LinkPropertiesDlg::OnSelchangeCmbLine() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	int index = m_cmbLineStyle.GetCurSel();
	if (index == 0 || index == 5) {
		lineWidth = 0;
	} else {
		lineWidth = index+1;
	}
	if (index < 5) {
		styleLine = PS_SOLID;
	} else if (index == 5) {
		styleLine = PS_DOT;
	}
}
