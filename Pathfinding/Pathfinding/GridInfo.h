#pragma once

#include "Info.h"
#include "TZ/GameKit.hpp"

#define GRID_WIDTH (SCREEN_WIDTH)
#define GRID_W_STEP 25
#define GRID_HEIGHT (SCREEN_HEIGHT)
#define GRID_H_STEP 25

#define TILE_AMNT (GRID_W*GRID_H)
#define TILE


//
//inline bool operator < (const Tile &lhs, const Tile &rhs) 
//{
//	return lhs.fCost < rhs.fCost;
//}