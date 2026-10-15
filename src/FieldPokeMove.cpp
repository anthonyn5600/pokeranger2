#include <nitro.h>

#include "CGame.hpp"
#include "FieldScreenEffectManage.hpp"
#include "MathUtil.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldEffectManpu.hpp"
#include "field/CFieldEffectSlime.hpp"
#include "field/CFieldEnemy.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "field/CFieldPartner.hpp"
#include "field/CFieldPlayer.hpp"
#include "field/CFieldPokeMove.hpp"

extern CFieldPlayer *MAIN_BSS_0210CA48;
extern CFieldEffectManage *MAIN_BSS_0210CA60;
extern u16 DAT_0208d58c;

extern "C" {
void LogError(const char *fmt, ...);
}

CFieldPokeMove::CFieldPokeMove()
{
    unk_48 = NULL;
    unk_4C = 0;
    unk_64 = 0xA000;
    unk_68 = 0;
    unk_4E = 0;
    unk_AC = NULL;
    unk_B0 = 0;
    unk_B4 = 0x24;
    unk_4C = 0xFFF;
    unk_B8 = 0;
    unk_BC = 1;
    unk_5C = 0;
    unk_CC = 0;
    unk_C0 = 0;
    unk_D0 = 0;
    unk_24.x = 0;
    unk_24.y = 0;
    unk_24.z = 0;
    unk_44 = 1;
    unk_D4 = 0;
    unk_D6 = 0;
    unk_30 = (Point2D) { FX32_ONE, 0 };
}

CFieldPokeMove::~CFieldPokeMove()
{
}

void CFieldPokeMove::SetTarget(CFieldActor *owner, Point2D target, int arg)
{
    unk_48 = owner;
    unk_04 = target;
    if (unk_44 != 0xF && unk_44 != 0xE) {
        unk_44 = 1;
    }
}

static inline void CommitNext(CFieldPokeMove *m)
{
    m->unk_0C = m->unk_18;
}

static inline void SetNextR(CFieldPokeMove *m, const PokeMoveVec &v)
{
    m->unk_18 = v;
}

static inline void SetEnemyDir(CFieldEnemy *enemy, Point2D dir)
{
    enemy->unk_158 = dir;
    enemy->unk_168.unk_30 = enemy->GetUnk158();
}

// NONMATCHING: the C++ below matches except for the register allocation of the distance block (98.8%, same size).
// The original's PCode shares the dy difference and pp.x / the in-place dx difference with argument temps of the
// IsInSight calls (ip / lr) and loads unk_CC before the pos copy; no source shape, pragma or compiler version tried
// reproduces that, so the original instructions are used.
#ifdef NONMATCHING
BOOL CFieldPokeMove::Update()
{
    if (unk_AC == NULL) {
        unk_AC = MAIN_BSS_0210CA48;
    }
    if (unk_AC != NULL) {
        Point2D pos;
        unk_0C.x = unk_48->GetX();
        unk_0C.y = unk_48->GetY();
        unk_0C.z = unk_48->GetBaseHeight();
        int dist = unk_AC->GetPos().DistSqTo(unk_0C);
        int dz = unk_0C.z >> FX32_SHIFT;
        unk_C8 = dist;
        unk_C4 = dz * dz + unk_C8;
        pos = unk_0C;
        if (unk_CC == 0 && !(unk_AC->unk_10C & 1)) {
            if (unk_68 == 5 || unk_AC->m_layer == unk_48->m_layer) {
                if (IsInSight(pos, unk_AC->GetPos(), unk_6C.unk_02, unk_30, unk_6C.unk_06)) {
                    unk_C0 = 1;
                } else if (IsInSight(pos, unk_AC->GetPos(), unk_6C.unk_04, unk_30, unk_6C.unk_08)) {
                    unk_C0 = 2;
                } else {
                    unk_C0 = 0;
                }
            } else {
                unk_C0 = 0;
            }
        } else {
            unk_C0 = 0;
        }
        if (unk_48 != NULL && unk_CC == 0) {
            SetEnemyDir((CFieldEnemy *)unk_48, unk_30);
        }
    }
    switch (unk_44) {
    case 0:
        break;
    case 1:
        ov0_0215675C();
        break;
    case 2:
        ov0_02156898();
        break;
    case 3:
        ov0_02153040();
        break;
    case 4:
        ov0_02153538();
        break;
    case 6: // the original emits case 6's body before case 5's (jump table order)
        ov0_02153D78();
        break;
    case 5:
        ov0_02154210();
        break;
    case 7:
        ov0_021545EC();
        break;
    case 8:
        ov0_02154810();
        break;
    case 9:
        ov0_0215900C();
        break;
    case 10:
        ov0_02154C30();
        break;
    case 11:
        ov0_02154C58();
        break;
    case 12:
        ov0_02155558();
        break;
    case 13:
        ov0_02155580();
        break;
    case 14:
        ov0_02155588();
        break;
    case 15:
        ov0_021558F4();
        break;
    case 16:
        ov0_021559F0();
        break;
    case 17:
        ov0_021559F8();
        break;
    case 18:
        ov0_02155A90();
        break;
    case 19:
        ov0_02155B88();
        break;
    case 20:
        ov0_02155C20();
        break;
    case 21:
        ov0_02155D38();
        break;
    case 22:
        ov0_02155EA0();
        break;
    case 23:
        ov0_02156194();
        break;
    case 24:
        ov0_02156290();
        break;
    }
    ProcSpecialEffect();
    unk_50--;
    return FALSE;
}
#else
// clang-format off
asm BOOL CFieldPokeMove::Update()
{
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0x74
    mov r4, r0
    ldr r0, [r4, #0xac]
    cmp r0, #0
    ldreq r0, =MAIN_BSS_0210CA48
    ldreq r0, [r0]
    streq r0, [r4, #0xac]
    ldr r0, [r4, #0xac]
    cmp r0, #0
    beq @L02152E8C
    ldr r0, [r4, #0x48]
    ldr r0, [r0, #8]
    cmp r0, #0
    beq @L02152B54
    ldr r0, [r0, #0xc]
    cmp r0, #0
    ldrne r0, [r0, #0x20]
    moveq r0, #0
    b @L02152B58
@L02152B54:
    mov r0, #0
@L02152B58:
    str r0, [r4, #0xc]
    ldr r0, [r4, #0x48]
    ldr r0, [r0, #8]
    cmp r0, #0
    beq @L02152B80
    ldr r0, [r0, #0xc]
    cmp r0, #0
    ldrne r0, [r0, #0x24]
    moveq r0, #0
    b @L02152B84
@L02152B80:
    mov r0, #0
@L02152B84:
    str r0, [r4, #0x10]
    ldr r0, [r4, #0x48]
    ldr r0, [r0, #8]
    cmp r0, #0
    beq @L02152BAC
    ldr r0, [r0, #0xc]
    cmp r0, #0
    ldrne r0, [r0, #0x8c]
    moveq r0, #0
    b @L02152BB0
@L02152BAC:
    mov r0, #0
@L02152BB0:
    str r0, [r4, #0x14]
    ldr r0, [r4, #0xac]
    ldr r0, [r0, #8]
    cmp r0, #0
    beq @L02152C04
    ldr r0, [r0, #0xc]
    cmp r0, #0
    beq @L02152BE4
    ldr r1, [r0, #0x20]
    ldr r0, [r0, #0x24]
    str r1, [sp, #0x64]
    str r0, [sp, #0x68]
    b @L02152BFC
@L02152BE4:
    mov r0, #0
    add r1, sp, #0x4c
    str r0, [r1]
    str r0, [r1, #4]
    str r0, [sp, #0x64]
    str r0, [sp, #0x68]
@L02152BFC:
    add r3, sp, #0x64
    b @L02152C20
@L02152C04:
    mov r0, #0
    add r1, sp, #0x44
    add r3, sp, #0x64
    str r0, [r1]
    str r0, [r1, #4]
    str r0, [sp, #0x64]
    str r0, [sp, #0x68]
@L02152C20:
    ldr r2, [r3, #4]
    ldr r0, [r4, #0x10]
    ldr lr, [r3]
    sub ip, r2, r0
    mov r2, ip, asr #0xc
    mul r0, r2, r2
    ldr r3, [r4, #0xc]
    ldr r1, [r4, #0x14]
    sub lr, lr, r3
    mov r3, lr, asr #0xc
    mov r2, r1, asr #0xc
    mla r1, r3, r3, r0
    mla r0, r2, r2, r1
    str r1, [r4, #0xc8]
    str r0, [r4, #0xc4]
    ldr r0, [r4, #0xcc]
    ldr r2, [r4, #0xc]
    ldr r1, [r4, #0x10]
    str r2, [sp, #0x6c]
    str r1, [sp, #0x70]
    cmp r0, #0
    bne @L02152E40
    ldr r2, [r4, #0xac]
    ldr r0, [r2, #0x10c]
    tst r0, #1
    bne @L02152E40
    ldr r0, [r4, #0x68]
    cmp r0, #5
    beq @L02152CA8
    ldr r0, [r4, #0x48]
    ldr r1, [r2, #0x14]
    ldr r0, [r0, #0x14]
    cmp r1, r0
    bne @L02152E34
@L02152CA8:
    ldr r0, [r2, #8]
    cmp r0, #0
    beq @L02152CF4
    ldr r0, [r0, #0xc]
    cmp r0, #0
    beq @L02152CD4
    ldr r1, [r0, #0x20]
    ldr r0, [r0, #0x24]
    str r1, [sp, #0x5c]
    str r0, [sp, #0x60]
    b @L02152CEC
@L02152CD4:
    mov r0, #0
    add r1, sp, #0x3c
    str r0, [r1]
    str r0, [r1, #4]
    str r0, [sp, #0x5c]
    str r0, [sp, #0x60]
@L02152CEC:
    add r3, sp, #0x5c
    b @L02152D10
@L02152CF4:
    mov r0, #0
    add r1, sp, #0x34
    add r3, sp, #0x5c
    str r0, [r1]
    str r0, [r1, #4]
    str r0, [sp, #0x5c]
    str r0, [sp, #0x60]
@L02152D10:
    ldrh r0, [r4, #0x6e]
    sub lr, sp, #4
    add r1, sp, #0x6c
    str r0, [sp, #4]
    ldr ip, [r4, #0x30]
    ldr r2, [r4, #0x34]
    mov r0, r4
    str ip, [sp, #8]
    str r2, [sp, #0xc]
    ldrh ip, [r4, #0x72]
    ldmia r1, {r1, r2}
    str ip, [sp, #0x10]
    ldr ip, [r3]
    ldr r3, [r3, #4]
    str ip, [lr]
    str r3, [lr, #4]
    ldr r3, [lr]
    bl IsInSight
    cmp r0, #0
    movne r0, #1
    strne r0, [r4, #0xc0]
    bne @L02152E48
    ldr r0, [r4, #0xac]
    ldr r0, [r0, #8]
    cmp r0, #0
    beq @L02152DB8
    ldr r0, [r0, #0xc]
    cmp r0, #0
    beq @L02152D98
    ldr r1, [r0, #0x20]
    ldr r0, [r0, #0x24]
    str r1, [sp, #0x54]
    str r0, [sp, #0x58]
    b @L02152DB0
@L02152D98:
    mov r0, #0
    add r1, sp, #0x2c
    str r0, [r1]
    str r0, [r1, #4]
    str r0, [sp, #0x54]
    str r0, [sp, #0x58]
@L02152DB0:
    add r3, sp, #0x54
    b @L02152DD4
@L02152DB8:
    mov r0, #0
    add r1, sp, #0x24
    add r3, sp, #0x54
    str r0, [r1]
    str r0, [r1, #4]
    str r0, [sp, #0x54]
    str r0, [sp, #0x58]
@L02152DD4:
    ldrh r0, [r4, #0x70]
    sub lr, sp, #4
    add r1, sp, #0x6c
    str r0, [sp, #4]
    ldr ip, [r4, #0x30]
    ldr r2, [r4, #0x34]
    mov r0, r4
    str ip, [sp, #8]
    str r2, [sp, #0xc]
    ldrh ip, [r4, #0x74]
    ldmia r1, {r1, r2}
    str ip, [sp, #0x10]
    ldr ip, [r3]
    ldr r3, [r3, #4]
    str ip, [lr]
    str r3, [lr, #4]
    ldr r3, [lr]
    bl IsInSight
    cmp r0, #0
    movne r0, #2
    strne r0, [r4, #0xc0]
    moveq r0, #0
    streq r0, [r4, #0xc0]
    b @L02152E48
@L02152E34:
    mov r0, #0
    str r0, [r4, #0xc0]
    b @L02152E48
@L02152E40:
    mov r0, #0
    str r0, [r4, #0xc0]
@L02152E48:
    ldr r3, [r4, #0x48]
    cmp r3, #0
    beq @L02152E8C
    ldr r0, [r4, #0xcc]
    cmp r0, #0
    bne @L02152E8C
    ldr r1, [r4, #0x34]
    ldr r2, [r4, #0x30]
    str r1, [sp, #0x20]
    str r2, [r3, #0x158]
    str r1, [r3, #0x15c]
    ldr r0, [r3, #0x158]
    str r2, [sp, #0x1c]
    str r0, [r3, #0x198]
    str r0, [sp, #0x14]
    str r1, [sp, #0x18]
    str r1, [r3, #0x19c]
@L02152E8C:
    ldr r0, [r4, #0x44]
    cmp r0, #0x18
    addls pc, pc, r0, lsl #2
    b @L0215301C
@L02152E9C:
    b @L0215301C
    b @L02152F00
    b @L02152F0C
    b @L02152F18
    b @L02152F24
    b @L02152F3C
    b @L02152F30
    b @L02152F48
    b @L02152F54
    b @L02152F60
    b @L02152F6C
    b @L02152F78
    b @L02152F84
    b @L02152F90
    b @L02152F9C
    b @L02152FA8
    b @L02152FB4
    b @L02152FC0
    b @L02152FCC
    b @L02152FD8
    b @L02152FE4
    b @L02152FF0
    b @L02152FFC
    b @L02153008
    b @L02153014
@L02152F00:
    mov r0, r4
    bl ov0_0215675C
    b @L0215301C
@L02152F0C:
    mov r0, r4
    bl ov0_02156898
    b @L0215301C
@L02152F18:
    mov r0, r4
    bl ov0_02153040
    b @L0215301C
@L02152F24:
    mov r0, r4
    bl ov0_02153538
    b @L0215301C
@L02152F30:
    mov r0, r4
    bl ov0_02153D78
    b @L0215301C
@L02152F3C:
    mov r0, r4
    bl ov0_02154210
    b @L0215301C
@L02152F48:
    mov r0, r4
    bl ov0_021545EC
    b @L0215301C
@L02152F54:
    mov r0, r4
    bl ov0_02154810
    b @L0215301C
@L02152F60:
    mov r0, r4
    bl ov0_0215900C
    b @L0215301C
@L02152F6C:
    mov r0, r4
    bl ov0_02154C30
    b @L0215301C
@L02152F78:
    mov r0, r4
    bl ov0_02154C58
    b @L0215301C
@L02152F84:
    mov r0, r4
    bl ov0_02155558
    b @L0215301C
@L02152F90:
    mov r0, r4
    bl ov0_02155580
    b @L0215301C
@L02152F9C:
    mov r0, r4
    bl ov0_02155588
    b @L0215301C
@L02152FA8:
    mov r0, r4
    bl ov0_021558F4
    b @L0215301C
@L02152FB4:
    mov r0, r4
    bl ov0_021559F0
    b @L0215301C
@L02152FC0:
    mov r0, r4
    bl ov0_021559F8
    b @L0215301C
@L02152FCC:
    mov r0, r4
    bl ov0_02155A90
    b @L0215301C
@L02152FD8:
    mov r0, r4
    bl ov0_02155B88
    b @L0215301C
@L02152FE4:
    mov r0, r4
    bl ov0_02155C20
    b @L0215301C
@L02152FF0:
    mov r0, r4
    bl ov0_02155D38
    b @L0215301C
@L02152FFC:
    mov r0, r4
    bl ov0_02155EA0
    b @L0215301C
@L02153008:
    mov r0, r4
    bl ov0_02156194
    b @L0215301C
@L02153014:
    mov r0, r4
    bl ov0_02156290
@L0215301C:
    mov r0, r4
    bl ProcSpecialEffect
    ldr r1, [r4, #0x50]
    mov r0, #0
    sub r1, r1, #1
    str r1, [r4, #0x50]
    add sp, sp, #0x74
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
#endif

int CFieldPokeMove::ov0_02153040()
{
    switch (unk_4E) {
    case 0:
        BeginSequence();
        unk_30.x = FX_CosIdx(unk_48->GetDir());
        unk_30.y = FX_SinIdx(unk_48->GetDir());
        unk_38 = GetPlayerPos() - (Point2D) { unk_0C.x, unk_0C.y };
        fx32 inv;
        inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
        unk_38.x = FX32_MUL(unk_38.x, inv);
        unk_38.y = FX32_MUL(unk_38.y, inv);
        SetUnk04(GetPlayerPos());
        unk_4C = unk_6C.unk_14;
        if (IsBlockedAhead(unk_38, unk_6C.unk_10)) {
            SetSequence(1);
        } else {
            ShowManpu(4, 30);
            if (unk_68 != 5) {
                PlayCry();
            }
            if (unk_68 == 9) {
                unk_4E = 10;
            } else {
                unk_4E = 1;
            }
        }
        break;
    case 1:
        if (unk_6C.unk_3C == 0) {
            if (TurnToward(&unk_30, &unk_38, unk_4C)) {
                unk_4E = 2;
            }
        } else {
            unk_4E = 2;
        }
        unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
        unk_50 = unk_6C.unk_1A;
        break;
    case 2:
        SetUnk04(GetPlayerPos());
        int next;
        next = Move(&unk_24, unk_6C.unk_10, -1);
        if (next != 0) {
            SetSequence(next);
        } else if (unk_50 <= 0) {
            SetSequence(1);
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    case 10:
        if (TurnToward(&unk_30, &unk_38, unk_4C)) {
            unk_4E = 11;
        }
        unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
        break;
    case 11:
        unk_4E = 12;
        break;
    case 12:
        unk_4E = 13;
        break;
    case 13:
        unk_4E = 14;
        break;
    case 14:
        unk_4E = 15;
        break;
    case 15:
        SetSequence(1);
        break;
    }
    return 0;
}

int CFieldPokeMove::ov0_02153538()
{
    switch (unk_4E) {
    case 0: {
        BeginSequence();
        unk_30.x = FX_CosIdx(unk_48->GetDir());
        unk_30.y = FX_SinIdx(unk_48->GetDir());
        unk_38 = unk_0C - GetPlayerPos();
        fx32 inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
        unk_38.x = FX32_MUL(unk_38.x, inv);
        unk_38.y = FX32_MUL(unk_38.y, inv);
        fx32 dist = FX32_MUL(unk_6C.unk_10, unk_6C.unk_1A << FX32_SHIFT);
        Point2D target;
        target.x = unk_0C.x + FX32_MUL(unk_38.x, dist);
        target.y = unk_0C.y + FX32_MUL(unk_38.y, dist);
        SetUnk04(target);
        unk_4C = unk_6C.unk_14;
        ShowManpu(7, 30);
        if (unk_68 != 5 && IsBlockedAhead(unk_38, unk_6C.unk_10)) {
            if (unk_48->unk_64.x > unk_0C.x) {
                if (unk_48->unk_64.y > unk_0C.y) {
                    unk_4E = 10;
                } else {
                    unk_4E = 11;
                }
            } else {
                if (unk_48->unk_64.y > unk_0C.y) {
                    unk_4E = 11;
                } else {
                    unk_4E = 10;
                }
            }
        } else {
            if (unk_68 != 5) {
                PlayCry();
            }
            unk_4E = 1;
        }
        break;
    }
    case 1:
        if (unk_6C.unk_3C == 0) {
            if (TurnToward(&unk_30, &unk_38, unk_4C)) {
                unk_4E = 2;
            }
        } else {
            unk_4E = 2;
        }
        unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
        break;
    case 2:
        if (Move(&unk_24, unk_6C.unk_10, -1) != 0) {
            SetSequence(1);
        }
        break;
    case 10:
    case 11: {
        int angle = unk_4E == 10 ? 0xAAA : 0xF555;
        fx32 c = FX_CosIdx(angle);
        fx32 s = FX_SinIdx(angle);
        Point2D dir = unk_38;
        unk_38.x = FX32_MUL(dir.x, c) - FX32_MUL(dir.y, s);
        unk_38.y = FX32_MUL(dir.y, c) + FX32_MUL(dir.x, s);
        fx32 inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
        unk_38.x = FX32_MUL(unk_38.x, inv);
        unk_38.y = FX32_MUL(unk_38.y, inv);
        ShowManpu(7, 30);
        if (IsBlockedAhead(unk_38, unk_6C.unk_10)) {
            dir = unk_38;
            unk_38.x = FX32_MUL(dir.x, c) - FX32_MUL(dir.y, s);
            unk_38.y = FX32_MUL(dir.y, c) + FX32_MUL(dir.x, s);
            inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
            unk_38.x = FX32_MUL(unk_38.x, inv);
            unk_38.y = FX32_MUL(unk_38.y, inv);
            IsBlockedAhead(unk_38, unk_6C.unk_10);
        } else {
            if (unk_68 != 5) {
                PlayCry();
            }
            fx32 dist = FX32_MUL(unk_6C.unk_10, unk_6C.unk_1A << FX32_SHIFT);
            Point2D target;
            target.x = unk_0C.x + FX32_MUL(unk_38.x, dist);
            target.y = unk_0C.y + FX32_MUL(unk_38.y, dist);
            SetUnk04(target);
            unk_4C = unk_6C.unk_14;
            unk_4E = 1;
        }
        break;
    }
    }
    return 0;
}

BOOL CFieldPokeMove::ov0_02153B60(int step)
{
    BOOL ok;
    if (step <= 0) {
        ok = !CollidesAt(unk_04, unk_6C.unk_1C, unk_B4);
    } else {
        fx32 dist = FX32_MUL(unk_6C.unk_10, unk_6C.unk_1A << FX32_SHIFT);
        u16 angle = (((step - 1) >> 1) + 1) * 0x1000;
        BOOL behind = angle > 0x4000;
        if (step & 1) {
            angle = 0x10000 - angle;
        }
        fx32 c = FX_CosIdx(angle);
        fx32 s = FX_SinIdx(angle);
        fx32 dx = FX32_MUL(unk_38.x, c) - FX32_MUL(unk_38.y, s);
        fx32 dy = FX32_MUL(unk_38.x, s) + FX32_MUL(unk_38.y, c);
        Point2D pos;
        pos.x = unk_0C.x + FX32_MUL(dx, dist);
        pos.y = unk_0C.y + FX32_MUL(dy, dist);
        ok = !CollidesAt(pos, unk_6C.unk_1C, unk_B4);
        if (behind) {
            Point2D pp = GetPlayerPos();
            if (ApproxLength(pos.x - pp.x, pos.y - pp.y) < 0x20000) {
                ok = FALSE;
            }
        }
        if (ok) {
            unk_04 = pos;
        }
    }
    return ok;
}

int CFieldPokeMove::ov0_02153D78()
{
    int step;
    switch (unk_4E & 0xFF) {
    case 0: {
        step = unk_4E >> 8;
        for (int i = 0; step < 16 && i < 4; i++) {
            if (ov0_02153B60(step)) {
                unk_4E = 1;
                break;
            }
            step++;
            unk_4E = step << 8;
        }
        if (step >= 16) {
            SetSequence(1);
        }
        break;
    }
    case 1:
        unk_48->sub_reset();
        if (PlayEnemyAnime(0) == -1) {
            unk_48->sub_02012A3C_(7, 0x1800, 0x800);
            unk_4E = 4;
            unk_50 = 7;
        } else {
            unk_4E = 2;
        }
        if (unk_CC == 0) {
            PlayGroupSe(0x56, 0x5C);
        }
        break;
    case 2:
        if (unk_48->GetAnimState() == 0) {
            unk_4E = 3;
            PlayEnemyAnime(1);
            fx32 y = unk_04.y;
            // Reusing step makes this x a split live range, which gets the original's register.
            step = unk_04.x;
            unk_48->SetPosXY(step, y);
        }
        break;
    case 3:
        if (unk_48->GetAnimState() == 0) {
            unk_48->sub_show();
            SetSequence(1);
        }
        break;
    case 4:
        if (unk_48->GetScale() == 0x1800 || unk_50 <= 0) {
            unk_48->sub_02012A3C_(7, 0, 0x2000);
            unk_4E = 5;
            unk_50 = 7;
        }
        break;
    case 5:
        if (unk_48->GetScale() == 0 || unk_50 <= 0) {
            unk_48->sub_02012A3C_(7, 0x1800, 0x800);
            fx32 y = unk_04.y;
            step = unk_04.x;
            unk_48->SetPosXY(step, y);
            unk_4E = 6;
            unk_50 = 7;
        }
        break;
    case 6:
        if (unk_48->GetScale() == 0x1800 || unk_50 <= 0) {
            unk_48->sub_02012A3C_(7, 0x1000, 0x1000);
            unk_4E = 7;
            unk_50 = 7;
        }
        break;
    case 7:
        if (unk_48->GetScale() == 0x1000 || unk_50 <= 0) {
            unk_48->sub_show();
            SetSequence(1);
        }
        break;
    }
    return 0;
}

int CFieldPokeMove::ov0_02154210()
{
    switch (unk_4E) {
    case 0: {
        BeginSequence();
        unk_30.x = FX_CosIdx(unk_48->GetDir());
        unk_30.y = FX_SinIdx(unk_48->GetDir());
        unk_38 = GetPlayerPos() - (Point2D) { unk_0C.x, unk_0C.y };
        fx32 inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
        unk_38.x = FX32_MUL(unk_38.x, inv);
        unk_38.y = FX32_MUL(unk_38.y, inv);
        Point2D target = { FX32_MUL(-unk_38.x, (fx64)0x23000) + GetPlayerPos().x,
            FX32_MUL(-unk_38.y, (fx64)0x23000) + GetPlayerPos().y };
        SetUnk04(target);
        unk_4C = unk_6C.unk_14;
        unk_4E = 1;
        break;
    }
    case 1:
        if (unk_6C.unk_3C == 0) {
            if (TurnToward(&unk_30, &unk_38, unk_4C)) {
                unk_4E = 2;
            }
        } else {
            unk_4E = 2;
        }
        unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
        break;
    case 2:
        SetSequence(6);
        break;
    }
    return 0;
}

int CFieldPokeMove::ov0_021545EC()
{
    switch (unk_4E) {
    case 0:
        ShowManpu(4, 30);
        PlayCry();
        BeginSequence();
        unk_48->sub_reset();
        PlayEnemyAnime(0);
        unk_4E = 1;
        break;
    case 1:
        if (unk_48->GetAnimState() == 0) {
            unk_48->sub_show();
            CFieldEffectManage *manage = MAIN_BSS_0210CA60;
            FieldScreenEffectManage *fade = MAIN_BSS_0210CA78;
            CFieldEffect *effect = manage->Get(manage->Create(0xC, 0));
            if (effect != NULL) {
                effect->SetParam(1, unk_0C.x >> FX32_SHIFT);
                effect->SetParam(2, (unk_0C.y - unk_0C.z) >> FX32_SHIFT);
                effect->SetParam(18, unk_6C.unk_27);
                effect->Start(0, -1, 0);
            }
            if (fade != NULL) {
                fade->SetPrimaryEffect(6);
                fade->StartEffect(6, 15, 30, 150);
            }
            unk_50 = 120;
            unk_4E = 2;
        }
        break;
    case 2:
        if (unk_50 <= 0) {
            SetSequence(1);
        }
        break;
    }
    return 0;
}

int CFieldPokeMove::ov0_02154810()
{
    switch (unk_4E) {
    case 0:
        ShowManpu(4, 30);
        PlayCry();
        BeginSequence();
        unk_48->sub_reset();
        PlayEnemyAnime(0);
        unk_4E = 1;
        break;
    case 1:
        if (unk_48->GetAnimState() == 0) {
            CFieldEffectManage *manage = MAIN_BSS_0210CA60;
            CFieldEffect *effect = manage->Get(manage->Create(0xD, 0));
            if (effect != NULL) {
                effect->SetParam(1, unk_0C.x >> FX32_SHIFT);
                effect->SetParam(2, unk_0C.y >> FX32_SHIFT);
                effect->SetParam(18, unk_6C.unk_27);
                effect->Start(0, -1, 0);
                PlayGroupSe(0x57, 0x5D);
            }
            unk_50 = 60;
            unk_4E = 2;
        }
        break;
    case 2:
        if (unk_50 <= 0) {
            unk_48->sub_reset();
            PlayEnemyAnime(1);
            unk_4E = 3;
        }
        break;
    case 3:
        if (unk_48->GetAnimState() == 0) {
            unk_48->sub_show();
            SetSequence(1);
        }
        break;
    }
    return 0;
}

int CFieldPokeMove::ProcSpecialEffect()
{
    if (unk_CC == 0 && unk_6C.unk_00 >= 16 && unk_6C.unk_00 <= 18 && unk_B8 == 0) {
        CFieldEffectManage *manage = MAIN_BSS_0210CA60;
        if (manage != NULL) {
            int arg = 0;
            switch (unk_6C.unk_00) {
            case 16:
                arg = 0x84;
                break;
            case 17:
                arg = 0x85;
                break;
            case 18:
                arg = 0x86;
                break;
            default:
                LogError("ProcSpecaialEffect() ScriptID=%d");
                break;
            }
            for (u16 id = manage->GetNext(0); id != 0; id = manage->GetNext(id)) {
                CFieldEffectSlime *slime = (CFieldEffectSlime *)manage->Get(id);
                if (slime != NULL && slime->GetEffectId() == 0x12 && slime->m_actor == unk_48 && !(slime->m_flags & 0x8000)) {
                    unk_B8 = id;
                    break;
                }
            }
            if (unk_B8 == 0) {
                unk_B8 = manage->Create(0x12, arg);
                CFieldEffectSlime *slime = (CFieldEffectSlime *)manage->Get(unk_B8);
                if (slime != NULL) {
                    slime->m_actor = unk_48;
                    slime->SetParam(18, unk_6C.unk_27);
                    slime->Start(0, -1, 0);
                }
            }
        }
    }
    if (unk_B8 != 0 && MAIN_BSS_0210CA60 != NULL) {
        CFieldEffectSlime *slime = (CFieldEffectSlime *)MAIN_BSS_0210CA60->Get(unk_B8);
        if (slime != NULL) {
            if (unk_44 == 1) {
                slime->StopPuddles();
            } else {
                slime->StartPuddles();
            }
        }
    }
    return 0;
}

static inline void SetActorPos(CFieldActor *actor, fx32 x, fx32 y, fx32 z)
{
    actor->SetPosXY(x, y);
    actor->SetBaseHeight(z);
}

int CFieldPokeMove::ov0_02154C30()
{
    ShowManpu(4, 30);
    SetSequence(1);
    return 0;
}

int CFieldPokeMove::ov0_02154C58()
{
    // x is assigned in the argument lists: a split live range of one variable gets the original's registers and
    // keeps its load in argument order.
    fx32 x;
    switch (unk_4E) {
    case 0:
        ShowManpu(4, 30);
        PlayCry();
        BeginSequence();
        unk_30.x = FX_CosIdx(unk_48->GetDir());
        unk_30.y = FX_SinIdx(unk_48->GetDir());
        unk_38 = GetPlayerPos() - (Point2D) { unk_0C.x, unk_0C.y };
        fx32 inv;
        inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
        unk_38.x = FX32_MUL(unk_38.x, inv);
        unk_38.y = FX32_MUL(unk_38.y, inv);
        SetUnk04(GetPlayerPos());
        unk_4C = unk_6C.unk_14;
        unk_4E = 1;
        break;
    case 1:
        if (unk_6C.unk_3C == 0) {
            if (TurnToward(&unk_30, &unk_38, unk_4C)) {
                unk_4E = 2;
            }
        } else {
            unk_4E = 2;
        }
        unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
        break;
    case 2:
        unk_48->sub_reset();
        unk_48->m_flags &= ~0x400;
        PlayEnemyAnime(2);
        unk_4E = 3;
        unk_24.x = FX32_MUL(unk_30.x, 0x6000);
        unk_24.y = FX32_MUL(unk_30.y, 0x6000);
        unk_24.z = 0x4000;
        unk_50 = 60;
        break;
    case 3:
        if (IsTouchingPlayer()) {
            fx32 dx = unk_AC->GetPos().x - unk_0C.x;
            fx32 dy = unk_AC->GetPos().y - unk_0C.y;
            fx32 inv = FX_InvSqrt(FX32_MUL(dx, dx) + FX32_MUL(dy, dy));
            unk_AC->KnockBack(FX32_MUL(dx, inv), FX32_MUL(dy, inv), 10, unk_6C.unk_27, -1);
            unk_4E = 5;
        } else {
            unk_24.z -= 0x800;
            if (unk_24.z < -0xA000) {
                unk_24.z = -0xA000;
            }
            unk_18.x = unk_0C.x + unk_24.x;
            unk_18.y = unk_0C.y + unk_24.y;
            unk_18.z = unk_0C.z + unk_24.z;
            if (unk_18.z < 0) {
                unk_18.z = 0;
            }
            PointPair2D move;
            move.p1 = unk_0C;
            move.p2 = unk_18;
            if (IsBlocked(move, unk_64, unk_B4)) {
                unk_18.x = unk_48->unk_64.x;
                unk_18.y = unk_48->unk_64.y;
                SetActorPos(unk_48, x = unk_18.x, unk_18.y, unk_18.z);
                unk_0C = unk_18;
                unk_4E = 5;
            } else {
                SetActorPos(unk_48, x = unk_18.x, unk_18.y, unk_18.z);
                unk_0C = unk_18;
                if (unk_50 < 0 || unk_0C.z <= 0) {
                    unk_4E = 4;
                }
            }
        }
        break;
    case 4:
        unk_48->m_flags |= 0x400;
        SetSequence(1);
        break;
    case 5:
        PlayGroupSe(0x49, 0x4F);
        unk_24.x = FX32_MUL(-unk_30.x, FX32_ONE);
        unk_24.y = FX32_MUL(-unk_30.y, FX32_ONE);
        unk_24.z = 0x2000;
        unk_4E = 6;
        break;
    case 6: {
        unk_24.z -= 0x800;
        if (unk_24.z < -0xA000) {
            unk_24.z = -0xA000;
        }
        unk_18.x = unk_0C.x + unk_24.x;
        unk_18.y = unk_0C.y + unk_24.y;
        unk_18.z = unk_0C.z + unk_24.z;
        if (unk_18.z < 0) {
            unk_18.z = 0;
        }
        PointPair2D move;
        move.p1 = unk_0C;
        move.p2 = unk_18;
        if (IsBlocked(move, unk_64, unk_B4)) {
            unk_18.x = unk_48->unk_64.x;
            unk_18.y = unk_48->unk_64.y;
            unk_48->SetBaseHeight(unk_18.z);
            unk_0C.z = unk_18.z;
        } else {
            SetActorPos(unk_48, x = unk_18.x, unk_18.y, unk_18.z);
            unk_0C = unk_18;
        }
        if (unk_18.z == 0) {
            unk_4E = 4;
        }
        break;
    }
    }
    return 0;
}

PokeMoveVec PokeMoveVec::operator=(const PokeMoveVec &other)
{
    return PokeMoveVec(x = other.x, y = other.y, z = other.z);
}

int CFieldPokeMove::ov0_02155558()
{
    ShowManpu(4, 30);
    SetSequence(1);
    return 0;
}

int CFieldPokeMove::ov0_02155580()
{
    return 0;
}

int CFieldPokeMove::ov0_02155588()
{
    fx32 speed;
    switch (unk_4E) {
    case 0: {
        BeginSequence();
        int range = unk_6C.unk_04;
        speed = FX32_MUL(range << FX32_SHIFT, (fx64)0x555);
        range *= range;
        if (unk_C8 <= range) {
            unk_0C.z = 0;
            unk_48->m_flags &= ~1;
            if (unk_6C.unk_2E != 0) {
                unk_24.z = FX32_MUL(FX32_MUL(speed, unk_6C.unk_2E), FX32_ONE / 2);
            } else {
                unk_24.z = FX32_MUL(speed, FX32_ONE / 4);
            }
            unk_30 = GetPlayerPos() - GetPos();
            fx32 inv = FX_InvSqrt(FX32_MUL(unk_30.x, unk_30.x) + FX32_MUL(unk_30.y, unk_30.y));
            unk_30.x = FX32_MUL(unk_30.x, inv);
            unk_30.y = FX32_MUL(unk_30.y, inv);
            unk_24.x = FX32_MUL(unk_30.x, (fx64)0x3000);
            unk_24.y = FX32_MUL(unk_30.y, (fx64)0x3000);
            unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
            PlayCry();
            SpawnGroundEffect(1);
            unk_4E = 1;
        }
        break;
    }
    case 1:
        if (unk_6C.unk_2E != 0) {
            unk_24.z -= unk_6C.unk_2E;
        } else {
            unk_24.z -= 0x800;
        }
        if (unk_24.z < -0xA000) {
            unk_24.z = -0xA000;
        }
        unk_0C.x += unk_24.x;
        unk_0C.y += unk_24.y;
        unk_0C.z += unk_24.z;
        if (unk_0C.z < 0) {
            unk_0C.z = 0;
            unk_4E = 2;
        }
        break;
    case 2:
        SetSequence(1);
        break;
    }
    fx32 y = unk_0C.y;
    // Reusing speed makes this x a split live range, which gets the original's register.
    speed = unk_0C.x;
    unk_48->SetPosXY(speed, y);
    unk_48->SetBaseHeight(unk_0C.z);
    return 0;
}

int CFieldPokeMove::ov0_021558F4()
{
    switch (unk_4E) {
    case 0:
        unk_0C.z = 0xFA000;
        int sq;
        sq = unk_6C.unk_02;
        sq *= sq;
        if (unk_C8 <= sq) {
            PlayGroupSe(0x99, 0x91);
            unk_0C.z = 0x96000;
            unk_48->m_flags &= ~1;
            unk_24.z = 0;
            unk_4E = 1;
        }
        break;
    case 1:
        unk_24.z -= unk_6C.unk_2E;
        if (unk_24.z < -0x14000) {
            unk_24.z = 0x14000;
        }
        unk_0C.z += unk_24.z;
        if (unk_0C.z < 0) {
            unk_0C.z = 0;
            SpawnGroundEffect(0);
            unk_4E = 2;
        }
        break;
    case 2:
        SetSequence(1);
        break;
    }
    unk_48->SetBaseHeight(unk_0C.z);
    return 0;
}

int CFieldPokeMove::ov0_021559F0()
{
    return 0;
}

int CFieldPokeMove::ov0_021559F8()
{
    switch (unk_4E) {
    case 0:
        unk_48->m_flags &= ~0x400;
        ((CFieldEnemy *)unk_48)->EnableTargetObject();
        unk_48->m_flags |= 1;
        unk_48->m_flags |= 0x200;
        unk_4E = 1;
        break;
    case 1:
        unk_50 = 60;
        unk_4E = 2;
        break;
    case 2:
        if (unk_50 <= 0) {
            unk_4E = 1;
        }
        break;
    }
    return 0;
}

int CFieldPokeMove::ov0_02155A90()
{
    switch (unk_4E) {
    case 0:
        PlayCry();
        unk_48->sub_reset();
        unk_48->m_flags &= ~0x400;
        PlayEnemyAnime(1);
        unk_4E = 1;
        break;
    case 1:
        if (unk_48->GetAnimState() == 0) {
            ((CFieldEnemy *)unk_48)->EnableTargetObject();
            unk_48->m_flags |= 1;
            unk_48->m_flags |= 0x200;
            unk_4E = 2;
        }
        break;
    case 2:
        break;
    }
    return 0;
}

int CFieldPokeMove::ov0_02155B88()
{
    ((CFieldEnemy *)unk_48)->DisableTargetObject();
    unk_48->m_flags &= ~1;
    unk_48->m_flags &= ~0x200;
    unk_48->m_flags |= 0x400;
    unk_48->sub_show();
    SetSequence(1);
    return 0;
}

int CFieldPokeMove::ov0_02155C20()
{
    switch (unk_4E) {
    case 0:
        ((CFieldEnemy *)unk_48)->DisableTargetObject();
        unk_48->m_flags &= ~1;
        unk_48->m_flags &= ~0x200;
        if (unk_B0 != 0x1C7) {
            PlayCry();
        }
        PlayEnemyAnime(0);
        unk_4E = 1;
        break;
    case 1:
        if (unk_48->GetAnimState() == 0) {
            unk_48->m_flags |= 0x400;
            unk_48->sub_show();
            SetSequence(1);
        }
        break;
    }
    return 0;
}

int CFieldPokeMove::ov0_02155D38()
{
    if (IsTouchingPlayer()) {
        fx32 dx = unk_AC->GetPos().x - unk_0C.x;
        fx32 dy = unk_AC->GetPos().y - unk_0C.y;
        fx32 inv = FX_InvSqrt(FX32_MUL(dx, dx) + FX32_MUL(dy, dy));
        unk_AC->KnockBack(FX32_MUL(dx, inv), FX32_MUL(dy, inv), 10, unk_6C.unk_27, -1);
    }
    return 0;
}

int CFieldPokeMove::ov0_02155EA0()
{
    BOOL busy = TRUE;
    switch (unk_4E) {
    case 0:
        unk_48->sub_reset();
        PlayEnemyAnime(1);
        unk_4E = 1;
        unk_50 = 60;
        break;
    case 1:
        if (unk_50 <= 0) {
            unk_4E = 2;
            busy = FALSE;
        }
        break;
    case 2:
        busy = FALSE;
        unk_48->m_flags &= ~0x400;
        BeginSequence();
        unk_30.x = FX_CosIdx(unk_48->GetDir());
        unk_30.y = FX_SinIdx(unk_48->GetDir());
        unk_38 = unk_04 - GetPos();
        fx32 inv;
        inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
        unk_38.x = FX32_MUL(unk_38.x, inv);
        unk_38.y = FX32_MUL(unk_38.y, inv);
        unk_4C = unk_6C.unk_14;
        unk_4E = 3;
        break;
    case 3:
        unk_4E = 4;
        busy = FALSE;
        unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
        break;
    case 4:
        busy = FALSE;
        if (Move(&unk_24, unk_6C.unk_10, 10) != 0) {
            PlayEnemyAnime(0);
            unk_4E = 5;
            unk_50 = 60;
        }
        break;
    case 5:
        if (unk_50 <= 0) {
            unk_48->sub_show();
            unk_48->m_flags |= 0x400;
            SetSequence(1);
        }
        break;
    default:
        LogError("CFieldPokeMove Sequence Exception kabarudon");
        break;
    }
    unk_48->m_hasShadow = busy;
    return 0;
}

int CFieldPokeMove::ov0_02156194()
{
    switch (unk_4E) {
    case 0:
        ShowManpu(4, 30);
        PlayEnemyAnime(0);
        PlayCry();
        if (unk_48->GetAnimState() == -1) {
            unk_50 = 60;
            unk_4E = 1;
        } else {
            unk_4E = 2;
        }
        break;
    case 1:
        if (unk_50 <= 0) {
            SetSequence(1);
        }
        break;
    case 2:
        if (unk_48->GetAnimState() == 0) {
            SetSequence(1);
        }
        break;
    }
    return 0;
}

int CFieldPokeMove::ov0_02156290()
{
    switch (unk_4E) {
    case 0:
        BeginSequence();
        unk_30.x = FX_CosIdx(unk_48->GetDir());
        unk_30.y = FX_SinIdx(unk_48->GetDir());
        unk_48->PlayAnim(2, 0);
        unk_38 = GetPlayerPos() - (Point2D) { unk_0C.x, unk_0C.y };
        fx32 inv;
        inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
        unk_38.x = FX32_MUL(unk_38.x, inv);
        unk_38.y = FX32_MUL(unk_38.y, inv);
        SetUnk04(GetPlayerPos());
        unk_4C = unk_6C.unk_14;
        ShowManpu(8, 60);
        unk_4E = 1;
        break;
    case 1: {
        unk_38 = GetPlayerPos() - (Point2D) { unk_0C.x, unk_0C.y };
        fx32 inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
        unk_38.x = FX32_MUL(unk_38.x, inv);
        unk_38.y = FX32_MUL(unk_38.y, inv);
        SetUnk04(GetPlayerPos());
        TurnToward(&unk_30, &unk_38, unk_4C);
        unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
        break;
    }
    }
    return 0;
}

void CFieldPokeMove::SetSequence(int sequence)
{
    unk_44 = sequence;
    unk_4E = 0;
}

int CFieldPokeMove::ov0_0215675C()
{
    unk_48->sub_show();
    switch (unk_68) {
    case 1:
    case 2:
        unk_24.z -= unk_6C.unk_2E;
        if (unk_24.z < -0xA000) {
            unk_24.z = -0xA000;
        }
        unk_0C.z += unk_24.z;
        if (unk_0C.z < 0) {
            unk_0C.z = 0;
        }
        unk_48->SetBaseHeight(unk_0C.z);
        break;
    case 3: {
        fx32 s = FX_SinIdx((u16)unk_24.z);
        unk_0C.z = FX_MUL(s, unk_6C.unk_18 << FX32_SHIFT) + (unk_6C.unk_35 << FX32_SHIFT);
        unk_24.z += unk_6C.unk_16;
        unk_24.z &= 0xFFFF;
        unk_48->SetBaseHeight(unk_0C.z);
        break;
    }
    }
    return 0;
}

int CFieldPokeMove::ov0_02156898()
{
    switch (unk_4E) {
    case 0:
        BeginSequence();
        unk_30.x = FX_CosIdx(unk_48->GetDir());
        unk_30.y = FX_SinIdx(unk_48->GetDir());
        unk_38 = unk_04 - GetPos();
        fx32 inv;
        inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
        unk_38.x = FX32_MUL(unk_38.x, inv);
        unk_38.y = FX32_MUL(unk_38.y, inv);
        unk_4C = unk_6C.unk_14;
        unk_4E = 1;
        break;
    case 1:
        if (unk_6C.unk_3C == 0) {
            if (TurnToward(&unk_30, &unk_38, unk_4C)) {
                unk_4E = 2;
            }
        } else {
            unk_4E = 2;
        }
        unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
        break;
    case 2: {
        int next = Move(&unk_24, unk_6C.unk_0C, -1);
        if (next != 0) {
            SetSequence(next);
        }
        break;
    }
    default:
        LogError("CFieldPokeMove Sequence Exception");
        break;
    }
    return 0;
}

void CFieldPokeMove::BeginSequence()
{
    unk_0C.x = unk_48->GetX();
    unk_0C.y = unk_48->GetY();
    unk_0C.z = unk_48->GetBaseHeight();
    unk_54 = 1;
    unk_58 = 0;
    unk_5C = 0;
    unk_60 = 0;
    unk_40 = 0;
}

int CFieldPokeMove::Move(PokeMoveVec *vel, fx32 speed, int mode)
{
    if (mode == -1) {
        mode = unk_68;
    }
    switch (mode) {
    case 5:
        return ov0_02156BC0(vel, speed);
    case 0:
        return ov0_02156BE4(vel, speed);
    case 9:
        return ov0_02156BE4(vel, speed);
    case 1:
        return ov0_02156E68(vel, speed);
    case 2:
        return ov0_021572F4(vel, speed);
    case 3:
        return ov0_02157764(vel, speed);
    case 4:
        return ov0_02157A70(vel, speed);
    case 10:
        return ov0_02157CF4(vel, speed);
    case 6:
    case 7:
    case 8:
    default:
        return ov0_02156BE4(vel, speed);
    }
}

int CFieldPokeMove::ov0_02156BC0(PokeMoveVec *vel, fx32 speed)
{
    if (unk_54 != 0) {
        unk_54--;
    }
    SetSequence(6);
    return 0;
}

int CFieldPokeMove::ov0_02156BE4(PokeMoveVec *vel, fx32 speed)
{
    BOOL done = FALSE;
    if (IsNearTarget(speed)) {
        unk_58 = 1;
    }
    if (unk_54 != 0 && --unk_54 == 0) {
        unk_48->sub_reset();
        unk_48->PlayAnim(4, 0);
    }
    unk_38 = unk_04 - GetPos();
    fx32 inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
    unk_38.x = FX32_MUL(unk_38.x, inv);
    unk_38.y = FX32_MUL(unk_38.y, inv);
    TurnToward(&unk_30, &unk_38, unk_4C);
    unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
    vel->x = FX32_MUL(unk_30.x, speed);
    vel->y = FX32_MUL(unk_30.y, speed);
    unk_18.x = unk_0C.x + vel->x;
    unk_18.y = unk_0C.y + vel->y;
    PointPair2D move;
    move.p1 = unk_0C;
    move.p2 = unk_18;
    if (IsBlocked(move, unk_64, unk_B4)) {
        unk_58 = 1;
        unk_5C = 1;
    } else {
        unk_48->SetPosXY(unk_18.x, unk_18.y);
        unk_0C = unk_18;
    }
    if (unk_58 != 0) {
        done = TRUE;
    }
    return done;
}

int CFieldPokeMove::ov0_02156E68(PokeMoveVec *vel, fx32 speed)
{
    BOOL done = FALSE;
    if (unk_54 != 0 && --unk_54 == 0) {
        unk_48->sub_reset();
        unk_48->PlayAnim(4, 0);
        unk_38 = unk_04 - (Point2D) { unk_0C.x, unk_0C.y };
        fx32 inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
        unk_38.x = FX32_MUL(unk_38.x, inv);
        unk_38.y = FX32_MUL(unk_38.y, inv);
        TurnToward(&unk_30, &unk_38, unk_4C);
        unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
        if (unk_0C.z == 0) {
            vel->z = unk_6C.unk_2C << FX32_SHIFT;
        }
    } else if (unk_54 == 0) {
        vel->x = FX32_MUL(unk_30.x, speed);
        vel->y = FX32_MUL(unk_30.y, speed);
        if (((int)unk_48->m_id >> 24 & 0xFF) == 6) {
            unk_38 = unk_04 - (Point2D) { unk_0C.x, unk_0C.y };
            fx32 inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
            unk_38.x = FX32_MUL(unk_38.x, inv);
            unk_38.y = FX32_MUL(unk_38.y, inv);
            TurnToward(&unk_30, &unk_38, unk_4C);
            unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
            vel->x = FX32_MUL(unk_30.x, (fx64)speed);
            vel->y = FX32_MUL(unk_30.y, (fx64)speed);
        }
        vel->z -= unk_6C.unk_2E;
        if (unk_24.z < -0xA000) {
            unk_24.z = -0xA000;
        }
        SetNextR(this, unk_0C + *vel);
        if (unk_18.z < 0) {
            unk_54 = 10;
            unk_18.z = 0;
        }
        PointPair2D move;
        move.p1 = unk_0C;
        move.p2 = unk_18;
        if (IsBlocked(move, unk_64, unk_B4)) {
            unk_5C = 1;
            unk_58 = 1;
            unk_0C.z = unk_18.z;
            unk_48->SetBaseHeight(unk_18.z);
        } else {
            unk_48->SetPosXY(unk_18.x, unk_18.y);
            unk_48->SetBaseHeight(unk_18.z);
            CommitNext(this);
        }
        if (IsNearTarget(speed)) {
            unk_58 = 1;
        }
        if (unk_58 != 0 && unk_0C.z == 0) {
            done = TRUE;
        }
    }
    return done;
}

PokeMoveVec PokeMoveVec::operator+(const PokeMoveVec &other) const
{
    return PokeMoveVec(x + other.x, y + other.y, z + other.z);
}

int CFieldPokeMove::ov0_021572F4(PokeMoveVec *vel, fx32 speed)
{
    BOOL done = FALSE;
    if (unk_54 != 0 && --unk_54 == 0) {
        unk_48->sub_reset();
        unk_48->PlayAnim(4, 0);
        unk_38 = unk_04 - (Point2D) { unk_0C.x, unk_0C.y };
        fx32 inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
        unk_38.x = FX32_MUL(unk_38.x, inv);
        unk_38.y = FX32_MUL(unk_38.y, inv);
        TurnToward(&unk_30, &unk_38, unk_4C);
        unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
        if (unk_0C.z == 0) {
            vel->z = unk_6C.unk_2C << FX32_SHIFT;
        }
    } else if (unk_54 == 0) {
        vel->x = FX32_MUL(unk_30.x, speed);
        vel->y = FX32_MUL(unk_30.y, speed);
        if (((int)unk_48->m_id >> 24 & 0xFF) == 6) {
            unk_38 = unk_04 - (Point2D) { unk_0C.x, unk_0C.y };
            fx32 inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
            unk_38.x = FX32_MUL(unk_38.x, inv);
            unk_38.y = FX32_MUL(unk_38.y, inv);
            TurnToward(&unk_30, &unk_38, unk_4C);
            unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
            vel->x = FX32_MUL(unk_30.x, (fx64)speed);
            vel->y = FX32_MUL(unk_30.y, (fx64)speed);
        }
        vel->z -= unk_6C.unk_2E;
        if (unk_24.z < -0x64000) {
            unk_24.z = -0x64000;
        }
        SetNextR(this, unk_0C + *vel);
        if (unk_18.z < 0) {
            unk_48->PlayAnim(2, 0);
            unk_54 = 30;
            unk_18.z = 0;
        }
        PointPair2D move;
        move.p1 = unk_0C;
        move.p2 = unk_18;
        if (IsBlocked(move, unk_64, unk_B4)) {
            unk_5C = 1;
            unk_58 = 1;
            unk_0C.z = unk_18.z;
            unk_48->SetBaseHeight(unk_18.z);
        } else {
            unk_48->SetPosXY(unk_18.x, unk_18.y);
            unk_48->SetBaseHeight(unk_18.z);
            CommitNext(this);
        }
        if (IsNearTarget(speed)) {
            unk_58 = 1;
        }
        if (unk_58 != 0 && unk_0C.z == 0) {
            done = TRUE;
        }
    }
    return done;
}

int CFieldPokeMove::ov0_02157764(PokeMoveVec *vel, fx32 speed)
{
    BOOL done = FALSE;
    unk_B4 |= 2;
    if (IsNearTarget(speed)) {
        unk_58 = 1;
    }
    if (unk_54 != 0 && --unk_54 == 0) {
        unk_48->sub_reset();
        unk_48->PlayAnim(4, 0);
    }
    unk_38 = unk_04 - GetPos();
    fx32 inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
    unk_38.x = FX32_MUL(unk_38.x, inv);
    unk_38.y = FX32_MUL(unk_38.y, inv);
    TurnToward(&unk_30, &unk_38, unk_4C);
    unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
    vel->x = FX32_MUL(unk_30.x, speed);
    vel->y = FX32_MUL(unk_30.y, speed);
    unk_18.x = unk_0C.x + vel->x;
    unk_18.y = unk_0C.y + vel->y;
    PointPair2D move;
    move.p1 = unk_0C;
    move.p2 = unk_18;
    if (IsBlocked(move, unk_64, unk_B4)) {
        unk_58 = 1;
        unk_5C = 1;
    } else {
        unk_48->SetPosXY(unk_18.x, unk_18.y);
        unk_0C = unk_18;
    }
    fx32 s = FX_SinIdx((u16)unk_24.z);
    unk_0C.z = FX_MUL(s, unk_6C.unk_18 << FX32_SHIFT) + (unk_6C.unk_35 << FX32_SHIFT);
    unk_24.z += unk_6C.unk_16;
    unk_24.z &= 0xFFFF;
    unk_48->SetBaseHeight(unk_0C.z);
    if (unk_58 != 0) {
        done = TRUE;
    }
    return done;
}

int CFieldPokeMove::ov0_02157A70(PokeMoveVec *vel, fx32 speed)
{
    BOOL done = FALSE;
    if (IsNearTarget(speed)) {
        unk_58 = 1;
    }
    if (unk_54 != 0 && --unk_54 == 0) {
        unk_48->sub_reset();
        unk_48->PlayAnim(4, 0);
    }
    unk_38 = unk_04 - GetPos();
    fx32 inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
    unk_38.x = FX32_MUL(unk_38.x, inv);
    unk_38.y = FX32_MUL(unk_38.y, inv);
    TurnToward(&unk_30, &unk_38, unk_4C);
    unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
    vel->x = FX32_MUL(unk_30.x, speed);
    vel->y = FX32_MUL(unk_30.y, speed);
    unk_18.x = unk_0C.x + vel->x;
    unk_18.y = unk_0C.y + vel->y;
    PointPair2D move;
    move.p1 = unk_0C;
    move.p2 = unk_18;
    if (IsBlocked(move, unk_64, unk_B4)) {
        unk_58 = 1;
        unk_5C = 1;
    } else {
        unk_48->SetPosXY(unk_18.x, unk_18.y);
        unk_0C = unk_18;
    }
    if (unk_58 != 0) {
        done = TRUE;
    }
    return done;
}

int CFieldPokeMove::ov0_02157CF4(PokeMoveVec *vel, fx32 speed)
{
    BOOL done = FALSE;
    if (IsNearTarget(speed)) {
        unk_58 = 1;
    }
    if (unk_54 != 0 && --unk_54 == 0) {
        unk_48->sub_reset();
    }
    unk_38 = unk_04 - GetPos();
    fx32 len = ApproxLength(unk_38.x, unk_38.y);
    unk_38.x = FX32_DIV(unk_38.x, len);
    unk_38.y = FX32_DIV(unk_38.y, len);
    TurnToward(&unk_30, &unk_38, unk_4C);
    unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
    vel->x = FX32_MUL(unk_30.x, speed);
    vel->y = FX32_MUL(unk_30.y, speed);
    unk_18.x = unk_0C.x + vel->x;
    unk_18.y = unk_0C.y + vel->y;
    unk_48->SetPosXY(unk_18.x, unk_18.y);
    unk_0C = unk_18;
    if (unk_58 != 0) {
        done = TRUE;
    }
    return done;
}

BOOL CFieldPokeMove::TurnToward(Point2D *dir, Point2D *target, u16 maxAngle)
{
    if (target->x == 0 && target->y == 0) {
        return TRUE;
    }
    fx32 dot = DotProduct(dir, target);
    if (FX_CosIdx(maxAngle) < dot + 100) {
        *dir = *target;
        return TRUE;
    }
    Point2D r;
    if (CrossProduct(dir, target) >= 0) {
        r.x = FX32_MUL(dir->x, FX_CosIdx(maxAngle)) - FX32_MUL(dir->y, FX_SinIdx(maxAngle));
        r.y = FX32_MUL(dir->x, FX_SinIdx(maxAngle)) + FX32_MUL(dir->y, FX_CosIdx(maxAngle));
    } else {
        r.x = FX32_MUL(dir->x, FX_CosIdx(maxAngle)) - FX32_MUL(dir->y, -FX_SinIdx(maxAngle));
        r.y = FX32_MUL(dir->x, -FX_SinIdx(maxAngle)) + FX32_MUL(dir->y, FX_CosIdx(maxAngle));
    }
    Length(r.x, r.y);
    Length(dir->x, dir->y);
    *dir = r;
    return FALSE;
}

int CFieldPokeMove::GetTargetDistSq()
{
    int dx = (unk_04.x - unk_0C.x) >> FX32_SHIFT;
    int dy = (unk_04.y - unk_0C.y) >> FX32_SHIFT;
    return dx * dx + dy * dy;
}

fx32 CFieldPokeMove::Distance(fx32 x1, fx32 y1, fx32 x2, fx32 y2)
{
    fx32 dx = x1 - x2;
    fx32 dy = y1 - y2;
    return FX_Sqrt(FX32_MUL(dx, dx) + FX32_MUL(dy, dy));
}

fx32 CFieldPokeMove::Length(fx32 x, fx32 y)
{
    return FX_Sqrt(FX32_MUL(x, x) + FX32_MUL(y, y));
}

int CFieldPokeMove::PlayEnemyAnime(int anim)
{
    if (anim >= 0 && anim < 3) {
        u8 kind;
        switch (anim) {
        case 0:
            kind = unk_6C.unk_38;
            break;
        case 1:
            kind = unk_6C.unk_39;
            break;
        case 2:
            kind = unk_6C.unk_3A;
            break;
        default:
            kind = 0;
            break;
        }
        switch (kind) {
        case 0:
            return -1;
        case 1:
            unk_48->PlayAnim(0x20, 0);
            return 0;
        case 2:
            unk_48->PlayAnim(0x20, 1);
            return 0;
        case 3:
            unk_48->PlayAnim(0x20, 2);
            return 0;
        case 4:
            unk_48->PlayAnim(0x20, 3);
            return 0;
        case 5:
            unk_48->PlayAnim(0x10, 0);
            return 0;
        case 6:
            unk_48->PlayAnim(0x10, 1);
            return 0;
        case 7:
            unk_48->PlayAnim(8, 0);
            return 0;
        }
    } else {
        LogError("ERROR : FieldPokeMove.cpp PlayEnemyAnime ");
    }
    return -1;
}

void CFieldPokeMove::PlayCry()
{
    s_game->m_audioEngine->PlayStream(unk_B0, 0x40);
}

void CFieldPokeMove::PlayGroupSe(int group, int index)
{
    s_game->m_audioEngine->PlayGroupSe(group, index);
}

int CFieldPokeMove::ShowManpu(int type, int arg)
{
    return Actor_ShowManpu(unk_48, type, arg);
}

BOOL CFieldPokeMove::IsInSight(Point2D from, Point2D to, int range, Point2D dir, int angle)
{
    if (angle == 0) {
        return FALSE;
    }
    angle /= 2;
    if (range * range < unk_C8) {
        return FALSE;
    }
    BOOL back = FALSE;
    if (angle >= 180) {
        return TRUE;
    }
    if (angle >= 90) {
        angle = 180 - angle;
        dir.x = -dir.x;
        dir.y = -dir.y;
        back = TRUE;
    }
    fx32 dx = to.x - from.x;
    fx32 dy = to.y - from.y;
    fx32 len = FX_Sqrt(FX32_MUL(dx, dx) + FX32_MUL(dy, dy));
    fx32 dot = FX32_MUL(dx, dir.x) + FX32_MUL(dy, dir.y);
    dot = FX32_DIV(dot, len);
    u16 idx = FX_Div(angle << 16, 360 * FX32_ONE);
    if (FX_CosIdx(idx) < dot) {
        return back == TRUE ? FALSE : TRUE;
    }
    return back == TRUE ? TRUE : FALSE;
}

BOOL CFieldPokeMove::IsTouchingPlayer()
{
    int r = (unk_6C.unk_1C + unk_AC->unk_E0) >> FX32_SHIFT;
    r *= r;
    return unk_C4 < r;
}

struct PokeMoveSave {
    u8 seq;
    u8 state;
    u8 done;
    u8 unk_03;
    PokeMoveVec pos;
    Point2D dir;
    PokeMoveVec vel;
    Point2D unk_24;
    Point2D target;
    u8 unk_34;
    u16 timer;
    u16 anim;
    u8 frame;
    u8 unk_3B;
    u32 flags;
};

static inline u16 GetAnimNoD(CFieldDrawObject *obj)
{
    if (obj->m_actor != NULL) {
        return obj->m_actor->GetAnimScriptPos();
    }
    return 0;
}

static inline u16 GetAnimNo(CFieldActor *actor)
{
    if (actor->m_drawObject != NULL) {
        return GetAnimNoD(actor->m_drawObject);
    }
    return 0;
}

static inline u8 GetAnimFrameD(CFieldDrawObject *obj)
{
    if (obj->m_actor != NULL) {
        return obj->m_actor->GetAnimLoopCount();
    }
    return 0;
}

static inline u8 GetAnimFrame(CFieldActor *actor)
{
    if (actor->m_drawObject != NULL) {
        return GetAnimFrameD(actor->m_drawObject);
    }
    return 0;
}

static inline void SetShown(CFieldActor *actor, BOOL shown)
{
    if (shown) {
        actor->sub_show();
    } else {
        actor->sub_reset();
    }
}

static inline void SetSpriteXY(CFieldActor *actor, fx32 x, fx32 y)
{
    if (actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL && actor->m_drawObject->m_actor->m_sprite != NULL) {
        actor->m_drawObject->m_actor->m_sprite->SetXY(x, y);
    }
}

static inline void SetUnkC0(CFieldActor *actor, u8 value)
{
    if (actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
        actor->m_drawObject->m_actor->unk_C0 = value;
    }
}

int CFieldPokeMove::SaveState(void *buf, void *end)
{
    PokeMoveSave save;
    MI_CpuFill8(&save, 0, sizeof(save));
    save.seq = unk_44;
    save.state = unk_4E;
    save.done = unk_58;
    save.unk_03 = unk_54;
    save.pos = unk_0C;
    save.dir = unk_30;
    save.vel = unk_24;
    save.unk_24 = unk_38;
    save.target = unk_04;
    save.unk_34 = unk_D0;
    save.timer = unk_50;
    save.anim = GetAnimNo(unk_48);
    save.frame = GetAnimFrame(unk_48);
    save.unk_3B = unk_48->GetUnkC0();
    save.flags = unk_48->m_flags;
    if (PTR_CAST(u32, buf) + sizeof(save) > PTR_CAST(u32, end)) {
        return 0;
    }
    MI_CpuCopy8(&save, buf, sizeof(save));
    return sizeof(save);
}

BOOL CFieldPokeMove::RestoreState(void *data)
{
    PokeMoveSave *save = (PokeMoveSave *)data;
    unk_44 = save->seq;
    unk_4E = save->state;
    unk_58 = save->done;
    unk_54 = save->unk_03;
    unk_0C = save->pos;
    unk_48->SetBaseHeight(unk_0C.z);
    SetSpriteXY(unk_48, unk_0C.x, unk_0C.y - unk_0C.z);
    unk_30 = save->dir;
    unk_24 = save->vel;
    unk_38 = save->unk_24;
    unk_04 = save->target;
    unk_D0 = save->unk_34;
    unk_50 = save->timer;
    SetUnkC0(unk_48, save->unk_3B);
    if (unk_48->m_drawObject != NULL && unk_48->m_drawObject->m_actor != NULL) {
        unk_48->m_drawObject->m_actor->RestartAnim();
    }
    if (unk_48->m_drawObject != NULL && unk_48->m_drawObject->m_actor != NULL) {
        unk_48->m_drawObject->m_actor->GetAnimScriptPos();
    }
    if (unk_48->m_drawObject != NULL && unk_48->m_drawObject->m_actor != NULL) {
        unk_48->m_drawObject->m_actor->GetAnimLoopCount();
    }
    int count = 0xFFFF;
    while (count--) {
        if (unk_48->m_drawObject != NULL && unk_48->m_drawObject->m_actor != NULL) {
            unk_48->m_drawObject->m_actor->UpdateAnimBank();
        }
        u16 anim = GetAnimNo(unk_48);
        u8 frame = GetAnimFrame(unk_48);
        if (anim == save->anim && frame == save->frame) {
            break;
        }
    }
    unk_48->m_flags = 0;
    unk_48->m_flags |= save->flags;
    SetShown(unk_48, (unk_48->m_flags & 8) ? TRUE : FALSE);
    if (unk_48->m_flags & 0x800) {
        ((CFieldEnemy *)unk_48)->EnableTargetObject();
    } else {
        ((CFieldEnemy *)unk_48)->DisableTargetObject();
    }
    return TRUE;
}

BOOL CFieldPokeMove::IsBlockedAhead(Point2D dir, fx32 scale)
{
    PointPair2D move;
    move.p1 = unk_0C;
    move.p2.x = unk_0C.x + FX32_MUL(dir.x, scale);
    move.p2.y = unk_0C.y + FX32_MUL(dir.y, scale);
    return IsBlocked(move, unk_64, unk_B4) ? TRUE : FALSE;
}

BOOL CFieldPokeMove::CollidesAt(const Point2D &pos, fx32 radius, u32 flags)
{
    if (unk_BC == 0) {
        return FALSE;
    }
    return unk_48->CheckCircleCollision(pos, radius, flags);
}

void CFieldPokeMove::StopPuddles()
{
    if (unk_B8 != 0 && MAIN_BSS_0210CA60 != NULL) {
        CFieldEffectSlime *slime = (CFieldEffectSlime *)MAIN_BSS_0210CA60->Get(unk_B8);
        if (slime != NULL) {
            slime->StopPuddles();
        }
    }
}

void CFieldPokeMove::UpdateHeight()
{
    unk_D4 ^= 0xFF;
    if (s_game->unk_146C.GetFps() == 60 && unk_D4 == 0) {
        return;
    }
    switch (unk_44) {
    case 1:
    case 3:
    case 4:
    case 9:
        switch (unk_68) {
        case 3: {
            fx32 s = FX_SinIdx((u16)unk_24.z);
            unk_0C.z = FX_MUL(s, unk_6C.unk_18 << FX32_SHIFT) + (unk_6C.unk_35 << FX32_SHIFT);
            unk_24.z += unk_6C.unk_16;
            unk_24.z &= 0xFFFF;
            unk_48->SetBaseHeight(unk_0C.z);
            break;
        }
        case 1:
        case 2:
            unk_24.z -= unk_6C.unk_2E;
            if (unk_24.z < -0x64000) {
                unk_24.z = -0x64000;
            }
            unk_0C.z += unk_24.z;
            if (unk_0C.z < 0) {
                unk_0C.z = 0;
            }
            unk_48->SetBaseHeight(unk_0C.z);
            break;
        }
        break;
    case 25:
        if (unk_68 == 3) {
            unk_0C.z = unk_6C.unk_35 << FX32_SHIFT;
            unk_48->SetBaseHeight(unk_0C.z);
        }
        break;
    }
}

BOOL CFieldPokeMove::IsNearTarget(fx32 radius)
{
    int r = radius >> FX32_SHIFT;
    int limit;
    if (r < 1) {
        limit = 1;
    } else {
        limit = r * r;
    }
    return GetTargetDistSq() <= limit;
}

void CFieldPokeMove::SpawnGroundEffect(int arg1)
{
    CFieldEffectManage *manage = MAIN_BSS_0210CA60;
    if (manage == NULL) {
        return;
    }
    CFieldActor *actor = unk_48;
    fx32 x = actor->GetX();
    fx32 y = actor->GetY();
    int cell = 0;
    if (actor->m_map != NULL) {
        CFieldMapLayerAttribute *attr = actor->m_map->GetAttributeLayer(actor->m_layer);
        if (attr != NULL) {
            cell = attr->GetCellAtPos(x, y);
        }
    }
    CFieldEffect *effect;
    switch (cell) {
    case 0:
        break;
    case 1:
    case 6:
        effect = manage->Get(manage->Create(0xB, 0));
        if (effect == NULL) {
            return;
        }
        effect->SetParam(0, 8);
        effect->SetParam(8, 20);
        effect->SetParam(1, x >> FX32_SHIFT);
        effect->SetParam(2, y >> FX32_SHIFT);
        effect->SetParam(3, 0);
        effect->SetParam(4, 0);
        effect->Start(0, -1, 0);
        break;
    case 3:
    case 4:
    case 8:
        effect = manage->Get(manage->Create(0xA, 0));
        if (effect == NULL) {
            return;
        }
        effect->SetParam(0, 16);
        effect->SetParam(1, x >> FX32_SHIFT);
        effect->SetParam(2, (y >> FX32_SHIFT) + 8);
        effect->SetParam(3, 16);
        effect->SetParam(4, 0);
        effect->Start(0, -1, 0);
        break;
    case 2:
    case 5:
        effect = manage->Get(manage->Create(0x26, 0));
        if (effect == NULL) {
            return;
        }
        effect->SetParam(1, x >> FX32_SHIFT);
        effect->SetParam(2, (y >> FX32_SHIFT) + 8);
        effect->Start(0, -1, 0);
        break;
    case 7:
    case 9:
    case 10:
        break;
    case 11:
        effect = manage->Get(manage->Create(0xA, 0));
        if (effect == NULL) {
            return;
        }
        effect->SetParam(0, 16);
        effect->SetParam(1, x >> FX32_SHIFT);
        effect->SetParam(2, (y >> FX32_SHIFT) + 8);
        effect->SetParam(3, 16);
        effect->SetParam(4, 0);
        effect->SetParam(19, 1);
        effect->Start(0, -1, 0);
        break;
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
        break;
    }
}

void CFieldPokeMove::ApplyFloatHeight()
{
    switch (unk_44) {
    case 1:
    case 3:
    case 4:
    case 9:
        if (unk_68 == 3) {
            fx32 x = unk_48->GetX();
            fx32 y = unk_48->GetY();
            fx32 h = unk_6C.unk_35 << FX32_SHIFT;
            unk_48->SetBaseHeight(h);
            SetSpriteXY(unk_48, x, y - h);
        }
        break;
    }
}
