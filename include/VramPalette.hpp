#ifndef POKERANGER2_VRAMPALETTE_HPP
#define POKERANGER2_VRAMPALETTE_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"
#include "file/CNCLRFile.hpp"

// Palette loaded into palette VRAM (arm9_02007AA4.s).
class VramPalette {
public:
    VramPalette();
    VramPalette(const char *path, u32 arg1, u32 arg2);
    VramPalette(NNSG2dPaletteData *data);
    ~VramPalette();

    void Init();
    void Load(const char *path, u32 arg1, u32 arg2);
    void SetData(NNSG2dPaletteData *data);
    void Release();
    void LoadToVram(u32 addr);
    void LoadToVramDeferred(u32 addr);

    static void LoadToVramCallback(void *data);

    NNSG2dPaletteData *GetData()
    {
        return unk_04;
    }

public:
    CNCLRFile *unk_00;
    NNSG2dPaletteData *unk_04;
    NNSG2dImagePaletteProxy unk_08;
    u32 unk_1C;
    u8 unk_20;
};

STATIC_SIZE_ASSERT(VramPalette, 0x24);

#endif // POKERANGER2_VRAMPALETTE_HPP
