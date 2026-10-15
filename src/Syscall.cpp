#include <nitro.h>
#include <string.h>

#include "AudioEngine.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "CTPEmulator.hpp"
#include "CameraController.hpp"
#include "FieldEventRectManage.hpp"
#include "FieldScreenEffectManage.hpp"
#include "FieldSubScreen.hpp"
#include "GlobalValues.hpp"
#include "Log.hpp"
#include "PadInput.hpp"
#include "SaveData.hpp"
#include "SaveDialog.hpp"
#include "SaveManager.hpp"
#include "ScriptManager.hpp"
#include "SubScreenIconMenu.hpp"
#include "TextboxManager.hpp"
#include "TitleBanner.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkStruct_020107A8.hpp"
#include "WindowWipe.hpp"
#include "YesNoPrompt.hpp"
#include "common.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldActorManage.hpp"
#include "field/CFieldEffectExplosion.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldEffectManpu.hpp"
#include "field/CFieldEffectPoisonGas.hpp"
#include "field/CFieldEffectSlime.hpp"
#include "field/CFieldEnemy.hpp"
#include "field/CFieldEnemyManage.hpp"
#include "field/CFieldEventRect.hpp"
#include "field/CFieldNpc.hpp"
#include "field/CFieldPartner.hpp"
#include "field/CFieldPartnerManage.hpp"
#include "field/CFieldPartnerNpc.hpp"
#include "field/CFieldPlayer.hpp"
#include "field/CFieldTargetObject.hpp"
#include "field/CFieldTargetObjectManage.hpp"
#include "fx_utils.hpp"
#include "main.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;
extern CFieldPlayer *MAIN_BSS_0210CA48;
extern CFieldPartnerManage *MAIN_BSS_0210CA4C;
extern CFieldActorManage *MAIN_BSS_0210CA50;
extern CFieldEnemyManage *MAIN_BSS_0210CA5C;
extern CFieldEffectManage *MAIN_BSS_0210CA60;
extern FieldData *MAIN_BSS_0210CA6C;
extern FieldScreenEffectManage *MAIN_BSS_0210CA78;
extern CFieldTargetObjectManage *MAIN_BSS_0210CA7C;
extern SaveData MAIN_BSS_020B26A0;
extern u16 *MAIN_BSS_0210CA70;
extern u32 MAIN_BSS_0210CAB0;
extern u32 MAIN_BSS_0210CA74;
extern SaveManager *MAIN_BSS_0210CA3C;

extern "C" const u32 DAT_02084c7c = 4;

// Nothing calls this (mwld strips it); it keeps DAT_02084c7c in the TU's pooled .rodata, as in the original
extern "C" const u32 *sub_Syscall_Unused()
{
    return &DAT_02084c7c;
}
struct ChapterInfo {
    char name[0x10];
    int x;
    int y;
    int z;
};
extern ChapterInfo s_c000First_0208ac1c[];

static inline AudioEngine *Audio()
{
    return s_game->m_audioEngine;
}

static inline void SetLookAt(CFieldActor *actor, u32 a, u32 b)
{
    actor->m_lookAt = a;
    actor->m_lookAtId = b;
}

extern "C" {
void LogError(const char *fmt, ...);
u32 SaveData_AddPokemonRides(SaveData *save, u32 value);
void BattleStartParam_SetPartnerMood(void *obj, int arg1);
void ov0_0216EE1C(void *obj);
void ov0_0216FEA4(void *obj);
void ov0_0217248C(void *obj);
int SaveData_CountParty(SaveData *save, int group);
void SavePartner_SetName(PartnerSlot *partner, const char *name);
int MissionQuestData_IsQuestCleared(MissionQuestData *obj, int arg1);
void MissionQuestData_ExitQuest(MissionQuestData *obj);
void MissionQuestData_StartQuest(MissionQuestData *obj, int arg1);
int MissionQuestData_IsQuestActive(MissionQuestData *obj, int arg1);
void MissionQuestData_SetQuestEntered(MissionQuestData *obj, int arg1);
int MissionQuestData_IsQuestEntered(MissionQuestData *obj, int arg1);
void MissionQuestData_LoadChapterMessages(MissionQuestData *obj, int arg1);
void MissionQuestData_ReceiveMission(MissionQuestData *obj, int arg1);
void MissionQuestData_StartMission(MissionQuestData *obj);
void MissionQuestData_ClearMission(MissionQuestData *obj);
void MissionQuestData_EnterQuest(MissionQuestData *obj, int arg1);
void MissionQuestData_ExitQuestCleared(MissionQuestData *obj);
void SaveData_EnableEventRect(SaveData *save, int idx, int mapId);
void SaveData_DisableEventRect(SaveData *save, int idx, int mapId);
void ov0_02161FD4(int arg0);
void MissionQuestData_SetChapter(MissionQuestData *missionQuestData, u32 mapIdx);
void sub_02010B08(void *record, u8 arg1);
void BattleStartParam_SetSequenceScript(void *record, u8 arg1);
void BattleStartParam_SetTutorialScript(void *record, u8 arg1);
void BattleStartParam_SetStartScript(void *record, u8 arg1);
void BattleStartParam_SetStylerLevel(void *obj, u8 arg1);
void BattleStartParam_AddPartyMember(void *obj, u16 arg1, u32 arg2);
void BattleStartParam_AddEnemy(void *record, u16 arg1, int arg2);
void BattleStartParam_SetBannerType(void *obj, u8 arg1);
void sub_02010AEC(void *obj, int arg1);
void SaveData_Backup(SaveData *save);
void SaveData_Restore(SaveData *save);
PartnerSlot *SaveData_FindPartner(SaveData *save, u32 id);
int ScriptManager_GetArg(ScriptManager *script);
void ScriptManager_SetNext(ScriptManager *script, int arg1);
void BattleStartParam_SetBgmIndex(void *record, u8 arg1);
void BattleStartParam_SetCaptureBg(void *record, u8 arg1);
void sub_02010AD8(void *record, int arg1);
void LogInfo(const char *fmt, ...);
BOOL SaveData_RemoveFromParty(SaveData *save, u32 id);
void SaveData_DisableActor(SaveData *save, u32 id);
void SaveData_EnableActor(SaveData *save, u32 id);
int SaveData_IsActorEnabled(SaveData *save, u32 id);
CFieldActor *FindScriptActor(u32 id);
CFieldActor *FindEnemyActor(u32 id);
CFieldActor *FindFieldActor(u32 id);
}

static inline void SetAnimSpeed(CFieldActor *actor, fx32 value)
{
    if (actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
        actor->m_drawObject->m_actor->m_animSpeed = value;
    }
}

static inline void Sub02012808(CFieldActor *actor, fx32 value, fx32 speed)
{
    if (actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
        actor->m_drawObject->m_actor->MoveHeightAtSpeed(value, speed);
    }
}

static inline void FindPartyEnemy(u32 id, int &kind, u16 &species)
{
    if (MAIN_BSS_0210CA5C != NULL) {
        for (int i = 0; i < MAIN_BSS_0210CA5C->m_count; i++) {
            CFieldEnemy *enemy = (CFieldEnemy *)MAIN_BSS_0210CA5C->Get(i);
            if (enemy != NULL && id == enemy->m_id) {
                species = enemy->unk_E8;
                kind = 1;
                enemy->unk_20 = 1;
                break;
            }
        }
    }
}

static inline void FindPartyNpc(u32 id, int &kind, u16 &species)
{
    if (MAIN_BSS_0210CA50 != NULL) {
        for (int i = 0; i < MAIN_BSS_0210CA50->m_count; i++) {
            CFieldNpc *npc = (CFieldNpc *)MAIN_BSS_0210CA50->Get(i);
            if (npc != NULL && id == npc->m_id) {
                kind = npc->unk_E8;
                species = npc->unk_EC;
                break;
            }
        }
    }
}

static inline void SetPartnerPos(PartnerSlot *data, Point2D pos)
{
    data->unk_0C.x = pos.x;
    data->unk_0C.y = pos.y;
}

static inline void SetRecordPos(PartyEntry *data, Point2D pos)
{
    data->m_pos.x = pos.x;
    data->m_pos.y = pos.y;
}

static inline void SetSaveName(const char *name)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    if (name != NULL) {
        strcpy(save->m_saveName, name);
    } else {
        save->m_saveName[0] = '\0';
    }
}

static inline void SetSceneFlag(u32 flag)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_flags |= flag;
    }
}

static inline void ClearSceneFlag(u32 flag)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_flags &= ~flag;
    }
}

static inline BOOL IsFading(WindowWipe *fade)
{
    return (fade->unk_0000 & 8) ? TRUE : FALSE;
}

static inline void RestoreHP()
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    int hp = save->m_maxEnergy;
    save->m_energy = hp;
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_hpGauge->SetCurrentHP(hp);
    }
}

// The part object an effect of type 0x12 keeps at +0x1EC (defined in ov0)
class UnkEffectPart {
public:
    virtual void vfunc_00();
    virtual void vfunc_04();
    virtual void vfunc_08();
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
};

typedef int (*ScriptSyscall)(int *args, int argc);

struct EffectParam {
    int arg1;
    int arg2;
};

static EffectParam sEffectParams[41] = {
    { 2, 0x1E },
    { 2, 0x2B },
    { 5, 0x4F },
    { 2, 0x56 },
    { 2, 0x2E },
    { 2, 0x2F },
    { 2, 0x30 },
    { 2, 0x31 },
    { 5, 0x22 },
    { 3, 0x35 },
    { 3, 0x34 },
    { 2, 0x3 },
    { 4, 0x3F },
    { 4, 0x47 },
    { 2, 0x14 },
    { 2, 0x18 },
    { 2, 0x37 },
    { 2, 0x3C },
    { 2, 0x1 },
    { 2, 0x9 },
    { 2, 0xA },
    { 2, 0x1B },
    { 2, 0x7 },
    { 4, 0x2 },
    { 4, 0x41 },
    { 4, 0x43 },
    { 4, 0x4D },
    { 3, 0x32 },
    { 4, 0x21 },
    { 2, 0x39 },
    { 6, 0x8 },
    { 2, 0x19 },
    { 4, 0x3D },
    { 4, 0x3D },
    { 6, 0x12 },
    { 2, 0x51 },
    { 8, 0x36 },
    { 7, 0x5B },
    { 2, 0x3B },
    { 5, 0x20 },
    { 2, 0x20 },
};

static inline u8 GetForm(SaveData *save)
{
    return (save->m_rangerClassGrade >> 4) & 0xF;
}

static inline void SetTouchMode(BOOL on)
{
    s_game->unk_0014->unk_002A = on;
    CTouchPanel *touchPanel = s_game->activeTouchPanel;
    TextboxManager *textbox = s_game->m_textboxData;
    textbox->unk_08C = touchPanel;
    textbox->m_yesNo->m_touch = touchPanel;
}

static inline SaveData *Save()
{
    return (SaveData *)(void *)&MAIN_BSS_020B26A0;
}

static inline TextboxManager *Textbox()
{
    return s_game->m_textboxData;
}

static inline u32 GetPokemonState(SaveData *save, int i)
{
    if (i >= 0 && i < 500) {
        return (save->m_pokemonStates[i >> 4] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

static inline void SetPokemonState(SaveData *save, int i, u32 state)
{
    int shift = (i & 0xF) * 2;
    save->m_pokemonStates[i >> 4] &= ~(3 << shift);
    save->m_pokemonStates[i >> 4] |= state << shift;
}

static inline void RaisePokemonState(SaveData *save, int i, u32 state)
{
    if (i >= 0 && i < 500) {
        if (GetPokemonState(save, i) < state) {
            SetPokemonState(save, i, state);
        }
    }
}

extern "C" {

int sub_0202BC74(const s8 *src, s8 *dst, int len)
{
    int count = 0;
    if (src != NULL && dst != NULL && len != 0) {
        for (int i = 0; i < len; i++) {
            s8 c = src[i];
            dst[i] = c;
            if (c >= 'a' && c <= 'z') {
                dst[i] = c - 0x20;
            }
            if (dst[i] == 0) {
                break;
            }
            count++;
        }
    }
    return count;
}

CFieldActor *FindScriptActor(u32 id)
{
    if (MAIN_BSS_0210CA40 == NULL) {
        return NULL;
    }
    return MAIN_BSS_0210CA40->ov0_02123060(id);
}

CFieldActor *FindEnemyActor(u32 id)
{
    CFieldActorManage *manage = MAIN_BSS_0210CA5C;
    if (manage != NULL) {
        return manage->FindTarget(id);
    }
    return NULL;
}

CFieldActor *FindFieldActor(u32 id)
{
    CFieldActorManage *manage = MAIN_BSS_0210CA50;
    if (manage != NULL) {
        return manage->FindTarget(id);
    }
    return NULL;
}

int Sys_LoadMapBgmGroup(int *args)
{
    Audio()->LoadMapBgmGroup(args[0]);
    return 0;
}

int sub_0202BDE4(int *args)
{
    Audio()->sub_02034F4C(1);
    return 0;
}

int sub_0202BE0C(int *args)
{
    Audio()->sub_02034F4C(0);
    return 0;
}

int Sys_LoadBgmGroup(int *args)
{
    if (args[0] == 0xB1 && MAIN_BSS_020B26A0.m_energy == 0) {
        return 1;
    }
    Audio()->LoadBgmGroup(args[0]);
    return 0;
}

int sub_0202BE78(int *args)
{
    Audio()->sub_02034A08(args[0]);
    return 0;
}

int sub_0202BEA0(int *args)
{
    return 0;
}

int Sys_PlayBgm(int *args)
{
    if (args[0] == 0x1A && MAIN_BSS_020B26A0.m_energy == 0) {
        return 1;
    }
    Audio()->PlayBgm(args[0], args[1]);
    return 0;
}

#define AUDIO_1(name, fn)     \
    int name(int *args)       \
    {                         \
        Audio()->fn(args[0]); \
        return 0;             \
    }
#define AUDIO_2(name, fn)              \
    int name(int *args)                \
    {                                  \
        Audio()->fn(args[0], args[1]); \
        return 0;                      \
    }

AUDIO_1(Sys_StopBgm, StopBgm)
AUDIO_1(Sys_StopBgmReset, StopBgmReset)
AUDIO_1(Sys_SetBgmTempo, SetBgmTempo)
AUDIO_1(Sys_SetBgmVolume, SetBgmVolume)
AUDIO_1(sub_0202BF90, sub_02034BCC)
AUDIO_1(Sys_PlayLoopSe, PlayLoopSe)
AUDIO_1(Sys_StopLoopSe, StopLoopSe)
AUDIO_1(Sys_SetLoopSeVolume, SetLoopSeVolume)
AUDIO_1(Sys_PlaySe, PlaySe)
AUDIO_1(Sys_StopSe, StopSe)
AUDIO_1(Sys_SetSeVolume, SetSeVolume)

int Sys_PlayJingle(int *args)
{
    Audio()->PlayJingle(args[0], args[1], 0x100);
    return 0;
}

AUDIO_1(Sys_StopJingle, StopJingle)
AUDIO_2(Sys_PlayStream, PlayStream)
AUDIO_2(Sys_PlayStream2, PlayStream2)
AUDIO_1(Sys_StopStream2, StopStream2)

int Sys_PlaySolveBgm(int *args)
{
    Audio()->LoadBgmGroup(0x2B);
    Audio()->PlayBgm(8, 0);
    return 0;
}

int Sys_PlayMissionBridgeBgm(int *args)
{
    Audio()->LoadBgmGroup(0x2C);
    Audio()->PlayBgm(9, 0);
    return 0;
}

int Sys_SetAudioVar(int *args)
{
    Audio()->m_scriptVar = args[0];
    return 0;
}

int Sys_GetAudioVar(int *args)
{
    return Audio()->m_scriptVar;
}

int Sys_LoadSystemSe(int *args)
{
    Audio()->LoadSystemSe();
    return 0;
}

int Sys_PlayMapBgm(int *args)
{
    BOOL ok = FALSE;
    if (MAIN_BSS_0210CA78 != NULL) {
        ok = MAIN_BSS_0210CA78->IsEffectActive(9);
        if (GlobalValues_Get((GlobalValues *)s_game->unk_14B4, 0x18) == 0) {
            ok = FALSE;
        }
        if (MAIN_BSS_0210CA6C != NULL) {
            u32 kind = FieldData_GetMap(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.m_mapId)->unk_00 - 0x26;
            if (kind <= 1) {
                ok = FALSE;
            }
        }
    }
    if (ok) {
        Audio()->LoadBgmGroup(0xB1);
        Audio()->PlayBgm(0x1A, 0);
    } else {
        Audio()->PlayMapBgm(MAIN_BSS_020B26A0.m_mapId, args[0], TRUE);
        Audio()->SetLoopSeVolume(0x100);
    }
    return 0;
}

int Sys_PlayPartnerCry(int *args)
{
    if (FindScriptActor(1) == NULL) {
        return 1;
    }
    CFieldPartnerManage *manage = MAIN_BSS_0210CA4C;
    if (manage != NULL) {
        u32 kinds[20] = { 0x1F, 0x5C, 0x63, 0xA7, 0xA1, 0xA4, 0xAA, 0xAF, 0xB6, 0xB7, 0xBC, 0xD2, 0xD5, 0xD7, 0xD9, 0xDC, 0xE2, 0x101, 0x102, 0x103 };
        u32 strms[20] = { 0x42, 0xC8, 0xD7, 0x189, 0x183, 0x186, 0x18C, 0x191, 0x198, 0x19A, 0x1A1, 0x1B7, 0x1BB, 0x1BE, 0x1C1, 0x1C5, 0x1CB, 0x18C, 0x1A1, 0x1BE };
        for (int i = 0; i < 20; i++) {
            if (manage->ov0_0213A520(kinds[i])) {
                Audio()->PlayStream(strms[i], 0x40);
                return 0;
            }
        }
    }
    return 1;
}

AUDIO_2(Sys_PlayGroupSe, PlayGroupSe)

int Sys_SetPokemonSeen(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    RaisePokemonState(save, args[0], 1);
    return 0;
}

int Sys_SetPokemonCaptured(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    RaisePokemonState(save, args[0], 2);
    return 0;
}

int Sys_GetPokemonState(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    return GetPokemonState(save, args[0]);
}

int Sys_CountCapturedPokemon(int *args)
{
    int n = 0;
    for (int i = 0; i < 500; i++) {
        if (GetPokemonState(&MAIN_BSS_020B26A0, i) >= 2) {
            n++;
        }
    }
    return n;
}

int Sys_ClearPokemonState(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    int i = args[0];
    if (i >= 0 && i < 500) {
        SetPokemonState(save, i, 0);
    }
    return 0;
}

int Sys_CheckBrowserComplete(int *args)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    int n = 0;
    for (int i = 0; i < 500; i++) {
        if (GetPokemonState(save, i) >= 2) {
            n++;
        }
    }
    if (GetPokemonState(save, 483) == 2) {
        n--;
    }
    if (GetPokemonState(save, 484) == 2) {
        n--;
    }
    if (GetPokemonState(save, 492) == 2) {
        n--;
    }
    if (n == 266) {
        return 1;
    }
    if (n == 267) {
        return 2;
    }
    return 0;
}

int sub_0202C768(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    RaisePokemonState(save, args[1], 1);
    BOOL flag = FALSE;
    if (GetPokemonState(save, args[1]) != 2) {
        flag = TRUE;
    }
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_subScreen->SwitchToPokemonInfo(args[0], flag);
    }
    return 0;
}

int Sys_ShowMessage(int *args)
{
    Textbox()->ShowMessage(args[0], args[1], args[2], args[3], 0);
    return 0;
}

int Sys_IsTextboxActive(int *args)
{
    return Textbox()->IsActive();
}

int Sys_CloseTextbox(int *args)
{
    Textbox()->CloseAndClear(1, 1);
    return 0;
}

int Sys_SetTextboxParam(int *args)
{
    Textbox()->SetParam(args[0], args[1]);
    return 0;
}

int Sys_SetTextSpeed(int *args)
{
    Textbox()->SetTextSpeed(args[0]);
    return 0;
}

int Sys_ResetTextSpeed(int *args)
{
    Textbox()->ResetTextSpeed();
    return 0;
}

int Sys_SetTextAutoAdvance(int *args)
{
    Textbox()->SetAutoAdvance(args[0]);
    return 0;
}

int Sys_ClearTextAutoAdvance(int *args)
{
    Textbox()->ClearAutoAdvance();
    return 0;
}

int Sys_SetTextAutoClose(int *args)
{
    Textbox()->SetAutoClose(args[0]);
    return 0;
}

int Sys_ClearTextAutoClose(int *args)
{
    Textbox()->ClearAutoClose();
    return 0;
}

int Sys_OpenYesNo(int *args)
{
    Textbox()->OpenYesNo();
    return 0;
}

int Sys_CloseTextboxIfNoPrompt(int *args)
{
    return Textbox()->CloseIfNoPrompt(1);
}

int Sys_GetYesNoResult(int *args)
{
    return Textbox()->GetYesNoResult();
}

int Sys_ShowMessageEx(int *args)
{
    Textbox()->ShowMessage(args[0], args[1], args[2], args[3], args[4]);
    return 0;
}

int Sys_MoveCamera(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_cameraTarget = -1;
    }
    s_game->m_cameraController->MoveToTimed(-(args[0] << 12), -(args[1] << 12), args[2]);
    return 0;
}

int Sys_SetCameraTarget(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_cameraTarget = args[0];
    }
    return 0;
}

int Sys_MoveCameraBetween(int *args)
{
    CFieldActor *a = FindScriptActor(args[0]);
    CFieldActor *b = FindScriptActor(args[1]);
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_cameraTarget = -1;
    }
    int x = 0;
    int y = 0;
    if (a != NULL && b != NULL) {
        x = ((a->GetX() >> 12) + (b->GetX() >> 12)) / 2;
        y = ((a->GetY() >> 12) + (b->GetY() >> 12)) / 2;
    }
    s_game->m_cameraController->MoveToTimed(-(x << 12), -(y << 12), args[2]);
    return 0;
}

int Sys_IsCameraMoving(int *args)
{
    return s_game->m_cameraController->IsMoving() == TRUE ? TRUE : FALSE;
}

int Sys_CameraFollowPlayer(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_cameraTarget = 0;
    }
    return 0;
}

int Sys_FreeCamera(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_cameraTarget = -1;
    }
    return 0;
}

int Sys_GetCameraX(int *args)
{
    UnkStruct_0200D3F8_Target *target = s_game->m_cameraController->m_target;
    if (target != NULL) {
        return -(target->x >> 12);
    }
    return 0;
}

int Sys_GetCameraY(int *args)
{
    UnkStruct_0200D3F8_Target *target = s_game->m_cameraController->m_target;
    if (target != NULL) {
        return -(target->y >> 12);
    }
    return 0;
}

int Sys_FixActorDir(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->sub_020128D8_();
    }
    return 0;
}

int Sys_ActorFaceMoveDir(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->sub_0201287C_();
    }
    return 0;
}

int sub_0202CD8C(int *args)
{
    CFieldActor *a = FindScriptActor(args[0]);
    CFieldActor *b = FindScriptActor(args[1]);
    Point2D pos;
    pos.x = 0;
    pos.y = 0;
    if (a != NULL && b != NULL) {
        pos = b->GetPos();
        if (a->m_drawObject != NULL && a->m_drawObject->m_actor != NULL) {
            a->m_drawObject->m_actor->FaceToward(pos);
        }
        if (a->m_drawObject != NULL && a->m_drawObject->m_actor != NULL) {
            a->m_drawObject->m_actor->FaceMoveDir();
        }
    }
    return 0;
}

int Sys_ActorLookAt(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        SetLookAt(actor, 1, args[1]);
    }
    return 0;
}

int Sys_StopActorLookAt(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->m_lookAt = 0;
        actor->sub_0201287C_();
    }
    return 0;
}

int sub_0202CEDC(int *args)
{
    CFieldActor *a = FindScriptActor(args[0]);
    CFieldActor *b = FindScriptActor(args[1]);
    Point2D posA;
    posA.x = 0;
    posA.y = 0;
    Point2D posB;
    posB.x = 0;
    posB.y = 0;
    if (a != NULL && b != NULL) {
        posA = a->GetPos();
        posB = b->GetPos();
        if (a->m_drawObject != NULL && a->m_drawObject->m_actor != NULL) {
            a->m_drawObject->m_actor->FaceToward(posB);
        }
        if (b->m_drawObject != NULL && b->m_drawObject->m_actor != NULL) {
            b->m_drawObject->m_actor->FaceToward(posA);
        }
        if (a->m_drawObject != NULL && a->m_drawObject->m_actor != NULL) {
            a->m_drawObject->m_actor->FaceMoveDir();
        }
        if (b->m_drawObject != NULL && b->m_drawObject->m_actor != NULL) {
            b->m_drawObject->m_actor->FaceMoveDir();
        }
    }
    return 0;
}

int Sys_SetActorDir(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    u16 dir = args[1];
    if (actor != NULL) {
        if (actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
            actor->m_drawObject->m_actor->SetDir(dir);
        }
        if (actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
            actor->m_drawObject->m_actor->FaceMoveDir();
        }
    }
    return 0;
}

int sub_0202D0D0(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    Point2D pos;
    pos.x = args[1] << 12;
    pos.y = args[2] << 12;
    if (actor != NULL) {
        if (actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
            actor->m_drawObject->m_actor->FaceToward(pos);
        }
        if (actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
            actor->m_drawObject->m_actor->FaceMoveDir();
        }
    }
    return 0;
}

int Sys_GetActorX(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        return actor->GetX() >> 12;
    }
    return 0;
}

int Sys_GetActorY(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        return actor->GetY() >> 12;
    }
    return 0;
}

int Sys_GetActorHeight(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        return actor->GetHeight() >> 12;
    }
    return 0;
}

int Sys_GetActorDir8(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        int dir = actor->GetDir();
        if (dir < 0x1000 || dir >= 0xF000) {
            return 0;
        }
        if (dir < 0x3000) {
            return 0x2000;
        }
        if (dir < 0x5000) {
            return 0x4000;
        }
        if (dir < 0x7000) {
            return 0x6000;
        }
        if (dir < 0x9000) {
            return 0x8000;
        }
        if (dir < 0xB000) {
            return 0xA000;
        }
        if (dir < 0xD000) {
            return 0xC000;
        }
        if (dir < 0xF000) {
            return 0xE000;
        }
    }
    return 0;
}

// FindTarget with the count read in the loop condition (an IRO invariant temp instead of an inline local)
static inline CFieldActor *FindTargetIn(CFieldActorManage *m, u32 id)
{
    for (int i = 0; i < m->m_count; i++) {
        CFieldActor *actor = m->m_actors[i];
        if (actor != NULL && id == actor->m_id) {
            return ((CFieldActor *const *)m->m_actors)[i];
        }
    }
    return NULL;
}

static inline CFieldActor *FindTargetKey(CFieldActorManage *m, u32 id)
{
    int count = m->m_count;
    u32 key = id;
    for (int i = 0; i < count; i++) {
        CFieldActor *actor = m->m_actors[i];
        if (actor != NULL && key == actor->m_id) {
            return ((CFieldActor *const *)m->m_actors)[i];
        }
    }
    return NULL;
}

static inline CFieldPartner *FindByOrderIn(CFieldPartnerManage *m, int order)
{
    for (int i = 0; i < m->m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)m->Get(i);
        if (partner != NULL && order == partner->unk_1E8) {
            return partner;
        }
    }
    return NULL;
}

static inline CFieldActor *FindActor(int id)
{
    switch ((id >> 24) & 0xFF) {
    case 1:
        return FindEnemyActor(id);
    case 2:
        return FindFieldActor(id);
    default:
        return FindScriptActor(id);
    }
}

int Sys_DisableActor(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    if (argc >= 1) {
        int id = args[0];
        SaveData_DisableActor(save, id);
        if (save->m_mapId == ((id >> 12) & 0xFFF)) {
            CFieldActor *actor = FindActor(id);
            if (actor != NULL) {
                Actor_HideManpu(actor);
                actor->unk_20 = 0;
                actor->sub_0202D394();
            }
        }
    }
    return 0;
}
}

void CFieldActor::sub_0202D394()
{
}

extern "C" {
int Sys_EnableActor(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    if (argc >= 1) {
        int id = args[0];
        SaveData_EnableActor(save, id);
        if (save->m_mapId == ((id >> 12) & 0xFFF)) {
            CFieldActor *actor = FindScriptActor(id);
            switch ((id >> 24) & 0xFF) {
            case 1:
                if (actor != NULL && (((int)actor->m_id >> 24) & 0xFF) != 1) {
                    actor = NULL;
                }
                break;
            case 2:
                if (actor != NULL && (((int)actor->m_id >> 24) & 0xFF) != 2) {
                    actor = NULL;
                }
                break;
            }
            if (actor != NULL) {
                actor->unk_20 = 2;
            }
        }
    }
    return 0;
}

int sub_0202D448(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    if (argc >= 2) {
        int id = args[1];
        SaveData_DisableActor(save, id);
        if (save->m_mapId == ((id >> 12) & 0xFFF)) {
            CFieldActor *actor = FindActor(id);
            if (actor != NULL) {
                Actor_HideManpu(actor);
                actor->unk_20 = 0;
                actor->sub_0202D394();
            }
        }
    }
    return 0;
}

int sub_0202D4FC(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    if (argc >= 2) {
        int id = args[1];
        SaveData_EnableActor(save, id);
        if (save->m_mapId == ((id >> 12) & 0xFFF)) {
            CFieldActor *actor = FindScriptActor(id);
            switch ((id >> 24) & 0xFF) {
            case 1:
                if (actor != NULL && (((int)actor->m_id >> 24) & 0xFF) != 1) {
                    actor = NULL;
                }
                break;
            case 2:
                if (actor != NULL && (((int)actor->m_id >> 24) & 0xFF) != 2) {
                    actor = NULL;
                }
                break;
            }
            if (actor != NULL) {
                actor->unk_20 = 2;
            }
        }
    }
    return 0;
}

int Sys_IsActorEnabled(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    if (argc < 1) {
        return 0;
    }
    return SaveData_IsActorEnabled(save, args[0]);
}

int Sys_ShowManpu(int *args)
{
    return Actor_ShowManpu(FindScriptActor(args[0]), args[1], args[2]);
}

int Sys_HideManpu(int *args)
{
    Actor_HideManpu(FindScriptActor(args[0]));
    return 0;
}

int sub_0202D608(int *args)
{
    CFieldActorManage *manage = MAIN_BSS_0210CA5C;
    int id = args[0];
    int a = args[1];
    int b = args[2];
    if (manage != NULL) {
        CFieldActor *actor = FindTargetIn(manage, id);
        if (actor != NULL) {
            return Actor_ShowManpu(actor, a, b);
        }
    }
    return 0;
}

int sub_0202D680(int *args)
{
    CFieldActorManage *manage = MAIN_BSS_0210CA5C;
    u32 id = args[0];
    if (manage != NULL) {
        CFieldActor *actor = manage->FindTarget(id);
        if (actor != NULL) {
            Actor_HideManpu(actor);
        }
    }
    return 0;
}

int Sys_MoveActorTo(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    Point2D pos;
    pos.x = args[1] << 12;
    pos.y = args[2] << 12;
    if (actor != NULL) {
        actor->MoveTo(pos, 0x1000);
    }
    return 0;
}

int Sys_MoveActorToFast(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    Point2D pos;
    pos.x = args[1] << 12;
    pos.y = args[2] << 12;
    if (actor != NULL) {
        actor->MoveTo(pos, 0x2000);
    }
    return 0;
}

int Sys_StopActor(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->StopMotion();
    }
    return 0;
}
}

void CFieldActor::StopMotion()
{
    sub_show();
    sub_0201287C_();
    ResetUnk00C();
}

extern "C" {
int sub_0202D85C(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL && actor->IsUnk00CSet()) {
        return 1;
    }
    return 0;
}

int sub_0202D8BC(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        fx32 y;
        CFieldDrawObject *obj;
        CFieldDrawActor *draw;
        fx32 x;
        y = args[2] << 12;
        x = args[1] << 12;
        obj = actor->m_drawObject;
        if (obj != NULL && (draw = obj->m_actor) != NULL) {
            draw->SetXY(x, y);
            if (obj->m_actor->m_sprite != NULL) {
                obj->m_actor->m_sprite->SetXY(x, y);
            }
        }
    }
    return 0;
}

int Sys_SetActorHeight(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        int z = args[1] << 12;
        if (actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
            actor->m_drawObject->m_actor->m_height = z;
        }
    }
    return 0;
}

int Sys_SetActorMoveDir(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    u16 dir = args[1];
    if (actor != NULL) {
        if (actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
            actor->m_drawObject->m_actor->SetDir(dir);
        }
        if (actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
            actor->m_drawObject->m_actor->FaceMoveDir();
        }
    }
    return 0;
}

int sub_0202D9C0(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        return actor->IsUnk00CSet();
    }
    return 0;
}

BOOL Sys_IsActorOutOfRange(int *args)
{
    CFieldActor *a = FindScriptActor(args[0]);
    CFieldActor *b = FindScriptActor(args[1]);
    if (a != NULL && b != NULL) {
        int r = args[2];
        int dx = (a->GetX() - b->GetX()) >> 12;
        int dy = (a->GetY() - b->GetY()) >> 12;
        if (r * r > dx * dx + dy * dy) {
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

int sub_0202DB00(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->sub_reset();
        actor->ClearUnk004Bit8();
    }
    return 0;
}

int sub_0202DB70(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->sub_show();
        actor->SetUnk004Bit8();
    }
    return 0;
}

int Sys_PlayActorAnim(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->sub_reset();
        actor->PlayAnim(args[1], 0);
    }
    return 0;
}
}

void CFieldActor::PlayAnim(int arg0, int arg1)
{
    sub_02012114_(arg0, arg1);
}

extern "C" {
int sub_0202DC74(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->sub_show();
    }
    return 0;
}

int Sys_GetActorAnimState(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        return actor->GetAnimState();
    }
    return 2;
}

int Sys_SetActorAnimSpeed(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        SetAnimSpeed(actor, args[1]);
    }
    return 0;
}

int sub_0202DD48(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    fx32 speed = args[1] << 12;
    if (actor != NULL && actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
        actor->m_drawObject->m_actor->MoveHeightAtSpeed(0, speed);
    }
    return 0;
}

int sub_0202DD88(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        fx32 dist = args[2] << 12;
        Point2D pos = actor->GetPos();
        pos.x += FX32_MUL(dist, FX_CosIdx(args[1]));
        pos.y += FX32_MUL(dist, FX_SinIdx(args[1]));
        if (dist == 0) {
            if (actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
                actor->m_drawObject->m_actor->Jump(0xF000, 30);
            }
        } else if (actor->m_drawObject != NULL) {
            if (actor->m_drawObject->m_actor != NULL) {
                actor->m_drawObject->m_actor->Jump(0xA000, 30);
            }
            if (actor->m_drawObject->m_actor != NULL) {
                actor->m_drawObject->m_actor->m_motion.MoveLinear(pos, 30);
            }
        }
    }
    return 0;
}

int sub_0202DEE8(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        fx32 dist = args[2] << 12;
        Point2D pos = actor->GetPos();
        pos.x += FX32_MUL(dist, FX_CosIdx(args[1]));
        pos.y += FX32_MUL(dist, FX_SinIdx(args[1]));
        if (dist == 0) {
            u16 frames = args[3];
            fx32 jump = args[4] << 12;
            if (actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
                actor->m_drawObject->m_actor->Jump(jump, frames);
            }
        } else {
            u16 frames = args[3];
            fx32 jump = args[4] << 12;
            if (actor->m_drawObject != NULL) {
                if (actor->m_drawObject->m_actor != NULL) {
                    actor->m_drawObject->m_actor->Jump(jump, frames);
                }
                if (actor->m_drawObject->m_actor != NULL) {
                    actor->m_drawObject->m_actor->m_motion.MoveLinear(pos, frames);
                }
            }
        }
    }
    return 0;
}

int sub_0202E060(int *args)
{
    return 0;
}

int sub_0202E068(int *args)
{
    return 0;
}

int sub_0202E070(u32 *args)
{
    u32 id = args[0];
    int kind = -1;
    u16 species = 0;
    switch (((s32)id >> 24) & 0xFF) {
    case 1:
        FindPartyEnemy(id, kind, species);
        break;
    case 2:
        FindPartyNpc(id, kind, species);
        break;
    }
    if (kind != -1) {
        BOOL isPokemon;
        u16 flags;
        if (kind == 0) {
            flags = 0x1E16;
            isPokemon = TRUE;
        } else {
            isPokemon = FALSE;
            flags = 0xE;
        }
        if (MAIN_BSS_0210CA4C != NULL) {
            MAIN_BSS_0210CA4C->ov0_0213A360(id, species, flags, isPokemon, TRUE);
        }
        if (!isPokemon) {
            FieldSubScreen *subScreen = FieldSubScreen::GetInstance();
            if (subScreen != NULL) {
                subScreen->sub_02022B20();
            }
        }
    } else {
        LogError("_syscall_actor_party_add error");
    }
    return -1;
}

void LogError(const char *fmt, ...)
{
    // va_start without MSL's alignment of the parameter address
    va_list args = (va_list)(&fmt + 1);
    thunk_FUN_020442cc(fmt, args);
}

int sub_0202E210(int *args)
{
    if (FindScriptActor(1) != NULL) {
        return 1;
    }
    u32 id;
    u16 kind;
    switch (args[0]) {
    case 0:
        id = 0x02032003;
        kind = 0x63;
        break;
    case 1:
        id = 0x02032004;
        kind = 0xBC;
        break;
    case 2:
        id = 0x02032005;
        kind = 0xAA;
        break;
    case 3:
        id = 0x02032006;
        kind = 0xB6;
        break;
    case 4:
        id = 0x02032007;
        kind = 0x5C;
        break;
    case 5:
        id = 0x02032008;
        kind = 0xAF;
        break;
    case 6:
        id = 0x02032009;
        kind = 0xB7;
        break;
    case 7:
        id = 0x0203200A;
        kind = 0xD7;
        break;
    default:
        id = 0x0203200B;
        kind = 0x1F;
        break;
    }
    if (MAIN_BSS_0210CA4C == NULL) {
        return -1;
    }
    MAIN_BSS_0210CA4C->ov0_0213A360(id, kind, 0xE, FALSE, TRUE);
    return 0;
}

int sub_0202E330(int *args)
{
    CFieldPartnerManage *manage = MAIN_BSS_0210CA4C;
    u32 id = args[1];
    if (manage != NULL) {
        for (int i = 0; i < manage->m_count; i++) {
            CFieldPartner *partner = (CFieldPartner *)manage->Get(i);
            if (partner != NULL) {
                LogInfo("*************");
                LogInfo("NPC= %d", i);
                LogInfo("Id= %x", partner->m_id);
                LogInfo("partnertype= %d", partner->unk_1FC);
                LogInfo("linenumber= %d", partner->unk_1E8);
                LogInfo("*************");
            }
        }
        manage->ov0_0213A050(id);
        SaveData_RemoveFromParty(&MAIN_BSS_020B26A0, id);
        LogInfo("party leave : %x", id);
        return 0;
    }
    LogInfo("error actor_party_add id= %x", id);
    return -1;
}

int sub_0202E43C(int *args)
{
    CFieldPartnerManage *manage = MAIN_BSS_0210CA4C;
    u32 id = args[1];
    if (manage != NULL) {
        for (int i = 0; i < manage->m_count; i++) {
            CFieldPartner *partner = (CFieldPartner *)manage->Get(i);
            if (partner != NULL) {
                LogInfo("*************");
                LogInfo("NPC= %d", i);
                LogInfo("Id= %x", partner->m_id);
                LogInfo("partnertype= %d", partner->unk_1FC);
                LogInfo("linenumber= %d", partner->unk_1E8);
                LogInfo("*************");
            }
        }
        manage->ov0_0213A084(id);
        SaveData_RemoveFromParty(&MAIN_BSS_020B26A0, id);
        LogInfo("party leave : %x", id);
        return 0;
    }
    LogInfo("error actor_party_add id= %x", id);
    return -1;
}

int sub_0202E548(int *args)
{
    return 0;
}

int sub_0202E550(int *args)
{
    return 0;
}

int sub_0202E558(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        Point2D pos;
        UnkStruct_0200D3F8_Target *target = s_game->m_cameraController->m_target;
        if (target != NULL) {
            pos.x = -target->x;
            pos.y = -target->y;
        } else {
            pos.x = actor->GetX();
            pos.y = actor->GetY();
        }
        actor->m_flags |= 0x100;
        actor->StartMoveTo(pos);
    }
    return 0;
}

int sub_0202E61C(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        return actor->IsC8Set();
    }
    return 0;
}

int Sys_SetActorLayer(int *args)
{
    u32 id = args[0];
    int value = args[1];
    CFieldActor *actor = FindScriptActor(id);
    if (actor != NULL) {
        actor->SetLayer(value);
    }
    if (id == 0) {
        MAIN_BSS_020B26A0.m_layer = value;
    }
    return 0;
}
}

void CFieldActor::SetLayer(int arg0)
{
    m_layer = arg0;
}

extern "C" {
int Sys_SetActorNotSolid(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->m_flags |= 0x80;
    }
    return 0;
}

int Sys_ClearActorNotSolid(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->m_flags &= ~0x80;
    }
    return 0;
}

int Sys_MoveActorToSlow(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    Point2D pos;
    pos.x = args[1] << 12;
    pos.y = args[2] << 12;
    if (actor != NULL) {
        actor->MoveTo(pos, 0x800);
    }
    return 0;
}

int Sys_ActorOrbit(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    Point2D center;
    center.x = args[1] << 12;
    center.y = args[2] << 12;
    fx32 radiusX = args[3] << 12;
    fx32 radiusY = args[4] << 12;
    u16 angle = args[5];
    u16 speed = args[6];
    if (actor != NULL && actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
        actor->m_drawObject->m_actor->m_motion.Orbit(center, radiusX, radiusY, angle, speed, 0);
    }
    return 0;
}

int Sys_IsActorJumping(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        return actor->IsJumping();
    }
    return 0;
}

int sub_0202E81C(int *args)
{
    int id = args[0];
    CFieldActor *actor = FindScriptActor(id);
    if (actor != NULL) {
        return actor->unk_20;
    }
    SaveData *save = &MAIN_BSS_020B26A0;
    switch ((id >> 24) & 0xFF) {
    case 1: {
        int i = id & 0xFFF;
        int mapId = (id >> 12) & 0xFFF;
        int state = save->GetEnemyState(mapId, i);
        if (state > 0) {
            return state - 1;
        }
        break;
    }
    case 2: {
        int i = id & 0xFFF;
        int mapId = (id >> 12) & 0xFFF;
        int state = save->GetNpcState(mapId, i);
        if (state > 0) {
            return state - 1;
        }
        break;
    }
    case 3: {
        int i = id & 0xFFF;
        int mapId = (id >> 12) & 0xFFF;
        int state = save->GetObjectState(mapId, i);
        if (state > 0) {
            return state - 1;
        }
        break;
    }
    }
    return 0;
}

int sub_0202E9C0(int *args)
{
    int id = args[0];
    CFieldActor *actor = FindEnemyActor(id);
    if (actor != NULL) {
        return actor->unk_20;
    }
    SaveData *save = &MAIN_BSS_020B26A0;
    int i = id & 0xFFF;
    int mapId = (id >> 12) & 0xFFF;
    int state = save->GetEnemyState(mapId, i);
    if (state > 0) {
        return state - 1;
    }
    return 0;
}

int sub_0202EA5C(int *args)
{
    int id = args[0];
    int value = args[1];
    CFieldActor *actor = FindScriptActor(id);
    if (actor != NULL) {
        actor->unk_20 = value;
    }
    SaveData *save = &MAIN_BSS_020B26A0;
    switch ((id >> 24) & 0xFF) {
    case 1: {
        int i = id & 0xFFF;
        int mapId = (id >> 12) & 0xFFF;
        save->SetEnemyState(mapId, i, value + 1);
        break;
    }
    case 2: {
        int i = id & 0xFFF;
        int mapId = (id >> 12) & 0xFFF;
        save->SetNpcState(mapId, i, value + 1);
        break;
    }
    case 3: {
        int i = id & 0xFFF;
        int mapId = (id >> 12) & 0xFFF;
        save->SetObjectState(mapId, i, value + 1);
        break;
    }
    }
    return 0;
}

static inline void StartOutline(CFieldActor *actor, u16 color, int time)
{
    if (actor->m_drawObject != NULL) {
        CFieldDrawActor *draw = actor->m_drawObject->m_actor;
        if (draw != NULL) {
            draw->m_outlinePhase = 0;
        }
        draw = actor->m_drawObject->m_actor;
        if (draw != NULL) {
            draw->m_outlineColor = color;
            draw->m_outlinePhase = 0;
        }
        draw = actor->m_drawObject->m_actor;
        if (draw != NULL) {
            draw->m_outlineWidth = 2;
        }
        draw = actor->m_drawObject->m_actor;
        if (draw != NULL) {
            draw->m_effectFlags |= 1;
            draw->m_outlineTime = time;
            draw->m_outlinePhase = 0;
        }
    }
}

int sub_0202EC08(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        u16 color = 0x7FFF;
        switch (((int)actor->m_id >> 24) & 0xFF) {
        case 0:
            color = 0x7FE0;
            break;
        case 1:
            color = 0x1F;
            break;
        case 2:
            color = 0x3F0;
            break;
        case 3:
            color = 0x3F0;
            break;
        case 4:
            color = 0x7FE0;
            break;
        case 5:
            color = 0x7FE0;
            break;
        case 6:
            color = 0x7FE0;
            break;
        }
        StartOutline(actor, color, -1);
    }
    return 0;
}

int Sys_StartActorOutline(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        StartOutline(actor, args[1] | (args[2] << 5) | (args[3] << 10), args[4]);
    }
    return 0;
}

int Sys_StopActorOutline(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL && actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
        actor->m_drawObject->m_actor->m_effectFlags &= ~1;
    }
    return 0;
}

int sub_0202EDFC(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->ov0_0212451C();
    }
    return 0;
}

int Sys_HideActor(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->m_flags |= 1;
    }
    return 0;
}

int Sys_UnhideActor(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->m_flags &= ~1;
    }
    return 0;
}

int Sys_FadeActorAlpha(int *args)
{
    int alpha = args[1];
    int duration = args[2];
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL && actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
        actor->m_drawObject->m_actor->FadeAlpha(duration, alpha);
    }
    return 0;
}

int Sys_ShakeActor(int *args)
{
    u8 a = args[2];
    u8 b = args[3];
    int time = args[1];
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL && actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
        CFieldDrawActor *draw = actor->m_drawObject->m_actor;
        draw->m_effectFlags |= 4;
        draw->m_shakeRangeX = a;
        draw->m_shakeRangeY = b;
        if (time <= 0) {
            time = -1;
        }
        draw->m_shakeTime = time;
    }
    return 0;
}

int Sys_StopActorShake(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL && actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
        CFieldDrawActor *draw = actor->m_drawObject->m_actor;
        draw->m_effectFlags &= ~4;
        draw->m_shakeRangeX = 0;
        draw->m_shakeRangeY = 0;
        draw->m_shakeTime = 0;
    }
    return 0;
}

int Sys_SetActorOnTop(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->m_flags |= 0x100;
    }
    return 0;
}

int Sys_ClearActorOnTop(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->m_flags &= ~0x100;
    }
    return 0;
}

int Sys_RotateActor(int *args)
{
    int value = args[1];
    int duration = args[2];
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL && actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
        actor->m_drawObject->m_actor->RotateTo(duration, value);
    }
    return 0;
}

int Sys_StartActorBlink(int *args)
{
    u16 color = args[1] | (args[2] << 5) | (args[3] << 10);
    u8 alpha = args[4];
    int duration = args[5];
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL && actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
        actor->m_drawObject->m_actor->StartColorBlink(color, alpha, duration);
    }
    return 0;
}

int Sys_StopActorBlink(int *args)
{
    int duration = args[1];
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL && actor->m_drawObject != NULL && actor->m_drawObject->m_actor != NULL) {
        actor->m_drawObject->m_actor->StopBlink(duration);
    }
    return 0;
}

int Sys_HideActorShadow(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->m_hasShadow = 0;
    }
    return 0;
}

int Sys_ShowActorShadow(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->m_hasShadow = 1;
    }
    return 0;
}

int sub_0202F0A8(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        s8 a = args[1];
        s8 b = args[2];
        s8 c = args[3];
        s8 d = args[4];
        actor->SetUnkBC(a, b);
        actor->SetUnkBE(c, d);
    }
    return 0;
}

int sub_0202F0E4(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if ((((int)actor->m_id >> 24) & 0xFF) == 6) {
        UnkStruct_020107A8 *record = PokeIdTable_Get(s_game->unk_1434, ((CFieldPartner *)actor)->unk_200);
        if (record != NULL) {
            return record->unk_06;
        }
    }
    return 0;
}

int Sys_ResetBattleParams(int *args)
{
    BattleStartParam_Reset(s_game->unk_143C);
    sub_02010D04(s_game->unk_1444);
    return 0;
}

int Sys_SetSaveName2(int *args)
{
    const char *name = (const char *)args[0];
    SaveData *save = &MAIN_BSS_020B26A0;
    if (name != NULL) {
        strcpy(save->m_saveName, name);
    } else {
        save->m_saveName[0] = '\0';
    }
    return 0;
}

int Sys_ClearSaveName(int *args)
{
    MAIN_BSS_020B26A0.m_saveName[0] = '\0';
    return 0;
}

int sub_0202F1C0(int *args)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    CBattleResultParameter *battle = s_game->unk_1444;
    if (scene != NULL && battle != NULL) {
        battle->unk_0C = 1;
        scene->m_flags |= 1;
    }
    return 0;
}

int sub_0202F208(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->ov0_02122FEC(args[0], -1, -1);
    }
    return 0;
}

int Sys_SetBattleBgm(int *args)
{
    BattleStartParam_SetBgmIndex(s_game->unk_143C, args[0]);
    return 0;
}

int Sys_SetBattleCaptureBg(int *args)
{
    BattleStartParam_SetCaptureBg(s_game->unk_143C, args[0]);
    return 0;
}

int sub_0202F294(int *args)
{
    return 0;
}

int sub_0202F29C(int *args)
{
    return 0;
}

int sub_0202F2A4(int *args)
{
    return 0;
}

int sub_0202F2AC(int *args)
{
    return 0;
}

int sub_0202F2B4(int *args)
{
    CBattleResultParameter *battle = s_game->unk_1444;
    if (battle != NULL) {
        return battle->unk_08;
    }
    return 0;
}

int sub_0202F2D8(int *args)
{
    sub_02010AD8(s_game->unk_143C, 0);
    return 0;
}

int sub_0202F300(int *args)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    CBattleResultParameter *battle = s_game->unk_1444;
    if (scene != NULL && battle != NULL) {
        battle->unk_0C = 1;
        scene->m_flags |= 1;
    }
    return 0;
}
int sub_0202F348(int *args)
{
    sub_02010B08(s_game->unk_143C, args[0]);
    return 0;
}

int Sys_SetBattleSequenceScript(int *args)
{
    BattleStartParam_SetSequenceScript(s_game->unk_143C, args[0]);
    return 0;
}

int Sys_SetBattleTutorialScript(int *args)
{
    BattleStartParam_SetTutorialScript(s_game->unk_143C, args[0]);
    return 0;
}

int Sys_SetBattleStartScript(int *args)
{
    BattleStartParam_SetStartScript(s_game->unk_143C, args[0]);
    return 0;
}

int Sys_SetBattleStylerLevel(int *args)
{
    BattleStartParam_SetStylerLevel(s_game->unk_143C, args[0]);
    return 0;
}

int Sys_AddBattlePartyMember(int *args)
{
    BattleStartParam_AddPartyMember(s_game->unk_143C, args[0], 1);
    return 0;
}

int Sys_AddBattleEnemy(int *args)
{
    BattleStartParam_AddEnemy(s_game->unk_143C, args[0], (u8)args[1]);
    CBattleResultParameter *battle = s_game->unk_1444;
    u8 n = battle->unk_14++;
    battle->unk_18[n] = 0;
    battle->unk_38[n] = args[0];
    return 0;
}

int Sys_SetBattleBanner(int *args)
{
    BattleStartParam_SetBannerType(s_game->unk_143C, args[0]);
    return 0;
}

int sub_0202F4E8(int *args)
{
    sub_02010AEC(s_game->unk_143C, 1);
    return 0;
}

int Sys_BackupSave(int *args)
{
    SaveData_Backup(&MAIN_BSS_020B26A0);
    return 0;
}

int Sys_RestoreSave(int *args)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    SaveData_Restore(save);
    CFieldPartnerManage *manage = MAIN_BSS_0210CA4C;
    if (manage != NULL) {
        manage->Clear();
        for (int i = 0; i < 2; i++) {
            PartnerSlot *partner = save->GetPartner(i);
            if (partner != NULL && partner->unk_00 != 0) {
                int index = manage->ov0_02139920(partner->unk_04, partner->unk_08, 0x1E16, TRUE, TRUE);
                if (index >= 0) {
                    CFieldActor *actor = manage->Get(index);
                    if (actor != NULL) {
                        actor->SetPos(partner->unk_0C);
                        actor->sub_020128EC_(partner->unk_0A);
                        actor->sub_0201287C_();
                        ((CFieldPartnerNpc *)actor)->SetName(partner->unk_14);
                    }
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            PartyEntry *record = SaveData_GetEntry(save, i);
            if (record != NULL && (record->m_flags & 1)) {
                manage->ov0_02139920((record->m_index & 0xFFF) | (((record->m_mapId & 0xFFF) << 12) | 0x6000000),
                    record->m_kind,
                    0xE,
                    FALSE,
                    TRUE);
            }
        }
    }
    CPlayerHPGauge *gauge;
    if (MAIN_BSS_0210CA40 != NULL && (gauge = MAIN_BSS_0210CA40->m_hpGauge) != NULL) {
        gauge->SetHP(save->m_energy, save->m_maxEnergy);
        gauge->SetPartner(save->unk_0004 >> 12, save->unk_0008);
    }
    FieldSubScreen *subScreen = FieldSubScreen::GetInstance();
    if (subScreen != NULL) {
        subScreen->sub_02022B20();
    }
    return 0;
}

int Sys_GetScriptArg(int *args, int argc)
{
    return ScriptManager_GetArg(s_game->m_scriptManager);
}

int sub_0202F784(int *args)
{
    return 0;
}

int sub_0202F78C(int *args)
{
    return 0;
}

int sub_0202F794(int *args)
{
    return 0;
}

int sub_0202F79C(int *args)
{
    return 0;
}

int sub_0202F7A4(int *args)
{
    return 0;
}

int sub_0202F7AC(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_flags |= 0x200000;
    }
    u32 id = Sys_GetScriptArg(args, argc);
    if (id != 0) {
        CFieldActor *actor = FindScriptActor(id);
        SaveData *save = &MAIN_BSS_020B26A0;
        if (actor != NULL && save != NULL) {
            Point2D pos = actor->GetPos();
            pos.y += 0x2C000;
            int layer = actor->m_layer;
            int i;
            CFieldPartnerManage *manage = MAIN_BSS_0210CA4C;
            save->SetPos(pos);
            save->m_dir = 0x4000;
            save->m_layer = layer;
            if (manage != NULL) {
                for (i = 0; i < manage->m_count; i++) {
                    CFieldActor *partner = manage->Get(i);
                    if (partner != NULL) {
                        switch (((s32)partner->m_id >> 24) & 0xFF) {
                        case 5: {
                            PartnerSlot *data = SaveData_FindPartner(save, partner->m_id);
                            if (data != NULL) {
                                SetPartnerPos(data, pos);
                                data->unk_34 = layer;
                                data->unk_0A = 0x4000;
                            }
                            break;
                        }
                        case 6: {
                            PartyEntry *data = SaveData_FindEntry(save, partner->m_id);
                            if (data != NULL) {
                                data->SetPos(pos);
                                data->m_layer = layer;
                                data->unk_14 = 0x4000;
                            }
                            break;
                        }
                        }
                    }
                }
            }
        }
    }
    SaveDialog::Create();
    SaveDialog::GetInstance()->sub_02027A2C();
    return 0;
}

int Sys_UpdateSaveDialog(int *args)
{
    SaveDialog *inst = SaveDialog::GetInstance();
    BOOL result = FALSE;
    if (inst != NULL) {
        result = SaveDialog::GetInstance()->Update();
        if (!result) {
            SAFE_DELETE(MAIN_BSS_0210C1BC);
            if (MAIN_BSS_0210CA40 != NULL) {
                MAIN_BSS_0210CA40->m_flags &= ~0x200000;
            }
        }
    }
    return result;
}

int Sys_SetNextScript(int *args)
{
    ScriptManager_SetNext(s_game->m_scriptManager, args[0]);
    return 0;
}

int sub_0202FA24(int *args)
{
    if (MAIN_BSS_0210CA70 != NULL) {
        return MAIN_BSS_0210CA70[2];
    }
    return 0xFFFF;
}

int Sys_GetSex(int *args)
{
    return MAIN_BSS_020B26A0.m_sex;
}

int Sys_GetRangerClass(int *args)
{
    return MAIN_BSS_020B26A0.m_rangerClassGrade & 0xF;
}

int Sys_GetRangerGrade(int *args)
{
    return (MAIN_BSS_020B26A0.m_rangerClassGrade >> 4) & 0xF;
}

int Sys_OpenLetter(int *args)
{
    Audio()->StopBgmReset(30);
    Audio()->StopLoopSe(30);
    SetSaveName((const char *)args[1]);
    s_game->m_scriptManager->unk_18 = 1;
    s_game->m_missionQuestData->unk_10 = args[0];
    SetSceneFlag(0x20);
    return 0;
}

int Sys_SetSex(int *args)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    u8 old = save->m_sex;
    save->m_sex = (u8)args[0] & 1;
    CFieldPlayer *player;
    if (save->m_sex != old && (player = MAIN_BSS_0210CA48) != NULL) {
        Point2D pos = player->GetPos();
        player->ov0_02132F14(save->m_sex, GetForm(save), save->m_areaType);
        player->ov0_02132FA0(save->unk_8802);
        player->SetPos(pos);
    }
    return 0;
}

int Sys_SetRangerClass(int *args)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    int before = SaveData_GetPartyCapacity(save, 0xFF);
    save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF0) | (u8)args[0];
    if (before != SaveData_GetPartyCapacity(save, 0xFF)) {
        FieldSubScreen *subScreen = FieldSubScreen::GetInstance();
        if (subScreen != NULL) {
            subScreen->sub_02022B20();
        }
    }
    return 0;
}

int Sys_SetRangerGrade(int *args)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    int old = (save->m_rangerClassGrade >> 4) & 0xF;
    save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF) | ((u8)args[0] << 4);
    CFieldPlayer *player;
    if (((save->m_rangerClassGrade >> 4) & 0xF) != old && (player = MAIN_BSS_0210CA48) != NULL) {
        Point2D pos = player->GetPos();
        player->ov0_02132F14(save->m_sex, GetForm(save), save->m_areaType);
        player->ov0_02132FA0(save->unk_8802);
        player->SetPos(pos);
    }
    return 0;
}

int sub_0202FE28(int *args)
{
    return 0;
}

int Sys_SetStylerLevel(int *args)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    SaveData_SetStylerLevel(save, (u8)args[0]);
    if (MAIN_BSS_0210CA40 != NULL) {
        CPlayerHPGauge *gauge = MAIN_BSS_0210CA40->m_hpGauge;
        int max = save->m_maxEnergy;
        int hp = save->m_energy;
        if (gauge != NULL) {
            if (max == 0) {
                gauge->SetCurrentHP(hp);
            } else {
                gauge->SetHP(hp, max);
            }
        }
    }
    return 0;
}

int Sys_GetStylerLevel(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save != NULL) {
        return save->m_stylerLevel;
    }
    return 0;
}

int Sys_SetHP(int *args)
{
    int hp = args[0];
    SaveData *save = &MAIN_BSS_020B26A0;
    if (hp == 0) {
        hp = save->m_maxEnergy;
    }
    save->m_energy = hp;
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_hpGauge->SetCurrentHP(hp);
    }
    return 0;
}

int Sys_GetMaxHP(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save != NULL) {
        return save->m_maxEnergy;
    }
    return 0;
}

int Sys_GetHP(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save != NULL) {
        return save->m_energy;
    }
    return 0;
}

int sub_0202FF38(int *args)
{
    sub_020010E4();
    return 0;
}

int sub_0202FF48(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        UnkStruct_020107A8 *record;
        switch (((int)actor->m_id >> 24) & 0xFF) {
        case 1:
            record = PokeIdTable_Get(s_game->unk_1434, ((CFieldEnemy *)actor)->unk_E8);
            if (record != NULL) {
                return record->unk_00;
            }
            break;
        case 6:
            record = PokeIdTable_Get(s_game->unk_1434, ((CFieldPartner *)actor)->unk_200);
            if (record != NULL) {
                return record->unk_00;
            }
            break;
        }
    }
    return 0;
}

int sub_0202FFE4(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    FieldData *table = MAIN_BSS_0210CA6C;
    if (actor != NULL && table != NULL) {
        switch (((int)actor->m_id >> 24) & 0xFF) {
        case 1:
            return ((CFieldEnemy *)actor)->unk_E8;
        case 6:
            return ((CFieldPartner *)actor)->unk_200;
        }
    }
    return 0;
}

int Sys_SetScriptArg(int *args)
{
    ScriptManager_SetArg(s_game->m_scriptManager, args[0]);
    return 0;
}

int sub_02030068(int *args)
{
    u8 n = s_game->unk_14A4->unk_8802;
    if (n <= 1) {
        return 0;
    }
    return n - 1;
}

int Sys_OpenStyler(int *args)
{
    SetSceneFlag(0x2000);
    return 0;
}

int sub_020300B8(int *args)
{
    GlobalValues_Set((GlobalValues *)s_game->unk_14B4, 3, args[0]);
    Textbox()->LoadSystemMessages(3);
    return 0;
}

int Sys_HideHud(int *args)
{
    SetSceneFlag(0x800);
    return 0;
}

int Sys_ShowHud(int *args)
{
    ClearSceneFlag(0x800);
    return 0;
}

int Sys_HideField(int *args)
{
    SetSceneFlag(0x1000);
    return 0;
}

int Sys_ShowField(int *args)
{
    ClearSceneFlag(0x1000);
    return 0;
}

int Sys_GameOver(int *args)
{
    SetSceneFlag(0x4000);
    return 0;
}

int Sys_StartStaffroll(int *args)
{
    SetSceneFlag(0x8000);
    return 0;
}

int Sys_OpenSuitePicture(int *args)
{
    u32 value = args[0];
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        MAIN_BSS_0210CAB0 = value;
        scene->m_flags |= 0x10000;
    }
    return 0;
}

int Sys_OpenRecord(int *args)
{
    SetSceneFlag(0x20000);
    return 0;
}

int Sys_OpenNameInput(int *args)
{
    Audio()->StopBgmReset(30);
    Audio()->StopLoopSe(30);
    GlobalValues_ClearChapterValues((GlobalValues *)s_game->unk_14B4);
    GlobalValues_ApplyProgress((GlobalValues *)s_game->unk_14B4, args[0]);
    MissionQuestData_SetChapter(s_game->m_missionQuestData, args[0]);
    SaveData *save = &MAIN_BSS_020B26A0;
    const char *name = s_c000First_0208ac1c[args[0]].name;
    if (name != NULL) {
        strcpy(save->m_saveName, name);
    } else {
        save->m_saveName[0] = '\0';
    }
    s_game->m_scriptManager->unk_18 = 1;
    SetSceneFlag(0x40000);
    return 0;
}

int Sys_OpenOpeningDemo(int *args)
{
    Audio()->StopBgmReset(30);
    Audio()->StopLoopSe(30);
    Audio()->sub_02034F4C(1);
    GlobalValues_ClearChapterValues((GlobalValues *)s_game->unk_14B4);
    GlobalValues_ApplyProgress((GlobalValues *)s_game->unk_14B4, 4);
    MissionQuestData_SetChapter(s_game->m_missionQuestData, 4);
    SaveData *save = &MAIN_BSS_020B26A0;
    const char *name = s_c000First_0208ac1c[4].name;
    if (name != NULL) {
        strcpy(save->m_saveName, name);
    } else {
        save->m_saveName[0] = '\0';
    }
    s_game->m_scriptManager->unk_18 = 1;
    SetSceneFlag(0x100000);
    return 0;
}

int Sys_EndDownloadMission(int *args)
{
    SetSceneFlag(0x80000);
    return 0;
}

int sub_0203044C(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save != NULL) {
        return save->unk_81AC;
    }
    return 0;
}

int Sys_ShowTitleBanner(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_banner->Show(200);
    }
    return 0;
}

int Sys_IsTitleBannerActive(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        return MAIN_BSS_0210CA40->m_banner->GetState() != 8 ? TRUE : FALSE;
    }
    return FALSE;
}

int Sys_ReleaseTitleBanner(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_banner->Release();
    }
    return 0;
}

int Sys_IsHPChanging(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL && MAIN_BSS_0210CA40->m_hpGauge->IsHPChanging()) {
        return TRUE;
    }
    return FALSE;
}

int Sys_ShowSubScreenPicture(int *args)
{
    FieldSubScreen *subScreen = FieldSubScreen::GetInstance();
    if (subScreen != NULL) {
        subScreen->ShowPicture(args[0]);
    }
    return 0;
}

int sub_0203054C(int *args)
{
    FieldSubScreen *subScreen = FieldSubScreen::GetInstance();
    if (subScreen != NULL) {
        subScreen->sub_02022EC4();
        subScreen->SwitchToDefaultPanel();
    }
    return 0;
}

int Sys_SwitchSubScreenToMap(int *args)
{
    FieldSubScreen *subScreen = FieldSubScreen::GetInstance();
    if (subScreen != NULL) {
        subScreen->SwitchToAreaMap(-1000, -1000, -1000);
    }
    return 0;
}

int sub_0203059C(int *args)
{
    s_game->touchPanelEmulator->func0();
    return 0;
}

int Sys_PressTouch(int *args)
{
    s_game->touchPanelEmulator->Press(args[0] << 12, args[1] << 12);
    return 0;
}

int Sys_ReleaseTouch(int *args)
{
    s_game->touchPanelEmulator->Release();
    return 0;
}

int Sys_DragTouch(int *args)
{
    s_game->touchPanelEmulator->DragTo(args[0] << 12, args[1] << 12, args[2]);
    return 0;
}

int sub_0203064C(int *args)
{
    return s_game->touchPanelEmulator->unk_30;
}

int Sys_SetTouchMode(int *args)
{
    if (args[0] == 0) {
        s_game->SetTouchPanelMode(0);
        SetTouchMode(FALSE);
    } else {
        s_game->SetTouchPanelMode(1);
        SetTouchMode(TRUE);
    }
    return 0;
}

int Sys_SetSubScreenIdleReturn(int *args)
{
    FieldSubScreen *subScreen = FieldSubScreen::GetInstance();
    if (subScreen != NULL) {
        if (args[0] == 0) {
            subScreen->SetIdleReturn(1);
        } else {
            subScreen->SetIdleReturn(0);
        }
    }
    return 0;
}

int Sys_ShowRangerCard(int *args)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        scene->m_iconMenu->OpenTimed(args[0]);
        scene->m_subScreen->SwitchToRangerCard();
    }
    return 0;
}

int Sys_FadeOutBlack(int *args)
{
    MAIN_BSS_0210CA40->m_subScreen->unk_60 = 1;
    s_game->m_mainFade->Start(4, args[0]);
    if (s_game->m_subFade->GetMode() != 4) {
        s_game->m_subFade->Start(4, args[0]);
    }
    return 0;
}

int Sys_FadeOutWhite(int *args)
{
    MAIN_BSS_0210CA40->m_subScreen->unk_60 = 1;
    s_game->m_mainFade->Start(2, args[0]);
    s_game->m_subFade->Start(2, args[0]);
    return 0;
}

int Sys_WipeOut(int *args)
{
    MAIN_BSS_0210CA40->m_subScreen->unk_60 = 1;
    if (s_game->m_subFade->GetMode() != 4) {
        s_game->m_subFade->Start(4, args[0]);
    }
    s_game->m_mainWipe->Start(0x7F, 0x5F, args[0], 2);
    return 0;
}

int Sys_FadeInBlack(int *args)
{
    s_game->m_mainFade->Start(3, args[0]);
    s_game->m_subFade->Start(3, args[0]);
    return 0;
}

int Sys_FadeInWhite(int *args)
{
    s_game->m_mainFade->Start(1, args[0]);
    s_game->m_subFade->Start(1, args[0]);
    return 0;
}

int Sys_WipeIn(int *args)
{
    s_game->m_subFade->Start(3, args[0]);
    s_game->m_mainWipe->Start(0x7F, 0x5F, args[0], 1);
    s_game->m_mainFade->Start(3, 0);
    return 0;
}

int Sys_IsFading(int *args)
{
    CGame *game = s_game;
    if (IsFading(game->m_mainWipe) || IsFading(game->m_subWipe) || game->m_mainFade->IsActive() || s_game->m_subFade->IsActive()) {
        return 1;
    }
    return 0;
}

int sub_02030AD0(int *args)
{
    return 0;
}

int Sys_StartCameraShake(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_cameraTarget = -1;
    }
    s_game->m_cameraController->StartShake(args[0] << 12);
    return 0;
}

int Sys_StopCameraShake(int *args)
{
    s_game->m_cameraController->StopShake();
    return 0;
}

int sub_02030B40(int *args, int argc)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        int a = 0;
        int b = 0;
        int c = 0;
        int d = -1;
        if (argc > 0) {
            a = args[0];
            if (argc > 1) {
                b = args[1];
                if (argc > 2) {
                    c = args[2];
                    if (argc > 3) {
                        d = args[3];
                    }
                }
            }
        }
        scene->m_flags |= 2;
        scene->unk_0068 = a;
        scene->unk_006C = b;
        scene->unk_0070 = c;
        scene->unk_0074 = d;
    }
    return 0;
}

int Sys_SetSaveName(int *args)
{
    SetSaveName((const char *)args[0]);
    return 0;
}
int Sys_HasSaveName(int *args)
{
    return MAIN_BSS_020B26A0.HasString() ? TRUE : FALSE;
}

int Sys_EnableEventRect(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    if (argc >= 1) {
        int map = (args[0] >> 20) & 0xFFF;
        int idx = args[0] & 0xFFFFF;
        SaveData_EnableEventRect(save, idx, map);
        if (map == save->m_mapId) {
            FieldEventRectManage *manage = MAIN_BSS_0210CA58;
            if (manage != NULL) {
                CFieldEventRect *rect = manage->Get(idx);
                if (rect != NULL) {
                    rect->unk_18 = 1;
                }
            }
        }
    }
    return 0;
}

int Sys_DisableEventRect(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    if (argc >= 1) {
        int map = (args[0] >> 20) & 0xFFF;
        int idx = args[0] & 0xFFFFF;
        SaveData_DisableEventRect(save, idx, map);
        if (map == save->m_mapId) {
            FieldEventRectManage *manage = MAIN_BSS_0210CA58;
            if (manage != NULL) {
                CFieldEventRect *rect = manage->Get(idx);
                if (rect != NULL) {
                    rect->unk_18 = 0;
                }
            }
        }
    }
    return 0;
}

int sub_02030D24(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    if (argc >= 2) {
        int map = (args[1] >> 20) & 0xFFF;
        int idx = args[1] & 0xFFFFF;
        SaveData_EnableEventRect(save, idx, map);
        if (map == save->m_mapId) {
            FieldEventRectManage *manage = MAIN_BSS_0210CA58;
            if (manage != NULL) {
                CFieldEventRect *rect = manage->Get(idx);
                if (rect != NULL) {
                    rect->unk_18 = 1;
                }
            }
        }
    }
    return 0;
}

int sub_02030DA8(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    if (argc >= 2) {
        int map = (args[1] >> 20) & 0xFFF;
        int idx = args[1] & 0xFFFFF;
        SaveData_DisableEventRect(save, idx, map);
        if (map == save->m_mapId) {
            FieldEventRectManage *manage = MAIN_BSS_0210CA58;
            if (manage != NULL) {
                CFieldEventRect *rect = manage->Get(idx);
                if (rect != NULL) {
                    rect->unk_18 = 0;
                }
            }
        }
    }
    return 0;
}

int sub_02030E2C(int *args)
{
    ov0_02161FD4(args[0]);
    return 0;
}

int Sys_StartScreenEffect(int *args)
{
    int type = args[0];
    int fadeIn = args[1];
    int hold = args[2];
    int fadeOut = args[3];
    FieldScreenEffectManage *effect = MAIN_BSS_0210CA78;
    if (effect != NULL) {
        effect->FindByType(type);
        effect->StartEffect(type, fadeIn, hold, fadeOut);
    }
    return 0;
}

int Sys_StopScreenEffect(int *args)
{
    int type = args[0];
    int fadeOut = args[1];
    if (MAIN_BSS_0210CA78 != NULL) {
        MAIN_BSS_0210CA78->StopEffect(type, fadeOut);
    }
    return 0;
}

int Sys_IsScreenEffectActive(int *args)
{
    int type = args[0];
    if (MAIN_BSS_0210CA78 == NULL) {
        return 0;
    }
    return MAIN_BSS_0210CA78->IsEffectActive(type);
}

int sub_02030EE0(int *args)
{
    int type = args[0];
    int arg = args[1];
    if (MAIN_BSS_0210CA78 == NULL) {
        return 0;
    }
    return MAIN_BSS_0210CA78->sub_02035F50(type, arg);
}

int sub_02030F08(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->ov0_02124588((u8)args[0], args[1]);
    }
    return 0;
}

int sub_02030F38(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->ov0_021245C4((u8)args[0]);
    }
    return 0;
}

int sub_02030F68(int *args)
{
    if (MAIN_BSS_0210CA7C == NULL) {
        return 0;
    }
    return MAIN_BSS_0210CA7C->ov0_0213D564();
}
int Sys_PlayMissionReceive(int *args)
{
    MissionQuestData_ReceiveMission(s_game->m_missionQuestData, args[0]);
    Audio()->StopBgmReset(0);
    Audio()->StopLoopSe(0);
    Audio()->LoadBgmGroup(0x28);
    Audio()->PlayBgm(0x12, 0);
    Textbox()->SetTextSpeed(0);
    Textbox()->SetAutoClose(180);
    Textbox()->ShowMessage(0, 2, 1, 1, 0);
    return 0;
}

int sub_02031078(int *args)
{
    BOOL ok = FALSE;
    if (MAIN_BSS_0210CA78 != NULL) {
        ok = MAIN_BSS_0210CA78->IsEffectActive(9);
        if (GlobalValues_Get((GlobalValues *)s_game->unk_14B4, 0x18) == 0) {
            ok = FALSE;
        }
        if (MAIN_BSS_0210CA6C != NULL) {
            u32 kind = FieldData_GetMap(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.m_mapId)->unk_00 - 0x26;
            if (kind <= 1) {
                ok = FALSE;
            }
        }
    }
    if (ok) {
        Audio()->LoadBgmGroup(0xB1);
        Audio()->PlayBgm(0x1A, 0);
    } else {
        Audio()->PlayMapBgm(MAIN_BSS_020B26A0.m_mapId, 60, TRUE);
        Audio()->SetLoopSeVolume(0x100);
    }
    return 0;
}

int Sys_ShowMissionStart(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_banner->Show(args[0]);
    }
    G2_SetBlendBrightness(GX_BLEND_PLANEMASK_BG0, -8);
    Audio()->LoadBgmGroup(0x29);
    Audio()->PlayBgm(6, 0);
    MissionQuestData_StartMission(s_game->m_missionQuestData);
    return 0;
}

int Sys_IsMissionStartBusy(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        return MAIN_BSS_0210CA40->m_banner->GetState() != 2 ? TRUE : FALSE;
    }
    return FALSE;
}

int Sys_EndMissionStart(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_banner->Release();
    }
    G2_SetBlendBrightness(GX_BLEND_PLANEMASK_BG0, 0);
    Audio()->PlayMapBgm(MAIN_BSS_020B26A0.m_mapId, 60, FALSE);
    Audio()->SetLoopSeVolume(0x100);
    return 0;
}

int Sys_ShowMissionClear(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_banner->Show(100);
    }
    Audio()->LoadBgmGroup(0x2A);
    Audio()->PlayBgm(7, 0);
    MissionQuestData_ClearMission(s_game->m_missionQuestData);
    return 0;
}

int Sys_IsMissionClearBusy(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        return MAIN_BSS_0210CA40->m_banner->GetState() != 9 ? TRUE : FALSE;
    }
    return FALSE;
}

int Sys_EndMissionClear(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_banner->Release();
    }
    CFieldActor *actor = FindScriptActor(0);
    if (actor != NULL) {
        actor->sub_show();
    }
    return 0;
}

int Sys_GetMissionId(int *args)
{
    return s_game->m_missionQuestData->m_missionId;
}

int Sys_StartMission(int *args)
{
    MissionQuestData_StartMission(s_game->m_missionQuestData);
    return 0;
}

int Sys_ReceiveMission(int *args)
{
    MissionQuestData_ReceiveMission(s_game->m_missionQuestData, args[0]);
    return 0;
}

int Sys_ClearMission(int *args)
{
    MissionQuestData_ClearMission(s_game->m_missionQuestData);
    return 0;
}

int Sys_EnterQuest(int *args)
{
    MissionQuestData_EnterQuest(s_game->m_missionQuestData, args[0]);
    GlobalValues_ClearQuestValues((GlobalValues *)s_game->unk_14B4);
    Audio()->StopBgmReset(0);
    Audio()->StopLoopSe(0);
    Audio()->LoadBgmGroup(0x28);
    Audio()->PlayBgm(0x12, 0);
    Textbox()->SetTextSpeed(0);
    Textbox()->SetAutoClose(180);
    Textbox()->ShowMessage(0, 0x1C, 1, 1, 0);
    return 0;
}

int Sys_ShowQuestClear(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_banner->Show(101);
    }
    Audio()->LoadBgmGroup(0x2A);
    Audio()->PlayBgm(7, 0);
    return 0;
}

int Sys_IsQuestClearBusy(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        return MAIN_BSS_0210CA40->m_banner->GetState() != 9 ? TRUE : FALSE;
    }
    return FALSE;
}

int Sys_EndQuestClear(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_banner->Release();
    }
    CFieldActor *actor = FindScriptActor(0);
    if (actor != NULL) {
        actor->sub_show();
    }
    return 0;
}

int Sys_ExitQuestCleared(int *args)
{
    MissionQuestData_ExitQuestCleared(s_game->m_missionQuestData);
    return 0;
}
int Sys_IsQuestCleared(int *args)
{
    return MissionQuestData_IsQuestCleared(s_game->m_missionQuestData, args[0]);
}

int Sys_GetQuestId(int *args)
{
    return s_game->m_missionQuestData->m_questId;
}

int Sys_ExitQuest(int *args)
{
    MissionQuestData_ExitQuest(s_game->m_missionQuestData);
    return 0;
}

int Sys_StartQuest(int *args)
{
    MissionQuestData_StartQuest(s_game->m_missionQuestData, args[0]);
    return 0;
}

int Sys_IsQuestActive(int *args)
{
    return MissionQuestData_IsQuestActive(s_game->m_missionQuestData, args[0]);
}

int Sys_SetQuestEntered(int *args)
{
    MissionQuestData_SetQuestEntered(s_game->m_missionQuestData, args[0]);
    return 0;
}

int Sys_IsQuestEntered(int *args)
{
    return MissionQuestData_IsQuestEntered(s_game->m_missionQuestData, args[0]);
}

int Sys_ShowBrowserFanfare(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_banner->Show(0x66);
    }
    Audio()->LoadBgmGroup(0x32);
    Audio()->PlayBgm(0x34, 0);
    return 0;
}

int Sys_IsBrowserFanfareBusy(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        return MAIN_BSS_0210CA40->m_banner->GetState() != 9 ? TRUE : FALSE;
    }
    return FALSE;
}

int Sys_EndBrowserFanfare(int *args)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_banner->Release();
    }
    CFieldActor *actor = FindScriptActor(0);
    if (actor != NULL) {
        actor->sub_show();
    }
    return 0;
}

int sub_020318B4(int *args)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    const char *name = s_c000First_0208ac1c[args[0]].name;
    if (name != NULL) {
        strcpy(save->m_saveName, name);
    } else {
        save->m_saveName[0] = '\0';
    }
    s_game->m_scriptManager->unk_18 = 1;
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        int chapter = args[0];
        scene->m_flags |= 2;
        scene->unk_0068 = s_c000First_0208ac1c[chapter].x;
        scene->unk_006C = s_c000First_0208ac1c[chapter].y;
        scene->unk_0070 = s_c000First_0208ac1c[chapter].z;
        scene->unk_0074 = 0;
    }
    GlobalValues_ClearChapterValues((GlobalValues *)s_game->unk_14B4);
    GlobalValues_ApplyProgress((GlobalValues *)s_game->unk_14B4, args[0]);
    MissionQuestData_SetChapter(s_game->m_missionQuestData, args[0]);
    return 0;
}

int sub_020319C4(int *args)
{
    return 0;
}

int Sys_GetChapter(int *args)
{
    return s_game->m_missionQuestData->m_chapter;
}

int sub_020319E8(int *args)
{
    Audio()->StopBgmReset(30);
    Audio()->StopLoopSe(30);
    Audio()->sub_02034F4C(1);
    RestoreHP();
    GlobalValues_ClearChapterValues((GlobalValues *)s_game->unk_14B4);
    GlobalValues_ApplyProgress((GlobalValues *)s_game->unk_14B4, args[0]);
    MissionQuestData_SetChapter(s_game->m_missionQuestData, args[0]);
    SaveData *save = &MAIN_BSS_020B26A0;
    const char *name = s_c000First_0208ac1c[args[0]].name;
    if (name != NULL) {
        strcpy(save->m_saveName, name);
    } else {
        save->m_saveName[0] = '\0';
    }
    s_game->m_scriptManager->unk_18 = 1;
    s_game->m_missionQuestData->unk_10 = s_game->m_missionQuestData->m_chapter;
    SetSceneFlag(0x20);
    return 0;
}

int Sys_LoadChapterMessages(int *args)
{
    MissionQuestData_LoadChapterMessages(s_game->m_missionQuestData, args[0]);
    return 0;
}

int Sys_GetChapterValue(int *args)
{
    return GlobalValues_GetChapterValue((GlobalValues *)s_game->unk_14B4, args[0]);
}

int Sys_SetChapterValue(int *args)
{
    GlobalValues_SetChapterValue((GlobalValues *)s_game->unk_14B4, args[0], args[1]);
    return 0;
}

int Sys_GetGlobalValue(int *args)
{
    return GlobalValues_Get((GlobalValues *)s_game->unk_14B4, args[0]);
}

int Sys_SetGlobalValue(int *args)
{
    GlobalValues_Set((GlobalValues *)s_game->unk_14B4, args[0], args[1]);
    return 0;
}

int Sys_GetQuestValue(int *args)
{
    return GlobalValues_GetQuestValue((GlobalValues *)s_game->unk_14B4, args[0]);
}

int Sys_SetQuestValue(int *args)
{
    GlobalValues_SetQuestValue((GlobalValues *)s_game->unk_14B4, args[0], args[1]);
    return 0;
}

int sub_02031C50(int *args)
{
    CFieldPartnerManage *manage = MAIN_BSS_0210CA4C;
    if (manage != NULL) {
        int count = manage->m_count;
        for (int i = 0; i < count; i++) {
            CFieldActor *actor = manage->Get(i);
            if (actor != NULL) {
                actor->m_flags |= 1;
            }
        }
    }
    return 0;
}

int sub_02031CB4(int *args)
{
    CFieldPartnerManage *manage = MAIN_BSS_0210CA4C;
    if (manage != NULL) {
        int count = manage->m_count;
        Point2D pos = MAIN_BSS_0210CA48->GetPos();
        for (int i = 0; i < count; i++) {
            CFieldActor *actor = manage->Get(i);
            if (actor != NULL && actor->IsHidden()) {
                actor->SetPos(pos);
                actor->m_flags &= ~1;
            }
        }
    }
    return 0;
}

int sub_02031E00(int *args)
{
    int id = args[0];
    if (MAIN_BSS_0210CA4C != NULL) {
        MAIN_BSS_0210CA4C->ov0_0213A96C(TRUE, id, TRUE);
    }
    return 0;
}

int sub_02031E30(int *args)
{
    if (MAIN_BSS_0210CA4C == NULL) {
        return 0;
    }
    return MAIN_BSS_0210CA4C->ov0_0213B048();
}

int sub_02031E54(int *args)
{
    if (MAIN_BSS_0210CA4C == NULL) {
        return 0;
    }
    return MAIN_BSS_0210CA4C->ov0_0213B0F0();
}

int sub_02031E78(int *args)
{
    int id = args[0];
    if (MAIN_BSS_0210CA4C != NULL) {
        MAIN_BSS_0210CA4C->ov0_0213A96C(FALSE, id, TRUE);
    }
    return 0;
}

int sub_02031EA8(int *args)
{
    int id = args[0];
    if (MAIN_BSS_0210CA4C != NULL) {
        MAIN_BSS_0210CA4C->ov0_0213A96C(FALSE, id, FALSE);
    }
    return 0;
}

int sub_02031ED8(int *args)
{
    int id = args[0];
    if (MAIN_BSS_0210CA4C != NULL) {
        MAIN_BSS_0210CA4C->ov0_0213AD8C(id);
    }
    return 0;
}

int sub_02031F00(int *args)
{
    int id = args[0];
    if (MAIN_BSS_0210CA4C != NULL) {
        MAIN_BSS_0210CA4C->ov0_0213B150(id);
    }
    return 0;
}
int sub_02031F28(int *args)
{
    u32 id = args[0];
    if (MAIN_BSS_0210CA4C != NULL) {
        MAIN_BSS_0210CA4C->ov0_0213B184(id);
    }
    return 0;
}

int sub_02031F50(int *args)
{
    return MAIN_BSS_0210CA4C->unk_88;
}

int sub_02031F64(int *args)
{
    u32 kind = args[0];
    CFieldPartnerManage *manage = MAIN_BSS_0210CA4C;
    int n = 0;
    if (manage == NULL) {
        return 0;
    }
    int count = manage->m_count;
    for (int i = 0; i < count; i++) {
        CFieldPartner *partner = (CFieldPartner *)manage->Get(i);
        if (partner != NULL && kind == partner->unk_200 && partner->unk_1FC == 0) {
            n++;
        }
    }
    return n;
}

int sub_02031FD4(int *args)
{
    u32 id = args[0];
    int type;
    int target;
    u32 kind = ((int)id >> 24) & 0xFF;
    if (kind == 2) {
        type = 5;
    } else if (kind == 1) {
        type = 6;
    } else {
        LogError("error actorid= %x is not enemy or npc", id);
        return 0;
    }
    target = (id & 0xFFFFFF) | (type << 24);
    if (MAIN_BSS_0210CA4C != NULL) {
        if (FindTargetKey(MAIN_BSS_0210CA4C, target) != NULL) {
            return 1;
        }
    }
    return 0;
}

int sub_02032080(int *args)
{
    u32 kind = args[0];
    if (MAIN_BSS_0210CA4C == NULL) {
        return 0;
    }
    return MAIN_BSS_0210CA4C->ov0_0213A4C4(kind);
}

int Sys_IsPartnerPresent(int *args)
{
    return FindScriptActor(1) != NULL ? TRUE : FALSE;
}

int sub_020320C4(int *args)
{
    u32 kind = args[0];
    if (MAIN_BSS_0210CA4C == NULL) {
        return 0;
    }
    return MAIN_BSS_0210CA4C->ov0_0213A520(kind);
}

int Sys_SetPartnerNpcName(int *args)
{
    u32 id = args[0];
    const char *name = (const char *)args[1];
    CFieldActor *actor = FindScriptActor(id);
    if (actor != NULL && (((int)actor->m_id >> 24) & 0xFF) == 5) {
        ((CFieldPartnerNpc *)actor)->SetName(name);
    }
    PartnerSlot *partner = SaveData_FindPartner(&MAIN_BSS_020B26A0, id);
    if (partner != NULL) {
        SavePartner_SetName(partner, name);
    }
    return 0;
}

int Sys_SetPartyEntrySelected(int *args)
{
    PartyEntry *record = SaveData_FindEntry(&MAIN_BSS_020B26A0, args[0]);
    if (record != NULL) {
        record->m_flags |= 4;
    }
    return 0;
}

int Sys_ClearPartyEntrySelected(int *args)
{
    PartyEntry *record = SaveData_FindEntry(&MAIN_BSS_020B26A0, args[0]);
    if (record != NULL) {
        record->m_flags &= ~4;
    }
    return 0;
}

int Sys_SetPartyEntryPartner(int *args)
{
    PartyEntry *record = SaveData_FindEntry(&MAIN_BSS_020B26A0, args[0]);
    if (record != NULL) {
        record->m_flags |= 2;
    }
    return 0;
}

int Sys_ClearPartyEntryPartner(int *args)
{
    PartyEntry *record = SaveData_FindEntry(&MAIN_BSS_020B26A0, args[0]);
    if (record != NULL) {
        record->m_flags &= ~2;
    }
    return 0;
}

int sub_020321F8(int *args)
{
    CFieldPartnerManage *manage = MAIN_BSS_0210CA4C;
    SaveData *save = &MAIN_BSS_020B26A0;
    if (manage != NULL && save != NULL) {
        int count = SaveData_CountParty(save, -1);
        int idx = 0;
        for (int i = 0; i < count; i++) {
            PartyEntry *record = SaveData_GetEntry(save, idx);
            if (record != NULL) {
                if (record->m_flags & 2) {
                    idx++;
                } else {
                    u32 id = (record->m_index & 0xFFF) | (((record->m_mapId & 0xFFF) << 12) | 0x6000000);
                    manage->ov0_0213A050(id);
                    SaveData_RemoveFromParty(save, id);
                }
            }
        }
    }
    return 0;
}

int sub_020322B0(int *args)
{
    u32 kind = 0;
    CFieldPartnerManage *manage = MAIN_BSS_0210CA4C;
    if (manage != NULL) {
        int n = manage->unk_88;
        int base = manage->unk_84;
        for (int i = 0; i < n; i++) {
            CFieldPartner *partner = FindByOrderIn(manage, base + i);
            if (partner != NULL && (partner->m_flags & 0x20)) {
                kind = partner->unk_200;
                break;
            }
        }
    }
    if (kind != 0) {
        return PokeIdTable_Get(s_game->unk_1434, kind)->unk_00;
    }
    return 0;
}

int sub_0203238C(int *args)
{
    BOOL arg = args[0];
    if (MAIN_BSS_0210CA4C != NULL) {
        MAIN_BSS_0210CA4C->ov0_02139F10(arg);
    }
    return 0;
}

int sub_020323B4(int *args)
{
    return MAIN_BSS_0210CA4C->unk_84;
}

int sub_020323C8(int *args)
{
    int id = args[0];
    CFieldPartnerManage *manage = MAIN_BSS_0210CA4C;
    SaveData *save = &MAIN_BSS_020B26A0;
    if (manage != NULL && save != NULL) {
        CFieldPartner *partner = (CFieldPartner *)FindTargetKey(manage, id);
        if (partner != NULL && partner->IsActive() && !partner->IsHidden()) {
            if ((partner->m_flags & 0x20) || partner->IsNpc() || save->m_areaType != 4) {
                return 1;
            }
        }
    }
    return 0;
}

int sub_020324A8(int *args)
{
    if (MAIN_BSS_0210CA6C == NULL) {
        return 0;
    }
    return FieldData_GetMap(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.m_mapId)->unk_00;
}

int sub_020324DC(int *args)
{
    CFieldEffectManage *manage = MAIN_BSS_0210CA60;
    if (manage == NULL) {
        return 0;
    }
    u32 i = args[0];
    if ((int)i >= 0 && i < 41) {
        return manage->ov0_02142F6C(sEffectParams[i].arg1, sEffectParams[i].arg2);
    }
    return 0;
}

int sub_02032538(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            effect->ov0_021421F0(args[1], args[2], args[3]);
        }
    }
    return 0;
}

int Sys_HasEffect(int *args)
{
    u16 id = args[0];
    if (MAIN_BSS_0210CA60 != NULL && MAIN_BSS_0210CA60->ov0_02143088(id) != NULL) {
        return TRUE;
    }
    return FALSE;
}

int sub_020325C0(int *args)
{
    u16 id = args[0];
    if (MAIN_BSS_0210CA60 == NULL) {
        return 0;
    }
    return MAIN_BSS_0210CA60->ov0_021430D8(id);
}

int sub_020325F0(int *args)
{
    int type = args[0];
    CFieldEffectManage *manage = MAIN_BSS_0210CA60;
    switch (type) {
    case 1:
        return manage->ov0_02142F6C(0x1F, 0);
    }
    return 0;
}

int sub_02032624(int *args)
{
    u16 id = args[0];
    CFieldEffectManage *manage = MAIN_BSS_0210CA60;
    Point2D pos;
    pos.x = args[1] << 12;
    pos.y = args[2] << 12;
    int a = args[3];
    int b = args[4];
    int c = args[5];
    if (manage != NULL) {
        CFieldEffect *effect = manage->ov0_02143088(id);
        if (effect != NULL) {
            effect->ov0_0214234C(pos, 0, 0, 0, 0);
            effect->ov0_021421F0(a, b, c);
        }
    }
    return 0;
}

int Sys_HasEffect2(int *args)
{
    u16 id = args[0];
    if (MAIN_BSS_0210CA60 != NULL && MAIN_BSS_0210CA60->ov0_02143088(id) != NULL) {
        return TRUE;
    }
    return FALSE;
}

int sub_02032708(int *args)
{
    u16 id = args[0];
    int value = args[1];
    if (MAIN_BSS_0210CA60 != NULL) {
        if (value == -1) {
            return MAIN_BSS_0210CA60->ov0_021430D8(id);
        }
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(id);
        if (effect != NULL) {
            return effect->ov0_02142240(value);
        }
    }
    return 0;
}

int sub_02032768(int *args)
{
    if (MAIN_BSS_0210CA5C != NULL) {
        MAIN_BSS_0210CA5C->ov0_0213690C(args[0], args[1]);
    }
    return 0;
}

int sub_02032794(int *args)
{
    if (MAIN_BSS_0210CA5C != NULL) {
        MAIN_BSS_0210CA5C->ov0_02136968();
    }
    return 0;
}
int Sys_SetPartnerFlags(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    save->m_partnerFlags |= args[0];
    return 0;
}

int Sys_TestPartnerFlags(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save == NULL) {
        return 0;
    }
    return save->m_partnerFlags & args[0];
}

int Sys_GetPartnerMood(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save != NULL) {
        return save->m_partnerMoods[args[0]];
    }
    return 0;
}

int Sys_SetBattlePartnerMood(int *args)
{
    BattleStartParam_SetPartnerMood(s_game->unk_143C, args[0]);
    return 0;
}

int sub_02032850(int *args)
{
    return 0;
}

int sub_02032858(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL && (((int)actor->m_id >> 24) & 0xFF) == 3) {
        ((CFieldTargetObject *)actor)->unk_EC = args[1];
        return 1;
    }
    return 0;
}

int sub_0203289C(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL && (((int)actor->m_id >> 24) & 0xFF) == 3) {
        return ((CFieldTargetObject *)actor)->unk_EC;
    }
    return 0;
}

int Sys_SetTargetOffset(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL && (((int)actor->m_id >> 24) & 0xFF) == 3) {
        int x = args[1];
        int y = args[2];
        ((CFieldTargetObject *)actor)->m_offsetX = x << 12;
        ((CFieldTargetObject *)actor)->m_offsetY = y << 12;
    }
    return 0;
}

int Sys_GetTargetX(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL && (((int)actor->m_id >> 24) & 0xFF) == 3) {
        fx32 x = actor->GetX();
        return (x + ((CFieldTargetObject *)actor)->m_offsetX) >> 12;
    }
    return 0;
}

int Sys_GetTargetY(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL && (((int)actor->m_id >> 24) & 0xFF) == 3) {
        fx32 y = actor->GetY();
        return (y + ((CFieldTargetObject *)actor)->m_offsetY) >> 12;
    }
    return 0;
}

int sub_020329E0(int *args)
{
    MAIN_BSS_0210CA74 |= 1;
    return 0;
}

int sub_020329FC(int *args)
{
    MAIN_BSS_0210CA74 &= ~1;
    return 0;
}

int sub_02032A18(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->sub_02032A44(0x10);
    }
    return 0;
}
}

void CFieldActor::sub_02032A44(int arg0)
{
}

extern "C" {
int sub_02032A48(int *args)
{
    CFieldActor *actor = FindScriptActor(args[0]);
    if (actor != NULL) {
        actor->sub_02032A44(1);
    }
    return 0;
}

int sub_02032A74(int *args)
{
    CFieldEffectManage *manage = MAIN_BSS_0210CA60;
    if (manage != NULL) {
        switch (args[0]) {
        case 200:
            if (manage->m_factories[12] != NULL) {
                ((CFieldEffectPoisonGasFactory *)manage->m_factories[12])->Load();
            }
            break;
        case 201:
            if (manage->m_factories[13] != NULL) {
                ((CFieldEffectExplosionFactory *)manage->m_factories[13])->Load();
            }
            break;
        case 202:
            if (manage->m_factories[18] != NULL) {
                ((CFieldEffectSlimeFactory *)manage->m_factories[18])->Load(0x84);
            }
            break;
        case 203:
            if (manage->m_factories[18] != NULL) {
                ((CFieldEffectSlimeFactory *)manage->m_factories[18])->Load(0x85);
            }
            break;
        case 204:
            if (manage->m_factories[18] != NULL) {
                ((CFieldEffectSlimeFactory *)manage->m_factories[18])->Load(0x86);
            }
            break;
        case 0x10:
            if (manage->m_factories[25] != NULL) {
                ov0_0216EE1C(manage->m_factories[25]);
            }
            break;
        case 0x11:
            if (manage->m_factories[26] != NULL) {
                ov0_0216FEA4(manage->m_factories[26]);
            }
            break;
        case 0x16:
            if (manage->m_factories[30] != NULL) {
                ov0_0217248C(manage->m_factories[30]);
            }
            break;
        }
    }
    return 0;
}

int sub_02032BAC(int *args)
{
    CFieldEffectManage *manage = MAIN_BSS_0210CA60;
    if (manage != NULL) {
        switch (args[0]) {
        case 0:
            return manage->ov0_02142F6C(9, 0);
        case 1:
            return manage->ov0_02142F6C(0xB, 0);
        case 2:
            return manage->ov0_02142F6C(0xA, 0);
        case 8:
            return manage->ov0_02142F6C(0x26, 0);
        case 9:
            return manage->ov0_02142F6C(0x13, 0);
        case 10:
            return manage->ov0_02142F6C(0x14, 1);
        case 11:
            return manage->ov0_02142F6C(0x15, 0);
        case 12:
            return manage->ov0_02142F6C(0x16, 2);
        case 13:
            return manage->ov0_02142F6C(0x17, 1);
        case 14:
            return manage->ov0_02142F6C(0xE, -12);
        case 15:
            return manage->ov0_02142F6C(0x18, 0);
        case 16:
            return manage->ov0_02142F6C(0x19, 0);
        case 17:
            return manage->ov0_02142F6C(0x1A, 0);
        case 18:
            return manage->ov0_02142F6C(0x1B, 0);
        case 20:
            return manage->ov0_02142F6C(0x1C, 0);
        case 21:
            return manage->ov0_02142F6C(0x1C, 1);
        case 22:
            return manage->ov0_02142F6C(0x1E, 0);
        case 19:
            return manage->ov0_02142F6C(9, 1);
        case 100:
            return manage->ov0_02142F6C(0x22, 0);
        case 102:
            return manage->ov0_02142F6C(0x20, 0x79);
        case 103:
            return manage->ov0_02142F6C(0x20, 0x78);
        case 3:
            return manage->ov0_02142F6C(0xE, 10);
        case 4:
            return manage->ov0_02142F6C(0xF, 12);
        case 5:
            return manage->ov0_02142F6C(0x10, 0);
        case 6:
            return manage->ov0_02142F6C(0x11, 13);
        case 7:
            return manage->ov0_02142F6C(0xE, 14);
        case 200:
            return manage->ov0_02142F6C(0xC, 0);
        case 201:
            return manage->ov0_02142F6C(0xD, 0);
        case 202:
            return manage->ov0_02142F6C(0x12, 0x84);
        case 203:
            return manage->ov0_02142F6C(0x12, 0x85);
        case 204:
            return manage->ov0_02142F6C(0x12, 0x486);
        case 104:
            return manage->ov0_02142F6C(0x21, 0x6E);
        case 105:
            return manage->ov0_02142F6C(0x1D, 0);
        }
    }
    return 0;
}

int sub_02032F5C(int *args)
{
    u16 id = args[0];
    if (MAIN_BSS_0210CA60 == NULL) {
        return 0;
    }
    return MAIN_BSS_0210CA60->ov0_021430D8(id);
}

int sub_02032F8C(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        int a = args[1];
        int b = args[2];
        int c = args[3];
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            effect->ov0_021421F0(a, b, c);
            effect->ov0_02142264(0);
            if (effect->GetEffectId() == 0x12) {
                (*(UnkEffectPart **)((u8 *)effect + 0x1EC))->vfunc_1C();
                static_cast<CFieldEffectSlime *>(effect)->ov0_021633CC();
            }
        }
    }
    return 0;
}
int sub_02033030(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        int value = args[1];
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            effect->ov0_02142240(value);
        }
    }
    return 0;
}

int sub_0203307C(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL && MAIN_BSS_0210CA60->ov0_02143088(args[0]) != NULL) {
        return TRUE;
    }
    return FALSE;
}

int sub_020330BC(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            effect->SetParam(1, args[1]);
            effect->SetParam(2, args[2]);
            return 1;
        }
    }
    return 0;
}
int sub_02033134(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            effect->SetParam(3, args[1]);
            effect->SetParam(4, args[2]);
            return 1;
        }
    }
    return 0;
}

int sub_020331A4(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            return effect->SetParam(args[1], args[2]);
        }
    }
    return 0;
}

int sub_020331F4(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            return effect->sub_02033244(args[1], args[2], args[3]);
        }
    }
    return 0;
}

int sub_0203324C(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            return effect->IsReady() == 0 ? TRUE : FALSE;
        }
    }
    return FALSE;
}
int sub_020332AC(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            Point2D pos;
            pos.x = args[1] << 12;
            pos.y = args[2] << 12;
            effect->sub_0203331C(pos, args[3]);
        }
    }
    return 0;
}
int sub_02033320(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            Point2D pos;
            pos.x = args[1];
            pos.y = args[2];
            effect->sub_02033388(pos, args[3]);
        }
    }
    return 0;
}
int sub_0203338C(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            effect->FadeTo(args[1], args[2]);
        }
    }
    return 0;
}
int sub_020333DC(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            effect->SetColor(args[1] | (args[2] << 5) | (args[3] << 10));
        }
    }
    return 0;
}
int sub_02033444(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            effect->SetParam(1, args[1]);
            effect->SetParam(2, args[2]);
            return 1;
        }
    }
    return 0;
}

int sub_020334B4(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            effect->SetParam(9, args[1]);
            effect->SetParam(10, args[2]);
        }
    }
    return 0;
}

int sub_0203351C(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            return effect->SetParam(args[1], args[2]);
        }
    }
    return 0;
}

int sub_0203356C(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        int value = args[1];
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            effect->ov0_02142240(value);
        }
    }
    return 0;
}

int sub_020335B8(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            return effect->IsReady() == 0 ? TRUE : FALSE;
        }
    }
    return FALSE;
}

int sub_02033610(int *args)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffect *effect = MAIN_BSS_0210CA60->ov0_02143088(args[0]);
        if (effect != NULL) {
            effect->sub_0203365C(args[1]);
        }
    }
    return 0;
}
int sub_02033660(int *args)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    if (MAIN_BSS_0210CA40 == NULL || save == NULL) {
        return 0;
    }
    CPlayerHPGauge *gauge = MAIN_BSS_0210CA40->m_hpGauge;
    if (gauge == NULL) {
        return 0;
    }
    int max = save->m_maxEnergy;
    int hp = save->m_energy + args[0];
    if (hp > max) {
        hp = max;
    }
    u16 speed = args[1];
    gauge->SetCurrentHP(hp);
    save->m_energy = hp;
    gauge->StartHeal(speed);
    return 0;
}

int sub_020336E4(int *args)
{
    if (MAIN_BSS_0210CA40 == NULL) {
        return 0;
    }
    if (MAIN_BSS_0210CA40->m_hpGauge == NULL) {
        return 0;
    }
    return MAIN_BSS_0210CA40->m_hpGauge->IsHealing();
}

static inline u32 GetCaptureState(SaveData *save, int group, int i)
{
    if (group >= 0 && group < 3 && i >= 0 && i < 64) {
        return (save->m_encyclopediaStates[group][i / 16] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

int sub_02033718(int *args)
{
    int group = args[0];
    int i = args[1];
    SaveData *save = &MAIN_BSS_020B26A0;
    if (GetCaptureState(save, group, i) == 0 && group >= 0 && group < 3 && i >= 0 && i < 64) {
        int shift = (i & 0xF) * 2;
        save->m_encyclopediaStates[group][i / 16] &= ~(3 << shift);
        save->m_encyclopediaStates[group][i / 16] |= 1 << shift;
    }
    return 0;
}

int sub_020337EC(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    save->m_timer = 0;
    save->m_timerMode = 0;
    save->m_timerLimit = 0;
    save->unk_7F60 &= ~2;
    return 0;
}

int sub_0203381C(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    save->m_timer = args[0];
    save->m_timerMode = 1;
    save->m_timerLimit = 0;
    return 0;
}

int sub_02033844(int *args)
{
    int limit = args[0];
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    save->m_timer = 0;
    save->m_timerMode = 2;
    save->m_timerLimit = limit;
    return 0;
}

int sub_0203386C(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    // fake: the second (merged) store keeps `save` a base register, like the original's add #0x8000
    save->m_timerMode = 0;
    save->m_timerMode = 0;
    return 0;
}

int sub_02033884(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    // fake: the second (merged) store keeps `save` a base register, like the original's add #0x8000
    save->m_timerMode = 1;
    save->m_timerMode = 1;
    return 0;
}

int sub_020338A0(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    // fake: the second (merged) store keeps `save` a base register, like the original's add #0x8000
    save->m_timerMode = 2;
    save->m_timerMode = 2;
    return 0;
}

int sub_020338BC(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    save->unk_7F60 |= 2;
    return 0;
}

int sub_020338DC(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    save->unk_7F60 &= ~2;
    return 0;
}

int sub_020338FC(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save != NULL) {
        return save->m_timer;
    }
    return 0;
}

int sub_02033918(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    int value = args[0];
    // fake: the second (merged) store keeps `save` a base register, like the original's add #0x8000
    save->m_timer = value;
    save->m_timer = value;
    return 0;
}

int sub_02033934(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    // fake: re-reading the mode through another type keeps `save` a base register (the original's add #0x8000);
    // the backend merges the loads
    if (save->m_timerMode == 0 || (*(u8 *)&save->m_timerMode != 1 && *(u8 *)&save->m_timerMode != 2)) {
        return 0;
    }
    return 1;
}

int sub_02033968(int *args)
{
    GlobalValues_Set((GlobalValues *)s_game->unk_14B4, 0x1B, 0);
    return 0;
}

int sub_02033994(int *args)
{
    if (args[0] > 7) {
        return 1;
    }
    return (GlobalValues_Get((GlobalValues *)s_game->unk_14B4, 0x1B) >> args[0]) & 1;
}

int sub_020339D8(int *args)
{
    if (args[0] > 7) {
        return 1;
    }
    u32 bits = GlobalValues_Get((GlobalValues *)s_game->unk_14B4, 0x1B);
    GlobalValues_Set((GlobalValues *)s_game->unk_14B4, 0x1B, bits | (1 << args[0]));
    return 0;
}

int sub_02033A38(int *args)
{
    if (args[0] < 3) {
        GlobalValues_Set((GlobalValues *)s_game->unk_14B4, args[0] + 0x1C, 0);
    } else {
        return 1;
    }
    return 0;
}

int sub_02033A7C(int *args)
{
    if (args[0] < 3) {
        if (args[1] > 7) {
            return 1;
        }
        return (GlobalValues_Get((GlobalValues *)s_game->unk_14B4, args[0] + 0x1C) >> args[1]) & 1;
    }
    return 1;
}

int sub_02033AD4(int *args)
{
    if (args[0] < 3) {
        if (args[1] > 7) {
            return 1;
        }
        u32 bits = GlobalValues_Get((GlobalValues *)s_game->unk_14B4, args[0] + 0x1C);
        bits |= 1 << args[1];
        GlobalValues_Set((GlobalValues *)s_game->unk_14B4, args[0] + 0x1C, bits);
    } else {
        return 1;
    }
    return 0;
}

int Sys_AddPokemonRide(int *args)
{
    SaveData_AddPokemonRides(&MAIN_BSS_020B26A0, 1);
    return 0;
}

int sub_02033B6C(int *args)
{
    if (MAIN_BSS_0210CA3C == NULL) {
        MAIN_BSS_0210CA3C = new SaveManager(1);
    }
    MAIN_BSS_0210CA3C->sub_02028408(0);
    return 0;
}

int sub_02033BBC(int *args)
{
    if (MAIN_BSS_0210CA3C != NULL) {
        u32 result = MAIN_BSS_0210CA3C->Update();
        if (result != 0) {
            SAFE_DELETE(MAIN_BSS_0210CA3C);
            return (result & 0x80) == 0 ? 1 : 2;
        }
        return 0;
    }
    return 2;
}

int Sys_GetSaveCount(int *args)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save != NULL) {
        return save->m_saveCount;
    }
    return 0;
}
}

// The script syscall table (registered by ScriptManager)
ScriptSyscall gScriptSyscalls[] = {
    (ScriptSyscall)Sys_LoadMapBgmGroup,
    (ScriptSyscall)sub_0202BDE4,
    (ScriptSyscall)sub_0202BE0C,
    (ScriptSyscall)Sys_LoadBgmGroup,
    (ScriptSyscall)sub_0202BE78,
    (ScriptSyscall)Sys_PlayBgm,
    (ScriptSyscall)Sys_StopBgm,
    (ScriptSyscall)Sys_SetBgmTempo,
    (ScriptSyscall)Sys_SetBgmVolume,
    (ScriptSyscall)Sys_PlayLoopSe,
    (ScriptSyscall)Sys_StopLoopSe,
    (ScriptSyscall)Sys_SetLoopSeVolume,
    (ScriptSyscall)Sys_PlaySe,
    (ScriptSyscall)Sys_StopSe,
    (ScriptSyscall)Sys_PlayJingle,
    (ScriptSyscall)Sys_StopJingle,
    (ScriptSyscall)Sys_PlayStream,
    (ScriptSyscall)Sys_PlayStream2,
    (ScriptSyscall)Sys_StopStream2,
    (ScriptSyscall)Sys_SetPokemonSeen,
    (ScriptSyscall)Sys_SetPokemonCaptured,
    (ScriptSyscall)Sys_GetPokemonState,
    (ScriptSyscall)Sys_CountCapturedPokemon,
    (ScriptSyscall)Sys_ClearPokemonState,
    (ScriptSyscall)Sys_ShowMessage,
    (ScriptSyscall)Sys_IsTextboxActive,
    (ScriptSyscall)Sys_CloseTextbox,
    (ScriptSyscall)Sys_SetTextboxParam,
    (ScriptSyscall)Sys_SetTextSpeed,
    (ScriptSyscall)Sys_ResetTextSpeed,
    (ScriptSyscall)Sys_SetTextAutoAdvance,
    (ScriptSyscall)Sys_ClearTextAutoAdvance,
    (ScriptSyscall)Sys_SetTextAutoClose,
    (ScriptSyscall)Sys_ClearTextAutoClose,
    (ScriptSyscall)Sys_OpenYesNo,
    (ScriptSyscall)Sys_CloseTextboxIfNoPrompt,
    (ScriptSyscall)Sys_GetYesNoResult,
    (ScriptSyscall)Sys_MoveCamera,
    (ScriptSyscall)Sys_SetCameraTarget,
    (ScriptSyscall)Sys_MoveCameraBetween,
    (ScriptSyscall)Sys_IsCameraMoving,
    (ScriptSyscall)Sys_CameraFollowPlayer,
    (ScriptSyscall)Sys_FixActorDir,
    (ScriptSyscall)Sys_ActorFaceMoveDir,
    (ScriptSyscall)sub_0202CD8C,
    (ScriptSyscall)Sys_ActorLookAt,
    (ScriptSyscall)Sys_StopActorLookAt,
    (ScriptSyscall)sub_0202CEDC,
    (ScriptSyscall)Sys_SetActorDir,
    (ScriptSyscall)sub_0202D0D0,
    (ScriptSyscall)Sys_GetActorX,
    (ScriptSyscall)Sys_GetActorY,
    (ScriptSyscall)Sys_GetActorHeight,
    (ScriptSyscall)Sys_GetActorDir8,
    (ScriptSyscall)Sys_DisableActor,
    (ScriptSyscall)Sys_EnableActor,
    (ScriptSyscall)sub_0202D448,
    (ScriptSyscall)sub_0202D4FC,
    (ScriptSyscall)Sys_ShowManpu,
    (ScriptSyscall)Sys_HideManpu,
    (ScriptSyscall)Sys_MoveActorTo,
    (ScriptSyscall)Sys_MoveActorToFast,
    (ScriptSyscall)Sys_StopActor,
    (ScriptSyscall)sub_0202D85C,
    (ScriptSyscall)sub_0202D8BC,
    (ScriptSyscall)Sys_SetActorHeight,
    (ScriptSyscall)Sys_SetActorMoveDir,
    (ScriptSyscall)sub_0202D9C0,
    (ScriptSyscall)Sys_IsActorOutOfRange,
    (ScriptSyscall)sub_0202DB00,
    (ScriptSyscall)sub_0202DB70,
    (ScriptSyscall)Sys_PlayActorAnim,
    (ScriptSyscall)sub_0202DC74,
    (ScriptSyscall)Sys_GetActorAnimState,
    (ScriptSyscall)Sys_SetActorAnimSpeed,
    (ScriptSyscall)sub_0202DD48,
    (ScriptSyscall)sub_0202DD88,
    (ScriptSyscall)sub_0202E060,
    (ScriptSyscall)sub_0202E068,
    (ScriptSyscall)sub_0202E070,
    (ScriptSyscall)sub_0202E330,
    (ScriptSyscall)sub_0202E548,
    (ScriptSyscall)sub_0202E550,
    (ScriptSyscall)sub_0202E558,
    (ScriptSyscall)sub_0202E61C,
    (ScriptSyscall)Sys_ResetBattleParams,
    (ScriptSyscall)Sys_SetSaveName2,
    (ScriptSyscall)Sys_ClearSaveName,
    (ScriptSyscall)sub_0202F1C0,
    (ScriptSyscall)sub_0202F208,
    (ScriptSyscall)Sys_SetBattleBgm,
    (ScriptSyscall)Sys_SetBattleCaptureBg,
    (ScriptSyscall)sub_0202F294,
    (ScriptSyscall)sub_0202F29C,
    (ScriptSyscall)sub_0202F2A4,
    (ScriptSyscall)sub_0202F2AC,
    (ScriptSyscall)Sys_GetScriptArg,
    (ScriptSyscall)sub_0202F784,
    (ScriptSyscall)sub_0202F78C,
    (ScriptSyscall)sub_0202F794,
    (ScriptSyscall)sub_0202F79C,
    (ScriptSyscall)sub_0202F7A4,
    (ScriptSyscall)sub_0202F7AC,
    (ScriptSyscall)Sys_UpdateSaveDialog,
    (ScriptSyscall)Sys_SetNextScript,
    (ScriptSyscall)Sys_FadeOutBlack,
    (ScriptSyscall)Sys_FadeOutWhite,
    (ScriptSyscall)Sys_WipeOut,
    (ScriptSyscall)Sys_FadeInBlack,
    (ScriptSyscall)Sys_FadeInWhite,
    (ScriptSyscall)Sys_WipeIn,
    (ScriptSyscall)Sys_IsFading,
    (ScriptSyscall)sub_02030AD0,
    (ScriptSyscall)Sys_StartCameraShake,
    (ScriptSyscall)Sys_StopCameraShake,
    (ScriptSyscall)sub_02030B40,
    (ScriptSyscall)Sys_SetSaveName,
    (ScriptSyscall)Sys_HasSaveName,
    (ScriptSyscall)Sys_EnableEventRect,
    (ScriptSyscall)Sys_DisableEventRect,
    (ScriptSyscall)sub_02030D24,
    (ScriptSyscall)sub_02030DA8,
    (ScriptSyscall)Sys_PlayMissionReceive,
    (ScriptSyscall)Sys_ShowMissionStart,
    (ScriptSyscall)Sys_EndMissionStart,
    (ScriptSyscall)Sys_ShowMissionClear,
    (ScriptSyscall)Sys_EndMissionClear,
    (ScriptSyscall)Sys_EnterQuest,
    (ScriptSyscall)Sys_ShowQuestClear,
    (ScriptSyscall)sub_020318B4,
    (ScriptSyscall)sub_020319C4,
    (ScriptSyscall)Sys_GetChapterValue,
    (ScriptSyscall)Sys_SetChapterValue,
    (ScriptSyscall)Sys_GetGlobalValue,
    (ScriptSyscall)Sys_SetGlobalValue,
    (ScriptSyscall)sub_02031C50,
    (ScriptSyscall)sub_02031CB4,
    (ScriptSyscall)sub_02031E00,
    (ScriptSyscall)sub_02031E30,
    (ScriptSyscall)sub_02031E78,
    (ScriptSyscall)sub_02031F50,
    (ScriptSyscall)sub_02031F64,
    (ScriptSyscall)sub_02031FD4,
    (ScriptSyscall)sub_0202FA24,
    (ScriptSyscall)Sys_StartScreenEffect,
    (ScriptSyscall)Sys_StopScreenEffect,
    (ScriptSyscall)Sys_IsScreenEffectActive,
    (ScriptSyscall)sub_02030EE0,
    (ScriptSyscall)sub_020324DC,
    (ScriptSyscall)sub_02032538,
    (ScriptSyscall)Sys_HasEffect,
    (ScriptSyscall)Sys_IsMissionStartBusy,
    (ScriptSyscall)Sys_IsMissionClearBusy,
    (ScriptSyscall)Sys_PlaySolveBgm,
    (ScriptSyscall)Sys_PlayMissionBridgeBgm,
    (ScriptSyscall)Sys_GetChapter,
    (ScriptSyscall)Sys_IsActorEnabled,
    (ScriptSyscall)sub_020325C0,
    (ScriptSyscall)sub_020319E8,
    (ScriptSyscall)Sys_IsQuestCleared,
    (ScriptSyscall)Sys_GetQuestId,
    (ScriptSyscall)Sys_GetSex,
    (ScriptSyscall)Sys_GetRangerClass,
    (ScriptSyscall)Sys_OpenLetter,
    (ScriptSyscall)Sys_SetSex,
    (ScriptSyscall)Sys_SetRangerClass,
    (ScriptSyscall)sub_0202FE28,
    (ScriptSyscall)Sys_ExitQuest,
    (ScriptSyscall)Sys_SetActorLayer,
    (ScriptSyscall)Sys_SetActorNotSolid,
    (ScriptSyscall)Sys_ClearActorNotSolid,
    (ScriptSyscall)Sys_MoveActorToSlow,
    (ScriptSyscall)sub_02032080,
    (ScriptSyscall)Sys_SetPartnerFlags,
    (ScriptSyscall)Sys_TestPartnerFlags,
    (ScriptSyscall)Sys_IsPartnerPresent,
    (ScriptSyscall)Sys_SetStylerLevel,
    (ScriptSyscall)Sys_GetStylerLevel,
    (ScriptSyscall)Sys_ActorOrbit,
    (ScriptSyscall)Sys_IsActorJumping,
    (ScriptSyscall)Sys_SetHP,
    (ScriptSyscall)Sys_GetMaxHP,
    (ScriptSyscall)Sys_GetHP,
    (ScriptSyscall)sub_0202FF38,
    (ScriptSyscall)sub_0202FF48,
    (ScriptSyscall)sub_0202FFE4,
    (ScriptSyscall)sub_020320C4,
    (ScriptSyscall)Sys_SetSeVolume,
    (ScriptSyscall)Sys_SetScriptArg,
    (ScriptSyscall)sub_02030068,
    (ScriptSyscall)Sys_ShowMessageEx,
    (ScriptSyscall)sub_0202E81C,
    (ScriptSyscall)sub_0202EC08,
    (ScriptSyscall)Sys_StopActorOutline,
    (ScriptSyscall)sub_0202EDFC,
    (ScriptSyscall)Sys_HideActor,
    (ScriptSyscall)Sys_UnhideActor,
    (ScriptSyscall)Sys_SetPartnerNpcName,
    (ScriptSyscall)Sys_IsQuestClearBusy,
    (ScriptSyscall)Sys_EndQuestClear,
    (ScriptSyscall)Sys_ExitQuestCleared,
    (ScriptSyscall)Sys_GetMissionId,
    (ScriptSyscall)sub_020325F0,
    (ScriptSyscall)sub_02032624,
    (ScriptSyscall)Sys_HasEffect2,
    (ScriptSyscall)sub_02032708,
    (ScriptSyscall)sub_0202F2B4,
    (ScriptSyscall)Sys_FadeActorAlpha,
    (ScriptSyscall)Sys_ShakeActor,
    (ScriptSyscall)Sys_StopActorShake,
    (ScriptSyscall)sub_02032850,
    (ScriptSyscall)Sys_SetAudioVar,
    (ScriptSyscall)Sys_GetAudioVar,
    (ScriptSyscall)sub_02032BAC,
    (ScriptSyscall)sub_02032F5C,
    (ScriptSyscall)sub_02032F8C,
    (ScriptSyscall)sub_02033030,
    (ScriptSyscall)sub_0203307C,
    (ScriptSyscall)sub_020330BC,
    (ScriptSyscall)sub_02033134,
    (ScriptSyscall)sub_020331A4,
    (ScriptSyscall)Sys_SetActorOnTop,
    (ScriptSyscall)Sys_ClearActorOnTop,
    (ScriptSyscall)sub_0203324C,
    (ScriptSyscall)sub_020335B8,
    (ScriptSyscall)sub_02031078,
    (ScriptSyscall)Sys_RotateActor,
    (ScriptSyscall)Sys_StartActorBlink,
    (ScriptSyscall)Sys_StopActorBlink,
    (ScriptSyscall)sub_02030F08,
    (ScriptSyscall)sub_02030F38,
    (ScriptSyscall)Sys_HideActorShadow,
    (ScriptSyscall)Sys_ShowActorShadow,
    (ScriptSyscall)sub_02033444,
    (ScriptSyscall)sub_020334B4,
    (ScriptSyscall)sub_0203351C,
    (ScriptSyscall)sub_0203356C,
    (ScriptSyscall)sub_02033660,
    (ScriptSyscall)sub_020336E4,
    (ScriptSyscall)sub_0202F0E4,
    (ScriptSyscall)Sys_FreeCamera,
    (ScriptSyscall)Sys_OpenStyler,
    (ScriptSyscall)sub_02030E2C,
    (ScriptSyscall)Sys_SetPartyEntrySelected,
    (ScriptSyscall)Sys_ClearPartyEntrySelected,
    (ScriptSyscall)Sys_SetPartyEntryPartner,
    (ScriptSyscall)Sys_ClearPartyEntryPartner,
    (ScriptSyscall)Sys_StartActorOutline,
    (ScriptSyscall)Sys_HideHud,
    (ScriptSyscall)Sys_ShowHud,
    (ScriptSyscall)Sys_HideField,
    (ScriptSyscall)Sys_ShowField,
    (ScriptSyscall)sub_020300B8,
    (ScriptSyscall)Sys_LoadSystemSe,
    (ScriptSyscall)sub_02032A74,
    (ScriptSyscall)sub_02032858,
    (ScriptSyscall)Sys_GameOver,
    (ScriptSyscall)Sys_StartStaffroll,
    (ScriptSyscall)Sys_OpenSuitePicture,
    (ScriptSyscall)Sys_OpenRecord,
    (ScriptSyscall)sub_020329E0,
    (ScriptSyscall)sub_020329FC,
    (ScriptSyscall)sub_0202DEE8,
    (ScriptSyscall)sub_0203289C,
    (ScriptSyscall)Sys_ShowTitleBanner,
    (ScriptSyscall)Sys_IsTitleBannerActive,
    (ScriptSyscall)Sys_ReleaseTitleBanner,
    (ScriptSyscall)Sys_SetRangerGrade,
    (ScriptSyscall)Sys_GetRangerGrade,
    (ScriptSyscall)sub_0202F2D8,
    (ScriptSyscall)Sys_StopBgmReset,
    (ScriptSyscall)Sys_PlayMapBgm,
    (ScriptSyscall)Sys_IsHPChanging,
    (ScriptSyscall)sub_0202E210,
    (ScriptSyscall)sub_02031F00,
    (ScriptSyscall)Sys_GetPartnerMood,
    (ScriptSyscall)Sys_OpenNameInput,
    (ScriptSyscall)sub_02030F68,
    (ScriptSyscall)sub_0202D608,
    (ScriptSyscall)sub_0202D680,
    (ScriptSyscall)Sys_ReceiveMission,
    (ScriptSyscall)Sys_PlayPartnerCry,
    (ScriptSyscall)Sys_SetTargetOffset,
    (ScriptSyscall)Sys_GetTargetX,
    (ScriptSyscall)Sys_GetTargetY,
    (ScriptSyscall)Sys_GetQuestValue,
    (ScriptSyscall)Sys_SetQuestValue,
    (ScriptSyscall)Sys_ClearMission,
    (ScriptSyscall)sub_020332AC,
    (ScriptSyscall)sub_02033320,
    (ScriptSyscall)sub_0203338C,
    (ScriptSyscall)sub_020333DC,
    (ScriptSyscall)sub_0202F300,
    (ScriptSyscall)sub_0202E9C0,
    (ScriptSyscall)sub_02033610,
    (ScriptSyscall)Sys_EndDownloadMission,
    (ScriptSyscall)sub_0203044C,
    (ScriptSyscall)sub_02033718,
    (ScriptSyscall)sub_020337EC,
    (ScriptSyscall)sub_0203381C,
    (ScriptSyscall)sub_02033844,
    (ScriptSyscall)sub_0203386C,
    (ScriptSyscall)sub_02033884,
    (ScriptSyscall)sub_020338A0,
    (ScriptSyscall)sub_020338BC,
    (ScriptSyscall)sub_020338DC,
    (ScriptSyscall)sub_020338FC,
    (ScriptSyscall)sub_02033918,
    (ScriptSyscall)sub_02033934,
    (ScriptSyscall)Sys_StartQuest,
    (ScriptSyscall)Sys_IsQuestActive,
    (ScriptSyscall)sub_020321F8,
    (ScriptSyscall)sub_0202EA5C,
    (ScriptSyscall)sub_020331F4,
    (ScriptSyscall)Sys_ShowSubScreenPicture,
    (ScriptSyscall)sub_0203054C,
    (ScriptSyscall)sub_02033968,
    (ScriptSyscall)sub_02033994,
    (ScriptSyscall)sub_020339D8,
    (ScriptSyscall)sub_02033A38,
    (ScriptSyscall)sub_02033A7C,
    (ScriptSyscall)sub_02033AD4,
    (ScriptSyscall)sub_0202F348,
    (ScriptSyscall)Sys_SetBattleSequenceScript,
    (ScriptSyscall)Sys_SetBattleTutorialScript,
    (ScriptSyscall)Sys_SetBattleStartScript,
    (ScriptSyscall)Sys_SetBattleStylerLevel,
    (ScriptSyscall)Sys_AddBattlePartyMember,
    (ScriptSyscall)Sys_AddBattleEnemy,
    (ScriptSyscall)Sys_SetBattleBanner,
    (ScriptSyscall)sub_0202F4E8,
    (ScriptSyscall)sub_02031F28,
    (ScriptSyscall)sub_020322B0,
    (ScriptSyscall)Sys_SwitchSubScreenToMap,
    (ScriptSyscall)sub_0203059C,
    (ScriptSyscall)Sys_PressTouch,
    (ScriptSyscall)Sys_ReleaseTouch,
    (ScriptSyscall)Sys_DragTouch,
    (ScriptSyscall)sub_0203064C,
    (ScriptSyscall)Sys_SetTouchMode,
    (ScriptSyscall)Sys_SetSubScreenIdleReturn,
    (ScriptSyscall)sub_0203238C,
    (ScriptSyscall)sub_02032768,
    (ScriptSyscall)sub_02032794,
    (ScriptSyscall)sub_02032A18,
    (ScriptSyscall)sub_02032A48,
    (ScriptSyscall)Sys_BackupSave,
    (ScriptSyscall)Sys_RestoreSave,
    (ScriptSyscall)Sys_LoadChapterMessages,
    (ScriptSyscall)Sys_OpenOpeningDemo,
    (ScriptSyscall)Sys_ShowBrowserFanfare,
    (ScriptSyscall)Sys_IsBrowserFanfareBusy,
    (ScriptSyscall)Sys_EndBrowserFanfare,
    (ScriptSyscall)sub_0202BEA0,
    (ScriptSyscall)sub_0202BF90,
    (ScriptSyscall)Sys_StartMission,
    (ScriptSyscall)Sys_ShowRangerCard,
    (ScriptSyscall)Sys_SetBattlePartnerMood,
    (ScriptSyscall)Sys_CheckBrowserComplete,
    (ScriptSyscall)Sys_PlayGroupSe,
    (ScriptSyscall)sub_0202C768,
    (ScriptSyscall)sub_020323B4,
    (ScriptSyscall)sub_020324A8,
    (ScriptSyscall)Sys_SetQuestEntered,
    (ScriptSyscall)Sys_IsQuestEntered,
    (ScriptSyscall)sub_02031EA8,
    (ScriptSyscall)sub_02031E54,
    (ScriptSyscall)sub_020323C8,
    (ScriptSyscall)sub_0202F0A8,
    (ScriptSyscall)sub_02031ED8,
    (ScriptSyscall)Sys_AddPokemonRide,
    (ScriptSyscall)sub_0202E43C,
    (ScriptSyscall)Sys_GetCameraX,
    (ScriptSyscall)Sys_GetCameraY,
    (ScriptSyscall)sub_02033B6C,
    (ScriptSyscall)sub_02033BBC,
    (ScriptSyscall)Sys_GetSaveCount,
    NULL,
};
