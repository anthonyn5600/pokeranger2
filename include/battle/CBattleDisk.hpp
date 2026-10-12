#ifndef POKERANGER2_BATTLE_CBATTLEDISK_HPP
#define POKERANGER2_BATTLE_CBATTLEDISK_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "common.hpp"

class CBattlePowerSave;
class UnkClass_02127E14;
class UnkClass_02128860;
class UnkClass_0212306C;
class UnkClass_02136AD4;

// Defined in ov1
class CBattleDisk : public CActor {
public:
    CBattleDisk(UnkClass_02136AD4 *arg0);
    virtual ~CBattleDisk();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    void ov1_0212C00C(Camera2D *camera);
    void ov1_0212C1C4(Point2D pos);
    int ov1_0212C33C(u16 arg0, u8 arg1);
    BOOL ov1_0212C4B8();
    BOOL ov1_0212C4CC();
    BOOL ov1_0212C4E4();
    void ov1_0212C514(int arg0);
    BOOL ov1_0212C5C0();
    BOOL ov1_0212C5D8();
    void ov1_0212C5F0(BOOL arg0);
    void ov1_0212C610(fx32 x, fx32 y);
    Point2D ov1_0212C670(int index);
    Point2D ov1_0212C690(int index);
    int ov1_0212C6B0(u16 index);
    int ov1_0212C6C0();
    void ov1_0212C6D0(int arg0);
    void ov1_0212C7E8(Point2D pos, int arg1, int arg2, int arg3);
    void ov1_0212C990(Point2D pos, int arg1, int arg2, int arg3);
    void ov1_0212CBA0(Point2D pos, int arg1, int arg2);
    int ov1_0212CD6C(u16 arg0, int assistType, u8 type);
    void ov1_0212CF0C(fx32 x, fx32 y, int arg2);
    int ov1_0212D0D4(int z);
    int ov1_0212D124(int z);

    inline void ShowHitEffect(Point2D pos, int mode)
    {
        ov1_0212CF0C(pos.x, pos.y, mode);
    }

    inline BOOL IsUnk194Flag80()
    {
        return (unk_194 & 0x80) != 0;
    }

public:
    u8 unk_184[0x3];
    u8 unk_187;
    u8 unk_188[0x4];
    u32 unk_18C;
    u32 unk_190;
    u16 unk_194;
    u8 unk_196[0x6];
    u8 unk_19C;
    u8 unk_19D;
    u16 unk_19E;
    u8 unk_1A0[0x18];
    UnkClass_0212306C *unk_1B8;
    u8 unk_1BC[0x4];
    CBattlePowerSave *unk_1C0;
    u8 unk_1C4[0x90];
    UnkClass_02127E14 *unk_254;
    u8 unk_258[0x4];
    UnkClass_02128860 *unk_25C;
    u8 unk_260[0x8];
};

STATIC_SIZE_ASSERT(CBattleDisk, 0x268);

#endif // POKERANGER2_BATTLE_CBATTLEDISK_HPP
