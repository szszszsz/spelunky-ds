//
// Created by xdbeef on 01.04.18.
//

#ifndef SPELUNKYDS_OAMMANAGER_H
#define SPELUNKYDS_OAMMANAGER_H

#define MAX_SPRITE_NUMBER 128

#include "../level_layout/SpriteInfo.h"
#include "../sprites/SpriteTypes.h"
#include "OamType.h"


class OAMManager {
public:
    OamType oamType;
    int offset_multiplier;
    u16 *sprite_address;
    u16 *palette_address;
    u16 *oam_address;

    u32 current_oam_id_palette = 0;
    u32 current_oam_id_tiles = 0;

    /* Keep track of the available tiles */
    u16 nextAvailableTileIdx = 0;

    OAMTable *oam;

    void initOAMTable(u16 *spriteAddress, u16 *paletteAddress, u16 *oam_address, int offset_multiplier, OamType o);

    void updateOAM();

    SpriteInfo *initSprite(const unsigned short pallette[], int palLen, const unsigned int tiles[], int tilesLen,
                           int size, SpriteType spriteType, bool reuse_palette, bool reuse_tiles);

    void clearAllSprites();
};


#endif //SPELUNKYDS_OAMMANAGER_H
