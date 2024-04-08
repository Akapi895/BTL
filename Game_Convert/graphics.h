#ifndef GRAPHICS_H
#define GRAPHICS_H

struct Game {
     SDL_Window* g_window = NULL;
     SDL_Renderer* g_screen = NULL;
     SDL_Event g_event;

     bool InitData() {
        bool success = true;
        int ret = SDL_Init(SDL_INIT_VIDEO);
        if (ret < 0) return 0;

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

        g_window = SDL_CreateWindow("Game CPP", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (g_window == NULL) success = false;
        else {
            g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
            if (g_screen == NULL) success = 0;
            else {
                SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) && imgFlags)) success = 0;
            }
        }
        return success;
    }
    bool LoadBackground() {
        bool ret = LoadImg("img//backkgr.png", g_screen);
        if (ret == false) return false;
        return true;
    }
    void close () {
        Free();

        SDL_DestroyRenderer(g_screen);
        g_screen = NULL;

        SDL_DestroyWindow(g_window);
        g_window = NULL;

        IMG_Quit();
        SDL_Quit();
    }
};

#endif // GRAPHICS_H
