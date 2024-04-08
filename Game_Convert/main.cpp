#include <iostream>
#include "defs.h"
#include "BaseObject.h"
#include "graphics.h"

using namespace std;




int main(int argc, char* argv[]) {
    Game game;
    if (!game.InitData()) {
        cout << 12;
        return -1;
    }

    if (!game.LoadBackground()) {
        cout << 123;
        return -1;
    }

    bool is_quit = false;
    while (!is_quit) {
        while (SDL_PollEvent(&g_event) != 0) {
            if (game.g_event.type == SDL_QUIT) is_quit = true;
        }
        SDL_SetRenderDrawColor(game.g_screen, 255, 255, 255, 255);
        SDL_RenderClear(game.g_screen);

        game.Render(game.g_screen, NULL);

        SDL_RenderPresent(game.g_screen);
    }

    game.close();
    return 0;
}
