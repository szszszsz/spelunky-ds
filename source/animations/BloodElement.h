//
// Created by xdbeef on 28.04.18.
//

#ifndef SPELUNKYDS_BLOODELEMENT_H
#define SPELUNKYDS_BLOODELEMENT_H


#include "../sprites/MovingObject.h"

class BloodElement : public MovingObject {

public:

    void updateOther() override {};

    void init() override;

    void draw() override;

    void updateTimers() override {};

    void updatePosition() override ;

    void updateSpeed() override;

    void updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) override;

    void updateCollisionsOtherMoving() override {};

    void onCollisionWithMainCharacter() override {};


    SpriteInfo *mainSpriteInfo = nullptr;
    SpriteInfo *subSpriteInfo = nullptr;

    u8 * frameGfx;

    int currentFrame;
    int frameTimer;
    int pos_inc_timer;
    bool finished;
};



#endif //SPELUNKYDS_BLOODELEMENT_H
