#include "AudioEngine.hpp"
#include "BattleStartParam.hpp"
#include "BrightnessFade.hpp"
#include "CActor.hpp"
#include "CGame.hpp"
#include "CTPEmulator.hpp"
#include "CameraController.hpp"
#include "SaveData.hpp"
#include "ScriptVM.hpp"
#include "TextboxManager.hpp"
#include "battle/BattleEffectParam.hpp"
#include "battle/BattlePokemonParam.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleAttackEffect.hpp"
#include "battle/CBattleAttackEffectData.hpp"
#include "battle/CBattleDisk.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "battle/UnkClass_0212770C.hpp"
#include "battle/UnkClass_02127B48.hpp"
#include "scene/CBattleScene.hpp"

static inline CBattleScene *BattleScene()
{
    return (CBattleScene *)s_game->currentScene;
}

extern "C" {

CBattleDisk *Battle_GetDisk()
{
    return BattleScene()->unk_00D8;
}

CBattleAssist *Battle_GetAssist()
{
    return BattleScene()->unk_0384;
}

CBattleEnemy *Battle_FindEnemy(u8 id);
CBattleAttackEffect *Battle_FindEffect(u8 id);

CActor *Battle_FindActor(u8 id)
{
    int kind = CBattleScene::GetObjectType(id);
    CActor *actor = NULL;
    switch (kind) {
    case 0:
        actor = Battle_GetDisk();
        break;
    case 1:
        actor = Battle_FindEnemy(id);
        break;
    case 2:
        actor = Battle_FindEffect(id);
        break;
    }
    return actor;
}

CBattleEnemy *Battle_FindEnemy(u8 id)
{
    return BattleScene()->GetEnemy(id);
}

CBattleAttackEffect *Battle_FindEffect(u8 id)
{
    return BattleScene()->GetEffect(id);
}

u8 Battle_FindFreeEffectId()
{
    for (u8 i = 0; i < 0x60; i++) {
        if (!Battle_FindEffect(i + 9)->HasData()) {
            return i + 9;
        }
    }
    return 0x89;
}

CBattleAttackEffectData *Battle_FindEffectData(u16 id)
{
    CBattleScene *scene = BattleScene();
    for (u8 i = 0; i < 0x12; i++) {
        CBattleAttackEffectData *data = scene->GetEffectData(i);
        if (data != NULL && id == data->unk_18->unk_00) {
            return data;
        }
    }
    return NULL;
}

int BattleSys_LoadEffectData(int *args)
{
    return BattleScene()->AddEffectData(args[0]) ? TRUE : FALSE;
}

int BattleSys_LoadMessages(int *args)
{
    s_game->m_textboxData->LoadBattleMessages(args[0]);
    return 1;
}

int BattleSys_LoadBgmGroup(int *args)
{
    s_game->m_audioEngine->LoadBgmGroup(args[0]);
    return 1;
}

int BattleSys_LoadSeGroup(int *args)
{
    s_game->m_audioEngine->LoadBattleSeGroup(args[0]);
    return 1;
}

int BattleSys_ChangeBackground(int *args)
{
    BattleScene()->ChangeBackground(args[0]);
    return 1;
}

int BattleSys_SpawnEffect(int *args)
{
    u8 slot = Battle_FindFreeEffectId();
    if (slot == 0x89) {
        return 0x89;
    }
    CBattleAttackEffectData *data = Battle_FindEffectData(args[0]);
    if (data == NULL) {
        return 0x89;
    }
    CBattleAttackEffect *effect = Battle_FindEffect(slot);
    effect->Start(data);
    Point2D pos;
    pos.x = args[1];
    pos.y = args[2];
    effect->m_motion.SetPos(pos);
    effect->unk_18E = 1;
    return slot;
}

int BattleSys_SpawnEffectWithPower(int *args)
{
    u8 slot = Battle_FindFreeEffectId();
    if (slot == 0x89) {
        return 0x89;
    }
    CBattleAttackEffectData *data = Battle_FindEffectData(args[0]);
    if (data == NULL) {
        return 0x89;
    }
    CBattleAttackEffect *effect = Battle_FindEffect(slot);
    effect->Start(data);
    Point2D pos;
    pos.x = args[1];
    pos.y = args[2];
    effect->m_motion.SetPos(pos);
    effect->unk_18E = args[3];
    return slot;
}

int BattleSys_MoveActorLinear(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    Point2D pos;
    pos.x = args[1];
    pos.y = args[2];
    actor->m_motion.MoveLinear(pos, (u16)args[3]);
    return 1;
}

int BattleSys_MoveActorAtSpeed(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    Point2D pos;
    pos.x = args[1];
    pos.y = args[2];
    actor->m_motion.MoveAtSpeed(pos, args[3]);
    return 1;
}

int BattleSys_MoveActorInDirection(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->m_motion.MoveInDirection(args[1], args[2]);
    return 1;
}

int BattleSys_ActorOrbit(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->m_motion.Orbit(actor->m_motion.m_pos, args[1], args[2], args[3], args[4], args[5]);
    return 1;
}

int BattleSys_MoveActorHeightTo(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->MoveHeightTo(args[1], (u16)args[2]);
    return 1;
}

int BattleSys_MoveActorHeightAtSpeed(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->MoveHeightAtSpeed(args[1], args[2]);
    return 1;
}

int BattleSys_StopActor(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->m_motion.SetPos(actor->m_motion.m_pos);
    return 0;
}

int BattleSys_ActorJump(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->Jump(args[1], (u16)args[2]);
    return 0;
}

int BattleSys_SetActorAnim(int *args)
{
    if ((u8)args[2] == 0 && args[1] == 0x10) {
        return 0;
    }
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    CBattleAttackEffect *effect = Battle_FindEffect(args[0]);
    if (effect != NULL) {
        effect->PlayAction(args[1], (u8)(args[2] - 1));
    } else {
        actor->SetAnim(args[1], (u8)(args[2] - 1));
    }
    return 1;
}

int BattleSys_RemoveActor(int *args)
{
    u8 id = args[0];
    switch (CBattleScene::GetObjectType(id)) {
    case 0:
        break;
    case 1:
        Battle_FindEnemy(id)->Terminate();
        break;
    case 2:
        Battle_FindEffect(id)->Terminate();
        break;
    }
    return 0;
}

int BattleSys_PauseEnemyScript(int *args)
{
    CBattleEnemy *enemy = Battle_FindEnemy(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->m_flags |= 0x100;
    return 1;
}

int BattleSys_ResumeEnemyScript(int *args)
{
    CBattleEnemy *enemy = Battle_FindEnemy(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->m_flags &= ~0x100;
    return 1;
}

int BattleSys_EnableCollision(int *args)
{
    u8 id = args[0];
    switch (CBattleScene::GetObjectType(id)) {
    case 1:
        Battle_FindEnemy(id)->SetTargetable(TRUE);
        break;
    case 2:
        Battle_FindEffect(id)->SetCollisionEnabled(TRUE);
        break;
    }
    return 0;
}

int BattleSys_DisableCollision(int *args)
{
    u8 id = args[0];
    switch (CBattleScene::GetObjectType(id)) {
    case 1:
        Battle_FindEnemy(id)->SetTargetable(FALSE);
        break;
    case 2:
        Battle_FindEffect(id)->SetCollisionEnabled(FALSE);
        break;
    }
    return 0;
}

int BattleSys_AttachEffect(int *args)
{
    CBattleAttackEffect *effect = Battle_FindEffect(args[0]);
    if (effect == NULL) {
        return 0;
    }
    CActor *target = Battle_FindActor(args[1]);
    if (target == NULL) {
        return 0;
    }
    effect->AttachTo((CBattleEnemy *)target, CBattleScene::GetObjectType((u8)args[1]));
    return 1;
}

int BattleSys_ScaleActor(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->ScaleTo(args[3], args[1], args[2]);
    return 1;
}

int BattleSys_FadeActorAlpha(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->FadeAlpha(args[2], args[1]);
    return 1;
}

int BattleSys_TurnActorTo(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
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

int BattleSys_ActorFaceMoveDir(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->FaceMoveDir();
    return 1;
}

int BattleSys_ActorLookAt(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    Point2D pos;
    pos.x = args[1];
    pos.y = args[2];
    actor->LookAt(pos);
    return 1;
}

int BattleSys_SpinActor(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    actor->Spin((u16)args[1]);
    return 1;
}

int ov1_0212AAE0(int *args)
{
    CBattleEnemy *enemy = Battle_FindEnemy(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->unk_1A4->Show(args[1], args[2]);
    return 1;
}

int ov1_0212AB20(int *args)
{
    CBattleEnemy *enemy = Battle_FindEnemy(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->unk_1A0->unk_08 = TRUE;
    return 1;
}

int ov1_0212AB48(int *args)
{
    CBattleEnemy *enemy = Battle_FindEnemy(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->unk_1A0->unk_08 = FALSE;
    return 1;
}

int BattleSys_SetEnemyInvincible(int *args)
{
    CBattleEnemy *enemy = Battle_FindEnemy(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->SetInvincible(TRUE);
    return 1;
}

int BattleSys_ClearEnemyInvincible(int *args)
{
    CBattleEnemy *enemy = Battle_FindEnemy(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->SetInvincible(FALSE);
    return 1;
}

int BattleSys_ShowShadow(int *args)
{
    u8 id = args[0];
    switch (CBattleScene::GetObjectType(id)) {
    case 1:
        Battle_FindEnemy(id)->SetShadowVisible(TRUE);
        break;
    case 2:
        Battle_FindEffect(id)->SetShadowVisible(TRUE);
        break;
    }
    return 1;
}

int BattleSys_HideShadow(int *args)
{
    u8 id = args[0];
    switch (CBattleScene::GetObjectType(id)) {
    case 1:
        Battle_FindEnemy(id)->SetShadowVisible(FALSE);
        break;
    case 2:
        Battle_FindEffect(id)->SetShadowVisible(FALSE);
        break;
    }
    return 1;
}

int BattleSys_SetEnemyStatus(int *args)
{
    CBattleEnemy *enemy = Battle_FindEnemy(args[0]);
    if (enemy == NULL) {
        return 0;
    }
    enemy->SetStatus(args[1], (u16)args[2]);
    return 1;
}

int ov1_0212ACB0(int *args)
{
    CBattleDisk *disk = Battle_GetDisk();
    if (disk == NULL) {
        return 0;
    }
    disk->unk_194 |= 0x80;
    return 1;
}

int ov1_0212ACDC(int *args)
{
    CBattleDisk *disk = Battle_GetDisk();
    if (disk == NULL) {
        return 0;
    }
    disk->unk_194 &= ~0x80;
    return 1;
}

int BattleSys_SetPartnerEnergyGain(int *args)
{
    BattleScene()->unk_007C = args[0];
    return 1;
}

int BattleSys_GetHP(int *args)
{
    u8 id = args[0];
    int value;
    switch (CBattleScene::GetObjectType(id)) {
    case 0:
        value = Battle_GetDisk()->unk_19C;
        break;
    case 1:
        value = Battle_FindEnemy(id)->unk_188;
        break;
    case 2:
        return 0;
    }
    return value;
}

int BattleSys_GetHPPercent(int *args)
{
    u8 id = args[0];
    int hp;
    int maxHp;
    switch (CBattleScene::GetObjectType(id)) {
    case 0: {
        u8 level = BattleStartParam_GetStylerLevel(s_game->unk_143C);
        hp = Battle_GetDisk()->unk_19C;
        maxHp = DiskHPTable_GetMaxEnergy(s_game->m_diskHPTable, level);
        break;
    }
    case 1:
        hp = Battle_FindEnemy(id)->unk_188;
        maxHp = Battle_FindEnemy(id)->unk_184->unk_1C->unk_00;
        break;
    case 2:
        return 0;
    }
    return hp * 100 / maxHp;
}

int BattleSys_GetEnemyStatus(int *args)
{
    CBattleEnemy *enemy = Battle_FindEnemy(args[0]);
    if (enemy != NULL) {
        return enemy->unk_18C;
    }
    return 0;
}

int BattleSys_GetActorX(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor != NULL) {
        return actor->m_motion.m_pos.x;
    }
    return 0;
}

int BattleSys_GetActorY(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor != NULL) {
        return actor->m_motion.m_pos.y;
    }
    return 0;
}

int BattleSys_PredictActorX(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    fx32 dx = actor->m_motion.m_pos.x - actor->m_motion.m_prev.x;
    return actor->m_motion.m_pos.x + dx * args[1];
}

int BattleSys_PredictActorY(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    fx32 dy = actor->m_motion.m_pos.y - actor->m_motion.m_prev.y;
    return actor->m_motion.m_pos.y + dy * args[1];
}

int BattleSys_GetActorDir(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor != NULL) {
        return actor->m_dir;
    }
    return 0;
}

int BattleSys_GetAttackPower(int *args)
{
    int value = 0;
    u8 id = args[0];
    switch (CBattleScene::GetObjectType(id)) {
    case 1:
        value = Battle_FindEnemy(id)->unk_184->unk_1C->unk_05;
        break;
    case 2:
        value = Battle_FindEffect(id)->unk_18E;
        break;
    }
    return value;
}

int BattleSys_ActorExists(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    return actor->HasData();
}

int BattleSys_IsActorMoving(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor == NULL) {
        return 0;
    }
    return actor->m_motion.IsActive();
}

int BattleSys_IsActorHeightMoving(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor != NULL) {
        return actor->m_heightTweening;
    }
    return 0;
}

int BattleSys_IsActorJumping(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor != NULL) {
        return actor->m_jumping;
    }
    return 0;
}

int BattleSys_GetActorAnimState(int *args)
{
    u8 id = args[0];
    CActor *actor = Battle_FindActor(id);
    if (actor == NULL) {
        return 0;
    }
    if (CBattleScene::GetObjectType(id) == 2) {
        return ((CBattleAttackEffect *)actor)->IsAnimActive();
    }
    return actor->GetAnimStatus();
}

int BattleSys_IsActorTurning(int *args)
{
    CActor *actor = Battle_FindActor(args[0]);
    if (actor != NULL) {
        return actor->m_turning;
    }
    return 0;
}

int BattleSys_ActivateDisk(int *args)
{
    Battle_GetDisk()->SetActive(1);
    return 1;
}

int BattleSys_DeactivateDisk(int *args)
{
    Battle_GetDisk()->SetActive(0);
    s_game->m_audioEngine->StopCaptureLineSe(0);
    CBattleAssist *assist = Battle_GetAssist();
    if (assist != NULL) {
        assist->vfunc_0C();
    }
    return 1;
}

int BattleSys_IsDiskActive(int *args)
{
    return Battle_GetDisk()->IsActive();
}

int BattleSys_GetBattleTime(int *args)
{
    return BattleScene()->unk_0028;
}

int BattleSys_CountEnemies(int *args)
{
    int count = 0;
    for (int i = 0; i < 8; i++) {
        CBattleEnemy *enemy = Battle_FindEnemy(i + 1);
        if (enemy != NULL && enemy->HasData()) {
            count++;
        }
    }
    return count;
}

int BattleSys_ShowMessage(int *args)
{
    s_game->m_textboxData->ShowBattleMessage(args[0], 1, 1, 0);
    return 1;
}

int ov1_0212B1AC(int *args)
{
    s_game->m_textboxData->ShowBattleMessage(args[0], 0, 1, 0);
    return 1;
}

int BattleSys_IsTextboxActive(int *args)
{
    return s_game->m_textboxData->IsActive();
}

int BattleSys_CloseTextbox(int *args)
{
    s_game->m_textboxData->CloseAndClear(1, 1);
    return 1;
}

int BattleSys_PauseBattle(int *args)
{
    BattleScene()->unk_0008 |= 2;
    return 1;
}

int BattleSys_ResumeBattle(int *args)
{
    BattleScene()->unk_0008 &= ~2;
    return 1;
}

int BattleSys_ShowEnemyGauges(int *args)
{
    BattleScene()->unk_0070 = TRUE;
    return 1;
}

int BattleSys_HideEnemyGauges(int *args)
{
    BattleScene()->unk_0070 = FALSE;
    return 1;
}

int BattleSys_EndBattle(int *args)
{
    BattleScene()->EndBattle(args[0]);
    return 1;
}

int BattleSys_UseTouchEmulator(int *args)
{
    BattleScene()->SelectTouchPanel(0);
    return 1;
}

int BattleSys_UseTouchPanel(int *args)
{
    BattleScene()->SelectTouchPanel(1);
    return 1;
}

int BattleSys_FadeOutWhite(int *args)
{
    s_game->m_mainFade->Start(2, args[0]);
    return 1;
}

int BattleSys_FadeInWhite(int *args)
{
    s_game->m_mainFade->Start(1, args[0]);
    return 1;
}

int BattleSys_FadeOutBlack(int *args)
{
    s_game->m_mainFade->Start(4, args[0]);
    return 1;
}

int BattleSys_FadeInBlack(int *args)
{
    s_game->m_mainFade->Start(3, args[0]);
    return 1;
}

int BattleSys_PlaySe(int *args)
{
    s_game->m_audioEngine->PlaySe(args[0]);
    return 1;
}

int BattleSys_StopSe(int *args)
{
    s_game->m_audioEngine->StopSe(args[0]);
    return 1;
}

int BattleSys_PlayStream(int *args)
{
    s_game->m_audioEngine->PlayStream(args[0], 0x40);
    return 1;
}

int BattleSys_PlayBgm(int *args)
{
    s_game->m_audioEngine->PlayBgm(args[0], 0);
    return 1;
}

int BattleSys_StopBgm(int *args)
{
    s_game->m_audioEngine->StopBgm(args[0]);
    return 1;
}

int BattleSys_Sin(int *args)
{
    return FX_SinIdx((u16)args[0]);
}

int BattleSys_Cos(int *args)
{
    return FX_CosIdx((u16)args[0]);
}

int BattleSys_Atan2(int *args)
{
    return FX_Atan2Idx(args[3] - args[1], args[2] - args[0]);
}

int BattleSys_TouchPress(int *args)
{
    CTPEmulator *emu = CGame::GetInstance()->touchPanelEmulator;
    if (emu == NULL) {
        return 0;
    }
    emu->Press(args[0], args[1]);
    return 1;
}

int BattleSys_TouchRelease(int *args)
{
    CTPEmulator *emu = CGame::GetInstance()->touchPanelEmulator;
    if (emu == NULL) {
        return 0;
    }
    emu->Release();
    return 1;
}

int BattleSys_TouchDragTo(int *args)
{
    CTPEmulator *emu = CGame::GetInstance()->touchPanelEmulator;
    if (emu == NULL) {
        return 0;
    }
    emu->DragTo(args[0], args[1], args[2]);
    return 1;
}

CameraController *Battle_GetCameraController()
{
    return BattleScene()->GetCameraController();
}

int BattleSys_SetCameraPos(int *args)
{
    CameraController *camera = Battle_GetCameraController();
    if (camera != NULL) {
        return 0;
    }
    camera->SetPos(args[0], args[1]);
    return 1;
}

int BattleSys_SetCameraScale(int *args)
{
    CameraController *camera = Battle_GetCameraController();
    if (camera != NULL) {
        return 0;
    }
    camera->SetScale(args[0]);
    return 1;
}

int BattleSys_MoveCameraTo(int *args)
{
    CameraController *camera = Battle_GetCameraController();
    if (camera == NULL) {
        return 0;
    }
    camera->MoveTo(args[0], args[1], args[2]);
    return 1;
}

int BattleSys_MoveCameraToTimed(int *args)
{
    CameraController *camera = Battle_GetCameraController();
    if (camera == NULL) {
        return 0;
    }
    camera->MoveToTimed(args[0], args[1], args[3]);
    return 1;
}

int BattleSys_ZoomCamera(int *args)
{
    CameraController *camera = Battle_GetCameraController();
    if (camera == NULL) {
        return 0;
    }
    camera->ZoomTo(args[0], args[1]);
    return 1;
}

int BattleSys_SwayCamera(int *args)
{
    CameraController *camera = Battle_GetCameraController();
    if (camera == NULL) {
        return 0;
    }
    camera->Sway(args[0], args[1], args[2]);
    return 1;
}

int BattleSys_ShakeCamera(int *args)
{
    CameraController *camera = Battle_GetCameraController();
    if (camera == NULL) {
        return 0;
    }
    camera->Shake(args[0], args[1]);
    return 1;
}

int BattleSys_SpinCamera(int *args)
{
    CameraController *camera = Battle_GetCameraController();
    if (camera == NULL) {
        return 0;
    }
    camera->Spin(args[0], args[1]);
    return 1;
}

int BattleSys_SpinZoomCamera(int *args)
{
    CameraController *camera = Battle_GetCameraController();
    if (camera == NULL) {
        return 0;
    }
    camera->SpinZoom(args[0], args[1], args[2]);
    return 1;
}
}

// The battle script syscall table (registered by CBattleScene::func6)
ScriptSyscall gBattleSyscalls[] = {
    (ScriptSyscall)BattleSys_LoadEffectData,
    (ScriptSyscall)BattleSys_LoadMessages,
    (ScriptSyscall)BattleSys_LoadBgmGroup,
    (ScriptSyscall)BattleSys_LoadSeGroup,
    (ScriptSyscall)BattleSys_ChangeBackground,
    (ScriptSyscall)BattleSys_SpawnEffect,
    (ScriptSyscall)BattleSys_SpawnEffectWithPower,
    (ScriptSyscall)BattleSys_MoveActorLinear,
    (ScriptSyscall)BattleSys_MoveActorAtSpeed,
    (ScriptSyscall)BattleSys_MoveActorInDirection,
    (ScriptSyscall)BattleSys_ActorOrbit,
    (ScriptSyscall)BattleSys_MoveActorHeightTo,
    (ScriptSyscall)BattleSys_MoveActorHeightAtSpeed,
    (ScriptSyscall)BattleSys_StopActor,
    (ScriptSyscall)BattleSys_ActorJump,
    (ScriptSyscall)BattleSys_SetActorAnim,
    (ScriptSyscall)BattleSys_RemoveActor,
    (ScriptSyscall)BattleSys_PauseEnemyScript,
    (ScriptSyscall)BattleSys_ResumeEnemyScript,
    (ScriptSyscall)BattleSys_EnableCollision,
    (ScriptSyscall)BattleSys_DisableCollision,
    (ScriptSyscall)BattleSys_AttachEffect,
    (ScriptSyscall)BattleSys_ScaleActor,
    (ScriptSyscall)BattleSys_FadeActorAlpha,
    (ScriptSyscall)BattleSys_TurnActorTo,
    (ScriptSyscall)BattleSys_ActorFaceMoveDir,
    (ScriptSyscall)BattleSys_ActorLookAt,
    (ScriptSyscall)BattleSys_SpinActor,
    (ScriptSyscall)ov1_0212AAE0,
    (ScriptSyscall)ov1_0212AB20,
    (ScriptSyscall)ov1_0212AB48,
    (ScriptSyscall)BattleSys_SetEnemyInvincible,
    (ScriptSyscall)BattleSys_ClearEnemyInvincible,
    (ScriptSyscall)BattleSys_ShowShadow,
    (ScriptSyscall)BattleSys_HideShadow,
    (ScriptSyscall)BattleSys_SetEnemyStatus,
    (ScriptSyscall)BattleSys_GetHP,
    (ScriptSyscall)BattleSys_GetHPPercent,
    (ScriptSyscall)BattleSys_GetEnemyStatus,
    (ScriptSyscall)BattleSys_GetActorX,
    (ScriptSyscall)BattleSys_GetActorY,
    (ScriptSyscall)BattleSys_PredictActorX,
    (ScriptSyscall)BattleSys_PredictActorY,
    (ScriptSyscall)BattleSys_GetActorDir,
    (ScriptSyscall)BattleSys_GetAttackPower,
    (ScriptSyscall)BattleSys_ActorExists,
    (ScriptSyscall)BattleSys_IsActorMoving,
    (ScriptSyscall)BattleSys_IsActorHeightMoving,
    (ScriptSyscall)BattleSys_IsActorJumping,
    (ScriptSyscall)BattleSys_GetActorAnimState,
    (ScriptSyscall)BattleSys_IsActorTurning,
    (ScriptSyscall)BattleSys_ActivateDisk,
    (ScriptSyscall)BattleSys_DeactivateDisk,
    (ScriptSyscall)BattleSys_IsDiskActive,
    (ScriptSyscall)ov1_0212ACB0,
    (ScriptSyscall)ov1_0212ACDC,
    (ScriptSyscall)BattleSys_SetPartnerEnergyGain,
    (ScriptSyscall)BattleSys_GetBattleTime,
    (ScriptSyscall)BattleSys_CountEnemies,
    (ScriptSyscall)BattleSys_ShowMessage,
    (ScriptSyscall)ov1_0212B1AC,
    (ScriptSyscall)BattleSys_IsTextboxActive,
    (ScriptSyscall)BattleSys_CloseTextbox,
    (ScriptSyscall)BattleSys_PauseBattle,
    (ScriptSyscall)BattleSys_ResumeBattle,
    (ScriptSyscall)BattleSys_EndBattle,
    (ScriptSyscall)BattleSys_UseTouchEmulator,
    (ScriptSyscall)BattleSys_UseTouchPanel,
    (ScriptSyscall)BattleSys_ShowEnemyGauges,
    (ScriptSyscall)BattleSys_HideEnemyGauges,
    (ScriptSyscall)BattleSys_FadeOutWhite,
    (ScriptSyscall)BattleSys_FadeInWhite,
    (ScriptSyscall)BattleSys_FadeOutBlack,
    (ScriptSyscall)BattleSys_FadeInBlack,
    (ScriptSyscall)BattleSys_PlaySe,
    (ScriptSyscall)BattleSys_StopSe,
    (ScriptSyscall)BattleSys_PlayStream,
    (ScriptSyscall)BattleSys_PlayBgm,
    (ScriptSyscall)BattleSys_StopBgm,
    (ScriptSyscall)BattleSys_Sin,
    (ScriptSyscall)BattleSys_Cos,
    (ScriptSyscall)BattleSys_Atan2,
    (ScriptSyscall)BattleSys_TouchPress,
    (ScriptSyscall)BattleSys_TouchRelease,
    (ScriptSyscall)BattleSys_TouchDragTo,
    (ScriptSyscall)BattleSys_SetCameraPos,
    (ScriptSyscall)BattleSys_SetCameraScale,
    (ScriptSyscall)BattleSys_MoveCameraTo,
    (ScriptSyscall)BattleSys_MoveCameraToTimed,
    (ScriptSyscall)BattleSys_ZoomCamera,
    (ScriptSyscall)BattleSys_SwayCamera,
    (ScriptSyscall)BattleSys_ShakeCamera,
    (ScriptSyscall)BattleSys_SpinCamera,
    (ScriptSyscall)BattleSys_SpinZoomCamera,
    NULL,
};
