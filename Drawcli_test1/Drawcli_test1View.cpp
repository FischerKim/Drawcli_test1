
// Drawcli_test1View.cpp : implementation of the CDrawclitest1View class
//

#include "pch.h"
#ifndef SHARED_HANDLERS
#include "Drawcli_test1.h"
#endif
#include "Drawcli_test1Doc.h"
#include "Drawcli_test1View.h"
#include "SliderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <string>


// CDrawclitest1View
IMPLEMENT_DYNCREATE(CDrawclitest1View, CView)

BEGIN_MESSAGE_MAP(CDrawclitest1View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DRAW_SLIDER, &CDrawclitest1View::OnDrawSlider)
	ON_COMMAND(ID_BUTTON_CIRCLE, &CDrawclitest1View::OnButtonCircle)
	ON_COMMAND(ID_BUTTON_EMPTY, &CDrawclitest1View::OnButtonEmpty)
	ON_COMMAND(ID_BUTTON_LINE, &CDrawclitest1View::OnButtonLine)
	ON_COMMAND(ID_BUTTON_RECT, &CDrawclitest1View::OnButtonRect)
	//ON_COMMAND(ID_BUTTON_ZOOM_IN, &CDrawclitest1View::OnButtonZoomIn)
	//ON_COMMAND(ID_BUTTON_ZOOM_OUT, &CDrawclitest1View::OnButtonZoomOut)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_UPDATE_COMMAND_UI(ID_BUTTON_CIRCLE, &CDrawclitest1View::OnUpdateButtonCircle)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_LINE, &CDrawclitest1View::OnUpdateButtonLine)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_RECT, &CDrawclitest1View::OnUpdateButtonRect)
	ON_COMMAND(ID_BUTTON_SELECT, &CDrawclitest1View::OnButtonSelect)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_SELECT, &CDrawclitest1View::OnUpdateButtonSelect)
END_MESSAGE_MAP()


CDrawclitest1View::CDrawclitest1View() noexcept
{
	m_pDC = nullptr;
	ODrawingTool = new CDrawingTool();	
}


CDrawclitest1View::~CDrawclitest1View()
{
	m_pDC = nullptr;
	delete ODrawingTool;
}


BOOL CDrawclitest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}


void CDrawclitest1View::OnDraw(CDC* pDC)
{
	m_pDC = pDC;
	CDrawclitest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect rectWindow;
	GetClientRect(&rectWindow);

	auto color{ RGB(m_red, m_green, m_blue) };
	CBrush brush(color);
	m_pDC->FillRect(&rectWindow, &brush);

	std::list<DrawableObject> m_drawableObjects = ODrawingTool->GetDrawableObjects();
	for (const DrawableObject& obj : m_drawableObjects) {
		CPen pen;
		if (obj.GetSelected()) pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		else  pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

		CPen* pOriginalPen = pDC->SelectObject(&pen);
		switch (obj.GetShape()) {
		case DrawShape::Circle:
			m_pDC->Ellipse(obj.GetCRect());
			break;
		case DrawShape::Rect:
			m_pDC->Rectangle(obj.GetCRect());
			break;
		case DrawShape::Line:
			m_pDC->MoveTo(obj.GetCRect().TopLeft());
			m_pDC->LineTo(obj.GetCRect().BottomRight());
			break;
		case DrawShape::None:
			break;
		}
		m_pDC->SelectObject(pOriginalPen);
	}

}

void CDrawclitest1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawclitest1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

#ifdef _DEBUG
void CDrawclitest1View::AssertValid() const
{
	CView::AssertValid();
}

void CDrawclitest1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawclitest1Doc* CDrawclitest1View::GetDocument() const 
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawclitest1Doc)));
	return (CDrawclitest1Doc*)m_pDocument;
}
#endif 

void CDrawclitest1View::OnDrawSlider()
{
	SliderDlg dlgCSlider;

	dlgCSlider.red = m_red;
	dlgCSlider.green = m_green;
	dlgCSlider.blue = m_blue;

	if (dlgCSlider.DoModal() == IDOK)
	{
		m_red = dlgCSlider.red;
		m_green = dlgCSlider.green;
		m_blue = dlgCSlider.blue;
		Invalidate();
		UpdateWindow();
	}
}

void CDrawclitest1View::OnButtonEmpty()
{
	std::vector<int> deleted = ODrawingTool->OnButtonShape();
	std::string tmp = "deleted ID: ";
	for (const auto& element : deleted) {
		tmp += std::to_string(element) + " ";
	}
	//MessageBoxA(nullptr, tmp.c_str(), "Deleted Elements ID", MB_OK | MB_ICONINFORMATION);

	Invalidate();
	UpdateWindow();
}

void CDrawclitest1View::OnButtonCircle()
{
	ODrawingTool->OnButtonShape(DrawShape::Circle);
	Invalidate();
	UpdateWindow();
}

void CDrawclitest1View::OnButtonLine()
{
	ODrawingTool->OnButtonShape(DrawShape::Line);
	Invalidate();
	UpdateWindow();
}

void CDrawclitest1View::OnButtonRect()
{
	ODrawingTool->OnButtonShape(DrawShape::Rect);
	Invalidate();
	UpdateWindow();
}

void CDrawclitest1View::OnButtonSelect()
{
	ODrawingTool->OnButtonShape(DrawShape::None);
	Invalidate();
	UpdateWindow();
}

//void CDrawclitest1View::OnButtonZoomIn()
//{
//	ODrawingTool->OnButtonZoomIn();
//	Invalidate();
//	UpdateWindow();
//}
//
//void CDrawclitest1View::OnButtonZoomOut()
//{
//	ODrawingTool->OnButtonZoomOut();
//	Invalidate();
//	UpdateWindow();
//}

void CDrawclitest1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	ODrawingTool->OnLButtonDown(point);
	CView::OnLButtonDown(nFlags, point);
}

void CDrawclitest1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	ODrawingTool->OnLButtonUp(point);
	Invalidate();
	UpdateWindow();
	CView::OnLButtonUp(nFlags, point);
}

void CDrawclitest1View::OnUpdateButtonCircle(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(ODrawingTool->GetShapeToDraw() == DrawShape::Circle);
}

void CDrawclitest1View::OnUpdateButtonLine(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(ODrawingTool->GetShapeToDraw() == DrawShape::Line);
}

void CDrawclitest1View::OnUpdateButtonRect(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(ODrawingTool->GetShapeToDraw() == DrawShape::Rect);
}

void CDrawclitest1View::OnUpdateButtonSelect(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
}
