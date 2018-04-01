//
// Created by xdbeef on 24.02.18.
//

#include <nds.h>
#include <nds/arm9/sprite.h>
#include <iostream>
#include "MainDude.h"
#include "../Consts.h"
#include "../../build/spelunker.h"
#include "Collisions.h"
#include "../level_layout/MapUtils.h"

/**
 * For debugging purposes
 * @param mapTiles
 */
void MainDude::clearTilesOnRight(MapTile *mapTiles[32][32]) {

    int xx = floor_div(this->x, 16);
    int yy = floor_div(this->y, 16);

    MapTile *left_middle = mapTiles[xx - 1][yy];
    MapTile *right_middle = mapTiles[xx + 1][yy];
    MapTile *up_middle = mapTiles[xx][yy - 1];
    MapTile *down_middle = mapTiles[xx][yy + 1];
    MapTile *center = mapTiles[xx][yy];
    MapTile *left_up = mapTiles[xx - 1][yy - 1];
    MapTile *right_up = mapTiles[xx + 1][yy - 1];
    MapTile *left_down = mapTiles[xx - 1][yy + 1];
    MapTile *right_down = mapTiles[xx + 1][yy + 1];

    up_middle->values[0] = 16;
    up_middle->values[1] = 16;
    up_middle->values[2] = 16;
    up_middle->values[3] = 16;

    down_middle->values[0] = 0;
    down_middle->values[1] = 0;
    down_middle->values[2] = 0;
    down_middle->values[3] = 0;

}

void MainDude::handleKeyInput(int keys_held, int keys_down) {


    if (keys_down) {
        if (keys_down & KEY_R) {
            if (bottomCollision) {
                ySpeed = -JUMP_SPEED;
            }
            if ((hangingOnTileLeft || hangingOnTileRight) && hangingTimer > MIN_HANGING_TIME) {
                ySpeed = -JUMP_SPEED;
                hangingOnTileLeft = false;
                hangingOnTileRight = false;
                hangingTimer = 0;
            }
        }
    }
    if (keys_held) {


        if (keys_held & KEY_LEFT) {
            state = W_LEFT;
            hangingOnTileLeft = false;
            if (xSpeed > -MAX_X_SPEED && !(hangingOnTileRight || hangingOnTileLeft))
                if (speedIncTimer > X_SPEED_DELTA_TIME_MS) {
                    xSpeed -= X_SPEED_DELTA;
                    speedIncTimer = 0;
                }
        }

        if (keys_held & KEY_RIGHT) {
            state = W_RIGHT;
            hangingOnTileRight = false;
            if (xSpeed < MAX_X_SPEED && !(hangingOnTileRight || hangingOnTileLeft)) {
                if (speedIncTimer > X_SPEED_DELTA_TIME_MS) {
                    xSpeed += X_SPEED_DELTA;
                    speedIncTimer = 0;
                }
            }
        }

        if (keys_held & KEY_DOWN) {
            hangingOnTileLeft = false;
            hangingOnTileRight = false;
        }
    }
}


void MainDude::updateTimers(int timeElapsed) {
    posIncTimer += timeElapsed;
    frictionTimer += timeElapsed;
    speedIncTimer += timeElapsed;
    hangingTimer += timeElapsed;

    if (xSpeed != 0)
        animationFrameTimer += timeElapsed;
}


void MainDude::updateSpeed(MapTile *mapTiles[32][32]) {

    if (xSpeed > MAX_X_SPEED)
        xSpeed = MAX_X_SPEED;
    if (xSpeed < -MAX_X_SPEED)
        xSpeed = -MAX_X_SPEED;

    if (ySpeed > MAX_Y_SPEED)
        ySpeed = MAX_Y_SPEED;
    if (ySpeed < -MAX_Y_SPEED)
        ySpeed = -MAX_Y_SPEED;


    if (posIncTimer > 10) {

        std::cout << xSpeed << '\n';

        double tempXspeed = abs(xSpeed);
        double tempYspeed = abs(ySpeed);

        int old_xx = -1;
        int old_yy = -1;
        int xx;
        int yy;

        while (tempXspeed > 0 || tempYspeed > 0) {
            if (tempXspeed > 0) {
                if (xSpeed > 0) {
                    x += 1;
                } else if (xSpeed < 0) {
                    x -= 1;
                }
            }
            if (tempYspeed > 0) {
                if (ySpeed > 0)
                    y += 1;
                else if (ySpeed < 0)
                    y -= 1;
            }

            xx = floor_div(this->x + 0.5 * MAIN_DUDE_WIDTH, 16);
            yy = floor_div(this->y + 0.5 * MAIN_DUDE_HEIGHT, 16);

            if (old_xx != xx || old_yy != yy) {
                checkCollisionWithMap(mapTiles, xx, yy);
            }

            old_xx = xx;
            old_yy = yy;

            tempXspeed--;
            tempYspeed--;
        }


        if (!bottomCollision && !(hangingOnTileLeft || hangingOnTileRight))
            ySpeed += GRAVITY_DELTA_SPEED;

        posIncTimer = 0;

    }
}

void MainDude::checkCollisionWithMap(MapTile *mapTiles[32][32], int xx, int yy) {

    MapTile *left_middle = mapTiles[xx - 1][yy];
    MapTile *right_middle = mapTiles[xx + 1][yy];
    MapTile *up_middle = mapTiles[xx][yy - 1];
    MapTile *down_middle = mapTiles[xx][yy + 1];
    MapTile *center = mapTiles[xx][yy];
    MapTile *left_up = mapTiles[xx - 1][yy - 1];
    MapTile *right_up = mapTiles[xx + 1][yy - 1];
    MapTile *left_down = mapTiles[xx - 1][yy + 1];
    MapTile *right_down = mapTiles[xx + 1][yy + 1];
    MapTile *tiles[9] = {
            left_middle, //0
            right_middle, //1
            up_middle, //2
            down_middle, //3
            center, //4
            left_up, //5
            right_up, //6
            left_down, //7
            right_down //8
    };

    bottomCollision = Collisions::checkBottomCollision(tiles, &this->x, &this->y, &ySpeed, 16, 16);
    leftCollision = Collisions::checkLeftCollision(tiles, &this->x, &this->y, &xSpeed, 16, 16, !bottomCollision);
    rightCollision = Collisions::checkRightCollision(tiles, &this->x, &this->y, &xSpeed, 16, 16, !bottomCollision);
    upperCollision = Collisions::checkUpperCollision(tiles, &this->x, &this->y, &ySpeed, 16);
    Collisions::isStandingOnEdge(tiles, &
            this->x, &this->y, &ySpeed, 16, 16);


    canHangOnTile(tiles);

    if (upperCollision || bottomCollision) {
        hangingOnTileLeft = false;
        hangingOnTileRight = false;
    }


    if (!bottomCollision) {
        if ((right_middle == 0 && (right_up != 0 && right_down != 0))) {
            if (xSpeed > 0)
                x += 2;
        }
        if ((left_middle == 0 && (left_up != 0 && left_down != 0))) {
            if (xSpeed < 0)
                x -= 2;
        }
    }

}

void MainDude::init() {
    spriteGfxMemMain = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
    spriteGfxMemSub = oamAllocateGfx(&oamSub, SpriteSize_16x16, SpriteColorFormat_256Color);
    frameGfx = (u8 *) spelunkerTiles;
    dmaCopy(spelunkerPal, SPRITE_PALETTE, 512);
    dmaCopy(spelunkerPal, SPRITE_PALETTE_SUB, 512);
}


void MainDude::animate(int camera_x, int camera_y) {


    if (animationFrameTimer > 70) {
        animationFrameTimer = 0;
        animFrame++;
    }

    if (animFrame >= FRAMES_PER_ANIMATION) animFrame = 0;

    if (hangingOnTileRight) {
        int frame = (2 * 6) + 1;
        u8 *offset = frameGfx + frame * 16 * 16;
        dmaCopy(offset, spriteGfxMemMain, 16 * 16);
        dmaCopy(offset, spriteGfxMemSub, 16 * 16);


        if (this->y <= 320 + 16) {
            oamSet(&oamMain, 0, x - camera_x, y - camera_y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color,
                   spriteGfxMemMain, -1, false, false, false, false, false);
        } else
            oamSet(&oamMain, 0, -16, -16, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color,
                   0, -1, false, false, false, false, false);

        if (this->y >= 320) {
            oamSet(&oamSub, 0, x - camera_x, y - camera_y - 192, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color,
                   spriteGfxMemSub, -1, false, false, false, false, false);
        } else
            oamSet(&oamSub, 0, -16, -16, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color,
                   0, -1, false, false, false, false, false);

        return;
    }
    if (hangingOnTileLeft) {
        int frame = (2 * 6);
        u8 *offset = frameGfx + frame * 16 * 16;
        dmaCopy(offset, spriteGfxMemMain, 16 * 16);
        dmaCopy(offset, spriteGfxMemSub, 16 * 16);
        if (this->y <= 320) {
            oamSet(&oamMain, 0, x - camera_x, y - camera_y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color,
                   spriteGfxMemMain, -1, false, false, false, false, false);
        } else
            oamSet(&oamMain, 0, -16, -16, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color,
                   0, -1, false, false, false, false, false);


        if (this->y >= 320) {
            oamSet(&oamSub, 0, x - camera_x, y - camera_y - 192, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color,
                   spriteGfxMemSub, -1, false, false, false, false, false);
        } else
            oamSet(&oamSub, 0, -16, -16, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color,
                   0, -1, false, false, false, false, false);

        return;
    }

    int frame = animFrame + state * FRAMES_PER_ANIMATION;
    u8 *offset = frameGfx + frame * 16 * 16;
    dmaCopy(offset, spriteGfxMemMain, 16 * 16);
    dmaCopy(offset, spriteGfxMemSub, 16 * 16);
    if (this->y <= 320) {
        oamSet(&oamMain, 0, x - camera_x, y - camera_y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color,
               spriteGfxMemMain, -1, false, false, false, false, false);
    } else
        oamSet(&oamMain, 0, -16, -16, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color,
               0, -1, false, false, false, false, false);

    if (this->y >= 320) {
        oamSet(&oamSub, 0, x - camera_x, y - camera_y - 192, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color,
               spriteGfxMemSub, -1, false, false, false, false, false);
    } else
        oamSet(&oamSub, 0, -16, -16, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color,
               0, -1, false, false, false, false, false);

}

void MainDude::canHangOnTile(MapTile *neighboringTiles[9]) {

    if (bottomCollision || (!leftCollision && !rightCollision))
        return;

    if (neighboringTiles[2] != 0 || neighboringTiles[3] != 0)
        return;

    bool y_bound = false;
    bool x_bound = false;

    if (rightCollision && state == W_LEFT) {

        if (neighboringTiles[5] != 0)
            return;

        x_bound = (this->x <= (neighboringTiles[0]->x * 16) + 16 && (this->x >= (neighboringTiles[0]->x * 16) + 12));
        y_bound = (this->y > (neighboringTiles[0]->y * 16) - 2) && (this->y < (neighboringTiles[0]->y * 16) + 8);
    } else if (leftCollision && state == W_RIGHT) {

        if (neighboringTiles[6] != 0)
            return;

        y_bound = (this->y > (neighboringTiles[1]->y * 16) - 2) && (this->y < (neighboringTiles[1]->y * 16) + 8);
        x_bound = (this->x <= (neighboringTiles[1]->x * 16) - 12 && (this->x >= (neighboringTiles[1]->x * 16) - 16));
    }

    if ((y_bound && x_bound) && hangingTimer > MIN_HANGING_TIME) {
        hangingTimer = 0;
        ySpeed = 0;

        fprintf(stdout, "HANGING" + '\n');

        if (rightCollision) {
            this->y = (neighboringTiles[0]->y * 16);
            hangingOnTileRight = true;
        }
        if (leftCollision) {
            hangingOnTileLeft = true;
            this->y = (neighboringTiles[1]->y * 16);
        }
    }

}

//W spelunkach zwalnianie jes ttakże w powietrzu!
void MainDude::applyFriction() {

//    if (bottomCollision) {
    if (frictionTimer > FRICTION_DELTA_TIME_MS) {
        frictionTimer = 0;
        if (xSpeed > 0) {
            xSpeed -= FRICTION_DELTA_SPEED;
            if (xSpeed < 0)
                xSpeed = 0;
        }
        if (xSpeed < 0) {
            xSpeed += FRICTION_DELTA_SPEED;
            if (xSpeed > 0)
                xSpeed = 0;
        }
    }
//    }

}

void MainDude::update(int camera_x, int camera_y, int keys_held, int keys_down, LevelGenerator *l) {
    this->applyFriction();
    this->updateTimers(timerElapsed(0) / TICKS_PER_SECOND);
    this->animate(camera_x, camera_y);
    this->updateSpeed(l->mapTiles);
//    this->checkCollisionWithMap(l->mapTiles);
    this->handleKeyInput(keys_held, keys_down);
}

