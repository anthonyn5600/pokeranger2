// Field debug menu: variable accessors and the menu tables (the retail game has no menu interpreter left)
//
// TODO(revisit after overlay 0 is finished): FAKE data order. The tables' strings, arrays and .bss statics all go
// through mwcc's size heapsort, and no natural source order reproduces the original layout (the original most likely
// had dead static tables that left no trace). sUnusedNames below and the declaration order of the .bss statics and
// tables were computed to match (~/scratch/ov0/fb984/construct2.py, NOTES.md there); find the real source order.

#include "UnkClass_0214B984.hpp"

#include <nitro.h>
#include <string.h>

#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "DebugProcess.hpp"
#include "FieldDebugMenu.hpp"
#include "FieldEventRectManage.hpp"
#include "FieldScreenEffectManage.hpp"
#include "FieldSubScreen.hpp"
#include "GlobalValues.hpp"
#include "MissionQuestData.hpp"
#include "SaveData.hpp"
#include "TextboxManager.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkStruct_020107A8.hpp"
#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldEffectManpu.hpp"
#include "field/CFieldPartner.hpp"
#include "field/CFieldPartnerManage.hpp"
#include "field/CFieldPlayer.hpp"
#include "field/CFieldScreenEffect.hpp"
#include "field/CFieldTargetObject.hpp"
#include "field/CFieldTargetObjectManage.hpp"
#include "field/FieldPartnerIndex.hpp"
#include "scene/CFieldScene.hpp"

extern UnkClass_0214B984 *MAIN_BSS_0210CA68;
extern FieldDebugMenu *MAIN_BSS_0210CA80;
extern FieldData *MAIN_BSS_0210CA6C;
extern SaveData MAIN_BSS_020B26A0;
extern CFieldScene *MAIN_BSS_0210CA40;
extern CFieldPlayer *MAIN_BSS_0210CA48;
extern CFieldTargetObjectManage *MAIN_BSS_0210CA7C;
extern CFieldPartnerManage *MAIN_BSS_0210CA4C;
extern FieldEventRectManage *MAIN_BSS_0210CA58;
extern CFieldEffectManage *MAIN_BSS_0210CA60;
extern FieldScreenEffectManage *MAIN_BSS_0210CA78;

extern "C" {
BOOL SaveData_IsInParty(SaveData *save, int mapId, int idx);
BOOL SaveData_AddToParty(SaveData *save, u32 id, int kind, int arg3);
void MissionQuestData_SetChapter(MissionQuestData *missionQuestData, u32 chapter);
void LogInfo(const char *fmt, ...);
void MissionQuestData_EnterQuest(MissionQuestData *obj, int quest);
void MissionQuestData_ExitQuest(MissionQuestData *obj);
void SaveData_SetPartsLevel(SaveData *save, int idx, int count);
void SaveData_SetPartnerCount(SaveData *save, int idx, u32 value);
void SaveData_SetPlayTime(SaveData *save, u32 hours, u8 minutes, u8 seconds);
}

struct UnkStruct_0208AC1C {
    char name[0x10];
    u32 mapId;
    int x;
    int y;
};

extern UnkStruct_0208AC1C s_c000First_0208ac1c[];
extern u16 DAT_0208c55c[];

extern "C" {
}

UnkClass_0214B984::UnkClass_0214B984()
{
    MAIN_BSS_0210CA68 = this;
    unk_00 = 0;
}

UnkClass_0214B984::~UnkClass_0214B984()
{
    MAIN_BSS_0210CA68 = NULL;
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

static inline u32 GetCaptureState(SaveData *save, int group, int i)
{
    if (group >= 0 && group < 3 && i >= 0 && i < 64) {
        return (save->m_encyclopediaStates[group][i / 16] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

static inline u32 GetEncState(SaveData *save, int group, int i)
{
    if (i >= 0 && i < 64) {
        return (save->m_encyclopediaStates[group][i / 16] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

static inline BOOL IsBrowserEntry(int i)
{
    if (i > 0x1EC || i == 0) {
        return FALSE;
    }
    if (DAT_0208c55c[i] == 0xFFFF) {
        return FALSE;
    }
    return TRUE;
}

static inline void SetBrowserState(SaveData *save, int i, u8 state)
{
    if (i >= 0 && i < 500 && state <= 3) {
        int shift = (i & 0xF) * 2;
        save->m_pokemonStates[i >> 4] &= ~(3 << shift);
        save->m_pokemonStates[i >> 4] |= (state & 3) << shift;
    }
}

static inline int GetQuestState(MissionQuestData *quests, int quest)
{
    int state = 0;
    u8 flags = quests->m_questStates[quest];
    switch (flags & 0xF) {
    case 1:
        if (flags & 0x10) {
            if (quests->m_questActive == 1 && quest == quests->m_questId) {
                return 3;
            }
            return 2;
        }
        return 1;
    case 2:
        state = 4;
        break;
    }
    return state;
}

extern DebugMenuItem sCustom2Items[];
extern const char *sManpuNames[];
extern DebugMenuItem sEventChapterItems[];
extern DebugMenuItem sQuestStatusItems[];
extern DebugMenuItem sPartnerList0Items[];
extern DebugMenuItem sFieldEffectItems[];
extern const char *sFootStepNames[];
extern const char *sMoodNames[];
extern DebugMenuItem sRangerRecordItems[];
extern DebugMenuItem sMAINItems[];
extern int sManpuTypes[15];
extern DebugMenuItem sEventFlagsItems[];
extern DebugMenuItem sCustom0Items[];
extern DebugMenuItem sEventItems[];
extern DebugMenuItem sPartnerMoodItems[];
extern const char *sSexNames[];
extern const char *sWatchNames[];
extern DebugMenuItem sBrowserItems[];
extern const char *sEncStates[];
extern DebugMenuItem sQuestItems[];
extern DebugMenuItem sAddTargetItems[];
extern DebugMenuItem sCustomPartsItems[];
extern DebugMenu sMenus[];
extern DebugMenuItem sAddPartyItems[];
extern DebugMenuItem sPartnerList1Items[];
extern DebugMenuItem sDebugInfoItems[];
extern DebugMenuItem sEncyclopediaMapItems[];
extern DebugMenuItem sMapItems[];
extern DebugMenuItem sPlayerMoveItems[];
extern DebugMenuItem sEncyclopediaCaptItems[];
extern DebugMenuItem sFogColorItems[];
extern const char *sCaptureNames[];
extern const char *sQuestStates[];
extern DebugMenuItem sActorDispItems[];
extern DebugMenuItem sPlayerItems[];
extern const char *sTestEffectNames[];
extern DebugMenuItem sSetWeatherItems[];
extern DebugMenuItem sSetActorItems[];
extern DebugMenuItem sEncyclopediaItems[];
extern DebugMenuItem sCustom1Items[];
extern DebugMenuItem sPartnerAssistCountItems[];
extern const char *sPutFieldNames[];
extern DebugMenuItem sEncyclopediaWordItems[];
extern DebugMenuItem sMapJumpItems[];
extern DebugMenuItem sPartnerGetFlagItems[];
extern const char *sDebugPrimNames[];

// FAKE (see TODO at the top). Unused (mwcc drops unreferenced static tables): its names are created first, which gives the TU's data
// size sort the original .data/.bss layout. Order computed by ~/scratch/ov0/fb984/construct2.py.
static const char *sUnusedNames[] = {
    "POSY",
    "TalkCnt",
    "PlayerMove",
    "IKARI",
    "DARKFOG2",
    "PlyrHP",
    "EncyclopediaMap",
    "Collision",
    "DARKFOG3",
    "CHAP",
    "Player",
    "SGOKIGEN",
    "put field",
    "LIGHT_G",
    "PtAssCnt",
    "PlyrDisp",
    "B-STONE",
    "BLOOM2",
    "OFF",
    "BLOOM3",
    "MAIN",
    "KIZUKI",
    "EventFlags",
    "PartnerMood",
    "CLEAR",
    "SNOW",
    "BLOOM1",
    "NORMAL",
    "1X3",
    "Weather",
    "A",
    "view party",
    "Custom1",
    "HINT_B",
    "TouchRect",
    "ROCK_G",
    "Custom2",
    "GOOD",
    "B-STONE2",
    "EncWord",
    "COMBO",
    "Event",
    "RideCnt",
    "CollFree",
    "LongLine",
    "Manene",
    "Mission",
    "ASE",
    "DbgInfo",
    "SetWeather",
    "PokeAdd",
    "B",
    "LookCnt",
    "PSYCHO_G",
    "QUE",
    "EscpCnt",
    "GLITTER",
    "DRAGON_G",
    "EneDisp",
    "Hide ALL",
    "ACCEPT",
    "ActorDisp",
    "POSX",
    "Map",
    "AIR_G",
    "TestEff",
    "AddTarget",
    "Chapter",
    "MANPU",
    "BIKKURI",
    "Disp ALL",
    "SYS",
    "TargetID",
    "PartnerGetFlag",
    "Quest",
    "(none)",
    "12X",
    "List1",
    "X23",
    "DOKARIMO",
    "ScriptID",
    "PlyrMove",
    "CaptCnt",
    "FIRE_G",
    "MapJump",
    "(hide)",
    "HPGauge",
    "EncMap",
    "CLEAR3",
    "SetWatchAll",
    "XX3",
    "CAPTURE",
    "LOOK",
    "BAT",
    "Zugaidos",
    "EncFree",
    "m_008_006",
    "SOKO",
    "Korobohshi",
    "MALE",
    "Gonbe",
    "HATENA",
    "Hikozaru",
    "Gureggru",
    "Fukamaru",
    "R",
    "ChapJump",
    "Mukkuru",
    "EncyclopediaCapt",
    "1XX",
    "FEMALE",
    "QuestSta",
    "Muma",
    "HPDisp",
    "SHADOW1",
    "TotalExp",
    "CLEAR2",
    "SHADOW2",
    "Pachirisu",
    "123",
    "(fall)",
    "FogParam",
    "PartnerAssistCount",
    "PartnerList0",
    "AddParty",
    "SPCapture",
    "HANABI1",
    "PartnerList1",
    "ObjDisp",
    "DARKRIE",
    "Pochama",
    "ICE_G",
    "CREVICE1",
    "HINT_A(G",
    "PlyTime",
    "CLOSE",
    "Quest RANDOM",
    "XXX",
    "HANABI2",
    "",
    "RangGrd",
    "GAMEEND",
    "MOBARIMO",
    "TexVramInfo",
    "ARIENAI!",
    "VERYGOOD",
    "List2",
    "INSECT_G",
    "Regigigas",
    "FLOWER",
    "PlttVramInfo",
    "EncCapt",
    "DARKFOG1",
    "QuestStatus",
    "FIGHT_G",
    "EvArea",
    "Yukikaburi",
    "FogColor",
    "DEBPRIM",
    "PlyrSex",
    "CLEAR1",
    "put party",
    "ASSISTT",
    "UpperDbgInfo",
    "GRASS",
    "CustomParts",
    "MUDDY",
    "CROUND_G",
    "SaveCnt",
    "RECOVER",
    "List0",
    "LineLeng",
    "POISON_G",
    "GOKIGEN",
    "DebugInfo",
    "PrtyDisp",
    "CREVICE2",
    "METAL_G",
    "AREA",
    "HORROR_G",
    "DARK_G",
    "EnclsCnt",
    "Event(Chap",
    "Browser",
    "SUPERCHG",
    "NpcDisp",
    "SetActor",
    "VisitAll",
    "Custom0",
    "Encyclopedia",
    "LastMes",
    "ENEPLS",
    "Poke:",
    "RangCls",
    "FieldEffect",
    "Wanriky",
    "CLEAR4",
    "OPEN",
    "RangerRecord",
    "Naetle",
    "G",
    "HINT_A(B",
    "Quest CLOSE ALL",
    "NONE",
    "PlyrLvl",
    "NEW",
    "AQUA_G",
    "m_008_008",
    "AssCnt",
    "ProcLoad",
    "X2X",
    "Nyula",
    "Quest OPEN ALL",
    "Tatetopsu",
    "FootStep",
    "CHGSPD",
    "WATER",
    "WalkStep",
    "Custom",
    "HINT_A(R",
    "MapID",
    "EventChapter",
    "Hippopotas",
    "EncyclopediaWord",
    "NORMAL_G",
    "LEAF_G",
    "POWPLS",
};

static char sEncWordName[12];
static char sPokeName[16];
static char sAssistName[64];
static char sEncMapStateName[12];
static char sMissionLine[24];
static char sStoryLine2[32];
static char sEncCaptStateName[12];
static char sStoryLine3[32];
static char sQuestLine[24];
static char sQuestValueLine0[32];
static char sEncWordStateName[12];
static int sEncCaptIdx;
static int sQuestIdx;
static u16 sTargetId;
static char sMapName[12];
static char sQuestValueLine1[32];
static char sLastMessage[64];
static char sPlayTime[16];
static char sEventLine0[32];
static char sEventLine1[32];
static char sQuestListName[12];
static char sEventLine2[32];
static char sChapterLine[24];
static char sQuestName[12];
static char sTargetName[16];
static char sStoryLine0[32];
static int sAssistIdx;
static int sEncWordIdx;
static char sEncMapName[12];
static int sEncMapIdx;
static char sEncCaptName[12];
static char sStoryLine1[32];

extern "C" {

const char *ov0_0214B9B0(int id)
{
    strcpy(sMapName, "error");
    if (MAIN_BSS_0210CA6C != NULL) {
        UnkStruct_02041D80 *map = FieldData_GetMap(MAIN_BSS_0210CA6C, id);
        if (map != NULL) {
            if (id > 0) {
                if (map->unk_02 == 0xFF) {
                    OS_SPrintf(sMapName, "m%03d_%03d", map->unk_00, map->unk_01);
                } else {
                    OS_SPrintf(sMapName, "m%03d_%03d%c", map->unk_00, map->unk_01, map->unk_02 + 'a');
                }
            } else {
                strcpy(sMapName, "test");
            }
        }
    }
    return sMapName;
}

int ov0_0214BAAC()
{
    int count = 0;
    if (MAIN_BSS_0210CA6C != NULL) {
        count = 441;
    }
    return count;
}

int ov0_0214BACC()
{
    return MAIN_BSS_020B26A0.m_mapId;
}

void Debug_SetMapJump(int mapId)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        scene->m_flags |= 2;
        scene->unk_0068 = mapId;
        scene->unk_006C = 0;
        scene->unk_0070 = 0;
        scene->unk_0074 = -1;
    }
}

int Debug_GetTargetID()
{
    return sTargetId;
}

void Debug_SetTargetID(int id)
{
    sTargetId = id;
}

const char *ov0_0214BB38(int id)
{
    strcpy(sTargetName, "NONE");
    if (id > 0 && MAIN_BSS_0210CA6C != NULL) {
        FieldTargetObjectData *data = FieldData_GetTargetObject(MAIN_BSS_0210CA6C, id);
        if (data != NULL) {
            OS_SPrintf(sTargetName, "%03d)t%03d_%02d", id, data->unk_00, data->unk_02);
        }
    }
    return sTargetName;
}

int ov0_0214BBCC()
{
    int count = 0;
    if (MAIN_BSS_0210CA6C != NULL) {
        count = 369;
    }
    return count;
}

void Debug_DoScriptID(int scriptId)
{
    if (sTargetId == 0) {
        return;
    }
    if (sTargetId >= 369) {
        return;
    }
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player == NULL) {
        return;
    }
    Point2D pos = player->GetPos();
    CFieldTargetObjectManage *targets = MAIN_BSS_0210CA7C;
    if (targets == NULL) {
        return;
    }
    int count = targets->CountActors();
    int index = targets->ov0_0213D1AC(count, sTargetId, scriptId, 0, 0);
    if (index < 0) {
        return;
    }
    CFieldTargetObject *target = (CFieldTargetObject *)targets->Get(index);
    target->SetPos(pos);
    target->SetHomePos(pos);
    target->unk_E0 = 0;
    target->unk_E4 = 0;
    target->SetLayer(player->m_layer);
    target->unk_20 = 2;
}

int Debug_GetPosx()
{
    int x = 0;
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player != NULL) {
        x = player->GetX() >> FX32_SHIFT;
    }
    return x;
}

void Debug_SetPosx(int x)
{
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player == NULL) {
        return;
    }
    player->SetPosXY(x << FX32_SHIFT, player->GetY());
    player->ov0_021307B0(NULL, NULL, NULL, NULL, 0);
}

int Debug_GetPosy()
{
    int y = 0;
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player != NULL) {
        y = player->GetY() >> FX32_SHIFT;
    }
    return y;
}

void Debug_SetPosy(int y)
{
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player == NULL) {
        return;
    }
    player->SetPosXY(player->GetX(), y << FX32_SHIFT);
    player->ov0_021307B0(NULL, NULL, NULL, NULL, 0);
}

void Debug_DoGameend(int on)
{
    if (on && MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_flags |= 0x10;
    }
}

int Debug_GetDebprim()
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL && (debug->unk_00 & 1)) {
        // always 0: the bit shifted out (a plain `return 0` lets IRO fold the test away)
        return (debug->unk_00 & 1) >> 1;
    }
    return 0;
}

void Debug_SetDebprim(int on)
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL) {
        u32 flags = debug->unk_00;
        if (on) {
            flags |= 1;
        } else {
            flags &= ~1;
        }
        debug->unk_00 = flags;
    }
}

int ov0_0214C010()
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        return !(scene->m_flags & 0x800);
    }
    return 0;
}

void ov0_0214C040(int on)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        if (on) {
            scene->m_flags &= ~0x800;
        } else {
            scene->m_flags |= 0x800;
        }
    }
}

int Debug_GetPlyrHP()
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    return save != NULL ? save->m_energy : 0;
}

void Debug_SetPlyrHP(int hp)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    save->m_energy = hp;
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_hpGauge->SetCurrentHP(save->m_energy);
    }
}

int Debug_GetPlyrLvl()
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    return save != NULL ? save->m_stylerLevel : 0;
}

void Debug_SetPlyrLvl(int level)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    SaveData_SetStylerLevel(save, (u8)level);
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_hpGauge->SetHP(save->m_energy, save->m_maxEnergy);
    }
}

int Debug_GetRangCls()
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    return save != NULL ? save->m_rangerClassGrade & 0xF : 0;
}

void Debug_SetRangCls(int rank)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF0) | (u8)rank;
    FieldSubScreen *obj = FieldSubScreen::GetInstance();
    if (obj != NULL) {
        obj->sub_02022B20();
    }
}

int Debug_GetRangGrd()
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    return save != NULL ? (save->m_rangerClassGrade >> 4) & 0xF : 0;
}

void Debug_SetRangGrd(int grade)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (((save->m_rangerClassGrade >> 4) & 0xF) == (u8)grade) {
        return;
    }
    save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF) | ((u8)grade << 4);
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player == NULL) {
        return;
    }
    Point2D pos = player->GetPos();
    player->ov0_02132F14(save->m_sex, (u8)((save->m_rangerClassGrade >> 4) & 0xF), save->m_areaType);
    player->ov0_02132FA0(save->unk_8802);
    player->SetPos(pos);
}

int Debug_GetPlyrSex()
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    return save != NULL ? save->m_sex : 0;
}

void Debug_SetPlyrSex(int sex)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save->m_sex == (u8)sex) {
        return;
    }
    save->m_sex = (u8)sex & 1;
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player == NULL) {
        return;
    }
    Point2D pos = player->GetPos();
    player->ov0_02132F14(save->m_sex, (u8)((save->m_rangerClassGrade >> 4) & 0xF), save->m_areaType);
    player->ov0_02132FA0(save->unk_8802);
    player->SetPos(pos);
}

int Debug_GetCollFree()
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL && (debug->unk_00 & 2)) {
        return 1;
    }
    return 0;
}

void Debug_SetCollFree(int on)
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL) {
        u32 flags = debug->unk_00;
        if (on) {
            flags |= 2;
        } else {
            flags &= ~2;
        }
        debug->unk_00 = flags;
    }
}

const char *ov0_0214C4A0(int kind)
{
    strcpy(sPokeName, "error");
    UnkStruct_020107A8 *info = PokeIdTable_Get(s_game->unk_1434, kind);
    if (info != NULL) {
        OS_SPrintf(sPokeName, "%03d)p%03d_%02d", kind, info->unk_00, info->unk_02);
    }
    return sPokeName;
}

int ov0_0214C540()
{
    int count = 0;
    if (MAIN_BSS_0210CA6C != NULL) {
        count = 443;
    }
    return count;
}

int Debug_GetPokeAdd()
{
    return 0;
}

void Debug_SetPokeAdd(int kind)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    u16 slot = 0xFFF;
    for (u16 i = 0; i < 0xFFF; i++) {
        if (!SaveData_IsInParty(save, 0xFFF, i)) {
            slot = i;
            break;
        }
    }
    u32 id = (slot & 0xFFF) | 0x1FFF000;
    CFieldPartnerManage *partners;
    if (SaveData_AddToParty(save, id, kind, -1) && (partners = MAIN_BSS_0210CA4C) != NULL) {
        partners->ov0_02139920(id, kind, 0xE, 0, 1);
        FieldActorManage_RestartAllScripts(partners);
        if (HasPartnerIndex((u16)kind)) {
            PartyEntry *entry = SaveData_FindEntry(save, id);
            if (entry != NULL) {
                entry->m_flags |= 2;
            }
        }
    }
}

int Debug_GetEvArea()
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL && (debug->unk_00 & 4)) {
        return 1;
    }
    return 0;
}

void Debug_SetEvArea(int on)
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL) {
        u32 flags = debug->unk_00;
        if (on) {
            flags |= 4;
        } else {
            flags &= ~4;
        }
        debug->unk_00 = flags;
        FieldEventRectManage *rects = MAIN_BSS_0210CA58;
        if (rects != NULL) {
            rects->m_draw = on ? TRUE : FALSE;
        }
    }
}

int Debug_GetEncFree()
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL && (debug->unk_00 & 8)) {
        return 1;
    }
    return 0;
}

void Debug_SetEncFree(int on)
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL) {
        u32 flags = debug->unk_00;
        if (on) {
            flags |= 8;
        } else {
            flags &= ~8;
        }
        debug->unk_00 = flags;
    }
}

int Debug_GetProcLoad()
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL && (debug->unk_00 & 0x10)) {
        return 1;
    }
    return 0;
}

void Debug_SetProcLoad(int on)
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL) {
        u32 flags = debug->unk_00;
        if (on) {
            flags |= 0x10;
        } else {
            flags &= ~0x10;
        }
        debug->unk_00 = flags;
    }
}

int ov0_0214C790()
{
    return s_game->m_missionQuestData->m_chapter;
}

void Debug_SetChapJump(int chapter)
{
    CFieldPartnerManage *partners = MAIN_BSS_0210CA4C;
    SaveData *save = &MAIN_BSS_020B26A0;
    for (int i = 0; i < 2; i++) {
        PartnerSlot *partner = MAIN_BSS_020B26A0.GetPartner(i);
        if (partner != NULL && partner->unk_00 != 0) {
            if (partners != NULL) {
                partners->ov0_0213A050(partner->unk_04);
            }
            partner->unk_00 = 0;
        }
    }
    const char *name = s_c000First_0208ac1c[chapter].name;
    if (name != NULL) {
        strcpy(save->m_saveName, name);
    } else {
        save->m_saveName[0] = 0;
    }
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        scene->m_flags |= 2;
        scene->unk_0068 = s_c000First_0208ac1c[chapter].mapId;
        scene->unk_006C = s_c000First_0208ac1c[chapter].x;
        scene->unk_0070 = s_c000First_0208ac1c[chapter].y;
        scene->unk_0074 = 0;
    }
    GlobalValues_ClearChapterValues((GlobalValues *)s_game->unk_14B4);
    GlobalValues_ApplyProgress((GlobalValues *)s_game->unk_14B4, chapter);
    MissionQuestData_SetChapter(s_game->m_missionQuestData, chapter);
}

void ov0_0214C900()
{
    NNS_GfdDumpLnkTexVramManager();
}

void Debug_DoPlttVramInfo()
{
    NNS_GfdDumpLnkPlttVramManager();
}

void Debug_DoUpperDbgInfo()
{
    FieldSubScreen *obj = FieldSubScreen::GetInstance();
    if (obj != NULL) {
        obj->sub_02022D04();
    }
}

void Debug_DoViewParty()
{
    LogInfo("****************************************");
    LogInfo("PartyInfo start");
    LogInfo("****************************************");
    LogInfo("----------");
    LogInfo("commondata");
    LogInfo("----------");
    SaveData *save = &MAIN_BSS_020B26A0;
    LogInfo("----------");
    LogInfo("partnernpc");
    LogInfo("----------");
    LogInfo("----------");
    LogInfo("partnerpoke");
    LogInfo("----------");
    for (int i = 0; i < 10; i++) {
        PartyEntry *entry = SaveData_GetEntry(save, i);
        if (entry != NULL && (entry->m_flags & 1)) {
            LogInfo("*******************************");
            LogInfo("arrryindex= %d", i);
            LogInfo("pokeid= %d", entry->m_kind);
            LogInfo("mapID= %d", entry->m_mapId);
            LogInfo("NpcID= %d", entry->m_index);
            LogInfo("*******************************");
        }
    }
    LogInfo("----------");
    LogInfo("filedpartner");
    LogInfo("----------");
    CFieldPartnerManage *partners = MAIN_BSS_0210CA4C;
    if (partners != NULL) {
        for (int i = 0; i < partners->m_count; i++) {
            CFieldPartner *partner = (CFieldPartner *)partners->Get(i);
            if (partner != NULL) {
                LogInfo("***************");
                LogInfo("linenumber= %d", partner->unk_1E8);
                LogInfo("id= %d", partner->m_id);
                LogInfo("typeid= %d", partner->unk_200);
                LogInfo("***************");
            }
        }
    }
    LogInfo("****************************************");
    LogInfo("PartyInfo end");
    LogInfo("****************************************");
}

int Debug_GetWeather()
{
    return 0;
}

void Debug_SetWeather(int weather)
{
    LogInfo("****************************************");
    LogInfo("Weather Start");
    LogInfo("****************************************");
    FieldScreenEffectManage *control = MAIN_BSS_0210CA78;
    control->ClearPrimary();
    control->sub_02035D38(weather);
    control->StartEffect(weather, 120, -1, 0);
    if (weather != 0) {
        return;
    }
    Debug_SetRangCls(10);
    Debug_SetPokeAdd(218);
    Debug_SetPokeAdd(30);
    Debug_SetPokeAdd(29);
    Debug_SetPokeAdd(20);
    Debug_SetPokeAdd(198);
    Debug_SetPokeAdd(38);
    Debug_SetPokeAdd(38);
    for (int i = 0; i < 500; i++) {
        RaisePokemonState(&MAIN_BSS_020B26A0, i, 1);
    }
}

int Debug_GetA()
{
    return CFieldSEFFog::GetDensity();
}

void Debug_SetA(int density)
{
    CFieldSEFFog::SetDensity(density);
}

int Debug_GetR()
{
    return CFieldSEFFog::GetColorR();
}

void Debug_SetR(int r)
{
    CFieldSEFFog::SetColorR(r);
}

int Debug_GetG()
{
    return CFieldSEFFog::GetColorG();
}

void Debug_SetG(int g)
{
    CFieldSEFFog::SetColorG(g);
}

int Debug_GetB()
{
    return CFieldSEFFog::GetColorB();
}

void Debug_SetB(int b)
{
    CFieldSEFFog::SetColorB(b);
}

int Debug_GetFootStep()
{
    CFieldEffectManage *manage = MAIN_BSS_0210CA60;
    return manage != NULL ? manage->unk_77C : 0;
}

void Debug_SetFootStep(int value)
{
    CFieldEffectManage *manage = MAIN_BSS_0210CA60;
    if (manage != NULL) {
        manage->unk_77C = value;
    }
}

int Debug_GetManpu()
{
    return 0;
}

void Debug_SetManpu(u32 type)
{
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player == NULL) {
        return;
    }
    if (type >= sizeof(sManpuTypes)) {
        return;
    }
    Actor_HideManpu(player);
    Actor_ShowManpu(player, sManpuTypes[type], -1);
}

int Debug_GetTestEff()
{
    return 0;
}

void Debug_SetTestEff(int type)
{
    CFieldEffectManage *manage = MAIN_BSS_0210CA60;
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (manage == NULL || player == NULL) {
        return;
    }
    u16 id;
    switch (type) {
    case 0:
        id = manage->ov0_02142F6C(0x13, 0);
        break;
    case 1:
        id = manage->ov0_02142F6C(0x13, 1);
        break;
    case 2:
        id = manage->ov0_02142F6C(0x13, 2);
        break;
    case 3:
        id = manage->ov0_02142F6C(0x14, 0);
        break;
    case 4:
        id = manage->ov0_02142F6C(0x14, 1);
        break;
    case 5:
        id = manage->ov0_02142F6C(0x14, 2);
        break;
    case 6:
        id = manage->ov0_02142F6C(0x16, 0);
        break;
    case 7:
        id = manage->ov0_02142F6C(0x16, 1);
        break;
    case 8:
        id = manage->ov0_02142F6C(0x15, 0);
        break;
    case 9:
        id = manage->ov0_02142F6C(0x15, 1);
        break;
    case 10:
        id = manage->ov0_02142F6C(0x17, 0);
        break;
    case 11:
        id = manage->ov0_02142F6C(0x17, 0);
        break;
    case 12:
        id = manage->ov0_02142F6C(0x17, 1);
        break;
    case 13:
        id = manage->ov0_02142F6C(0x17, 1);
        break;
    case 14:
        id = manage->ov0_02142F6C(0x1B, 0);
        break;
    case 15:
        id = manage->ov0_02142F6C(0x1C, 0);
        break;
    case 16:
        id = manage->ov0_02142F6C(0x1C, 1);
        break;
    case 17:
        id = manage->ov0_02142F6C(0x1D, 1);
        break;
    case 18:
    case 19:
        id = manage->ov0_02142F6C(0x1E, 0);
        break;
    default:
        id = 0;
        break;
    }
    if (id == 0) {
        return;
    }
    CFieldEffect *effect = manage->ov0_02143088(id);
    if (effect == NULL) {
        return;
    }
    fx32 x = player->GetX();
    fx32 y = player->GetY();
    effect->SetParam(1, x >> FX32_SHIFT);
    if (effect->GetEffectId() == 0x13) {
        effect->SetColor(0x421F);
        effect->SetParam(2, y >> FX32_SHIFT);
        effect->ov0_021421F0(0, -1, 0);
        return;
    }
    if (effect->GetEffectId() == 0x15) {
        effect->SetParam(2, (y >> FX32_SHIFT) - 0x40);
        effect->ov0_021421F0(type == 9 ? 5 : 4, 0, 60);
        return;
    }
    if (effect->GetEffectId() == 0x17) {
        effect->SetParam(2, y >> FX32_SHIFT);
        effect->ov0_021421F0(0, 30, 180);
        if (type == 11 || type == 13) {
            CGame::GetInstance()->m_mainFade->Start(3, 180);
        }
        return;
    }
    if (effect->GetEffectId() == 0x1B) {
        effect->SetParam(2, y >> FX32_SHIFT);
        effect->ov0_021421F0(30, 0, 30);
        return;
    }
    if (effect->GetEffectId() == 0x1E) {
        effect->SetParam(2, y >> FX32_SHIFT);
        effect->SetParam(0x1B, (y >> FX32_SHIFT) + 0x40);
        if (type == 19) {
            effect->ov0_021421F0(60, 180, 150);
        } else {
            effect->ov0_021421F0(60, -1, 60);
        }
        return;
    }
    effect->SetParam(2, y >> FX32_SHIFT);
    effect->ov0_021421F0(0, -1, 0);
}

int Debug_GetNormalG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_NORMAL_G);
}

void Debug_SetNormalG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_NORMAL_G, count);
}

int Debug_GetLeafG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_LEAF_G);
}

void Debug_SetLeafG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_LEAF_G, count);
}

int Debug_GetAquaG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_AQUA_G);
}

void Debug_SetAquaG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_AQUA_G, count);
}

int Debug_GetRockG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_ROCK_G);
}

void Debug_SetRockG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_ROCK_G, count);
}

int Debug_GetInsectG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_INSECT_G);
}

void Debug_SetInsectG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_INSECT_G, count);
}

int Debug_GetAirG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_AIR_G);
}

void Debug_SetAirG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_AIR_G, count);
}

int Debug_GetFireG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_FIRE_G);
}

void Debug_SetFireG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_FIRE_G, count);
}

int Debug_GetFightG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_FIGHT_G);
}

void Debug_SetFightG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_FIGHT_G, count);
}

int Debug_GetLightG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_LIGHT_G);
}

void Debug_SetLightG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_LIGHT_G, count);
}

int Debug_GetCroundG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_GROUND_G);
}

void Debug_SetCroundG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_GROUND_G, count);
}

int Debug_GetMetalG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_METAL_G);
}

void Debug_SetMetalG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_METAL_G, count);
}

int Debug_GetPoisonG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_POISON_G);
}

void Debug_SetPoisonG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_POISON_G, count);
}

int Debug_GetHorrorG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_HORROR_G);
}

void Debug_SetHorrorG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_HORROR_G, count);
}

int Debug_GetPsychoG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_PSYCHO_G);
}

void Debug_SetPsychoG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_PSYCHO_G, count);
}

int Debug_GetDarkG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_DARK_G);
}

void Debug_SetDarkG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_DARK_G, count);
}

int Debug_GetIceG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_ICE_G);
}

void Debug_SetIceG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_ICE_G, count);
}

int Debug_GetDragonG()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_DRAGON_G);
}

void Debug_SetDragonG(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_DRAGON_G, count);
}

int Debug_GetLongLine()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_LONGLINE);
}

void Debug_SetLongLine(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_LONGLINE, count);
}

int Debug_GetChgspd()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_CHGSPD);
}

void Debug_SetChgspd(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_CHGSPD, count);
}

int Debug_GetSuperchg()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_SUPERCHG);
}

void Debug_SetSuperchg(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_SUPERCHG, count);
}

int Debug_GetAssistt()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_ASSISTT);
}

void Debug_SetAssistt(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_ASSISTT, count);
}

int Debug_GetSoko()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_SOKO);
}

void Debug_SetSoko(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_SOKO, count);
}

int Debug_GetCombo()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_COMBO);
}

void Debug_SetCombo(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_COMBO, count);
}

int Debug_GetRecover()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_RECOVER);
}

void Debug_SetRecover(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_RECOVER, count);
}

int Debug_GetPowpls()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_POWPLS);
}

void Debug_SetPowpls(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_POWPLS, count);
}

int Debug_GetEnepls()
{
    return SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_ENEPLS);
}

void Debug_SetEnepls(int count)
{
    SaveData_SetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_ENEPLS, count);
}

int Debug_GetGonbe()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 1) ? 1 : 0;
}

void Debug_SetGonbe(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 1;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~1;
    }
}

int Debug_GetHikozaru()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 2) ? 1 : 0;
}

void Debug_SetHikozaru(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 2;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~2;
    }
}

int Debug_GetPochama()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 4) ? 1 : 0;
}

void Debug_SetPochama(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 4;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~4;
    }
}

int Debug_GetNaetle()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 8) ? 1 : 0;
}

void Debug_SetNaetle(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 8;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~8;
    }
}

int Debug_GetPachirisu()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 0x10) ? 1 : 0;
}

void Debug_SetPachirisu(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 0x10;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~0x10;
    }
}

int Debug_GetYukikaburi()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 0x20) ? 1 : 0;
}

void Debug_SetYukikaburi(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 0x20;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~0x20;
    }
}

int Debug_GetWanriky()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 0x40) ? 1 : 0;
}

void Debug_SetWanriky(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 0x40;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~0x40;
    }
}

int Debug_GetGureggru()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 0x80) ? 1 : 0;
}

void Debug_SetGureggru(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 0x80;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~0x80;
    }
}

int Debug_GetHippopotas()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 0x100) ? 1 : 0;
}

void Debug_SetHippopotas(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 0x100;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~0x100;
    }
}

int Debug_GetMukkuru()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 0x200) ? 1 : 0;
}

void Debug_SetMukkuru(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 0x200;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~0x200;
    }
}

int Debug_GetManene()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 0x400) ? 1 : 0;
}

void Debug_SetManene(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 0x400;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~0x400;
    }
}

int Debug_GetKorobohshi()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 0x800) ? 1 : 0;
}

void Debug_SetKorobohshi(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 0x800;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~0x800;
    }
}

int Debug_GetZugaidos()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 0x1000) ? 1 : 0;
}

void Debug_SetZugaidos(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 0x1000;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~0x1000;
    }
}

int Debug_GetMuma()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 0x2000) ? 1 : 0;
}

void Debug_SetMuma(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 0x2000;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~0x2000;
    }
}

int Debug_GetFukamaru()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 0x4000) ? 1 : 0;
}

void Debug_SetFukamaru(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 0x4000;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~0x4000;
    }
}

int Debug_GetNyula()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 0x8000) ? 1 : 0;
}

void Debug_SetNyula(int on)
{
    // clears the wrong bit (original bug)
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 0x8000;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~1;
    }
}

int Debug_GetTatetopsu()
{
    return (MAIN_BSS_020B26A0.m_partnerFlags & 0x10000) ? 1 : 0;
}

void Debug_SetTatetopsu(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.m_partnerFlags |= 0x10000;
    } else {
        MAIN_BSS_020B26A0.m_partnerFlags &= ~0x10000;
    }
}

void Debug_DoVisitAll(int on)
{
    if (!on) {
        return;
    }
    for (int i = 0; i < 64; i++) {
        if (i >= 0 && i < 64) {
            MAIN_BSS_020B26A0.unk_7F64 |= (u64)1 << i;
        }
    }
}

const char *ov0_0214DD8C()
{
    return ov0_0214B9B0(ov0_0214BACC());
}

int Debug_MAIN_GetQuest()
{
    return MAIN_BSS_020B2638.m_questId;
}

int Debug_GetMission()
{
    return MAIN_BSS_020B2638.m_missionId;
}

const char *ov0_0214DDBC()
{
    TextboxManager *textbox = s_game->m_textboxData;
    const char *kinds[] = { "SYS", "AREA", "CHAP", "QUE", "BAT" };
    OS_SPrintf(sLastMessage, "%s - %d", kinds[textbox->unk_150], textbox->unk_154);
    return sLastMessage;
}

int Debug_Quest_GetQuest()
{
    return sQuestIdx;
}

void Debug_SetQuest(int quest)
{
    sQuestIdx = quest;
}

const char *ov0_0214DE44(int quest)
{
    MissionQuestData *quests = (MissionQuestData *)(void *)&MAIN_BSS_020B2638;
    OS_SPrintf(sQuestListName, "%02d)%s", quest, sQuestStates[GetQuestState(quests, quest)]);
    return sQuestListName;
}

int ov0_0214DEC8()
{
    return 0x3E;
}

int Debug_GetQuestSta()
{
    MissionQuestData *quests = (MissionQuestData *)(void *)&MAIN_BSS_020B2638;
    return GetQuestState(quests, sQuestIdx);
}

void Debug_SetQuestSta(int state)
{
    MissionQuestData *quests = &MAIN_BSS_020B2638;
    switch (state) {
    case 0:
        quests->m_questStates[sQuestIdx] = 0;
        break;
    case 1:
        quests->m_questStates[sQuestIdx] = 1;
        break;
    case 2:
        quests->m_questStates[sQuestIdx] = 0x11;
        break;
    case 3:
        quests->m_questStates[sQuestIdx] = 0x11;
        if (quests->m_questActive == 1) {
            MissionQuestData_ExitQuest(quests);
        }
        MissionQuestData_EnterQuest(quests, sQuestIdx);
        break;
    case 4:
        quests->m_questStates[sQuestIdx] = 0x12;
        break;
    }
}

const char *ov0_0214E000(int state)
{
    OS_SPrintf(sQuestName, "%02d)%s", sQuestIdx, sQuestStates[state]);
    return sQuestName;
}

int ov0_0214E038()
{
    return 5;
}

void Debug_DoQuestOpenAll()
{
    MissionQuestData *quests = &MAIN_BSS_020B2638;
    if (quests->m_questActive == 1) {
        MissionQuestData_ExitQuest(quests);
    }
    for (int i = 0; i < 0x3E; i++) {
        quests->m_questStates[i] = 0x11;
    }
    MissionQuestData_EnterQuest(quests, MATH_Rand32(&CGame::GetInstance()->m_rand32, 0x3D));
}

void Debug_DoQuestCloseAll()
{
    MissionQuestData *quests = &MAIN_BSS_020B2638;
    if (quests->m_questActive == 1) {
        MissionQuestData_ExitQuest(quests);
    }
    for (int i = 0; i < 0x3E; i++) {
        quests->m_questStates[i] = 0;
    }
}

void Debug_DoQuestRandom()
{
    MissionQuestData *quests = &MAIN_BSS_020B2638;
    if (quests->m_questActive == 1) {
        MissionQuestData_ExitQuest(quests);
    }
    u32 current = MATH_Rand32(&CGame::GetInstance()->m_rand32, 0x3D);
    for (int i = 0; i < 0x3E; i++) {
        if (i != current) {
            switch (MATH_Rand32(&CGame::GetInstance()->m_rand32, 4)) {
            case 0:
                quests->m_questStates[i] = 0;
                break;
            case 1:
                quests->m_questStates[i] = 1;
                break;
            case 2:
                quests->m_questStates[i] = 0x11;
                break;
            default:
                quests->m_questStates[i] = 0x12;
                break;
            }
        } else {
            quests->m_questStates[i] = 0x11;
        }
    }
    MissionQuestData_EnterQuest(quests, current);
}

void Debug_DoEventFlags()
{
    OS_SPrintf(sChapterLine, "ChaptNo: %02d", MAIN_BSS_020B2638.m_chapter);
    OS_SPrintf(sMissionLine, "MissSta[%02d]: %d", MAIN_BSS_020B2638.m_missionId, MAIN_BSS_020B2638.m_missionState);
    OS_SPrintf(sQuestLine, "QueSta [%02d]: %d", MAIN_BSS_020B2638.m_questId, MAIN_BSS_020B2638.m_questActive);
    OS_SPrintf(sEventLine0, "e00-07:%02d %02d %02d %02d %02d %02d %02d %02d", GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 0), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 1), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 2), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 3), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 4), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 5), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 6), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 7));
    OS_SPrintf(sEventLine1, "e08-15:%02d %02d %02d %02d %02d %02d %02d %02d", GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 8), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 9), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 10), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 11), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 12), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 13), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 14), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 15));
    OS_SPrintf(sEventLine2, "e16-20:%02d %02d %02d %02d %02d", GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 16), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 17), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 18), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 19), GlobalValues_GetChapterValue(&MAIN_BSS_0210C0B0, 20));
    OS_SPrintf(sStoryLine0, "s00-07:%02d %02d %02d %02d %02d %02d %02d %02d", GlobalValues_Get(&MAIN_BSS_0210C0B0, 0), GlobalValues_Get(&MAIN_BSS_0210C0B0, 1), GlobalValues_Get(&MAIN_BSS_0210C0B0, 2), GlobalValues_Get(&MAIN_BSS_0210C0B0, 3), GlobalValues_Get(&MAIN_BSS_0210C0B0, 4), GlobalValues_Get(&MAIN_BSS_0210C0B0, 5), GlobalValues_Get(&MAIN_BSS_0210C0B0, 6), GlobalValues_Get(&MAIN_BSS_0210C0B0, 7));
    OS_SPrintf(sStoryLine1, "s08-15:%02d %02d %02d %02d %02d %02d %02d %02d", GlobalValues_Get(&MAIN_BSS_0210C0B0, 8), GlobalValues_Get(&MAIN_BSS_0210C0B0, 9), GlobalValues_Get(&MAIN_BSS_0210C0B0, 10), GlobalValues_Get(&MAIN_BSS_0210C0B0, 11), GlobalValues_Get(&MAIN_BSS_0210C0B0, 12), GlobalValues_Get(&MAIN_BSS_0210C0B0, 13), GlobalValues_Get(&MAIN_BSS_0210C0B0, 14), GlobalValues_Get(&MAIN_BSS_0210C0B0, 15));
    OS_SPrintf(sStoryLine2, "s16-19:%02d %02d %02d %02d %02d %02d %02d %02d", GlobalValues_Get(&MAIN_BSS_0210C0B0, 16), GlobalValues_Get(&MAIN_BSS_0210C0B0, 17), GlobalValues_Get(&MAIN_BSS_0210C0B0, 18), GlobalValues_Get(&MAIN_BSS_0210C0B0, 19), GlobalValues_Get(&MAIN_BSS_0210C0B0, 20), GlobalValues_Get(&MAIN_BSS_0210C0B0, 21), GlobalValues_Get(&MAIN_BSS_0210C0B0, 22), GlobalValues_Get(&MAIN_BSS_0210C0B0, 23));
    OS_SPrintf(sStoryLine3, "s20-27:%02d %02d %02d %02d %02d %02d %02d", GlobalValues_Get(&MAIN_BSS_0210C0B0, 24), GlobalValues_Get(&MAIN_BSS_0210C0B0, 25), GlobalValues_Get(&MAIN_BSS_0210C0B0, 26), GlobalValues_Get(&MAIN_BSS_0210C0B0, 27), GlobalValues_Get(&MAIN_BSS_0210C0B0, 28), GlobalValues_Get(&MAIN_BSS_0210C0B0, 29), GlobalValues_Get(&MAIN_BSS_0210C0B0, 30));
    OS_SPrintf(sQuestValueLine0, "q00-07:%02d %02d %02d %02d %02d %02d %02d %02d", GlobalValues_GetQuestValue(&MAIN_BSS_0210C0B0, 0), GlobalValues_GetQuestValue(&MAIN_BSS_0210C0B0, 1), GlobalValues_GetQuestValue(&MAIN_BSS_0210C0B0, 2), GlobalValues_GetQuestValue(&MAIN_BSS_0210C0B0, 3), GlobalValues_GetQuestValue(&MAIN_BSS_0210C0B0, 4), GlobalValues_GetQuestValue(&MAIN_BSS_0210C0B0, 5), GlobalValues_GetQuestValue(&MAIN_BSS_0210C0B0, 6), GlobalValues_GetQuestValue(&MAIN_BSS_0210C0B0, 7));
    OS_SPrintf(sQuestValueLine1, "q08-15:%02d %02d %02d", GlobalValues_GetQuestValue(&MAIN_BSS_0210C0B0, 8), GlobalValues_GetQuestValue(&MAIN_BSS_0210C0B0, 9), GlobalValues_GetQuestValue(&MAIN_BSS_0210C0B0, 10));
}

int Debug_Encyclopedia_GetEncMap()
{
    return sEncMapIdx;
}

int Debug_Encyclopedia_GetEncCapt()
{
    return sEncCaptIdx;
}

int Debug_Encyclopedia_GetEncWord()
{
    return sEncWordIdx;
}

void Debug_Encyclopedia_SetEncMap(int i)
{
    sEncMapIdx = i;
}

void Debug_Encyclopedia_SetEncCapt(int i)
{
    sEncCaptIdx = i;
}

void Debug_Encyclopedia_SetEncWord(int i)
{
    sEncWordIdx = i;
}

int ov0_0214E89C()
{
    return 64;
}

const char *ov0_0214E8A4(int i)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    OS_SPrintf(sEncMapName, "%02d)%s", i, sEncStates[GetEncState(save, 0, i)]);
    return sEncMapName;
}

const char *ov0_0214E918(int i)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    OS_SPrintf(sEncCaptName, "%02d)%s", i, sEncStates[GetEncState(save, 1, i)]);
    return sEncCaptName;
}

const char *ov0_0214E98C(int i)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    OS_SPrintf(sEncWordName, "%02d)%s", i, sEncStates[GetEncState(save, 2, i)]);
    return sEncWordName;
}

void Debug_EncyclopediaMap_SetEncMap(int state)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    int i = sEncMapIdx;
    if (i >= 0 && i < 64 && state >= 0 && state < 3) {
        int shift = (i & 0xF) * 2;
        save->m_encyclopediaStates[0][i / 16] &= ~(3 << shift);
        save->m_encyclopediaStates[0][i / 16] |= (state & 3) << shift;
    }
}

int Debug_EncyclopediaMap_GetEncMap()
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    return GetEncState(save, 0, sEncMapIdx);
}

const char *ov0_0214EACC(int state)
{
    OS_SPrintf(sEncMapStateName, "%02d)%s", sEncMapIdx, sEncStates[state]);
    return sEncMapStateName;
}

void Debug_EncyclopediaCapt_SetEncCapt(int state)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    int i = sEncCaptIdx;
    if (i >= 0 && i < 64 && state >= 0 && state < 3) {
        int shift = (i & 0xF) * 2;
        save->m_encyclopediaStates[1][i / 16] &= ~(3 << shift);
        save->m_encyclopediaStates[1][i / 16] |= (state & 3) << shift;
    }
}

int Debug_EncyclopediaCapt_GetEncCapt()
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    return GetEncState(save, 1, sEncCaptIdx);
}

const char *ov0_0214EBD0(int state)
{
    OS_SPrintf(sEncCaptStateName, "%02d)%s", sEncCaptIdx, sEncStates[state]);
    return sEncCaptStateName;
}

void Debug_EncyclopediaWord_SetEncWord(int state)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    int i = sEncWordIdx;
    if (i >= 0 && i < 64 && state >= 0 && state < 3) {
        int shift = (i & 0xF) * 2;
        save->m_encyclopediaStates[2][i / 16] &= ~(3 << shift);
        save->m_encyclopediaStates[2][i / 16] |= (state & 3) << shift;
    }
}

int Debug_EncyclopediaWord_GetEncWord()
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    return GetEncState(save, 2, sEncWordIdx);
}

const char *ov0_0214ECD4(int state)
{
    OS_SPrintf(sEncWordStateName, "%02d)%s", sEncWordIdx, sEncStates[state]);
    return sEncWordStateName;
}

int ov0_0214ED0C()
{
    return 3;
}

void Debug_DoDispAll()
{
    int group;
    int i;
    SaveData *save = CGame::GetInstance()->unk_14A4;
    for (group = 0; group < 3; group++) {
        for (i = 0; i < 64; i++) {
            if (GetCaptureState(save, group, i) == 0 && group >= 0 && group < 3 && i >= 0 && i < 64) {
                int shift = (i & 0xF) * 2;
                save->m_encyclopediaStates[group][i / 16] &= ~(3 << shift);
                save->m_encyclopediaStates[group][i / 16] |= 1 << shift;
            }
        }
    }
}

void Debug_DoHideAll()
{
    int group;
    int i;
    SaveData *save = CGame::GetInstance()->unk_14A4;
    for (group = 0; group < 3; group++) {
        for (i = 0; i < 64; i++) {
            if (group >= 0 && group < 3 && i >= 0 && i < 64) {
                int shift = (i & 0xF) * 2;
                save->m_encyclopediaStates[group][i / 16] &= ~(3 << shift);
            }
        }
    }
}

void Debug_DoPartnerMood(int mood)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    switch (mood) {
    case 0:
    case 1:
    case 2:
        for (int i = 0; i < 17; i++) {
            save->m_partnerMoods[i] = mood;
        }
        break;
    }
}

int Debug_GetPlyrDisp()
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        return !(scene->m_hiddenLayers & 1);
    }
    return 1;
}

int Debug_GetPrtyDisp()
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        return !(scene->m_hiddenLayers & 2);
    }
    return 1;
}

int Debug_GetEneDisp()
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        return !(scene->m_hiddenLayers & 4);
    }
    return 1;
}

int Debug_GetNpcDisp()
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        return !(scene->m_hiddenLayers & 8);
    }
    return 1;
}

int Debug_GetObjDisp()
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        return !(scene->m_hiddenLayers & 16);
    }
    return 1;
}

void Debug_SetPlyrDisp(int on)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        if (on) {
            scene->m_hiddenLayers &= ~1;
        } else {
            scene->m_hiddenLayers |= 1;
        }
    }
}

void Debug_SetPrtyDisp(int on)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        if (on) {
            scene->m_hiddenLayers &= ~2;
        } else {
            scene->m_hiddenLayers |= 2;
        }
    }
}

void Debug_SetEneDisp(int on)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        if (on) {
            scene->m_hiddenLayers &= ~4;
        } else {
            scene->m_hiddenLayers |= 4;
        }
    }
}

void Debug_SetNpcDisp(int on)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        if (on) {
            scene->m_hiddenLayers &= ~8;
        } else {
            scene->m_hiddenLayers |= 8;
        }
    }
}

void Debug_SetObjDisp(int on)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        if (on) {
            scene->m_hiddenLayers &= ~16;
        } else {
            scene->m_hiddenLayers |= 16;
        }
    }
}

int ov0_0214F0A4()
{
    return 0;
}

void Debug_SetSetWatchAll(int state)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    for (int i = 0; i < 0x1EE; i++) {
        if (IsBrowserEntry(i)) {
            SetBrowserState(save, i, state);
        }
    }
    if (state == 0) {
        SetBrowserState(save, 399, 2);
    }
}

void Debug_SetSPCapture(int flags)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    SetBrowserState(save, 492, (flags & 1) ? 2 : 0);
    SetBrowserState(save, 483, (flags & 2) ? 2 : 0);
    SetBrowserState(save, 484, (flags & 4) ? 2 : 0);
}

void Debug_SetRegigigas()
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    for (int i = 0; i < 0x1EE; i++) {
        if (i != 486 && i != 492 && i != 483 && i != 484 && IsBrowserEntry(i)) {
            SetBrowserState(save, i, 2);
        } else {
            SetBrowserState(save, i, 0);
        }
    }
}

int Debug_GetTotalExp()
{
    return MAIN_BSS_020B26A0.m_exp;
}

void Debug_SetTotalExp(int value)
{
    SaveData_SetExp(&MAIN_BSS_020B26A0, value);
}

int Debug_GetWalkStep()
{
    return MAIN_BSS_020B26A0.m_stepsWalked;
}

void Debug_SetWalkStep(int value)
{
    SaveData_SetStepsWalked(&MAIN_BSS_020B26A0, value);
}

int Debug_GetTalkCnt()
{
    return MAIN_BSS_020B26A0.m_conversations;
}

void Debug_SetTalkCnt(int value)
{
    SaveData_SetConversations(&MAIN_BSS_020B26A0, value);
}

int Debug_GetLookCnt()
{
    return MAIN_BSS_020B26A0.m_targetsChecked;
}

void Debug_SetLookCnt(int value)
{
    SaveData_SetTargetsChecked(&MAIN_BSS_020B26A0, value);
}

int Debug_GetSaveCnt()
{
    return MAIN_BSS_020B26A0.m_saveCount;
}

void Debug_SetSaveCnt(int value)
{
    SaveData_SetSaveCount(&MAIN_BSS_020B26A0, value);
}

int Debug_GetRideCnt()
{
    return MAIN_BSS_020B26A0.m_pokemonRides;
}

void Debug_SetRideCnt(int value)
{
    SaveData_SetPokemonRides(&MAIN_BSS_020B26A0, value);
}

int Debug_RangerRecord_GetPtAssCnt()
{
    return sAssistIdx;
}

void Debug_RangerRecord_SetPtAssCnt(int index)
{
    sAssistIdx = index;
}

const char *ov0_0214F488(int index)
{
    switch (index) {
    case 0:
        OS_SPrintf(sAssistName, "GONB:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 1:
        OS_SPrintf(sAssistName, "HIKO:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 2:
        OS_SPrintf(sAssistName, "POCH:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 3:
        OS_SPrintf(sAssistName, "NAET:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 4:
        OS_SPrintf(sAssistName, "PACH:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 5:
        OS_SPrintf(sAssistName, "YUKI:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 6:
        OS_SPrintf(sAssistName, "WANR:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 7:
        OS_SPrintf(sAssistName, "GURE:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 8:
        OS_SPrintf(sAssistName, "HIPP:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 9:
        OS_SPrintf(sAssistName, "MUKK:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 10:
        OS_SPrintf(sAssistName, "MANE:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 11:
        OS_SPrintf(sAssistName, "KORO:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 12:
        OS_SPrintf(sAssistName, "ZUGA:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 13:
        OS_SPrintf(sAssistName, "MUMA:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 14:
        OS_SPrintf(sAssistName, "FUKA:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 15:
        OS_SPrintf(sAssistName, "NYUL:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    case 16:
        OS_SPrintf(sAssistName, "TATE:%d", MAIN_BSS_020B26A0.m_partnerCounts[index]);
        break;
    default:
        OS_SPrintf(sAssistName, "ERROR(%d)", index);
        break;
    }
    return sAssistName;
}

int ov0_0214F6DC()
{
    return 17;
}

u32 Debug_GetLineLeng()
{
    return MAIN_BSS_020B26A0.m_captureLineLength * 33 / 480;
}

void Debug_SetLineLeng(int value)
{
    SaveData_SetCaptureLineLength(&MAIN_BSS_020B26A0, value * 1584 / 10);
}

int Debug_GetEnclsCnt()
{
    return MAIN_BSS_020B26A0.m_loopCount;
}

void Debug_SetEnclsCnt(int value)
{
    SaveData_SetLoopCount(&MAIN_BSS_020B26A0, value);
}

int Debug_GetCaptCnt()
{
    return MAIN_BSS_020B26A0.m_totalCaptures;
}

void Debug_SetCaptCnt(int value)
{
    SaveData_SetTotalCaptures(&MAIN_BSS_020B26A0, value);
}

int Debug_GetEscpCnt()
{
    return MAIN_BSS_020B26A0.m_fledCount;
}

void Debug_SetEscpCnt(int value)
{
    SaveData_SetFledCount(&MAIN_BSS_020B26A0, value);
}

int Debug_GetAssCnt()
{
    return MAIN_BSS_020B26A0.m_assistsUsed;
}

void Debug_SetAssCnt(int value)
{
    SaveData_SetAssistsUsed(&MAIN_BSS_020B26A0, value);
}

int Debug_GetPlyTime()
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (MAIN_BSS_020B26A0.unk_87DA != 0) {
        return 359999;
    }
    return save->m_playHours * 3600 + save->m_playMinutes * 60 + save->m_playSeconds;
}

void Debug_SetPlyTime(int seconds)
{
    SaveData_SetPlayTime(&MAIN_BSS_020B26A0, seconds / 3600, (seconds % 3600) / 60, seconds % 60);
    RTCTime time;
    RTCDate date;
    RTC_GetTime(&time);
    RTC_GetDate(&date);
    MAIN_BSS_020B26A0.m_lastTime = time;
    MAIN_BSS_020B26A0.m_lastDate = date;
}

const char *ov0_0214F904(int seconds)
{
    OS_SPrintf(sPlayTime, "%02d:%02d:%02d", seconds / 3600, (seconds % 3600) / 60, seconds % 60);
    return sPlayTime;
}

int ov0_0214F990()
{
    return 359999;
}

int Debug_PartnerAssistCount_GetPtAssCnt()
{
    return MAIN_BSS_020B26A0.m_partnerCounts[sAssistIdx];
}

void Debug_PartnerAssistCount_SetPtAssCnt(int value)
{
    SaveData_SetPartnerCount(&MAIN_BSS_020B26A0, sAssistIdx, value);
}

} // extern "C"

DebugMenuItem sCustom2Items[] = {
    { "CHGSPD", 1, 2, 4, 0, (void *)Debug_GetChgspd, (void *)Debug_SetChgspd, (void *)3, 0 },
    { "SUPERCHG", 1, 2, 4, 0, (void *)Debug_GetSuperchg, (void *)Debug_SetSuperchg, (void *)3, 0 },
    { "ASSISTT", 1, 2, 4, 0, (void *)Debug_GetAssistt, (void *)Debug_SetAssistt, (void *)3, 0 },
    { "SOKO", 1, 2, 4, 0, (void *)Debug_GetSoko, (void *)Debug_SetSoko, (void *)3, 0 },
    { "COMBO", 1, 2, 4, 0, (void *)Debug_GetCombo, (void *)Debug_SetCombo, (void *)3, 0 },
    { "RECOVER", 1, 2, 4, 0, (void *)Debug_GetRecover, (void *)Debug_SetRecover, (void *)3, 0 },
    { "POWPLS", 1, 2, 4, 0, (void *)Debug_GetPowpls, (void *)Debug_SetPowpls, (void *)3, 0 },
    { "ENEPLS", 1, 2, 4, 0, (void *)Debug_GetEnepls, (void *)Debug_SetEnepls, (void *)3, 0 },
};

const char *sManpuNames[] = { "HINT_A(R", "HINT_A(B", "HINT_A(G", "HINT_B", "BIKKURI", "HATENA", "IKARI", "ASE", "KIZUKI", "DOKARIMO", "MOBARIMO", "ARIENAI!", "DARKRIE", "GOKIGEN", "SGOKIGEN" };

DebugMenuItem sEventChapterItems[] = {
    { "ChapJump", 1, 2, 2, 0, (void *)ov0_0214C790, (void *)Debug_SetChapJump, (void *)76, 0 },
};

DebugMenuItem sQuestStatusItems[] = {
    { "QuestSta", 5, 1, 1, 0, (void *)Debug_GetQuestSta, (void *)Debug_SetQuestSta, (void *)ov0_0214E000, (void *)ov0_0214E038 },
};

DebugMenuItem sPartnerList0Items[] = {
    { "Nyula", 3, 2, 4, 0, (void *)Debug_GetNyula, (void *)Debug_SetNyula, 0, 0 },
    { "Pachirisu", 3, 2, 4, 0, (void *)Debug_GetPachirisu, (void *)Debug_SetPachirisu, 0, 0 },
    { "Mukkuru", 3, 2, 4, 0, (void *)Debug_GetMukkuru, (void *)Debug_SetMukkuru, 0, 0 },
    { "Zugaidos", 3, 2, 4, 0, (void *)Debug_GetZugaidos, (void *)Debug_SetZugaidos, 0, 0 },
    { "Muma", 3, 2, 4, 0, (void *)Debug_GetMuma, (void *)Debug_SetMuma, 0, 0 },
    { "Korobohshi", 3, 2, 4, 0, (void *)Debug_GetKorobohshi, (void *)Debug_SetKorobohshi, 0, 0 },
    { "Tatetopsu", 3, 2, 4, 0, (void *)Debug_GetTatetopsu, (void *)Debug_SetTatetopsu, 0, 0 },
    { "Gonbe", 3, 2, 4, 0, (void *)Debug_GetGonbe, (void *)Debug_SetGonbe, 0, 0 },
    { "Wanriky", 3, 2, 4, 0, (void *)Debug_GetWanriky, (void *)Debug_SetWanriky, 0, 0 },
};

DebugMenuItem sFieldEffectItems[] = {
    { "SetWeather", 0, 0, 1, 12, 0, 0, 0, 0 },
    { "FogParam", 0, 0, 1, 13, 0, 0, 0, 0 },
    { "FootStep", 4, 2, 3, 0, (void *)Debug_GetFootStep, (void *)Debug_SetFootStep, (void *)sFootStepNames, (void *)5 },
    { "MANPU", 4, 2, 3, 0, (void *)Debug_GetManpu, (void *)Debug_SetManpu, (void *)sManpuNames, (void *)15 },
    { "TestEff", 4, 1, 3, 0, (void *)Debug_GetTestEff, (void *)Debug_SetTestEff, (void *)sTestEffectNames, (void *)20 },
};

const char *sFootStepNames[] = { "NONE", "MUDDY", "SNOW", "GRASS", "WATER" };

const char *sMoodNames[] = { "NORMAL", "GOOD", "VERYGOOD" };

DebugMenuItem sRangerRecordItems[] = {
    { "TotalExp", 8, 2, 4, 0, (void *)Debug_GetTotalExp, (void *)Debug_SetTotalExp, (void *)9999999, 0 },
    { "WalkStep", 8, 2, 4, 0, (void *)Debug_GetWalkStep, (void *)Debug_SetWalkStep, (void *)9999999, 0 },
    { "TalkCnt", 1, 2, 4, 0, (void *)Debug_GetTalkCnt, (void *)Debug_SetTalkCnt, (void *)99999, 0 },
    { "LookCnt", 1, 2, 4, 0, (void *)Debug_GetLookCnt, (void *)Debug_SetLookCnt, (void *)99999, 0 },
    { "SaveCnt", 1, 2, 4, 0, (void *)Debug_GetSaveCnt, (void *)Debug_SetSaveCnt, (void *)99999, 0 },
    { "RideCnt", 1, 2, 4, 0, (void *)Debug_GetRideCnt, (void *)Debug_SetRideCnt, (void *)99999, 0 },
    { "PtAssCnt", 5, 0, 1, 30, (void *)Debug_RangerRecord_GetPtAssCnt, (void *)Debug_RangerRecord_SetPtAssCnt, (void *)ov0_0214F488, (void *)ov0_0214F6DC },
    { "LineLeng", 7, 2, 4, 0, (void *)Debug_GetLineLeng, (void *)Debug_SetLineLeng, (void *)14545440, 0 },
    { "EnclsCnt", 7, 2, 4, 0, (void *)Debug_GetEnclsCnt, (void *)Debug_SetEnclsCnt, (void *)999999, 0 },
    { "CaptCnt", 1, 2, 4, 0, (void *)Debug_GetCaptCnt, (void *)Debug_SetCaptCnt, (void *)9999, 0 },
    { "EscpCnt", 1, 2, 4, 0, (void *)Debug_GetEscpCnt, (void *)Debug_SetEscpCnt, (void *)9999, 0 },
    { "AssCnt", 1, 2, 4, 0, (void *)Debug_GetAssCnt, (void *)Debug_SetAssCnt, (void *)9999, 0 },
    { "PlyTime", 5, 2, 4, 0, (void *)Debug_GetPlyTime, (void *)Debug_SetPlyTime, (void *)ov0_0214F904, (void *)ov0_0214F990 },
};

DebugMenuItem sMAINItems[] = {
    { "Map", 5, 0, 3, 1, 0, 0, (void *)ov0_0214DD8C, 0 },
    { "Event(Chap", 6, 0, 3, 5, (void *)ov0_0214C790, 0, 0, 0 },
    { "Quest", 6, 0, 3, 32, (void *)Debug_MAIN_GetQuest, 0, 0, 0 },
    { "Mission", 6, 0, 3, 32, (void *)Debug_GetMission, 0, 0, 0 },
    { "LastMes", 5, 2, 0, 0, 0, 0, (void *)ov0_0214DDBC, 0 },
    { "Player", 0, 0, 3, 3, 0, 0, 0, 0 },
    { "DEBPRIM", 4, 2, 3, 0, (void *)Debug_GetDebprim, (void *)Debug_SetDebprim, (void *)sDebugPrimNames, (void *)3 },
    { "DbgInfo", 0, 0, 3, 9, 0, 0, 0, 0 },
    { "SetActor", 0, 0, 3, 10, 0, 0, 0, 0 },
    { "FieldEffect", 0, 0, 3, 11, 0, 0, 0, 0 },
    { "Encyclopedia", 0, 0, 3, 22, 0, 0, 0, 0 },
    { "ActorDisp", 0, 0, 3, 27, 0, 0, 0, 0 },
    { "Browser", 0, 0, 3, 28, 0, 0, 0, 0 },
    { "RangerRecord", 0, 0, 3, 29, 0, 0, 0, 0 },
    { "GAMEEND", 2, 3, 3, 0, 0, (void *)Debug_DoGameend, 0, 0 },
};

int sManpuTypes[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 14, 10, 11 };

DebugMenuItem sEventFlagsItems[] = {
    { sChapterLine, 0, 1, 2, 0, 0, 0, 0, 0 },
    { sMissionLine, 0, 1, 2, 0, 0, 0, 0, 0 },
    { sQuestLine, 0, 1, 2, 0, 0, 0, 0, 0 },
    { "", 0, 1, 2, 0, 0, 0, 0, 0 },
    { sEventLine0, 0, 1, 2, 0, 0, 0, 0, 0 },
    { sEventLine1, 0, 1, 2, 0, 0, 0, 0, 0 },
    { sEventLine2, 0, 1, 2, 0, 0, 0, 0, 0 },
    { "", 0, 1, 2, 0, 0, 0, 0, 0 },
    { sStoryLine0, 0, 1, 2, 0, 0, 0, 0, 0 },
    { sStoryLine1, 0, 1, 2, 0, 0, 0, 0, 0 },
    { sStoryLine2, 0, 1, 2, 0, 0, 0, 0, 0 },
    { sStoryLine3, 0, 1, 2, 0, 0, 0, 0, 0 },
    { "", 0, 1, 2, 0, 0, 0, 0, 0 },
    { sQuestValueLine0, 0, 1, 2, 0, 0, 0, 0, 0 },
    { sQuestValueLine1, 0, 1, 2, 0, 0, 0, 0, 0 },
};

DebugMenuItem sCustom0Items[] = {
    { "NORMAL_G", 1, 2, 4, 0, (void *)Debug_GetNormalG, (void *)Debug_SetNormalG, (void *)3, 0 },
    { "LEAF_G", 1, 2, 4, 0, (void *)Debug_GetLeafG, (void *)Debug_SetLeafG, (void *)3, 0 },
    { "AQUA_G", 1, 2, 4, 0, (void *)Debug_GetAquaG, (void *)Debug_SetAquaG, (void *)3, 0 },
    { "ROCK_G", 1, 2, 4, 0, (void *)Debug_GetRockG, (void *)Debug_SetRockG, (void *)3, 0 },
    { "INSECT_G", 1, 2, 4, 0, (void *)Debug_GetInsectG, (void *)Debug_SetInsectG, (void *)3, 0 },
    { "AIR_G", 1, 2, 4, 0, (void *)Debug_GetAirG, (void *)Debug_SetAirG, (void *)3, 0 },
    { "FIRE_G", 1, 2, 4, 0, (void *)Debug_GetFireG, (void *)Debug_SetFireG, (void *)3, 0 },
    { "FIGHT_G", 1, 2, 4, 0, (void *)Debug_GetFightG, (void *)Debug_SetFightG, (void *)3, 0 },
    { "LIGHT_G", 1, 2, 4, 0, (void *)Debug_GetLightG, (void *)Debug_SetLightG, (void *)3, 0 },
};

DebugMenuItem sEventItems[] = {
    { "Chapter", 0, 0, 0, 6, 0, 0, 0, 0 },
    { "EventFlags", 0, 0, 1, 31, 0, (void *)Debug_DoEventFlags, 0, 0 },
};

DebugMenuItem sPartnerMoodItems[] = {
    { "PartnerMood", 4, 2, 4, 0, 0, (void *)Debug_DoPartnerMood, (void *)sMoodNames, (void *)3 },
};

const char *sSexNames[] = { "MALE", "FEMALE" };

const char *sWatchNames[] = { "NONE", "LOOK", "CAPTURE" };

DebugMenuItem sBrowserItems[] = {
    { "SetWatchAll", 4, 1, 3, 0, (void *)ov0_0214F0A4, (void *)Debug_SetSetWatchAll, (void *)sWatchNames, (void *)3 },
    { "SPCapture", 4, 1, 3, 0, (void *)ov0_0214F0A4, (void *)Debug_SetSPCapture, (void *)sCaptureNames, (void *)8 },
    { "Regigigas", 0, 0, 1, 0, (void *)ov0_0214F0A4, (void *)Debug_SetRegigigas, 0, 0 },
};

const char *sEncStates[] = { "CLOSE", "NEW", "OPEN" };

DebugMenuItem sQuestItems[] = {
    { "Quest", 5, 0, 1, 7, (void *)Debug_Quest_GetQuest, (void *)Debug_SetQuest, (void *)ov0_0214DE44, (void *)ov0_0214DEC8 },
    { "Quest OPEN ALL", 0, 2, 8, 0, 0, (void *)Debug_DoQuestOpenAll, 0, 0 },
    { "Quest CLOSE ALL", 0, 2, 8, 0, 0, (void *)Debug_DoQuestCloseAll, 0, 0 },
    { "Quest RANDOM", 0, 2, 8, 0, 0, (void *)Debug_DoQuestRandom, 0, 0 },
};

DebugMenuItem sAddTargetItems[] = {
    { "TargetID", 5, 2, 2, 0, (void *)Debug_GetTargetID, (void *)Debug_SetTargetID, (void *)ov0_0214BB38, (void *)ov0_0214BBCC },
    { "ScriptID", 1, 2, 2, 0, 0, (void *)Debug_DoScriptID, (void *)1000, 0 },
};

DebugMenuItem sCustomPartsItems[] = {
    { "List0", 0, 0, 1, 16, 0, 0, 0, 0 },
    { "List1", 0, 0, 1, 17, 0, 0, 0, 0 },
    { "List2", 0, 0, 1, 18, 0, 0, 0, 0 },
};

DebugMenu sMenus[] = {
    { "MAIN", sMAINItems, 15, 0, 0, 0 },
    { "Map", sMapItems, 6, 1, 0, 0 },
    { "MapJump", sMapJumpItems, 1, 2, 0, 0 },
    { "Player", sPlayerItems, 11, 1, 0, 0 },
    { "PlayerMove", sPlayerMoveItems, 2, 1, 0, 0 },
    { "Event", sEventItems, 2, 0, 0, 0 },
    { "EventChapter", sEventChapterItems, 1, 2, 0, 0 },
    { "QuestStatus", sQuestStatusItems, 1, 0, 0, 0 },
    { "AddParty", sAddPartyItems, 1, 1, 0, 0 },
    { "DebugInfo", sDebugInfoItems, 4, 0, 0, 0 },
    { "SetActor", sSetActorItems, 4, 0, 0, 0 },
    { "FieldEffect", sFieldEffectItems, 5, 0, 0, 0 },
    { "SetWeather", sSetWeatherItems, 1, 1, 0, 0 },
    { "FogColor", sFogColorItems, 4, 1, 0, 0 },
    { "AddTarget", sAddTargetItems, 2, 1, 0, 0 },
    { "CustomParts", sCustomPartsItems, 3, 0, 0, 0 },
    { "Custom0", sCustom0Items, 9, 0, 0, 0 },
    { "Custom1", sCustom1Items, 9, 0, 0, 0 },
    { "Custom2", sCustom2Items, 8, 0, 0, 0 },
    { "PartnerGetFlag", sPartnerGetFlagItems, 2, 1, 0, 0 },
    { "PartnerList0", sPartnerList0Items, 9, 2, 0, 0 },
    { "PartnerList1", sPartnerList1Items, 8, 2, 0, 0 },
    { "Encyclopedia", sEncyclopediaItems, 5, 0, 0, 0 },
    { "EncyclopediaMap", sEncyclopediaMapItems, 1, 0, 0, 0 },
    { "EncyclopediaCapt", sEncyclopediaCaptItems, 1, 0, 0, 0 },
    { "EncyclopediaWord", sEncyclopediaWordItems, 1, 0, 0, 0 },
    { "PartnerMood", sPartnerMoodItems, 1, 1, 0, 0 },
    { "ActorDisp", sActorDispItems, 6, 0, 0, 0 },
    { "Browser", sBrowserItems, 3, 0, 0, 0 },
    { "RangerRecord", sRangerRecordItems, 13, 0, 0, 0 },
    { "PartnerAssistCount", sPartnerAssistCountItems, 1, 0, 0, 0 },
    { "EventFlags", sEventFlagsItems, 15, 0, 0, 0 },
    { "Quest", sQuestItems, 4, 0, 0, 0 },
};

DebugMenuItem sAddPartyItems[] = {
    { "PokeAdd", 5, 2, 2, 0, (void *)Debug_GetPokeAdd, (void *)Debug_SetPokeAdd, (void *)ov0_0214C4A0, (void *)ov0_0214C540 },
};

DebugMenuItem sPartnerList1Items[] = {
    { "Naetle", 3, 2, 4, 0, (void *)Debug_GetNaetle, (void *)Debug_SetNaetle, 0, 0 },
    { "Hikozaru", 3, 2, 4, 0, (void *)Debug_GetHikozaru, (void *)Debug_SetHikozaru, 0, 0 },
    { "Gureggru", 3, 2, 4, 0, (void *)Debug_GetGureggru, (void *)Debug_SetGureggru, 0, 0 },
    { "Yukikaburi", 3, 2, 4, 0, (void *)Debug_GetYukikaburi, (void *)Debug_SetYukikaburi, 0, 0 },
    { "Manene", 3, 2, 4, 0, (void *)Debug_GetManene, (void *)Debug_SetManene, 0, 0 },
    { "Hippopotas", 3, 2, 4, 0, (void *)Debug_GetHippopotas, (void *)Debug_SetHippopotas, 0, 0 },
    { "Fukamaru", 3, 2, 4, 0, (void *)Debug_GetFukamaru, (void *)Debug_SetFukamaru, 0, 0 },
    { "Pochama", 3, 2, 4, 0, (void *)Debug_GetPochama, (void *)Debug_SetPochama, 0, 0 },
};

DebugMenuItem sDebugInfoItems[] = {
    { "TexVramInfo", 0, 1, 1, 0, 0, (void *)ov0_0214C900, 0, 0 },
    { "PlttVramInfo", 0, 1, 1, 0, 0, (void *)Debug_DoPlttVramInfo, 0, 0 },
    { "UpperDbgInfo", 0, 1, 1, 0, 0, (void *)Debug_DoUpperDbgInfo, 0, 0 },
    { "ProcLoad", 3, 2, 3, 0, (void *)Debug_GetProcLoad, (void *)Debug_SetProcLoad, 0, 0 },
};

DebugMenuItem sEncyclopediaMapItems[] = {
    { "EncMap", 5, 1, 4, 0, (void *)Debug_EncyclopediaMap_GetEncMap, (void *)Debug_EncyclopediaMap_SetEncMap, (void *)ov0_0214EACC, (void *)ov0_0214ED0C },
};

DebugMenuItem sMapItems[] = {
    { "MapID", 5, 0, 0, 2, (void *)ov0_0214BACC, 0, (void *)ov0_0214B9B0, 0 },
    { "CollFree", 3, 2, 2, 0, (void *)Debug_GetCollFree, (void *)Debug_SetCollFree, 0, 0 },
    { "EncFree", 3, 2, 3, 0, (void *)Debug_GetEncFree, (void *)Debug_SetEncFree, 0, 0 },
    { "EvArea", 3, 2, 3, 0, (void *)Debug_GetEvArea, (void *)Debug_SetEvArea, 0, 0 },
    { "AddTarget", 0, 0, 0, 14, 0, 0, 0, 0 },
    { "VisitAll", 3, 2, 3, 0, 0, (void *)Debug_DoVisitAll, 0, 0 },
};

DebugMenuItem sPlayerMoveItems[] = {
    { "POSX", 1, 2, 4, 0, (void *)Debug_GetPosx, (void *)Debug_SetPosx, (void *)2048, 0 },
    { "POSY", 1, 2, 4, 0, (void *)Debug_GetPosy, (void *)Debug_SetPosy, (void *)2048, 0 },
};

DebugMenuItem sEncyclopediaCaptItems[] = {
    { "EncCapt", 5, 1, 4, 0, (void *)Debug_EncyclopediaCapt_GetEncCapt, (void *)Debug_EncyclopediaCapt_SetEncCapt, (void *)ov0_0214EBD0, (void *)ov0_0214ED0C },
};

DebugMenuItem sFogColorItems[] = {
    { "R", 1, 1, 4, 0, (void *)Debug_GetR, (void *)Debug_SetR, (void *)31, 0 },
    { "G", 1, 1, 4, 0, (void *)Debug_GetG, (void *)Debug_SetG, (void *)31, 0 },
    { "B", 1, 1, 4, 0, (void *)Debug_GetB, (void *)Debug_SetB, (void *)31, 0 },
    { "A", 1, 1, 4, 0, (void *)Debug_GetA, (void *)Debug_SetA, (void *)31, 0 },
};

const char *sCaptureNames[] = { "XXX", "1XX", "X2X", "12X", "XX3", "1X3", "X23", "123" };

const char *sQuestStates[] = { "CLOSE", "NEW", "OPEN", "ACCEPT", "CLEAR" };

DebugMenuItem sActorDispItems[] = {
    { "PlyrDisp", 3, 2, 4, 0, (void *)Debug_GetPlyrDisp, (void *)Debug_SetPlyrDisp, 0, 0 },
    { "PrtyDisp", 3, 2, 4, 0, (void *)Debug_GetPrtyDisp, (void *)Debug_SetPrtyDisp, 0, 0 },
    { "EneDisp", 3, 2, 4, 0, (void *)Debug_GetEneDisp, (void *)Debug_SetEneDisp, 0, 0 },
    { "NpcDisp", 3, 2, 4, 0, (void *)Debug_GetNpcDisp, (void *)Debug_SetNpcDisp, 0, 0 },
    { "ObjDisp", 3, 2, 4, 0, (void *)Debug_GetObjDisp, (void *)Debug_SetObjDisp, 0, 0 },
    { "HPDisp", 3, 2, 4, 0, (void *)ov0_0214C010, (void *)ov0_0214C040, 0, 0 },
};

DebugMenuItem sPlayerItems[] = {
    { "PlyrHP", 1, 2, 4, 0, (void *)Debug_GetPlyrHP, (void *)Debug_SetPlyrHP, (void *)128, 0 },
    { "PlyrLvl", 1, 2, 4, 0, (void *)Debug_GetPlyrLvl, (void *)Debug_SetPlyrLvl, (void *)128, 0 },
    { "RangCls", 1, 2, 3, 0, (void *)Debug_GetRangCls, (void *)Debug_SetRangCls, (void *)10, 0 },
    { "RangGrd", 1, 2, 3, 0, (void *)Debug_GetRangGrd, (void *)Debug_SetRangGrd, (void *)2, 0 },
    { "PlyrSex", 4, 2, 3, 0, (void *)Debug_GetPlyrSex, (void *)Debug_SetPlyrSex, (void *)sSexNames, (void *)2 },
    { "PlyrMove", 0, 0, 3, 4, 0, 0, 0, 0 },
    { "PokeAdd", 0, 0, 3, 8, 0, 0, 0, 0 },
    { "Custom", 0, 0, 3, 15, 0, 0, 0, 0 },
    { "PartnerGetFlag", 0, 0, 3, 19, 0, 0, 0, 0 },
    { "HPGauge", 3, 2, 3, 0, (void *)ov0_0214C010, (void *)ov0_0214C040, 0, 0 },
    { "PartnerMood", 0, 0, 3, 26, 0, 0, 0, 0 },
};

const char *sTestEffectNames[] = { "BLOOM1", "BLOOM2", "BLOOM3", "DARKFOG1", "DARKFOG2", "DARKFOG3", "SHADOW1", "SHADOW2", "HANABI1", "HANABI2", "CLEAR1", "CLEAR2", "CLEAR3", "CLEAR4", "GLITTER", "B-STONE", "B-STONE2", "FLOWER", "CREVICE1", "CREVICE2" };

DebugMenuItem sSetWeatherItems[] = {
    { "Weather", 1, 2, 2, 0, (void *)Debug_GetWeather, (void *)Debug_SetWeather, (void *)16, 0 },
};

DebugMenuItem sSetActorItems[] = {
    { "Poke:", 0, 2, 1, 0, 0, (void *)ov0_0214C900, 0, 0 },
    { "put field", 4, 2, 1, 0, 0, (void *)ov0_0214C900, (void *)sPutFieldNames, (void *)3 },
    { "put party", 0, 2, 1, 0, 0, (void *)ov0_0214C900, 0, 0 },
    { "view party", 0, 2, 8, 0, 0, (void *)Debug_DoViewParty, 0, 0 },
};

DebugMenuItem sEncyclopediaItems[] = {
    { "EncMap", 5, 0, 1, 23, (void *)Debug_Encyclopedia_GetEncMap, (void *)Debug_Encyclopedia_SetEncMap, (void *)ov0_0214E8A4, (void *)ov0_0214E89C },
    { "EncCapt", 5, 0, 1, 24, (void *)Debug_Encyclopedia_GetEncCapt, (void *)Debug_Encyclopedia_SetEncCapt, (void *)ov0_0214E918, (void *)ov0_0214E89C },
    { "EncWord", 5, 0, 1, 25, (void *)Debug_Encyclopedia_GetEncWord, (void *)Debug_Encyclopedia_SetEncWord, (void *)ov0_0214E98C, (void *)ov0_0214E89C },
    { "Disp ALL", 0, 2, 1, 0, 0, (void *)Debug_DoDispAll, 0, 0 },
    { "Hide ALL", 0, 2, 1, 0, 0, (void *)Debug_DoHideAll, 0, 0 },
};

DebugMenuItem sCustom1Items[] = {
    { "CROUND_G", 1, 2, 4, 0, (void *)Debug_GetCroundG, (void *)Debug_SetCroundG, (void *)3, 0 },
    { "METAL_G", 1, 2, 4, 0, (void *)Debug_GetMetalG, (void *)Debug_SetMetalG, (void *)3, 0 },
    { "POISON_G", 1, 2, 4, 0, (void *)Debug_GetPoisonG, (void *)Debug_SetPoisonG, (void *)3, 0 },
    { "HORROR_G", 1, 2, 4, 0, (void *)Debug_GetHorrorG, (void *)Debug_SetHorrorG, (void *)3, 0 },
    { "PSYCHO_G", 1, 2, 4, 0, (void *)Debug_GetPsychoG, (void *)Debug_SetPsychoG, (void *)3, 0 },
    { "DARK_G", 1, 2, 4, 0, (void *)Debug_GetDarkG, (void *)Debug_SetDarkG, (void *)3, 0 },
    { "ICE_G", 1, 2, 4, 0, (void *)Debug_GetIceG, (void *)Debug_SetIceG, (void *)3, 0 },
    { "DRAGON_G", 1, 2, 4, 0, (void *)Debug_GetDragonG, (void *)Debug_SetDragonG, (void *)3, 0 },
    { "LongLine", 1, 2, 4, 0, (void *)Debug_GetLongLine, (void *)Debug_SetLongLine, (void *)3, 0 },
};

DebugMenuItem sPartnerAssistCountItems[] = {
    { "PtAssCnt", 8, 1, 4, 0, (void *)Debug_PartnerAssistCount_GetPtAssCnt, (void *)Debug_PartnerAssistCount_SetPtAssCnt, (void *)9999999, 0 },
};

const char *sPutFieldNames[] = { "(none)", "(hide)", "(fall)" };

DebugMenuItem sEncyclopediaWordItems[] = {
    { "EncWord", 5, 1, 4, 0, (void *)Debug_EncyclopediaWord_GetEncWord, (void *)Debug_EncyclopediaWord_SetEncWord, (void *)ov0_0214ECD4, (void *)ov0_0214ED0C },
};

DebugMenuItem sMapJumpItems[] = {
    { "MapJump", 5, 3, 3, 0, (void *)ov0_0214BACC, (void *)Debug_SetMapJump, (void *)ov0_0214B9B0, (void *)ov0_0214BAAC },
};

DebugMenuItem sPartnerGetFlagItems[] = {
    { "m_008_006", 0, 0, 3, 20, 0, 0, 0, 0 },
    { "m_008_008", 0, 0, 3, 21, 0, 0, 0, 0 },
};

const char *sDebugPrimNames[] = { "OFF", "Collision", "TouchRect" };

FieldDebugMenu::FieldDebugMenu(CGame *game)
{
    MAIN_BSS_0210CA80 = this;
    m_game = game;
    unk_04 = new DebugProcessManager(game->GetPrinter(), (u32)game->unk_0014);
    unk_08 = NULL;
    unk_0C = NULL;
    unk_10 = 0;
    ov0_0214FA94(sMenus, sizeof(sMenus) / sizeof(sMenus[0]));
}

FieldDebugMenu::~FieldDebugMenu()
{
    unk_04->CloseAll();
    SAFE_DELETE(unk_04);
    MAIN_BSS_0210CA80 = NULL;
}

void FieldDebugMenu::ov0_0214FA94(DebugMenu *menus, int count)
{
    unk_0C = menus;
    unk_10 = count;
}

void FieldDebugMenu::ov0_0214FAA0()
{
    unk_04->SetValue(0, 0);
    unk_08 = unk_0C;
    for (int i = 0; i < unk_10; i++) {
        unk_0C[i].unk_10 = 0;
        unk_0C[i].unk_14 = 0;
    }
}

void FieldDebugMenu::ov0_0214FB08()
{
    unk_04->Update();
}

BOOL FieldDebugMenu::ov0_0214FB18()
{
    return unk_04->IsActive();
}
