// SliderStaticCtrl.cpp : implementation file
//

#include "pch.h"
#include "Drawcli_test1.h"
#include "SliderStaticCtrl.h"


// SliderStaticCtrl

IMPLEMENT_DYNAMIC(SliderStaticCtrl, CStatic)

SliderStaticCtrl::SliderStaticCtrl()
{

}

SliderStaticCtrl::~SliderStaticCtrl()
{
}


BEGIN_MESSAGE_MAP(SliderStaticCtrl, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// SliderStaticCtrl message handlers




void SliderStaticCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CStatic::OnPaint() for painting messages

	CRect rectWindow;
	GetClientRect(&rectWindow);

	auto color{ RGB(red, green, blue) };
	CBrush brush(color);
	dc.FillRect(&rectWindow, &brush);

	auto oldBkColor{ dc.SetBkColor(color) };
	CString strColor;
	strColor.Format(_T("RGB: %d, %d, %d"), red, green, blue);
	dc.TextOutW(10, 10, strColor);


	dc.SelectClipRgn(NULL);
}
