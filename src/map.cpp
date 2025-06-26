#include "map.h"

Map::Map() {
    data = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1},
        {1,0,1,0,1,1,1,0,1,1,1,0,0,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
}

int Map::get(int x, int y) const {
    if (y >= 0 && y < static_cast<int>(data.size()) && x >= 0 && x < static_cast<int>(data[y].size())) {
        return data[y][x];
    }
    return 1; // Should not happen
}

int Map::width() const {
    return data.empty() ? 0 : static_cast<int>(data[0].size());
}

int Map::height() const {
    return static_cast<int>(data.size());
}