#include "pch.h"
#include "CDrawingTool.h"

CDrawingTool::CDrawingTool()
{
	m_shapeToDraw = DrawShape::None;
}

CDrawingTool::~CDrawingTool()
{
	m_drawableObjects.clear();
}

std::list<DrawableObject> CDrawingTool::GetDrawableObjects() {
	return m_drawableObjects;
}

void CDrawingTool::OnButtonEmpty()
{
	m_shapeToDraw = DrawShape::None;
	std::list<DrawableObject>::iterator iterator = m_drawableObjects.begin();

	while (iterator != m_drawableObjects.end()) {
		if (iterator->selected) {
			iterator = m_drawableObjects.erase(iterator);
		}
		else {
			++iterator;
		}
	}
}

void CDrawingTool::OnButtonCircle()
{
	m_createCircle = !m_createCircle;
	if(m_createCircle) m_shapeToDraw = DrawShape::Circle;
	else m_shapeToDraw = DrawShape::None;
}

void CDrawingTool::OnButtonLine()
{
	m_createLine = !m_createLine;
	if (m_createLine) m_shapeToDraw = DrawShape::Line;
	else m_shapeToDraw = DrawShape::None;
}

void CDrawingTool::OnButtonRect()
{
	m_createRect = !m_createRect;
	if (m_createRect) m_shapeToDraw = DrawShape::Rect;
	else m_shapeToDraw = DrawShape::None;
}

//void CDrawingTool::OnButtonZoomIn()
//{
//	double center_x = (m_x1 + m_x2) / 2;
//	double center_y = (m_y1 + m_y2) / 2;
//
//	m_x1 = (m_x1 - center_x) * 1.2 + center_x;
//	m_y1 = (m_y1 - center_y) * 1.2 + center_y;
//	m_x2 = (m_x2 - center_x) * 1.2 + center_x;
//	m_y2 = (m_y2 - center_y) * 1.2 + center_y;
//}
//
//void CDrawingTool::OnButtonZoomOut() 
//{
//	double center_x = (m_x1 + m_x2) / 2;
//	double center_y = (m_y1 + m_y2) / 2;
//
//	m_x1 = (m_x1 - center_x) / 1.2 + center_x;
//	m_y1 = (m_y1 - center_y) / 1.2 + center_y;
//	m_x2 = (m_x2 - center_x) / 1.2 + center_x;
//	m_y2 = (m_y2 - center_y) / 1.2 + center_y;
//}

void CDrawingTool::OnLButtonDown(CPoint point)
{
	m_btndown = true;
	m_x1 = point.x;
	m_y1 = point.y;
	for (auto it = m_drawableObjects.begin(); it != m_drawableObjects.end(); ++it)
	{
		if (it->selected && it->rect.PtInRect(point)) {
			m_changelocation = true;
		}
	}
}


void CDrawingTool::OnLButtonUp(CPoint point)
{
	m_btndown = false;
	m_x2 = point.x;
	m_y2 = point.y;
	
	 if(m_changelocation)
	 {
		m_changelocation = false;
			int deltaX = m_x2 - m_x1;
			int deltaY = m_y2 - m_y1;
			for (auto it = m_drawableObjects.begin(); it != m_drawableObjects.end(); ++it)
			{
				if (it->selected) {
					it->rect.TopLeft().x += deltaX;
					it->rect.TopLeft().y += deltaY;
					it->rect.BottomRight().x += deltaX;
					it->rect.BottomRight().y += deltaY;
				}
			}
	 }
	 else if ((m_createCircle || m_createLine || m_createRect) && (m_shapeToDraw != DrawShape::None))
	 {
		 DrawableObject obj;
		 obj.shape = m_shapeToDraw;
		 obj.rect = CRect(m_x1, m_y1, m_x2, m_y2);
		 m_drawableObjects.push_back(obj);
	 }
	else
	{
		for (auto it = m_drawableObjects.begin(); it != m_drawableObjects.end(); ++it) {
			CRect intersectionRect = new CRect(it->rect);
			if (intersectionRect.IntersectRect(&CRect(m_x1, m_y1, m_x2, m_y2), &intersectionRect)) {
				it->selected = true;
			}
			else
			{
				it->selected = false;
			}
		}
	}
}