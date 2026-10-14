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

static u16 GetFieldFps();

int CFieldPokeMove::ov0_0215900C()
{
    unk_4C = 0x8000;
    CFieldActor *owner = unk_48;
    unk_0C.x = unk_48->GetPos().x;
    unk_0C.y = unk_48->GetPos().y;
    unk_B4 |= 8;
    unk_64 = 0x10000;
    switch (unk_4E) {
    case 0: {
        ov0_02156A8C();
        unk_30.x = FX_CosIdx(unk_48->GetDir());
        unk_30.y = FX_SinIdx(unk_48->GetDir());
        unk_38 = unk_04 - (Point2D) { unk_0C.x, unk_0C.y };
        fx32 inv = FX_InvSqrt(FX32_MUL(unk_38.x, unk_38.x) + FX32_MUL(unk_38.y, unk_38.y));
        unk_38.x = FX32_MUL(unk_38.x, inv);
        unk_38.y = FX32_MUL(unk_38.y, inv);
        unk_4C = 0xFFF;
        unk_4E = 1;
        break;
    }
    case 1:
        if (unk_6C.unk_3C == 0) {
            if (ov0_02157F0C(&unk_30, &unk_38, unk_4C)) {
                unk_4E = 2;
            }
        } else {
            unk_4E = 2;
        }
        unk_48->sub_020128EC_(FX_Atan2Idx(unk_30.y, unk_30.x));
        if (unk_68 == 1 || unk_68 == 2) {
            fx32 t = FX32_DIV(unk_6C.unk_2C << FX32_SHIFT, unk_6C.unk_2E) * 2;
            if (t < 0x1000) {
                t = 0x1000;
            }
            unk_D8 = FX32_DIV(ov0_0215809C(unk_04.x, unk_04.y, unk_48->GetPos().x, unk_48->GetPos().y), t);
        }
        break;
    case 2:
        if (unk_40 != 0) {
            ov0_0215674C(1);
        } else {
            int mul = GetFieldFps() == 60 ? 1 : 2;
            Point2D d = unk_04;
            d -= unk_48->GetPos();
            fx32 distSq = FX32_MUL(d.x, d.x) + FX32_MUL(d.y, d.y);
            fx32 speed;
            if (((CFieldPartner *)owner)->unk_1EC == 1) {
                if (distSq > 0x4000000) {
                    speed = mul * FX32_MUL(unk_AC->unk_10, (fx64)0x3800);
                } else {
                    speed = mul * FX32_MUL(unk_AC->unk_10, (fx64)0x2800);
                }
            } else if (distSq > 0x4000000) {
                speed = mul * FX32_MUL(unk_AC->unk_10, (fx64)0x3800);
            } else if (unk_68 == 1) {
                speed = mul * FX32_MUL(unk_AC->unk_10, (fx64)0x1CCC);
            } else if (unk_68 == 2) {
                speed = mul * FX32_MUL(unk_AC->unk_10, (fx64)0x2666);
            } else {
                speed = mul * FX32_MUL(unk_AC->unk_10, (fx64)0x1333);
            }
            if (unk_68 == 1 || unk_68 == 2) {
                if (unk_0C.z == 0) {
                    fx32 t = FX32_DIV(unk_6C.unk_2C << FX32_SHIFT, unk_6C.unk_2E) * 2;
                    if (t < 0x1000) {
                        t = 0x1000;
                    }
                    unk_D8 = FX32_DIV(ov0_0215809C(unk_04.x, unk_04.y, unk_48->GetPos().x, unk_48->GetPos().y), t);
                    if (unk_D8 < 0x1000) {
                        unk_D8 = 0x1000;
                    }
                }
                speed = unk_D8;
            }
            if (distSq <= FX32_MUL(speed, speed) || distSq <= 0x1000) {
                unk_48->SetPos(unk_04);
                unk_0C.x = unk_48->GetPos().x;
                unk_0C.y = unk_48->GetPos().y;
                unk_40 = 1;
                ov0_0215674C(1);
            } else {
                ov0_02156B30(&unk_24, speed, -1);
            }
        }
        break;
    default:
        LogError("CFieldPokeMove Sequence Exception");
        break;
    }
    return 0;
}

static u16 GetFieldFps()
{
    return DAT_0208d58c;
}
