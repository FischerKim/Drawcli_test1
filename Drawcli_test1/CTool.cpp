#include "pch.h"
#include <iostream>
#include "CTool.h"

void CTool::OnButtonShape(DrawShape type)
{
	std::cout << "이 함수는 오버라이딩되는게 아니라 base class에 숨겨져있습니다" << std::endl;
}

void CTool::OnLButtonDown(CPoint point)
{
}

void CTool::OnLButtonUp(CPoint point)
{
}