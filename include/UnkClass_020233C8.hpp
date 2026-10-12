#ifndef POKERANGER2_UNKCLASS_020233C8_HPP
#define POKERANGER2_UNKCLASS_020233C8_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;
class Camera2D;
class UnkClass_0200E960;
class UnkClass_0200ECD0;
class UnkClass_0201AD60;
class UnkClass_0202773C;

// Sub-screen 3x3 icon menu: the icons pop in/out with a scale animation over a grid overlay
class UnkClass_02023558 {
public:
    UnkClass_02023558(CGame *game);
    ~UnkClass_02023558();

    void Update();
    void Render();
    void sub_020237E0();
    void Init();
    void sub_020238D8();
    void Release();
    void SetVisible(BOOL visible);
    void sub_02023B54();
    BOOL IsBusy();
    void SetAffineScales(BOOL scaled);
    void UpdateIcon(u16 index);
    void sub_02024068(int popFrames, int bounceFrames, BOOL opening);
    void Draw();
    void sub_02024214();
    BOOL sub_02024380();
    BOOL sub_020243CC();
    void sub_020243F0(int timer);
    BOOL sub_02024440();
    void sub_02024480();
    BOOL sub_020244DC();
    void sub_020244F8();
    void sub_02024570();
    void sub_0202458C();
    void sub_020245A8();
    void sub_020245D8();
    void sub_0202462C();
    void sub_02024690();
    BOOL IsFading();
    BOOL IsActive();
    int GetSelection();
    fx32 Quadratic(fx32 a, fx32 b, fx32 t, fx32 c);
    fx32 SolveQuadratic(fx32 start, fx32 end, fx32 b, fx32 t);

public:
    u16 unk_00;
    u8 unk_02[6];
    int unk_08;
    Camera2D *unk_0C;
    u8 unk_10[8];
    UnkClass_0201AD60 *unk_18;
    UnkClass_0200ECD0 *unk_1C;
    UnkClass_0200ECD0 *unk_20;
    UnkClass_0200E960 *unk_24[9];
    UnkClass_0200E960 *unk_48[9];
    UnkClass_0200E960 *unk_6C;
    int unk_70;
    int unk_74;
    fx32 unk_78;
    fx32 unk_7C;
    int unk_80[9];
    int unk_A4[9];
    fx32 unk_C8[9];
    fx32 unk_EC[9];
    BOOL unk_110;
    BOOL unk_114;
    int unk_118;
    UnkClass_0202773C *unk_11C;
    CGame *unk_120;
};

STATIC_SIZE_ASSERT(UnkClass_02023558, 0x124);

class UnkClass_020233C8 {
public:
    UnkClass_020233C8(CGame *game);
    ~UnkClass_020233C8();

    void Update();
    void Render();
    void sub_02023470();
    void Init();
    void sub_020234D4();
    void sub_020234F0();
    void sub_0202350C(int timer);
    BOOL IsActive();
    int GetSelection();

public:
    u16 unk_00;
    u16 unk_02;
    int unk_04;
    UnkClass_02023558 *unk_08;
    CGame *unk_0C;
};

STATIC_SIZE_ASSERT(UnkClass_020233C8, 0x10);

#endif // POKERANGER2_UNKCLASS_020233C8_HPP
