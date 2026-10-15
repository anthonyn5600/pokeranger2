#include "AudioEngine.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "FieldDataRecords.hpp"
#include "SaveData.hpp"
#include "heap.hpp"

extern SaveData MAIN_BSS_020B26A0;
extern FieldData *MAIN_BSS_0210CA6C;

AudioEngine::AudioEngine()
{
    NNS_SndInit();
    unk_00 = Heap_AllocSecondary(0x64000);
    unk_04 = Heap_AllocSecondary(0x30000);
#ifdef PC_PORT
    // libntrsystem keeps the sound archive's FAT at twice its file size (64-bit entries)
    unk_08 = Heap_AllocSecondary(0xC000 + 0x10000);
    m_seHeap = NNS_SndHeapCreate(unk_00, 0x64000);
    m_bgmHeap = NNS_SndHeapCreate(unk_04, 0x30000);
    unk_A4 = NNS_SndHeapCreate(unk_08, 0xC000 + 0x10000);
#else
    unk_08 = Heap_AllocSecondary(0xC000);
    m_seHeap = NNS_SndHeapCreate(unk_00, 0x64000);
    m_bgmHeap = NNS_SndHeapCreate(unk_04, 0x30000);
    unk_A4 = NNS_SndHeapCreate(unk_08, 0xC000);
#endif
    NNS_SndArcInit((NNSSndArc *)unk_0C, "/data/Sound/sound_data.sdat", unk_A4, FALSE);
    NNS_SndArcPlayerSetup(m_seHeap);
    NNS_SndArcPlayerSetup(m_bgmHeap);
    NNS_SndArcPlayerSetup(unk_A4);
    NNS_SndArcStrmInit(10, unk_A4);
    m_bgmGroup = 99;
    m_bgmSeq = 99;
    m_loopSeIdx = 99;
    m_loopSeVolume = 0;
    unk_F0 = 0;
    m_captureLinePitch = 0;
    m_bgmTempo = 0x100;
    m_strmChannel = 0;
    m_groupSeGroup = 0;
    NNS_SndStrmHandleInit(&m_strm);
    NNS_SndStrmHandleInit(&m_strm2);
    NNS_SndHandleInit(&m_bgm);
    NNS_SndHandleInit(&m_se);
    NNS_SndHandleInit(&m_loopSe);
    NNS_SndHandleInit(&m_captureLineSe);
    NNS_SndHandleInit(&m_jingle);
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
    NNS_SndHeapClear(m_bgmHeap);
}

void AudioEngine::ClearSeHeap()
{
    NNS_SndHeapClear(m_seHeap);
    m_groupSeGroup = 0;
}

void AudioEngine::LoadSystemSe()
{
    ClearSeHeap();
    NNS_SndArcLoadGroup(0, m_seHeap);
    m_seHeapState = NNS_SndHeapSaveState(m_seHeap);
    DumpHeapSizes();
}

BOOL AudioEngine::LoadMapBgmGroup(u32 mapId)
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
    if (m_bgmGroup == group) {
        LoadSystemSe();
        return TRUE;
    }
    if (unk_F0 == 1) {
        LoadSystemSe();
        return TRUE;
    }
    m_bgmGroup = group;
    m_bgmMapId = mapId;
    ClearBgmHeap();
    NNS_SndArcLoadGroup(m_bgmGroup, m_bgmHeap);
    LoadSystemSe();
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
    if (LoadMapBgmGroup(mapId) == TRUE) {
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
    NNS_SndArcPlayerStartSeq(&m_bgm, seq);
    if (fadeFrames != 0) {
        NNS_SndPlayerMoveVolume(&m_bgm, 127, fadeFrames);
    }
    m_bgmSeq = seq;
    unk_EC = 0;
}

void AudioEngine::LoadBattleSe()
{
    m_savedBgmSeq = m_bgmSeq;
    m_savedLoopSeIdx = m_loopSeIdx;
    m_savedBgmGroup = m_bgmGroup;
    ClearSeHeap();
    NNS_SndArcLoadGroup(0x24, m_seHeap);
    for (int i = 0; i < 0x28; i++) {
        m_battleSeGroups[i] = 0xFF;
    }
    DumpHeapSizes();
}

void AudioEngine::LoadBattleBgmGroup(int index)
{
    int groups[] = { 0x1F, 0x20, 0x21, 0x22, 0x23, 0x40, 0x31 };
    ClearBgmHeap();
    NNS_SndArcLoadGroup(groups[index], m_bgmHeap);
    DumpHeapSizes();
}

void AudioEngine::LoadBattleSeGroup(int group)
{
    for (int i = 0; i < 0x28; i++) {
        if (group == m_battleSeGroups[i]) {
            return;
        }
        if (m_battleSeGroups[i] == 0xFF) {
            m_battleSeGroups[i] = group;
            if (!NNS_SndArcLoadGroup(group, m_seHeap)) {
                DumpHeapSizes();
            }
            DumpHeapSizes();
            m_seHeapState = NNS_SndHeapSaveState(m_seHeap);
            return;
        }
    }
}

void AudioEngine::LoadSeGroup(int group)
{
    NNS_SndHeapLoadState(m_seHeap, m_seHeapState);
    if (!NNS_SndArcLoadGroup(group, m_seHeap)) {
        DumpHeapSizes();
    }
    DumpHeapSizes();
}

void AudioEngine::LoadResultAudio()
{
    ClearBgmHeap();
    ClearSeHeap();
    NNS_SndArcLoadGroup(0x25, m_bgmHeap);
    NNS_SndArcLoadGroup(0x26, m_seHeap);
    DumpHeapSizes();
}

void AudioEngine::RestoreFieldBgm()
{
    ClearBgmHeap();
    NNS_SndArcLoadGroup(m_savedBgmGroup, m_bgmHeap);
    m_bgmGroup = m_savedBgmGroup;
    LoadSystemSe();
    DumpHeapSizes();
    NNS_SndArcPlayerStartSeq(&m_bgm, m_savedBgmSeq);
    m_bgmSeq = m_savedBgmSeq;
}

void AudioEngine::LoadBgmGroup(int group)
{
    m_bgmGroup = group;
    if (unk_F0 == 1 && (group == 5 || group == 8)) {
        unk_CC = m_bgmGroup;
    }
    ClearBgmHeap();
    NNS_SndArcLoadGroup(group, m_bgmHeap);
    DumpHeapSizes();
}

void AudioEngine::AddSeGroup(int group)
{
    NNS_SndArcLoadGroup(group, m_seHeap);
    DumpHeapSizes();
}

void AudioEngine::sub_02034A08(int group)
{
    NNS_SndHeapLoadState(m_seHeap, m_seHeapState);
    m_groupSeGroup = 0;
    NNS_SndArcLoadGroup(group, m_seHeap);
    DumpHeapSizes();
}

void AudioEngine::PlayBgm(int seq, int fadeFrames)
{
    StopBgm(0);
    NNS_SndArcPlayerStartSeq(&m_bgm, seq);
    if (fadeFrames != 0) {
        NNS_SndPlayerMoveVolume(&m_bgm, 127, fadeFrames);
    }
    m_bgmSeq = seq;
    unk_EC = 0;
    if (unk_F0 == 1 && (seq == 0 || seq == 0x27)) {
        unk_D8 = m_bgmSeq;
    }
}

void AudioEngine::PlayEncounterBgm()
{
    ClearBgmHeap();
    NNS_SndArcLoadGroup(0x44, m_bgmHeap);
    DumpHeapSizes();
    StopBgm(0);
    NNS_SndArcPlayerStartSeq(&m_bgm, 1);
}

void AudioEngine::PlayBattleBgm(int index, int fadeFrames)
{
    int seqs[] = { 2, 0x20, 0x23, 0x24, 0x25, 0x4C, 0x26 };
    StopBgm(0);
    NNS_SndArcPlayerStartSeq(&m_bgm, seqs[index]);
    if (fadeFrames != 0) {
        NNS_SndPlayerMoveVolume(&m_bgm, 127, fadeFrames);
    }
    unk_EC = 0;
}

void AudioEngine::StopBgm(int fadeFrames)
{
    NNS_SndPlayerStopSeq(&m_bgm, fadeFrames);
}

void AudioEngine::ResumeBgm(int fadeFrames)
{
    NNS_SndArcPlayerStartSeq(&m_bgm, m_bgmSeq);
    if (fadeFrames != 0) {
        NNS_SndPlayerMoveVolume(&m_bgm, 127, fadeFrames);
    }
}

void AudioEngine::StopBgmReset(int fadeFrames)
{
    NNS_SndPlayerStopSeq(&m_bgm, fadeFrames);
    m_bgmGroup = 99;
}

void AudioEngine::SetBgmTempo(int ratio)
{
    m_bgmTempo = ratio;
    NNS_SndPlayerSetTempoRatio(&m_bgm, ratio);
}

void AudioEngine::sub_02034BCC(int group)
{
    StopLoopSe(0);
    NNS_SndArcLoadGroup(group, m_bgmHeap);
    DumpHeapSizes();
}

void AudioEngine::PlayLoopSe(int index)
{
    StopLoopSe(0);
    if (index != 0) {
        NNS_SndArcPlayerStartSeqArc(&m_loopSe, 0, index);
    }
    m_loopSeIdx = index;
}

void AudioEngine::StopLoopSe(int fadeFrames)
{
    NNS_SndPlayerStopSeqBySeqArcIdx(0, m_loopSeIdx, fadeFrames);
}

BOOL AudioEngine::PlaySe(int index)
{
    return NNS_SndArcPlayerStartSeqArc(&m_se, 0, index);
}

void AudioEngine::StopSe(int index)
{
    NNS_SndPlayerStopSeqBySeqArcIdx(0, index, 0);
}

void AudioEngine::StopAllSe()
{
    NNS_SndPlayerStopSeq(&m_se, 0);
}

BOOL AudioEngine::IsSePlaying(int index)
{
    return NNS_SndPlayerCountPlayingSeqBySeqArcIdx(0, index) > 0;
}

void AudioEngine::PlayGroupSe(int group, int index)
{
    if (m_groupSeGroup != group) {
        m_groupSeGroup = group;
        NNS_SndHeapLoadState(m_seHeap, m_seHeapState);
        NNS_SndArcLoadGroup(group, m_seHeap);
        DumpHeapSizes();
    }
    NNS_SndArcPlayerStartSeqArc(&m_se, 0, index);
}

void AudioEngine::PlayStream(int strmNo, int pan)
{
    NNS_SndArcStrmStartEx(&m_strm, m_strmChannel, -1, strmNo, 0);
    NNS_SndArcStrmSetChannelPan(&m_strm, 0, pan);
    m_strmChannel = m_strmChannel == 0;
}

void AudioEngine::sub_02034D44(int strmNo, int pan)
{
    PlayStream(0, pan);
}

void AudioEngine::PlayStream2(int strmNo, int pan)
{
    if (NNS_SndArcStrmGetCurrentPlayingPos(&m_strm) != 0) {
        return;
    }
    NNS_SndArcStrmStartEx(&m_strm2, m_strmChannel, -1, strmNo, 0);
    NNS_SndArcStrmSetChannelPan(&m_strm2, 0, pan);
    if (m_strmChannel == 0) {
        m_strmChannel = 1;
    } else {
        m_strmChannel = 0;
    }
}

void AudioEngine::StopStream2(int fadeFrames)
{
    NNS_SndArcStrmStop(&m_strm2, fadeFrames);
}

void AudioEngine::StopStream(int fadeFrames)
{
    NNS_SndArcStrmStop(&m_strm, fadeFrames);
}

void AudioEngine::PlayJingle(int seq, int fadeFrames, int ratio)
{
    StopJingle(0);
    NNS_SndArcPlayerStartSeq(&m_jingle, seq);
    NNS_SndPlayerSetTempoRatio(&m_jingle, ratio);
    if (fadeFrames != 0) {
        NNS_SndPlayerMoveVolume(&m_jingle, 127, fadeFrames);
    }
}

void AudioEngine::StopJingle(int fadeFrames)
{
    NNS_SndPlayerStopSeq(&m_jingle, fadeFrames);
}

void AudioEngine::PlayCaptureLineSe(int arg0)
{
    NNS_SndArcPlayerStartSeqArc(&m_captureLineSe, 0, 0x19);
    NNS_SndArcPlayerStartSeqArc(&m_captureLineSe, 0, 0xB);
    AddCaptureLinePitch(0);
}

void AudioEngine::AddCaptureLinePitch(int delta)
{
    if (delta != 0) {
        m_captureLinePitch += delta;
        if (m_captureLinePitch > 0x3FF) {
            m_captureLinePitch = 0x3FF;
        } else if (m_captureLinePitch < 0) {
            m_captureLinePitch = 0;
        }
    } else {
        m_captureLinePitch = delta;
    }
    NNS_SndPlayerSetTrackPitch(&m_captureLineSe, 0xFFFF, m_captureLinePitch);
}

void AudioEngine::StopCaptureLineSe(int arg0)
{
    NNS_SndPlayerStopSeq(&m_captureLineSe, 0);
}

void AudioEngine::DumpHeapSizes()
{
    NNS_SndHeapGetSize(m_bgmHeap);
    NNS_SndHeapGetSize(m_seHeap);
    NNS_SndHeapGetSize(unk_A4);
}

void AudioEngine::SetBgmVolume(int volume)
{
    NNS_SndPlayerSetVolume(&m_bgm, volume);
}

void AudioEngine::SetLoopSeVolume(int volume)
{
    if (volume != 0x100) {
        m_loopSeVolume = volume;
    }
    NNS_SndPlayerSetVolume(&m_loopSe, m_loopSeVolume);
}

void AudioEngine::SetSeVolume(int volume)
{
    NNS_SndPlayerSetVolume(&m_se, volume);
}

void AudioEngine::sub_02034F4C(int mode)
{
    unk_F0 = mode;
    if (mode == 1) {
        if (m_bgmGroup == 5 || m_bgmGroup == 8) {
            unk_CC = m_bgmGroup;
        } else {
            unk_CC = 0;
        }
        if (m_bgmSeq == 0 || m_bgmSeq == 0x27) {
            unk_D8 = m_bgmSeq;
        } else {
            unk_D8 = 0;
        }
    } else {
        unk_CC = 0;
        unk_D8 = 0;
    }
}
