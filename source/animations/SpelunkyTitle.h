//
// Created by xdbeef on 29.04.18.
//

#ifndef SPELUNKYDS_STATICSPRITE_H
#define SPELUNKYDS_STATICSPRITE_H


#include "../sprites/MovingObject.h"

class SpelunkyTitle : public MovingObject {

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

    SpriteInfo *mainSpriteInfo_1 = nullptr;
    SpriteInfo *mainSpriteInfo_2 = nullptr;
    SpriteInfo *mainSpriteInfo_3 = nullptr;

    SpriteInfo *subSpriteInfo_1 = nullptr;
    SpriteInfo *subSpriteInfo_2 = nullptr;
    SpriteInfo *subSpriteInfo_3 = nullptr;

    OamType oamType;
};




#endif //SPELUNKYDS_STATICSPRITE_H
