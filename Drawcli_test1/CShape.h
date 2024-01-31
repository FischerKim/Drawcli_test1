#pragma once

enum class DrawShape { None, Circle, Rect, Line };

struct DrawableObject {
    int id;
    bool selected = false;
    DrawShape shape;
    CRect rect;
};