#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals {
    const float SPRITE_SCALE = 1.0f;
}

struct Vector2 {
    int x, y;
    Vector2():
        x(0), y(0)
    {}
    Vector2 (int a, int b):
        x(a), y(b)
    {}
    Vector2 zero() {
        return Vector2(0, 0);
    }

};

#endif // GLOBALS_H
