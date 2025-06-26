#include "renderer.h"
#include "player.h"
#include "map.h"
#include <cmath>

Renderer::Renderer(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, NULL);
    SDL_GetWindowSize(window, &width, &height);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}

void Renderer::render(const Player& player, const Map& map) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);

    for (int x = 0; x < width; ++x) {
        float camera_x = 2 * x / static_cast<float>(width) - 1;
        float ray_dir_x = cos(player.angle) - sin(player.angle) * camera_x;
        float ray_dir_y = sin(player.angle) + cos(player.angle) * camera_x;

        int map_x = static_cast<int>(player.x);
        int map_y = static_cast<int>(player.y);

        float side_dist_x;
        float side_dist_y;

        float delta_dist_x = fabsf(1.0f / ray_dir_x);
        float delta_dist_y = fabsf(1.0f / ray_dir_y);
        float perp_wall_dist;

        int step_x;
        int step_y;

        int hit = 0;
        int side;

        if (ray_dir_x < 0) {
            step_x = -1;
            side_dist_x = (player.x - map_x) * delta_dist_x;
        } else {
            step_x = 1;
            side_dist_x = (map_x + 1.0f - player.x) * delta_dist_x;
        }

        if (ray_dir_y < 0) {
            step_y = -1;
            side_dist_y = (player.y - map_y) * delta_dist_y;
        } else {
            step_y = 1;
            side_dist_y = (map_y + 1.0f - player.y) * delta_dist_y;
        }

        while (hit == 0) {
            if (side_dist_x < side_dist_y) {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                side = 0;
            } else {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                side = 1;
            }
            if (map.get(map_x, map_y) > 0) hit = 1;
        }

        if (side == 0) {
            perp_wall_dist = (map_x - player.x + (1 - step_x) / 2) / ray_dir_x;
        } else {
            perp_wall_dist = (map_y - player.y + (1 - step_y) / 2) / ray_dir_y;
        }

        int line_height = static_cast<int>(height / perp_wall_dist);

        int draw_start = -line_height / 2 + height / 2;
        if (draw_start < 0) draw_start = 0;
        int draw_end = line_height / 2 + height / 2;
        if (draw_end >= height) draw_end = height - 1;

        SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);
        SDL_RenderLine(renderer, static_cast<float>(x), static_cast<float>(draw_start), static_cast<float>(x), static_cast<float>(draw_end));
    }

    SDL_RenderPresent(renderer);
}