#ifndef POKERANGER2_CGAME_HPP
#define POKERANGER2_CGAME_HPP

#include <nitro.h>

#include "CGame_0024.hpp"
#include "CTPEmulator.hpp"
#include "CTouchPanel.hpp"
#include "UnkClass_02001C04.hpp"
#include "UnkClass_020023EC.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200CFF4.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0200E330.hpp"
#include "UnkClass_020B26A0.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

extern "C" void *sub_020101A8(u32 size);

typedef void (*CGame_020100E4_arg0)(void *);

class UnkClass_0200D3F8;

struct UnkStruct_02010D04 {
    u8 unk_00[0xC];
    u8 unk_0C;
    u8 unk_0D[0x7];
    u8 unk_14;
    u8 unk_15[0x3];
    u32 unk_18[8];
    u32 unk_38[8];
    u8 unk_58[0x14];
    u8 unk_6C;
};

class UnkClass_0201164C {
public:
    u8 unk_00[0x3];
    u8 unk_03;
    u32 unk_04;
    u32 unk_08;
};

class CGame {
public:
    CGame();

    void *operator new(size_t size)
    {
        return sub_020101A8(size);
    }

    inline void func0()
    {
        MI_DmaCopy32(3, unk_0824, unk_0024, 0x400);
        MI_DmaCopy32(3, unk_0824, unk_0424, 0x400);
    }

    inline UnkClass_020023EC *GetPrinter()
    {
        return unk_0C24;
    }

    void sub_0200FB28();
    BOOL sub_020100E4(CGame_020100E4_arg0 arg0, void *arg1);
    void sub_020101B4(char *arg0);
    void sub_0201028C();
    void sub_020102E8();
    void sub_02010448();
    void sub_0201044C();

public:
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    CScene *currentScene;
    u32 unk_0010;
    UnkClass_02001C04 *unk_0014;
    CTouchPanel *touchPanel;
    CTPEmulator *touchPanelEmulator;
    CTouchPanel *activeTouchPanel;
    CGame_0024 unk_0024[0x80];
    CGame_0024 unk_0424[0x80];
    CGame_0024 unk_0824[0x80];
    UnkClass_020023EC *unk_0C24;
    UnkClass_020023EC *unk_0C28;
    u8 unk_0C2C[0x808];
    void *unk_1434;
    u8 unk_1438[0x4];
    void *unk_143C;
    u8 unk_1440[0x4];
    UnkStruct_02010D04 *unk_1444;
    u8 unk_1448[0x24];
    u16 unk_146C[16];
    void *m_audioEngine;
    UnkClass_020091E8 *m_textboxData;
    void *unk_1494;
    void *unk_1498;
    void *m_scriptManager;
    UnkClass_0201164C *m_missionQuestData;
    UnkClass_020B26A0 *unk_14A4;
    u32 unk_14A8;
    UnkClass_0200CFF4 *unk_14AC;
    void *unk_14B0;
    u32 unk_14B4;
    UnkClass_0200D3F8 *unk_14B8;
    UnkClass_0200E0B4 *unk_14BC;
    UnkClass_0200E0B4 *unk_14C0;
    UnkClass_0200E330 *unk_14C4;
    UnkClass_0200E330 *unk_14C8;
    u8 unk_14CC[0x114];
    u32 unk_15E0;
};

STATIC_SIZE_ASSERT(CGame, 0x15E4);

extern CGame *s_game;

#endif // POKERANGER2_CGAME_HPP
