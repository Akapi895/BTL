#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "defs.h"

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
    Graphics();
    ~Graphics();

    SDL_Surface* loadImage(const std::string &filePath);

    //draw texture to a certain part of the screen
    void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

    //render everything to the screen
    void flip();

    //clear the screen
    void clear();

    SDL_Renderer* getRenderer() const;

private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    std::map<std::string, SDL_Surface*> _spriteSheets;

};

#endif // GRAPHICS_H
