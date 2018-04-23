//
// Created by xdbeef on 24.03.18.
//

#include <nds/arm9/sprite.h>
#include <cstdio>
#include <iostream>
#include "Hud.h"
#include "../../build/heart.h"
#include "../../build/dollar.h"
#include "../../build/bomb_hud.h"
#include "../../build/rope.h"
#include "../../build/holding_item.h"
#include "../Globals.h"

#define HEART_POSITION_X 5
#define HEART_POSITION_Y 5

#define BOMB_POSITION_X 45
#define BOMB_POSITION_Y 5

#define ROPE_POSITION_X 85
#define ROPE_POSITION_Y 5

#define DOLLAR_POSITION_X 125
#define DOLLAR_POSITION_Y 5

#define HOLDING_ITEM_FRAME_POSITION_X 5
#define HOLDING_ITEM_FRAME_POSITION_Y 20

void Hud::init() {

    heartSpriteInfo = global::main_oam_manager->initSprite(heartPal, heartPalLen, heartTiles, heartTilesLen, 16, HUD_HEART, true, false);
    dollarSpriteInfo = global::main_oam_manager->initSprite(dollarPal, dollarPalLen, dollarTiles, dollarTilesLen, 16, HUD_DOLLAR, true, false);
    bombSpriteInfo = global::main_oam_manager->initSprite(bomb_hudPal, bomb_hudPalLen, bomb_hudTiles, bomb_hudTilesLen, 16, HUD_BOMB, true, false);
    ropeSpriteInfo = global::main_oam_manager->initSprite(ropePal, ropePalLen, ropeTiles, ropeTilesLen, 16, HUD_ROPE, true, false);
    holdingItemSpriteInfo = global::main_oam_manager->initSprite(holding_itemPal, holding_itemPalLen, holding_itemTiles, holding_itemTilesLen, 16, HUD_HOLDING_ITEM, true, false);

    heartSpriteInfo->entry->x = HEART_POSITION_X;
    heartSpriteInfo->entry->y = HEART_POSITION_Y;

    bombSpriteInfo->entry->x = BOMB_POSITION_X;
    bombSpriteInfo->entry->y = BOMB_POSITION_Y;

    dollarSpriteInfo->entry->x = DOLLAR_POSITION_X;
    dollarSpriteInfo->entry->y = DOLLAR_POSITION_Y;

    ropeSpriteInfo->entry->x = ROPE_POSITION_X;
    ropeSpriteInfo->entry->y = ROPE_POSITION_Y;

    holdingItemSpriteInfo->entry->x = HOLDING_ITEM_FRAME_POSITION_X;
    holdingItemSpriteInfo->entry->y = HOLDING_ITEM_FRAME_POSITION_Y;

    std::cout << '\n' << "   4    4    4    1000" ;

}

void Hud::draw() {
    //nothing
}