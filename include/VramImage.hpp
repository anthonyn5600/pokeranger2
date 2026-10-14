#ifndef POKERANGER2_VRAMIMAGE_HPP
#define POKERANGER2_VRAMIMAGE_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"
#include "file/CNCGRFile.hpp"

class VramImage {
public:
    VramImage();
    VramImage(const char *arg0, u32 arg1, u32 arg2, u32 arg3);
    VramImage(NNSG2dCharacterData *arg0);
    ~VramImage();

    void Init();
    void Load(const char *arg0, u32 arg1, u32 arg2, u32 arg3);
    void SetData(NNSG2dCharacterData *arg0);
    void Release();
    void LoadToVram(u32 arg0);
    void LoadToVramDeferred(u32 arg0);

    static void LoadToVramCallback(void *data);

    inline u8 *func0()
    {
        return (u8 *)unk_04->pRawData;
    }

public:
    CNCGRFile *unk_00;
    NNSG2dCharacterData *unk_04;
    NNSG2dImageProxy unk_08;
    u32 unk_2C;
    u8 unk_30;
    u16 unk_32;
    u16 unk_34;
    u32 unk_38;
};

STATIC_SIZE_ASSERT(VramImage, 0x3C);

#endif // POKERANGER2_VRAMIMAGE_HPP
