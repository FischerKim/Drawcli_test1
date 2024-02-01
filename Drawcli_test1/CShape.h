#pragma once

enum class DrawShape { None, Circle, Rect, Line };

struct Object {
private:
    int m_id;
public:
    int GetID() const;
    void SetID(int id);
};

struct DrawableObject : Object {
private:
    bool m_selected{ false };
    DrawShape m_shape;
    CRect m_rect;
public:
    DrawShape GetShape() const;
    CRect GetCRect() const;
    bool GetSelected() const;

    void SetShape(DrawShape shape);
    void SetCRect(CRect rect);
    void SetSelected(bool selected);
};

