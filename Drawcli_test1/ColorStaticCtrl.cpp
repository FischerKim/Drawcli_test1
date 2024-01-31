// ColorStaticCtrl.cpp : implementation file
//

#include "pch.h"
#include "Drawcli_test1.h"
#include "ColorStaticCtrl.h"


// ColorStaticCtrl

IMPLEMENT_DYNAMIC(ColorStaticCtrl, CStatic)

ColorStaticCtrl::ColorStaticCtrl()
{

}

ColorStaticCtrl::~ColorStaticCtrl()
{
}


BEGIN_MESSAGE_MAP(ColorStaticCtrl, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// ColorStaticCtrl message handlers
void ColorStaticCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CStatic::OnPaint() for painting messages

	CRect rectWindow;
	GetClientRect(&rectWindow);

	CRgn ClipRgn;
	if (ClipRgn.CreateRectRgnIndirect(&rectWindow))
		dc.SelectClipRgn(&ClipRgn);

	auto color{ RGB( red, green, blue ) };
	CBrush brush(color);
	dc.FillRect(&rectWindow, &brush);

	dc.LineTo(500, 30);

	auto oldBkColor{ dc.SetBkColor(color) };
	CString strPoint;
	strPoint.Format(_T("x: %d"), point.x);
	dc.TextOutW(10, 10, strPoint);

	strPoint.Format(_T("y: %d"), point.y);
	dc.TextOutW(10, 40, strPoint);


	dc.SelectClipRgn(NULL);

}
