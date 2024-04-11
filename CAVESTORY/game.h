#ifndef GAME_H
#define GAME_H

#include "defs.h"
#include "graphics.h"
#include "input.h"
#include "game.h"
#include "sprite.h"

class Graphics;

class Game {
public:
    Game();
    ~Game();
private:
    void gameloop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    Sprite _player;
};

#endif // GAME_H
