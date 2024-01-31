#pragma once
#include "SliderStaticCtrl.h"


// SliderDlg dialog

class SliderDlg : public CDialog
{
	DECLARE_DYNAMIC(SliderDlg)

public:
	SliderDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SliderDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SLIDER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int red{ 255 }, green{ 255 }, blue{ 255 };
	CSliderCtrl m_sliderRed;
	CSliderCtrl m_sliderGreen;
	CSliderCtrl m_sliderBlue;
	SliderStaticCtrl m_staticColor;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
private:
	void UpdateColorStaticCtrl();
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
