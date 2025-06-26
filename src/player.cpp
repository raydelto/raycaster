#include "player.h"
#include "map.h"
#include <cmath>

Player::Player(float x, float y, float angle) : x(x), y(y), angle(angle) {}

void Player::move(float speed, const Map& map) {
    float new_x = x + cos(angle) * speed;
    float new_y = y + sin(angle) * speed;

    if (map.get(static_cast<int>(new_x), static_cast<int>(y)) == 0) {
        x = new_x;
    }
    if (map.get(static_cast<int>(x), static_cast<int>(new_y)) == 0) {
        y = new_y;
    }
}

void Player::rotate(float angle_speed) {
    angle += angle_speed;
}
