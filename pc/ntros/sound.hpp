// The ARM7's sound driver (sound_*.cpp): the SDK's ARM7 sound library, on the sound hardware (spu.cpp). Written from
// the SDK (its headers; the ARM7 parts of snd_command.c, snd_alarm.c, snd_work.c, snd_bank.c, snd_util.c and
// snd_main.c) and, for the parts the SDK ships only compiled (channels, channel allocation and envelopes, the
// sequence player), from what the game's ARM7 program does. It keeps its state in the SDK's own structures
// (SNDWork: channels, players, tracks, alarms), so the game's SND_ReadDriverInfo copies read as on the DS.
#ifndef NTROS_SOUND_HPP
#define NTROS_SOUND_HPP

#include "internal.hpp"

namespace ntros::snd {

extern SNDWork gWork;
extern SNDSharedWork *gShared; // the game's shared work (SND_COMMAND_SHARED_WORK); NULL until it says

// sound_channel.cpp: the hardware channels, mixer controls and capture units (snd_channel.c, snd_global.c,
// snd_capture.c)
void SetupChannelPcm(int ch, const void *data, int format, int loop, int loopStart, int loopLen, int volume, int shift, int timer, int pan);
void SetupChannelPsg(int ch, int duty, int volume, int shift, int timer, int pan);
void SetupChannelNoise(int ch, int volume, int shift, int timer, int pan);
void StartChannel(int ch);
void StopChannel(int ch, s32 flags);
void SetChannelTimer(int ch, int timer);
void SetChannelVolume(int ch, int volume, int shift);
void SetChannelPan(int ch, int pan);
bool IsChannelActive(int ch);
u32 GetChannelControl(int ch);
void SetMasterVolume(int volume);
void SetMasterPan(int pan);
void SetSurroundDecay(int decay);
void SetOutputSelector(int left, int right, int channel1, int channel3);
void Enable();
void SetupCapture(int capture, int format, void *buffer, int length, bool repeat, int in, int out);
void StartCapture(int capture);
void StartCaptureBoth();
void StopCapture(int capture);
bool IsCaptureActive(int capture);

// sound_exchannel.cpp: channels as the driver hands them out, with envelopes, LFO and sweep (snd_exchannel.c)
void ExChannelInit();
void UpdateExChannel();
void ExChannelMain(bool doPeriodicProc);
SNDExChannel *AllocExChannel(u32 chBitMask, int prio, bool strongRequest, SNDExChannelCallback callback, void *callbackData);
void FreeExChannel(SNDExChannel *ch);
bool StartExChannelPcm(SNDExChannel *ch, const SNDWaveParam *wave, const void *data, s32 length);
bool StartExChannelPsg(SNDExChannel *ch, int duty, s32 length);
bool StartExChannelNoise(SNDExChannel *ch, s32 length);
void ReleaseExChannel(SNDExChannel *ch);
bool IsExChannelActive(SNDExChannel *ch);
void SetExChannelAttack(SNDExChannel *ch, int attack);
void SetExChannelDecay(SNDExChannel *ch, int decay);
void SetExChannelSustain(SNDExChannel *ch, int sustain);
void SetExChannelRelease(SNDExChannel *ch, int release);
void InitLfoParam(SNDLfoParam *lfo);
void LockChannel(u32 chBitMask, u32 flags);
void UnlockChannel(u32 chBitMask, u32 flags);
void StopUnlockedChannel(u32 chBitMask, u32 flags);
u32 GetLockedChannel(u32 flags);
void InvalidateWave(const void *start, const void *end);

// sound_seq.cpp: the sequence player (snd_seq.c) and instruments (snd_bank.c)
void SeqInit();
void SeqMain(bool doPeriodicProc);
void StartSeq(int playerNo, const void *seqBase, u32 seqOffset, SNDBankData *bank);
void PrepareSeq(int playerNo, const void *seqBase, u32 seqOffset, SNDBankData *bank);
void StartPreparedSeq(int playerNo);
void StopSeq(int playerNo);
void PauseSeq(int playerNo, bool flag);
void SkipSeq(int playerNo, u32 tick);
void SetPlayerParam(int playerNo, u32 offset, u32 data, int size);
void SetTrackParam(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size);
void SetTrackMute(int playerNo, u32 trackBitMask, int mute);
void SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask);
void SetPlayerLocalVariable(int playerNo, int varNo, s16 var);
void SetPlayerGlobalVariable(int varNo, s16 var);
void InvalidateSeq(const void *start, const void *end);
void InvalidateBank(const void *start, const void *end);

// sound_driver.cpp: the sound thread's timer (snd_main.c)
void RestartIntervalTimer(); // SND_SkipSeq stops and restarts the periodic sound frames
u16 CalcRandom();

// The ARM7's part of snd_util.c. (The conversions both CPUs have, SND_CalcTimer, SND_CalcChannelVolume and
// SNDi_DecibelSquareTable, come from the game's SDK library; the ARM7 reads the same pitch and volume tables
// from its BIOS.)
s8 SinIdx(int index);

} // namespace ntros::snd

#endif // NTROS_SOUND_HPP
