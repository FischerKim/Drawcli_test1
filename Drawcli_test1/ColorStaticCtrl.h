#pragma once

// ColorStaticCtrl
class ColorStaticCtrl : public CStatic
{
	DECLARE_DYNAMIC(ColorStaticCtrl)

public:
	ColorStaticCtrl();
	virtual ~ColorStaticCtrl();

	int red{ 255 }, green{ 255 }, blue{ 255 };
	CPoint point;

	void refresh() {
		Invalidate();
		UpdateWindow();	
	}

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


