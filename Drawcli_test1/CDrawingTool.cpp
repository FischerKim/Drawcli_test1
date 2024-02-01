#include "pch.h"
#include "CDrawingTool.h"
#include <iostream>

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

DrawShape CDrawingTool::GetShapeToDraw() {
	return m_shapeToDraw;
}

void CDrawingTool::OnButtonShape(DrawShape type)
{
	if(type == DrawShape::Circle) m_createCircle = !m_createCircle;
	else if(type == DrawShape::Rect) m_createRect = !m_createRect;
	else if(type == DrawShape::Line) m_createLine = !m_createLine;
	else {
		m_createCircle = false;
		m_createLine = false;
		m_createRect = false;
	}
	m_shapeToDraw = type;
}

std::vector<int> CDrawingTool::OnButtonShape()
{
	std::vector<int> tmp;
	m_shapeToDraw = DrawShape::None;
	std::list<DrawableObject>::iterator iterator = m_drawableObjects.begin();

	while (iterator != m_drawableObjects.end()) {
		if (iterator->GetSelected()) {
			int id = iterator->GetID();
			tmp.push_back(id);
			iterator = m_drawableObjects.erase(iterator);
		}
		else {
			++iterator;
		}
	}
	return tmp;
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
		if (it->GetSelected() && it->GetCRect().PtInRect(point)) {
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
				if (it->GetSelected()) {
					CRect tmp = it->GetCRect();
					tmp.TopLeft().x += deltaX;
					tmp.TopLeft().y += deltaY;
					tmp.BottomRight().x += deltaX;
					tmp.BottomRight().y += deltaY;
					it->SetCRect(tmp);
				}
			}
	 }
	 else if ((m_createCircle || m_createLine || m_createRect) && (m_shapeToDraw != DrawShape::None))
	 {
		 DrawableObject obj;
		 obj.SetID(m_count++);
		 obj.SetShape(m_shapeToDraw);
		 obj.SetCRect(CRect(m_x1, m_y1, m_x2, m_y2));
		 m_drawableObjects.push_back(obj);
	 }
	else
	{
		for (auto it = m_drawableObjects.begin(); it != m_drawableObjects.end(); ++it) {
			CRect tmp(it->GetCRect());
			CRect normalizedrect(
				min(tmp.TopLeft().x, tmp.BottomRight().x),
				min(tmp.TopLeft().y, tmp.BottomRight().y),
				max(tmp.TopLeft().x, tmp.BottomRight().x),
				max(tmp.TopLeft().y, tmp.BottomRight().y)
			);

			if (normalizedrect.PtInRect(point)) it->SetSelected(true);
			else if (normalizedrect.IntersectRect(
				&CRect(min(m_x1, m_x2),
					min(m_y1, m_y2),
					max(m_x1, m_x2),
					max(m_y1, m_y2)),
				&normalizedrect)) 
				it->SetSelected(true);
			else it->SetSelected(false);
		}
	}
}