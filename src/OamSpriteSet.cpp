#include "OamSpriteSet.hpp"

#include "file/CArchiveGuard.hpp"

extern "C" {
extern char s_COM_0208aafc;
extern char s_s_s_LZ_bin_0208ab00;
extern char s_s_s_NCGR_0208ab10;
extern char s_s_s_NCLR_0208ab1c;
extern char s_s_s_NCER_0208ab28;
extern char s_s_s_cac_0208ab34;
}

OamSpriteSet::OamSpriteSet(GXOamAttr *oam, u32 arg1, BOOL subScreen, int count)
{
    unk_2C = subScreen;
    unk_00 = arg1;
    unk_04 = oam;
    unk_30 = 0;
    unk_10 = count;
    unk_08 = new u16[unk_10];
    unk_0C = new OamSprite[unk_10];
}

OamSpriteSet::~OamSpriteSet()
{
    if (unk_08 != NULL) {
        delete[] unk_08;
        unk_08 = NULL;
    }
    if (unk_0C != NULL) {
        delete[] unk_0C;
        unk_0C = NULL;
    }
    if (unk_34 != NULL) {
        delete unk_34;
        unk_34 = NULL;
    }
    if (unk_38 != NULL) {
        delete unk_38;
        unk_38 = NULL;
    }
    if (unk_3C != NULL) {
        delete unk_3C;
        unk_3C = NULL;
    }
    if (unk_40 != NULL) {
        delete unk_40;
        unk_40 = NULL;
    }
}

u32 OamSpriteSet::Load(const char *dir, const char *name, u32 charOffset, u32 paletteSlot)
{
    char cacPath[0x60];
    char ncerPath[0x60];
    char nclrPath[0x60];
    char ncgrPath[0x60];
    char arcPath[0x60];
    char arcName[0x60];

    unk_20 = charOffset;
    unk_1C = paletteSlot;
    if (unk_2C == 0) {
        unk_14 = HW_OBJ_VRAM + charOffset * 0x20;
        unk_18 = HW_OBJ_PLTT + paletteSlot * 0x20;
    } else {
        unk_14 = HW_DB_OBJ_VRAM + charOffset * 0x20;
        unk_18 = HW_DB_OBJ_PLTT + paletteSlot * 0x20;
    }

    OS_SPrintf(arcName, &s_COM_0208aafc);
    OS_SPrintf(arcPath, &s_s_s_LZ_bin_0208ab00, dir, name);
    OS_SPrintf(ncgrPath, &s_s_s_NCGR_0208ab10, arcName, name);
    OS_SPrintf(nclrPath, &s_s_s_NCLR_0208ab1c, arcName, name);
    OS_SPrintf(ncerPath, &s_s_s_NCER_0208ab28, arcName, name);
    OS_SPrintf(cacPath, &s_s_s_cac_0208ab34, arcName, name);

    CArchiveGuard *archive = new CArchiveGuard(arcName, arcPath, 1, 1, unk_00, NULL, 0);

    unk_3C = new CNCGRFile(ncgrPath, 1, 0, 0);
    u32 charSize = unk_3C->unk_B8->szByte;

    int vramSize = 0;
    if (unk_2C == 1) {
        switch (GX_GetBankForSubOBJ()) {
        case GX_VRAM_SUB_OBJ_NONE:
            break;
        case GX_VRAM_SUB_OBJ_16_I:
            vramSize = 0x4000;
            break;
        case GX_VRAM_SUB_OBJ_128_D:
            vramSize = 0x20000;
            break;
        }
    } else {
        switch (GX_GetBankForOBJ()) {
        case GX_VRAM_OBJ_NONE:
            break;
        case GX_VRAM_OBJ_16_F:
        case GX_VRAM_OBJ_16_G:
            vramSize = 0x4000;
            break;
        case GX_VRAM_OBJ_32_FG:
            vramSize = 0x8000;
            break;
        case GX_VRAM_OBJ_64_E:
            vramSize = 0x10000;
            break;
        case GX_VRAM_OBJ_80_EF:
        case GX_VRAM_OBJ_80_EG:
            vramSize = 0x14000;
            break;
        case GX_VRAM_OBJ_96_EFG:
            vramSize = 0x18000;
            break;
        case GX_VRAM_OBJ_128_A:
        case GX_VRAM_OBJ_128_B:
            vramSize = 0x20000;
            break;
        case GX_VRAM_OBJ_256_AB:
            vramSize = 0x40000;
            break;
        }
    }

    if (unk_2C == 1 && (int)(charSize + charOffset * 0x20) > vramSize) {
        OS_Terminate();
    }

    MI_CpuCopyFast(unk_3C->unk_B8->pRawData, (void *)unk_14, charSize);
    unk_28 = (int)charSize / 32;
    if (unk_3C != NULL) {
        delete unk_3C;
        unk_3C = NULL;
    }

    unk_40 = new CNCLRFile(nclrPath, 1, 0, 0);
    MI_CpuCopyFast(unk_40->unk_B8->pRawData, (void *)unk_18, unk_40->unk_B8->szByte);
    if (unk_40 != NULL) {
        delete unk_40;
        unk_40 = NULL;
    }

    unk_34 = new CNCERFile(ncerPath, 0, 0, 0);
    unk_38 = new CellAnimController();
    unk_38->Load(cacPath, 0, 0);

    delete archive;

    return charSize;
}

u32 OamSpriteSet::LoadFiles(const char *dir, const char *name, u32 charOffset, u32 paletteSlot)
{
    char cacPath[0x60];
    char ncerPath[0x60];
    char nclrPath[0x60];
    char ncgrPath[0x60];
    char arcPath[0x60];
    char arcName[0x60];

    unk_20 = charOffset;
    unk_1C = paletteSlot;
    if (unk_2C == 0) {
        unk_14 = HW_OBJ_VRAM + charOffset * 0x20;
        unk_18 = HW_OBJ_PLTT + paletteSlot * 0x20;
    } else {
        unk_14 = HW_DB_OBJ_VRAM + charOffset * 0x20;
        unk_18 = HW_DB_OBJ_PLTT + paletteSlot * 0x20;
    }

    OS_SPrintf(arcName, &s_COM_0208aafc);
    OS_SPrintf(arcPath, &s_s_s_LZ_bin_0208ab00, dir, name);
    OS_SPrintf(ncgrPath, &s_s_s_NCGR_0208ab10, arcName, name);
    OS_SPrintf(nclrPath, &s_s_s_NCLR_0208ab1c, arcName, name);
    OS_SPrintf(ncerPath, &s_s_s_NCER_0208ab28, arcName, name);
    OS_SPrintf(cacPath, &s_s_s_cac_0208ab34, arcName, name);

    CArchiveGuard *archive = new CArchiveGuard(arcName, arcPath, 1, 1, unk_00, NULL, 0);

    unk_3C = new CNCGRFile(ncgrPath, 0, 0, 0);
    u32 charSize = unk_3C->unk_B8->szByte;
    unk_28 = (int)charSize / 32;
    unk_40 = new CNCLRFile(nclrPath, 0, 0, 0);
    unk_34 = new CNCERFile(ncerPath, 0, 0, 0);
    unk_38 = new CellAnimController();
    unk_38->Load(cacPath, 0, 0);

    delete archive;

    return charSize;
}

u32 OamSpriteSet::SetVramOffsets(u32 charOffset, u32 paletteSlot)
{
    if (unk_2C == 0) {
        unk_14 = HW_OBJ_VRAM + charOffset * 0x20;
        unk_18 = HW_OBJ_PLTT + paletteSlot * 0x20;
    } else {
        unk_14 = HW_DB_OBJ_VRAM + charOffset * 0x20;
        unk_18 = HW_DB_OBJ_PLTT + paletteSlot * 0x20;
    }
    return CopyToVram();
}

u32 OamSpriteSet::CopyToVram()
{
    u32 charSize = unk_3C->unk_B8->szByte;
    MI_CpuCopyFast(unk_3C->unk_B8->pRawData, (void *)unk_14, charSize);
    unk_28 = (int)charSize / 32;
    MI_CpuCopyFast(unk_40->unk_B8->pRawData, (void *)unk_18, unk_40->unk_B8->szByte);
    return charSize;
}

u32 OamSpriteSet::TransferToVram()
{
    u32 size = unk_3C->unk_B8->szByte;
    if (unk_2C == 0) {
        NNS_GfdRegisterNewVramTransferTask(NNS_GFD_DST_2D_OBJ_CHAR_MAIN, unk_14 - HW_OBJ_VRAM, unk_3C->unk_B8->pRawData, size);
    } else {
        NNS_GfdRegisterNewVramTransferTask(NNS_GFD_DST_2D_OBJ_CHAR_SUB, unk_14 - HW_DB_OBJ_VRAM, unk_3C->unk_B8->pRawData, size);
    }
    unk_28 = (int)size / 32;

    size = unk_40->unk_B8->szByte;
    if (unk_2C == 0) {
        NNS_GfdRegisterNewVramTransferTask(NNS_GFD_DST_2D_OBJ_PLTT_MAIN, unk_18 - HW_OBJ_PLTT, unk_40->unk_B8->pRawData, size);
    } else {
        NNS_GfdRegisterNewVramTransferTask(NNS_GFD_DST_2D_OBJ_PLTT_SUB, unk_18 - HW_DB_OBJ_PLTT, unk_40->unk_B8->pRawData, size);
    }
    return size;
}

void OamSpriteSet::ReleaseFiles()
{
    if (unk_3C != NULL) {
        delete unk_3C;
        unk_3C = NULL;
    }
    if (unk_40 != NULL) {
        delete unk_40;
        unk_40 = NULL;
    }
}

OamSprite *OamSpriteSet::AddSprite(int anim, int x, int y, int priority)
{
    const NNSG2dCellData *cellData;

    unk_24 = unk_38->GetCount();
    if (unk_24 >= unk_10) {
        OS_Terminate();
    }

    unk_08[unk_24] = unk_38->Create(0, 0);
    unk_38->SetAnim(unk_08[unk_24], anim);
    u16 cell = unk_38->GetCell(unk_08[unk_24]);

    for (int i = 0; i < unk_10; i++) {
        if (unk_0C[i].unk_14 == 0) {
            // Fake match: the self-assignment stops mwcc from folding cellData into the call,
            // so the cell pointer is computed before the other arguments, like in the original.
            cellData = (cellData = &unk_34->unk_B8->pCellDataArrayHead[cell]);
            unk_30 += unk_0C[i].Setup(cellData, x, y, unk_1C, unk_20, priority);
            return &unk_0C[i];
        }
    }

    OS_Terminate();
    return NULL;
}

BOOL OamSpriteSet::SetAnim(int idx, int anim)
{
    return unk_38->SetAnim(unk_08[idx], anim);
}

void OamSpriteSet::Update()
{
    unk_24 = unk_38->GetCount();
    unk_38->UpdateAll();
    for (int i = 0; i < unk_24; i++) {
        unk_0C[i].SetCellData(GetCell(unk_08[i]));
    }
}

void OamSpriteSet::RemoveAll()
{
    for (int i = 0; i < unk_10; i++) {
        unk_0C[i].Init((u32)&unk_04[i]);
    }
    unk_38->RemoveAll();
}

void OamSpriteSet::WriteOam()
{
    int nameShift = 0;
    int charShift = 0;
    GXOamAttr *dst = unk_04;

    if (unk_2C == 1) {
        switch (GXS_GetOBJVRamModeChar()) {
        case GX_OBJVRAMMODE_CHAR_2D:
        case GX_OBJVRAMMODE_CHAR_1D_32K:
            nameShift = 0;
            break;
        case GX_OBJVRAMMODE_CHAR_1D_64K:
            nameShift = 1;
            break;
        case GX_OBJVRAMMODE_CHAR_1D_128K:
            nameShift = 2;
            break;
        case GX_OBJVRAMMODE_CHAR_1D_256K:
            nameShift = 3;
            break;
        }
    } else {
        switch (GX_GetOBJVRamModeChar()) {
        case GX_OBJVRAMMODE_CHAR_2D:
        case GX_OBJVRAMMODE_CHAR_1D_32K:
            nameShift = 0;
            break;
        case GX_OBJVRAMMODE_CHAR_1D_64K:
            nameShift = 1;
            break;
        case GX_OBJVRAMMODE_CHAR_1D_128K:
            nameShift = 2;
            break;
        case GX_OBJVRAMMODE_CHAR_1D_256K:
            nameShift = 3;
            break;
        }
    }

    switch (unk_34->unk_B8->mappingMode) {
    case 0:
    case 4:
        charShift = 0;
        break;
    case 1:
        charShift = 1;
        break;
    case 2:
        charShift = 2;
        break;
    case 3:
        charShift = 3;
        break;
    }

    for (int i = 0; i < unk_10; i++) {
        if (unk_0C[i].unk_14 != 0) {
            dst = unk_0C[i].Write(dst, nameShift, charShift);
        }
    }
}
