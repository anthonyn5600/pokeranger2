#include "field/CFieldPartnerManage.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_02019284.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkClass_020B26A0.hpp"
#include "UnkStruct_020107A8.hpp"
#include "field/CFieldPartnerNpc.hpp"
#include "field/CFieldPartnerPokemon.hpp"
#include "field/CFieldPlayer.hpp"
#include "file/CBinaryFile.hpp"
#include "scene/CFieldScene.hpp"
#include "sub_02044440.hpp"

struct FieldNpcData {
    u16 unk_00;
    s8 unk_02;
    s8 unk_03;
};

extern CFieldScene *MAIN_BSS_0210CA40;
extern UnkClass_02041D80 *MAIN_BSS_0210CA6C;
extern UnkClass_020B26A0 MAIN_BSS_020B26A0;
extern MATHRandContext16 MAIN_BSS_0210CEC8;

extern "C" {
void LogError(const char *fmt, ...);
void LogInfo(const char *fmt, ...);
void sub_02044AC8(void *script);
FieldNpcData *sub_02041D44(UnkClass_02041D80 *obj, int kind);
FieldEnemyData *sub_02041D58(UnkClass_02041D80 *obj, int kind);
BOOL sub_02015434(UnkClass_020B26A0 *save, int mapId, int idx);
void sub_02015124(UnkStruct_020B26A0_8AD4 *partner);
void sub_02015C78(UnkClass_020B26A0 *save, u32 id, u16 kind, int arg3);
void sub_02041A70(CFieldActor *actor, int arg1, int arg2);
void sub_0203C590(CFieldActor *actor, UnkClass_0211E3FC *renderLists, UnkClass_020416AC *hud);
void sub_0203F440(CFieldActorManage *mgr);
BOOL sub_02034F9C(u32 kind);
int sub_02035088(u32 kind);
void *sub_020233A4(void);
void sub_02022B20(void *obj);
}

UnkClass_0213949C::UnkClass_0213949C()
{
    sub_02044440();
    for (int i = 0; i < 2; i++) {
        unk_24[i] = NULL;
        unk_2C[i] = NULL;
    }
    Load("data/Script/field/actor/FieldPartnerPokemonScript.fsb", 1);
    Load("data/Script/field/actor/FieldPartnerNpcScript.fsb", 0);
}

UnkClass_0213949C::~UnkClass_0213949C()
{
    for (int i = 0; i < 2; i++) {
        SAFE_DELETE(unk_24[i]);
    }
}

void UnkClass_0213949C::Load(const char *path, int idx)
{
    u32 heapId = s_game->unk_14A8;
    unk_24[idx] = new CBinaryFile(path, 0, 0, heapId, NULL, 0);
    unk_2C[idx] = unk_24[idx]->unk_4C;
    sub_02044AC8(unk_2C[idx]);
}

CFieldPartnerManage::CFieldPartnerManage()
{
    MAIN_BSS_0210CA4C = this;
    unk_0C = 4;
}

void CFieldPartnerManage::sub_0203EFE4(int capacity)
{
    CFieldActorManage::sub_0203EFE4(capacity);
    unk_8C = new UnkClass_0213949C();
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

void CFieldPartnerManage::sub_0203F034()
{
    CFieldActorManage::sub_0203F034();
    SAFE_DELETE(unk_8C);
}

void CFieldPartnerManage::sub_0203F2B0(CFieldMap *map, BOOL update)
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
        UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
        for (int i = 0; i < m_count; i++) {
            CFieldPartner *partner = (CFieldPartner *)m_actors[i];
            if (partner == NULL || !partner->IsActive()) {
                continue;
            }
            if (save->unk_8B64 == 4 && partner->IsKind0() && !(partner->unk_04 & 0x20)) {
                continue;
            }
            if (player->unk_110 & 3) {
                continue;
            }
            partner->sub_0203DA40(map);
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
            partner->sub_0203D578(map);
            partner->ov0_02139164();
        }
    }
}

void CFieldPartnerManage::sub_0203F348(UnkClass_0211E3FC *renderLists, UnkClass_020416AC *hud)
{
    CFieldPlayer *player = (CFieldPlayer *)MAIN_BSS_0210CA40->ov0_02123060(0);
    if (player->ov0_0213416C()) {
        return;
    }
    if (m_actors == NULL) {
        return;
    }
    UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
    for (int i = 0; i < m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)m_actors[i];
        if (partner == NULL || !partner->IsActive()) {
            continue;
        }
        if (save->unk_8B64 == 4 && partner->IsKind0() && !(partner->unk_04 & 0x20)) {
            continue;
        }
        sub_0203C590(partner, renderLists, hud);
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
        UnkClass_02041D80 *table = MAIN_BSS_0210CA6C;
        if (type == 1) {
            FieldNpcData *data = sub_02041D44(table, kind);
            partner = new CFieldPartnerNpc();
            partner->unk_200 = kind;
            sub_0203C418(partner, 1, data->unk_00, 0, flags, arg5);
            script = unk_8C->unk_2C[0];
            partner->unk_1E8 = unk_84;
            partner->unk_1FC = 1;
            partner->sub_0203DA60((id & 0xFFFFFF) | 0x5000000);
            unk_84++;
            ov0_0213A2B4();
            SetUnk70(partner, data->unk_02 << FX32_SHIFT, data->unk_03 << FX32_SHIFT);
        } else {
            FieldEnemyData *data = sub_02041D58(table, kind);
            UnkStruct_020107A8 *info = sub_020107A8(s_game->unk_1434, kind);
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
            sub_0203C418(pokemon, 0, info->unk_00, info->unk_02, pokemonFlags, arg5);
            pokemon->unk_1FC = 0;
            pokemon->sub_0203DA60((id & 0xFFFFFF) | 0x6000000);
            pokemon->SetUnkBC(info->unk_0A, info->unk_0B);
            pokemon->SetUnkBE(info->unk_0C, info->unk_0D);
            pokemon->ov0_0213E3E4(info->unk_00, info->unk_02);
            Rectangle bounds = { { info->unk_07 << FX32_SHIFT, info->unk_08 << FX32_SHIFT },
                { info->unk_09 << FX32_SHIFT, info->unk_09 << FX32_SHIFT } };
            pokemon->unk_24.pos.x = bounds.pos.x;
            pokemon->unk_24.pos.y = bounds.pos.y;
            pokemon->unk_24.size.x = bounds.size.x;
            pokemon->unk_24.size.y = bounds.size.y;
            pokemon->unk_D4 = info->unk_0E;
            pokemon->unk_D6 = info->unk_0F;
            SetUnk70(pokemon, data->unk_3D << FX32_SHIFT, data->unk_3E << FX32_SHIFT);
            ov0_0213A57C(kind, pokemon);
            pokemon->sub_0202E68C(MAIN_BSS_0210CA40->ov0_02123060(0)->unk_14);
            if (sub_02034F9C(kind)) {
                pokemon->unk_1E8 = unk_84;
                ov0_0213A2B4();
            } else {
                pokemon->unk_1E8 = unk_84 + unk_88;
            }
            unk_88++;
            partner = pokemon;
        }
        if (!partner->sub_0203C1B4(script)) {
            LogError("SetScript ERROR by FieldPartnerMange.cpp");
        } else {
            partner->sub_0203C22C("main");
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
        if (partner != NULL && partner->IsNpc() && partner->unk_08->unk_0C != NULL) {
            partner->unk_08->unk_0C->m_motion.m_mode = 0;
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
            partner->sub_0202E68C(dir);
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
    void *obj = sub_020233A4();
    if (obj != NULL) {
        sub_02022B20(obj);
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
        if (partner != NULL && id == partner->unk_58 && kind == partner->unk_1FC) {
            if (sub_0203F144(i)) {
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

BOOL CFieldPartnerManage::sub_0203F190()
{
    unk_84 = 0;
    unk_88 = 0;
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL && scene->unk_00D8 != NULL) {
        sub_0201A178(scene->unk_00D8, 0);
    }
    return CFieldActorManage::sub_0203F190();
}

void CFieldPartnerManage::ov0_0213A360(u32 id, u16 kind, u16 flags, int type, int arg5)
{
    UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
    if (type == 1) {
        for (int i = 0; i < 3; i++) {
            UnkStruct_020B26A0_8AD4 *slot = save->GetPartner(i);
            if (slot != NULL && slot->unk_00 == 0) {
                sub_02015124(slot);
                slot->unk_00 = 1;
                slot->unk_04 = id;
                slot->unk_08 = kind;
                ov0_02139920(id, kind, flags, type, arg5);
                sub_0203F440(this);
                return;
            }
        }
    } else if (type == 0) {
        u32 newId = 0;
        for (int i = 0; i < 0xFFF; i++) {
            if (!sub_02015434(save, 0xFFF, i)) {
                newId = (i & 0xFFF) | 0x1FFF000;
                break;
            }
        }
        if (newId != 0) {
            sub_02015C78(save, newId, kind, -1);
            ov0_02139920(newId, kind, flags, type, arg5);
        }
        sub_0203F440(this);
    }
}

u32 CFieldPartnerManage::ov0_0213A4C4(u32 kind)
{
    int i;
    int count = m_count;
    for (i = 0; i < count; i++) {
        CFieldPartner *partner = (CFieldPartner *)(count <= i ? NULL : m_actors[i]);
        if (partner != NULL && partner->unk_1FC == 1 && kind == partner->unk_200) {
            return partner->unk_58;
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
            return partner->unk_58;
        }
    }
    return 0;
}

BOOL CFieldPartnerManage::ov0_0213A57C(u16 kind, CFieldPartner *partner)
{
    if (sub_02034F9C(kind)) {
        partner->unk_04 |= 0x30;
        CFieldScene *scene = MAIN_BSS_0210CA40;
        if (scene != NULL) {
            UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
            UnkClass_02019284 *obj = scene->unk_00D8;
            if (obj != NULL && save != NULL) {
                save->unk_0008 = ov0_0213A658(kind);
                sub_0201A178(obj, 1);
                sub_0201A220(obj, (u16)(save->unk_0004 >> FX32_SHIFT), save->unk_0008);
                u8 mood = save->unk_0009[sub_02035088(kind)];
                if (mood == 2) {
                    sub_02041A70(partner, 0xB, -1);
                } else if (mood == 1) {
                    sub_02041A70(partner, 0xA, -1);
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
                actor->unk_04 &= ~1;
            } else {
                actor->unk_04 |= 1;
            }
        }
    }
}

void CFieldPartnerManage::func0()
{
    CFieldPartner *leader = (CFieldPartner *)FindLeader();
    CFieldScene *scene = MAIN_BSS_0210CA40;
    UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
    if (leader != NULL && scene != NULL && save != NULL) {
        u8 mood = save->unk_0009[sub_02035088(leader->unk_200)];
        if (mood == 2) {
            sub_02041A70(leader, 0xB, -1);
        } else if (mood == 1) {
            sub_02041A70(leader, 0xA, -1);
        }
    }
}
