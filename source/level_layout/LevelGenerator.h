//
// Created by xdbeef on 04.03.18.
//

#ifndef SPELUNKYDS_LEVELGENERATOR_H
#define SPELUNKYDS_LEVELGENERATOR_H

#include <cstdlib>
#include <iostream>
#include <nds.h>
#include <nds/arm9/background.h>
#include <cstring>
#include "MapTile.h"

#define ROOMS_X 3
#define ROOMS_Y 3

class LevelGenerator {

public:

    MapTile *mapTiles[32][32];
    int layout[ROOMS_X][ROOMS_Y];

    void mapBackground();

    void getEntranceTile(MapTile *&m);

    void newLayout(int seed);

    void tilesToMap();

    void mapFrame();

    void generateRooms();

    void clearCollidedTile(int x, int y, int camera_x, int camera_y, int bg);

    void generateSplashScreen(int room_type);

    void matchTile(MapTile *t, int value);
};

//0 - nothing (background)
//1 - just regular tile
//2 - tile up-oriented
//3 - tile down-oriented
//4 - tile both up and down oriented
//5 - block
//6 - tile with gold
//7 - tile with more gold
//8 - regular tile with rock
//9 - ladder
//10 - ladder with deck
//11 - entrance
//12 - arrow trap left
//13 - arrow trap right
//14 - exit

//15 left bar
//16 left bar, top rounded
//17 left bar, bot rounded

//18 right bar
//19 right bar, top rounded
//20 right bar, bottom rounded

//21 top bar
//22 bottom bar

//23 black background

//tabs closed room, type 0
//tabs left-right, type 1
//tabs left-right-down, type 2
//tabs left-right-up, type 3

//entrance room - type 5

//21
static int on_level_done_upper[12][16]{
        {1, 1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1},
        {1, 1, 16, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 19, 1, 7},
        {1, 1, 15, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 18, 1, 7},
        {7, 1, 15, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 18, 1, 1},
        {1, 1, 15, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 18, 1, 1},
        {1, 1, 15, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 18, 1, 1},
        {1, 1, 15, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 18, 1, 7},
        {1, 1, 15, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 18, 1, 6},
        {1, 1, 15, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 18, 1, 1},
        {8, 1, 15, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 18, 1, 1},
        {1, 1, 17, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 20, 1, 1},
        {1, 7, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 8}
};

//20
static int on_level_done_lower[12][16]{
        {1, 1, 1,  1, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1, 1,  1},
        {1, 1, 1,  1, 1, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1,  1},
        {1, 7, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1},
        {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6,  1},
        {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1},
        {1, 1, 3,  3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,  1},
        {8, 1, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  1},
        {1, 1, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  1},
        {1, 1, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 1},
        {1, 1, 2,  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,  1},
        {1, 1, 1,  1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 7,  1},
        {1, 1, 6,  7, 1, 1, 6, 1, 1, 1, 1, 6, 1, 1, 7,  1}
};
//22
static int start_screen_lower[12][16]{
        {6, 1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1},
        {1, 7, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 7},
        {1, 1, 1,  1,  6,  1,  1,  1,  1,  8,  6,  1,  1,  1,  1, 1},
        {1, 1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1},
        {1, 1, 8,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1},
        {1, 1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1},
        {1, 1, 1,  1,  7,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1},
        {1, 1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1},
        {1, 7, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  6,  1, 1},
        {1, 1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  7,  1, 1},
        {1, 1, 1,  1,  1,  1,  1,  6,  1,  1,  1,  1,  1,  1,  1, 1},
        {1, 1, 6,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1},
};

//23
static int start_screen_upper[12][16]{
        {8, 1,  1, 1, 1, 3, 3, 3, 3, 3, 3, 1, 1, 1, 0, 1},
        {1, 1,  7, 1, 3, 0, 0, 0, 0, 0, 0, 3, 7, 1, 0, 1},
        {1, 1,  1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 0, 1},
        {1, 6,  3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1},
        {1, 3,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
        {1, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {6, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 2,  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
};
////////////////////////
static int entrance_room[10][10]{
        {3, 3, 3, 3, 3, 3, 3,  3,  3, 3},
        {0, 0, 0, 0, 0, 0, 0,  9,  0, 0},
        {2, 0, 4, 4, 4, 4, 4,  10, 0, 2},
        {1, 0, 0, 0, 0, 0, 0,  9,  0, 3},
        {1, 0, 0, 4, 4, 4, 0,  9,  0, 0},
        {3, 0, 0, 0, 0, 0, 0,  9,  0, 2},
        {0, 0, 0, 0, 0, 0, 0,  9,  2, 1},
        {0, 0, 0, 0, 0, 0, 11, 2,  7, 1},
        {2, 2, 2, 2, 2, 2, 2,  2,  2, 6},
        {1, 1, 1, 1, 1, 1, 1,  2,  1, 6}
};

//entrance room - type 6
static int exit_room[10][10]{
        {3, 0, 0,  0, 0, 0, 0, 0,  0, 3},
        {0, 0, 0,  0, 0, 0, 0, 9,  0, 0},
        {2, 0, 4,  4, 4, 4, 4, 10, 0, 2},
        {1, 0, 0,  0, 0, 0, 0, 9,  0, 3},
        {1, 0, 0,  4, 4, 4, 0, 9,  0, 0},
        {3, 0, 0,  0, 0, 0, 0, 9,  0, 2},
        {0, 0, 0,  0, 0, 0, 0, 9,  2, 1},
        {0, 0, 14, 0, 0, 0, 0, 2,  7, 1},
        {2, 2, 2,  2, 2, 2, 2, 2,  2, 6},
        {1, 1, 1,  1, 1, 1, 1, 2,  1, 6},
};

static int tab_0_1[10][10] = {
        {3, 3, 3, 3, 3, 3, 3, 3,  3, 3},
        {0, 0, 0, 0, 0, 0, 0, 9,  0, 0},
        {2, 0, 4, 4, 4, 4, 4, 10, 0, 2},
        {1, 0, 0, 0, 0, 0, 0, 9,  0, 3},
        {1, 0, 0, 4, 4, 4, 0, 9,  0, 0},
        {3, 0, 0, 0, 0, 0, 0, 9,  0, 2},
        {0, 0, 0, 0, 0, 0, 0, 9,  2, 1},
        {0, 0, 0, 0, 0, 0, 0, 2,  7, 1},
        {2, 2, 2, 2, 2, 2, 2, 2,  2, 6},
        {1, 1, 1, 1, 1, 1, 1, 2,  1, 6},
};

static int tab_0_2[10][10] = {
        {1, 3, 3, 3, 3, 3, 1, 1, 3, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 7},
        {8, 0, 0, 0, 0, 0, 7, 6, 0, 6},
        {1, 4, 4, 0, 0, 0, 1, 7, 0, 1},
        {1, 0, 0, 0, 0, 0, 3, 6, 6, 1},
        {3, 0, 0, 0, 0, 0, 0, 3, 3, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 5, 2, 5, 2, 0, 0, 2},
        {2, 2, 2, 2, 1, 2, 2, 2, 2, 6},
};

static int tab_0_3[10][10] = {
        {1, 3, 3, 3, 3, 1, 1,  1, 1, 1},
        {1, 0, 0, 0, 0, 3, 6,  1, 3, 7},
        {8, 0, 0, 0, 0, 0, 3,  1, 0, 6},
        {1, 0, 0, 0, 0, 0, 0,  3, 0, 1},
        {1, 0, 0, 0, 0, 0, 0,  0, 0, 8},
        {3, 0, 0, 0, 0, 0, 0,  0, 0, 3},
        {0, 0, 0, 0, 0, 0, 13, 0, 0, 0},
        {0, 0, 2, 2, 2, 0, 5,  0, 0, 2},
        {0, 2, 7, 1, 8, 2, 2,  0, 2, 6},
        {2, 1, 1, 1, 1, 1, 1,  2, 1, 6},
};

static int tab_1_1[10][10] = {
        {3,  3, 3, 3, 3, 3, 3, 3, 3, 3},
        {9,  0, 0, 0, 0, 0, 0, 0, 0, 0},
        {10, 4, 4, 4, 4, 4, 4, 4, 0, 0},
        {9,  0, 0, 0, 0, 0, 0, 0, 0, 0},
        {9,  0, 0, 0, 0, 0, 2, 2, 0, 0},
        {9,  0, 0, 0, 0, 0, 3, 3, 4, 0},
        {9,  0, 0, 0, 5, 0, 0, 0, 0, 0},
        {9,  2, 2, 0, 2, 0, 0, 0, 0, 0},
        {2,  5, 7, 2, 1, 5, 0, 0, 0, 0},
        {1,  1, 1, 1, 1, 2, 2, 2, 2, 2},
};
static int tab_1_2[10][10] = {
        {3, 3, 3,  3, 3, 3, 3, 3, 3, 3},
        {0, 0, 0,  0, 0, 0, 0, 0, 0, 0},
        {0, 0, 9,  0, 0, 0, 0, 0, 0, 0},
        {2, 2, 10, 2, 2, 0, 0, 0, 0, 2},
        {7, 1, 9,  1, 7, 0, 0, 0, 0, 3},
        {1, 8, 9,  1, 1, 0, 0, 0, 0, 0},
        {3, 1, 9,  1, 1, 0, 0, 0, 0, 0},
        {0, 3, 9,  3, 3, 0, 2, 5, 0, 0},
        {0, 0, 9,  0, 0, 0, 1, 2, 0, 0},
        {2, 2, 2,  2, 2, 2, 1, 1, 2, 2},
};
static int tab_1_3[10][10] = {
        {3, 3, 3, 3, 3,  3, 3, 3, 3, 1},
        {0, 0, 0, 0, 0,  0, 0, 0, 0, 1},
        {0, 0, 0, 2, 0,  0, 0, 0, 0, 0},
        {2, 2, 2, 1, 4,  4, 0, 0, 0, 5},
        {3, 6, 1, 3, 0,  0, 0, 0, 2, 2},
        {0, 3, 3, 0, 0,  0, 0, 4, 3, 3},
        {0, 0, 0, 0, 0,  5, 0, 0, 0, 0},
        {0, 0, 0, 0, 12, 2, 0, 0, 0, 0},
        {0, 2, 2, 2, 1,  1, 2, 0, 0, 0},
        {2, 1, 7, 6, 8,  1, 1, 2, 2, 2},
};

static int tab_2_1[10][10] = {

        {3, 3,  3, 3, 3, 3, 3, 3, 3, 3},
        {0, 9,  0, 5, 0, 0, 0, 0, 0, 0},
        {4, 10, 4, 4, 0, 0, 0, 0, 0, 0},
        {0, 9,  0, 0, 0, 0, 0, 0, 0, 0},
        {4, 9,  0, 0, 0, 0, 0, 0, 0, 0},
        {0, 9,  0, 0, 0, 0, 0, 0, 0, 0},
        {0, 9,  0, 0, 0, 0, 5, 0, 0, 0},
        {3, 4,  4, 0, 0, 0, 4, 4, 4, 2},
        {1, 0,  0, 0, 0, 0, 0, 0, 0, 1},
        {2, 2,  2, 0, 0, 0, 0, 0, 2, 1},
};

static int tab_2_2[10][10] = {

        {3, 3, 3, 3,  3, 3, 3, 3, 3, 7},
        {0, 0, 0, 0,  0, 0, 0, 0, 0, 3},
        {0, 0, 0, 2,  0, 0, 0, 0, 0, 0},
        {2, 2, 2, 1,  4, 4, 0, 0, 0, 0},
        {3, 1, 1, 3,  0, 0, 0, 0, 2, 2},
        {0, 3, 3, 13, 0, 0, 0, 4, 3, 3},
        {0, 0, 0, 0,  0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0,  4, 4, 0, 0, 0, 0},
        {0, 5, 0, 0,  0, 0, 0, 0, 0, 0},
        {2, 2, 0, 0,  0, 0, 0, 0, 2, 2},
};

static int tab_2_3[10][10] = {

        {3, 3, 3, 3, 3, 3, 3, 3, 3, 7},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {2, 2, 2, 1, 4, 4, 0, 0, 0, 0},
        {3, 1, 1, 3, 0, 0, 0, 0, 2, 2},
        {0, 3, 3, 0, 0, 0, 0, 4, 3, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 4, 0, 0, 0, 0},
        {0, 5, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 2, 0, 0, 0, 0, 0, 0, 2, 2},
};

static int tab_3_1[10][10] = {
        {3, 0, 0,  0, 0, 0, 0,  0, 0, 6},
        {0, 0, 0,  0, 0, 0, 0,  0, 0, 3},
        {0, 0, 4,  4, 4, 4, 4,  0, 0, 0},
        {0, 0, 0,  0, 0, 0, 9,  0, 0, 0},
        {0, 0, 0,  0, 0, 0, 10, 2, 2, 2},
        {2, 2, 13, 0, 0, 0, 9,  3, 3, 3},
        {3, 3, 4,  0, 0, 0, 9,  0, 0, 0},
        {0, 0, 0,  0, 0, 0, 5,  0, 0, 0},
        {0, 2, 2,  2, 0, 2, 2,  5, 0, 0},
        {2, 7, 8,  5, 2, 1, 1,  2, 2, 2}
};
static int tab_3_2[10][10] = {
        {3, 0, 0, 0, 0, 0,  0, 0, 0, 6},
        {0, 1, 1, 0, 0, 0,  0, 0, 0, 3},
        {0, 7, 6, 0, 0, 9,  0, 0, 0, 0},
        {0, 3, 3, 4, 4, 10, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 9,  0, 0, 0, 2},
        {0, 0, 4, 4, 4, 9,  0, 0, 0, 3},
        {0, 0, 0, 0, 0, 9,  0, 0, 0, 0},
        {0, 0, 0, 0, 0, 9,  2, 4, 4, 0},
        {0, 0, 0, 0, 0, 9,  5, 0, 0, 0},
        {2, 2, 2, 2, 2, 2,  2, 2, 2, 2}
};
static int tab_3_3[10][10] = {
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 12},
        {0, 0, 0, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 2, 4, 0, 0, 0, 0, 2, 2},
        {0, 3, 3, 0, 0, 0, 0, 0, 3, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 4, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 5, 0, 0},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
};


#endif //SPELUNKYDS_LEVELGENERATOR_H

