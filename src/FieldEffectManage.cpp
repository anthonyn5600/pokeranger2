#include <nitro.h>

#include "UnkClass_020B26A0.hpp"
#include "field/CFieldEffectManage.hpp"
#include "file/CArchiveGuard.hpp"

#define SAFE_RELEASE(ptr)          \
    do {                           \
        if (ptr != NULL) {         \
            (ptr)->ov0_021423A4(); \
            ptr = NULL;            \
        }                          \
    } while (0)

struct UnkStruct_0210C1C0 {
    u8 unk_00[0x60];
    u8 unk_60;
    IFieldEffectDataBuilder *unk_64;
};

extern "C" {
void LogInfo(const char *fmt, ...);
}

extern UnkStruct_0210C1C0 MAIN_BSS_0210C1C0;
extern UnkClass_020B26A0 MAIN_BSS_020B26A0;

// Instantiated up front: the original emits it before the constructor (right after the stripped C2 copy).
template void TFieldEffectParticle<CSoftwareSprite>::ov0_021423E8(const FieldEffectSpriteRes &res);

// fake: an unreferenced global (own section, stripped by mwld) that only takes part in mwcc's size sort of the
// TU's data; it puts _ZTI18CFieldEffectManage before CResidentResource's typeinfo like the original.
u32 sFieldEffectManageUnused[4];

CFieldEffectManage::CFieldEffectManage(UnkClass_02143714 *listeners)
    : unk_77C(0)
{
    m_listeners = listeners;
    unk_87C = 0;
    unk_87D = 0;
    MAIN_BSS_0210CA60 = this;
    for (int i = 0; i < 0x80; i++) {
        m_effects[i] = NULL;
    }
    MI_CpuFill8(m_factories, 0, sizeof(m_factories));
    ov0_02143358();
    m_footStepSmoke.ov0_021509F4(m_resident.GetNcbr(0), m_resident.GetPalette(), m_resident.GetNcer(0));
    m_footStepSmoke.ov0_02150A04(m_resident.GetNcbr(0), m_resident.GetPalette(), m_resident.GetNcer(5), m_resident.GetCac(5));
    m_airBubbles.ov0_021423E8(
        FieldEffectSpriteRes(m_resident.GetNcbr(0), m_resident.GetPalette(), m_resident.GetNcer(7)));
    m_airBubbles.sub_0203312C(0, 8);
    for (int i = 0; i < 4; i++) {
        unk_780[i] = 0;
        unk_790[i] = 0;
    }
    MAIN_BSS_0210C1C0.unk_64 = this;
}

CFieldEffectManage::~CFieldEffectManage()
{
    MAIN_BSS_0210C1C0.unk_64 = NULL;
    ov0_02142F08();
    m_footStepSmoke.ov0_02150A94();
    for (int i = 0; i < 41; i++) {
        if (m_factories[i] != NULL) {
            m_factories[i]->Release(this);
        }
    }
    m_resident.Release();
    MAIN_BSS_0210CA60 = NULL;
}

int CFieldEffectManage::ov0_021428EC(int fps, BOOL arg1)
{
    int frames;
    if (fps <= 0) {
        frames = 1;
    } else {
        frames = 60 / fps;
    }
    unk_87C = arg1;
    for (int i = 0; i < 41; i++) {
        if (m_factories[i] != NULL) {
            m_factories[i]->Update(frames);
        }
    }
    for (u32 i = 0; i < m_resident.GetCount(); i++) {
        if (i != 8 && i != 9 && i != 10) {
            UnkClass_02008788 *cac = m_resident.GetCac(i);
            if (cac != NULL) {
                cac->sub_020089EC();
            }
        }
    }
    for (int i = 0; i < 0x80; i++) {
        if (m_effects[i] != NULL && m_effects[i]->ov0_02142264(frames) == 4) {
            for (int j = 0; j < 4; j++) {
                unk_780[j] -= m_effects[i]->ov0_0214239C(j);
            }
            SAFE_RELEASE(m_effects[i]);
        }
    }
    m_footStepSmoke.ov0_02142264(frames);
    m_damageIndication.ov0_02142264(frames);
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    // fake: the second read through another type keeps `save` a base register (the original's add #0x8000);
    // the backend merges the loads (as in Syscall's sub_02033934)
    if (save->unk_8B64 == 1 && *(u8 *)&save->unk_8B64 == 1) {
        m_airBubbles.ov0_02142264(frames);
    }
    return TRUE;
}

static inline void DrawEffect(int *budget, CFieldEffect *effect, Camera2D *camera)
{
    effect->ov0_02142344(camera);
    for (int j = 0; j < 4; j++) {
        budget[j] -= effect->ov0_0214239C(j);
    }
}

int CFieldEffectManage::ov0_02142D88(Camera2D *camera)
{
    for (int i = 0; i < 0x80; i++) {
        if (m_effects[i] != NULL) {
            DrawEffect(unk_790, m_effects[i], camera);
        }
    }
    DrawEffect(unk_790, &m_footStepSmoke, camera);
    DrawEffect(unk_790, &m_damageIndication, camera);
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    // fake: the second read through another type keeps `save` a base register (the original's add #0x8000);
    // the backend merges the loads (as in Syscall's sub_02033934)
    if (save->unk_8B64 == 1 && *(u8 *)&save->unk_8B64 == 1) {
        DrawEffect(unk_790, &m_airBubbles, camera);
    }
    return TRUE;
}

int CFieldEffectManage::ov0_02142F08()
{
    for (int i = 0; i < 0x80; i++) {
        SAFE_RELEASE(m_effects[i]);
    }
    for (int j = 0; j < 4; j++) {
        unk_780[j] = 0;
    }
    return TRUE;
}

u16 CFieldEffectManage::ov0_02142F6C(int kind, int arg)
{
    u16 id = 0;
    for (int i = 0; i < 0x80; i++) {
        if (m_effects[i] == NULL) {
            if (m_factories[kind] != NULL) {
                CFieldEffect *effect = m_factories[kind]->Create(arg);
                if (effect != NULL) {
                    m_effects[i] = effect;
                    for (int j = 0; j < 4; j++) {
                        unk_780[j] += effect->ov0_0214239C(j);
                    }
                    id = i | (effect->sub_02033028() << 8);
                }
            }
            break;
        }
    }
    return id;
}

u16 CFieldEffectManage::ov0_02143024(u16 id)
{
    u16 next = 0;
    int i = id != 0 ? (id & 0xFF) + 1 : 0;
    for (; i < 0x80; i++) {
        if (m_effects[i] != NULL) {
            next = i | (m_effects[i]->sub_02033028() << 8);
            break;
        }
    }
    return next;
}

CFieldEffect *CFieldEffectManage::ov0_02143088(u16 id)
{
    int idx = id & 0xFF;
    if (idx < 0x80) {
        CFieldEffect *effect = m_effects[idx];
        if (effect != NULL && ((id >> 8) & 0xFF) == effect->sub_02033028()) {
            return effect;
        }
    }
    return NULL;
}

BOOL CFieldEffectManage::ov0_021430D8(u16 id)
{
    int idx = id & 0xFF;
    if (idx < 0x80 && m_effects[idx] != NULL && ((id >> 8) & 0xFF) == m_effects[idx]->sub_02033028()) {
        for (int j = 0; j < 4; j++) {
            unk_780[j] -= m_effects[idx]->ov0_0214239C(j);
        }
        SAFE_RELEASE(m_effects[idx]);
        return TRUE;
    }
    return FALSE;
}

void CFieldEffectManage::ov0_0214318C(int kind, CFieldEffectFactory *factory)
{
    if (kind >= 0 && kind < 41) {
        m_factories[kind] = factory;
    }
}

BOOL CFieldEffectManage::ov0_021431A4(int kind, int arg1, int arg2, int arg3, const UnkStruct_02041D80 *table)
{
    int idx = -1;
    if (table == NULL) {
        return FALSE;
    }
    if (kind == 0 && unk_77C != 0) {
        switch (unk_77C) {
        case 1:
            idx = 2;
            break;
        case 2:
            idx = 3;
            break;
        case 3:
            idx = 0;
            break;
        case 4:
            idx = 1;
            break;
        }
    } else {
        switch (kind) {
        case 0:
            idx = (s8)table->unk_07;
            break;
        case 1:
            idx = (s8)table->unk_0B;
            break;
        case 2:
            idx = (s8)table->unk_0F;
            break;
        case 3:
            idx = (s8)table->unk_13;
            break;
        case 4:
            idx = (s8)table->unk_17;
            break;
        case 5:
            idx = (s8)table->unk_1B;
            break;
        case 6:
            idx = (s8)table->unk_1F;
            break;
        case 7:
            idx = (s8)table->unk_23;
            break;
        case 8:
            idx = (s8)table->unk_27;
            break;
        case 9:
            idx = (s8)table->unk_2B;
            break;
        case 10:
            idx = (s8)table->unk_2F;
            break;
        case 11:
            idx = (s8)table->unk_33;
            break;
        case 12:
            idx = (s8)table->unk_37;
            break;
        case 13:
            idx = (s8)table->unk_3B;
            break;
        case 14:
            idx = (s8)table->unk_3F;
            break;
        case 15:
        case 16:
        case 17:
        case 18:
            idx = (s8)table->unk_43;
            break;
        case 19:
        case 20:
        case 21:
        case 22:
            idx = (s8)table->unk_47;
            break;
        }
    }
    if (idx >= 0) {
        m_footStepSmoke.ov0_02150AE8(idx, arg1, arg2, arg3);
    }
    return TRUE;
}

int CFieldEffectManage::ov0_0214332C(int arg0, int arg1, CFieldPlayer *player)
{
    m_damageIndication.ov0_02164DB8(arg0, arg1, player);
    return TRUE;
}

void CFieldEffectManage::ov0_02143344(fx32 x, fx32 y)
{
    m_airBubbles.ov0_0216D050(x, y);
}

void CFieldEffectManage::ov0_02143358()
{
    m_resident.Load();
}

int CFieldEffectManage::ov0_0214336C(int layer, int budget)
{
    unk_790[layer] = budget;
    unk_7A0[layer] = budget;
    return unk_780[layer];
}

void CFieldEffectManage::ov0_02143380(UnkClass_0211E3FC *renderLists)
{
    m_footStepSmoke.ov0_02142398(renderLists);
    for (int i = 0; i < 0x80; i++) {
        if (m_effects[i] != NULL) {
            m_effects[i]->ov0_02142398(renderLists);
        }
    }
}

void CFieldEffectManage::ov0_021433D0()
{
    ov0_02142F08();
    for (int i = 0; i < 41; i++) {
        if (m_factories[i] != NULL) {
            m_factories[i]->Reset();
        }
    }
}

void CFieldEffectManage::ov0_02143410()
{
    m_listeners->ov0_0214378C(this);
}

void CFieldEffectManage::BuildData(void *buf, int size)
{
    LogInfo("CFieldEffectManage::BuildData()");
    u32 n = 0;
    CFieldEffect *list[3] = { NULL, NULL, NULL };
    for (int i = 0; i < 0x80; i++) {
        if (m_effects[i] != NULL) {
            int type = m_effects[i]->sub_02033028();
            if ((type == 0xC || type == 0xD || type == 0x12) && n < 3) {
                list[n] = m_effects[i];
                n++;
            }
        }
    }
    u8 *p = (u8 *)buf;
    u8 *end = p + size;
    for (int i = 0; i < 3; i++) {
        if (list[i] != NULL) {
            p += list[i]->ov0_02142390(p, end);
        }
    }
}

void CFieldEffectManage::ov0_021434F0()
{
    u8 data[0x20];
    if (!MAIN_BSS_0210C1C0.unk_60) {
        return;
    }
    u8 *p = MAIN_BSS_0210C1C0.unk_00;
    u8 *end = &MAIN_BSS_0210C1C0.unk_60;
    for (; p < end; p += 0x20) {
        MI_CpuCopy8(p, data, sizeof(data));
        ov0_02143568(data);
    }
    MAIN_BSS_0210C1C0.unk_60 = 0;
}

void CFieldEffectManage::ov0_02143568(const u8 *data)
{
    u16 id = 0;
    int type = data[0] & 0x3F;
    int sub = (data[0] >> 6) & 3;
    switch (type) {
    case 0xD:
        id = ov0_02142F6C(0xD, 0);
        break;
    case 0xC:
        id = ov0_02142F6C(0xC, 0);
        break;
    case 0x12: {
        int arg;
        switch (sub) {
        case 0:
            arg = 0x84;
            break;
        case 1:
            arg = 0x85;
            break;
        case 2:
            arg = 0x86;
            break;
        case 3:
            arg = 0x486;
            break;
        default:
            arg = -1;
            break;
        }
        if (arg >= 0) {
            id = ov0_02142F6C(0x12, arg);
        }
        break;
    }
    }
    if (id == 0) {
        return;
    }
    CFieldEffect *effect = ov0_02143088(id);
    if (effect == NULL) {
        return;
    }
    if (!effect->ov0_02142388(data)) {
        ov0_021430D8(id);
    }
}

void CFieldEffectManage::ov0_0214366C()
{
    for (int i = 0; i < 0x80; i++) {
        if (m_effects[i] != NULL) {
            int type = m_effects[i]->sub_02033028();
            if (type == 1 || type == 0x12 || type == 0xC || type == 0xD) {
                for (int j = 0; j < 4; j++) {
                    unk_780[j] -= m_effects[i]->ov0_0214239C(j);
                }
                m_effects[i]->ov0_021423A4();
                m_effects[i] = NULL;
            }
        }
    }
}

UnkClass_02143714::UnkClass_02143714()
{
    MI_CpuFill8(this, 0, sizeof(*this));
}

BOOL UnkClass_02143714::ov0_02143730(CFieldEffectManageEventListener *listener)
{
    BOOL added = FALSE;
    for (int i = 0; i < 4; i++) {
        if (m_listeners[i] == NULL) {
            m_listeners[i] = listener;
            added = TRUE;
            break;
        }
    }
    return added;
}

void UnkClass_02143714::ov0_02143760(CFieldEffectManageEventListener *listener)
{
    for (int i = 0; i < 4; i++) {
        if (m_listeners[i] != NULL && m_listeners[i] == listener) {
            m_listeners[i] = NULL;
        }
    }
}

void UnkClass_02143714::ov0_0214378C(CFieldEffectManage *mgr)
{
    for (int i = 0; i < 4; i++) {
        if (m_listeners[i] != NULL) {
            m_listeners[i]->func0(mgr);
        }
    }
}

CFieldEffectManage::CResidentResource::CResidentResource()
{
    m_texKey = 0;
    m_plttKey = 0;
}

CFieldEffectManage::CResidentResource::~CResidentResource()
{
    Release();
}

void CFieldEffectManage::CResidentResource::Load()
{
    CArchiveGuard guard("MEF", "data/Field/Effect/ef001_LZ.bin", 1, 1, 0, NULL, 0);
    char path[0x60];
    m_palette.sub_02007B60("MEF:ef001.NCLR", 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette.unk_04->szByte, FALSE, 0);
    m_palette.sub_02007BFC(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette.sub_02007BC4();
    m_ncbr.sub_02007590("MEF:ef001.NCBR", 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_ncbr.unk_38, FALSE, 0);
    m_ncbr.sub_020076E8(NNS_GfdGetTexKeyAddr(m_texKey));
    m_ncbr.sub_020076B0();
    for (int i = 0; i < 12; i++) {
        OS_SPrintf(path, "MEF:ef001_a%02d.NCER", i + 1);
        m_ncer[i] = new CNCERFile(path, 0, 0, 0);
        OS_SPrintf(path, "MEF:ef001_a%02d.cac", i + 1);
        m_cac[i] = new UnkClass_02008788(path);
    }
}

void CFieldEffectManage::CResidentResource::Release()
{
    if (m_texKey != 0) {
        NNS_GfdFreeLnkTexVram(m_texKey);
        m_texKey = 0;
    }
    if (m_plttKey != 0) {
        NNS_GfdFreeLnkPlttVram(m_plttKey);
        m_plttKey = 0;
    }
    for (int i = 0; i < 12; i++) {
        SAFE_DELETE(m_cac[i]);
        SAFE_DELETE(m_ncer[i]);
    }
}

UnkClass_020074D4 *CFieldEffectManage::CResidentResource::GetNcbr(int i)
{
    return &m_ncbr;
}

CNCERFile *CFieldEffectManage::CResidentResource::GetNcer(int i)
{
    if (i >= 0 && i < 12) {
        return m_ncer[i];
    }
    return NULL;
}

UnkClass_02008788 *CFieldEffectManage::CResidentResource::GetCac(int i)
{
    if (i >= 0 && i < 12) {
        return m_cac[i];
    }
    return NULL;
}

UnkClass_02007AA4 *CFieldEffectManage::CResidentResource::GetPalette()
{
    return &m_palette;
}

void CFieldEffectManage::CResidentResource::Update()
{
}

int CFieldEffectManage::CResidentResource::GetCount()
{
    return 12;
}

BOOL CFieldEffectManage::CResidentResource::IsLoaded()
{
    if (m_texKey != 0 && m_plttKey != 0) {
        return TRUE;
    }
    return FALSE;
}
