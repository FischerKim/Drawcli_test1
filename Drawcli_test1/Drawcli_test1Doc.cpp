
// Drawcli_test1Doc.cpp : implementation of the CDrawclitest1Doc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Drawcli_test1.h"
#endif

#include "Drawcli_test1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CDraw.h"

// CDrawclitest1Doc

IMPLEMENT_DYNCREATE(CDrawclitest1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDrawclitest1Doc, CDocument)
	ON_COMMAND(ID_DRAW_LAUNCH, &CDrawclitest1Doc::OnDrawLaunch)
END_MESSAGE_MAP()


// CDrawclitest1Doc construction/destruction

CDrawclitest1Doc::CDrawclitest1Doc() noexcept
{
	// TODO: add one-time construction code here

}

CDrawclitest1Doc::~CDrawclitest1Doc()
{
}

BOOL CDrawclitest1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CDrawclitest1Doc serialization

void CDrawclitest1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CDrawclitest1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CDrawclitest1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDrawclitest1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDrawclitest1Doc diagnostics

#ifdef _DEBUG
void CDrawclitest1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawclitest1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDrawclitest1Doc commands


void CDrawclitest1Doc::OnDrawLaunch()
{
	CDraw dlgCDraw;
	if (dlgCDraw.DoModal() == IDOK)
	{
	}
	// TODO: Add your command handler code here
}
