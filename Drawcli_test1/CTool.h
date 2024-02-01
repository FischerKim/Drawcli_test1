#pragma once
#include "pch.h"

class CTool
{
public:
	void OnButtonShape(DrawShape type);
	virtual void OnLButtonDown(CPoint point);
	virtual void OnLButtonUp(CPoint point);
};