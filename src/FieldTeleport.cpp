#include <nitro.h>

#include "FieldData.hpp"
#include "SaveData.hpp"
#include "UnkClass_02041D80.hpp"

extern FieldData *MAIN_BSS_0210CA6C;

// Teleport destination per area (the map's area id), -1 terminated; unknown areas use the first entry.
struct TeleportPoint {
    int area;
    u16 x;
    u16 y;
    u16 z;
};

static TeleportPoint sTeleportPoints[] = {
    { 0x00, 0x0000, 0x012F, 0x01CC },
    { 0x06, 0x0028, 0x00E0, 0x0324 },
    { 0x10, 0x0073, 0x0120, 0x0360 },
    { 0x13, 0x008C, 0x0190, 0x02D0 },
    { 0x17, 0x00B5, 0x0190, 0x0090 },
    { 0x18, 0x00C8, 0x0318, 0x00F0 },
    { 0x1C, 0x00E1, 0x0160, 0x0150 },
    { 0x1E, 0x010C, 0x00F0, 0x00B0 },
    { 0x24, 0x0131, 0x0140, 0x0310 },
    { 0x26, 0x0148, 0x0190, 0x01B0 },
    { 0x27, 0x0148, 0x0190, 0x01B0 },
    { -1, 0x0000, 0x0000, 0x0000 },
};

static inline void SetTeleportPos(SaveData *save, u16 x, u16 y, u16 z)
{
    save->unk_8B78 = x;
    save->unk_8B7A = y;
    save->unk_8B7C = z;
}

extern "C" {

TeleportPoint *ov0_02161F2C(int area)
{
    for (int i = 0; sTeleportPoints[i].area != -1; i++) {
        if (area == sTeleportPoints[i].area) {
            return &sTeleportPoints[i];
        }
    }
    return sTeleportPoints;
}

void ov0_02161F88(void)
{
    UnkStruct_02041D80 *map = FieldData_GetMap(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.m_mapId);
    TeleportPoint *point = ov0_02161F2C(map->unk_00);
    SetTeleportPos(&MAIN_BSS_020B26A0, point->x, point->y, point->z);
}

int ov0_02161FD4(int arg0)
{
    return 0;
}
}
