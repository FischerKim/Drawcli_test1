// CDraw.cpp : implementation file
//

#include "pch.h"
#include "Drawcli_test1.h"
#include "CDraw.h"
#include "afxdialogex.h"


// CDraw dialog

IMPLEMENT_DYNAMIC(CDraw, CDialogEx)

CDraw::CDraw(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_HOVER, pParent)
{

}

CDraw::~CDraw()
{
}

void CDraw::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_DRAW, m_staticDraw);
}


BEGIN_MESSAGE_MAP(CDraw, CDialogEx)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CDraw message handlers


void CDraw::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_staticDraw.red = point.x % 256;
	m_staticDraw.green = point.y % 256;
	m_staticDraw.point = point;
	m_staticDraw.refresh();
	CDialogEx::OnMouseMove(nFlags, point);
}
