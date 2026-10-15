// What the game's ROM header says (ranger2.us/rom.ini) and its overlay count (ranger2.us/main.lsf), for ntros's card
#include "ntros.h"

extern "C" const NtrOsCartridge NtrOs_Cartridge = {
    "POKE RANGER2", // title
    "YP2E", // game code
    "01", // maker code
    0, // revision
    30, // overlays (ARM9; the ARM7 has none)
    "pokeranger2.sav",
};
