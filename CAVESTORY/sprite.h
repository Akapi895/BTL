#ifndef SPRITE_H
#define SPRITE_H

#include "defs.h"
#include "graphics.h"

/*this class holds all in4 for individual sprites*/
class Sprite {
public:
    Sprite();
    Sprite(Graphics &graphics, const std::string &filePath,
           int sourceX, int sourceY, int width, int height, float posX, float posY);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics &graphics, int x, int y);
private:
    SDL_Rect _sourceRect;
    SDL_Texture* _spriteSheet;

    float _x, _y;
};

#endif // SPRITE_H
