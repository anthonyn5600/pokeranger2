#ifndef POKERANGER2_FIELD_CFIELDPOKEMOVE_HPP
#define POKERANGER2_FIELD_CFIELDPOKEMOVE_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"

class CFieldActor;
class CFieldPlayer;

// Enemy record from the table behind MAIN_BSS_0210CA6C (FieldData_GetEnemy).
struct FieldEnemyData {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    fx32 unk_0C;
    fx32 unk_10;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    fx32 unk_1C;
    fx32 unk_20;
    u8 unk_24;
    u8 unk_25;
    u8 unk_26;
    u8 unk_27;
    u16 unk_28;
    u16 unk_2A;
    u16 unk_2C;
    u16 unk_2E;
    u16 unk_30;
    u16 unk_32;
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 unk_37;
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u8 unk_3C;
    s8 unk_3D;
    s8 unk_3E;
    u8 unk_3F;
};

// 3D position/velocity (z = height above ground); its operators are emitted out of line after their first user.
struct PokeMoveVec : public Point2D {
    fx32 z;

    PokeMoveVec()
    {
    }

    PokeMoveVec(fx32 x_, fx32 y_, fx32 z_)
    {
        x = x_;
        y = y_;
        z = z_;
    }

    PokeMoveVec operator=(const PokeMoveVec &other);
    PokeMoveVec operator+(const PokeMoveVec &other) const;
};

// FieldPokeMove.cpp (ov0): scripted movement of a Pokémon, embedded in each CFieldEnemy.
class CFieldPokeMove {
public:
    CFieldPokeMove();
    virtual ~CFieldPokeMove();

    void ov0_02152AD0(CFieldActor *owner, Point2D target, int arg);
    BOOL ov0_02152B04();
    int ov0_02153040();
    int ov0_02153538();
    BOOL ov0_02153B60(int step);
    int ov0_02153D78();
    int ov0_02154210();
    int ov0_021545EC();
    int ov0_02154810();
    int ov0_02154A84();
    int ov0_02154C30();
    int ov0_02154C58();
    int ov0_02155558();
    int ov0_02155580();
    int ov0_02155588();
    int ov0_021558F4();
    int ov0_021559F0();
    int ov0_021559F8();
    int ov0_02155A90();
    int ov0_02155B88();
    int ov0_02155C20();
    int ov0_02155D38();
    int ov0_02155EA0();
    int ov0_02156194();
    int ov0_02156290();
    int ov0_0215675C();
    int ov0_02156898();
    void ov0_02156A8C();
    int ov0_02156B30(PokeMoveVec *vel, fx32 speed, int mode);
    int ov0_02156BC0(PokeMoveVec *vel, fx32 speed);
    int ov0_02156BE4(PokeMoveVec *vel, fx32 speed);
    int ov0_02156E68(PokeMoveVec *vel, fx32 speed);
    int ov0_021572F4(PokeMoveVec *vel, fx32 speed);
    int ov0_02157764(PokeMoveVec *vel, fx32 speed);
    int ov0_02157A70(PokeMoveVec *vel, fx32 speed);
    int ov0_02157CF4(PokeMoveVec *vel, fx32 speed);
    BOOL ov0_02157F0C(Point2D *dir, Point2D *target, u16 maxAngle);
    int ov0_021580F8(int anim);
    void ov0_0215826C();
    void ov0_02158294(int group, int index);
    int ov0_021582B4(int type, int arg);
    BOOL ov0_02158420();
    BOOL ov0_02158894(Point2D dir, fx32 scale);
    BOOL ov0_02158928(const Point2D &pos, fx32 radius, u32 flags);
    void ov0_02158B5C(int arg);
    void ov0_02158F38();
    int ov0_0215900C();
    void ov0_0215674C(int sequence);
    int ov0_0215844C(void *buf, void *end);
    BOOL ov0_021585B8(void *data);
    void ov0_02158954();
    int ov0_02158070();
    fx32 ov0_0215809C(fx32 x1, fx32 y1, fx32 x2, fx32 y2);
    fx32 ov0_021580D0(fx32 x, fx32 y);
    BOOL ov0_02158B34(fx32 radius);
    BOOL ov0_021582C4(Point2D from, Point2D to, int range, Point2D dir, int angle);
    void ov0_02158988();

    inline Point2D GetPlayerPos();
    inline BOOL IsBlocked(const PointPair2D &move, fx32 radius, u32 flags);

    inline Point2D GetPos()
    {
        return (Point2D) { unk_0C.x, unk_0C.y };
    }

    inline void SetUnk38(Point2D dir)
    {
        unk_38 = dir;
    }

    inline void SetUnk04(Point2D pos)
    {
        unk_04 = pos;
    }

public:
    Point2D unk_04;
    PokeMoveVec unk_0C;
    PokeMoveVec unk_18;
    PokeMoveVec unk_24;
    Point2D unk_30;
    Point2D unk_38;
    int unk_40;
    int unk_44;
    CFieldActor *unk_48;
    u16 unk_4C;
    u16 unk_4E;
    int unk_50;
    u16 unk_54;
    int unk_58;
    int unk_5C;
    u16 unk_60;
    int unk_64;
    int unk_68;
    FieldEnemyData unk_6C;
    CFieldPlayer *unk_AC;
    int unk_B0;
    u32 unk_B4;
    u16 unk_B8;
    int unk_BC;
    int unk_C0;
    int unk_C4;
    int unk_C8;
    int unk_CC;
    int unk_D0;
    u8 unk_D4;
    u16 unk_D6;
    int unk_D8;
};

STATIC_SIZE_ASSERT(CFieldPokeMove, 0xDC);

#include "field/CFieldPlayer.hpp"

inline BOOL CFieldPokeMove::IsBlocked(const PointPair2D &move, fx32 radius, u32 flags)
{
    if (unk_BC == 0) {
        return FALSE;
    }
    return unk_48->CheckSweepCollision(move, radius, flags);
}

inline Point2D CFieldPokeMove::GetPlayerPos()
{
    if (unk_AC != NULL) {
        return unk_AC->GetPos();
    }
    Point2D zero = { 0, 0 };
    return zero;
}

#endif // POKERANGER2_FIELD_CFIELDPOKEMOVE_HPP
