// The sequence player: 16 players with up to 16 tracks each (32 tracks in all), interpreting the sequences' MML
// commands (SND_MML_*: notes, waits, jumps and calls, loops, variables, track settings). Every sound frame a player
// adds tempo x tempo ratio to its counter and steps its tracks once per 240 (one tick each). Notes take a channel
// (AllocExChannel) with the instrument the bank gives for the track's program and key.
#include <stdlib.h>
#include <string.h>

#include "sound.hpp"

namespace ntros::snd {
namespace {

    enum ArgType {
        kArgU8,
        kArgS16,
        kArgVlv,
        kArgRandom,
        kArgVariable
    };

    constexpr int kNoRelease = -1;
    constexpr u8 kNoTrack = SND_INVALID_TRACK_INDEX;
    constexpr u8 kTrackDefault = 0xFF; // track envelope settings: use the instrument's

    // The bank as the port loads it: its fields up to instCount may be wider than in the file (pointers), which
    // moves the instrument data behind them by this much from where the file's offsets point
    constexpr size_t kBankShift = offsetof(SNDBankData, instCount) - 0x38;

    SNDPlayer *Player(int playerNo)
    {
        return &gWork.player[playerNo];
    }

    SNDTrack *Track(SNDPlayer *player, int trackNo)
    {
        if (trackNo >= SND_TRACK_NUM_PER_PLAYER || player->tracks[trackNo] == kNoTrack) {
            return NULL;
        }
        return &gWork.track[player->tracks[trackNo]];
    }

    u8 ReadByte(SNDTrack *track)
    {
        return *track->cur++;
    }

    u32 Read24(SNDTrack *track)
    {
        u32 v = ReadByte(track);
        v |= (u32)ReadByte(track) << 8;
        return v | (u32)ReadByte(track) << 16;
    }

    vs16 *Variable(SNDPlayer *player, int varNo)
    {
        if (gShared == NULL || varNo >= SND_PLAYER_VARIABLE_NUM + SND_GLOBAL_VARIABLE_NUM) {
            return NULL;
        }
        if (varNo < SND_PLAYER_VARIABLE_NUM) {
            return &gShared->player[player->myNo].variable[varNo];
        }
        return &gShared->globalVariable[varNo - SND_PLAYER_VARIABLE_NUM];
    }

    s32 ReadArg(SNDTrack *track, SNDPlayer *player, ArgType type)
    {
        switch (type) {
        case kArgU8:
            return ReadByte(track);
        case kArgS16: {
            u32 lo = ReadByte(track);
            return (u16)(lo | ReadByte(track) << 8);
        }
        case kArgVlv: {
            s32 v = 0;
            u8 b;
            do {
                b = ReadByte(track);
                v = (v << 7) | (b & 0x7F);
            } while (b & 0x80);
            return v;
        }
        case kArgRandom: {
            u32 lo = ReadByte(track);
            s16 min = (s16)(lo | ReadByte(track) << 8);
            lo = ReadByte(track);
            s16 max = (s16)(lo | ReadByte(track) << 8);
            return ((s32)CalcRandom() * (max - min + 1) >> 16) + min;
        }
        case kArgVariable: {
            vs16 *var = Variable(player, ReadByte(track));
            return var != NULL ? *var : 0;
        }
        }
        return 0;
    }

    void InitTrack(SNDTrack *track)
    {
        track->base = NULL;
        track->cur = NULL;
        track->note_wait = 1;
        track->mute_flag = 0;
        track->tie_flag = 0;
        track->note_finish_wait = 0;
        track->porta_flag = 0;
        track->cmp_flag = 1;
        track->channel_mask_flag = 0;
        track->call_stack_depth = 0;
        track->prgNo = 0;
        track->prio = 64;
        track->volume = 127;
        track->volume2 = 127;
        track->extFader = 0;
        track->pan = 0;
        track->ext_pan = 0;
        track->pitch_bend = 0;
        track->ext_pitch = 0;
        track->attack = kTrackDefault;
        track->decay = kTrackDefault;
        track->sustain = kTrackDefault;
        track->release = kTrackDefault;
        track->pan_range = 127;
        track->bend_range = 2;
        track->porta_key = 60;
        track->porta_time = 0;
        track->sweep_pitch = 0;
        track->transpose = 0;
        track->channel_mask = 0xFFFF;
        InitLfoParam(&track->mod);
        track->wait = 0;
        track->channel_list = NULL;
    }

    int AllocTrack()
    {
        for (int i = 0; i < SND_TRACK_NUM; i++) {
            if (!gWork.track[i].active_flag) {
                gWork.track[i].active_flag = 1;
                return i;
            }
        }
        return -1;
    }

    // Track and player settings -> the track's channels; release: let channels whose note length ran out go
    void UpdateTrackChannels(SNDTrack *track, SNDPlayer *player, bool release)
    {
        s32 pan = track->pan;
        if (track->pan_range != 127) {
            pan = (pan * track->pan_range + 64) >> 7;
        }
        s32 volume = SNDi_DecibelSquareTable[player->volume] + SNDi_DecibelSquareTable[track->volume]
            + SNDi_DecibelSquareTable[track->volume2];
        if (volume < -0x8000) {
            volume = -0x8000;
        }
        s32 fader = track->extFader + player->extFader;
        if (fader < -0x8000) {
            fader = -0x8000;
        }
        pan += track->ext_pan;
        pan = pan < -128 ? -128 : pan > 127 ? 127
                                            : pan;
        s16 pitch = (s16)(track->ext_pitch + ((s32)(track->pitch_bend * track->bend_range * 64) >> 7));
        for (SNDExChannel *ch = track->channel_list; ch != NULL; ch = ch->nextLink) {
            ch->user_decay2 = (s16)fader;
            if (ch->env_status == SND_ENV_RELEASE) {
                continue;
            }
            ch->user_decay = (s16)volume;
            ch->user_pitch = pitch;
            ch->user_pan = (s8)pan;
            ch->pan_range = track->pan_range;
            ch->lfo.param = track->mod;
            if (ch->length == 0 && release) {
                ch->prio = 1;
                ReleaseExChannel(ch);
            }
        }
    }

    void ReleaseTrackChannels(SNDTrack *track, SNDPlayer *player, int release)
    {
        UpdateTrackChannels(track, player, false);
        for (SNDExChannel *ch = track->channel_list; ch != NULL; ch = ch->nextLink) {
            if (IsExChannelActive(ch)) {
                if (release >= 0) {
                    SetExChannelRelease(ch, release & 0xFF);
                }
                ch->prio = 1;
                ReleaseExChannel(ch);
            }
        }
    }

    void FreeTrackChannels(SNDTrack *track)
    {
        for (SNDExChannel *ch = track->channel_list; ch != NULL; ch = ch->nextLink) {
            FreeExChannel(ch);
        }
        track->channel_list = NULL;
    }

    void SetTrackMute(SNDTrack *track, SNDPlayer *player, int mute)
    {
        switch (mute) {
        case SND_SEQ_MUTE_OFF:
            track->mute_flag = 0;
            break;
        case SND_SEQ_MUTE_NO_STOP:
            track->mute_flag = 1;
            break;
        case SND_SEQ_MUTE_RELEASE:
            track->mute_flag = 1;
            ReleaseTrackChannels(track, player, kNoRelease);
            break;
        case SND_SEQ_MUTE_STOP:
            track->mute_flag = 1;
            ReleaseTrackChannels(track, player, 127);
            FreeTrackChannels(track);
            break;
        }
    }

    void CloseTrack(SNDPlayer *player, int trackNo)
    {
        SNDTrack *track = Track(player, trackNo);
        if (track == NULL) {
            return;
        }
        ReleaseTrackChannels(track, player, kNoRelease);
        FreeTrackChannels(track);
        gWork.track[player->tracks[trackNo]].active_flag = 0;
        player->tracks[trackNo] = kNoTrack;
    }

    void FinishPlayer(SNDPlayer *player)
    {
        for (int i = 0; i < SND_TRACK_NUM_PER_PLAYER; i++) {
            CloseTrack(player, i);
        }
        player->active_flag = 0;
    }

    // A channel a track holds finished or was taken away
    void ChannelCallback(SNDExChannel *ch, SNDExChannelCallbackStatus status, void *userData)
    {
        SNDTrack *track = (SNDTrack *)userData;
        if (status == SND_EX_CHANNEL_CALLBACK_FINISH) {
            ch->prio = 0;
            FreeExChannel(ch);
        }
        if (track->channel_list == ch) {
            track->channel_list = ch->nextLink;
            return;
        }
        for (SNDExChannel *prev = track->channel_list; prev != NULL; prev = prev->nextLink) {
            if (prev->nextLink == ch) {
                prev->nextLink = ch->nextLink;
                return;
            }
        }
    }

    // SND_ReadInstData: the instrument for program prgNo and key (drum sets and key splits pick by key)
    bool ReadInstData(const SNDBankData *bank, int prgNo, int key, SNDInstData *inst)
    {
        if (prgNo < 0 || bank == NULL || (u32)prgNo >= bank->instCount) {
            return false;
        }
        u32 offset = bank->instOffset[prgNo];
        const u8 *data = (const u8 *)bank + (offset >> 8) + kBankShift;
        inst->type = (u8)offset;
        switch (inst->type) {
        case SND_INST_PCM:
        case SND_INST_PSG:
        case SND_INST_NOISE:
        case SND_INST_DIRECTPCM:
        case SND_INST_NULL:
            memcpy(&inst->param, data, sizeof(inst->param));
            return true;
        case SND_INST_DRUM_SET: {
            u8 min = data[0], max = data[1];
            if (key < min || key > max) {
                return false;
            }
            memcpy(inst, data + 2 + (key - min) * sizeof(SNDInstData), sizeof(*inst));
            return true;
        }
        case SND_INST_KEY_SPLIT: {
            int index = 0;
            while (key > data[index]) {
                if (++index >= SND_INST_KEYSPLIT_MAX) {
                    return false;
                }
            }
            memcpy(inst, data + SND_INST_KEYSPLIT_MAX + index * sizeof(SNDInstData), sizeof(*inst));
            return true;
        }
        default:
            return false;
        }
    }

    // SND_GetWaveDataAddress: wave archive entries hold offsets in the archive, or the address of a wave loaded
    // on its own
    const SNDWaveData *WaveData(const SNDBankData *bank, int waveArcNo, int waveIndex)
    {
        const SNDWaveArc *arc = bank->waveArcLink[waveArcNo].waveArc;
        if (arc == NULL || (u32)waveIndex >= arc->waveCount) {
            return NULL;
        }
        u32 offset = arc->waveOffset[waveIndex];
        if (offset == 0) {
            return NULL;
        }
        if (offset < HW_MAIN_MEM) {
            return (const SNDWaveData *)((const u8 *)arc + offset);
        }
        return (const SNDWaveData *)(uPtr)offset;
    }

    // SND_NoteOn: start the instrument's sound on the channel
    bool NoteOn(SNDExChannel *ch, int key, int velocity, s32 length, const SNDBankData *bank, const SNDInstData *inst)
    {
        int release = inst->param.release;
        if (release == SND_BANK_DISABLE_RELEASE) {
            length = -1;
            release = 0;
        }
        bool result;
        switch (inst->type) {
        case SND_INST_PCM:
        case SND_INST_DIRECTPCM: {
            const SNDWaveData *wave = inst->type == SND_INST_PCM
                ? WaveData(bank, inst->param.wave[1], inst->param.wave[0])
                : (const SNDWaveData *)(uPtr)((u32)inst->param.wave[1] << 16 | inst->param.wave[0]);
            result = wave != NULL && StartExChannelPcm(ch, &wave->param, wave->samples, length);
            break;
        }
        case SND_INST_PSG:
            result = StartExChannelPsg(ch, inst->param.wave[0], length);
            break;
        case SND_INST_NOISE:
            result = StartExChannelNoise(ch, length);
            break;
        default:
            result = false;
            break;
        }
        if (!result) {
            return false;
        }
        ch->key = (u8)key;
        ch->original_key = inst->param.original_key;
        ch->velocity = (u8)velocity;
        SetExChannelAttack(ch, inst->param.attack);
        SetExChannelDecay(ch, inst->param.decay);
        SetExChannelSustain(ch, inst->param.sustain);
        SetExChannelRelease(ch, release);
        ch->init_pan = (s8)(inst->param.pan - 64);
        return true;
    }

    void NoteOnCommand(SNDTrack *track, SNDPlayer *player, int key, int velocity, s32 length)
    {
        SNDExChannel *ch = NULL;
        if (track->tie_flag) {
            ch = track->channel_list;
            if (ch != NULL) {
                ch->key = (u8)key;
                ch->velocity = (u8)velocity;
            }
        }
        if (ch == NULL) {
            SNDInstData inst;
            if (!ReadInstData(player->bank, track->prgNo, key, &inst)) {
                return;
            }
            u32 mask;
            switch (inst.type) {
            case SND_INST_PCM:
            case SND_INST_DIRECTPCM:
                mask = SND_PCM_CHANNEL_MASK;
                break;
            case SND_INST_PSG:
                mask = SND_PSG_CHANNEL_MASK;
                break;
            case SND_INST_NOISE:
                mask = SND_NOISE_CHANNEL_MASK;
                break;
            default:
                return;
            }
            ch = AllocExChannel(mask & track->channel_mask, player->prio + track->prio, track->channel_mask_flag != 0, ChannelCallback, track);
            if (ch == NULL) {
                return;
            }
            if (!NoteOn(ch, key, velocity, track->tie_flag ? -1 : (length > 0 ? length : -1), player->bank, &inst)) {
                ch->prio = 0;
                FreeExChannel(ch);
                return;
            }
            ch->nextLink = track->channel_list;
            track->channel_list = ch;
        }
        if (track->attack != kTrackDefault) {
            SetExChannelAttack(ch, track->attack);
        }
        if (track->decay != kTrackDefault) {
            SetExChannelDecay(ch, track->decay);
        }
        if (track->sustain != kTrackDefault) {
            SetExChannelSustain(ch, track->sustain);
        }
        if (track->release != kTrackDefault) {
            SetExChannelRelease(ch, track->release);
        }
        ch->sweep_pitch = track->sweep_pitch;
        if (track->porta_flag) {
            ch->sweep_pitch = (s16)(ch->sweep_pitch + ((track->porta_key - key) << 6));
        }
        if (track->porta_time == 0) {
            ch->sweep_length = length > 0 ? length : -1;
            ch->auto_sweep = 0;
        } else {
            u32 sweep = (u32)abs(ch->sweep_pitch);
            ch->sweep_length = (s32)(track->porta_time * track->porta_time * sweep) >> 11;
        }
        ch->sweep_counter = 0;
    }

    // Interpret the track's commands until it has to wait; false when it ends
    bool RunTrack(SNDTrack *track, SNDPlayer *player, bool doNoteOn)
    {
        while (track->wait == 0 && !track->note_finish_wait) {
            bool cond = true;
            bool argOverride = false;
            ArgType argType = kArgU8;
            u8 cmd = ReadByte(track);
            if (cmd == SND_MML_IF) {
                cmd = ReadByte(track);
                cond = track->cmp_flag;
            }
            if (cmd == SND_MML_RANDOM) {
                cmd = ReadByte(track);
                argType = kArgRandom;
                argOverride = true;
            }
            if (cmd == SND_MML_VARIABLE) {
                cmd = ReadByte(track);
                argType = kArgVariable;
                argOverride = true;
            }
            auto arg = [&](ArgType def) { return ReadArg(track, player, argOverride ? argType : def); };

            if (!(cmd & 0x80)) {
                int velocity = ReadByte(track);
                s32 length = arg(kArgVlv);
                int key = cmd + track->transpose;
                if (!cond) {
                    continue;
                }
                key = key < 0 ? 0 : key > 127 ? 127
                                              : key;
                if (!track->mute_flag && doNoteOn) {
                    NoteOnCommand(track, player, key, velocity, length);
                }
                track->porta_key = (u8)key;
                if (track->note_wait) {
                    track->wait = length;
                    if (length == 0) {
                        track->note_finish_wait = 1;
                    }
                }
                continue;
            }

            switch (cmd & 0xF0) {
            case 0x80: {
                s32 v = arg(kArgVlv);
                if (!cond) {
                    break;
                }
                if (cmd == SND_MML_WAIT) {
                    track->wait = v;
                } else if (cmd == SND_MML_PRG && v < 0x10000) {
                    track->prgNo = (u16)v;
                }
                break;
            }
            case 0x90:
                if (cmd == SND_MML_OPEN_TRACK) {
                    int trackNo = ReadByte(track);
                    u32 offset = Read24(track);
                    SNDTrack *other = cond ? Track(player, trackNo) : NULL;
                    if (other != NULL && other != track) {
                        ReleaseTrackChannels(other, player, kNoRelease);
                        FreeTrackChannels(other);
                        other->base = track->base;
                        other->cur = track->base + offset;
                    }
                } else if (cmd == SND_MML_JUMP) {
                    u32 offset = Read24(track);
                    if (cond) {
                        track->cur = track->base + offset;
                    }
                } else if (cmd == SND_MML_CALL) {
                    u32 offset = Read24(track);
                    if (cond && track->call_stack_depth < SND_TRACK_CALL_STACK_DEPTH) {
                        track->call_stack[track->call_stack_depth++] = track->cur;
                        track->cur = track->base + offset;
                    }
                }
                break;
            case 0xB0: {
                int varNo = ReadByte(track);
                s16 v = (s16)arg(kArgS16);
                vs16 *var = Variable(player, varNo);
                if (!cond || var == NULL) {
                    break;
                }
                switch (cmd) {
                case SND_MML_SETVAR:
                    *var = v;
                    break;
                case SND_MML_ADDVAR:
                    *var = (s16)(*var + v);
                    break;
                case SND_MML_SUBVAR:
                    *var = (s16)(*var - v);
                    break;
                case SND_MML_MULVAR:
                    *var = (s16)(*var * v);
                    break;
                case SND_MML_DIVVAR:
                    if (v != 0) {
                        *var = (s16)(*var / v);
                    }
                    break;
                case SND_MML_SHIFTVAR:
                    *var = (s16)(v < 0 ? *var >> -v : *var << v);
                    break;
                case SND_MML_RANDVAR: {
                    bool negative = v < 0;
                    s32 range = negative ? (s16)-v : v;
                    s16 r = (s16)((s32)CalcRandom() * (range + 1) >> 16);
                    *var = negative ? (s16)-r : r;
                    break;
                }
                case SND_MML_CMP_EQ:
                    track->cmp_flag = *var == v;
                    break;
                case SND_MML_CMP_GE:
                    track->cmp_flag = *var >= v;
                    break;
                case SND_MML_CMP_GT:
                    track->cmp_flag = *var > v;
                    break;
                case SND_MML_CMP_LE:
                    track->cmp_flag = *var <= v;
                    break;
                case SND_MML_CMP_LT:
                    track->cmp_flag = *var < v;
                    break;
                case SND_MML_CMP_NE:
                    track->cmp_flag = *var != v;
                    break;
                }
                break;
            }
            case 0xC0:
            case 0xD0: {
                s32 v = arg(kArgU8);
                u8 b = (u8)v;
                if (!cond) {
                    break;
                }
                switch (cmd) {
                case SND_MML_PAN:
                    track->pan = (s8)(b - 64);
                    break;
                case SND_MML_VOLUME:
                    track->volume = b;
                    break;
                case SND_MML_MAIN_VOLUME:
                    player->volume = b;
                    break;
                case SND_MML_TRANSPOSE:
                    track->transpose = (s8)b;
                    break;
                case SND_MML_PITCH_BEND:
                    track->pitch_bend = (s8)b;
                    break;
                case SND_MML_BEND_RANGE:
                    track->bend_range = b;
                    break;
                case SND_MML_PRIO:
                    track->prio = b;
                    break;
                case SND_MML_NOTE_WAIT:
                    track->note_wait = v & 1;
                    break;
                case SND_MML_TIE:
                    track->tie_flag = v & 1;
                    ReleaseTrackChannels(track, player, kNoRelease);
                    FreeTrackChannels(track);
                    break;
                case SND_MML_PORTA:
                    track->porta_key = (u8)(b + track->transpose);
                    track->porta_flag = 1;
                    break;
                case SND_MML_MOD_DEPTH:
                    track->mod.depth = b;
                    break;
                case SND_MML_MOD_SPEED:
                    track->mod.speed = b;
                    break;
                case SND_MML_MOD_TYPE:
                    track->mod.target = b;
                    break;
                case SND_MML_MOD_RANGE:
                    track->mod.range = b;
                    break;
                case SND_MML_PORTA_SW:
                    track->porta_flag = v & 1;
                    break;
                case SND_MML_PORTA_TIME:
                    track->porta_time = b;
                    break;
                case SND_MML_ATTACK:
                    track->attack = b;
                    break;
                case SND_MML_DECAY:
                    track->decay = b;
                    break;
                case SND_MML_SUSTAIN:
                    track->sustain = b;
                    break;
                case SND_MML_RELEASE:
                    track->release = b;
                    break;
                case SND_MML_LOOP_START:
                    if (track->call_stack_depth < SND_TRACK_CALL_STACK_DEPTH) {
                        track->call_stack[track->call_stack_depth] = track->cur;
                        track->loop_count[track->call_stack_depth] = b;
                        track->call_stack_depth++;
                    }
                    break;
                case SND_MML_VOLUME2:
                    track->volume2 = b;
                    break;
                case SND_MML_PRINTVAR: // a debugging aid (prints a variable when enabled)
                    break;
                case SND_MML_MUTE:
                    SetTrackMute(track, player, b);
                    break;
                }
                break;
            }
            case 0xE0: {
                s16 v = (s16)arg(kArgS16);
                if (!cond) {
                    break;
                }
                if (cmd == SND_MML_MOD_DELAY) {
                    track->mod.delay = (u16)v;
                } else if (cmd == SND_MML_TEMPO) {
                    player->tempo = (u16)v;
                } else if (cmd == SND_MML_SWEEP_PITCH) {
                    track->sweep_pitch = v;
                }
                break;
            }
            case 0xF0:
                if (!cond) {
                    break;
                }
                if (cmd == SND_MML_LOOP_END) {
                    int depth = track->call_stack_depth;
                    if (depth != 0) {
                        u8 count = track->loop_count[depth - 1];
                        if (count == 0 || --count != 0) {
                            track->loop_count[depth - 1] = count;
                            track->cur = track->call_stack[depth - 1];
                        } else {
                            track->call_stack_depth--;
                        }
                    }
                } else if (cmd == SND_MML_RET) {
                    if (track->call_stack_depth != 0) {
                        track->cur = track->call_stack[--track->call_stack_depth];
                    }
                } else if (cmd == SND_MML_FIN) {
                    return false;
                }
                break;
            default:
                break;
            }
        }
        return true;
    }

    // One tick of every track; true when all of them have ended
    bool PlayerStep(SNDPlayer *player, bool doNoteOn)
    {
        bool alive = false;
        for (int i = 0; i < SND_TRACK_NUM_PER_PLAYER; i++) {
            SNDTrack *track = Track(player, i);
            if (track == NULL || track->cur == NULL) {
                continue;
            }
            for (SNDExChannel *ch = track->channel_list; ch != NULL; ch = ch->nextLink) {
                if (ch->length > 0) {
                    ch->length--;
                }
                if (!ch->auto_sweep && ch->sweep_counter < ch->sweep_length) {
                    ch->sweep_counter++;
                }
            }
            bool running = true;
            if (track->note_finish_wait && track->channel_list != NULL) {
                // the note is still sounding
            } else {
                track->note_finish_wait = 0;
                if (track->wait > 0) {
                    track->wait--;
                }
                if (track->wait <= 0) {
                    running = RunTrack(track, player, doNoteOn);
                }
            }
            if (running) {
                alive = true;
            } else {
                CloseTrack(player, i);
            }
        }
        return !alive;
    }

} // namespace

void SeqInit()
{
    for (int i = 0; i < SND_PLAYER_NUM; i++) {
        gWork.player[i].active_flag = 0;
        gWork.player[i].myNo = (u8)i;
    }
    for (int i = 0; i < SND_TRACK_NUM; i++) {
        gWork.track[i].active_flag = 0;
    }
}

void SeqMain(bool doPeriodicProc)
{
    u32 status = 0;
    for (int i = 0; i < SND_PLAYER_NUM; i++) {
        SNDPlayer *player = Player(i);
        if (!player->active_flag) {
            continue;
        }
        if (player->prepared_flag) {
            if (doPeriodicProc && !player->pause_flag) {
                int ticks = 0;
                while (player->tempo_counter >= SND_BASE_TEMPO) {
                    ticks++;
                    player->tempo_counter -= SND_BASE_TEMPO;
                }
                int done = 0;
                for (; done < ticks; done++) {
                    if (PlayerStep(player, true)) {
                        FinishPlayer(player);
                        break;
                    }
                }
                if (gShared != NULL) {
                    gShared->player[player->myNo].tickCounter += done;
                }
                player->tempo_counter = (u16)(player->tempo_counter + ((u32)player->tempo * player->tempo_ratio >> 8));
            }
            for (int t = 0; t < SND_TRACK_NUM_PER_PLAYER; t++) {
                SNDTrack *track = Track(player, t);
                if (track != NULL) {
                    UpdateTrackChannels(track, player, true);
                }
            }
        }
        if (player->active_flag) {
            status |= 1u << i;
        }
    }
    if (gShared != NULL) {
        gShared->playerStatus = status;
    }
}

void PrepareSeq(int playerNo, const void *seqBase, u32 seqOffset, SNDBankData *bank)
{
    SNDPlayer *player = Player(playerNo);
    if (player->active_flag) {
        FinishPlayer(player);
    }
    player->pause_flag = 0;
    player->bank = bank;
    player->tempo = SND_DEFAULT_TEMPO;
    player->tempo_ratio = 256;
    player->tempo_counter = SND_BASE_TEMPO;
    player->volume = 127;
    player->extFader = 0;
    player->prio = 64;
    for (int i = 0; i < SND_TRACK_NUM_PER_PLAYER; i++) {
        player->tracks[i] = kNoTrack;
    }
    if (gShared != NULL) {
        gShared->player[player->myNo].tickCounter = 0;
        for (int i = 0; i < SND_PLAYER_VARIABLE_NUM; i++) {
            gShared->player[player->myNo].variable[i] = -1;
        }
    }
    int trackIndex = AllocTrack();
    if (trackIndex < 0) {
        return;
    }
    SNDTrack *track = &gWork.track[trackIndex];
    InitTrack(track);
    track->base = (const u8 *)seqBase;
    track->cur = track->base + seqOffset;
    player->tracks[0] = (u8)trackIndex;
    // A multi-track sequence starts with the tracks it uses
    if (ReadByte(track) == SND_MML_ALLOC_TRACK) {
        u32 mask = ReadByte(track);
        mask |= (u32)ReadByte(track) << 8;
        for (int i = 1; (mask >>= 1) != 0; i++) {
            if (mask & 1) {
                int index = AllocTrack();
                if (index < 0) {
                    break;
                }
                InitTrack(&gWork.track[index]);
                player->tracks[i] = (u8)index;
            }
        }
    } else {
        track->cur--;
    }
    player->active_flag = 1;
    player->prepared_flag = 0;
    if (gShared != NULL) {
        gShared->playerStatus |= 1u << playerNo;
    }
}

void StartSeq(int playerNo, const void *seqBase, u32 seqOffset, SNDBankData *bank)
{
    PrepareSeq(playerNo, seqBase, seqOffset, bank);
    StartPreparedSeq(playerNo);
}

void StartPreparedSeq(int playerNo)
{
    Player(playerNo)->prepared_flag = 1;
}

void StopSeq(int playerNo)
{
    SNDPlayer *player = Player(playerNo);
    if (!player->active_flag) {
        return;
    }
    FinishPlayer(player);
    if (gShared != NULL) {
        gShared->playerStatus &= ~(1u << playerNo);
    }
}

void PauseSeq(int playerNo, bool flag)
{
    SNDPlayer *player = Player(playerNo);
    player->pause_flag = flag;
    if (!flag) {
        return;
    }
    for (int i = 0; i < SND_TRACK_NUM_PER_PLAYER; i++) {
        SNDTrack *track = Track(player, i);
        if (track != NULL) {
            ReleaseTrackChannels(track, player, 127);
            FreeTrackChannels(track);
        }
    }
}

// Run the sequence ahead without notes
void SkipSeq(int playerNo, u32 tick)
{
    SNDPlayer *player = Player(playerNo);
    for (int i = 0; i < SND_TRACK_NUM_PER_PLAYER; i++) {
        SNDTrack *track = Track(player, i);
        if (track != NULL) {
            ReleaseTrackChannels(track, player, 127);
            FreeTrackChannels(track);
        }
    }
    u32 done = 0;
    for (; done < tick; done++) {
        if (PlayerStep(player, false)) {
            FinishPlayer(player);
            break;
        }
    }
    RestartIntervalTimer();
    if (gShared != NULL) {
        gShared->player[player->myNo].tickCounter += done;
    }
}

static void WriteParam(void *base, u32 offset, u32 data, int size)
{
    u8 *p = (u8 *)base + offset;
    if (size == 1) {
        *p = (u8)data;
    } else if (size == 2) {
        *(u16 *)p = (u16)data;
    } else if (size == 4) {
        *(u32 *)p = data;
    }
}

void SetPlayerParam(int playerNo, u32 offset, u32 data, int size)
{
    WriteParam(Player(playerNo), offset, data, size);
}

void SetTrackParam(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size)
{
    SNDPlayer *player = Player(playerNo);
    for (int i = 0; i < SND_TRACK_NUM_PER_PLAYER && trackBitMask != 0; i++, trackBitMask >>= 1) {
        SNDTrack *track = (trackBitMask & 1) ? Track(player, i) : NULL;
        if (track != NULL) {
            WriteParam(track, offset, data, size);
        }
    }
}

void SetTrackMute(int playerNo, u32 trackBitMask, int mute)
{
    SNDPlayer *player = Player(playerNo);
    for (int i = 0; i < SND_TRACK_NUM_PER_PLAYER && trackBitMask != 0; i++, trackBitMask >>= 1) {
        SNDTrack *track = (trackBitMask & 1) ? Track(player, i) : NULL;
        if (track != NULL) {
            SetTrackMute(track, player, mute);
        }
    }
}

void SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask)
{
    SNDPlayer *player = Player(playerNo);
    for (int i = 0; i < SND_TRACK_NUM_PER_PLAYER && trackBitMask != 0; i++, trackBitMask >>= 1) {
        SNDTrack *track = (trackBitMask & 1) ? Track(player, i) : NULL;
        if (track != NULL) {
            track->channel_mask = (u16)chBitMask;
            track->channel_mask_flag = 1;
        }
    }
}

void SetPlayerLocalVariable(int playerNo, int varNo, s16 var)
{
    if (gShared != NULL) {
        gShared->player[playerNo].variable[varNo] = var;
    }
}

void SetPlayerGlobalVariable(int varNo, s16 var)
{
    if (gShared != NULL) {
        gShared->globalVariable[varNo] = var;
    }
}

// Sequence data in [start, end] goes away: stop the players reading it
void InvalidateSeq(const void *start, const void *end)
{
    for (int i = 0; i < SND_PLAYER_NUM; i++) {
        SNDPlayer *player = Player(i);
        if (!player->active_flag) {
            continue;
        }
        for (int t = 0; t < SND_TRACK_NUM_PER_PLAYER; t++) {
            SNDTrack *track = Track(player, t);
            if (track != NULL && start <= (const void *)track->cur && (const void *)track->cur <= end) {
                FinishPlayer(player);
                break;
            }
        }
    }
}

void InvalidateBank(const void *start, const void *end)
{
    for (int i = 0; i < SND_PLAYER_NUM; i++) {
        SNDPlayer *player = Player(i);
        if (player->active_flag && start <= (const void *)player->bank && (const void *)player->bank <= end) {
            FinishPlayer(player);
        }
    }
}

} // namespace ntros::snd
