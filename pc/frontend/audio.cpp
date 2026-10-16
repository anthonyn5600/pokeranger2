// Sound out of the computer's speakers: ntros's sound hardware output (NTROS_AUDIO_RATE) into an SDL audio device,
// resampled to the device's rate. The sound card's clock, not the computer's, sets the pace: the frame limiter asks
// Audio_FrameNs for the frame length, which is up to 5 % shorter or longer than the DS's to keep about kTargetMs
// of sound queued (enough to ride out short stalls, like a window switch or a load).
// PC_AUDIO_MUTE=1 sends silence to the device (same timing; for tests that must not be heard).
// PC_AUDIO_DUMP=file.wav also writes the DS's own output (before resampling) to a file; PC_AUDIO_LOG=1 reports
// the queue.
#include <SDL2/SDL.h>
#include <algorithm>
#include <atomic>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <time.h>
#include <vector>

#include "frontend.h"
#include "ntros.h"

namespace {

constexpr int kTargetMs = 100;
constexpr int kMaxMs = 400; // more than this queued (nobody plays it): drop
constexpr double kDsFrameNs = 1e9 * 263 * 2130 / 33513982; // 16.715 ms

std::atomic<SDL_AudioDeviceID> sDevice; // 0 until the device is open
int sRate;
double sPos; // resampler: position between the previous input frame (0) and the next (1)
short sPrev[2];
std::vector<short> sBuf;
FILE *sDump;
Uint32 sPushed; // device frames queued so far (for PC_AUDIO_LOG)
Uint32 sDumpFrames;

void WriteWavHeader()
{
    auto u32 = [](Uint32 v) { fwrite(&v, 4, 1, sDump); };
    auto u16 = [](Uint16 v) { fwrite(&v, 2, 1, sDump); };
    fseek(sDump, 0, SEEK_SET);
    fwrite("RIFF", 1, 4, sDump);
    u32(36 + sDumpFrames * 4);
    fwrite("WAVEfmt ", 1, 8, sDump);
    u32(16);
    u16(1);
    u16(2);
    u32(NTROS_AUDIO_RATE);
    u32(NTROS_AUDIO_RATE * 4);
    u16(4);
    u16(16);
    fwrite("data", 1, 4, sDump);
    u32(sDumpFrames * 4);
    fseek(sDump, 0, SEEK_END);
    fflush(sDump);
}

void Dump(const short *frames, int count)
{
    static bool sTried;
    if (!sTried) {
        sTried = true;
        const char *path = getenv("PC_AUDIO_DUMP");
        if (path != NULL && (sDump = fopen(path, "wb")) != NULL) {
            WriteWavHeader();
        }
    }
    if (sDump != NULL) {
        fwrite(frames, 4, (size_t)count, sDump);
        sDumpFrames += (Uint32)count;
        WriteWavHeader();
    }
}

bool Open()
{
    if (!SDL_WasInit(SDL_INIT_AUDIO) && SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
        fprintf(stderr, "pc: no sound: %s\n", SDL_GetError());
        return false;
    }
    SDL_AudioSpec want = {};
    SDL_AudioSpec have;
    want.freq = 48000;
    want.format = AUDIO_S16SYS;
    want.channels = 2;
    want.samples = 1024;
    SDL_AudioDeviceID device = SDL_OpenAudioDevice(NULL, 0, &want, &have, SDL_AUDIO_ALLOW_FREQUENCY_CHANGE);
    if (device == 0) {
        fprintf(stderr, "pc: no sound: %s\n", SDL_GetError());
        return false;
    }
    sRate = have.freq;
    SDL_PauseAudioDevice(device, 0);
    sDevice = device;
    return true;
}

// PC_AUDIO_LOG=1: every 5 s, how full the device queue was and how often it ran dry (the game fell behind)
double NowMs()
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec * 1e3 + t.tv_nsec / 1e6;
}

void Report(Uint32 queued)
{
    static const bool sLog = getenv("PC_AUDIO_LOG") != NULL;
    static double sStart;
    static Uint32 sMin = ~0u, sMax, sDry;
    static unsigned long long sFrame0;
    static Uint32 sPushed0, sQueued0;
    if (!sLog) {
        return;
    }
    double now = NowMs();
    if (sStart == 0) {
        sStart = now;
        sFrame0 = NtrOs_GetFrame();
        sPushed0 = sPushed;
        sQueued0 = queued;
    }
    sMin = queued < sMin ? queued : sMin;
    sMax = queued > sMax ? queued : sMax;
    sDry += queued == 0;
    if (now - sStart >= 5000) {
        double secs = (now - sStart) / 1000;
        fprintf(stderr, "pc: audio queue %u..%u ms, ran dry %u times, %.1f frames/s, device plays %.0f Hz\n", sMin * 1000 / sRate, sMax * 1000 / sRate, sDry, (NtrOs_GetFrame() - sFrame0) / secs, ((double)(sPushed - sPushed0) - ((double)queued - sQueued0)) / secs);
        sPushed0 = sPushed;
        sQueued0 = queued;
        sFrame0 = NtrOs_GetFrame();
        sStart = now;
        sMin = ~0u;
        sMax = 0;
        sDry = 0;
    }
}

// The device opens with the first sound (main has started SDL by then)
void Samples(const short *frames, int count)
{
    Dump(frames, count);
    // The device opens on its own thread: a stuck audio server (WSLg) can take half a minute to give up
    static const bool sOpening = (std::thread([] { Open(); }).detach(), true); // detached: exiting must not wait
    (void)sOpening;
    if (sDevice == 0) {
        return;
    }
    Uint32 queued = SDL_GetQueuedAudioSize(sDevice) / 4;
    Report(queued);
    if (queued > (Uint32)(sRate * kMaxMs / 1000)) {
        // The device stopped playing (WSLg's audio server stalls now and then): one clean gap instead of a stream of
        // cut pieces
        fprintf(stderr, "pc: audio device stalled (%u ms queued)\n", queued * 1000 / sRate);
        SDL_ClearQueuedAudio(sDevice);
        queued = 0;
    }
    double step = 33513982.0 / 1024 / sRate;
    sBuf.clear();
    for (int i = 0; i < count; i++) {
        const short *cur = frames + i * 2;
        while (sPos < 1.0) {
            for (int c = 0; c < 2; c++) {
                sBuf.push_back((short)(sPrev[c] + (cur[c] - sPrev[c]) * sPos));
            }
            sPos += step;
        }
        sPos -= 1.0;
        sPrev[0] = cur[0];
        sPrev[1] = cur[1];
    }
    static const bool sMute = getenv("PC_AUDIO_MUTE") != NULL;
    if (sMute) {
        std::fill(sBuf.begin(), sBuf.end(), (short)0);
    }
    SDL_QueueAudio(sDevice, sBuf.data(), (Uint32)(sBuf.size() * sizeof(short)));
    sPushed += (Uint32)(sBuf.size() / 2);
}

struct RegisterAudio {
    RegisterAudio()
    {
        static const NtrOsAudio audio = { Samples };
        NtrOs_SetAudio(&audio);
    }
} sRegisterAudio;

} // namespace

long Audio_FrameNs()
{
    if (sDevice == 0) {
        return 0;
    }
    double target = sRate * kTargetMs / 1000.0;
    double fill = (SDL_GetQueuedAudioSize(sDevice) / 4 - target) / target;
    fill = fill < -1 ? -1 : fill > 1 ? 1
                                     : fill;
    return (long)(kDsFrameNs * (1.0 + 0.05 * fill));
}
