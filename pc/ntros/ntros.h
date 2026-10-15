// ntros: the PC port's own DS system layer, replacing libntr's OS parts in stages (stage 2). Written from the
// NitroSDK's behaviour (subprojects/NitroSDK-4.1.30001 in the repo: the SDK the DS build links) and the hardware's
// timing (GBATEK; melonDS as the reference for what the hardware does).
//
// So far: interrupts (IE/IF/IME, the interrupt table), the display timeline (263 lines per frame: VCOUNT, DISPSTAT,
// VBlank / HBlank / VCount-match interrupts), the tick clock, alarms, v-alarms, the interrupt waits
// (OS_WaitVBlankIntr, OS_WaitIrq), threads, and the game card (ROM files from a folder, romfs.cpp;
// .sav backup memory, card.cpp).
//
// Timing model: game code takes no time. The DS clock moves only while the game waits for an interrupt; then the
// display timeline runs line by line, raising interrupts and drawing lines as the hardware would, until what the
// game waits for has happened. Interrupt handlers therefore run only inside those waits (or at once when the game
// enables an interrupt that is already pending, as on hardware), always on the thread that runs the game's main loop.
#ifndef NTROS_H
#define NTROS_H

#ifdef __cplusplus
extern "C" {
#endif

// The screens, driven by the timeline. Every callback is optional.
typedef struct NtrOsDisplay {
    void (*beginFrame)(void); // line 0 starts
    void (*drawLine)(int y); // line y (0..191) is drawn now, with the registers and memory as they are
    void (*endFrame)(void); // line 191 is done: show the picture (and read input, pace to 60 Hz)
    void (*vblank)(void); // line 192 starts, just before the VBlank interrupt (the 3D engine swaps its lists here)
} NtrOsDisplay;
void NtrOs_SetDisplay(const NtrOsDisplay *display);

// The game card. The port defines NtrOs_Cartridge (what the ROM header says about the game). The ROM's files come
// from a folder ($NTR_FILES, else "files"), the backup memory from a raw .sav file ($NTR_SAVE, else saveName).
typedef struct NtrOsCartridge {
    const char *title; // header: game title (up to 12 characters)
    const char *gameCode; // header: 4 characters
    const char *makerCode; // header: 2 characters
    unsigned char revision; // header: ROM version
    int overlays; // ARM9 + ARM7 overlays: they take the first file IDs
    const char *saveName; // default save file
} NtrOsCartridge;
extern const NtrOsCartridge NtrOs_Cartridge;

// Current position on the display timeline: frame number (since start), line (0..262)
unsigned long long NtrOs_GetFrame(void);
int NtrOs_GetLine(void);

#ifdef __cplusplus
}
#endif

#endif // NTROS_H
