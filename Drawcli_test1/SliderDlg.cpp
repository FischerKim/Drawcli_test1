// SliderDlg.cpp : implementation file
//

#include "pch.h"
#include "Drawcli_test1.h"
#include "SliderDlg.h"
#include "afxdialogex.h"


// SliderDlg dialog

IMPLEMENT_DYNAMIC(SliderDlg, CDialog)

SliderDlg::SliderDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SLIDER, pParent)
{

}

SliderDlg::~SliderDlg()
{
}

void SliderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_RED, m_sliderRed);
	DDX_Control(pDX, IDC_SLIDER_GREEN, m_sliderGreen);
	DDX_Control(pDX, IDC_SLIDER_BLUE, m_sliderBlue);
	DDX_Control(pDX, IDC_STATIC_COLOR, m_staticColor);
}


BEGIN_MESSAGE_MAP(SliderDlg, CDialog)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDOK, &SliderDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SliderDlg message handlers
void SliderDlg::UpdateColorStaticCtrl()
{
	m_staticColor.red = m_sliderRed.GetPos();
	m_staticColor.green = m_sliderGreen.GetPos();
	m_staticColor.blue = m_sliderBlue.GetPos();
	m_staticColor.refresh();
}


void SliderDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	UpdateColorStaticCtrl();
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


BOOL SliderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	m_sliderRed.SetRange(0, 255);
	m_sliderGreen.SetRange(0, 255);
	m_sliderBlue.SetRange(0, 255);

	m_sliderRed.SetPos(red);
	m_sliderGreen.SetPos(green);
	m_sliderBlue.SetPos(blue);

	UpdateColorStaticCtrl();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void SliderDlg::OnBnClickedOk()
{
	red = m_staticColor.red;
	green = m_staticColor.green;
	blue = m_staticColor.blue;
	CDialog::OnOK();
}
