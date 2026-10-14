#ifndef POKERANGER2_OAMSPRITESET_HPP
#define POKERANGER2_OAMSPRITESET_HPP

#include <nitro.h>
#include <nnsys.h>

#include "CellAnimController.hpp"
#include "OamSprite.hpp"
#include "common.hpp"
#include "file/CNCERFile.hpp"
#include "file/CNCGRFile.hpp"
#include "file/CNCLRFile.hpp"

class OamSpriteSet {
public:
    OamSpriteSet(GXOamAttr *oam, u32 arg1, BOOL subScreen, int count);
    ~OamSpriteSet();

    u32 Load(const char *dir, const char *name, u32 charOffset, u32 paletteSlot);
    u32 LoadFiles(const char *dir, const char *name, u32 charOffset, u32 paletteSlot);
    u32 SetVramOffsets(u32 charOffset, u32 paletteSlot);
    u32 CopyToVram();
    u32 TransferToVram();
    void ReleaseFiles();
    OamSprite *AddSprite(int anim, int x, int y, int priority);
    BOOL SetAnim(int idx, int anim);
    void Update();
    void RemoveAll();
    void WriteOam();

    inline const NNSG2dCellData *GetCell(u16 id)
    {
        return &unk_34->unk_B8->pCellDataArrayHead[unk_38->GetCell(id)];
    }

    inline const NNSG2dCellData *GetCellData(int cellIdx)
    {
        return &unk_34->unk_B8->pCellDataArrayHead[cellIdx];
    }

public:
    u32 unk_00;
    GXOamAttr *unk_04;
    u16 *unk_08;
    OamSprite *unk_0C;
    int unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    int unk_24;
    int unk_28;
    BOOL unk_2C;
    int unk_30;
    CNCERFile *unk_34;
    CellAnimController *unk_38;
    CNCGRFile *unk_3C;
    CNCLRFile *unk_40;
};

STATIC_SIZE_ASSERT(OamSpriteSet, 0x44);

#endif // POKERANGER2_OAMSPRITESET_HPP
