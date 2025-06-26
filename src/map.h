#ifndef MAP_H
#define MAP_H

#include <vector>

class Map {
public:
    Map();
    int get(int x, int y) const;
    int width() const;
    int height() const;

private:
    std::vector<std::vector<int>> data;
};

#endif // MAP_H
