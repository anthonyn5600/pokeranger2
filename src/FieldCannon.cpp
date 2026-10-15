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
    Clear();
}

void FieldCannons::RestoreSaved()
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
                cannon = GetCannon(index);
            } else {
                cannon = GetCannon(CreateCannon(save->unk_8434, index, 1));
            }
            cannon->RestoreShot(&param, frame, unit);
            cannon->SetEnabled(TRUE);
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

int FieldCannons::FindFreeSlot()
{
    for (int i = 0; i < 10; i++) {
        if (!(unk_00 & (1 << i))) {
            return i;
        }
    }
    return -1;
}

int FieldCannons::CreateCannon(int type, int index, int mode)
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
        slot = FindFreeSlot();
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

void FieldCannons::Release()
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

void FieldCannons::Clear()
{
    Release();
}

void FieldCannons::Update()
{
    for (u16 i = 0; i < 10; i++) {
        if (unk_04[i] != NULL) {
            unk_04[i]->UpdateShots();
        }
    }
}

void FieldCannons::Draw(DrawObjectList *renderLists, FieldShadow *hud)
{
    for (u16 i = 0; i < 10; i++) {
        if (unk_04[i] != NULL) {
            unk_04[i]->DrawShots(renderLists, hud);
        }
    }
}

CFieldCannon *FieldCannons::GetCannon(int index)
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
    InitShots();
}

CFieldCannon::~CFieldCannon()
{
    ReleaseShots();
}

void CFieldCannon::InitShots()
{
    ReleaseShots();
    unk_EC = new FieldCannonParam;
    ResetParam();
    for (int i = 0; i < 4; i++) {
        unk_F0[i] = new CFieldCannonUnit(unk_E2);
    }
}

void CFieldCannon::ReleaseShots()
{
    SAFE_DELETE(unk_EC);
    for (int i = 0; i < 4; i++) {
        SAFE_DELETE(unk_F0[i]);
    }
}

void CFieldCannon::ResetParam()
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

void CFieldCannon::UpdateShots()
{
    if (!IsEnabled()) {
        return;
    }
    if (IsFieldBusy()) {
        return;
    }
    if (!(unk_EC->unk_0C & 4)) {
        unk_E0++;
        if (unk_E0 == unk_EC->unk_02) {
            u16 index = 0;
            if (FindFreeShot(&index)) {
                unk_F0[index]->ResetShot();
                unk_F0[index]->SetShotParam(unk_EC);
                unk_F0[index]->SetEnabled(TRUE);
                unk_E8->PlayGroupSe(0x5C, 0x62);
            }
            unk_E0 = 0;
        }
    }
    SaveData *save = &MAIN_BSS_020B26A0;
    for (u16 i = 0; i < 4; i++) {
        u16 id = unk_E4 * 4 + 0x20 + i;
        FieldCannonUnitParam *param = unk_F0[i]->GetShotParam();
        if (unk_F0[i]->IsEnabled()) {
            if (IsEnabled()) {
                if (!(param->unk_0A & 2)) {
                    u16 frame = unk_F0[i]->unk_E0;
                    u16 life = unk_F0[i]->GetShotParam()->unk_08;
                    fx32 speed = param->unk_10;
                    save->SetFlagKind(id & 0x3FF, 6);
                    save->SetFlagCount(id & 0x3FF, frame, 1);
                    save->SetFlagValue(id & 0x3FF, life);
                    SetCannonShot(id, param->unk_14.pos, param->unk_00, speed, (u8)param->unk_06 | ((u8)param->unk_02 << 8));
                }
                unk_F0[i]->UpdateShot();
                if (!unk_F0[i]->IsEnabled()) {
                    save->unk_81B4[id & 0x3FF] = 0;
                }
            } else {
                unk_F0[i]->SetEnabled(FALSE);
            }
        }
    }
}

void CFieldCannon::DrawShots(DrawObjectList *renderLists, FieldShadow *hud)
{
    if (!IsEnabled()) {
        return;
    }
    for (u16 i = 0; i < 4; i++) {
        if (unk_F0[i]->IsEnabled()) {
            unk_F0[i]->Draw(renderLists, hud);
        }
    }
}

BOOL CFieldCannon::IsFieldBusy()
{
    BOOL ret = FALSE;
    FieldScriptLauncher *runner = MAIN_BSS_0210CA44;
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (runner != NULL && runner->IsBusy()) {
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

BOOL CFieldCannon::FindFreeShot(u16 *index)
{
    for (u16 i = 0; i < 4; i++) {
        if (!unk_F0[i]->IsEnabled()) {
            *index = i;
            return TRUE;
        }
    }
    return FALSE;
}

void CFieldCannon::SetEnabled(BOOL active)
{
    if (active) {
        unk_EC->unk_0C |= 1;
    } else {
        unk_EC->unk_0C &= ~1;
    }
}

BOOL CFieldCannon::IsEnabled()
{
    if (unk_EC->unk_0C & 1) {
        return TRUE;
    }
    return FALSE;
}

void CFieldCannon::SetOrigin(int x, int y)
{
    Point2D pos = { x << FX32_SHIFT, y << FX32_SHIFT };
    unk_EC->unk_14.pos = pos;
}

void CFieldCannon::SetParams(int angle, int speed, int interval, int arg4, int arg5, int arg6, int arg7, int arg8)
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

void CFieldCannon::RestoreShot(FieldCannonParam *param, u16 frame, u16 index)
{
    if (unk_F0[index] == NULL) {
        return;
    }
    unk_F0[index]->ResetShot();
    unk_F0[index]->SetShotParam(param);
    unk_F0[index]->unk_E0 = frame;
    unk_F0[index]->SetEnabled(TRUE);
    unk_F0[index]->SetPos(param->unk_14.pos);
}

CFieldCannonUnit::CFieldCannonUnit(u16 type)
{
    unk_E8 = NULL;
    unk_E2 = type;
    unk_E4 = MAIN_BSS_0210CA48;
    unk_E0 = 0;
    Init();
}

CFieldCannonUnit::~CFieldCannonUnit()
{
    Release();
}

void CFieldCannonUnit::Init()
{
    Release();
    unk_E8 = new FieldCannonUnitParam;
    ResetParam();
    u16 id = 0;
    if (unk_E2 == 0) {
        id = 0x154;
    }
    if (unk_E2 == 1) {
        id = 0x174;
    }
    CreateDrawObject(2, id, 0, 6, 0);
}

void CFieldCannonUnit::Release()
{
    SAFE_DELETE(unk_E8);
}

void CFieldCannonUnit::ResetParam()
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

void CFieldCannonUnit::UpdateShot()
{
    if (!(unk_E8->unk_0A & 1)) {
        return;
    }
    Point2D pos = GetPos();
    unk_E8->unk_14.pos = pos;
    if (unk_E8->unk_0A & 2) {
        if (GetAnimState() == 0) {
            SetEnabled(FALSE);
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
            unk_E4->KnockBack(d.x, d.y, unk_E8->unk_06, unk_E8->unk_02, -1);
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

void CFieldCannonUnit::SetEnabled(BOOL active)
{
    if (active) {
        unk_E8->unk_0A |= 1;
    } else {
        unk_E8->unk_0A &= ~1;
    }
}

BOOL CFieldCannonUnit::IsEnabled()
{
    if (unk_E8->unk_0A & 1) {
        return TRUE;
    }
    return FALSE;
}

void CFieldCannonUnit::SetFlags(u16 flags)
{
    unk_E8->unk_0A = flags;
}

void CFieldCannonUnit::SetShotParam(FieldCannonParam *param)
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

void CFieldCannonUnit::ResetShot()
{
    unk_E0 = 0;
    SetFlags(0);
    PlayAnim(2, 0);
    SetUnk004Bit8();
}

FieldCannonUnitParam *CFieldCannonUnit::GetShotParam()
{
    return unk_E8;
}
