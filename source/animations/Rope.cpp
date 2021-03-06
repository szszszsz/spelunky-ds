//
// Created by xdbeef on 04.04.18.
//

#include <maxmod9.h>
#include "../Globals.h"
#include "../level_layout/MapUtils.h"
#include "Collisions.h"
#include "../../build/ropes.h"
#include "Rope.h";
#include "../../build/soundbank.h"


void Rope::draw() {


    if (hold_by_main_dude) {

        y = global::main_dude->y + 6;

        if (global::main_dude->state == 1) {
            x = global::main_dude->x - 2;
        } else
            x = global::main_dude->x + 10;
    }

    int main_x = x - global::camera->x;
    int main_y = y - global::camera->y;
    int sub_x = x - global::camera->x;
    int sub_y = y - global::camera->y - 192;

    for (int a = 0; a < ropeChain.size(); a++) {
        ropeChain.at(a)->draw();
        ropeChain.at(a)->update();
    }

    if (global::camera->y + 192 > this->y + 8 || global::camera->y + 192 + 192  < this->y - 8) {
        sub_x = -128;
        sub_y = -128;
    }
    if (global::camera->y > this->y + 8 || global::camera->y + 192 < this->y - 8) {
        main_x = -128;
        main_y = -128;
    }


    if (activated_by_main_dude && !thrown && !finished) {
        mmEffect(SFX_XTHROW);

        thrown = true;
        throwingTimer = 0;

        //todo apply this pattern to the bomb class
        global::main_dude->holding_item = false;
        hold_by_main_dude = false;

        x = floor_div(global::main_dude->x + 0.5 * MAIN_DUDE_WIDTH, 16) * TILE_W + ROPE_SIZE * 0.5;
        y -= 16;
        ySpeed = -4;
    }
    if (thrown && !finished) {
        throwingTimer += *timer;

        int temp_y = floor_div(this->y + (0.5 * ROPE_SIZE), 16);

        if (!isThereChainForThisTile(temp_y * TILE_H)) {


            if (temp_y * TILE_H > y) {

                RopeElement *element = new RopeElement();
                element->init();

                element->x = x;
                element->y = temp_y * TILE_H;

                element->draw();

                ropeChain.push_back(element);
                if (ropeChain.size() == 8) {
                    throwingFinished();
                    finished = true;
                }
            }
        }
    }

    //checking if main dude can climb over the rope

    bool onTopOfClimbingSpace = global::main_dude->y < y + 6;
    global::main_dude->onTopOfClimbingSpace = onTopOfClimbingSpace;

    for (int a = 0; a < ropeChain.size(); a++) {

        if (ropeChain.at(a)->x  + 5> global::main_dude->x &&
            ropeChain.at(a)->x + 5 < global::main_dude->x + MAIN_DUDE_WIDTH &&
            ropeChain.at(a)->y + 5 > global::main_dude->y &&
            ropeChain.at(a)->y - 5 < global::main_dude->y + MAIN_DUDE_HEIGHT
            && !onTopOfClimbingSpace) {
//            std::cout<< " CA NCLIMB " << '\n';
            if (!global::input_handler->r_bumper_down) {
                global::main_dude->canClimbRope = true;
                if(global::input_handler->up_key_held){
                    global::main_dude->x = ropeChain.at(a)->x - 4;
                }
            }

            break;
        } else {
//            std::cout<< " NOT" << '\n';
        }
    }

    mainSpriteInfo->entry->x = main_x;
    mainSpriteInfo->entry->y = main_y;

    subSpriteInfo->entry->x = sub_x;
    subSpriteInfo->entry->y = sub_y;

}


void Rope::init() {
    subSpriteInfo = global::sub_oam_manager->initSprite(ropesPal, ropesPalLen,
                                                        nullptr, 8 * 8, 8, ROPES, true, false);
    mainSpriteInfo = global::main_oam_manager->initSprite(ropesPal, ropesPalLen,
                                                          nullptr, 8 * 8, 8, ROPES, true, false);
    notThrown();
}

void Rope::notThrown() {
    frameGfx = (u8 *) ropesTiles + 1 * 8 * 8 / 2;
    subSpriteInfo->updateFrame(frameGfx, 8 * 8);
    mainSpriteInfo->updateFrame(frameGfx, 8 * 8);
}

void Rope::throwingFinished() {
    frameGfx = (u8 *) ropesTiles + (2 * 8 * 8 / 2);
    subSpriteInfo->updateFrame(frameGfx, 8 * 8);
    mainSpriteInfo->updateFrame(frameGfx, 8 * 8);
}

void Rope::updateSpeed() {

    if (xSpeed > MAX_X_SPEED_ROPE)
        xSpeed = MAX_X_SPEED_ROPE;
    if (xSpeed < -MAX_X_SPEED_ROPE)
        xSpeed = -MAX_X_SPEED_ROPE;

    if (ySpeed > MAX_Y_SPEED_ROPE)
        ySpeed = MAX_Y_SPEED_ROPE;
    if (ySpeed < -MAX_Y_SPEED_ROPE)
        ySpeed = -MAX_Y_SPEED_ROPE;

    pos_inc_timer += *timer;

    bool change_pos = (pos_inc_timer > 15) && !hold_by_main_dude && !finished;

    if (change_pos) {
        updatePosition();
    }

}

void Rope::updatePosition() {

    if (bottomCollision && xSpeed > 0) {
        xSpeed -= 0.055;
        if (xSpeed < 0)
            xSpeed = 0;
    }
    if (bottomCollision && xSpeed < 0) {
        xSpeed += 0.055;
        if (xSpeed > 0)
            xSpeed = 0;
    }

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

//            Collisions::getCenterTile(this->x, this->y, MAIN_DUDE_HEIGHT, MAIN_DUDE_WIDTH, xx, yy);
//fixme

        xx = floor_div(this->x + 0.5 * ROPE_SIZE, 16);
        yy = floor_div(this->y + 0.5 * ROPE_SIZE, 16);

        if (old_xx != xx || old_yy != yy) {
            updateCollisionsMap(xx, yy);
        }

        old_xx = xx;
        old_yy = yy;

        tempXspeed--;
        tempYspeed--;
    }


//    if (!bottomCollision)
//        ySpeed += GRAVITY_DELTA_SPEED;

    pos_inc_timer = 0;
}

void Rope::onCollisionWithMainCharacter() {
}

void Rope::updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) {

    MapTile *tiles[9];
    Collisions::getNeighboringTiles(global::level_generator->mapTiles, x_current_pos_in_tiles, y_current_pos_in_tiles,
                                    tiles);

    bottomCollision = Collisions::checkBottomCollision(tiles, &x, &y, &ySpeed, 8, 8, true);
    leftCollision = Collisions::checkLeftCollision(tiles, &x, &y, &xSpeed, 8, 8, true);
    rightCollision = Collisions::checkRightCollision(tiles, &x, &y, &xSpeed, 8, 8, true);
    upperCollision = Collisions::checkUpperCollision(tiles, &x, &y, &ySpeed, 8, false);

    if (upperCollision) {
        if (!finished) {
            throwingFinished();
            finished = true;
        }
    }

}

bool Rope::isThereChainForThisTile(int rope_y) {
    for (int a = 0; a < ropeChain.size(); a++) {
        if (ropeChain.at(a)->y == rope_y)
            return true;
    }
    return false;
}

