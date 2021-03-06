﻿// EditorView.h : ヘッダー ファイル
//

#pragma once

class iEditDoc;

class EditorView : public CEditView
{
protected:
	EditorView();
	DECLARE_DYNCREATE(EditorView)

public:
	iEditDoc* GetDocument();

protected:
	virtual void OnReplaceAll(LPCTSTR lpszFind, LPCTSTR lpszReplace, BOOL bCase);
	virtual void OnReplaceSel(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, LPCTSTR lpszReplace);
	virtual void OnFindNext(LPCTSTR lpszFind, BOOL bNext, BOOL bCase);
	virtual void OnInitialUpdate();
	virtual void OnDraw(CDC* pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

	virtual ~EditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDelete();
	afx_msg void OnUpdateDelete(CCmdUI* pCmdUI);
	afx_msg void OnEditLabel();
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI* pCmdUI);
	afx_msg void OnEditClear();
	afx_msg void OnUpdateEditClear(CCmdUI* pCmdUI);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnEditFind();
	afx_msg void OnUpdateEditFind(CCmdUI* pCmdUI);
	afx_msg void OnEditReplace();
	afx_msg void OnUpdateEditReplace(CCmdUI* pCmdUI);
	afx_msg void OnPaint();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnChange();
	afx_msg void OnEnVscroll();
	DECLARE_MESSAGE_MAP()

private:
	bool m_bPreUpdateReplace;
	BOOL m_bDrawUnderLine;
	BOOL m_bCanPaint;
	int m_nCaretLine;
	CSize m_textExtent;
	CBrush m_hBrsBack;
	COLORREF m_textColor;
	COLORREF m_bkColor;
	CFindReplaceDialog* m_pFindReplacedlg;
	CFont m_font;
	DWORD m_preKey;

	int GetCaretLine() const;
	void GetLineRect(int nLine, LPRECT lpRect) const;
	void UpdateTextExtent();
	void SetViewFont();
	void SetTabStop();
	void DrawCaretLine(BOOL bInPaint = FALSE);
};
