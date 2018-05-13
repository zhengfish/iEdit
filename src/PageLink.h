﻿#if !defined(AFX_PAGELINK_H__79C43545_7FE6_11D3_9860_006097789FE5__INCLUDED_)
#define AFX_PAGELINK_H__79C43545_7FE6_11D3_9860_006097789FE5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageLink.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// PageLink ダイアログ

class PageLink : public CDialog
{
// コンストラクション
public:
	int strength;
	int lineWidth;
	int styleLine;
	COLORREF colorLine;
	LOGFONT lf;
	PageLink(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(PageLink)
	enum { IDD = IDD_PG_LINK };
	CStatic	m_strn;
	CSliderCtrl	m_Slider;
	CButton	m_chkSetStreangth;
	CComboBox	m_cmbLine;
	BOOL	m_bSetStrength;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(PageLink)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(PageLink)
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnColor();
	afx_msg void OnBtnFont();
	afx_msg void OnSelchangeCmbLine();
	afx_msg void OnChkStrength();
	afx_msg void OnReleasedcaptureSlid(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_PAGELINK_H__79C43545_7FE6_11D3_9860_006097789FE5__INCLUDED_)