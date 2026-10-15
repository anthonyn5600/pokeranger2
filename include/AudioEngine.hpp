#ifndef POKERANGER2_AUDIOENGINE_HPP
#define POKERANGER2_AUDIOENGINE_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"

// CGame::m_audioEngine
class AudioEngine {
public:
    AudioEngine();

    void Main();
    void ClearBgmHeap();
    void ClearSeHeap();
    void LoadSystemSe();
    BOOL LoadMapBgmGroup(u32 mapId);
    void PlayMapBgm(u32 mapId, int fadeFrames, BOOL arg3);
    void LoadBattleSe();
    void LoadBattleBgmGroup(int index);
    void LoadBattleSeGroup(int group);
    void LoadSeGroup(int group);
    void LoadResultAudio();
    void RestoreFieldBgm();
    void LoadBgmGroup(int group);
    void AddSeGroup(int group);
    void sub_02034A08(int group);
    void PlayBgm(int seq, int fadeFrames);
    void PlayEncounterBgm();
    void PlayBattleBgm(int index, int fadeFrames);
    void StopBgm(int fadeFrames);
    void ResumeBgm(int fadeFrames);
    void StopBgmReset(int fadeFrames);
    void SetBgmTempo(int ratio);
    void sub_02034BCC(int group);
    void PlayLoopSe(int index);
    void StopLoopSe(int fadeFrames);
    BOOL PlaySe(int index);
    void StopSe(int index);
    void StopAllSe();
    BOOL IsSePlaying(int index);
    void PlayGroupSe(int group, int index);
    void PlayStream(int strmNo, int pan);
    void sub_02034D44(int strmNo, int pan);
    void PlayStream2(int strmNo, int pan);
    void StopStream2(int fadeFrames);
    void StopStream(int fadeFrames);
    void PlayJingle(int seq, int fadeFrames, int ratio);
    void StopJingle(int fadeFrames);
    void PlayCaptureLineSe(int arg0);
    void AddCaptureLinePitch(int delta);
    void StopCaptureLineSe(int arg0);
    void DumpHeapSizes();
    void SetBgmVolume(int volume);
    void SetLoopSeVolume(int volume);
    void SetSeVolume(int volume);
    void sub_02034F4C(int mode);

public:
    void *unk_00;
    void *unk_04;
    void *unk_08;
    // NNSSndArc; this game's NitroSystem has no loadBlockSize (0x90 bytes, the SDK header says 0x94)
    u8 unk_0C[0x90];
    NNSSndHeapHandle m_seHeap;
    NNSSndHeapHandle m_bgmHeap;
    NNSSndHeapHandle unk_A4;
    NNSSndStrmHandle m_strm;
    NNSSndStrmHandle m_strm2;
    NNSSndHandle m_bgm;
    NNSSndHandle m_se;
    NNSSndHandle m_loopSe;
    NNSSndHandle m_captureLineSe;
    NNSSndHandle m_jingle;
    s32 m_bgmGroup;
    s32 m_savedBgmGroup;
    s32 unk_CC;
    s32 m_bgmSeq;
    s32 m_savedBgmSeq;
    s32 unk_D8;
    s32 m_loopSeIdx;
    s32 m_savedLoopSeIdx;
    s32 m_groupSeGroup;
    u32 m_bgmMapId;
    s32 unk_EC;
    s32 unk_F0;
    s32 m_bgmTempo;
    s32 m_captureLinePitch;
    s32 m_strmChannel;
    s32 m_battleSeGroups[0x28];
    s32 m_loopSeVolume;
    int m_scriptVar;
    int m_seHeapState;
};

STATIC_SIZE_ASSERT(AudioEngine, 0x1AC);

#endif // POKERANGER2_AUDIOENGINE_HPP
