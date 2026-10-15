#include "field/CFieldTargetObjectManage.hpp"

#include <nitro.h>

#include "FieldCannons.hpp"
#include "FieldDataRecords.hpp"
#include "SaveData.hpp"
#include "field/CFieldTargetObject.hpp"

extern FieldData *MAIN_BSS_0210CA6C;
extern SaveData MAIN_BSS_020B26A0;

extern "C" {
void LogError(const char *fmt, ...);
}

void CFieldTargetObjectManage::Alloc(int capacity)
{
    CFieldActorManage::Alloc(capacity);
    unk_10 = new FieldTargetObjectScriptCache();
}

void CFieldTargetObjectManage::Free()
{
    CFieldActorManage::Free();
    SAFE_DELETE(unk_10);
}

// Collision shape: unk_50 = 0 uses the rectangle at unk_34, 1 the circle at unk_44.
static inline void SetRect(CFieldActor *actor, Rectangle r)
{
    actor->unk_34.pos.x = r.pos.x;
    actor->unk_34.pos.y = r.pos.y;
    actor->unk_34.size.x = r.size.x;
    actor->unk_34.size.y = r.size.y;
}

static inline void SetCircle(CFieldActor *actor, Circle v)
{
    actor->unk_44 = v;
}

int CFieldTargetObjectManage::Create(int slot, u16 kind, u16 script, u16 touchScript, int arg5)
{
    if (m_actors != NULL) {
        int i;
        FieldData *table = MAIN_BSS_0210CA6C;
        SaveData *save = &MAIN_BSS_020B26A0;
        for (i = 0; i < m_count; i++) {
            if (Get(i) != NULL) {
                continue;
            }
            CFieldTargetObject *obj = new CFieldTargetObject();
            u32 id = slot & 0xFFF;
            id |= ((save->m_mapId & 0xFFF) << 12) | 0x3000000;
            obj->SetId(id);
            obj->unk_E8 = kind;
            FieldTargetObjectData *data = FieldData_GetTargetObject(table, kind);
            obj->CreateDrawObject(2, data->unk_00, data->unk_02, 0xE, arg5);
            obj->SetUnkBC(data->unk_13, data->unk_14);
            obj->SetUnkBE(data->unk_15, data->unk_16);
            if (data->unk_0E == 0) {
                SetRect(obj, (Rectangle) { { data->unk_0F << FX32_SHIFT, data->unk_10 << FX32_SHIFT }, { data->unk_11 << FX32_SHIFT, data->unk_12 << FX32_SHIFT } });
                obj->unk_50 = 0;
            } else {
                SetCircle(obj, (Circle) { { data->unk_0F << FX32_SHIFT, data->unk_10 << FX32_SHIFT }, data->unk_11 << FX32_SHIFT });
                obj->unk_50 = 1;
            }
            Rectangle bounds = { { data->unk_09 << FX32_SHIFT, data->unk_0A << FX32_SHIFT },
                { data->unk_0B << FX32_SHIFT, data->unk_0C << FX32_SHIFT } };
            obj->unk_24.pos.x = bounds.pos.x;
            obj->unk_24.pos.y = bounds.pos.y;
            obj->unk_24.size.x = bounds.size.x;
            obj->unk_24.size.y = bounds.size.y;
            if (unk_10 != NULL) {
                void *block;
                if (script != 0) {
                    block = unk_10->Get(script, FALSE);
                } else {
                    block = unk_10->Get(data->unk_06, FALSE);
                }
                if (block != NULL) {
                    if (!obj->SetScript(new CFieldTargetObjectActorScript(0x30), block)) {
                        LogError("SetScript  ERROR by FieldTargetObjectManage.cpp");
                    } else {
                        obj->unk_0C = TRUE;
                        obj->CallNormal();
                    }
                }
                if (touchScript != 0) {
                    block = unk_10->Get(touchScript, TRUE);
                    if (block != NULL) {
                        if (!obj->SetTouchScript(new CFieldTargetObjectActorScript(0x20), block)) {
                            LogError("SetTouchScript ERROR by FieldTargetObjectManage.cpp");
                        }
                    }
                }
            }
            switch (kind) {
            case 0x61:
            case 0x6E:
                obj->m_flags |= 0x1000;
                break;
            case 0xF3:
                ov0_02159D30(0);
                break;
            case 0x122:
                ov0_02159D30(1);
                break;
            }
            m_actors[i] = obj;
            return i;
        }
    }
    return -1;
}

BOOL CFieldTargetObjectManage::Clear()
{
    if (unk_10 != NULL) {
        unk_10->Clear();
    }
    return CFieldActorManage::Clear();
}

int CFieldTargetObjectManage::ov0_0213D564()
{
    int count = 0;
    for (int i = 0; i < m_count; i++) {
        CFieldTargetObject *obj = (CFieldTargetObject *)Get(i);
        if (obj != NULL && obj->unk_20 == 2) {
            switch (obj->unk_E8) {
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
                count++;
                break;
            }
        }
    }
    return count;
}
