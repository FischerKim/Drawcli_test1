#include <atltypes.h>
enum class DrawShape { None, Circle, Rect, Line };

struct DrawableObject {
    int id;
    DrawShape shape;
    CRect rect;
};