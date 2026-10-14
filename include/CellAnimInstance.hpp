#ifndef POKERANGER2_CELLANIMINSTANCE_HPP
#define POKERANGER2_CELLANIMINSTANCE_HPP

#include <nitro.h>

#include "common.hpp"

extern u16 g_animFps;

fx32 sub_02007DE4(u16 value);
int sub_02007DF0(int count, u16 dir, int arg2);

struct AnimCmd {
    u8 op;
    u16 arg;
};

class CellAnimInstance {
public:
    CellAnimInstance(u32 arg0, u32 arg1);
    ~CellAnimInstance();

    u8 GetCell();
    fx32 *GetOffsets();
    int GetStatus();
    void SetSpeed(fx32 speed);
    void Init(u32 arg0, u32 arg1);
    BOOL SetDirection(u16 dir);
    void Restart();
    BOOL SetAnim(int index);
    void Step();
    void StepSimple();
    void Update();
    void SetPrev(CellAnimInstance *prev);
    void SetNext(CellAnimInstance *next);
    CellAnimInstance *GetPrev();
    CellAnimInstance *GetNext();
    u16 GetId();
    void SetScript(AnimCmd *script, u16 length, u8 count, u8 loop);
    void SetId(u16 id);
    u8 GetAnimCount();

    inline void ClearFrames()
    {
        for (int i = 0; i < unk_2E; i++) {
            unk_00[i] = 0;
            unk_04[i] = 0;
            unk_08[i] = 0;
        }
    }

public:
    u8 *unk_00;
    u8 *unk_04;
    u8 *unk_08;
    u8 unk_0C;
    u16 unk_0E;
    u8 unk_10;
    u8 unk_11;
    fx32 unk_14;
    fx32 unk_18;
    fx32 unk_1C;
    fx32 unk_20;
    fx32 unk_24;
    fx32 unk_28;
    u16 unk_2C;
    u8 unk_2E;
    u8 unk_2F;
    AnimCmd *unk_30;
    fx32 unk_34;
    fx32 unk_38;
    u16 unk_3C;
    u16 unk_3E;
    CellAnimInstance *unk_40;
    CellAnimInstance *unk_44;
    u16 unk_48;
};

STATIC_SIZE_ASSERT(CellAnimInstance, 0x4C);

#endif // POKERANGER2_CELLANIMINSTANCE_HPP
