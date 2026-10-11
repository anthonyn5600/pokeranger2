#include "CGame.hpp"

#include <nitro.h>

#include "UnkClass_0200D3F8.hpp"
#include "heap.hpp"

struct UnkStruct_02010EC8 {
    u8 unk_00[0x14];
};

extern "C" {
void sub_02010F18(UnkStruct_02010EC8 *obj);
void sub_0201128C(void *obj);
void sub_0201135C(UnkClass_0201164C *obj);
void sub_02011394(UnkClass_0201164C *obj, UnkClass_02033F04 *scriptManager, UnkClass_020091E8 *textboxData);
void sub_02015198(UnkClass_020B26A0 *obj);
void sub_02018E1C(void *obj);
void sub_0201926C(void *obj, int index, s32 value);
s32 sub_02019278(void *obj, int index);
void sub_02034384(UnkClass_02033F04 *scriptManager);

extern UnkClass_0201164C MAIN_BSS_020B2638;
extern UnkClass_020B26A0 MAIN_BSS_020B26A0;
extern u8 MAIN_BSS_0210C0B0[];
extern u8 MAIN_BSS_020AF598[];
extern UnkStruct_02010EC8 MAIN_BSS_020AF5D0;
extern UnkStruct_02010EC8 MAIN_BSS_020AF5E4[3];
}

CGame *CGame::sInstance;

static inline void ResetTimers()
{
    sub_02010F18(&MAIN_BSS_020AF5D0);
    for (int i = 0; i < 3; i++) {
        sub_02010F18(&MAIN_BSS_020AF5E4[i]);
    }
    sub_0201128C(MAIN_BSS_020AF598);
}

void CGame::sub_0200FA74()
{
    sub_0201135C(m_missionQuestData);
    sub_02018E1C(unk_14B4);
    sub_02015198(unk_14A4);
}

void CGame::sub_0200FAA4()
{
    sub_0200FA74();
    ResetTimers();
}

void CGame::sub_0200FAEC()
{
    sub_0200FA74();
    for (int i = 0; i < 0x20; i++) {
        m_vblankCallbacks[i] = NULL;
    }
    unk_15E0 = 1;
}

void CGame::sub_0200FB28()
{
    sub_0200FAEC();
    unk_0008 = -1;
    m_audioEngine->sub_02034B9C(0);
}

CGame::CGame()
{
    sInstance = this;

    unk_0014 = new UnkClass_02001C04();
    touchPanel = new CTouchPanel();
    touchPanelEmulator = new CTPEmulator();
    sub_02010178(0);
    unk_14A8 = 0;

    NNS_GfdInitVramTransferManager(m_vramTransferTasks, 0x80);
    u32 workSize = NNS_GfdGetLnkTexVramManagerWorkSize(0x20);
    m_texVramWork = Heap_AllocSecondary(workSize);
    NNS_GfdInitLnkTexVramManager(0x80000, 0, m_texVramWork, workSize, TRUE);
    workSize = NNS_GfdGetLnkPlttVramManagerWorkSize(0x20);
    m_plttVramWork = Heap_AllocSecondary(workSize);
    NNS_GfdInitLnkPlttVramManager(0x4000, m_plttVramWork, workSize, TRUE);

    for (u8 i = 0; i < 0x80; i++) {
        unk_0824[i].attr0 = 0x200;
    }

    unk_0C24 = new UnkClass_020023EC();
    unk_0C28 = new UnkClass_020023EC();
    unk_1434 = new UnkClass_02010470(unk_14A8);
    unk_1438 = new UnkClass_02010D2C(0);
    unk_143C = new UnkClass_02010854();
    unk_1440 = new UnkClass_02010C3C();
    unk_1444 = new CBattleResultParameter();
    unk_14CC = new UnkClass_02041C80("data/field/fielddata.bin", 0);
    MATHRandContext32 *ctx32 = &m_rand32;
    MATH_InitRand32(ctx32, 0x1234);
    MATHRandContext16 *ctx16 = &m_rand16;
    MATH_InitRand16(ctx16, 0x4321);
    unk_0000 = 0;
    unk_146C.sub_02008DB4(30);

    m_audioEngine = new UnkClass_02034478();
    unk_14AC = new UnkClass_0200CFF4(1);
    unk_14B0 = new UnkClass_02018208();
    m_textboxData = new UnkClass_020091E8();
    unk_1494 = new UnkClass_0200C38C(&unk_14AC->unk_14, unk_14B0);
    unk_1498 = new UnkClass_0200CAB4(&unk_14AC->unk_14, unk_14B0);
    m_scriptManager = new UnkClass_02033F04(unk_14A8);
    m_missionQuestData = &MAIN_BSS_020B2638;
    sub_02011394(m_missionQuestData, m_scriptManager, m_textboxData);
    unk_14A4 = &MAIN_BSS_020B26A0;
    unk_14B4 = MAIN_BSS_0210C0B0;
    sub_02018E1C(unk_14B4);

    unk_14B8 = new UnkClass_0200D3F8(NULL);
    unk_14BC = new UnkClass_0200E0B4(1, 0x10);
    unk_14C0 = new UnkClass_0200E0B4(2, 0x10);
    unk_14C4 = new UnkClass_0200E330(1);
    unk_14C8 = new UnkClass_0200E330(2);
    unk_15D4 = 1;
    unk_15D0 = 0;
    unk_15D8 = new UnkClass_0200FA5C();
    unk_15E0 = 1;
    ResetTimers();
}

CGame *CGame::GetInstance()
{
    return sInstance;
}

void CGame::sub_0201002C()
{
    unk_146C.sub_02008E68();

    if (unk_15E0) {
        for (int i = 0; i < 0x20; i++) {
            if (m_vblankCallbacks[i] != NULL) {
                m_vblankCallbacks[i](m_vblankArgs[i]);
                m_vblankCallbacks[i] = NULL;
            }
        }
        NNS_GfdDoVramTransfer();
        sub_020102E8();
    }

    unk_14BC->sub_0200E2D4();
    unk_14C0->sub_0200E2D4();
    unk_14C4->sub_0200E4A8();
    unk_14C8->sub_0200E4A8();
    // VCOUNT is read and dropped (likely a debug print stripped from the final build)
    GX_GetVCount();
    unk_146C.sub_02008E58();
}

BOOL CGame::sub_020100E4(CGame_020100E4_arg0 callback, void *arg)
{
    for (int i = 0; i < 0x20; i++) {
        if (m_vblankCallbacks[i] == NULL) {
            m_vblankCallbacks[i] = callback;
            m_vblankArgs[i] = arg;
            return TRUE;
        }
    }
    return FALSE;
}

void CGame::sub_02010124()
{
    sub_02034384(m_scriptManager);
    m_textboxData->sub_0200A118();
    unk_14B8->sub_0200D9CC();
    unk_14C4->sub_0200E44C();
    unk_14C8->sub_0200E44C();
    m_audioEngine->sub_0203459C();
}

CTouchPanel *CGame::sub_02010178(int mode)
{
    CTouchPanel *prev = activeTouchPanel;
    switch (mode) {
    case 1:
        activeTouchPanel = touchPanelEmulator;
        break;
    case 0:
    default:
        activeTouchPanel = touchPanel;
        break;
    }
    return prev;
}

void *CGame::operator new(size_t size)
{
    return Heap_AllocSecondary(size);
}

void CGame::sub_020101B4(char *label)
{
    NNSFndHeapHandle *heap = Heap_GetSecondaryHandle();
    NNS_FndGetTotalFreeSizeForExpHeap(*heap);
    NNS_FndGetAllocatableSizeForExpHeapEx(*heap, 4);
    heap = Heap_GetMainHandle();
    NNS_FndGetTotalFreeSizeForExpHeap(*heap);
    NNS_FndGetAllocatableSizeForExpHeapEx(*heap, 4);
}

void CGame::sub_020101F4(u32 texSize, u32 texSize4x4, u32 plttSize)
{
    NNS_GfdInitLnkTexVramManager(texSize, texSize4x4, m_texVramWork, NNS_GfdGetLnkTexVramManagerWorkSize(0x20), TRUE);
    NNS_GfdInitLnkPlttVramManager(plttSize, m_plttVramWork, NNS_GfdGetLnkPlttVramManagerWorkSize(0x20), TRUE);
}

void CGame::sub_0201024C()
{
    m_textboxData->unk_070 = sub_02019278(unk_14B4, 1);
    m_textboxData->unk_074 = sub_02019278(unk_14B4, 2);
}

void CGame::sub_0201028C()
{
    unk_15D0 += 0x1E000 / unk_146C.sub_02008E50();
    if (unk_15D0 > 0xD0000 || unk_15D0 < -0x10000) {
        unk_15D0 = -0x10000;
    }
}

void CGame::sub_020102E8()
{
    NNS_GfdInitVramTransferManager(m_vramTransferTasks, 0x80);
    for (int i = 0; i < 0x20; i++) {
        m_vblankCallbacks[i] = NULL;
    }
}

void CGame::sub_02010324()
{
    UnkClass_02034478 *audio = m_audioEngine;
    s32 c4 = audio->unk_C4;
    s32 d0 = audio->unk_D0;
    s32 f0 = audio->unk_F0;
    sub_0201926C(unk_14B4, 5, c4);
    sub_0201926C(unk_14B4, 6, d0);
    sub_0201926C(unk_14B4, 0x1A, f0);
}

BOOL CGame::sub_02010378()
{
    s32 v5 = sub_02019278(unk_14B4, 5);
    s32 v6 = sub_02019278(unk_14B4, 6);
    s32 v1A = sub_02019278(unk_14B4, 0x1A);
    if (v1A < 0) {
        return FALSE;
    }
    m_audioEngine->sub_0203499C(v5);
    m_audioEngine->sub_02034A40(v6, 0);
    m_audioEngine->sub_02034F4C(v1A);
    return TRUE;
}

void CGame::sub_02010400()
{
    sub_0201926C(unk_14B4, 5, 0);
    sub_0201926C(unk_14B4, 6, 0);
    sub_0201926C(unk_14B4, 0x1A, -1);
}

void CGame::sub_02010448()
{
}

void CGame::sub_0201044C()
{
    unk_1494->sub_0200C3D0();
    unk_1498->sub_0200CAE0();
}
