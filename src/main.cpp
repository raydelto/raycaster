#include <SDL3/SDL.h>
#include "player.h"
#include "map.h"
#include "renderer.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Raycaster", 800, 600, 0);

    Player player(2.0f, 2.0f, 0.0f);
    Map map;
    Renderer renderer(window);

    Uint64 last_time = SDL_GetTicks();
    float delta_time = 0.0f;

    bool running = true;
    while (running) {
        Uint64 current_time = SDL_GetTicks();
        delta_time = (current_time - last_time) / 1000.0f;
        last_time = current_time;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        const Uint8* keystates = reinterpret_cast<const Uint8*>(SDL_GetKeyboardState(NULL));
        float move_speed = 5.0f;
        float rotation_speed = 3.0f;

        if (keystates[SDL_SCANCODE_W]) {
            player.move(move_speed * delta_time, map);
        }
        if (keystates[SDL_SCANCODE_S]) {
            player.move(-move_speed * delta_time, map);
        }
        if (keystates[SDL_SCANCODE_A]) {
            player.rotate(-rotation_speed * delta_time);
        }
        if (keystates[SDL_SCANCODE_D]) {
            player.rotate(rotation_speed * delta_time);
        }

        renderer.render(player, map);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}