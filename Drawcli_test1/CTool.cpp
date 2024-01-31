#include "pch.h"
#include "CTool.h"
#include "CShape.h"
#include "Drawcli_test1View.h"

CTool::CTool(CShape nDrawShape) : m_drawShape(nDrawShape) {}

void CTool::OnLButtonDown(CDrawclitest1View* pView, UINT nFlags, const CPoint& point) {}
void CTool::OnLButtonDblClk(CDrawclitest1View* pView, UINT nFlags, const CPoint& point) {}
void CTool::OnLButtonUp(CDrawclitest1View* pView, UINT nFlags, const CPoint& point) {}
void CTool::OnMouseMove(CDrawclitest1View* pView, UINT nFlags, const CPoint& point) {}
void CTool::OnEditProperties(CDrawclitest1View* pView) {}
void CTool::OnCancel() {}

CSelectTool::CSelectTool() : CTool(CShape nDrawShape) {}

void CSelectTool::OnLButtonDown(CDrawclitest1View* pView, UINT nFlags, const CPoint& point)
{
    // Implementation for SelectTool
    // ...
    CTool::OnLButtonDown(pView, nFlags, point);
}

// Add implementations for other tools...

