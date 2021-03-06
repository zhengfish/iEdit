﻿/////////////////////////////////////////////////////////////////////////////
// OptionPageForOther ダイアログ

#pragma once

class OptionPageForOther : public CDialog
{
public:
	OptionPageForOther(CWnd* pParent = NULL);

	enum { IDD = IDD_PG_OTHER };
	CButton	m_chkStylesheet;
	CEdit	m_edStylesheet;
	CButton m_chkOpenFilesAfterExport;
	CButton m_chkOutputFileLinksOnExport;
	CButton	m_chkDrawUnderLine;
	CButton	m_chkAccelMove;
	CButton	m_chkInheritSibling;
	CButton	m_chkInheritParent;
	CButton	m_chkShowHS;
	int		m_tabSelect;
	BOOL	m_bOutputFileLinksOnExport;
	BOOL	m_bOpenFilesAfterExport;
	BOOL	m_bShowHS;
	BOOL	m_bInheritParent;
	BOOL	m_bInheritSibling;
	BOOL	m_bAccelmove;
	BOOL	m_bDrawUnderLine;
	BOOL	m_bSetStylesheet;
	CString	m_strStylesheet;

protected:

	virtual void DoDataExchange(CDataExchange* pDX);
	virtual void OnCancel();
	virtual BOOL OnInitDialog();

	afx_msg void OnRdTab1();
	afx_msg void OnRdTab2();
	afx_msg void OnRdTab3();
	afx_msg void OnChkShowHs();
	afx_msg void OnChkInheritParent();
	afx_msg void OnChkInheritSibling();
	afx_msg void OnChkAccel();
	afx_msg void OnBtnSetmfsize();
	afx_msg void OnChkDrwUndrln();
	afx_msg void OnChkSetStylesheet();
	afx_msg void OnChangeEditStylesheet();
	afx_msg void OnBnClickedChkPostAction();
	afx_msg void OnBnClickedChkExportFilelink();
	DECLARE_MESSAGE_MAP()
};
