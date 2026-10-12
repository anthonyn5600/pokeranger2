#ifndef POKERANGER2_UNKCLASS_0200ECD0_HPP
#define POKERANGER2_UNKCLASS_0200ECD0_HPP

#include <nitro.h>
#include <nnsys.h>

#include "UnkClass_02008788.hpp"
#include "UnkClass_0200E960.hpp"
#include "common.hpp"
#include "file/CNCERFile.hpp"
#include "file/CNCGRFile.hpp"
#include "file/CNCLRFile.hpp"

class UnkClass_0200ECD0 {
public:
    UnkClass_0200ECD0(GXOamAttr *oam, u32 arg1, BOOL subScreen, int count);
    ~UnkClass_0200ECD0();

    u32 sub_0200EE14(const char *dir, const char *name, u32 charOffset, u32 paletteSlot);
    u32 sub_0200F168(const char *dir, const char *name, u32 charOffset, u32 paletteSlot);
    u32 sub_0200F358(u32 charOffset, u32 paletteSlot);
    u32 sub_0200F398();
    u32 sub_0200F3EC();
    void sub_0200F4A8();
    UnkClass_0200E960 *sub_0200F4FC(int anim, int x, int y, int priority);
    BOOL sub_0200F628(int idx, int anim);
    void sub_0200F64C();
    void sub_0200F6C4();
    void sub_0200F71C();

    inline const NNSG2dCellData *GetCell(u16 id)
    {
        return &unk_34->unk_B8->pCellDataArrayHead[unk_38->sub_02008828(id)];
    }

    inline const NNSG2dCellData *GetCellData(int cellIdx)
    {
        return &unk_34->unk_B8->pCellDataArrayHead[cellIdx];
    }

public:
    u32 unk_00;
    GXOamAttr *unk_04;
    u16 *unk_08;
    UnkClass_0200E960 *unk_0C;
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
    UnkClass_02008788 *unk_38;
    CNCGRFile *unk_3C;
    CNCLRFile *unk_40;
};

STATIC_SIZE_ASSERT(UnkClass_0200ECD0, 0x44);

#endif // POKERANGER2_UNKCLASS_0200ECD0_HPP
