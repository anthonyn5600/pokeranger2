// "Who wrote this?" tracking for display memory (VRAM, palettes, OAM).
//
// Every SDK copy/fill function is wrapped at link time (-Wl,--wrap=..., see pc/meson.build): DMA copies, the
// GX_Load* functions, NNS VRAM transfer tasks and the MI_Cpu* helpers all end up here. When the destination is
// display memory and NTRGFX_TRACK=1, the call stack and frame number are recorded per 32-byte block, plus a log of
// recent writes. Snapshot dumps (NTRGFX_DUMP_*) then also write frame_N.writes; pc/tools/whowrote answers
// "who last wrote this address" from it, with function names and source lines.
// Not seen: writes through plain pointers (e.g. the game drawing text straight into VRAM, NNS char canvases).
//
//   NTRGFX_TRACK=1                    record writers (needed for .writes files)
//   NTRGFX_TRACE=bgA:0x4000-0x4100    also print every write overlapping this range as it happens (implies TRACK)

#include "vramtrack.hpp"

#include <execinfo.h>
#include <nitro.h>
#include <simulator/simvariables.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace {

struct Region {
    const char *name;
    u8 *base;
    u32 size;
};

// Names match pc/tools/whowrote and the snapshot layout (ntrgfx.h)
Region sRegions[] = {
    { "bgA", s_HW_BG_VRAM, sizeof(s_HW_BG_VRAM) },
    { "objA", s_HW_OBJ_VRAM, sizeof(s_HW_OBJ_VRAM) },
    { "bgB", s_HW_DB_BG_VRAM, sizeof(s_HW_DB_BG_VRAM) },
    { "objB", s_HW_DB_OBJ_VRAM, sizeof(s_HW_DB_OBJ_VRAM) },
    { "banks", s_HW_LCDC_VRAM, sizeof(s_HW_LCDC_VRAM) },
    { "plttBgA", s_HW_BG_PLTT, sizeof(s_HW_BG_PLTT) },
    { "plttObjA", s_HW_OBJ_PLTT, sizeof(s_HW_OBJ_PLTT) },
    { "plttBgB", s_HW_DB_BG_PLTT, sizeof(s_HW_DB_BG_PLTT) },
    { "plttObjB", s_HW_DB_OBJ_PLTT, sizeof(s_HW_DB_OBJ_PLTT) },
    { "oamA", s_HW_OAM, sizeof(s_HW_OAM) },
    { "oamB", s_HW_DB_OAM, sizeof(s_HW_DB_OAM) },
};
const int kRegionCount = sizeof(sRegions) / sizeof(sRegions[0]);
const u32 kBlock = 32;
const int kStackDepth = 12;
const size_t kLogSize = 1 << 16;

struct Site {
    void *stack[kStackDepth];
    int depth;
    const char *func; // the SDK function that wrote
};

struct LogEntry {
    u32 frame;
    u16 region;
    u32 offset;
    u32 size;
    u32 site;
};

struct BlockOwner {
    u32 site; // index + 1 into S().sites, 0 = never written
    u32 frame;
};

// Game code copies memory from global constructors, before this file's globals would be constructed: keep the
// containers in a function-local static (built on first use) and the rest constant-initialized.
struct State {
    std::vector<Site> sites;
    std::unordered_map<std::string, u32> siteIndex;
    std::vector<BlockOwner> owners[kRegionCount];
    std::vector<LogEntry> log;
};

State &S()
{
    static State sState;
    return sState;
}

int sEnabled = -1;
u32 sFrame;
size_t sLogNext;
bool sLogWrapped;
bool sInside; // no recursion when a wrapped function calls another

int sTraceRegion = -1;
u32 sTraceBegin, sTraceEnd;

int RegionByName(const char *name, size_t len)
{
    for (int i = 0; i < kRegionCount; i++) {
        if (strlen(sRegions[i].name) == len && strncmp(sRegions[i].name, name, len) == 0) {
            return i;
        }
    }
    return -1;
}

bool Enabled()
{
    if (sEnabled < 0) {
        const char *track = getenv("NTRGFX_TRACK");
        const char *trace = getenv("NTRGFX_TRACE");
        sEnabled = (track != NULL && strcmp(track, "1") == 0) || trace != NULL;
        if (trace != NULL) {
            // REGION:BEGIN-END (hex or decimal)
            const char *colon = strchr(trace, ':');
            if (colon != NULL && (sTraceRegion = RegionByName(trace, colon - trace)) >= 0) {
                char *end;
                sTraceBegin = (u32)strtoul(colon + 1, &end, 0);
                sTraceEnd = *end == '-' ? (u32)strtoul(end + 1, NULL, 0) : sTraceBegin + 1;
            } else {
                fprintf(stderr, "vramtrack: NTRGFX_TRACE must be REGION:BEGIN-END (regions bgA objA bgB objB banks "
                                "plttBgA plttObjA plttBgB plttObjB oamA oamB)\n");
            }
        }
        if (sEnabled) {
            for (int i = 0; i < kRegionCount; i++) {
                S().owners[i].assign(sRegions[i].size / kBlock, BlockOwner { 0, 0 });
            }
            S().log.resize(kLogSize);
            fprintf(stderr, "vramtrack: recording display memory writers\n");
        }
    }
    return sEnabled != 0;
}

u32 InternSite(const char *func)
{
    Site site;
    site.func = func;
    site.depth = backtrace(site.stack, kStackDepth);
    // frame 0 = this function, 1 = Record, 2 = the __wrap_ function: skip them
    std::string key(func);
    key.append((const char *)&site.stack[3], sizeof(void *) * (site.depth > 3 ? site.depth - 3 : 0));
    auto it = S().siteIndex.find(key);
    if (it != S().siteIndex.end()) {
        return it->second;
    }
    S().sites.push_back(site);
    u32 id = (u32)S().sites.size();
    S().siteIndex.emplace(key, id);
    return id;
}

void Record(const char *func, const volatile void *dst, u32 size)
{
    if (size == 0 || sInside || !Enabled()) {
        return;
    }
    const u8 *p = (const u8 *)dst;
    for (int r = 0; r < kRegionCount; r++) {
        const Region &reg = sRegions[r];
        if (p + size <= reg.base || p >= reg.base + reg.size) {
            continue;
        }
        sInside = true;
        u32 offset = p >= reg.base ? (u32)(p - reg.base) : 0;
        u32 end = (u32)((p + size > reg.base + reg.size ? reg.base + reg.size : p + size) - reg.base);
        u32 site = InternSite(func);
        for (u32 b = offset / kBlock; b <= (end - 1) / kBlock; b++) {
            S().owners[r][b] = BlockOwner { site, sFrame };
        }
        S().log[sLogNext] = LogEntry { sFrame, (u16)r, offset, end - offset, site };
        sLogNext = (sLogNext + 1) % kLogSize;
        sLogWrapped |= sLogNext == 0;
        if (r == sTraceRegion && offset < sTraceEnd && end > sTraceBegin) {
            fprintf(stderr, "vramtrack: frame %u %s %s:%#x-%#x site %u stack", sFrame, func, reg.name, offset, end, site);
            const Site &s = S().sites[site - 1];
            for (int i = 3; i < s.depth; i++) {
                fprintf(stderr, " %p", s.stack[i]);
            }
            fprintf(stderr, "\n");
        }
        sInside = false;
    }
}

} // namespace

void VramTrack_SetFrame(u32 frame)
{
    sFrame = frame;
}

bool VramTrack_Save(const char *path)
{
    if (!Enabled()) {
        return true;
    }
    FILE *f = fopen(path, "w");
    if (f == NULL) {
        return false;
    }
    // Text format, read by pc/tools/whowrote
    fprintf(f, "# vramtrack frame %u; addresses are in pc/build/pokeranger2 (non-PIE)\n", sFrame);
    for (size_t i = 0; i < S().sites.size(); i++) {
        const Site &s = S().sites[i];
        fprintf(f, "SITE %zu %s", i + 1, s.func);
        for (int k = 3; k < s.depth; k++) {
            fprintf(f, " %p", s.stack[k]);
        }
        fprintf(f, "\n");
    }
    for (int r = 0; r < kRegionCount; r++) {
        // Runs of blocks with the same owner
        const std::vector<BlockOwner> &own = S().owners[r];
        size_t b = 0;
        while (b < own.size()) {
            size_t e = b + 1;
            while (e < own.size() && own[e].site == own[b].site && own[e].frame == own[b].frame) {
                e++;
            }
            if (own[b].site != 0) {
                fprintf(f, "OWNER %s %#zx %#zx %u %u\n", sRegions[r].name, b * kBlock, e * kBlock, own[b].site, own[b].frame);
            }
            b = e;
        }
    }
    size_t count = sLogWrapped ? kLogSize : sLogNext;
    size_t first = sLogWrapped ? sLogNext : 0;
    for (size_t i = 0; i < count; i++) {
        const LogEntry &e = S().log[(first + i) % kLogSize];
        fprintf(f, "WRITE %u %s %#x %#x %u\n", e.frame, sRegions[e.region].name, e.offset, e.offset + e.size, e.site);
    }
    fclose(f);
    return true;
}

// Link-time wrappers (-Wl,--wrap=NAME): __real_NAME is the SDK's function
extern "C" {
void __real_MI_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size);
void __wrap_MI_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size)
{
    Record("MI_DmaCopy32", dest, size);
    __real_MI_DmaCopy32(dmaNo, src, dest, size);
}

void __real_MI_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size);
void __wrap_MI_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size)
{
    Record("MI_DmaCopy16", dest, size);
    __real_MI_DmaCopy16(dmaNo, src, dest, size);
}

void __real_MI_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size);
void __wrap_MI_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size)
{
    Record("MI_DmaFill32", dest, size);
    __real_MI_DmaFill32(dmaNo, dest, data, size);
}

void __real_MI_DmaFill16(u32 dmaNo, void *dest, u16 data, u32 size);
void __wrap_MI_DmaFill16(u32 dmaNo, void *dest, u16 data, u32 size)
{
    Record("MI_DmaFill16", dest, size);
    __real_MI_DmaFill16(dmaNo, dest, data, size);
}

void __real_MI_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg);
void __wrap_MI_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg)
{
    Record("MI_DmaCopy32Async", dest, size);
    __real_MI_DmaCopy32Async(dmaNo, src, dest, size, callback, arg);
}

void __real_MI_DmaCopy16Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg);
void __wrap_MI_DmaCopy16Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg)
{
    Record("MI_DmaCopy16Async", dest, size);
    __real_MI_DmaCopy16Async(dmaNo, src, dest, size, callback, arg);
}

void __real_MI_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg);
void __wrap_MI_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg)
{
    Record("MI_DmaFill32Async", dest, size);
    __real_MI_DmaFill32Async(dmaNo, dest, data, size, callback, arg);
}

void __real_MI_DmaFill16Async(u32 dmaNo, void *dest, u16 data, u32 size, MIDmaCallback callback, void *arg);
void __wrap_MI_DmaFill16Async(u32 dmaNo, void *dest, u16 data, u32 size, MIDmaCallback callback, void *arg)
{
    Record("MI_DmaFill16Async", dest, size);
    __real_MI_DmaFill16Async(dmaNo, dest, data, size, callback, arg);
}

void __real_MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
void __wrap_MIi_CpuCopy16(const void *srcp, void *destp, u32 size)
{
    Record("MI_CpuCopy16", destp, size);
    __real_MIi_CpuCopy16(srcp, destp, size);
}

void __real_MIi_CpuCopy32(const void *srcp, void *destp, u32 size);
void __wrap_MIi_CpuCopy32(const void *srcp, void *destp, u32 size)
{
    Record("MI_CpuCopy32", destp, size);
    __real_MIi_CpuCopy32(srcp, destp, size);
}

void __real_MIi_CpuCopyFast(const void *srcp, void *destp, u32 size);
void __wrap_MIi_CpuCopyFast(const void *srcp, void *destp, u32 size)
{
    Record("MI_CpuCopyFast", destp, size);
    __real_MIi_CpuCopyFast(srcp, destp, size);
}

void __real_MIi_CpuClear16(u16 data, void *destp, u32 size);
void __wrap_MIi_CpuClear16(u16 data, void *destp, u32 size)
{
    Record("MI_CpuFill16", destp, size);
    __real_MIi_CpuClear16(data, destp, size);
}

void __real_MIi_CpuClear32(u32 data, void *destp, u32 size);
void __wrap_MIi_CpuClear32(u32 data, void *destp, u32 size)
{
    Record("MI_CpuFill32", destp, size);
    __real_MIi_CpuClear32(data, destp, size);
}

void __real_MIi_CpuClearFast(u32 data, void *destp, u32 size);
void __wrap_MIi_CpuClearFast(u32 data, void *destp, u32 size)
{
    Record("MI_CpuFillFast", destp, size);
    __real_MIi_CpuClearFast(data, destp, size);
}

void __real_MI_CpuCopy8(const void *src, void *dest, u32 size);
void __wrap_MI_CpuCopy8(const void *src, void *dest, u32 size)
{
    Record("MI_CpuCopy8", dest, size);
    __real_MI_CpuCopy8(src, dest, size);
}

void __real_MI_CpuFill8(void *dest, u8 data, u32 size);
void __wrap_MI_CpuFill8(void *dest, u8 data, u32 size)
{
    Record("MI_CpuFill8", dest, size);
    __real_MI_CpuFill8(dest, data, size);
}

#define WRAP_FIXED_COPY(n)                                    \
    void __real_MI_Copy##n##B(const void *pSrc, void *pDest); \
    void __wrap_MI_Copy##n##B(const void *pSrc, void *pDest)  \
    {                                                         \
        Record("MI_Copy" #n "B", pDest, n);                   \
        __real_MI_Copy##n##B(pSrc, pDest);                    \
    }
WRAP_FIXED_COPY(16)
WRAP_FIXED_COPY(32)
WRAP_FIXED_COPY(36)
WRAP_FIXED_COPY(48)
WRAP_FIXED_COPY(64)
WRAP_FIXED_COPY(128)

#define WRAP_FIXED_ZERO(n)                  \
    void __real_MI_Zero##n##B(void *pDest); \
    void __wrap_MI_Zero##n##B(void *pDest)  \
    {                                       \
        Record("MI_Zero" #n "B", pDest, n); \
        __real_MI_Zero##n##B(pDest);        \
    }
WRAP_FIXED_ZERO(36)
}
