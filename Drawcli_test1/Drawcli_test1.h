
// Drawcli_test1.h : main header file for the Drawcli_test1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDrawclitest1App:
// See Drawcli_test1.cpp for the implementation of this class
//

class CDrawclitest1App : public CWinAppEx
{
public:
	CDrawclitest1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	bool rect_clicked = false;
	bool circle_clicked = false;
	bool line_clicked = false;
};

extern CDrawclitest1App theApp;
