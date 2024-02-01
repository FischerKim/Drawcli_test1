#pragma once
class CDrawingTool : public CTool
{
public:
	CDrawingTool();
	~CDrawingTool();
private:
	double m_x1{ 0 }, m_y1{ 0 }, m_x2{ 0 }, m_y2{ 0 };
	bool m_createCircle{ false };
	bool m_createLine{ false };
	bool m_createRect{ false };
	bool m_btndown{ false };
	bool m_changelocation = { false };
	DrawShape m_shapeToDraw{ DrawShape::None };
	int m_count{ 0 };
	std::list<DrawableObject> m_drawableObjects;
	bool m_zoomIn{ false };
public:
	DrawShape GetShapeToDraw();
	std::list<DrawableObject> GetDrawableObjects();
	std::vector<int> OnButtonShape();
	void OnButtonShape(DrawShape type);
	void OnLButtonDown(CPoint point) override;
	void OnLButtonUp(CPoint point) override;
};