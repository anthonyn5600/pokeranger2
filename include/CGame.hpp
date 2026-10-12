#ifndef POKERANGER2_CGAME_HPP
#define POKERANGER2_CGAME_HPP

#include <nitro.h>

#include "CGame_0024.hpp"
#include "CTPEmulator.hpp"
#include "CTouchPanel.hpp"
#include "UnkClass_02001C04.hpp"
#include "UnkClass_020023EC.hpp"
#include "UnkClass_02008D50.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200C38C.hpp"
#include "UnkClass_0200CAB4.hpp"
#include "UnkClass_0200CFF4.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0200E330.hpp"
#include "UnkClass_0200FA5C.hpp"
#include "UnkClass_02010470.hpp"
#include "UnkClass_02010854.hpp"
#include "UnkClass_02010C3C.hpp"
#include "UnkClass_02010D2C.hpp"
#include "UnkClass_02018208.hpp"
#include "UnkClass_02033F04.hpp"
#include "UnkClass_02034478.hpp"
#include "UnkClass_02041C80.hpp"
#include "UnkClass_020B26A0.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

typedef void (*CGame_020100E4_arg0)(void *);

class UnkClass_0200D3F8;

// RTTI name; ctor still asm
class CBattleResultParameter {
public:
    CBattleResultParameter();

public:
    u8 unk_00[0x8];
    u32 unk_08;
    u8 unk_0C;
    u8 unk_0D[0x7];
    u8 unk_14;
    u8 unk_15[0x3];
    u32 unk_18[8];
    u32 unk_38[8];
    u8 unk_58[0x14];
    u8 unk_6C;
    u8 unk_6D[0x17];
};

STATIC_SIZE_ASSERT(CBattleResultParameter, 0x84);

class UnkClass_0201164C {
public:
    u8 unk_00[0x3];
    u8 unk_03;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
};

class CGame {
public:
    CGame();

    void *operator new(size_t size);

    static CGame *GetInstance();

    inline void func0()
    {
        MI_DmaCopy32(3, unk_0824, unk_0024, 0x400);
        MI_DmaCopy32(3, unk_0824, unk_0424, 0x400);
    }

    inline UnkClass_020023EC *GetPrinter()
    {
        return unk_0C24;
    }

    void sub_0200FA74();
    void sub_0200FAA4();
    void sub_0200FAEC();
    void sub_0200FB28();
    void sub_0201002C();
    BOOL sub_020100E4(CGame_020100E4_arg0 arg0, void *arg1);
    void sub_02010124();
    CTouchPanel *sub_02010178(int mode);
    void sub_020101B4(char *arg0);
    void sub_020101F4(u32 texSize, u32 texSize4x4, u32 plttSize);
    void sub_0201024C();
    void sub_0201028C();
    void sub_020102E8();
    void sub_02010324();
    BOOL sub_02010378();
    void sub_02010400();
    void sub_02010448();
    void sub_0201044C();

    static CGame *sInstance;

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
    void *m_texVramWork;
    void *m_plttVramWork;
    NNSGfdVramTransferTask m_vramTransferTasks[0x80];
    UnkClass_02010470 *unk_1434;
    UnkClass_02010D2C *unk_1438;
    UnkClass_02010854 *unk_143C;
    UnkClass_02010C3C *unk_1440;
    CBattleResultParameter *unk_1444;
    MATHRandContext32 m_rand32;
    MATHRandContext16 m_rand16;
    UnkClass_02008D50 unk_146C;
    UnkClass_02034478 *m_audioEngine;
    UnkClass_020091E8 *m_textboxData;
    UnkClass_0200C38C *unk_1494;
    UnkClass_0200CAB4 *unk_1498;
    UnkClass_02033F04 *m_scriptManager;
    UnkClass_0201164C *m_missionQuestData;
    UnkClass_020B26A0 *unk_14A4;
    u32 unk_14A8;
    UnkClass_0200CFF4 *unk_14AC;
    UnkClass_02018208 *unk_14B0;
    void *unk_14B4;
    UnkClass_0200D3F8 *unk_14B8;
    UnkClass_0200E0B4 *unk_14BC;
    UnkClass_0200E0B4 *unk_14C0;
    UnkClass_0200E330 *unk_14C4;
    UnkClass_0200E330 *unk_14C8;
    UnkClass_02041C80 *unk_14CC;
    CGame_020100E4_arg0 m_vblankCallbacks[0x20];
    void *m_vblankArgs[0x20];
    s32 unk_15D0;
    u32 unk_15D4;
    UnkClass_0200FA5C *unk_15D8;
    u32 unk_15DC;
    u32 unk_15E0;
};

STATIC_SIZE_ASSERT(CGame, 0x15E4);

extern CGame *s_game;

#endif // POKERANGER2_CGAME_HPP
