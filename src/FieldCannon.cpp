#include "AudioEngine.hpp"
#include "CGame.hpp"
#include "Collision.hpp"
#include "FieldCannons.hpp"
#include "FieldScriptLauncher.hpp"
#include "MathUtil.hpp"
#include "SaveData.hpp"
#include "field/CFieldCannon.hpp"
#include "field/CFieldPlayer.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;
extern FieldScriptLauncher *MAIN_BSS_0210CA44;
extern CFieldPlayer *MAIN_BSS_0210CA48;
extern SaveData MAIN_BSS_020B26A0;

static CFieldCannonUnit *sCannonUnit;

static inline Point2D GetCannonPos(int i)
{
    Point2D pos = { MAIN_BSS_020B26A0.unk_8436[i] << FX32_SHIFT, MAIN_BSS_020B26A0.unk_8436[i + 0x50] << FX32_SHIFT };
    return pos;
}

static inline void SetCannonShot(int i, Point2D pos, u16 angle, fx32 speed, u16 data)
{
    MAIN_BSS_020B26A0.unk_8436[i] = pos.x >> FX32_SHIFT;
    MAIN_BSS_020B26A0.unk_84D6[i] = pos.y >> FX32_SHIFT;
    MAIN_BSS_020B26A0.unk_8616[i] = angle;
    MAIN_BSS_020B26A0.unk_8576[i] = speed >> FX32_SHIFT;
    MAIN_BSS_020B26A0.unk_86B6[i] = data;
}

FieldCannons::FieldCannons()
{
    unk_00 = 0;
    unk_02 = 0;
}

FieldCannons::~FieldCannons()
{
    ov0_02159D70();
}

void FieldCannons::ov0_02159970()
{
    SaveData *save = &MAIN_BSS_020B26A0;
    if (MAIN_BSS_020B26A0.unk_81B0 != 6) {
        return;
    }
    for (int i = 0x20; i < 0x50; i++) {
        u8 frame;
        u16 index = 0;
        u16 unit = 0;
        if (i > 0x20) {
            index = (i - 0x20) / 4;
            unit = (i - 0x20) % 4;
        }
        u32 flags = save->unk_81B4[i & 0x3FF];
        if (((flags & 1) ? TRUE : FALSE) && ((flags >> 1) & 0x7F) == 6) {
            FieldCannonParam param;
            param.unk_00 = save->unk_8616[i];
            param.unk_04 = (save->unk_86B6[i] >> 8) & 0xFF;
            param.unk_06 = 0;
            param.unk_08 = save->unk_86B6[i] & 0xFF;
            param.unk_0A = save->unk_81B4[i & 0x3FF] >> 20;
            frame = save->unk_81B4[i & 0x3FF] >> 12;
            param.unk_0C = 1;
            param.unk_0E = 0;
            param.unk_10 = save->unk_8576[i] << FX32_SHIFT;
            param.unk_14.pos = GetCannonPos(i);
            param.unk_14.r = FX32_CONST(16);
            CFieldCannon *cannon;
            if (unk_00 & (1 << index)) {
                cannon = ov0_02159DFC(index);
            } else {
                cannon = ov0_02159DFC(ov0_02159B84(save->unk_8434, index, 1));
            }
            cannon->ov0_0215A434(&param, frame, unit);
            cannon->ov0_0215A384(TRUE);
        }
    }
}

int FieldCannons::ov0_02159B24()
{
    for (int i = 0; i < 10; i++) {
        if ((unk_00 & (1 << i)) && !(unk_02 & (1 << i))) {
            return i;
        }
    }
    return -1;
}

int FieldCannons::ov0_02159B5C()
{
    for (int i = 0; i < 10; i++) {
        if (!(unk_00 & (1 << i))) {
            return i;
        }
    }
    return -1;
}

int FieldCannons::ov0_02159B84(int type, int index, int mode)
{
    if (mode == 1) {
        MAIN_BSS_020B26A0.unk_8434 = type;
        CFieldCannon *cannon = new CFieldCannon(type);
        if (cannon == NULL) {
            return -1;
        }
        if (unk_00 & (1 << index)) {
            return -1;
        }
        cannon->unk_E4 = index;
        unk_04[index] = cannon;
        unk_00 |= 1 << index;
        return index;
    }
    int slot = ov0_02159B24();
    if (mode == 0 && slot == -1) {
        MAIN_BSS_020B26A0.unk_8434 = type;
        CFieldCannon *cannon = new CFieldCannon(type);
        if (cannon == NULL) {
            return -1;
        }
        slot = ov0_02159B5C();
        if (slot == -1) {
            return -1;
        }
        cannon->unk_E4 = slot;
        unk_04[slot] = cannon;
        unk_00 |= 1 << slot;
        unk_02 |= 1 << slot;
        return slot;
    }
    unk_02 |= 1 << slot;
    return slot;
}

void FieldCannons::ov0_02159CA8()
{
    unk_00 = 0;
    unk_02 = 0;
    for (u16 i = 0; i < 10; i++) {
        SAFE_DELETE(unk_04[i]);
    }
    SAFE_DELETE(sCannonUnit);
}

void ov0_02159D30(u16 type)
{
    if (sCannonUnit == NULL) {
        sCannonUnit = new CFieldCannonUnit(type);
    }
}

void FieldCannons::ov0_02159D70()
{
    ov0_02159CA8();
}

void FieldCannons::ov0_02159D7C()
{
    for (u16 i = 0; i < 10; i++) {
        if (unk_04[i] != NULL) {
            unk_04[i]->ov0_0215A010();
        }
    }
}

void FieldCannons::ov0_02159DB4(DrawObjectList *renderLists, FieldShadow *hud)
{
    for (u16 i = 0; i < 10; i++) {
        if (unk_04[i] != NULL) {
            unk_04[i]->ov0_0215A25C(renderLists, hud);
        }
    }
}

CFieldCannon *FieldCannons::ov0_02159DFC(int index)
{
    if (index >= 10) {
        return NULL;
    }
    return unk_04[index];
}

CFieldCannon::CFieldCannon(u16 type)
{
    unk_EC = NULL;
    unk_E8 = CGame::GetInstance()->m_audioEngine;
    for (int i = 0; i < 4; i++) {
        unk_F0[i] = NULL;
    }
    unk_E2 = type;
    unk_E0 = 0;
    ov0_02159ED0();
}

CFieldCannon::~CFieldCannon()
{
    ov0_02159F28();
}

void CFieldCannon::ov0_02159ED0()
{
    ov0_02159F28();
    unk_EC = new FieldCannonParam;
    ov0_02159F88();
    for (int i = 0; i < 4; i++) {
        unk_F0[i] = new CFieldCannonUnit(unk_E2);
    }
}

void CFieldCannon::ov0_02159F28()
{
    SAFE_DELETE(unk_EC);
    for (int i = 0; i < 4; i++) {
        SAFE_DELETE(unk_F0[i]);
    }
}

void CFieldCannon::ov0_02159F88()
{
    if (unk_EC == NULL) {
        return;
    }
    unk_EC->unk_00 = 15000;
    unk_EC->unk_02 = 0;
    unk_EC->unk_04 = 0;
    unk_EC->unk_06 = 0;
    unk_EC->unk_08 = 0;
    unk_EC->unk_0A = 0;
    unk_EC->unk_0C = 0;
    unk_EC->unk_0E = 0x400;
    unk_EC->unk_10 = FX32_ONE;
    unk_EC->unk_14.pos.x = 0;
    unk_EC->unk_14.pos.y = 0;
    unk_EC->unk_14.r = FX32_CONST(16);
}

void CFieldCannon::ov0_0215A010()
{
    if (!ov0_0215A3A4()) {
        return;
    }
    if (ov0_0215A2BC()) {
        return;
    }
    if (!(unk_EC->unk_0C & 4)) {
        unk_E0++;
        if (unk_E0 == unk_EC->unk_02) {
            u16 index = 0;
            if (ov0_0215A33C(&index)) {
                unk_F0[index]->ov0_0215ABA4();
                unk_F0[index]->ov0_0215AAA4(unk_EC);
                unk_F0[index]->ov0_0215AA60(TRUE);
                unk_E8->PlayGroupSe(0x5C, 0x62);
            }
            unk_E0 = 0;
        }
    }
    SaveData *save = &MAIN_BSS_020B26A0;
    for (u16 i = 0; i < 4; i++) {
        u16 id = unk_E4 * 4 + 0x20 + i;
        FieldCannonUnitParam *param = unk_F0[i]->ov0_0215ABF0();
        if (unk_F0[i]->ov0_0215AA80()) {
            if (ov0_0215A3A4()) {
                if (!(param->unk_0A & 2)) {
                    u16 frame = unk_F0[i]->unk_E0;
                    u16 life = unk_F0[i]->ov0_0215ABF0()->unk_08;
                    fx32 speed = param->unk_10;
                    save->SetFlagKind(id & 0x3FF, 6);
                    save->SetFlagCount(id & 0x3FF, frame, 1);
                    save->SetFlagValue(id & 0x3FF, life);
                    SetCannonShot(id, param->unk_14.pos, param->unk_00, speed, (u8)param->unk_06 | ((u8)param->unk_02 << 8));
                }
                unk_F0[i]->ov0_0215A698();
                if (!unk_F0[i]->ov0_0215AA80()) {
                    save->unk_81B4[id & 0x3FF] = 0;
                }
            } else {
                unk_F0[i]->ov0_0215AA60(FALSE);
            }
        }
    }
}

void CFieldCannon::ov0_0215A25C(DrawObjectList *renderLists, FieldShadow *hud)
{
    if (!ov0_0215A3A4()) {
        return;
    }
    for (u16 i = 0; i < 4; i++) {
        if (unk_F0[i]->ov0_0215AA80()) {
            unk_F0[i]->Draw(renderLists, hud);
        }
    }
}

BOOL CFieldCannon::ov0_0215A2BC()
{
    BOOL ret = FALSE;
    FieldScriptLauncher *runner = MAIN_BSS_0210CA44;
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (runner != NULL && runner->ov0_0213FEEC()) {
        ret = TRUE;
    }
    if (scene != NULL) {
        int state = scene->unk_0084;
        if (!(!(scene->m_flags & 8) ? TRUE : FALSE) || state == 3 || state == 4 || state == 7 || state == 5
            || state == 6 || state == 8 || state == 9 || state == 0x14) {
            ret = TRUE;
        }
    }
    return ret;
}

BOOL CFieldCannon::ov0_0215A33C(u16 *index)
{
    for (u16 i = 0; i < 4; i++) {
        if (!unk_F0[i]->ov0_0215AA80()) {
            *index = i;
            return TRUE;
        }
    }
    return FALSE;
}

void CFieldCannon::ov0_0215A384(BOOL active)
{
    if (active) {
        unk_EC->unk_0C |= 1;
    } else {
        unk_EC->unk_0C &= ~1;
    }
}

BOOL CFieldCannon::ov0_0215A3A4()
{
    if (unk_EC->unk_0C & 1) {
        return TRUE;
    }
    return FALSE;
}

void CFieldCannon::ov0_0215A3BC(int x, int y)
{
    Point2D pos = { x << FX32_SHIFT, y << FX32_SHIFT };
    unk_EC->unk_14.pos = pos;
}

void CFieldCannon::ov0_0215A3D4(int angle, int speed, int interval, int arg4, int arg5, int arg6, int arg7, int arg8)
{
    unk_EC->unk_00 = angle;
    unk_EC->unk_10 = (u16)speed;
    unk_EC->unk_02 = interval;
    unk_EC->unk_04 = arg5;
    unk_EC->unk_06 = arg6;
    unk_EC->unk_08 = arg7;
    unk_EC->unk_0A = arg8;
    unk_EC->unk_14.r = arg4;
}

void CFieldCannon::ov0_0215A434(FieldCannonParam *param, u16 frame, u16 index)
{
    if (unk_F0[index] == NULL) {
        return;
    }
    unk_F0[index]->ov0_0215ABA4();
    unk_F0[index]->ov0_0215AAA4(param);
    unk_F0[index]->unk_E0 = frame;
    unk_F0[index]->ov0_0215AA60(TRUE);
    unk_F0[index]->SetPos(param->unk_14.pos);
}

CFieldCannonUnit::CFieldCannonUnit(u16 type)
{
    unk_E8 = NULL;
    unk_E2 = type;
    unk_E4 = MAIN_BSS_0210CA48;
    unk_E0 = 0;
    ov0_0215A5A4();
}

CFieldCannonUnit::~CFieldCannonUnit()
{
    ov0_0215A604();
}

void CFieldCannonUnit::ov0_0215A5A4()
{
    ov0_0215A604();
    unk_E8 = new FieldCannonUnitParam;
    ov0_0215A628();
    u16 id = 0;
    if (unk_E2 == 0) {
        id = 0x154;
    }
    if (unk_E2 == 1) {
        id = 0x174;
    }
    CreateDrawObject(2, id, 0, 6, 0);
}

void CFieldCannonUnit::ov0_0215A604()
{
    SAFE_DELETE(unk_E8);
}

void CFieldCannonUnit::ov0_0215A628()
{
    if (unk_E8 == NULL) {
        return;
    }
    unk_E8->unk_00 = 0;
    unk_E8->unk_02 = 0;
    unk_E8->unk_04 = 0;
    unk_E8->unk_06 = 0;
    unk_E8->unk_08 = 0;
    unk_E8->unk_0A = 0;
    unk_E8->unk_0C = 0x400;
    unk_E8->unk_10 = 0;
    unk_E8->unk_14.pos.x = 0;
    unk_E8->unk_14.pos.y = 0;
    unk_E8->unk_14.r = FX32_CONST(16);
}

void CFieldCannonUnit::ov0_0215A698()
{
    if (!(unk_E8->unk_0A & 1)) {
        return;
    }
    Point2D pos = GetPos();
    unk_E8->unk_14.pos = pos;
    if (unk_E8->unk_0A & 2) {
        if (GetAnimState() == 0) {
            ov0_0215AA60(FALSE);
        }
    } else {
        pos.x += FX32_MUL(unk_E8->unk_10, FX_CosIdx(unk_E8->unk_00));
        pos.y += FX32_MUL(unk_E8->unk_10, FX_SinIdx(unk_E8->unk_00));
        SetPos(pos);
        Circle area;
        area.pos = unk_E4->GetPos();
        area.r = unk_E4->unk_E0;
        if (!(unk_E4->unk_10C & 1) && CircleHitCircle(area, unk_E8->unk_14, NULL)) {
            PlayAnim(4, 0);
            unk_E8->unk_0A |= 2;
            Point2D playerPos = unk_E4->GetPos();
            ApproxLength(pos.x - playerPos.x, pos.y - playerPos.y);
            Point2D d = (const Point2D &)playerPos - pos;
            unk_E4->ov0_021333A0(d.x, d.y, unk_E8->unk_06, unk_E8->unk_02, -1);
        }
        if (!(unk_E8->unk_0A & 2)) {
            unk_E0++;
            if (unk_E0 == unk_E8->unk_08) {
                PlayAnim(4, 0);
                unk_E8->unk_0A |= 2;
            }
        }
    }
    Update(NULL);
}

void CFieldCannonUnit::ov0_0215AA60(BOOL active)
{
    if (active) {
        unk_E8->unk_0A |= 1;
    } else {
        unk_E8->unk_0A &= ~1;
    }
}

BOOL CFieldCannonUnit::ov0_0215AA80()
{
    if (unk_E8->unk_0A & 1) {
        return TRUE;
    }
    return FALSE;
}

void CFieldCannonUnit::ov0_0215AA98(u16 flags)
{
    unk_E8->unk_0A = flags;
}

void CFieldCannonUnit::ov0_0215AAA4(FieldCannonParam *param)
{
    if (unk_E8 == NULL) {
        return;
    }
    unk_E8->unk_00 = param->unk_00;
    unk_E8->unk_02 = param->unk_04;
    unk_E8->unk_04 = param->unk_06;
    unk_E8->unk_06 = param->unk_08;
    unk_E8->unk_08 = param->unk_0A;
    unk_E8->unk_0A = 0;
    unk_E8->unk_0C = param->unk_0E;
    unk_E8->unk_10 = param->unk_10;
    unk_E8->unk_14 = param->unk_14;
    SetPos(unk_E8->unk_14.pos);
}

void CFieldCannonUnit::ov0_0215ABA4()
{
    unk_E0 = 0;
    ov0_0215AA98(0);
    PlayAnim(2, 0);
    SetUnk004Bit8();
}

FieldCannonUnitParam *CFieldCannonUnit::ov0_0215ABF0()
{
    return unk_E8;
}
