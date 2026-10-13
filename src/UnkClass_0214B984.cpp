// Field debug menu: variable accessors and the menu tables (the retail game has no menu interpreter left)
//
// TODO(revisit after overlay 0 is finished): FAKE data order. The tables' strings, arrays and .bss statics all go
// through mwcc's size heapsort, and no natural source order reproduces the original layout (the original most likely
// had dead static tables that left no trace). sUnusedNames below and the declaration order of the .bss statics and
// tables were computed to match (~/scratch/ov0/fb984/construct2.py, NOTES.md there); find the real source order.

#include "UnkClass_0214B984.hpp"

#include <nitro.h>
#include <string.h>

#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "UnkClass_02008E88.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0201164C.hpp"
#include "UnkClass_02018DF4.hpp"
#include "UnkClass_02022404.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkClass_020B26A0.hpp"
#include "UnkClass_0211D850.hpp"
#include "UnkClass_0213DDCC.hpp"
#include "UnkClass_0214F9DC.hpp"
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
extern UnkClass_0214F9DC *MAIN_BSS_0210CA80;
extern UnkClass_02041C80 *MAIN_BSS_0210CA6C;
extern UnkClass_020B26A0 MAIN_BSS_020B26A0;
extern CFieldScene *MAIN_BSS_0210CA40;
extern CFieldPlayer *MAIN_BSS_0210CA48;
extern CFieldTargetObjectManage *MAIN_BSS_0210CA7C;
extern CFieldPartnerManage *MAIN_BSS_0210CA4C;
extern UnkClass_0213DDCC *MAIN_BSS_0210CA58;
extern CFieldEffectManage *MAIN_BSS_0210CA60;
extern UnkClass_0211D850 *MAIN_BSS_0210CA78;

extern "C" {
BOOL sub_02015434(UnkClass_020B26A0 *save, int mapId, int idx);
BOOL sub_02015C78(UnkClass_020B26A0 *save, u32 id, int kind, int arg3);
void sub_0201164C(UnkClass_0201164C *missionQuestData, u32 chapter);
void LogInfo(const char *fmt, ...);
void sub_02011540(UnkClass_0201164C *obj, int quest);
void sub_020115F8(UnkClass_0201164C *obj);
void sub_02016C40(UnkClass_020B26A0 *save, int idx, int count);
void sub_02016EF0(UnkClass_020B26A0 *save, int idx, u32 value);
void sub_02018148(UnkClass_020B26A0 *save, u32 hours, u8 minutes, u8 seconds);
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

static inline u32 GetPokemonState(UnkClass_020B26A0 *save, int i)
{
    if (i >= 0 && i < 500) {
        return (save->unk_7C3C[i >> 4] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

static inline void SetPokemonState(UnkClass_020B26A0 *save, int i, u32 state)
{
    int shift = (i & 0xF) * 2;
    save->unk_7C3C[i >> 4] &= ~(3 << shift);
    save->unk_7C3C[i >> 4] |= state << shift;
}

static inline void RaisePokemonState(UnkClass_020B26A0 *save, int i, u32 state)
{
    if (i >= 0 && i < 500) {
        if (GetPokemonState(save, i) < state) {
            SetPokemonState(save, i, state);
        }
    }
}

static inline u32 GetCaptureState(UnkClass_020B26A0 *save, int group, int i)
{
    if (group >= 0 && group < 3 && i >= 0 && i < 64) {
        return (save->unk_7F30[group][i / 16] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

static inline u32 GetEncState(UnkClass_020B26A0 *save, int group, int i)
{
    if (i >= 0 && i < 64) {
        return (save->unk_7F30[group][i / 16] >> ((i & 0xF) * 2)) & 3;
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

static inline void SetBrowserState(UnkClass_020B26A0 *save, int i, u8 state)
{
    if (i >= 0 && i < 500 && state <= 3) {
        int shift = (i & 0xF) * 2;
        save->unk_7C3C[i >> 4] &= ~(3 << shift);
        save->unk_7C3C[i >> 4] |= (state & 3) << shift;
    }
}

static inline int GetQuestState(UnkClass_0201164C *quests, int quest)
{
    int state = 0;
    u8 flags = quests->unk_14[quest];
    switch (flags & 0xF) {
    case 1:
        if (flags & 0x10) {
            if (quests->unk_01 == 1 && quest == quests->unk_03) {
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
        UnkStruct_02041D80 *map = sub_02041D80(MAIN_BSS_0210CA6C, id);
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
    return MAIN_BSS_020B26A0.unk_001A;
}

void ov0_0214BADC(int mapId)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        scene->unk_00D0 |= 2;
        scene->unk_0068 = mapId;
        scene->unk_006C = 0;
        scene->unk_0070 = 0;
        scene->unk_0074 = -1;
    }
}

int ov0_0214BB18()
{
    return sTargetId;
}

void ov0_0214BB28(int id)
{
    sTargetId = id;
}

const char *ov0_0214BB38(int id)
{
    strcpy(sTargetName, "NONE");
    if (id > 0 && MAIN_BSS_0210CA6C != NULL) {
        FieldTargetObjectData *data = sub_02041D6C(MAIN_BSS_0210CA6C, id);
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

void ov0_0214BBEC(int scriptId)
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
    target->sub_0202E68C(player->unk_14);
    target->unk_20 = 2;
}

int ov0_0214BDD0()
{
    int x = 0;
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player != NULL) {
        x = player->GetX() >> FX32_SHIFT;
    }
    return x;
}

void ov0_0214BE08(int x)
{
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player == NULL) {
        return;
    }
    player->SetPosXY(x << FX32_SHIFT, player->GetY());
    player->ov0_021307B0(NULL, NULL, NULL, NULL, 0);
}

int ov0_0214BEB0()
{
    int y = 0;
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player != NULL) {
        y = player->GetY() >> FX32_SHIFT;
    }
    return y;
}

void ov0_0214BEE8(int y)
{
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player == NULL) {
        return;
    }
    player->SetPosXY(player->GetX(), y << FX32_SHIFT);
    player->ov0_021307B0(NULL, NULL, NULL, NULL, 0);
}

void ov0_0214BF94(int on)
{
    if (on && MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->unk_00D0 |= 0x10;
    }
}

int ov0_0214BFB8()
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL && (debug->unk_00 & 1)) {
        // always 0: the bit shifted out (a plain `return 0` lets IRO fold the test away)
        return (debug->unk_00 & 1) >> 1;
    }
    return 0;
}

void ov0_0214BFE4(int on)
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
        return !(scene->unk_00D0 & 0x800);
    }
    return 0;
}

void ov0_0214C040(int on)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        if (on) {
            scene->unk_00D0 &= ~0x800;
        } else {
            scene->unk_00D0 |= 0x800;
        }
    }
}

int ov0_0214C070()
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    return save != NULL ? save->unk_0001 : 0;
}

void ov0_0214C088(int hp)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    save->unk_0001 = hp;
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->unk_00D8->SetCurrentHP(save->unk_0001);
    }
}

int ov0_0214C0C0()
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    return save != NULL ? save->unk_87DB : 0;
}

void ov0_0214C0DC(int level)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    sub_020160B8(save, (u8)level);
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->unk_00D8->SetHP(save->unk_0001, save->unk_0002);
    }
}

int ov0_0214C120()
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    return save != NULL ? save->unk_0003 & 0xF : 0;
}

void ov0_0214C13C(int rank)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    save->unk_0003 = (save->unk_0003 & 0xF0) | (u8)rank;
    UnkClass_02022404 *obj = UnkClass_02022404::GetInstance();
    if (obj != NULL) {
        obj->sub_02022B20();
    }
}

int ov0_0214C170()
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    return save != NULL ? (save->unk_0003 >> 4) & 0xF : 0;
}

void ov0_0214C194(int grade)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    if (((save->unk_0003 >> 4) & 0xF) == (u8)grade) {
        return;
    }
    save->unk_0003 = (save->unk_0003 & 0xF) | ((u8)grade << 4);
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player == NULL) {
        return;
    }
    Point2D pos = player->GetPos();
    player->ov0_02132F14(save->unk_0000, (u8)((save->unk_0003 >> 4) & 0xF), save->unk_8B64);
    player->ov0_02132FA0(save->unk_8802);
    player->SetPos(pos);
}

int ov0_0214C2E8()
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    return save != NULL ? save->unk_0000 : 0;
}

void ov0_0214C300(int sex)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    if (save->unk_0000 == (u8)sex) {
        return;
    }
    save->unk_0000 = (u8)sex & 1;
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player == NULL) {
        return;
    }
    Point2D pos = player->GetPos();
    player->ov0_02132F14(save->unk_0000, (u8)((save->unk_0003 >> 4) & 0xF), save->unk_8B64);
    player->ov0_02132FA0(save->unk_8802);
    player->SetPos(pos);
}

int ov0_0214C448()
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL && (debug->unk_00 & 2)) {
        return 1;
    }
    return 0;
}

void ov0_0214C474(int on)
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
    UnkStruct_020107A8 *info = sub_020107A8(s_game->unk_1434, kind);
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

int ov0_0214C560()
{
    return 0;
}

void ov0_0214C568(int kind)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    u16 slot = 0xFFF;
    for (u16 i = 0; i < 0xFFF; i++) {
        if (!sub_02015434(save, 0xFFF, i)) {
            slot = i;
            break;
        }
    }
    u32 id = (slot & 0xFFF) | 0x1FFF000;
    CFieldPartnerManage *partners;
    if (sub_02015C78(save, id, kind, -1) && (partners = MAIN_BSS_0210CA4C) != NULL) {
        partners->ov0_02139920(id, kind, 0xE, 0, 1);
        sub_0203F440(partners);
        if (sub_02034F9C((u16)kind)) {
            UnkStruct_020155FC *entry = sub_02015520(save, id);
            if (entry != NULL) {
                entry->unk_08 |= 2;
            }
        }
    }
}

int ov0_0214C664()
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL && (debug->unk_00 & 4)) {
        return 1;
    }
    return 0;
}

void ov0_0214C690(int on)
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
        UnkClass_0213DDCC *rects = MAIN_BSS_0210CA58;
        if (rects != NULL) {
            rects->m_draw = on ? TRUE : FALSE;
        }
    }
}

int ov0_0214C6E0()
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL && (debug->unk_00 & 8)) {
        return 1;
    }
    return 0;
}

void ov0_0214C70C(int on)
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

int ov0_0214C738()
{
    UnkClass_0214B984 *debug = MAIN_BSS_0210CA68;
    if (debug != NULL && (debug->unk_00 & 0x10)) {
        return 1;
    }
    return 0;
}

void ov0_0214C764(int on)
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
    return s_game->m_missionQuestData->unk_08;
}

void ov0_0214C7AC(int chapter)
{
    CFieldPartnerManage *partners = MAIN_BSS_0210CA4C;
    UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
    for (int i = 0; i < 2; i++) {
        UnkStruct_020B26A0_8AD4 *partner = MAIN_BSS_020B26A0.GetPartner(i);
        if (partner != NULL && partner->unk_00 != 0) {
            if (partners != NULL) {
                partners->ov0_0213A050(partner->unk_04);
            }
            partner->unk_00 = 0;
        }
    }
    const char *name = s_c000First_0208ac1c[chapter].name;
    if (name != NULL) {
        strcpy(save->unk_8B44, name);
    } else {
        save->unk_8B44[0] = 0;
    }
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        scene->unk_00D0 |= 2;
        scene->unk_0068 = s_c000First_0208ac1c[chapter].mapId;
        scene->unk_006C = s_c000First_0208ac1c[chapter].x;
        scene->unk_0070 = s_c000First_0208ac1c[chapter].y;
        scene->unk_0074 = 0;
    }
    sub_02018E30((UnkClass_02018DF4 *)s_game->unk_14B4);
    sub_02018E94((UnkClass_02018DF4 *)s_game->unk_14B4, chapter);
    sub_0201164C(s_game->m_missionQuestData, chapter);
}

void ov0_0214C900()
{
    NNS_GfdDumpLnkTexVramManager();
}

void ov0_0214C90C()
{
    NNS_GfdDumpLnkPlttVramManager();
}

void ov0_0214C918()
{
    UnkClass_02022404 *obj = UnkClass_02022404::GetInstance();
    if (obj != NULL) {
        obj->sub_02022D04();
    }
}

void ov0_0214C930()
{
    LogInfo("****************************************");
    LogInfo("PartyInfo start");
    LogInfo("****************************************");
    LogInfo("----------");
    LogInfo("commondata");
    LogInfo("----------");
    UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
    LogInfo("----------");
    LogInfo("partnernpc");
    LogInfo("----------");
    LogInfo("----------");
    LogInfo("partnerpoke");
    LogInfo("----------");
    for (int i = 0; i < 10; i++) {
        UnkStruct_020155FC *entry = sub_020155FC(save, i);
        if (entry != NULL && (entry->unk_08 & 1)) {
            LogInfo("*******************************");
            LogInfo("arrryindex= %d", i);
            LogInfo("pokeid= %d", entry->unk_00);
            LogInfo("mapID= %d", entry->unk_02);
            LogInfo("NpcID= %d", entry->unk_04);
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
                LogInfo("id= %d", partner->unk_58);
                LogInfo("typeid= %d", partner->unk_200);
                LogInfo("***************");
            }
        }
    }
    LogInfo("****************************************");
    LogInfo("PartyInfo end");
    LogInfo("****************************************");
}

int ov0_0214CB2C()
{
    return 0;
}

void ov0_0214CB34(int weather)
{
    LogInfo("****************************************");
    LogInfo("Weather Start");
    LogInfo("****************************************");
    UnkClass_0211D850 *control = MAIN_BSS_0210CA78;
    control->sub_020359FC();
    control->sub_02035D38(weather);
    control->sub_02035DA0(weather, 120, -1, 0);
    if (weather != 0) {
        return;
    }
    ov0_0214C13C(10);
    ov0_0214C568(218);
    ov0_0214C568(30);
    ov0_0214C568(29);
    ov0_0214C568(20);
    ov0_0214C568(198);
    ov0_0214C568(38);
    ov0_0214C568(38);
    for (int i = 0; i < 500; i++) {
        RaisePokemonState(&MAIN_BSS_020B26A0, i, 1);
    }
}

int ov0_0214CC8C()
{
    return CFieldSEFFog::GetDensity();
}

void ov0_0214CC9C(int density)
{
    CFieldSEFFog::SetDensity(density);
}

int ov0_0214CCBC()
{
    return CFieldSEFFog::GetColorR();
}

void ov0_0214CCCC(int r)
{
    CFieldSEFFog::SetColorR(r);
}

int ov0_0214CCEC()
{
    return CFieldSEFFog::GetColorG();
}

void ov0_0214CCFC(int g)
{
    CFieldSEFFog::SetColorG(g);
}

int ov0_0214CD1C()
{
    return CFieldSEFFog::GetColorB();
}

void ov0_0214CD2C(int b)
{
    CFieldSEFFog::SetColorB(b);
}

int ov0_0214CD4C()
{
    CFieldEffectManage *manage = MAIN_BSS_0210CA60;
    return manage != NULL ? manage->unk_77C : 0;
}

void ov0_0214CD68(int value)
{
    CFieldEffectManage *manage = MAIN_BSS_0210CA60;
    if (manage != NULL) {
        manage->unk_77C = value;
    }
}

int ov0_0214CD80()
{
    return 0;
}

void ov0_0214CD88(u32 type)
{
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player == NULL) {
        return;
    }
    if (type >= sizeof(sManpuTypes)) {
        return;
    }
    sub_02041C1C(player);
    sub_02041A70(player, sManpuTypes[type], -1);
}

int ov0_0214CDD0()
{
    return 0;
}

void ov0_0214CDD8(int type)
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
    effect->sub_0203312C(1, x >> FX32_SHIFT);
    if (effect->sub_02033028() == 0x13) {
        effect->sub_02033440(0x421F);
        effect->sub_0203312C(2, y >> FX32_SHIFT);
        effect->ov0_021421F0(0, -1, 0);
        return;
    }
    if (effect->sub_02033028() == 0x15) {
        effect->sub_0203312C(2, (y >> FX32_SHIFT) - 0x40);
        effect->ov0_021421F0(type == 9 ? 5 : 4, 0, 60);
        return;
    }
    if (effect->sub_02033028() == 0x17) {
        effect->sub_0203312C(2, y >> FX32_SHIFT);
        effect->ov0_021421F0(0, 30, 180);
        if (type == 11 || type == 13) {
            CGame::GetInstance()->unk_14BC->sub_0200E0E0(3, 180);
        }
        return;
    }
    if (effect->sub_02033028() == 0x1B) {
        effect->sub_0203312C(2, y >> FX32_SHIFT);
        effect->ov0_021421F0(30, 0, 30);
        return;
    }
    if (effect->sub_02033028() == 0x1E) {
        effect->sub_0203312C(2, y >> FX32_SHIFT);
        effect->sub_0203312C(0x1B, (y >> FX32_SHIFT) + 0x40);
        if (type == 19) {
            effect->ov0_021421F0(60, 180, 150);
        } else {
            effect->ov0_021421F0(60, -1, 60);
        }
        return;
    }
    effect->sub_0203312C(2, y >> FX32_SHIFT);
    effect->ov0_021421F0(0, -1, 0);
}

int ov0_0214D2CC()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 14);
}

void ov0_0214D2E4(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 14, count);
}

int ov0_0214D300()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 0);
}

void ov0_0214D318(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 0, count);
}

int ov0_0214D334()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 1);
}

void ov0_0214D34C(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 1, count);
}

int ov0_0214D368()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 9);
}

void ov0_0214D380(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 9, count);
}

int ov0_0214D39C()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 7);
}

void ov0_0214D3B4(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 7, count);
}

int ov0_0214D3D0()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 10);
}

void ov0_0214D3E8(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 10, count);
}

int ov0_0214D404()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 3);
}

void ov0_0214D41C(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 3, count);
}

int ov0_0214D438()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 4);
}

void ov0_0214D450(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 4, count);
}

int ov0_0214D46C()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 2);
}

void ov0_0214D484(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 2, count);
}

int ov0_0214D4A0()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 8);
}

void ov0_0214D4B8(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 8, count);
}

int ov0_0214D4D4()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 15);
}

void ov0_0214D4EC(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 15, count);
}

int ov0_0214D508()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 5);
}

void ov0_0214D520(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 5, count);
}

int ov0_0214D53C()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 12);
}

void ov0_0214D554(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 12, count);
}

int ov0_0214D570()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 6);
}

void ov0_0214D588(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 6, count);
}

int ov0_0214D5A4()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 11);
}

void ov0_0214D5BC(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 11, count);
}

int ov0_0214D5D8()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 13);
}

void ov0_0214D5F0(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 13, count);
}

int ov0_0214D60C()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 16);
}

void ov0_0214D624(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 16, count);
}

int ov0_0214D640()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 22);
}

void ov0_0214D658(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 22, count);
}

int ov0_0214D674()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 24);
}

void ov0_0214D68C(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 24, count);
}

int ov0_0214D6A8()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 25);
}

void ov0_0214D6C0(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 25, count);
}

int ov0_0214D6DC()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 17);
}

void ov0_0214D6F4(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 17, count);
}

int ov0_0214D710()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 18);
}

void ov0_0214D728(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 18, count);
}

int ov0_0214D744()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 19);
}

void ov0_0214D75C(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 19, count);
}

int ov0_0214D778()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 20);
}

void ov0_0214D790(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 20, count);
}

int ov0_0214D7AC()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 23);
}

void ov0_0214D7C4(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 23, count);
}

int ov0_0214D7E0()
{
    return sub_02016C14(&MAIN_BSS_020B26A0, 21);
}

void ov0_0214D7F8(int count)
{
    sub_02016C40(&MAIN_BSS_020B26A0, 21, count);
}

int ov0_0214D814()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 1) ? 1 : 0;
}

void ov0_0214D830(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 1;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~1;
    }
}

int ov0_0214D860()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 2) ? 1 : 0;
}

void ov0_0214D87C(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 2;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~2;
    }
}

int ov0_0214D8AC()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 4) ? 1 : 0;
}

void ov0_0214D8C8(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 4;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~4;
    }
}

int ov0_0214D8F8()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 8) ? 1 : 0;
}

void ov0_0214D914(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 8;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~8;
    }
}

int ov0_0214D944()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 0x10) ? 1 : 0;
}

void ov0_0214D960(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 0x10;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~0x10;
    }
}

int ov0_0214D990()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 0x20) ? 1 : 0;
}

void ov0_0214D9AC(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 0x20;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~0x20;
    }
}

int ov0_0214D9DC()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 0x40) ? 1 : 0;
}

void ov0_0214D9F8(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 0x40;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~0x40;
    }
}

int ov0_0214DA28()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 0x80) ? 1 : 0;
}

void ov0_0214DA44(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 0x80;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~0x80;
    }
}

int ov0_0214DA74()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 0x100) ? 1 : 0;
}

void ov0_0214DA90(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 0x100;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~0x100;
    }
}

int ov0_0214DAC0()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 0x200) ? 1 : 0;
}

void ov0_0214DADC(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 0x200;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~0x200;
    }
}

int ov0_0214DB0C()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 0x400) ? 1 : 0;
}

void ov0_0214DB28(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 0x400;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~0x400;
    }
}

int ov0_0214DB58()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 0x800) ? 1 : 0;
}

void ov0_0214DB74(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 0x800;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~0x800;
    }
}

int ov0_0214DBA4()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 0x1000) ? 1 : 0;
}

void ov0_0214DBC0(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 0x1000;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~0x1000;
    }
}

int ov0_0214DBF0()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 0x2000) ? 1 : 0;
}

void ov0_0214DC0C(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 0x2000;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~0x2000;
    }
}

int ov0_0214DC3C()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 0x4000) ? 1 : 0;
}

void ov0_0214DC58(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 0x4000;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~0x4000;
    }
}

int ov0_0214DC88()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 0x8000) ? 1 : 0;
}

void ov0_0214DCA4(int on)
{
    // clears the wrong bit (original bug)
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 0x8000;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~1;
    }
}

int ov0_0214DCD4()
{
    return (MAIN_BSS_020B26A0.unk_87C8 & 0x10000) ? 1 : 0;
}

void ov0_0214DCF0(int on)
{
    if (on) {
        MAIN_BSS_020B26A0.unk_87C8 |= 0x10000;
    } else {
        MAIN_BSS_020B26A0.unk_87C8 &= ~0x10000;
    }
}

void ov0_0214DD20(int on)
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

int ov0_0214DD9C()
{
    return MAIN_BSS_020B2638.unk_03;
}

int ov0_0214DDAC()
{
    return MAIN_BSS_020B2638.unk_02;
}

const char *ov0_0214DDBC()
{
    UnkClass_020091E8 *textbox = s_game->m_textboxData;
    const char *kinds[] = { "SYS", "AREA", "CHAP", "QUE", "BAT" };
    OS_SPrintf(sLastMessage, "%s - %d", kinds[textbox->unk_150], textbox->unk_154);
    return sLastMessage;
}

int ov0_0214DE24()
{
    return sQuestIdx;
}

void ov0_0214DE34(int quest)
{
    sQuestIdx = quest;
}

const char *ov0_0214DE44(int quest)
{
    UnkClass_0201164C *quests = (UnkClass_0201164C *)(void *)&MAIN_BSS_020B2638;
    OS_SPrintf(sQuestListName, "%02d)%s", quest, sQuestStates[GetQuestState(quests, quest)]);
    return sQuestListName;
}

int ov0_0214DEC8()
{
    return 0x3E;
}

int ov0_0214DED0()
{
    UnkClass_0201164C *quests = (UnkClass_0201164C *)(void *)&MAIN_BSS_020B2638;
    return GetQuestState(quests, sQuestIdx);
}

void ov0_0214DF34(int state)
{
    UnkClass_0201164C *quests = &MAIN_BSS_020B2638;
    switch (state) {
    case 0:
        quests->unk_14[sQuestIdx] = 0;
        break;
    case 1:
        quests->unk_14[sQuestIdx] = 1;
        break;
    case 2:
        quests->unk_14[sQuestIdx] = 0x11;
        break;
    case 3:
        quests->unk_14[sQuestIdx] = 0x11;
        if (quests->unk_01 == 1) {
            sub_020115F8(quests);
        }
        sub_02011540(quests, sQuestIdx);
        break;
    case 4:
        quests->unk_14[sQuestIdx] = 0x12;
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

void ov0_0214E040()
{
    UnkClass_0201164C *quests = &MAIN_BSS_020B2638;
    if (quests->unk_01 == 1) {
        sub_020115F8(quests);
    }
    for (int i = 0; i < 0x3E; i++) {
        quests->unk_14[i] = 0x11;
    }
    sub_02011540(quests, MATH_Rand32(&CGame::GetInstance()->m_rand32, 0x3D));
}

void ov0_0214E0D0()
{
    UnkClass_0201164C *quests = &MAIN_BSS_020B2638;
    if (quests->unk_01 == 1) {
        sub_020115F8(quests);
    }
    for (int i = 0; i < 0x3E; i++) {
        quests->unk_14[i] = 0;
    }
}

void ov0_0214E110()
{
    UnkClass_0201164C *quests = &MAIN_BSS_020B2638;
    if (quests->unk_01 == 1) {
        sub_020115F8(quests);
    }
    u32 current = MATH_Rand32(&CGame::GetInstance()->m_rand32, 0x3D);
    for (int i = 0; i < 0x3E; i++) {
        if (i != current) {
            switch (MATH_Rand32(&CGame::GetInstance()->m_rand32, 4)) {
            case 0:
                quests->unk_14[i] = 0;
                break;
            case 1:
                quests->unk_14[i] = 1;
                break;
            case 2:
                quests->unk_14[i] = 0x11;
                break;
            default:
                quests->unk_14[i] = 0x12;
                break;
            }
        } else {
            quests->unk_14[i] = 0x11;
        }
    }
    sub_02011540(quests, current);
}

void ov0_0214E24C()
{
    OS_SPrintf(sChapterLine, "ChaptNo: %02d", MAIN_BSS_020B2638.unk_08);
    OS_SPrintf(sMissionLine, "MissSta[%02d]: %d", MAIN_BSS_020B2638.unk_02, MAIN_BSS_020B2638.unk_00);
    OS_SPrintf(sQuestLine, "QueSta [%02d]: %d", MAIN_BSS_020B2638.unk_03, MAIN_BSS_020B2638.unk_01);
    OS_SPrintf(sEventLine0, "e00-07:%02d %02d %02d %02d %02d %02d %02d %02d", sub_02018E54(&MAIN_BSS_0210C0B0, 0), sub_02018E54(&MAIN_BSS_0210C0B0, 1), sub_02018E54(&MAIN_BSS_0210C0B0, 2), sub_02018E54(&MAIN_BSS_0210C0B0, 3), sub_02018E54(&MAIN_BSS_0210C0B0, 4), sub_02018E54(&MAIN_BSS_0210C0B0, 5), sub_02018E54(&MAIN_BSS_0210C0B0, 6), sub_02018E54(&MAIN_BSS_0210C0B0, 7));
    OS_SPrintf(sEventLine1, "e08-15:%02d %02d %02d %02d %02d %02d %02d %02d", sub_02018E54(&MAIN_BSS_0210C0B0, 8), sub_02018E54(&MAIN_BSS_0210C0B0, 9), sub_02018E54(&MAIN_BSS_0210C0B0, 10), sub_02018E54(&MAIN_BSS_0210C0B0, 11), sub_02018E54(&MAIN_BSS_0210C0B0, 12), sub_02018E54(&MAIN_BSS_0210C0B0, 13), sub_02018E54(&MAIN_BSS_0210C0B0, 14), sub_02018E54(&MAIN_BSS_0210C0B0, 15));
    OS_SPrintf(sEventLine2, "e16-20:%02d %02d %02d %02d %02d", sub_02018E54(&MAIN_BSS_0210C0B0, 16), sub_02018E54(&MAIN_BSS_0210C0B0, 17), sub_02018E54(&MAIN_BSS_0210C0B0, 18), sub_02018E54(&MAIN_BSS_0210C0B0, 19), sub_02018E54(&MAIN_BSS_0210C0B0, 20));
    OS_SPrintf(sStoryLine0, "s00-07:%02d %02d %02d %02d %02d %02d %02d %02d", sub_02019278(&MAIN_BSS_0210C0B0, 0), sub_02019278(&MAIN_BSS_0210C0B0, 1), sub_02019278(&MAIN_BSS_0210C0B0, 2), sub_02019278(&MAIN_BSS_0210C0B0, 3), sub_02019278(&MAIN_BSS_0210C0B0, 4), sub_02019278(&MAIN_BSS_0210C0B0, 5), sub_02019278(&MAIN_BSS_0210C0B0, 6), sub_02019278(&MAIN_BSS_0210C0B0, 7));
    OS_SPrintf(sStoryLine1, "s08-15:%02d %02d %02d %02d %02d %02d %02d %02d", sub_02019278(&MAIN_BSS_0210C0B0, 8), sub_02019278(&MAIN_BSS_0210C0B0, 9), sub_02019278(&MAIN_BSS_0210C0B0, 10), sub_02019278(&MAIN_BSS_0210C0B0, 11), sub_02019278(&MAIN_BSS_0210C0B0, 12), sub_02019278(&MAIN_BSS_0210C0B0, 13), sub_02019278(&MAIN_BSS_0210C0B0, 14), sub_02019278(&MAIN_BSS_0210C0B0, 15));
    OS_SPrintf(sStoryLine2, "s16-19:%02d %02d %02d %02d %02d %02d %02d %02d", sub_02019278(&MAIN_BSS_0210C0B0, 16), sub_02019278(&MAIN_BSS_0210C0B0, 17), sub_02019278(&MAIN_BSS_0210C0B0, 18), sub_02019278(&MAIN_BSS_0210C0B0, 19), sub_02019278(&MAIN_BSS_0210C0B0, 20), sub_02019278(&MAIN_BSS_0210C0B0, 21), sub_02019278(&MAIN_BSS_0210C0B0, 22), sub_02019278(&MAIN_BSS_0210C0B0, 23));
    OS_SPrintf(sStoryLine3, "s20-27:%02d %02d %02d %02d %02d %02d %02d", sub_02019278(&MAIN_BSS_0210C0B0, 24), sub_02019278(&MAIN_BSS_0210C0B0, 25), sub_02019278(&MAIN_BSS_0210C0B0, 26), sub_02019278(&MAIN_BSS_0210C0B0, 27), sub_02019278(&MAIN_BSS_0210C0B0, 28), sub_02019278(&MAIN_BSS_0210C0B0, 29), sub_02019278(&MAIN_BSS_0210C0B0, 30));
    OS_SPrintf(sQuestValueLine0, "q00-07:%02d %02d %02d %02d %02d %02d %02d %02d", sub_02018E88(&MAIN_BSS_0210C0B0, 0), sub_02018E88(&MAIN_BSS_0210C0B0, 1), sub_02018E88(&MAIN_BSS_0210C0B0, 2), sub_02018E88(&MAIN_BSS_0210C0B0, 3), sub_02018E88(&MAIN_BSS_0210C0B0, 4), sub_02018E88(&MAIN_BSS_0210C0B0, 5), sub_02018E88(&MAIN_BSS_0210C0B0, 6), sub_02018E88(&MAIN_BSS_0210C0B0, 7));
    OS_SPrintf(sQuestValueLine1, "q08-15:%02d %02d %02d", sub_02018E88(&MAIN_BSS_0210C0B0, 8), sub_02018E88(&MAIN_BSS_0210C0B0, 9), sub_02018E88(&MAIN_BSS_0210C0B0, 10));
}

int ov0_0214E83C()
{
    return sEncMapIdx;
}

int ov0_0214E84C()
{
    return sEncCaptIdx;
}

int ov0_0214E85C()
{
    return sEncWordIdx;
}

void ov0_0214E86C(int i)
{
    sEncMapIdx = i;
}

void ov0_0214E87C(int i)
{
    sEncCaptIdx = i;
}

void ov0_0214E88C(int i)
{
    sEncWordIdx = i;
}

int ov0_0214E89C()
{
    return 64;
}

const char *ov0_0214E8A4(int i)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    OS_SPrintf(sEncMapName, "%02d)%s", i, sEncStates[GetEncState(save, 0, i)]);
    return sEncMapName;
}

const char *ov0_0214E918(int i)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    OS_SPrintf(sEncCaptName, "%02d)%s", i, sEncStates[GetEncState(save, 1, i)]);
    return sEncCaptName;
}

const char *ov0_0214E98C(int i)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    OS_SPrintf(sEncWordName, "%02d)%s", i, sEncStates[GetEncState(save, 2, i)]);
    return sEncWordName;
}

void ov0_0214EA00(int state)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    int i = sEncMapIdx;
    if (i >= 0 && i < 64 && state >= 0 && state < 3) {
        int shift = (i & 0xF) * 2;
        save->unk_7F30[0][i / 16] &= ~(3 << shift);
        save->unk_7F30[0][i / 16] |= (state & 3) << shift;
    }
}

int ov0_0214EA74()
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    return GetEncState(save, 0, sEncMapIdx);
}

const char *ov0_0214EACC(int state)
{
    OS_SPrintf(sEncMapStateName, "%02d)%s", sEncMapIdx, sEncStates[state]);
    return sEncMapStateName;
}

void ov0_0214EB04(int state)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    int i = sEncCaptIdx;
    if (i >= 0 && i < 64 && state >= 0 && state < 3) {
        int shift = (i & 0xF) * 2;
        save->unk_7F30[1][i / 16] &= ~(3 << shift);
        save->unk_7F30[1][i / 16] |= (state & 3) << shift;
    }
}

int ov0_0214EB78()
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    return GetEncState(save, 1, sEncCaptIdx);
}

const char *ov0_0214EBD0(int state)
{
    OS_SPrintf(sEncCaptStateName, "%02d)%s", sEncCaptIdx, sEncStates[state]);
    return sEncCaptStateName;
}

void ov0_0214EC08(int state)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    int i = sEncWordIdx;
    if (i >= 0 && i < 64 && state >= 0 && state < 3) {
        int shift = (i & 0xF) * 2;
        save->unk_7F30[2][i / 16] &= ~(3 << shift);
        save->unk_7F30[2][i / 16] |= (state & 3) << shift;
    }
}

int ov0_0214EC7C()
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
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

void ov0_0214ED14()
{
    int group;
    int i;
    UnkClass_020B26A0 *save = CGame::GetInstance()->unk_14A4;
    for (group = 0; group < 3; group++) {
        for (i = 0; i < 64; i++) {
            if (GetCaptureState(save, group, i) == 0 && group >= 0 && group < 3 && i >= 0 && i < 64) {
                int shift = (i & 0xF) * 2;
                save->unk_7F30[group][i / 16] &= ~(3 << shift);
                save->unk_7F30[group][i / 16] |= 1 << shift;
            }
        }
    }
}

void ov0_0214EE00()
{
    int group;
    int i;
    UnkClass_020B26A0 *save = CGame::GetInstance()->unk_14A4;
    for (group = 0; group < 3; group++) {
        for (i = 0; i < 64; i++) {
            if (group >= 0 && group < 3 && i >= 0 && i < 64) {
                int shift = (i & 0xF) * 2;
                save->unk_7F30[group][i / 16] &= ~(3 << shift);
            }
        }
    }
}

void ov0_0214EE8C(int mood)
{
    UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
    switch (mood) {
    case 0:
    case 1:
    case 2:
        for (int i = 0; i < 17; i++) {
            save->unk_0009[i] = mood;
        }
        break;
    }
}

int ov0_0214EEC4()
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        return !(scene->unk_00D4 & 1);
    }
    return 1;
}

int ov0_0214EEF4()
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        return !(scene->unk_00D4 & 2);
    }
    return 1;
}

int ov0_0214EF24()
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        return !(scene->unk_00D4 & 4);
    }
    return 1;
}

int ov0_0214EF54()
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        return !(scene->unk_00D4 & 8);
    }
    return 1;
}

int ov0_0214EF84()
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        return !(scene->unk_00D4 & 16);
    }
    return 1;
}

void ov0_0214EFB4(int on)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        if (on) {
            scene->unk_00D4 &= ~1;
        } else {
            scene->unk_00D4 |= 1;
        }
    }
}

void ov0_0214EFE4(int on)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        if (on) {
            scene->unk_00D4 &= ~2;
        } else {
            scene->unk_00D4 |= 2;
        }
    }
}

void ov0_0214F014(int on)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        if (on) {
            scene->unk_00D4 &= ~4;
        } else {
            scene->unk_00D4 |= 4;
        }
    }
}

void ov0_0214F044(int on)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        if (on) {
            scene->unk_00D4 &= ~8;
        } else {
            scene->unk_00D4 |= 8;
        }
    }
}

void ov0_0214F074(int on)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        if (on) {
            scene->unk_00D4 &= ~16;
        } else {
            scene->unk_00D4 |= 16;
        }
    }
}

int ov0_0214F0A4()
{
    return 0;
}

void ov0_0214F0AC(int state)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    for (int i = 0; i < 0x1EE; i++) {
        if (IsBrowserEntry(i)) {
            SetBrowserState(save, i, state);
        }
    }
    if (state == 0) {
        SetBrowserState(save, 399, 2);
    }
}

void ov0_0214F184(int flags)
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    SetBrowserState(save, 492, (flags & 1) ? 2 : 0);
    SetBrowserState(save, 483, (flags & 2) ? 2 : 0);
    SetBrowserState(save, 484, (flags & 4) ? 2 : 0);
}

void ov0_0214F274()
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    for (int i = 0; i < 0x1EE; i++) {
        if (i != 486 && i != 492 && i != 483 && i != 484 && IsBrowserEntry(i)) {
            SetBrowserState(save, i, 2);
        } else {
            SetBrowserState(save, i, 0);
        }
    }
}

int ov0_0214F378()
{
    return MAIN_BSS_020B26A0.unk_002C;
}

void ov0_0214F388(int value)
{
    sub_02016D4C(&MAIN_BSS_020B26A0, value);
}

int ov0_0214F3A0()
{
    return MAIN_BSS_020B26A0.unk_8758;
}

void ov0_0214F3B0(int value)
{
    sub_02016D88(&MAIN_BSS_020B26A0, value);
}

int ov0_0214F3C8()
{
    return MAIN_BSS_020B26A0.unk_875C;
}

void ov0_0214F3D8(int value)
{
    sub_02016DD0(&MAIN_BSS_020B26A0, value);
}

int ov0_0214F3F0()
{
    return MAIN_BSS_020B26A0.unk_8760;
}

void ov0_0214F400(int value)
{
    sub_02016E18(&MAIN_BSS_020B26A0, value);
}

int ov0_0214F418()
{
    return MAIN_BSS_020B26A0.unk_8764;
}

void ov0_0214F428(int value)
{
    sub_02016E60(&MAIN_BSS_020B26A0, value);
}

int ov0_0214F440()
{
    return MAIN_BSS_020B26A0.unk_8768;
}

void ov0_0214F450(int value)
{
    sub_02016EA8(&MAIN_BSS_020B26A0, value);
}

int ov0_0214F468()
{
    return sAssistIdx;
}

void ov0_0214F478(int index)
{
    sAssistIdx = index;
}

const char *ov0_0214F488(int index)
{
    switch (index) {
    case 0:
        OS_SPrintf(sAssistName, "GONB:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 1:
        OS_SPrintf(sAssistName, "HIKO:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 2:
        OS_SPrintf(sAssistName, "POCH:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 3:
        OS_SPrintf(sAssistName, "NAET:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 4:
        OS_SPrintf(sAssistName, "PACH:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 5:
        OS_SPrintf(sAssistName, "YUKI:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 6:
        OS_SPrintf(sAssistName, "WANR:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 7:
        OS_SPrintf(sAssistName, "GURE:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 8:
        OS_SPrintf(sAssistName, "HIPP:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 9:
        OS_SPrintf(sAssistName, "MUKK:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 10:
        OS_SPrintf(sAssistName, "MANE:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 11:
        OS_SPrintf(sAssistName, "KORO:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 12:
        OS_SPrintf(sAssistName, "ZUGA:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 13:
        OS_SPrintf(sAssistName, "MUMA:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 14:
        OS_SPrintf(sAssistName, "FUKA:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 15:
        OS_SPrintf(sAssistName, "NYUL:%d", MAIN_BSS_020B26A0.unk_876C[index]);
        break;
    case 16:
        OS_SPrintf(sAssistName, "TATE:%d", MAIN_BSS_020B26A0.unk_876C[index]);
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

u32 ov0_0214F6E4()
{
    return MAIN_BSS_020B26A0.unk_87B0 * 33 / 480;
}

void ov0_0214F708(int value)
{
    sub_02017020(&MAIN_BSS_020B26A0, value * 1584 / 10);
}

int ov0_0214F738()
{
    return MAIN_BSS_020B26A0.unk_87B4;
}

void ov0_0214F748(int value)
{
    sub_02017068(&MAIN_BSS_020B26A0, value);
}

int ov0_0214F760()
{
    return MAIN_BSS_020B26A0.unk_87B8;
}

void ov0_0214F770(int value)
{
    sub_020170B0(&MAIN_BSS_020B26A0, value);
}

int ov0_0214F78C()
{
    return MAIN_BSS_020B26A0.unk_87BA;
}

void ov0_0214F79C(int value)
{
    sub_02017100(&MAIN_BSS_020B26A0, value);
}

int ov0_0214F7B8()
{
    return MAIN_BSS_020B26A0.unk_87BC;
}

void ov0_0214F7C8(int value)
{
    sub_02017150(&MAIN_BSS_020B26A0, value);
}

int ov0_0214F7E4()
{
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    if (MAIN_BSS_020B26A0.unk_87DA != 0) {
        return 359999;
    }
    return save->unk_87D4 * 3600 + save->unk_87D8 * 60 + save->unk_87D9;
}

void ov0_0214F830(int seconds)
{
    sub_02018148(&MAIN_BSS_020B26A0, seconds / 3600, (seconds % 3600) / 60, seconds % 60);
    RTCTime time;
    RTCDate date;
    RTC_GetTime(&time);
    RTC_GetDate(&date);
    MAIN_BSS_020B26A0.unk_8B94 = time;
    MAIN_BSS_020B26A0.unk_8B84 = date;
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

int ov0_0214F99C()
{
    return MAIN_BSS_020B26A0.unk_876C[sAssistIdx];
}

void ov0_0214F9B8(int value)
{
    sub_02016EF0(&MAIN_BSS_020B26A0, sAssistIdx, value);
}

} // extern "C"

DebugMenuItem sCustom2Items[] = {
    { "CHGSPD", 1, 2, 4, 0, (void *)ov0_0214D674, (void *)ov0_0214D68C, (void *)3, 0 },
    { "SUPERCHG", 1, 2, 4, 0, (void *)ov0_0214D6A8, (void *)ov0_0214D6C0, (void *)3, 0 },
    { "ASSISTT", 1, 2, 4, 0, (void *)ov0_0214D6DC, (void *)ov0_0214D6F4, (void *)3, 0 },
    { "SOKO", 1, 2, 4, 0, (void *)ov0_0214D710, (void *)ov0_0214D728, (void *)3, 0 },
    { "COMBO", 1, 2, 4, 0, (void *)ov0_0214D744, (void *)ov0_0214D75C, (void *)3, 0 },
    { "RECOVER", 1, 2, 4, 0, (void *)ov0_0214D778, (void *)ov0_0214D790, (void *)3, 0 },
    { "POWPLS", 1, 2, 4, 0, (void *)ov0_0214D7AC, (void *)ov0_0214D7C4, (void *)3, 0 },
    { "ENEPLS", 1, 2, 4, 0, (void *)ov0_0214D7E0, (void *)ov0_0214D7F8, (void *)3, 0 },
};

const char *sManpuNames[] = { "HINT_A(R", "HINT_A(B", "HINT_A(G", "HINT_B", "BIKKURI", "HATENA", "IKARI", "ASE", "KIZUKI", "DOKARIMO", "MOBARIMO", "ARIENAI!", "DARKRIE", "GOKIGEN", "SGOKIGEN" };

DebugMenuItem sEventChapterItems[] = {
    { "ChapJump", 1, 2, 2, 0, (void *)ov0_0214C790, (void *)ov0_0214C7AC, (void *)76, 0 },
};

DebugMenuItem sQuestStatusItems[] = {
    { "QuestSta", 5, 1, 1, 0, (void *)ov0_0214DED0, (void *)ov0_0214DF34, (void *)ov0_0214E000, (void *)ov0_0214E038 },
};

DebugMenuItem sPartnerList0Items[] = {
    { "Nyula", 3, 2, 4, 0, (void *)ov0_0214DC88, (void *)ov0_0214DCA4, 0, 0 },
    { "Pachirisu", 3, 2, 4, 0, (void *)ov0_0214D944, (void *)ov0_0214D960, 0, 0 },
    { "Mukkuru", 3, 2, 4, 0, (void *)ov0_0214DAC0, (void *)ov0_0214DADC, 0, 0 },
    { "Zugaidos", 3, 2, 4, 0, (void *)ov0_0214DBA4, (void *)ov0_0214DBC0, 0, 0 },
    { "Muma", 3, 2, 4, 0, (void *)ov0_0214DBF0, (void *)ov0_0214DC0C, 0, 0 },
    { "Korobohshi", 3, 2, 4, 0, (void *)ov0_0214DB58, (void *)ov0_0214DB74, 0, 0 },
    { "Tatetopsu", 3, 2, 4, 0, (void *)ov0_0214DCD4, (void *)ov0_0214DCF0, 0, 0 },
    { "Gonbe", 3, 2, 4, 0, (void *)ov0_0214D814, (void *)ov0_0214D830, 0, 0 },
    { "Wanriky", 3, 2, 4, 0, (void *)ov0_0214D9DC, (void *)ov0_0214D9F8, 0, 0 },
};

DebugMenuItem sFieldEffectItems[] = {
    { "SetWeather", 0, 0, 1, 12, 0, 0, 0, 0 },
    { "FogParam", 0, 0, 1, 13, 0, 0, 0, 0 },
    { "FootStep", 4, 2, 3, 0, (void *)ov0_0214CD4C, (void *)ov0_0214CD68, (void *)sFootStepNames, (void *)5 },
    { "MANPU", 4, 2, 3, 0, (void *)ov0_0214CD80, (void *)ov0_0214CD88, (void *)sManpuNames, (void *)15 },
    { "TestEff", 4, 1, 3, 0, (void *)ov0_0214CDD0, (void *)ov0_0214CDD8, (void *)sTestEffectNames, (void *)20 },
};

const char *sFootStepNames[] = { "NONE", "MUDDY", "SNOW", "GRASS", "WATER" };

const char *sMoodNames[] = { "NORMAL", "GOOD", "VERYGOOD" };

DebugMenuItem sRangerRecordItems[] = {
    { "TotalExp", 8, 2, 4, 0, (void *)ov0_0214F378, (void *)ov0_0214F388, (void *)9999999, 0 },
    { "WalkStep", 8, 2, 4, 0, (void *)ov0_0214F3A0, (void *)ov0_0214F3B0, (void *)9999999, 0 },
    { "TalkCnt", 1, 2, 4, 0, (void *)ov0_0214F3C8, (void *)ov0_0214F3D8, (void *)99999, 0 },
    { "LookCnt", 1, 2, 4, 0, (void *)ov0_0214F3F0, (void *)ov0_0214F400, (void *)99999, 0 },
    { "SaveCnt", 1, 2, 4, 0, (void *)ov0_0214F418, (void *)ov0_0214F428, (void *)99999, 0 },
    { "RideCnt", 1, 2, 4, 0, (void *)ov0_0214F440, (void *)ov0_0214F450, (void *)99999, 0 },
    { "PtAssCnt", 5, 0, 1, 30, (void *)ov0_0214F468, (void *)ov0_0214F478, (void *)ov0_0214F488, (void *)ov0_0214F6DC },
    { "LineLeng", 7, 2, 4, 0, (void *)ov0_0214F6E4, (void *)ov0_0214F708, (void *)14545440, 0 },
    { "EnclsCnt", 7, 2, 4, 0, (void *)ov0_0214F738, (void *)ov0_0214F748, (void *)999999, 0 },
    { "CaptCnt", 1, 2, 4, 0, (void *)ov0_0214F760, (void *)ov0_0214F770, (void *)9999, 0 },
    { "EscpCnt", 1, 2, 4, 0, (void *)ov0_0214F78C, (void *)ov0_0214F79C, (void *)9999, 0 },
    { "AssCnt", 1, 2, 4, 0, (void *)ov0_0214F7B8, (void *)ov0_0214F7C8, (void *)9999, 0 },
    { "PlyTime", 5, 2, 4, 0, (void *)ov0_0214F7E4, (void *)ov0_0214F830, (void *)ov0_0214F904, (void *)ov0_0214F990 },
};

DebugMenuItem sMAINItems[] = {
    { "Map", 5, 0, 3, 1, 0, 0, (void *)ov0_0214DD8C, 0 },
    { "Event(Chap", 6, 0, 3, 5, (void *)ov0_0214C790, 0, 0, 0 },
    { "Quest", 6, 0, 3, 32, (void *)ov0_0214DD9C, 0, 0, 0 },
    { "Mission", 6, 0, 3, 32, (void *)ov0_0214DDAC, 0, 0, 0 },
    { "LastMes", 5, 2, 0, 0, 0, 0, (void *)ov0_0214DDBC, 0 },
    { "Player", 0, 0, 3, 3, 0, 0, 0, 0 },
    { "DEBPRIM", 4, 2, 3, 0, (void *)ov0_0214BFB8, (void *)ov0_0214BFE4, (void *)sDebugPrimNames, (void *)3 },
    { "DbgInfo", 0, 0, 3, 9, 0, 0, 0, 0 },
    { "SetActor", 0, 0, 3, 10, 0, 0, 0, 0 },
    { "FieldEffect", 0, 0, 3, 11, 0, 0, 0, 0 },
    { "Encyclopedia", 0, 0, 3, 22, 0, 0, 0, 0 },
    { "ActorDisp", 0, 0, 3, 27, 0, 0, 0, 0 },
    { "Browser", 0, 0, 3, 28, 0, 0, 0, 0 },
    { "RangerRecord", 0, 0, 3, 29, 0, 0, 0, 0 },
    { "GAMEEND", 2, 3, 3, 0, 0, (void *)ov0_0214BF94, 0, 0 },
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
    { "NORMAL_G", 1, 2, 4, 0, (void *)ov0_0214D2CC, (void *)ov0_0214D2E4, (void *)3, 0 },
    { "LEAF_G", 1, 2, 4, 0, (void *)ov0_0214D300, (void *)ov0_0214D318, (void *)3, 0 },
    { "AQUA_G", 1, 2, 4, 0, (void *)ov0_0214D334, (void *)ov0_0214D34C, (void *)3, 0 },
    { "ROCK_G", 1, 2, 4, 0, (void *)ov0_0214D368, (void *)ov0_0214D380, (void *)3, 0 },
    { "INSECT_G", 1, 2, 4, 0, (void *)ov0_0214D39C, (void *)ov0_0214D3B4, (void *)3, 0 },
    { "AIR_G", 1, 2, 4, 0, (void *)ov0_0214D3D0, (void *)ov0_0214D3E8, (void *)3, 0 },
    { "FIRE_G", 1, 2, 4, 0, (void *)ov0_0214D404, (void *)ov0_0214D41C, (void *)3, 0 },
    { "FIGHT_G", 1, 2, 4, 0, (void *)ov0_0214D438, (void *)ov0_0214D450, (void *)3, 0 },
    { "LIGHT_G", 1, 2, 4, 0, (void *)ov0_0214D46C, (void *)ov0_0214D484, (void *)3, 0 },
};

DebugMenuItem sEventItems[] = {
    { "Chapter", 0, 0, 0, 6, 0, 0, 0, 0 },
    { "EventFlags", 0, 0, 1, 31, 0, (void *)ov0_0214E24C, 0, 0 },
};

DebugMenuItem sPartnerMoodItems[] = {
    { "PartnerMood", 4, 2, 4, 0, 0, (void *)ov0_0214EE8C, (void *)sMoodNames, (void *)3 },
};

const char *sSexNames[] = { "MALE", "FEMALE" };

const char *sWatchNames[] = { "NONE", "LOOK", "CAPTURE" };

DebugMenuItem sBrowserItems[] = {
    { "SetWatchAll", 4, 1, 3, 0, (void *)ov0_0214F0A4, (void *)ov0_0214F0AC, (void *)sWatchNames, (void *)3 },
    { "SPCapture", 4, 1, 3, 0, (void *)ov0_0214F0A4, (void *)ov0_0214F184, (void *)sCaptureNames, (void *)8 },
    { "Regigigas", 0, 0, 1, 0, (void *)ov0_0214F0A4, (void *)ov0_0214F274, 0, 0 },
};

const char *sEncStates[] = { "CLOSE", "NEW", "OPEN" };

DebugMenuItem sQuestItems[] = {
    { "Quest", 5, 0, 1, 7, (void *)ov0_0214DE24, (void *)ov0_0214DE34, (void *)ov0_0214DE44, (void *)ov0_0214DEC8 },
    { "Quest OPEN ALL", 0, 2, 8, 0, 0, (void *)ov0_0214E040, 0, 0 },
    { "Quest CLOSE ALL", 0, 2, 8, 0, 0, (void *)ov0_0214E0D0, 0, 0 },
    { "Quest RANDOM", 0, 2, 8, 0, 0, (void *)ov0_0214E110, 0, 0 },
};

DebugMenuItem sAddTargetItems[] = {
    { "TargetID", 5, 2, 2, 0, (void *)ov0_0214BB18, (void *)ov0_0214BB28, (void *)ov0_0214BB38, (void *)ov0_0214BBCC },
    { "ScriptID", 1, 2, 2, 0, 0, (void *)ov0_0214BBEC, (void *)1000, 0 },
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
    { "PokeAdd", 5, 2, 2, 0, (void *)ov0_0214C560, (void *)ov0_0214C568, (void *)ov0_0214C4A0, (void *)ov0_0214C540 },
};

DebugMenuItem sPartnerList1Items[] = {
    { "Naetle", 3, 2, 4, 0, (void *)ov0_0214D8F8, (void *)ov0_0214D914, 0, 0 },
    { "Hikozaru", 3, 2, 4, 0, (void *)ov0_0214D860, (void *)ov0_0214D87C, 0, 0 },
    { "Gureggru", 3, 2, 4, 0, (void *)ov0_0214DA28, (void *)ov0_0214DA44, 0, 0 },
    { "Yukikaburi", 3, 2, 4, 0, (void *)ov0_0214D990, (void *)ov0_0214D9AC, 0, 0 },
    { "Manene", 3, 2, 4, 0, (void *)ov0_0214DB0C, (void *)ov0_0214DB28, 0, 0 },
    { "Hippopotas", 3, 2, 4, 0, (void *)ov0_0214DA74, (void *)ov0_0214DA90, 0, 0 },
    { "Fukamaru", 3, 2, 4, 0, (void *)ov0_0214DC3C, (void *)ov0_0214DC58, 0, 0 },
    { "Pochama", 3, 2, 4, 0, (void *)ov0_0214D8AC, (void *)ov0_0214D8C8, 0, 0 },
};

DebugMenuItem sDebugInfoItems[] = {
    { "TexVramInfo", 0, 1, 1, 0, 0, (void *)ov0_0214C900, 0, 0 },
    { "PlttVramInfo", 0, 1, 1, 0, 0, (void *)ov0_0214C90C, 0, 0 },
    { "UpperDbgInfo", 0, 1, 1, 0, 0, (void *)ov0_0214C918, 0, 0 },
    { "ProcLoad", 3, 2, 3, 0, (void *)ov0_0214C738, (void *)ov0_0214C764, 0, 0 },
};

DebugMenuItem sEncyclopediaMapItems[] = {
    { "EncMap", 5, 1, 4, 0, (void *)ov0_0214EA74, (void *)ov0_0214EA00, (void *)ov0_0214EACC, (void *)ov0_0214ED0C },
};

DebugMenuItem sMapItems[] = {
    { "MapID", 5, 0, 0, 2, (void *)ov0_0214BACC, 0, (void *)ov0_0214B9B0, 0 },
    { "CollFree", 3, 2, 2, 0, (void *)ov0_0214C448, (void *)ov0_0214C474, 0, 0 },
    { "EncFree", 3, 2, 3, 0, (void *)ov0_0214C6E0, (void *)ov0_0214C70C, 0, 0 },
    { "EvArea", 3, 2, 3, 0, (void *)ov0_0214C664, (void *)ov0_0214C690, 0, 0 },
    { "AddTarget", 0, 0, 0, 14, 0, 0, 0, 0 },
    { "VisitAll", 3, 2, 3, 0, 0, (void *)ov0_0214DD20, 0, 0 },
};

DebugMenuItem sPlayerMoveItems[] = {
    { "POSX", 1, 2, 4, 0, (void *)ov0_0214BDD0, (void *)ov0_0214BE08, (void *)2048, 0 },
    { "POSY", 1, 2, 4, 0, (void *)ov0_0214BEB0, (void *)ov0_0214BEE8, (void *)2048, 0 },
};

DebugMenuItem sEncyclopediaCaptItems[] = {
    { "EncCapt", 5, 1, 4, 0, (void *)ov0_0214EB78, (void *)ov0_0214EB04, (void *)ov0_0214EBD0, (void *)ov0_0214ED0C },
};

DebugMenuItem sFogColorItems[] = {
    { "R", 1, 1, 4, 0, (void *)ov0_0214CCBC, (void *)ov0_0214CCCC, (void *)31, 0 },
    { "G", 1, 1, 4, 0, (void *)ov0_0214CCEC, (void *)ov0_0214CCFC, (void *)31, 0 },
    { "B", 1, 1, 4, 0, (void *)ov0_0214CD1C, (void *)ov0_0214CD2C, (void *)31, 0 },
    { "A", 1, 1, 4, 0, (void *)ov0_0214CC8C, (void *)ov0_0214CC9C, (void *)31, 0 },
};

const char *sCaptureNames[] = { "XXX", "1XX", "X2X", "12X", "XX3", "1X3", "X23", "123" };

const char *sQuestStates[] = { "CLOSE", "NEW", "OPEN", "ACCEPT", "CLEAR" };

DebugMenuItem sActorDispItems[] = {
    { "PlyrDisp", 3, 2, 4, 0, (void *)ov0_0214EEC4, (void *)ov0_0214EFB4, 0, 0 },
    { "PrtyDisp", 3, 2, 4, 0, (void *)ov0_0214EEF4, (void *)ov0_0214EFE4, 0, 0 },
    { "EneDisp", 3, 2, 4, 0, (void *)ov0_0214EF24, (void *)ov0_0214F014, 0, 0 },
    { "NpcDisp", 3, 2, 4, 0, (void *)ov0_0214EF54, (void *)ov0_0214F044, 0, 0 },
    { "ObjDisp", 3, 2, 4, 0, (void *)ov0_0214EF84, (void *)ov0_0214F074, 0, 0 },
    { "HPDisp", 3, 2, 4, 0, (void *)ov0_0214C010, (void *)ov0_0214C040, 0, 0 },
};

DebugMenuItem sPlayerItems[] = {
    { "PlyrHP", 1, 2, 4, 0, (void *)ov0_0214C070, (void *)ov0_0214C088, (void *)128, 0 },
    { "PlyrLvl", 1, 2, 4, 0, (void *)ov0_0214C0C0, (void *)ov0_0214C0DC, (void *)128, 0 },
    { "RangCls", 1, 2, 3, 0, (void *)ov0_0214C120, (void *)ov0_0214C13C, (void *)10, 0 },
    { "RangGrd", 1, 2, 3, 0, (void *)ov0_0214C170, (void *)ov0_0214C194, (void *)2, 0 },
    { "PlyrSex", 4, 2, 3, 0, (void *)ov0_0214C2E8, (void *)ov0_0214C300, (void *)sSexNames, (void *)2 },
    { "PlyrMove", 0, 0, 3, 4, 0, 0, 0, 0 },
    { "PokeAdd", 0, 0, 3, 8, 0, 0, 0, 0 },
    { "Custom", 0, 0, 3, 15, 0, 0, 0, 0 },
    { "PartnerGetFlag", 0, 0, 3, 19, 0, 0, 0, 0 },
    { "HPGauge", 3, 2, 3, 0, (void *)ov0_0214C010, (void *)ov0_0214C040, 0, 0 },
    { "PartnerMood", 0, 0, 3, 26, 0, 0, 0, 0 },
};

const char *sTestEffectNames[] = { "BLOOM1", "BLOOM2", "BLOOM3", "DARKFOG1", "DARKFOG2", "DARKFOG3", "SHADOW1", "SHADOW2", "HANABI1", "HANABI2", "CLEAR1", "CLEAR2", "CLEAR3", "CLEAR4", "GLITTER", "B-STONE", "B-STONE2", "FLOWER", "CREVICE1", "CREVICE2" };

DebugMenuItem sSetWeatherItems[] = {
    { "Weather", 1, 2, 2, 0, (void *)ov0_0214CB2C, (void *)ov0_0214CB34, (void *)16, 0 },
};

DebugMenuItem sSetActorItems[] = {
    { "Poke:", 0, 2, 1, 0, 0, (void *)ov0_0214C900, 0, 0 },
    { "put field", 4, 2, 1, 0, 0, (void *)ov0_0214C900, (void *)sPutFieldNames, (void *)3 },
    { "put party", 0, 2, 1, 0, 0, (void *)ov0_0214C900, 0, 0 },
    { "view party", 0, 2, 8, 0, 0, (void *)ov0_0214C930, 0, 0 },
};

DebugMenuItem sEncyclopediaItems[] = {
    { "EncMap", 5, 0, 1, 23, (void *)ov0_0214E83C, (void *)ov0_0214E86C, (void *)ov0_0214E8A4, (void *)ov0_0214E89C },
    { "EncCapt", 5, 0, 1, 24, (void *)ov0_0214E84C, (void *)ov0_0214E87C, (void *)ov0_0214E918, (void *)ov0_0214E89C },
    { "EncWord", 5, 0, 1, 25, (void *)ov0_0214E85C, (void *)ov0_0214E88C, (void *)ov0_0214E98C, (void *)ov0_0214E89C },
    { "Disp ALL", 0, 2, 1, 0, 0, (void *)ov0_0214ED14, 0, 0 },
    { "Hide ALL", 0, 2, 1, 0, 0, (void *)ov0_0214EE00, 0, 0 },
};

DebugMenuItem sCustom1Items[] = {
    { "CROUND_G", 1, 2, 4, 0, (void *)ov0_0214D4A0, (void *)ov0_0214D4B8, (void *)3, 0 },
    { "METAL_G", 1, 2, 4, 0, (void *)ov0_0214D4D4, (void *)ov0_0214D4EC, (void *)3, 0 },
    { "POISON_G", 1, 2, 4, 0, (void *)ov0_0214D508, (void *)ov0_0214D520, (void *)3, 0 },
    { "HORROR_G", 1, 2, 4, 0, (void *)ov0_0214D53C, (void *)ov0_0214D554, (void *)3, 0 },
    { "PSYCHO_G", 1, 2, 4, 0, (void *)ov0_0214D570, (void *)ov0_0214D588, (void *)3, 0 },
    { "DARK_G", 1, 2, 4, 0, (void *)ov0_0214D5A4, (void *)ov0_0214D5BC, (void *)3, 0 },
    { "ICE_G", 1, 2, 4, 0, (void *)ov0_0214D5D8, (void *)ov0_0214D5F0, (void *)3, 0 },
    { "DRAGON_G", 1, 2, 4, 0, (void *)ov0_0214D60C, (void *)ov0_0214D624, (void *)3, 0 },
    { "LongLine", 1, 2, 4, 0, (void *)ov0_0214D640, (void *)ov0_0214D658, (void *)3, 0 },
};

DebugMenuItem sPartnerAssistCountItems[] = {
    { "PtAssCnt", 8, 1, 4, 0, (void *)ov0_0214F99C, (void *)ov0_0214F9B8, (void *)9999999, 0 },
};

const char *sPutFieldNames[] = { "(none)", "(hide)", "(fall)" };

DebugMenuItem sEncyclopediaWordItems[] = {
    { "EncWord", 5, 1, 4, 0, (void *)ov0_0214EC7C, (void *)ov0_0214EC08, (void *)ov0_0214ECD4, (void *)ov0_0214ED0C },
};

DebugMenuItem sMapJumpItems[] = {
    { "MapJump", 5, 3, 3, 0, (void *)ov0_0214BACC, (void *)ov0_0214BADC, (void *)ov0_0214B9B0, (void *)ov0_0214BAAC },
};

DebugMenuItem sPartnerGetFlagItems[] = {
    { "m_008_006", 0, 0, 3, 20, 0, 0, 0, 0 },
    { "m_008_008", 0, 0, 3, 21, 0, 0, 0, 0 },
};

const char *sDebugPrimNames[] = { "OFF", "Collision", "TouchRect" };

UnkClass_0214F9DC::UnkClass_0214F9DC(CGame *game)
{
    MAIN_BSS_0210CA80 = this;
    m_game = game;
    unk_04 = new UnkClass_02008FA8(game->GetPrinter(), (u32)game->unk_0014);
    unk_08 = NULL;
    unk_0C = NULL;
    unk_10 = 0;
    ov0_0214FA94(sMenus, sizeof(sMenus) / sizeof(sMenus[0]));
}

UnkClass_0214F9DC::~UnkClass_0214F9DC()
{
    unk_04->sub_02009020();
    SAFE_DELETE(unk_04);
    MAIN_BSS_0210CA80 = NULL;
}

void UnkClass_0214F9DC::ov0_0214FA94(DebugMenu *menus, int count)
{
    unk_0C = menus;
    unk_10 = count;
}

void UnkClass_0214F9DC::ov0_0214FAA0()
{
    unk_04->sub_020090E8(0, 0);
    unk_08 = unk_0C;
    for (int i = 0; i < unk_10; i++) {
        unk_0C[i].unk_10 = 0;
        unk_0C[i].unk_14 = 0;
    }
}

void UnkClass_0214F9DC::ov0_0214FB08()
{
    unk_04->sub_02009050();
}

BOOL UnkClass_0214F9DC::ov0_0214FB18()
{
    return unk_04->sub_02009108();
}
