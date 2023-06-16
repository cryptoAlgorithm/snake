#include "map.h"

#include <stddef.h>

TileType map[H][W];

void map_Init() {
    // Init map
    for (size_t h = 0; h < H; h++) {
        for (size_t w = 0; w < W; w++) {
            if (h == 0 || h == H-1 || w == 0 || w == W-1) map[h][w] = TILE_OBSTACLE;
            else map[h][w] = TILE_EMPTY;
        }
    }
}
