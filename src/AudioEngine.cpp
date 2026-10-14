#include "AudioEngine.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "SaveData.hpp"
#include "UnkClass_02041D80.hpp"
#include "heap.hpp"

extern SaveData MAIN_BSS_020B26A0;
extern FieldData *MAIN_BSS_0210CA6C;

AudioEngine::AudioEngine()
{
    NNS_SndInit();
    unk_00 = Heap_AllocSecondary(0x64000);
    unk_04 = Heap_AllocSecondary(0x30000);
    unk_08 = Heap_AllocSecondary(0xC000);
    unk_9C = NNS_SndHeapCreate(unk_00, 0x64000);
    unk_A0 = NNS_SndHeapCreate(unk_04, 0x30000);
    unk_A4 = NNS_SndHeapCreate(unk_08, 0xC000);
    NNS_SndArcInit((NNSSndArc *)unk_0C, "/data/Sound/sound_data.sdat", unk_A4, FALSE);
    NNS_SndArcPlayerSetup(unk_9C);
    NNS_SndArcPlayerSetup(unk_A0);
    NNS_SndArcPlayerSetup(unk_A4);
    NNS_SndArcStrmInit(10, unk_A4);
    unk_C4 = 99;
    unk_D0 = 99;
    unk_DC = 99;
    unk_1A0 = 0;
    unk_F0 = 0;
    unk_F8 = 0;
    unk_F4 = 0x100;
    unk_FC = 0;
    unk_E4 = 0;
    NNS_SndStrmHandleInit(&unk_A8);
    NNS_SndStrmHandleInit(&unk_AC);
    NNS_SndHandleInit(&unk_B0);
    NNS_SndHandleInit(&unk_B4);
    NNS_SndHandleInit(&unk_B8);
    NNS_SndHandleInit(&unk_BC);
    NNS_SndHandleInit(&unk_C0);
    ClearBgmHeap();
    ClearSeHeap();
    DumpHeapSizes();
}

void AudioEngine::Main()
{
    NNS_SndMain();
}

void AudioEngine::ClearBgmHeap()
{
    NNS_SndHeapClear(unk_A0);
}

void AudioEngine::ClearSeHeap()
{
    NNS_SndHeapClear(unk_9C);
    unk_E4 = 0;
}

void AudioEngine::sub_020345D4()
{
    ClearSeHeap();
    NNS_SndArcLoadGroup(0, unk_9C);
    unk_1A8 = NNS_SndHeapSaveState(unk_9C);
    DumpHeapSizes();
}

BOOL AudioEngine::sub_02034604(u32 mapId)
{
    int group = 0;
    if (MAIN_BSS_0210CA6C != NULL) {
        group = FieldData_GetMap(MAIN_BSS_0210CA6C, mapId)->unk_4A;
        u8 hi = (MAIN_BSS_020B26A0.m_rangerClassGrade >> 4) & 0xF;
        u8 lo = MAIN_BSS_020B26A0.m_rangerClassGrade & 0xF;
        if (hi == 2 && group == 4) {
            group = 7;
        }
        if (lo == 10 && group == 0x1A) {
            group = 0x19;
        }
    }
    if (unk_C4 == group) {
        sub_020345D4();
        return TRUE;
    }
    if (unk_F0 == 1) {
        sub_020345D4();
        return TRUE;
    }
    unk_C4 = group;
    unk_E8 = mapId;
    ClearBgmHeap();
    NNS_SndArcLoadGroup(unk_C4, unk_A0);
    sub_020345D4();
    DumpHeapSizes();
    return FALSE;
}

void AudioEngine::PlayMapBgm(u32 mapId, int fadeFrames, BOOL arg3)
{
    if (arg3 && unk_F0 == 1 && (unk_CC == 5 || unk_CC == 8)) {
        LoadBgmGroup(unk_CC);
        PlayBgm(unk_D8, fadeFrames);
        return;
    }
    if (sub_02034604(mapId) == TRUE) {
        return;
    }
    int seq = 0;
    if (MAIN_BSS_0210CA6C != NULL) {
        seq = FieldData_GetMap(MAIN_BSS_0210CA6C, mapId)->unk_4C;
        u8 hi = (MAIN_BSS_020B26A0.m_rangerClassGrade >> 4) & 0xF;
        u8 lo = MAIN_BSS_020B26A0.m_rangerClassGrade & 0xF;
        if (hi == 2 && seq == 0xD) {
            seq = 0x21;
        }
        if (lo == 10 && seq == 0x1D) {
            seq = 0x1C;
        }
    }
    StopBgm(0);
    NNS_SndArcPlayerStartSeq(&unk_B0, seq);
    if (fadeFrames != 0) {
        NNS_SndPlayerMoveVolume(&unk_B0, 127, fadeFrames);
    }
    unk_D0 = seq;
    unk_EC = 0;
}

void AudioEngine::sub_020347C4()
{
    unk_D4 = unk_D0;
    unk_E0 = unk_DC;
    unk_C8 = unk_C4;
    ClearSeHeap();
    NNS_SndArcLoadGroup(0x24, unk_9C);
    for (int i = 0; i < 0x28; i++) {
        unk_100[i] = 0xFF;
    }
    DumpHeapSizes();
}

void AudioEngine::sub_0203481C(int index)
{
    int groups[] = { 0x1F, 0x20, 0x21, 0x22, 0x23, 0x40, 0x31 };
    ClearBgmHeap();
    NNS_SndArcLoadGroup(groups[index], unk_A0);
    DumpHeapSizes();
}

void AudioEngine::sub_02034870(int group)
{
    for (int i = 0; i < 0x28; i++) {
        if (group == unk_100[i]) {
            return;
        }
        if (unk_100[i] == 0xFF) {
            unk_100[i] = group;
            if (!NNS_SndArcLoadGroup(group, unk_9C)) {
                DumpHeapSizes();
            }
            DumpHeapSizes();
            unk_1A8 = NNS_SndHeapSaveState(unk_9C);
            return;
        }
    }
}

void AudioEngine::LoadSeGroup(int group)
{
    NNS_SndHeapLoadState(unk_9C, unk_1A8);
    if (!NNS_SndArcLoadGroup(group, unk_9C)) {
        DumpHeapSizes();
    }
    DumpHeapSizes();
}

void AudioEngine::sub_0203491C()
{
    ClearBgmHeap();
    ClearSeHeap();
    NNS_SndArcLoadGroup(0x25, unk_A0);
    NNS_SndArcLoadGroup(0x26, unk_9C);
    DumpHeapSizes();
}

void AudioEngine::sub_02034954()
{
    ClearBgmHeap();
    NNS_SndArcLoadGroup(unk_C8, unk_A0);
    unk_C4 = unk_C8;
    sub_020345D4();
    DumpHeapSizes();
    NNS_SndArcPlayerStartSeq(&unk_B0, unk_D4);
    unk_D0 = unk_D4;
}

void AudioEngine::LoadBgmGroup(int group)
{
    unk_C4 = group;
    if (unk_F0 == 1 && (group == 5 || group == 8)) {
        unk_CC = unk_C4;
    }
    ClearBgmHeap();
    NNS_SndArcLoadGroup(group, unk_A0);
    DumpHeapSizes();
}

void AudioEngine::sub_020349E8(int group)
{
    NNS_SndArcLoadGroup(group, unk_9C);
    DumpHeapSizes();
}

void AudioEngine::sub_02034A08(int group)
{
    NNS_SndHeapLoadState(unk_9C, unk_1A8);
    unk_E4 = 0;
    NNS_SndArcLoadGroup(group, unk_9C);
    DumpHeapSizes();
}

void AudioEngine::PlayBgm(int seq, int fadeFrames)
{
    StopBgm(0);
    NNS_SndArcPlayerStartSeq(&unk_B0, seq);
    if (fadeFrames != 0) {
        NNS_SndPlayerMoveVolume(&unk_B0, 127, fadeFrames);
    }
    unk_D0 = seq;
    unk_EC = 0;
    if (unk_F0 == 1 && (seq == 0 || seq == 0x27)) {
        unk_D8 = unk_D0;
    }
}

void AudioEngine::sub_02034AA8()
{
    ClearBgmHeap();
    NNS_SndArcLoadGroup(0x44, unk_A0);
    DumpHeapSizes();
    StopBgm(0);
    NNS_SndArcPlayerStartSeq(&unk_B0, 1);
}

void AudioEngine::sub_02034AE4(int index, int fadeFrames)
{
    int seqs[] = { 2, 0x20, 0x23, 0x24, 0x25, 0x4C, 0x26 };
    StopBgm(0);
    NNS_SndArcPlayerStartSeq(&unk_B0, seqs[index]);
    if (fadeFrames != 0) {
        NNS_SndPlayerMoveVolume(&unk_B0, 127, fadeFrames);
    }
    unk_EC = 0;
}

void AudioEngine::StopBgm(int fadeFrames)
{
    NNS_SndPlayerStopSeq(&unk_B0, fadeFrames);
}

void AudioEngine::ResumeBgm(int fadeFrames)
{
    NNS_SndArcPlayerStartSeq(&unk_B0, unk_D0);
    if (fadeFrames != 0) {
        NNS_SndPlayerMoveVolume(&unk_B0, 127, fadeFrames);
    }
}

void AudioEngine::StopBgmReset(int fadeFrames)
{
    NNS_SndPlayerStopSeq(&unk_B0, fadeFrames);
    unk_C4 = 99;
}

void AudioEngine::SetBgmTempo(int ratio)
{
    unk_F4 = ratio;
    NNS_SndPlayerSetTempoRatio(&unk_B0, ratio);
}

void AudioEngine::sub_02034BCC(int group)
{
    sub_02034C2C(0);
    NNS_SndArcLoadGroup(group, unk_A0);
    DumpHeapSizes();
}

void AudioEngine::sub_02034BF8(int index)
{
    sub_02034C2C(0);
    if (index != 0) {
        NNS_SndArcPlayerStartSeqArc(&unk_B8, 0, index);
    }
    unk_DC = index;
}

void AudioEngine::sub_02034C2C(int fadeFrames)
{
    NNS_SndPlayerStopSeqBySeqArcIdx(0, unk_DC, fadeFrames);
}

BOOL AudioEngine::PlaySe(int index)
{
    return NNS_SndArcPlayerStartSeqArc(&unk_B4, 0, index);
}

void AudioEngine::StopSe(int index)
{
    NNS_SndPlayerStopSeqBySeqArcIdx(0, index, 0);
}

void AudioEngine::StopAllSe()
{
    NNS_SndPlayerStopSeq(&unk_B4, 0);
}

BOOL AudioEngine::IsSePlaying(int index)
{
    return NNS_SndPlayerCountPlayingSeqBySeqArcIdx(0, index) > 0;
}

void AudioEngine::sub_02034CA0(int group, int index)
{
    if (unk_E4 != group) {
        unk_E4 = group;
        NNS_SndHeapLoadState(unk_9C, unk_1A8);
        NNS_SndArcLoadGroup(group, unk_9C);
        DumpHeapSizes();
    }
    NNS_SndArcPlayerStartSeqArc(&unk_B4, 0, index);
}

void AudioEngine::PlayStream(int strmNo, int pan)
{
    NNS_SndArcStrmStartEx(&unk_A8, unk_FC, -1, strmNo, 0);
    NNS_SndArcStrmSetChannelPan(&unk_A8, 0, pan);
    unk_FC = unk_FC == 0;
}

void AudioEngine::sub_02034D44(int strmNo, int pan)
{
    PlayStream(0, pan);
}

void AudioEngine::sub_02034D54(int strmNo, int pan)
{
    if (NNS_SndArcStrmGetCurrentPlayingPos(&unk_A8) != 0) {
        return;
    }
    NNS_SndArcStrmStartEx(&unk_AC, unk_FC, -1, strmNo, 0);
    NNS_SndArcStrmSetChannelPan(&unk_AC, 0, pan);
    if (unk_FC == 0) {
        unk_FC = 1;
    } else {
        unk_FC = 0;
    }
}

void AudioEngine::sub_02034DC8(int fadeFrames)
{
    NNS_SndArcStrmStop(&unk_AC, fadeFrames);
}

void AudioEngine::sub_02034DD8(int fadeFrames)
{
    NNS_SndArcStrmStop(&unk_A8, fadeFrames);
}

void AudioEngine::sub_02034DE8(int seq, int fadeFrames, int ratio)
{
    sub_02034E38(0);
    NNS_SndArcPlayerStartSeq(&unk_C0, seq);
    NNS_SndPlayerSetTempoRatio(&unk_C0, ratio);
    if (fadeFrames != 0) {
        NNS_SndPlayerMoveVolume(&unk_C0, 127, fadeFrames);
    }
}

void AudioEngine::sub_02034E38(int fadeFrames)
{
    NNS_SndPlayerStopSeq(&unk_C0, fadeFrames);
}

void AudioEngine::sub_02034E48(int arg0)
{
    NNS_SndArcPlayerStartSeqArc(&unk_BC, 0, 0x19);
    NNS_SndArcPlayerStartSeqArc(&unk_BC, 0, 0xB);
    sub_02034E80(0);
}

void AudioEngine::sub_02034E80(int delta)
{
    if (delta != 0) {
        unk_F8 += delta;
        if (unk_F8 > 0x3FF) {
            unk_F8 = 0x3FF;
        } else if (unk_F8 < 0) {
            unk_F8 = 0;
        }
    } else {
        unk_F8 = delta;
    }
    NNS_SndPlayerSetTrackPitch(&unk_BC, 0xFFFF, unk_F8);
}

void AudioEngine::sub_02034ED8(int arg0)
{
    NNS_SndPlayerStopSeq(&unk_BC, 0);
}

void AudioEngine::DumpHeapSizes()
{
    NNS_SndHeapGetSize(unk_A0);
    NNS_SndHeapGetSize(unk_9C);
    NNS_SndHeapGetSize(unk_A4);
}

void AudioEngine::SetBgmVolume(int volume)
{
    NNS_SndPlayerSetVolume(&unk_B0, volume);
}

void AudioEngine::sub_02034F20(int volume)
{
    if (volume != 0x100) {
        unk_1A0 = volume;
    }
    NNS_SndPlayerSetVolume(&unk_B8, unk_1A0);
}

void AudioEngine::SetSeVolume(int volume)
{
    NNS_SndPlayerSetVolume(&unk_B4, volume);
}

void AudioEngine::sub_02034F4C(int mode)
{
    unk_F0 = mode;
    if (mode == 1) {
        if (unk_C4 == 5 || unk_C4 == 8) {
            unk_CC = unk_C4;
        } else {
            unk_CC = 0;
        }
        if (unk_D0 == 0 || unk_D0 == 0x27) {
            unk_D8 = unk_D0;
        } else {
            unk_D8 = 0;
        }
    } else {
        unk_CC = 0;
        unk_D8 = 0;
    }
}
