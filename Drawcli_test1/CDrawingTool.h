#pragma once
class CDrawingTool
{
public:
	CDrawingTool();
	~CDrawingTool();
public:
	DrawShape m_shapeToDraw{ DrawShape::None };
private:
	double m_x1, m_y1, m_x2, m_y2 = 0;
	bool m_createCircle = false;
	bool m_createLine = false;
	bool m_createRect = false;
	bool m_btndown = false;
	bool m_changelocation = false;

	std::list<DrawableObject> m_drawableObjects;
	bool m_zoomIn{ false };
public:
	std::list<DrawableObject> GetDrawableObjects();
	void OnButtonEmpty();
	void OnButtonCircle();
	void OnButtonLine();
	void OnButtonRect();
	//void OnButtonZoomIn();
	//void OnButtonZoomOut();
	void OnLButtonDown(CPoint point);
	void OnLButtonUp(CPoint point);
};