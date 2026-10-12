#ifndef POKERANGER2_BATTLE_CBATTLEDISK_HPP
#define POKERANGER2_BATTLE_CBATTLEDISK_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CPrimitiveSPHERE.hpp"

class CBattlePowerSave;
class CDiskCursor;
class CLineEffect;
class CSoftwareSprite;
class UnkClass_0201AAE0;
class UnkClass_02127CD8;
class UnkClass_02127E14;
class UnkClass_02128860;
class UnkClass_02128A60;
class UnkClass_02128B24;
class UnkClass_0212306C;
class UnkClass_0212D2C4;
class UnkClass_02136AD4;

// Defined in ov1
class CBattleDisk : public CActor {
public:
    CBattleDisk(UnkClass_02136AD4 *particles);
    virtual ~CBattleDisk();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    void ov1_0212BAD0();
    void ov1_0212BC54();
    void ov1_0212C00C(Camera2D *camera);
    void ov1_0212C02C(Camera2D *camera);
    void ov1_0212C0B8(Camera2D *camera);
    void ov1_0212C144(Camera2D *camera);
    void ov1_0212C1C4(Point2D pos);
    int ov1_0212C33C(u16 damage, u8 type);
    void ov1_0212C3B4();
    void ov1_0212C414();
    BOOL ov1_0212C4B8();
    BOOL ov1_0212C4CC();
    u8 ov1_0212C4E4();
    void ov1_0212C4EC(u8 enabled);
    void ov1_0212C4F4(BOOL arg0);
    void ov1_0212C514(BOOL active);
    BOOL ov1_0212C5C0();
    BOOL ov1_0212C5D8();
    void ov1_0212C5F0(BOOL arg0);
    void ov1_0212C610(fx32 x, fx32 y);
    Point2D ov1_0212C670(int index);
    Point2D ov1_0212C690(int index);
    int ov1_0212C6B0(u16 index);
    int ov1_0212C6C0();
    void ov1_0212C6D0(u16 color);
    void ov1_0212C7E8(Point2D pos, int count, fx32 arg2, u16 color);
    void ov1_0212C990(Point2D pos, int count, fx32 arg2, u16 color);
    void ov1_0212CBA0(Point2D pos, int count, fx32 arg2);
    int ov1_0212CD6C(u16 level, int assistType, u8 type);
    void ov1_0212CF0C(fx32 x, fx32 y, int arg2);
    void ov1_0212CF1C();
    int ov1_0212D0D4(int z);
    int ov1_0212D124(int z);
    void ov1_0212D148(Point2D pos, int count);

    inline void ShowHitEffect(Point2D pos, int mode)
    {
        ov1_0212CF0C(pos.x, pos.y, mode);
    }

    inline BOOL IsUnk194Flag80()
    {
        return (unk_194 & 0x80) != 0;
    }

public:
    u8 unk_184;
    u8 unk_185;
    u8 unk_186;
    u8 unk_187;
    u8 unk_188;
    u32 unk_18C;
    u32 unk_190;
    u16 unk_194;
    u16 unk_196;
    u16 unk_198;
    u16 unk_19A;
    u8 unk_19C;
    u8 unk_19D;
    u16 unk_19E;
    u8 unk_1A0[0x4];
    u8 unk_1A4[0x13];
    UnkClass_0212306C *unk_1B8;
    UnkClass_02128860 *unk_1BC;
    CBattlePowerSave *unk_1C0;
    CPrimitiveSPHERE unk_1C4;
    CPrimitiveRECT unk_1E8;
    CSoftwareSprite *unk_228;
    UnkClass_0201AAE0 *unk_22C;
    u16 unk_230;
    CSoftwareSprite *unk_234;
    UnkClass_0201AAE0 *unk_238[2];
    u16 unk_240;
    u16 unk_242[3];
    CDiskCursor *unk_248;
    CLineEffect *unk_24C;
    UnkClass_02136AD4 *unk_250;
    UnkClass_02127E14 *unk_254;
    UnkClass_02127CD8 *unk_258;
    UnkClass_02128B24 *unk_25C;
    UnkClass_02128A60 *unk_260;
    UnkClass_0212D2C4 *unk_264;
};

STATIC_SIZE_ASSERT(CBattleDisk, 0x268);

#endif // POKERANGER2_BATTLE_CBATTLEDISK_HPP
