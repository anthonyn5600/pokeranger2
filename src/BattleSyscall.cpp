#include "AudioEngine.hpp"
#include "BattleStartParam.hpp"
#include "BrightnessFade.hpp"
#include "CActor.hpp"
#include "CGame.hpp"
#include "CTPEmulator.hpp"
#include "CameraController.hpp"
#include "SaveData.hpp"
#include "TextboxManager.hpp"
#include "UnkStruct_02044464.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleAttackEffect.hpp"
#include "battle/CBattleAttackEffectData.hpp"
#include "battle/CBattleDisk.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "battle/UnkClass_0212770C.hpp"
#include "battle/UnkClass_02127B48.hpp"
#include "battle/UnkStruct_0212DFEC.hpp"
#include "battle/UnkStruct_0212E008.hpp"
#include "scene/CBattleScene.hpp"

static inline CBattleScene *BattleScene()
{
    return (CBattleScene *)s_game->currentScene;
}

extern "C" {

CBattleDisk *ov1_0212A124()
{
    return BattleScene()->unk_00D8;
}

CBattleAssist *ov1_0212A13C()
{
    return BattleScene()->unk_0384;
}

CBattleEnemy *ov1_0212A1B0(u8 id);
CBattleAttackEffect *ov1_0212A1D0(u8 id);

CActor *ov1_0212A154(u8 id)
{
    int kind = CBattleScene::ov1_02122728(id);
    CActor *actor = NULL;
    switch (kind) {
    case 0:
        actor = ov1_0212A124();
        break;
    case 1:
        actor = ov1_0212A1B0(id);
        break;
    case 2:
        actor = ov1_0212A1D0(id);
        break;
    }
    return actor;
}

CBattleEnemy *ov1_0212A1B0(u8 id)
{
    return BattleScene()->ov1_02122760(id);
}

CBattleAttackEffect *ov1_0212A1D0(u8 id)
{
    return BattleScene()->ov1_02122788(id);
}

u8 ov1_0212A1F0()
{
    for (u8 i = 0; i < 0x60; i++) {
        if (!ov1_0212A1D0(i + 9)->HasData()) {
            return i + 9;
        }
    }
    return 0x89;
}

CBattleAttackEffectData *ov1_0212A240(u16 id)
{
    CBattleScene *scene = BattleScene();
    for (u8 i = 0; i < 0x12; i++) {
        CBattleAttackEffectData *data = scene->ov1_021227B0(i);
        if (data != NULL && id == data->unk_18->unk_00) {
            return data;
        }
    }
    return NULL;
}

int ov1_0212A298(int *args)
{
    return BattleScene()->ov1_0211E7E8(args[0]) ? TRUE : FALSE;
}

int ov1_0212A2CC(int *args)
{
    s_game->m_textboxData->LoadBattleMessages(args[0]);
    return 1;
}

int ov1_0212A2F4(int *args)
{
    s_game->m_audioEngine->LoadBgmGroup(args[0]);
    return 1;
}

int ov1_0212A31C(int *args)
{
    s_game->m_audioEngine->sub_02034870(args[0]);
    return 1;
}

int ov1_0212A344(int *args)
{
    BattleScene()->ov1_0211E71C(args[0]);
    return 1;
}

int ov1_0212A36C(int *args)
{
    u8 slot = ov1_0212A1F0();
    if (slot == 0x89) {
        return 0x89;
    }
    CBattleAttackEffectData *data = ov1_0212A240(args[0]);
    if (data == NULL) {
        return 0x89;
    }
    CBattleAttackEffect *effect = ov1_0212A1D0(slot);
    effect->ov1_021270FC(data);
    Point2D pos;
    pos.x = args[1];
    pos.y = args[2];
    effect->m_motion.SetPos(pos);
    effect->unk_18E = 1;
    return slot;
}

int ov1_0212A3FC(int *args)
{
    u8 slot = ov1_0212A1F0();
    if (slot == 0x89) {
        return 0x89;
    }
    CBattleAttackEffectData *data = ov1_0212A240(args[0]);
    if (data == NULL) {
        return 0x89;
    }
    CBattleAttackEffect *effect = ov1_0212A1D0(slot);
    effect->ov1_021270FC(data);
    Point2D pos;
    pos.x = args[1];
    pos.y = args[2];
    effect->m_motion.SetPos(pos);
    effect->unk_18E = args[3];
    return slot;
}

int ov1_0212A48C(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    Point2D pos;
    pos.x = args[1];
    pos.y = args[2];
    actor->m_motion.MoveLinear(pos, (u16)args[3]);
    return 1;
}

int ov1_0212A4EC(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    Point2D pos;
    pos.x = args[1];
    pos.y = args[2];
    actor->m_motion.MoveAtSpeed(pos, args[3]);
    return 1;
}

int ov1_0212A544(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->m_motion.MoveInDirection(args[1], args[2]);
    return 1;
}

int ov1_0212A580(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->m_motion.Orbit(actor->m_motion.m_pos, args[1], args[2], args[3], args[4], args[5]);
    return 1;
}

int ov1_0212A600(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->sub_020127D0(args[1], (u16)args[2]);
    return 1;
}

int ov1_0212A638(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->sub_02012808(args[1], args[2]);
    return 1;
}

int ov1_0212A668(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->m_motion.SetPos(actor->m_motion.m_pos);
    return 0;
}

int ov1_0212A69C(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->Jump(args[1], (u16)args[2]);
    return 0;
}

int ov1_0212A6D4(int *args)
{
    if ((u8)args[2] == 0 && args[1] == 0x10) {
        return 0;
    }
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    CBattleAttackEffect *effect = ov1_0212A1D0(args[0]);
    if (effect != NULL) {
        effect->ov1_02127454(args[1], (u8)(args[2] - 1));
    } else {
        actor->SetAnim(args[1], (u8)(args[2] - 1));
    }
    return 1;
}

int ov1_0212A754(int *args)
{
    u8 id = args[0];
    switch (CBattleScene::ov1_02122728(id)) {
    case 0:
        break;
    case 1:
        ov1_0212A1B0(id)->ov1_021262AC();
        break;
    case 2:
        ov1_0212A1D0(id)->ov1_02127300();
        break;
    }
    return 0;
}

int ov1_0212A7A8(int *args)
{
    CBattleEnemy *enemy = ov1_0212A1B0(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->m_flags |= 0x100;
    return 1;
}

int ov1_0212A7D8(int *args)
{
    CBattleEnemy *enemy = ov1_0212A1B0(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->m_flags &= ~0x100;
    return 1;
}

int ov1_0212A808(int *args)
{
    u8 id = args[0];
    switch (CBattleScene::ov1_02122728(id)) {
    case 1:
        ov1_0212A1B0(id)->ov1_0212671C(TRUE);
        break;
    case 2:
        ov1_0212A1D0(id)->ov1_02127388(TRUE);
        break;
    }
    return 0;
}

int ov1_0212A85C(int *args)
{
    u8 id = args[0];
    switch (CBattleScene::ov1_02122728(id)) {
    case 1:
        ov1_0212A1B0(id)->ov1_0212671C(FALSE);
        break;
    case 2:
        ov1_0212A1D0(id)->ov1_02127388(FALSE);
        break;
    }
    return 0;
}

int ov1_0212A8B0(int *args)
{
    CBattleAttackEffect *effect = ov1_0212A1D0(args[0]);
    if (effect == NULL) {
        return 0;
    }
    CActor *target = ov1_0212A154(args[1]);
    if (target == NULL) {
        return 0;
    }
    effect->ov1_0212728C((CBattleEnemy *)target, CBattleScene::ov1_02122728((u8)args[1]));
    return 1;
}

int ov1_0212A90C(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->ScaleTo(args[3], args[1], args[2]);
    return 1;
}

int ov1_0212A940(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->FadeAlpha(args[2], args[1]);
    return 1;
}

int ov1_0212A978(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    if ((s16)args[2] == 0) {
        actor->SetDir(args[1]);
    }
    u16 target = args[1];
    u16 cur = actor->m_dir;
    u32 left = cur >= target ? cur - target : cur + 0x10000 - target;
    u32 right = cur <= target ? target - cur : target + 0x10000 - cur;
    s16 speed;
    if (left >= right) {
        speed = MATH_IAbs((s16)args[2]);
    } else {
        speed = -MATH_IAbs((s16)args[2]);
    }
    actor->TurnTo(args[1], speed);
    return 1;
}

int ov1_0212AA30(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->FaceMoveDir();
    return 1;
}

int ov1_0212AA58(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    Point2D pos;
    pos.x = args[1];
    pos.y = args[2];
    actor->LookAt(pos);
    return 1;
}

int ov1_0212AAA8(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->Spin((u16)args[1]);
    return 1;
}

int ov1_0212AAE0(int *args)
{
    CBattleEnemy *enemy = ov1_0212A1B0(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->unk_1A4->ov1_02127888(args[1], args[2]);
    return 1;
}

int ov1_0212AB20(int *args)
{
    CBattleEnemy *enemy = ov1_0212A1B0(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->unk_1A0->unk_08 = TRUE;
    return 1;
}

int ov1_0212AB48(int *args)
{
    CBattleEnemy *enemy = ov1_0212A1B0(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->unk_1A0->unk_08 = FALSE;
    return 1;
}

int ov1_0212AB78(int *args)
{
    CBattleEnemy *enemy = ov1_0212A1B0(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->ov1_02126734(TRUE);
    return 1;
}

int ov1_0212ABA4(int *args)
{
    CBattleEnemy *enemy = ov1_0212A1B0(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->ov1_02126734(FALSE);
    return 1;
}

int ov1_0212ABD0(int *args)
{
    u8 id = args[0];
    switch (CBattleScene::ov1_02122728(id)) {
    case 1:
        ov1_0212A1B0(id)->ov1_0212674C(TRUE);
        break;
    case 2:
        ov1_0212A1D0(id)->ov1_02127370(TRUE);
        break;
    }
    return 1;
}

int ov1_0212AC24(int *args)
{
    u8 id = args[0];
    switch (CBattleScene::ov1_02122728(id)) {
    case 1:
        ov1_0212A1B0(id)->ov1_0212674C(FALSE);
        break;
    case 2:
        ov1_0212A1D0(id)->ov1_02127370(FALSE);
        break;
    }
    return 1;
}

int ov1_0212AC78(int *args)
{
    CBattleEnemy *enemy = ov1_0212A1B0(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->ov1_021263A4(args[1], (u16)args[2]);
    return 1;
}

int ov1_0212ACB0(int *args)
{
    CBattleDisk *disk = ov1_0212A124();
    if (disk == NULL) {
        return 0;
    }
    disk->unk_194 |= 0x80;
    return 1;
}

int ov1_0212ACDC(int *args)
{
    CBattleDisk *disk = ov1_0212A124();
    if (disk == NULL) {
        return 0;
    }
    disk->unk_194 &= ~0x80;
    return 1;
}

int ov1_0212AD08(int *args)
{
    BattleScene()->unk_007C = args[0];
    return 1;
}

int ov1_0212AD28(int *args)
{
    u8 id = args[0];
    int value;
    switch (CBattleScene::ov1_02122728(id)) {
    case 0:
        value = ov1_0212A124()->unk_19C;
        break;
    case 1:
        value = ov1_0212A1B0(id)->unk_188;
        break;
    case 2:
        return 0;
    }
    return value;
}

int ov1_0212AD88(int *args)
{
    u8 id = args[0];
    int hp;
    int maxHp;
    switch (CBattleScene::ov1_02122728(id)) {
    case 0: {
        u8 level = BattleStartParam_GetStylerLevel(s_game->unk_143C);
        hp = ov1_0212A124()->unk_19C;
        maxHp = sub_02010E78(s_game->unk_1438, level);
        break;
    }
    case 1:
        hp = ov1_0212A1B0(id)->unk_188;
        maxHp = ov1_0212A1B0(id)->unk_184->unk_1C->unk_00;
        break;
    case 2:
        return 0;
    }
    return hp * 100 / maxHp;
}

int ov1_0212AE40(int *args)
{
    CBattleEnemy *enemy = ov1_0212A1B0(args[0]);
    if (enemy != NULL) {
        return enemy->unk_18C;
    }
    return 0;
}

int ov1_0212AE60(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor != NULL) {
        return actor->m_motion.m_pos.x;
    }
    return 0;
}

int ov1_0212AE80(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor != NULL) {
        return actor->m_motion.m_pos.y;
    }
    return 0;
}

int ov1_0212AEA0(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    fx32 dx = actor->m_motion.m_pos.x - actor->m_motion.m_prev.x;
    return actor->m_motion.m_pos.x + dx * args[1];
}

int ov1_0212AED8(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    fx32 dy = actor->m_motion.m_pos.y - actor->m_motion.m_prev.y;
    return actor->m_motion.m_pos.y + dy * args[1];
}

int ov1_0212AF10(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor != NULL) {
        return actor->m_dir;
    }
    return 0;
}

int ov1_0212AF30(int *args)
{
    int value = 0;
    u8 id = args[0];
    switch (CBattleScene::ov1_02122728(id)) {
    case 1:
        value = ov1_0212A1B0(id)->unk_184->unk_1C->unk_05;
        break;
    case 2:
        value = ov1_0212A1D0(id)->unk_18E;
        break;
    }
    return value;
}

int ov1_0212AF8C(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    return actor->HasData();
}

int ov1_0212AFBC(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor == NULL) {
        return 0;
    }
    return actor->m_motion.IsActive();
}

int ov1_0212AFEC(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor != NULL) {
        return actor->unk_90;
    }
    return 0;
}

int ov1_0212B00C(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor != NULL) {
        return actor->m_jumping;
    }
    return 0;
}

int ov1_0212B02C(int *args)
{
    u8 id = args[0];
    CActor *actor = ov1_0212A154(id);
    if (actor == NULL) {
        return 0;
    }
    if (CBattleScene::ov1_02122728(id) == 2) {
        return ((CBattleAttackEffect *)actor)->ov1_0212747C();
    }
    return actor->sub_02012AFC();
}

int ov1_0212B070(int *args)
{
    CActor *actor = ov1_0212A154(args[0]);
    if (actor != NULL) {
        return actor->m_turning;
    }
    return 0;
}

int ov1_0212B090(int *args)
{
    ov1_0212A124()->ov1_0212C514(1);
    return 1;
}

int ov1_0212B0A8(int *args)
{
    ov1_0212A124()->ov1_0212C514(0);
    s_game->m_audioEngine->sub_02034ED8(0);
    CBattleAssist *assist = ov1_0212A13C();
    if (assist != NULL) {
        assist->vfunc_0C();
    }
    return 1;
}

int ov1_0212B0F4(int *args)
{
    return ov1_0212A124()->ov1_0212C5C0();
}

int ov1_0212B104(int *args)
{
    return BattleScene()->unk_0028;
}

int ov1_0212B11C(int *args)
{
    int count = 0;
    for (int i = 0; i < 8; i++) {
        CBattleEnemy *enemy = ov1_0212A1B0(i + 1);
        if (enemy != NULL && enemy->HasData()) {
            count++;
        }
    }
    return count;
}

int ov1_0212B170(int *args)
{
    s_game->m_textboxData->ShowBattleMessage(args[0], 1, 1, 0);
    return 1;
}

int ov1_0212B1AC(int *args)
{
    s_game->m_textboxData->ShowBattleMessage(args[0], 0, 1, 0);
    return 1;
}

int ov1_0212B1E4(int *args)
{
    return s_game->m_textboxData->IsActive();
}

int ov1_0212B204(int *args)
{
    s_game->m_textboxData->sub_02009FB0(1, 1);
    return 1;
}

int ov1_0212B230(int *args)
{
    BattleScene()->unk_0008 |= 2;
    return 1;
}

int ov1_0212B254(int *args)
{
    BattleScene()->unk_0008 &= ~2;
    return 1;
}

int ov1_0212B278(int *args)
{
    BattleScene()->unk_0070 = TRUE;
    return 1;
}

int ov1_0212B294(int *args)
{
    BattleScene()->unk_0070 = FALSE;
    return 1;
}

int ov1_0212B2B4(int *args)
{
    BattleScene()->ov1_021227CC(args[0]);
    return 1;
}

int ov1_0212B2D8(int *args)
{
    BattleScene()->ov1_02122D78(0);
    return 1;
}

int ov1_0212B2FC(int *args)
{
    BattleScene()->ov1_02122D78(1);
    return 1;
}

int ov1_0212B320(int *args)
{
    s_game->unk_14BC->Start(2, args[0]);
    return 1;
}

int ov1_0212B354(int *args)
{
    s_game->unk_14BC->Start(1, args[0]);
    return 1;
}

int ov1_0212B388(int *args)
{
    s_game->unk_14BC->Start(4, args[0]);
    return 1;
}

int ov1_0212B3BC(int *args)
{
    s_game->unk_14BC->Start(3, args[0]);
    return 1;
}

int ov1_0212B3F0(int *args)
{
    s_game->m_audioEngine->PlaySe(args[0]);
    return 1;
}

int ov1_0212B418(int *args)
{
    s_game->m_audioEngine->StopSe(args[0]);
    return 1;
}

int ov1_0212B440(int *args)
{
    s_game->m_audioEngine->PlayStream(args[0], 0x40);
    return 1;
}

int ov1_0212B46C(int *args)
{
    s_game->m_audioEngine->PlayBgm(args[0], 0);
    return 1;
}

int ov1_0212B498(int *args)
{
    s_game->m_audioEngine->StopBgm(args[0]);
    return 1;
}

int ov1_0212B4C0(int *args)
{
    return FX_SinIdx((u16)args[0]);
}

int ov1_0212B4E4(int *args)
{
    return FX_CosIdx((u16)args[0]);
}

int ov1_0212B510(int *args)
{
    return FX_Atan2Idx(args[3] - args[1], args[2] - args[0]);
}

int ov1_0212B530(int *args)
{
    CTPEmulator *emu = CGame::GetInstance()->touchPanelEmulator;
    if (emu == NULL) {
        return 0;
    }
    emu->Press(args[0], args[1]);
    return 1;
}

int ov1_0212B55C(int *args)
{
    CTPEmulator *emu = CGame::GetInstance()->touchPanelEmulator;
    if (emu == NULL) {
        return 0;
    }
    emu->Release();
    return 1;
}

int ov1_0212B580(int *args)
{
    CTPEmulator *emu = CGame::GetInstance()->touchPanelEmulator;
    if (emu == NULL) {
        return 0;
    }
    emu->DragTo(args[0], args[1], args[2]);
    return 1;
}

CameraController *ov1_0212B5BC()
{
    return BattleScene()->ov1_021227C4();
}

int ov1_0212B5D8(int *args)
{
    CameraController *camera = ov1_0212B5BC();
    if (camera != NULL) {
        return 0;
    }
    camera->SetPos(args[0], args[1]);
    return 1;
}

int ov1_0212B600(int *args)
{
    CameraController *camera = ov1_0212B5BC();
    if (camera != NULL) {
        return 0;
    }
    camera->SetScale(args[0]);
    return 1;
}

int ov1_0212B628(int *args)
{
    CameraController *camera = ov1_0212B5BC();
    if (camera == NULL) {
        return 0;
    }
    camera->MoveTo(args[0], args[1], args[2]);
    return 1;
}

int ov1_0212B650(int *args)
{
    CameraController *camera = ov1_0212B5BC();
    if (camera == NULL) {
        return 0;
    }
    camera->MoveToTimed(args[0], args[1], args[3]);
    return 1;
}

int ov1_0212B688(int *args)
{
    CameraController *camera = ov1_0212B5BC();
    if (camera == NULL) {
        return 0;
    }
    camera->ZoomTo(args[0], args[1]);
    return 1;
}

int ov1_0212B6B8(int *args)
{
    CameraController *camera = ov1_0212B5BC();
    if (camera == NULL) {
        return 0;
    }
    camera->sub_0200D6E8(args[0], args[1], args[2]);
    return 1;
}

int ov1_0212B6F8(int *args)
{
    CameraController *camera = ov1_0212B5BC();
    if (camera == NULL) {
        return 0;
    }
    camera->sub_0200D870(args[0], args[1]);
    return 1;
}

int ov1_0212B728(int *args)
{
    CameraController *camera = ov1_0212B5BC();
    if (camera == NULL) {
        return 0;
    }
    camera->sub_0200D7B8(args[0], args[1]);
    return 1;
}

int ov1_0212B760(int *args)
{
    CameraController *camera = ov1_0212B5BC();
    if (camera == NULL) {
        return 0;
    }
    camera->sub_0200D7F4(args[0], args[1], args[2]);
    return 1;
}
}

// The battle script syscall table (registered by CBattleScene::func6)
ScriptSyscall gBattleSyscalls[] = {
    (ScriptSyscall)ov1_0212A298,
    (ScriptSyscall)ov1_0212A2CC,
    (ScriptSyscall)ov1_0212A2F4,
    (ScriptSyscall)ov1_0212A31C,
    (ScriptSyscall)ov1_0212A344,
    (ScriptSyscall)ov1_0212A36C,
    (ScriptSyscall)ov1_0212A3FC,
    (ScriptSyscall)ov1_0212A48C,
    (ScriptSyscall)ov1_0212A4EC,
    (ScriptSyscall)ov1_0212A544,
    (ScriptSyscall)ov1_0212A580,
    (ScriptSyscall)ov1_0212A600,
    (ScriptSyscall)ov1_0212A638,
    (ScriptSyscall)ov1_0212A668,
    (ScriptSyscall)ov1_0212A69C,
    (ScriptSyscall)ov1_0212A6D4,
    (ScriptSyscall)ov1_0212A754,
    (ScriptSyscall)ov1_0212A7A8,
    (ScriptSyscall)ov1_0212A7D8,
    (ScriptSyscall)ov1_0212A808,
    (ScriptSyscall)ov1_0212A85C,
    (ScriptSyscall)ov1_0212A8B0,
    (ScriptSyscall)ov1_0212A90C,
    (ScriptSyscall)ov1_0212A940,
    (ScriptSyscall)ov1_0212A978,
    (ScriptSyscall)ov1_0212AA30,
    (ScriptSyscall)ov1_0212AA58,
    (ScriptSyscall)ov1_0212AAA8,
    (ScriptSyscall)ov1_0212AAE0,
    (ScriptSyscall)ov1_0212AB20,
    (ScriptSyscall)ov1_0212AB48,
    (ScriptSyscall)ov1_0212AB78,
    (ScriptSyscall)ov1_0212ABA4,
    (ScriptSyscall)ov1_0212ABD0,
    (ScriptSyscall)ov1_0212AC24,
    (ScriptSyscall)ov1_0212AC78,
    (ScriptSyscall)ov1_0212AD28,
    (ScriptSyscall)ov1_0212AD88,
    (ScriptSyscall)ov1_0212AE40,
    (ScriptSyscall)ov1_0212AE60,
    (ScriptSyscall)ov1_0212AE80,
    (ScriptSyscall)ov1_0212AEA0,
    (ScriptSyscall)ov1_0212AED8,
    (ScriptSyscall)ov1_0212AF10,
    (ScriptSyscall)ov1_0212AF30,
    (ScriptSyscall)ov1_0212AF8C,
    (ScriptSyscall)ov1_0212AFBC,
    (ScriptSyscall)ov1_0212AFEC,
    (ScriptSyscall)ov1_0212B00C,
    (ScriptSyscall)ov1_0212B02C,
    (ScriptSyscall)ov1_0212B070,
    (ScriptSyscall)ov1_0212B090,
    (ScriptSyscall)ov1_0212B0A8,
    (ScriptSyscall)ov1_0212B0F4,
    (ScriptSyscall)ov1_0212ACB0,
    (ScriptSyscall)ov1_0212ACDC,
    (ScriptSyscall)ov1_0212AD08,
    (ScriptSyscall)ov1_0212B104,
    (ScriptSyscall)ov1_0212B11C,
    (ScriptSyscall)ov1_0212B170,
    (ScriptSyscall)ov1_0212B1AC,
    (ScriptSyscall)ov1_0212B1E4,
    (ScriptSyscall)ov1_0212B204,
    (ScriptSyscall)ov1_0212B230,
    (ScriptSyscall)ov1_0212B254,
    (ScriptSyscall)ov1_0212B2B4,
    (ScriptSyscall)ov1_0212B2D8,
    (ScriptSyscall)ov1_0212B2FC,
    (ScriptSyscall)ov1_0212B278,
    (ScriptSyscall)ov1_0212B294,
    (ScriptSyscall)ov1_0212B320,
    (ScriptSyscall)ov1_0212B354,
    (ScriptSyscall)ov1_0212B388,
    (ScriptSyscall)ov1_0212B3BC,
    (ScriptSyscall)ov1_0212B3F0,
    (ScriptSyscall)ov1_0212B418,
    (ScriptSyscall)ov1_0212B440,
    (ScriptSyscall)ov1_0212B46C,
    (ScriptSyscall)ov1_0212B498,
    (ScriptSyscall)ov1_0212B4C0,
    (ScriptSyscall)ov1_0212B4E4,
    (ScriptSyscall)ov1_0212B510,
    (ScriptSyscall)ov1_0212B530,
    (ScriptSyscall)ov1_0212B55C,
    (ScriptSyscall)ov1_0212B580,
    (ScriptSyscall)ov1_0212B5D8,
    (ScriptSyscall)ov1_0212B600,
    (ScriptSyscall)ov1_0212B628,
    (ScriptSyscall)ov1_0212B650,
    (ScriptSyscall)ov1_0212B688,
    (ScriptSyscall)ov1_0212B6B8,
    (ScriptSyscall)ov1_0212B6F8,
    (ScriptSyscall)ov1_0212B728,
    (ScriptSyscall)ov1_0212B760,
    NULL,
};
