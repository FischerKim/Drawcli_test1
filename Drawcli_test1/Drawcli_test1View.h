
#pragma once
#include "CDrawingTool.h"
#include <algorithm>
class CDrawclitest1View : public CView
{
protected: // create from serialization only
	CDrawclitest1View() noexcept;
	DECLARE_DYNCREATE(CDrawclitest1View)

// Attributes
public:
	CDrawclitest1Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CDrawclitest1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawSlider();

private:
	CDrawingTool* ODrawingTool;
	int m_red = 255, m_green = 255, m_blue = 255;

public:
	afx_msg void OnButtonCircle();
	afx_msg void OnButtonEmpty();
	afx_msg void OnButtonLine();
	afx_msg void OnButtonRect();
	afx_msg void OnButtonZoomIn();
	afx_msg void OnButtonZoomOut();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnUpdateButtonCircle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateButtonLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateButtonRect(CCmdUI* pCmdUI);
	afx_msg void OnButtonSelect();
	afx_msg void OnUpdateButtonSelect(CCmdUI* pCmdUI);
};

#ifndef _DEBUG 
inline CDrawclitest1Doc* CDrawclitest1View::GetDocument() const
   { return reinterpret_cast<CDrawclitest1Doc*>(m_pDocument); }
#endif

