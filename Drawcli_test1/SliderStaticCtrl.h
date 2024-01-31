#pragma once


// SliderStaticCtrl

class SliderStaticCtrl : public CStatic
{
	DECLARE_DYNAMIC(SliderStaticCtrl)

public:
	SliderStaticCtrl();
	virtual ~SliderStaticCtrl();

	int red{ 255 }, green{ 0 }, blue{ 0 };

	void refresh() {
		Invalidate();
		UpdateWindow();
	}

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


