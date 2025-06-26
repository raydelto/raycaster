#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>

class Renderer {
public:
    Renderer(SDL_Window* window);
    ~Renderer();

    void render(const class Player& player, const class Map& map);

private:
    SDL_Renderer* renderer;
    int width, height;
};

#endif // RENDERER_H
