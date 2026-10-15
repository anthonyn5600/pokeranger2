#include <nitro.h>

#include "SaveData.hpp"
#include "field/CFieldEffectManage.hpp"
#include "file/CArchiveGuard.hpp"

#define SAFE_RELEASE(ptr)     \
    do {                      \
        if (ptr != NULL) {    \
            (ptr)->Destroy(); \
            ptr = NULL;       \
        }                     \
    } while (0)

struct FieldEffectSaveBuffer {
    u8 unk_00[0x60];
    u8 unk_60;
    IFieldEffectDataBuilder *unk_64;
};

extern "C" {
void LogInfo(const char *fmt, ...);
}

extern FieldEffectSaveBuffer MAIN_BSS_0210C1C0;
extern SaveData MAIN_BSS_020B26A0;

// Instantiated up front: the original emits it before the constructor (right after the stripped C2 copy).
template void TFieldEffectParticle<CSoftwareSprite>::SetParticleRes(const FieldEffectSpriteRes &res);

// fake: an unreferenced global (own section, stripped by mwld) that only takes part in mwcc's size sort of the
// TU's data; it puts _ZTI18CFieldEffectManage before CResidentResource's typeinfo like the original.
u32 sFieldEffectManageUnused[4];

CFieldEffectManage::CFieldEffectManage(FieldEffectListeners *listeners)
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
    LoadResident();
    m_footStepSmoke.SetSmokeRes(m_resident.GetNcbr(0), m_resident.GetPalette(), m_resident.GetNcer(0));
    m_footStepSmoke.SetPuffRes(m_resident.GetNcbr(0), m_resident.GetPalette(), m_resident.GetNcer(5), m_resident.GetCac(5));
    m_airBubbles.SetParticleRes(
        FieldEffectSpriteRes(m_resident.GetNcbr(0), m_resident.GetPalette(), m_resident.GetNcer(7)));
    m_airBubbles.SetParam(0, 8);
    for (int i = 0; i < 4; i++) {
        unk_780[i] = 0;
        unk_790[i] = 0;
    }
    MAIN_BSS_0210C1C0.unk_64 = this;
}

CFieldEffectManage::~CFieldEffectManage()
{
    MAIN_BSS_0210C1C0.unk_64 = NULL;
    Clear();
    m_footStepSmoke.ReleasePuffs();
    for (int i = 0; i < 41; i++) {
        if (m_factories[i] != NULL) {
            m_factories[i]->Release(this);
        }
    }
    m_resident.Release();
    MAIN_BSS_0210CA60 = NULL;
}

int CFieldEffectManage::Update(int fps, BOOL arg1)
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
            CellAnimController *cac = m_resident.GetCac(i);
            if (cac != NULL) {
                cac->UpdateAll();
            }
        }
    }
    for (int i = 0; i < 0x80; i++) {
        if (m_effects[i] != NULL && m_effects[i]->Update(frames) == 4) {
            for (int j = 0; j < 4; j++) {
                unk_780[j] -= m_effects[i]->GetDrawCount(j);
            }
            SAFE_RELEASE(m_effects[i]);
        }
    }
    m_footStepSmoke.Update(frames);
    m_damageIndication.Update(frames);
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    // fake: the second read through another type keeps `save` a base register (the original's add #0x8000);
    // the backend merges the loads (as in Syscall's sub_02033934)
    if (save->m_areaType == 1 && *(u8 *)&save->m_areaType == 1) {
        m_airBubbles.Update(frames);
    }
    return TRUE;
}

static inline void DrawEffect(int *budget, CFieldEffect *effect, Camera2D *camera)
{
    effect->Render(camera);
    for (int j = 0; j < 4; j++) {
        budget[j] -= effect->GetDrawCount(j);
    }
}

int CFieldEffectManage::Render(Camera2D *camera)
{
    for (int i = 0; i < 0x80; i++) {
        if (m_effects[i] != NULL) {
            DrawEffect(unk_790, m_effects[i], camera);
        }
    }
    DrawEffect(unk_790, &m_footStepSmoke, camera);
    DrawEffect(unk_790, &m_damageIndication, camera);
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    // fake: the second read through another type keeps `save` a base register (the original's add #0x8000);
    // the backend merges the loads (as in Syscall's sub_02033934)
    if (save->m_areaType == 1 && *(u8 *)&save->m_areaType == 1) {
        DrawEffect(unk_790, &m_airBubbles, camera);
    }
    return TRUE;
}

int CFieldEffectManage::Clear()
{
    for (int i = 0; i < 0x80; i++) {
        SAFE_RELEASE(m_effects[i]);
    }
    for (int j = 0; j < 4; j++) {
        unk_780[j] = 0;
    }
    return TRUE;
}

u16 CFieldEffectManage::Create(int kind, int arg)
{
    u16 id = 0;
    for (int i = 0; i < 0x80; i++) {
        if (m_effects[i] == NULL) {
            if (m_factories[kind] != NULL) {
                CFieldEffect *effect = m_factories[kind]->Create(arg);
                if (effect != NULL) {
                    m_effects[i] = effect;
                    for (int j = 0; j < 4; j++) {
                        unk_780[j] += effect->GetDrawCount(j);
                    }
                    id = i | (effect->GetEffectId() << 8);
                }
            }
            break;
        }
    }
    return id;
}

u16 CFieldEffectManage::GetNext(u16 id)
{
    u16 next = 0;
    int i = id != 0 ? (id & 0xFF) + 1 : 0;
    for (; i < 0x80; i++) {
        if (m_effects[i] != NULL) {
            next = i | (m_effects[i]->GetEffectId() << 8);
            break;
        }
    }
    return next;
}

CFieldEffect *CFieldEffectManage::Get(u16 id)
{
    int idx = id & 0xFF;
    if (idx < 0x80) {
        CFieldEffect *effect = m_effects[idx];
        if (effect != NULL && ((id >> 8) & 0xFF) == effect->GetEffectId()) {
            return effect;
        }
    }
    return NULL;
}

BOOL CFieldEffectManage::Remove(u16 id)
{
    int idx = id & 0xFF;
    if (idx < 0x80 && m_effects[idx] != NULL && ((id >> 8) & 0xFF) == m_effects[idx]->GetEffectId()) {
        for (int j = 0; j < 4; j++) {
            unk_780[j] -= m_effects[idx]->GetDrawCount(j);
        }
        SAFE_RELEASE(m_effects[idx]);
        return TRUE;
    }
    return FALSE;
}

void CFieldEffectManage::SetFactory(int kind, CFieldEffectFactory *factory)
{
    if (kind >= 0 && kind < 41) {
        m_factories[kind] = factory;
    }
}

BOOL CFieldEffectManage::EmitFootStep(int kind, int arg1, int arg2, int arg3, const FieldMapData *table)
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
        m_footStepSmoke.Emit(idx, arg1, arg2, arg3);
    }
    return TRUE;
}

int CFieldEffectManage::ShowDamage(int arg0, int arg1, CFieldPlayer *player)
{
    m_damageIndication.Show(arg0, arg1, player);
    return TRUE;
}

void CFieldEffectManage::EmitAirBubbles(fx32 x, fx32 y)
{
    m_airBubbles.Emit(x, y);
}

void CFieldEffectManage::LoadResident()
{
    m_resident.Load();
}

int CFieldEffectManage::SetDrawBudget(int layer, int budget)
{
    unk_790[layer] = budget;
    unk_7A0[layer] = budget;
    return unk_780[layer];
}

void CFieldEffectManage::AddToRenderLists(DrawObjectList *renderLists)
{
    m_footStepSmoke.AddToRenderLists(renderLists);
    for (int i = 0; i < 0x80; i++) {
        if (m_effects[i] != NULL) {
            m_effects[i]->AddToRenderLists(renderLists);
        }
    }
}

void CFieldEffectManage::Reset()
{
    Clear();
    for (int i = 0; i < 41; i++) {
        if (m_factories[i] != NULL) {
            m_factories[i]->Reset();
        }
    }
}

void CFieldEffectManage::NotifyListeners()
{
    m_listeners->Notify(this);
}

void CFieldEffectManage::BuildData(void *buf, int size)
{
    LogInfo("CFieldEffectManage::BuildData()");
    u32 n = 0;
    CFieldEffect *list[3] = { NULL, NULL, NULL };
    for (int i = 0; i < 0x80; i++) {
        if (m_effects[i] != NULL) {
            int type = m_effects[i]->GetEffectId();
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
            p += list[i]->SaveState(p, end);
        }
    }
}

void CFieldEffectManage::RestoreSavedEffects()
{
    u8 data[0x20];
    if (!MAIN_BSS_0210C1C0.unk_60) {
        return;
    }
    u8 *p = MAIN_BSS_0210C1C0.unk_00;
    u8 *end = &MAIN_BSS_0210C1C0.unk_60;
    for (; p < end; p += 0x20) {
        MI_CpuCopy8(p, data, sizeof(data));
        RestoreEffect(data);
    }
    MAIN_BSS_0210C1C0.unk_60 = 0;
}

void CFieldEffectManage::RestoreEffect(const u8 *data)
{
    u16 id = 0;
    int type = data[0] & 0x3F;
    int sub = (data[0] >> 6) & 3;
    switch (type) {
    case 0xD:
        id = Create(0xD, 0);
        break;
    case 0xC:
        id = Create(0xC, 0);
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
            id = Create(0x12, arg);
        }
        break;
    }
    }
    if (id == 0) {
        return;
    }
    CFieldEffect *effect = Get(id);
    if (effect == NULL) {
        return;
    }
    if (!effect->RestoreState(data)) {
        Remove(id);
    }
}

void CFieldEffectManage::ov0_0214366C()
{
    for (int i = 0; i < 0x80; i++) {
        if (m_effects[i] != NULL) {
            int type = m_effects[i]->GetEffectId();
            if (type == 1 || type == 0x12 || type == 0xC || type == 0xD) {
                for (int j = 0; j < 4; j++) {
                    unk_780[j] -= m_effects[i]->GetDrawCount(j);
                }
                m_effects[i]->Destroy();
                m_effects[i] = NULL;
            }
        }
    }
}

FieldEffectListeners::FieldEffectListeners()
{
    MI_CpuFill8(this, 0, sizeof(*this));
}

BOOL FieldEffectListeners::Add(CFieldEffectManageEventListener *listener)
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

void FieldEffectListeners::Remove(CFieldEffectManageEventListener *listener)
{
    for (int i = 0; i < 4; i++) {
        if (m_listeners[i] != NULL && m_listeners[i] == listener) {
            m_listeners[i] = NULL;
        }
    }
}

void FieldEffectListeners::Notify(CFieldEffectManage *mgr)
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
    m_palette.Load("MEF:ef001.NCLR", 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette.unk_04->szByte, FALSE, 0);
    m_palette.LoadToVram(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette.Release();
    m_ncbr.Load("MEF:ef001.NCBR", 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_ncbr.unk_38, FALSE, 0);
    m_ncbr.LoadToVram(NNS_GfdGetTexKeyAddr(m_texKey));
    m_ncbr.Release();
    for (int i = 0; i < 12; i++) {
        OS_SPrintf(path, "MEF:ef001_a%02d.NCER", i + 1);
        m_ncer[i] = new CNCERFile(path, 0, 0, 0);
        OS_SPrintf(path, "MEF:ef001_a%02d.cac", i + 1);
        m_cac[i] = new CellAnimController(path);
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

VramImage *CFieldEffectManage::CResidentResource::GetNcbr(int i)
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

CellAnimController *CFieldEffectManage::CResidentResource::GetCac(int i)
{
    if (i >= 0 && i < 12) {
        return m_cac[i];
    }
    return NULL;
}

VramPalette *CFieldEffectManage::CResidentResource::GetPalette()
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
