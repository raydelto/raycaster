#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(float x, float y, float angle);

    void move(float speed, const class Map& map);
    void rotate(float angle_speed);

    float x, y, angle;
};

#endif // PLAYER_H
