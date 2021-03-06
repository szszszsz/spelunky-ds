//
// Created by xdbeef on 04.03.18.
// CURRENTLY NOT USED
//

#include <nds/arm9/console.h>
#include <cstdio>
#include <iostream>
#include "TextManager.h"
#include "../../build/font.h"

void TextManager::initConsole() {
    const int tile_base = 2;
    const int map_base = 8;

    consoleInit(printConsole, 0, BgType_Text4bpp, BgSize_T_256x256, map_base, tile_base, true, false);

    ConsoleFont font;

    font.gfx = (u16 *) fontTiles;
    font.pal = (u16 *) fontPal;
    font.numChars = 59;
    font.numColors = 2 /*fontPalLen / 2*/;
    font.bpp = 4;
    font.asciiOffset = 32;
    font.convertSingleColor = true;
    consoleSetFont(printConsole, &font);

}



void TextManager::printIntro() {

//    updateTimer(intro_timers, Timer.getTimeElapsedMs());

    for (int a = 0; a < 3; a++) {
        if (intro_timers[a] <= 0 && printed_lines[a] == 0) {
            std::printf(intro_lines[a]);
            printed_lines[a] = 1;
        }
    }

    if (console_clear <= 0 && console_cleared == 0) {
        consoleClear();
        console_cleared = 1;
    }
}


void TextManager::updateTimer(int introTimers[], int timeElapsed) {
    for (int a = 0; a < 3; a++) {
        if (introTimers[a] >= 0) {
            introTimers[a] -= timeElapsed;
        }
    }
    console_clear -= timeElapsed;
}

