#pragma once
#include "ColorStaticCtrl.h";

// CDraw dialog
class CDraw : public CDialogEx
{
	DECLARE_DYNAMIC(CDraw)

public:
	CDraw(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDraw();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HOVER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	ColorStaticCtrl m_staticDraw;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
