#ifndef __TOOL_H__
#define __TOOL_H__

#include "CShape.h"

class CDrawclitest1View;

class CTool
{
public:
    CTool(DrawShape nDrawShape);
    virtual ~CTool() = default;

    virtual void OnLButtonDown(CDrawclitest1View* pView, UINT nFlags, const CPoint& point);
    virtual void OnLButtonDblClk(CDrawclitest1View* pView, UINT nFlags, const CPoint& point);
    virtual void OnLButtonUp(CDrawclitest1View* pView, UINT nFlags, const CPoint& point);
    virtual void OnMouseMove(CDrawclitest1View* pView, UINT nFlags, const CPoint& point);
    virtual void OnEditProperties(CDrawclitest1View* pView);
    virtual void OnCancel();

protected:
    DrawShape m_drawShape;
};

class CSelectTool : public CTool
{
public:
    CSelectTool();
    ~CSelectTool() override = default;

    void OnLButtonDown(CDrawclitest1View* pView, UINT nFlags, const CPoint& point) override;
    void OnLButtonDblClk(CDrawclitest1View* pView, UINT nFlags, const CPoint& point) override;
    void OnLButtonUp(CDrawclitest1View* pView, UINT nFlags, const CPoint& point) override;
    void OnMouseMove(CDrawclitest1View* pView, UINT nFlags, const CPoint& point) override;
    void OnEditProperties(CDrawclitest1View* pView) override;
};

// Add similar classes for other tools...

#endif // __TOOL_H__
