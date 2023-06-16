#pragma once

#pragma once

#include "Configuration.h"

typedef enum {
    TILE_EMPTY,
    TILE_OBSTACLE,
    TILE_FOOD
} TileType;

void map_Init();

extern TileType map[H][W];
