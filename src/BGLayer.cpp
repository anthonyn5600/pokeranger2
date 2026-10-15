#include "BGLayer.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "CGame.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CNCLRFile.hpp"
#include "file/CNSCRFile.hpp"
#include "heap.hpp"

// declared in this order so that mwcc's .bss pool puts them at MAIN_BSS_0210C1AC, +4, +8
u32 gBGLoadedSize; // size of the last loaded NCGR/NCLR/NSCR copy (also read by overlay 27)
static u32 sScreenWidth; // MAIN_BSS_0210C1AC
static u32 sScreenHeight; // MAIN_BSS_0210C1B4

void SetOamAffine(int index, const MtxFx22 *mtx, BOOL mainScreen)
{
    s16 pa = (s16)(mtx->_00 >> 4);
    s16 pb = (s16)(mtx->_01 >> 4);
    s16 pc = (s16)(mtx->_10 >> 4);
    s16 pd = (s16)(mtx->_11 >> 4);
    GXOamAffine *oam;
    if (mainScreen) {
        oam = (GXOamAffine *)&CGame::GetInstance()->unk_0024[(u8)(index * 4)];
    } else {
        oam = (GXOamAffine *)&CGame::GetInstance()->unk_0424[(u8)(index * 4)];
    }
    oam->PA = pa;
    oam->PB = pb;
    oam->PC = pc;
    oam->PD = pd;
}

void SetOamAffineScale(int index, fx32 sx, fx32 sy, BOOL mainScreen)
{
    MtxFx22 mtx;
    MTX_Scale22(&mtx, sx, sy);
    SetOamAffine(index, &mtx, mainScreen);
}

BGLayer::BGLayer()
{
    unk_60 = 0;
    Init();
}

BGLayer::BGLayer(int arg0)
{
    unk_60 = arg0;
    Init();
}

BGLayer::~BGLayer()
{
    Release();
}

void BGLayer::Init()
{
    unk_00 = 0;
    unk_08 = NULL;
    unk_04 = 0;
    unk_0C = 0;
    unk_14 = NULL;
    unk_10 = 0;
    unk_18 = 0;
    unk_20 = NULL;
    unk_1C = 0;
    unk_28 = 0;
    unk_5C = NULL;
}

void BGLayer::Release()
{
    FreeChar();
    FreePltt();
    FreeScr();
    ReleaseArchive();
}

void BGLayer::LoadCharToVram()
{
    if (unk_08 != NULL) {
        BG_LoadChar(unk_28, unk_08, unk_04, unk_00);
    }
}

void BGLayer::LoadCharToVramPartial(int step, int steps)
{
    u32 start;
    u32 size;
    void *data;
    u32 chunk;
    data = unk_08;
    if (data == NULL) {
        return;
    }
    size = unk_04;
    chunk = size / steps;
    if (chunk < 4) {
        BG_LoadChar(unk_28, data, size, unk_00);
        return;
    }
    chunk -= chunk & 3;
    start = chunk * step;
    if (step == steps - 1) {
        chunk = size - start;
    }
    u32 offset = unk_00;
    if (offset != 0) {
        if (!BG_Is256Color(unk_28)) {
            offset <<= 5;
        } else {
            offset <<= 6;
        }
    }
    BG_LoadCharRaw(unk_28, (u8 *)data + start, chunk, offset + start);
}

void BGLayer::LoadPlttToVram(BOOL ext)
{
    if (unk_14 != NULL) {
        BG_LoadPltt(unk_28, unk_14, unk_10, unk_0C, ext);
    }
}

void BGLayer::Setup(int width, int height)
{
    unk_44 = 0x100;
    unk_48 = 0x100;
    unk_4C = width;
    unk_50 = height;
    unk_24 = GetScrPtr();
}

void *BGLayer::GetScrPtr()
{
    switch (unk_28) {
    case 0:
        return G2_GetBG0ScrPtr();
    case 1:
        return G2_GetBG1ScrPtr();
    case 2:
        return G2_GetBG2ScrPtr();
    case 3:
        return G2_GetBG3ScrPtr();
    case 4:
        return G2S_GetBG0ScrPtr();
    case 5:
        return G2S_GetBG1ScrPtr();
    case 6:
        return G2S_GetBG2ScrPtr();
    case 7:
        return G2S_GetBG3ScrPtr();
    }
    return NULL;
}

void BGLayer::LoadScrToVram()
{
    BG_LoadScr(unk_28, unk_20, unk_1C, unk_18);
}

void BGLayer::LoadToVram()
{
    LoadCharToVram();
    LoadPlttToVram(FALSE);
    LoadScrToVram();
}

void BGLayer::Draw(int x, int y)
{
    SetOffset(x, y);
    int tx = unk_54;
    int ty = unk_58;
    int w;
    int h;
    GetTileRect(&tx, &ty, &w, &h);
    CopyTiles(tx, ty, w, h);
}

void BGLayer::Scroll(int x, int y)
{
    int ox = unk_54;
    int oy = unk_58;
    int ow;
    int oh;
    GetTileRect(&ox, &oy, &ow, &oh);
    int oright = ox + ow;
    int obottom = oy + oh;
    SetOffset(x, y);
    int nx = unk_54;
    int ny = unk_58;
    int nw;
    int nh;
    GetTileRect(&nx, &ny, &nw, &nh);
    int nright = nx + nw;
    int nbottom = ny + nh;
    BOOL copied = FALSE;
    if (nx != ox || nw > ow) {
        if (nx < ox && nright >= ox) {
            CopyTiles(nx, ny, ox - nx, nh);
            copied = TRUE;
        }
        if (nright > oright && nx < oright) {
            CopyTiles(oright, ny, nright - oright, nh);
            copied = TRUE;
        }
    }
    if (ny != oy || nh > oh) {
        if (ny < oy && nbottom >= oy) {
            CopyTiles(nx, ny, nw, oy - ny);
            copied = TRUE;
        }
        if (nbottom > obottom && ny < obottom) {
            CopyTiles(nx, obottom, nw, nbottom - obottom);
            copied = TRUE;
        }
    }
    if (!copied) {
        if (nright < ox || nbottom < oy || nx > oright || ny > obottom) {
            CopyTiles(nx, ny, nw, nh);
        }
    }
    DC_FlushAll();
}

void BGLayer::CopyTiles(int x, int y, int width, int height)
{
    u16 *dst;
    int vw;
    int vh;
    int sw;
    int sh;
    int i;
    int j;
    int tx;
    int ty;
    sw = unk_34 / 8;
    sh = unk_38 / 8;
    vw = unk_44 / 8;
    vh = unk_48 / 8;
    unk_24 = GetScrPtr();
    for (j = 0; j < width; j++) {
        tx = x + j;
        for (i = 0; i < height; i++) {
            ty = y + i;
            dst = GetTilePtr((u16 *)unk_24, tx, ty, vw, vh);
            if (tx < 0 || tx >= sw || ty < 0 || ty >= sh) {
                *dst = 0;
            } else {
                *dst = *GetTilePtr((u16 *)unk_20, tx, ty, sw, sh);
            }
        }
    }
}

void BGLayer::GetTileRect(int *x, int *y, int *width, int *height)
{
    int w = unk_4C;
    int h = unk_50;
    *x = *x >> 3;
    *y = *y >> 3;
    *width = w >> 3;
    *height = h >> 3;
}

u16 *BGLayer::GetTilePtr(u16 *scr, int x, int y, int width, int height)
{
    int tx = x % width;
    int ty = y % height;
    if (tx >= 32) {
        scr += 0x400;
    }
    if (ty >= 32) {
        scr += 0x800;
    }
    int index = (tx & 0x1F) + ((ty & 0x1F) << 5);
    return scr + index;
}

void BGLayer::SetBG(int bg)
{
    unk_28 = bg;
}

void BGLayer::SetOffset(int x, int y)
{
    unk_54 = x;
    unk_58 = y;
    switch (unk_28) {
    case 0:
        G2_SetBG0Offset(x, y);
        break;
    case 1:
        G2_SetBG1Offset(x, y);
        break;
    case 2:
        G2_SetBG2Offset(x, y);
        break;
    case 3:
        G2_SetBG3Offset(x, y);
        break;
    case 4:
        G2S_SetBG0Offset(x, y);
        break;
    case 5:
        G2S_SetBG1Offset(x, y);
        break;
    case 6:
        G2S_SetBG2Offset(x, y);
        break;
    case 7:
        G2S_SetBG3Offset(x, y);
        break;
    }
}

void BGLayer::LoadArchive(const char *dir, const char *name)
{
    unk_5C = BGS_OpenArchiveLZ(dir, name);
}

void BGLayer::ReleaseArchive()
{
    SAFE_DELETE(unk_5C);
}

void *BGLayer::LoadChar(const char *name, int mode, u32 offset, u32 arg3)
{
    if (unk_08 != NULL) {
        Heap_Free(unk_08);
        unk_08 = NULL;
    }
    if (mode == 0) {
        mode = 1;
    }
    unk_08 = BGS_LoadCharByName("BGS", unk_28, name, offset, mode, arg3);
    unk_04 = gBGLoadedSize;
    unk_00 = offset;
    return unk_08;
}

void *BGLayer::LoadPltt(const char *name, int mode, u32 offset, u32 arg3)
{
    if (unk_14 != NULL) {
        Heap_Free(unk_14);
        unk_14 = NULL;
    }
    if (mode == 0) {
        mode = 1;
    }
    unk_14 = BGS_LoadPlttByName("BGS", unk_28, name, offset, mode, arg3);
    unk_10 = gBGLoadedSize;
    unk_0C = offset;
    return unk_14;
}

void *BGLayer::LoadScr(const char *name, int mode, u32 arg2, u32 charAdd, u32 offset, u32 arg5)
{
    if (unk_20 != NULL) {
        Heap_Free(unk_20);
        unk_20 = NULL;
    }
    if (mode == 0) {
        mode = 1;
    }
    unk_20 = BGS_LoadScrByName("BGS", unk_28, name, arg2, charAdd, mode, arg5, offset);
    unk_1C = gBGLoadedSize;
    unk_34 = sScreenWidth;
    unk_38 = sScreenHeight;
    unk_18 = offset;
    return unk_20;
}

void *BGLayer::LoadScrFile(const char *path, int mode, u32 plttNo, u32 charAdd, u32 offset, u32 arg5)
{
    if (unk_20 != NULL) {
        Heap_Free(unk_20);
        unk_20 = NULL;
    }
    if (mode == 0) {
        mode = 1;
    }
    unk_20 = BGS_LoadScrFile(path, unk_28, arg5, plttNo, charAdd, mode, offset);
    unk_1C = gBGLoadedSize;
    unk_34 = sScreenWidth;
    unk_38 = sScreenHeight;
    return unk_20;
}

void BGLayer::FreeChar()
{
    if (unk_08 != NULL) {
        Heap_Free(unk_08);
        unk_08 = NULL;
    }
}

void BGLayer::FreePltt()
{
    if (unk_14 != NULL) {
        Heap_Free(unk_14);
        unk_14 = NULL;
    }
}

void BGLayer::FreeScr()
{
    if (unk_20 != NULL) {
        Heap_Free(unk_20);
        unk_20 = NULL;
    }
}

CArchiveGuard *BGS_OpenArchive(const char *path)
{
    return new CArchiveGuard("BGS", path, 1, 1, CGame::GetInstance()->unk_14A8, NULL, 0);
}

CArchiveGuard *BGS_OpenArchiveLZ(const char *dir, const char *name)
{
    char path[0x40];
    OS_SPrintf(path, "data/%s%sLZ.bin", dir, name);
    return BGS_OpenArchive(path);
}

int BGS_LoadCharAndPltt(const char *dir, const char *name, int bg, const char *charName, u32 charOffset, const char *plttName, u32 plttOffset)
{
    CArchiveGuard *archive = BGS_OpenArchiveLZ(dir, name);
    void *buf = Heap_AllocWithAlignment(0x40, -4);
    if (charName == NULL) {
        charName = name;
    }
    BGS_LoadCharByName("BGS", bg, charName, charOffset, 0, 0);
    if (plttName != NULL) {
        name = plttName;
    }
    BGS_LoadPlttByName("BGS", bg, name, plttOffset, 0, 0);
    delete archive;
    Heap_Free(buf);
    return 0;
}

void *BGS_LoadCharByName(const char *arc, int bg, const char *name, u32 offset, int mode, u32 arg5)
{
    char *path = (char *)Heap_AllocWithAlignment(0x40, -4);
    OS_SPrintf(path, "BGS:%s.NCGR", name);
    void *result = BGS_LoadCharFile(path, bg, arg5, offset, mode);
    Heap_Free(path);
    return result;
}

void *BGS_LoadCharFile(const char *path, int bg, u32 arg2, u32 offset, int mode)
{
    void *result = NULL;
    CBGNCGRFile *file = new CBGNCGRFile(path, 1, arg2, CGame::GetInstance()->unk_14A8);
    NNSG2dCharacterData *chr = file->unk_B8;
    u32 size = chr->szByte;
    void *data = chr->pRawData;
    DC_FlushRange(data, size);
    gBGLoadedSize = 0;
    if (mode != 0) {
        if (mode == 1) {
            result = Heap_Alloc(size);
        } else {
            result = (void *)mode;
        }
        MI_CpuCopy8(data, result, size);
        gBGLoadedSize = size;
        DC_FlushRange(result, size);
    } else {
        BG_LoadChar(bg, data, size, offset);
    }
    delete file;
    return result;
}

void BG_LoadChar(int bg, void *data, u32 size, u32 offset)
{
    if (offset != 0) {
        if (!BG_Is256Color(bg)) {
            offset <<= 5;
        } else {
            offset <<= 6;
        }
    }
    BG_LoadCharRaw(bg, data, size, offset);
}

void BG_LoadCharRaw(int bg, void *data, u32 size, u32 offset)
{
    DC_FlushRange((u8 *)data + offset, size);
    switch (bg) {
    case 0:
        GX_LoadBG0Char(data, offset, size);
        break;
    case 1:
        GX_LoadBG1Char(data, offset, size);
        break;
    case 2:
        GX_LoadBG2Char(data, offset, size);
        break;
    case 3:
        GX_LoadBG3Char(data, offset, size);
        break;
    case 4:
        GXS_LoadBG0Char(data, offset, size);
        break;
    case 5:
        GXS_LoadBG1Char(data, offset, size);
        break;
    case 6:
        GXS_LoadBG2Char(data, offset, size);
        break;
    case 7:
        GXS_LoadBG3Char(data, offset, size);
        break;
    }
}

BOOL BG_Is256Color(int bg)
{
    BOOL result = FALSE;
    GXBg01Control bg01;
    GXBg23ControlText bg23;
    GXSDispCnt dispSub;
    // cases 2 and 3 share `disp` (declared in case 2's scope): case 3's copy is a split temp in the original frame
    switch (bg) {
    case 0:
        bg01 = G2_GetBG0Control();
        result = bg01.colorMode;
        break;
    case 1:
        bg01 = G2_GetBG1Control();
        result = bg01.colorMode;
        break;
    case 2:
#ifdef PC_PORT // g++ rejects the case 3 jump across an initialization
        GXDispCnt disp;
        disp = GX_GetDispCnt();
#else
        GXDispCnt disp = GX_GetDispCnt();
#endif
        switch (disp.bgMode) {
        case GX_BGMODE_2:
        case GX_BGMODE_4:
        case GX_BGMODE_5:
            result = TRUE;
            break;
        case GX_BGMODE_0:
        case GX_BGMODE_1:
        case GX_BGMODE_3:
            bg23 = G2_GetBG2ControlText();
            result = bg23.colorMode;
            break;
        }
        break;
    case 3:
        disp = GX_GetDispCnt();
        switch (disp.bgMode) {
        case GX_BGMODE_1:
        case GX_BGMODE_2:
        case GX_BGMODE_3:
        case GX_BGMODE_4:
        case GX_BGMODE_5:
            // BUG: reads BG2's control
            bg23 = G2_GetBG2ControlText();
            result = bg23.colorMode;
            break;
        }
        break;
    case 4:
        bg01 = G2S_GetBG0Control();
        result = bg01.colorMode;
        break;
    case 5:
        bg01 = G2S_GetBG1Control();
        result = bg01.colorMode;
        break;
    case 6: {
        dispSub = GXS_GetDispCnt();
        switch (dispSub.bgMode) {
        case GX_BGMODE_2:
        case GX_BGMODE_4:
        case GX_BGMODE_5:
            result = TRUE;
            break;
        case GX_BGMODE_0:
        case GX_BGMODE_1:
        case GX_BGMODE_3:
            bg23 = G2S_GetBG2ControlText();
            result = bg23.colorMode;
            break;
        }
        break;
    }
    case 7: {
        GXSDispCnt dispSub7 = GXS_GetDispCnt();
        switch (dispSub7.bgMode) {
        case GX_BGMODE_1:
        case GX_BGMODE_2:
        case GX_BGMODE_3:
        case GX_BGMODE_4:
        case GX_BGMODE_5:
            bg23 = G2S_GetBG3ControlText();
            result = bg23.colorMode;
            break;
        }
        break;
    }
    }
    return result;
}

void *BGS_LoadPlttByName(const char *arc, int bg, const char *name, u32 offset, int mode, u32 arg5)
{
    char *path = (char *)Heap_AllocWithAlignment(0x40, -4);
    OS_SPrintf(path, "BGS:%s.NCLR", name);
    void *result = BGS_LoadPlttFile(path, bg, arg5, offset, mode);
    Heap_Free(path);
    return result;
}

void *BGS_LoadPlttFile(const char *path, int bg, u32 arg2, u32 offset, int mode)
{
    void *result = NULL;
    CNCLRFile *file = new CNCLRFile(path, 1, arg2, CGame::GetInstance()->unk_14A8);
    NNSG2dPaletteData *pltt = file->unk_B8;
    u32 size = pltt->szByte;
    void *data = pltt->pRawData;
    DC_FlushRange(data, size);
    gBGLoadedSize = 0;
    if (mode != 0) {
        if (mode == 1) {
            result = Heap_Alloc(size);
        } else {
            result = (void *)mode;
        }
        MI_CpuCopy8(data, result, size);
        gBGLoadedSize = size;
        DC_FlushRange(result, size);
    } else {
        BG_LoadPltt(bg, data, size, offset, FALSE);
    }
    delete file;
    return result;
}

void BG_LoadPltt(int bg, void *data, u32 size, u32 offset, BOOL ext)
{
    u32 dst = ext ? offset << 9 : offset << 5;
    u32 slot = 0;
    DC_FlushRange(data, size);
    switch (bg) {
    case 3:
        slot += 0x2000;
    case 2:
        slot += 0x2000;
    case 1:
        slot += 0x2000;
    case 0:
        if (ext) {
            GX_BeginLoadBGExtPltt();
            GX_LoadBGExtPltt(data, dst + slot, size);
            GX_EndLoadBGExtPltt();
        } else {
            GX_LoadBGPltt(data, dst, size);
        }
        break;
    case 7:
        slot += 0x2000;
    case 6:
        slot += 0x2000;
    case 5:
        slot += 0x2000;
    case 4:
        if (ext) {
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(data, dst + slot, size);
            GXS_EndLoadBGExtPltt();
        } else {
            GXS_LoadBGPltt(data, dst, size);
        }
        break;
    }
}

void *BGS_LoadScr(const char *dir, const char *name, int bg, const char *scrName, u32 arg4, u32 arg5, int mode, u32 arg7)
{
    CArchiveGuard *archive = BGS_OpenArchiveLZ(dir, name);
    void *buf = Heap_AllocWithAlignment(0x40, -4);
    if (scrName != NULL) {
        name = scrName;
    }
    void *result = BGS_LoadScrByName("BGS", bg, name, arg4, arg5, mode, 0, arg7);
    delete archive;
    Heap_Free(buf);
    return result;
}

void *BGS_LoadScrByName(const char *arc, int bg, const char *name, u32 arg3, u32 arg4, int mode, u32 arg6, u32 offset)
{
    char *path = (char *)Heap_AllocWithAlignment(0x40, -4);
    OS_SPrintf(path, "%s:%s.NSCR", arc, name);
    void *result = BGS_LoadScrFile(path, bg, arg6, arg3, arg4, mode, offset);
    Heap_Free(path);
    return result;
}

// screen entry offset: palette number in bits 12..15, character number in bits 0..9
#define TILE_ADD ((charAdd & 0x3FF) + (plttNo << 12))

void *BGS_LoadScrFile(const char *path, int bg, u32 arg2, u32 plttNo, u32 charAdd, int mode, u32 offset)
{
    CNSCRFile *file;
    NNSG2dScreenData *scr;
    void *result = NULL;
    u32 size;
    u64 add64;
    int i;
    int n;
    u16 *p;
    file = new CNSCRFile(path, 1, arg2, CGame::GetInstance()->unk_14A8);
    scr = file->unk_B8;
    if (scr == NULL) {
        delete file;
        return NULL;
    }
    size = scr->szByte;
    sScreenWidth = scr->screenWidth;
    sScreenHeight = file->unk_B8->screenHeight;
    if ((plttNo != 0) | (charAdd != 0)) {
        // TILE_ADD is written out at every use (no local): the original keeps it in a CSE temp
        add64 = ((u64)TILE_ADD << 48) | ((u64)TILE_ADD << 32) | ((u64)TILE_ADD << 16) | TILE_ADD;
        p = (u16 *)scr->rawData;
        n = size >> 3;
        for (i = 0; i < n; i++) {
#ifdef PC_PORT
            *(u64 *)p += add64;
            p += sizeof(u64) / sizeof(u16);
#else
            *((u64 *)p)++ += add64; // mwcc accepts the cast lvalue
#endif
        }
        u16 add16 = (u16)TILE_ADD;
        u32 add32 = add16 | (add16 << 16);
        u16 add = add32;
        n = (size & 7) >> 1;
        for (i = 0; i < n; i++) {
            *p++ += add;
        }
    }
    DC_FlushRange(scr->rawData, size);
    gBGLoadedSize = 0;
    if (mode != 0) {
        if (mode == 1) {
            result = Heap_Alloc(size);
        } else {
            result = (void *)mode;
        }
        MI_CpuCopy8(scr->rawData, result, size);
        gBGLoadedSize = size;
        DC_FlushRange(result, size);
    } else {
        BG_LoadScr(bg, scr->rawData, size, offset);
    }
    delete file;
    return result;
}

#undef TILE_ADD

void BG_LoadScr(int bg, void *data, u32 size, u32 offset)
{
    DC_FlushRange(data, size);
    switch (bg) {
    case 0:
        GX_LoadBG0Scr(data, offset, size);
        break;
    case 1:
        GX_LoadBG1Scr(data, offset, size);
        break;
    case 2:
        GX_LoadBG2Scr(data, offset, size);
        break;
    case 3:
        GX_LoadBG3Scr(data, offset, size);
        break;
    case 4:
        GXS_LoadBG0Scr(data, offset, size);
        break;
    case 5:
        GXS_LoadBG1Scr(data, offset, size);
        break;
    case 6:
        GXS_LoadBG2Scr(data, offset, size);
        break;
    case 7:
        GXS_LoadBG3Scr(data, offset, size);
        break;
    }
}
