#ifndef POKERANGER2_UNKCLASS_02034478_HPP
#define POKERANGER2_UNKCLASS_02034478_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"

// CGame::m_audioEngine
class UnkClass_02034478 {
public:
    UnkClass_02034478();

    void sub_0203459C();
    void sub_020345A8();
    void sub_020345B8();
    void sub_020345D4();
    BOOL sub_02034604(u32 mapId);
    void sub_020346CC(u32 mapId, int fadeFrames, BOOL arg3);
    void sub_020347C4();
    void sub_0203481C(int index);
    void sub_02034870(int group);
    void sub_020348DC(int group);
    void sub_0203491C();
    void sub_02034954();
    void sub_0203499C(int group);
    void sub_020349E8(int group);
    void sub_02034A08(int group);
    void sub_02034A40(int seq, int fadeFrames);
    void sub_02034AA8();
    void sub_02034AE4(int index, int fadeFrames);
    void sub_02034B58(int fadeFrames);
    void sub_02034B68(int fadeFrames);
    void sub_02034B9C(int fadeFrames);
    void sub_02034BB8(int ratio);
    void sub_02034BCC(int group);
    void sub_02034BF8(int index);
    void sub_02034C2C(int fadeFrames);
    BOOL sub_02034C44(int index);
    void sub_02034C5C(int index);
    void sub_02034C70();
    BOOL sub_02034C84(int index);
    void sub_02034CA0(int group, int index);
    void sub_02034CF4(int strmNo, int pan);
    void sub_02034D44(int strmNo, int pan);
    void sub_02034D54(int strmNo, int pan);
    void sub_02034DC8(int fadeFrames);
    void sub_02034DD8(int fadeFrames);
    void sub_02034DE8(int seq, int fadeFrames, int ratio);
    void sub_02034E38(int fadeFrames);
    void sub_02034E48(int arg0);
    void sub_02034E80(int delta);
    void sub_02034ED8(int arg0);
    void sub_02034EEC();
    void sub_02034F10(int volume);
    void sub_02034F20(int volume);
    void sub_02034F3C(int volume);
    void sub_02034F4C(int mode);

public:
    void *unk_00;
    void *unk_04;
    void *unk_08;
    // NNSSndArc; this game's NitroSystem has no loadBlockSize (0x90 bytes, the SDK header says 0x94)
    u8 unk_0C[0x90];
    NNSSndHeapHandle unk_9C;
    NNSSndHeapHandle unk_A0;
    NNSSndHeapHandle unk_A4;
    NNSSndStrmHandle unk_A8;
    NNSSndStrmHandle unk_AC;
    NNSSndHandle unk_B0;
    NNSSndHandle unk_B4;
    NNSSndHandle unk_B8;
    NNSSndHandle unk_BC;
    NNSSndHandle unk_C0;
    s32 unk_C4;
    s32 unk_C8;
    s32 unk_CC;
    s32 unk_D0;
    s32 unk_D4;
    s32 unk_D8;
    s32 unk_DC;
    s32 unk_E0;
    s32 unk_E4;
    u32 unk_E8;
    s32 unk_EC;
    s32 unk_F0;
    s32 unk_F4;
    s32 unk_F8;
    s32 unk_FC;
    s32 unk_100[0x28];
    s32 unk_1A0;
    u8 unk_1A4[0x4];
    int unk_1A8;
};

STATIC_SIZE_ASSERT(UnkClass_02034478, 0x1AC);

#endif // POKERANGER2_UNKCLASS_02034478_HPP
