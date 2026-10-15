#include "field/CFieldPartnerManage.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "FieldSubScreen.hpp"
#include "SaveData.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkStruct_020107A8.hpp"
#include "field/CFieldEffectManpu.hpp"
#include "field/CFieldPartnerNpc.hpp"
#include "field/CFieldPartnerPokemon.hpp"
#include "field/CFieldPlayer.hpp"
#include "field/FieldPartnerIndex.hpp"
#include "file/CBinaryFile.hpp"
#include "scene/CFieldScene.hpp"
#include "sub_02044440.hpp"

struct FieldNpcData {
    u16 unk_00;
    s8 unk_02;
    s8 unk_03;
};

extern CFieldScene *MAIN_BSS_0210CA40;
extern FieldData *MAIN_BSS_0210CA6C;
extern SaveData MAIN_BSS_020B26A0;
extern MATHRandContext16 MAIN_BSS_0210CEC8;

extern "C" {
void LogError(const char *fmt, ...);
void LogInfo(const char *fmt, ...);
void Script_Link(void *script);
FieldNpcData *FieldData_GetNpc(FieldData *obj, int kind);
FieldEnemyData *FieldData_GetEnemy(FieldData *obj, int kind);
BOOL SaveData_IsInParty(SaveData *save, int mapId, int idx);
void SavePartner_Clear(PartnerSlot *partner);
void SaveData_AddToParty(SaveData *save, u32 id, u16 kind, int arg3);
}

FieldPartnerScripts::FieldPartnerScripts()
{
    Script_InitSyscalls();
    for (int i = 0; i < 2; i++) {
        unk_24[i] = NULL;
        unk_2C[i] = NULL;
    }
    Load("data/Script/field/actor/FieldPartnerPokemonScript.fsb", 1);
    Load("data/Script/field/actor/FieldPartnerNpcScript.fsb", 0);
}

FieldPartnerScripts::~FieldPartnerScripts()
{
    for (int i = 0; i < 2; i++) {
        SAFE_DELETE(unk_24[i]);
    }
}

void FieldPartnerScripts::Load(const char *path, int idx)
{
    u32 heapId = s_game->unk_14A8;
    unk_24[idx] = new CBinaryFile(path, 0, 0, heapId, NULL, 0);
    unk_2C[idx] = unk_24[idx]->unk_4C;
    Script_Link(unk_2C[idx]);
}

CFieldPartnerManage::CFieldPartnerManage()
{
    MAIN_BSS_0210CA4C = this;
    unk_0C = 4;
}

void CFieldPartnerManage::Alloc(int capacity)
{
    CFieldActorManage::Alloc(capacity);
    unk_8C = new FieldPartnerScripts();
    unk_90 = MAIN_BSS_0210CA40;
    unk_84 = 0;
    unk_88 = 0;
    unk_94 = 5;
    for (int i = 0; i < 11; i++) {
        unk_54[i] = 0;
        unk_6A[i] = 0;
    }
    unk_80 = 0;
}

void CFieldPartnerManage::Free()
{
    CFieldActorManage::Free();
    SAFE_DELETE(unk_8C);
}

void CFieldPartnerManage::UpdateAll(CFieldMap *map, BOOL update)
{
    CFieldPlayer *player = (CFieldPlayer *)MAIN_BSS_0210CA40->ov0_02123060(0);
    if (update) {
        if (player->ov0_0213416C()) {
            return;
        }
        ov0_0213B0F0();
        if (m_actors == NULL) {
            return;
        }
        SaveData *save = &MAIN_BSS_020B26A0;
        for (int i = 0; i < m_count; i++) {
            CFieldPartner *partner = (CFieldPartner *)m_actors[i];
            if (partner == NULL || !partner->IsActive()) {
                continue;
            }
            if (save->m_areaType == 4 && partner->IsKind0() && !(partner->m_flags & 0x20)) {
                continue;
            }
            if (player->unk_110 & 3) {
                continue;
            }
            partner->Process(map);
            partner->ov0_02139164();
        }
    } else {
        unk_94 = 5;
        ov0_0213B0F0();
        if (m_actors == NULL) {
            return;
        }
        for (int i = 0; i < m_count; i++) {
            CFieldPartner *partner = (CFieldPartner *)m_actors[i];
            if (partner == NULL || !partner->IsActive()) {
                continue;
            }
            partner->UpdateMove(map);
            partner->ov0_02139164();
        }
    }
}

void CFieldPartnerManage::DrawAll(DrawObjectList *renderLists, FieldShadow *hud)
{
    CFieldPlayer *player = (CFieldPlayer *)MAIN_BSS_0210CA40->ov0_02123060(0);
    if (player->ov0_0213416C()) {
        return;
    }
    if (m_actors == NULL) {
        return;
    }
    SaveData *save = &MAIN_BSS_020B26A0;
    for (int i = 0; i < m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)m_actors[i];
        if (partner == NULL || !partner->IsActive()) {
            continue;
        }
        if (save->m_areaType == 4 && partner->IsKind0() && !(partner->m_flags & 0x20)) {
            continue;
        }
        partner->Draw(renderLists, hud);
    }
}

static inline void SetUnk70(CFieldActor *actor, fx32 x, fx32 y)
{
    actor->unk_70 = x;
    actor->unk_74 = y;
}

int CFieldPartnerManage::ov0_02139920(u32 id, u16 kind, u16 flags, int type, int arg5)
{
    for (int i = 0; i < m_count; i++) {
        if (Get(i) != NULL || unk_8C == NULL) {
            continue;
        }
        CFieldPartner *partner;
        void *script;
        FieldData *table = MAIN_BSS_0210CA6C;
        if (type == 1) {
            FieldNpcData *data = FieldData_GetNpc(table, kind);
            partner = new CFieldPartnerNpc();
            partner->unk_200 = kind;
            partner->CreateDrawObject(1, data->unk_00, 0, flags, arg5);
            script = unk_8C->unk_2C[0];
            partner->unk_1E8 = unk_84;
            partner->unk_1FC = 1;
            partner->SetId((id & 0xFFFFFF) | 0x5000000);
            unk_84++;
            ov0_0213A2B4();
            SetUnk70(partner, data->unk_02 << FX32_SHIFT, data->unk_03 << FX32_SHIFT);
        } else {
            FieldEnemyData *data = FieldData_GetEnemy(table, kind);
            UnkStruct_020107A8 *info = PokeIdTable_Get(s_game->unk_1434, kind);
            CFieldPartnerPokemon *pokemon = new CFieldPartnerPokemon();
            pokemon->unk_EC.unk_B0 = pokemon->unk_268 = info->unk_00;
            pokemon->unk_E8 = (int)data;
            pokemon->unk_EC.unk_6C = *data;
            pokemon->unk_EC.unk_68 = pokemon->unk_EC.unk_6C.unk_30;
            pokemon->unk_EC.unk_64 = pokemon->unk_EC.unk_6C.unk_1C;
            pokemon->unk_EC.unk_6C.unk_16 += MATH_Rand16(&MAIN_BSS_0210CEC8, 0xB6);
            script = unk_8C->unk_2C[1];
            pokemon->unk_200 = kind;
            u16 pokemonFlags = flags;
            if (data->unk_30 == 2 || data->unk_30 == 5) {
                pokemonFlags |= 0xC00;
            }
            pokemon->CreateDrawObject(0, info->unk_00, info->unk_02, pokemonFlags, arg5);
            pokemon->unk_1FC = 0;
            pokemon->SetId((id & 0xFFFFFF) | 0x6000000);
            pokemon->SetUnkBC(info->unk_0A, info->unk_0B);
            pokemon->SetUnkBE(info->unk_0C, info->unk_0D);
            pokemon->ov0_0213E3E4(info->unk_00, info->unk_02);
            Rectangle bounds = { { info->unk_07 << FX32_SHIFT, info->unk_08 << FX32_SHIFT },
                { info->unk_09 << FX32_SHIFT, info->unk_09 << FX32_SHIFT } };
            pokemon->unk_24.pos.x = bounds.pos.x;
            pokemon->unk_24.pos.y = bounds.pos.y;
            pokemon->unk_24.size.x = bounds.size.x;
            pokemon->unk_24.size.y = bounds.size.y;
            pokemon->m_bushMode = info->unk_0E;
            pokemon->unk_D6 = info->unk_0F;
            SetUnk70(pokemon, data->unk_3D << FX32_SHIFT, data->unk_3E << FX32_SHIFT);
            ov0_0213A57C(kind, pokemon);
            pokemon->SetLayer(MAIN_BSS_0210CA40->ov0_02123060(0)->m_layer);
            if (HasPartnerIndex(kind)) {
                pokemon->unk_1E8 = unk_84;
                ov0_0213A2B4();
            } else {
                pokemon->unk_1E8 = unk_84 + unk_88;
            }
            unk_88++;
            partner = pokemon;
        }
        if (!partner->SetScriptBlock(script)) {
            LogError("SetScript ERROR by FieldPartnerMange.cpp");
        } else {
            partner->RunScriptLabel("main");
            partner->unk_0C = TRUE;
        }
        if (Set(i, partner)) {
            return i;
        }
        delete partner;
    }
    return -1;
}

void CFieldPartnerManage::ov0_02139E14(int mode)
{
    int prev = unk_94;
    unk_94 = mode;
    for (int i = 0; i < m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)Get(i);
        if (partner != NULL) {
            partner->SetUnk1EC(mode);
        }
    }
    if (mode == 1 && prev != unk_94) {
        ov0_0213B1BC();
        ov0_0213B340();
    }
}

void CFieldPartnerManage::ov0_02139E9C()
{
    for (int i = 0; i < m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)Get(i);
        if (partner != NULL && partner->IsNpc() && partner->m_drawObject->m_actor != NULL) {
            partner->m_drawObject->m_actor->m_motion.m_mode = 0;
        }
    }
}

void CFieldPartnerManage::ov0_02139F10(BOOL arg)
{
    for (int i = 0; i < m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)Get(i);
        if (partner != NULL && partner->IsKind0()) {
            if (arg) {
                partner->unk_1CC &= ~1;
            } else {
                partner->unk_1CC |= 1;
            }
        }
    }
}

void CFieldPartnerManage::ov0_02139F98(fx32 x, fx32 y, int dir)
{
    int count = m_count;
    for (int i = 0; i < count; i++) {
        CFieldPartner *partner = (CFieldPartner *)Get(i);
        if (partner != NULL) {
            partner->SetPosXY(x, y);
            partner->SetLayer(dir);
            partner->sub_02032A44(1);
        }
    }
}

void CFieldPartnerManage::ov0_0213A050(u32 id)
{
    int result = ov0_0213A084(id);
    if (result < 0) {
        return;
    }
    if (((result >> 24) & 0xFF) == 2) {
        return;
    }
    FieldSubScreen *obj = FieldSubScreen::GetInstance();
    if (obj != NULL) {
        obj->sub_02022B20();
    }
}

inline BOOL CFieldPartnerManage::RemovePartner(u32 target)
{
    u32 kind;
    u32 id;
    u32 type = ((s32)target >> 24) & 0xFF;
    if (type == 2) {
        id = (target & 0xFFFFFF) | 0x5000000;
        kind = 1;
    } else if (type == 1) {
        id = (target & 0xFFFFFF) | 0x6000000;
        kind = 0;
    } else {
        return FALSE;
    }
    for (int i = 0; i < m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)Get(i);
        if (partner != NULL && id == partner->m_id && kind == partner->unk_1FC) {
            if (Remove(i)) {
                if (kind == 1) {
                    unk_84--;
                    LogInfo("%d", unk_84);
                } else if (kind == 0) {
                    unk_88--;
                    LogInfo("%d", unk_88);
                }
                return TRUE;
            }
            return FALSE;
        }
    }
    return FALSE;
}

int CFieldPartnerManage::ov0_0213A084(u32 id)
{
    // `target` first holds the type: reused, its id range becomes a late split temp (colored after the inlines'
    // locals); the int -> u32 copy keeps copy propagation from removing the first range.
    int target = ((s32)id >> 24) & 0xFF;
    u32 type = target;
    target = id;
    if (type == 5) {
        target = (id & 0xFFFFFF) | 0x2000000;
    } else if (type == 6) {
        target = (id & 0xFFFFFF) | 0x1000000;
    }
    CFieldPartner *partner = FindPartner(target);
    if (partner == NULL) {
        LogError("not find actorid %x", id);
        return -1;
    }
    int order = partner->unk_1E8;
    if (RemovePartner(target)) {
        for (int i = 0; i < m_count; i++) {
            CFieldPartner *other = (CFieldPartner *)Get(i);
            if (other != NULL && other->unk_1E8 > order) {
                other->unk_1E8--;
            }
        }
    }
    return target;
}

void CFieldPartnerManage::ov0_0213A2B4()
{
    for (int i = 0; i < m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)Get(i);
        if (partner != NULL && partner->IsKind0()) {
            partner->unk_1E8++;
        }
    }
}

BOOL CFieldPartnerManage::Clear()
{
    unk_84 = 0;
    unk_88 = 0;
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL && scene->m_hpGauge != NULL) {
        scene->m_hpGauge->SetPartnerVisible(FALSE);
    }
    return CFieldActorManage::Clear();
}

void CFieldPartnerManage::ov0_0213A360(u32 id, u16 kind, u16 flags, int type, int arg5)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    if (type == 1) {
        for (int i = 0; i < 3; i++) {
            PartnerSlot *slot = save->GetPartner(i);
            if (slot != NULL && slot->unk_00 == 0) {
                SavePartner_Clear(slot);
                slot->unk_00 = 1;
                slot->unk_04 = id;
                slot->unk_08 = kind;
                ov0_02139920(id, kind, flags, type, arg5);
                FieldActorManage_RestartAllScripts(this);
                return;
            }
        }
    } else if (type == 0) {
        u32 newId = 0;
        for (int i = 0; i < 0xFFF; i++) {
            if (!SaveData_IsInParty(save, 0xFFF, i)) {
                newId = (i & 0xFFF) | 0x1FFF000;
                break;
            }
        }
        if (newId != 0) {
            SaveData_AddToParty(save, newId, kind, -1);
            ov0_02139920(newId, kind, flags, type, arg5);
        }
        FieldActorManage_RestartAllScripts(this);
    }
}

u32 CFieldPartnerManage::ov0_0213A4C4(u32 kind)
{
    int i;
    int count = m_count;
    for (i = 0; i < count; i++) {
        CFieldPartner *partner = (CFieldPartner *)(count <= i ? NULL : m_actors[i]);
        if (partner != NULL && partner->unk_1FC == 1 && kind == partner->unk_200) {
            return partner->m_id;
        }
    }
    return 0;
}

u32 CFieldPartnerManage::ov0_0213A520(u32 kind)
{
    int i;
    int count = m_count;
    for (i = 0; i < count; i++) {
        CFieldPartner *partner = (CFieldPartner *)(count <= i ? NULL : m_actors[i]);
        if (partner != NULL && partner->unk_1FC == 0 && kind == partner->unk_200) {
            return partner->m_id;
        }
    }
    return 0;
}

BOOL CFieldPartnerManage::ov0_0213A57C(u16 kind, CFieldPartner *partner)
{
    if (HasPartnerIndex(kind)) {
        partner->m_flags |= 0x30;
        CFieldScene *scene = MAIN_BSS_0210CA40;
        if (scene != NULL) {
            SaveData *save = &MAIN_BSS_020B26A0;
            CPlayerHPGauge *obj = scene->m_hpGauge;
            if (obj != NULL && save != NULL) {
                save->unk_0008 = ov0_0213A658(kind);
                obj->SetPartnerVisible(TRUE);
                obj->SetPartner(save->unk_0004 >> FX32_SHIFT, save->unk_0008);
                u8 mood = save->m_partnerMoods[PartnerKindToIndex(kind)];
                if (mood == 2) {
                    Actor_ShowManpu(partner, 0xB, -1);
                } else if (mood == 1) {
                    Actor_ShowManpu(partner, 0xA, -1);
                }
            }
        }
        return TRUE;
    }
    return FALSE;
}

int CFieldPartnerManage::ov0_0213A658(u16 kind)
{
    switch (kind) {
    case 0xD7:
    case 0x103:
        return 0x56;
    case 0xA4:
        return 0x80;
    case 0xA7:
        return 0x80;
    case 0xA1:
        return 0x80;
    case 0xBC:
    case 0x102:
        return 0x56;
    case 0xE2:
        return 0x80;
    case 0x1F:
        return 0x80;
    case 0xDC:
        return 0x80;
    case 0xD9:
        return 0x80;
    case 0xAA:
    case 0x101:
        return 0x56;
    case 0xD2:
        return 0x66;
    case 0xAF:
        return 0x66;
    case 0xB6:
        return 0x66;
    case 0x5C:
        return 0x80;
    case 0xD5:
        return 0x80;
    case 0x63:
        return 0x80;
    case 0xB7:
        return 0x66;
    }
    return 0;
}

void CFieldPartnerManage::ov0_0213A7FC(BOOL arg)
{
    int count = m_count;
    for (int i = 0; i < count; i++) {
        CFieldActor *actor = Get(i);
        if (actor != NULL) {
            if (arg) {
                actor->m_flags &= ~1;
            } else {
                actor->m_flags |= 1;
            }
        }
    }
}

void CFieldPartnerManage::func0(CFieldEffectManage *mgr)
{
    CFieldPartner *leader = (CFieldPartner *)FindLeader();
    CFieldScene *scene = MAIN_BSS_0210CA40;
    SaveData *save = &MAIN_BSS_020B26A0;
    if (leader != NULL && scene != NULL && save != NULL) {
        u8 mood = save->m_partnerMoods[PartnerKindToIndex(leader->unk_200)];
        if (mood == 2) {
            Actor_ShowManpu(leader, 0xB, -1);
        } else if (mood == 1) {
            Actor_ShowManpu(leader, 0xA, -1);
        }
    }
}
