#include "game.h"
#include "defs.h"
#include "graphics.h"
#include "input.h"
#include "animatedsprite.h"

namespace {
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}
Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
    Graphics graphics;
    Input input;
    SDL_Event event;

    this->_player = Sprite(graphics, "character/Mychar.png", 64, 192, 64, 64, 100, 100, 100);
    this->_player.setupAnimations();
    this->_player.playAnimation("RunLeft");

    int LAST_UPDATE_TIME = SDL_GetTicks(); //get the number of milisecond
    //start gameloop
    while (true) {
        input.beginNewFrame();

        if (SDL_PollEvent(&event)) {
            if (event.type ==  SDL_KEYDOWN) {
                if (event.key.repeat == 0) { //make sure not holding down key
                    input.keyDownEvent(event);
                }
            }
            else if (event.type == SDL_KEYUP) {
                input.keyUpEvent(event);
            }
            else if (event.type == SDL_QUIT) {
                return;
            }
        }
        if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
            return;
        }

        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        this->update(std::min(MAX_FRAME_TIME, ELAPSED_TIME_MS));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;

        this->draw(graphics);
    }
}

void Game::draw(Graphics &graphics) {
    graphics.clear();

    this->_player.draw(graphics, 100, 100);

    graphics.flip();
}
void Game::update(float elapsedtime) {
    this->_player.update(elapsedtime);
}

