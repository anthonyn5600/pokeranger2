#ifndef POKERANGER2_BGLAYER_HPP
#define POKERANGER2_BGLAYER_HPP

#include <nitro.h>

#include "common.hpp"
#include "file/CArchiveGuard.hpp"

// Sets the affine parameters of OAM affine set `index` of the main (mainScreen != 0) or sub screen OAM buffer
void SetOamAffine(int index, const MtxFx22 *mtx, BOOL mainScreen);
void SetOamAffineScale(int index, fx32 sx, fx32 sy, BOOL mainScreen);

// BGS archive loaders (data/<dir><name>LZ.bin holding <name>.NCGR/.NCLR/.NSCR); the loaded size and the screen
// size of the last NSCR are left in gBGLoadedSize/sScreenWidth/sScreenHeight
extern u32 gBGLoadedSize;

CArchiveGuard *BGS_OpenArchive(const char *path);
CArchiveGuard *BGS_OpenArchiveLZ(const char *dir, const char *name);
int BGS_LoadCharAndPltt(const char *dir, const char *name, int bg, const char *charName, u32 charOffset, const char *plttName, u32 plttOffset);
void *BGS_LoadCharByName(const char *arc, int bg, const char *name, u32 offset, int mode, u32 arg5);
void *BGS_LoadCharFile(const char *path, int bg, u32 arg2, u32 offset, int mode);
void BG_LoadChar(int bg, void *data, u32 size, u32 offset);
void BG_LoadCharRaw(int bg, void *data, u32 size, u32 offset);
BOOL BG_Is256Color(int bg);
void *BGS_LoadPlttByName(const char *arc, int bg, const char *name, u32 offset, int mode, u32 arg5);
void *BGS_LoadPlttFile(const char *path, int bg, u32 arg2, u32 offset, int mode);
void BG_LoadPltt(int bg, void *data, u32 size, u32 offset, BOOL ext);
void *BGS_LoadScr(const char *dir, const char *name, int bg, const char *scrName, u32 arg4, u32 arg5, int mode, u32 arg7);
void *BGS_LoadScrByName(const char *arc, int bg, const char *name, u32 arg3, u32 arg4, int mode, u32 arg6, u32 offset);
void *BGS_LoadScrFile(const char *path, int bg, u32 arg2, u32 plttNo, u32 charAdd, int mode, u32 offset);
void BG_LoadScr(int bg, void *data, u32 size, u32 offset);

// A text BG layer (bg 0..3 main, 4..7 sub) with its character/palette/screen data kept in RAM; Scroll() copies the
// newly visible tiles of the (up to 512x512) screen into the 64x64 VRAM screen
class BGLayer {
public:
    BGLayer();
    BGLayer(int arg0);
    ~BGLayer();
    void Init();
    void Release();
    void LoadCharToVram();
    void LoadCharToVramPartial(int step, int steps);
    void LoadPlttToVram(BOOL ext);
    void Setup(int width, int height);
    void *GetScrPtr();
    void LoadScrToVram();
    void LoadToVram();
    void Draw(int x, int y);
    void Scroll(int x, int y);
    void CopyTiles(int x, int y, int width, int height);
    void GetTileRect(int *x, int *y, int *width, int *height);
    u16 *GetTilePtr(u16 *scr, int x, int y, int width, int height);
    void SetBG(int bg);
    void SetOffset(int x, int y);
    void LoadArchive(const char *dir, const char *name);
    void ReleaseArchive();
    void *LoadChar(const char *name, int mode, u32 offset, u32 arg3);
    void *LoadPltt(const char *name, int mode, u32 offset, u32 arg3);
    void *LoadScr(const char *name, int mode, u32 arg2, u32 charAdd, u32 offset, u32 arg5);
    void *LoadScrFile(const char *path, int mode, u32 plttNo, u32 charAdd, u32 offset, u32 arg5);
    void FreeChar();
    void FreePltt();
    void FreeScr();

public:
    u32 unk_00; // char VRAM offset
    u32 unk_04; // char size
    void *unk_08; // char data
    u32 unk_0C; // palette VRAM offset
    u32 unk_10; // palette size
    void *unk_14; // palette data
    u32 unk_18; // screen VRAM offset
    u32 unk_1C; // screen size
    void *unk_20; // screen data
    void *unk_24; // VRAM screen base
    int unk_28; // bg (0..3 main, 4..7 sub)
    u32 unk_2C;
    u32 unk_30;
    int unk_34; // screen width (px)
    int unk_38; // screen height (px)
    u32 unk_3C;
    u32 unk_40;
    int unk_44; // VRAM screen width (px, 0x100)
    int unk_48; // VRAM screen height (px, 0x100)
    int unk_4C; // view width (px)
    int unk_50; // view height (px)
    int unk_54; // scroll x
    int unk_58; // scroll y
    CArchiveGuard *unk_5C;
    int unk_60;
};
STATIC_SIZE_ASSERT(BGLayer, 0x64);

#endif // POKERANGER2_BGLAYER_HPP
