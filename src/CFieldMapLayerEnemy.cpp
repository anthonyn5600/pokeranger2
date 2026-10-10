#include <nitro.h>
#include <string.h>

#include "UnkClass_020B26A0.hpp"
#include "field/CFieldEnemy.hpp"
#include "field/CFieldEnemyManage.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "heap.hpp"

extern UnkClass_020B26A0 MAIN_BSS_020B26A0;

extern "C" {
int ov0_02135E30(CFieldEnemyManage *manage, int slot, int arg2, int arg3, int arg4);
BOOL sub_02015434(UnkClass_020B26A0 *save, int mapId, int idx);
}

BOOL CFieldMapLayerEnemy::Load(void *data)
{
    LoadEntries(data);
    CFieldEnemyManage *manage = MAIN_BSS_0210CA5C;
    if (manage != NULL) {
        int base = manage->CountActors();
        for (int i = 0; i < m_count; i++) {
            int slot = ov0_02135E30(manage, base + i, m_entries[i].unk_06, m_entries[i].unk_08, 0);
            if (slot >= 0) {
                u16 dir = (m_entries[i].dir + 1) << 14;
                CFieldEnemy *enemy = (CFieldEnemy *)manage->Get(slot);
                fx32 y = m_entries[i].y << FX32_SHIFT;
                // Reusing slot makes this x a split live range, which gets the original's spill slot.
                slot = m_entries[i].x << FX32_SHIFT;
                enemy->SetPosXY(slot, y);
                enemy->sub_020128EC_(dir);
                enemy->unk_158.x = FX_CosIdx(dir);
                enemy->unk_158.y = FX_SinIdx(dir);
                enemy->unk_198 = enemy->GetUnk158();
                enemy->sub_0201287C_();
                enemy->unk_256 = dir;
                fx32 x = m_entries[i].x << FX32_SHIFT;
                y = m_entries[i].y << FX32_SHIFT;
                enemy->unk_18 = x;
                enemy->unk_1C = y;
                enemy->unk_E0 = MAIN_BSS_020B26A0.unk_001A;
                enemy->sub_0202E68C(unk_08);
                if (!sub_02015434(&MAIN_BSS_020B26A0, MAIN_BSS_020B26A0.unk_001A, base + i) && m_entries[i].hidden == 1) {
                    enemy->unk_20 = 2;
                } else {
                    sub_02041C1C(enemy);
                    enemy->unk_20 = 0;
                    enemy->sub_0202D394();
                }
                if (m_entries[i].hidden == 2) {
                    enemy->unk_244 = TRUE;
                } else {
                    enemy->unk_244 = FALSE;
                }
            } else {
                OS_Terminate();
            }
        }
    }
    return TRUE;
}

BOOL CFieldMapLayerEnemy::LoadEntries(void *data)
{
    u8 *p = (u8 *)data;
    int count;

    memcpy(&count, p, 4);
    p += 4;
    m_entries = (FieldMapNpcEntry *)Heap_AllocWithAlignment(count * sizeof(FieldMapNpcEntry), 4);
    m_count = count;
    for (int i = 0; i < count; i++) {
        memcpy(&m_entries[i].x, p, 2);
        memcpy(&m_entries[i].y, p + 2, 2);
        m_entries[i].dir = p[4];
        m_entries[i].hidden = p[5];
        memcpy(&m_entries[i].unk_06, p + 6, 2);
        memcpy(&m_entries[i].unk_08, p + 8, 2);
        m_entries[i].unk_0A = 1;
        m_entries[i].unk_0B = 0;
        p += 10;
    }
    return TRUE;
}

int CFieldMapLayerEnemy::GetType()
{
    return 9;
}

CFieldMapLayerEnemy::~CFieldMapLayerEnemy()
{
}
