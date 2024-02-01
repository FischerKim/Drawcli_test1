#include "pch.h"

int Object::GetID() const
{
	return m_id;
}

void Object::SetID(int id)
{
	m_id = id;
}

DrawShape DrawableObject::GetShape() const
{
	return m_shape;
}

CRect DrawableObject::GetCRect() const 
{
	return m_rect;
}

bool DrawableObject::GetSelected() const
{
	return m_selected;
}

void DrawableObject::SetShape(DrawShape shape)
{
	m_shape = shape;
}

void DrawableObject::SetCRect(CRect rect)
{
	m_rect = rect;
}

void DrawableObject::SetSelected(bool selected)
{
	m_selected = selected;
}