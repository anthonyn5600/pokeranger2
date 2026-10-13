#ifndef POKERANGER2_FIELD_CFIELDENEMY_HPP
#define POKERANGER2_FIELD_CFIELDENEMY_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldPokeMove.hpp"
#include "field/CFieldTargetObjectManage.hpp"

// FieldEnemy.cpp (ov0)
class CFieldEnemy : public CFieldActor {
public:
    CFieldEnemy();
    virtual ~CFieldEnemy();
    virtual void sub_0202D394();
    virtual void sub_0203DA40(CFieldMap *map);
    virtual BOOL sub_0203D578(CFieldMap *map);
    virtual void sub_02032A44(int arg0);

    int ov0_021343B8(int index);
    BOOL ov0_02134D60(int radius);
    void ov0_02134F00();
    void ov0_02134F38();
    void ov0_02134F70();
    void ov0_02134FCC();
    void ov0_021351AC();
    void ov0_0213524C();
    void ov0_02135250();
    CFieldActor *ov0_02135278();
    void ov0_021352E4(int arg1);
    void ov0_021356BC(void *buf, void *end);
    void ov0_021356CC(void *data);
    void ov0_021356EC();

    inline Point2D GetUnk158()
    {
        return unk_158;
    }

    u32 unk_E0;
    int unk_E4;
    u32 unk_E8;
    int unk_EC;
    int unk_F0;
    int unk_F4;
    int unk_F8;
    int unk_FC;
    int unk_100;
    int unk_104;
    int unk_108;
    int unk_10C;
    int unk_110;
    int unk_114;
    int unk_118;
    int unk_11C;
    int unk_120;
    int unk_124;
    int unk_128;
    u16 unk_12C;
    u16 unk_12E;
    u16 unk_130;
    u16 unk_132[3];
    int unk_138;
    int unk_13C;
    u8 unk_140;
    u8 unk_141;
    u8 unk_142;
    u8 unk_143;
    u16 unk_144;
    u16 unk_146;
    int unk_148;
    VecFx32 unk_14C;
    Point2D unk_158;
    int unk_160;
    int unk_164;
    CFieldPokeMove unk_168;
    u8 unk_240[0x4];
    int unk_244;
    u8 unk_248[0x8];
    int unk_250;
    u16 unk_254;
    u16 unk_256;
};

STATIC_SIZE_ASSERT(CFieldEnemy, 0x258);

#endif // POKERANGER2_FIELD_CFIELDENEMY_HPP
