#include "CellAnimInstance.hpp"

#include <nitro.h>

u16 g_animFps = 60;

fx32 sub_02007DE4(u16 value)
{
    return (s16)value << 4;
}

int GetDirectionIndex(int count, u16 dir, int arg2)
{
    switch (count) {
    case 4:
        if (arg2 != 0) {
            if (dir < 0x2000 || dir > 0xE000) {
                return 3;
            }
            if (dir <= 0x6000) {
                return 0;
            }
            if (dir < 0xA000) {
                return 1;
            }
            return 2;
        } else {
            if (dir < 0x4000) {
                return 3;
            }
            if (dir <= 0x8000) {
                return 0;
            }
            if (dir < 0xC000) {
                return 1;
            }
            return 2;
        }
    case 8:
        if (dir < 0x1000 || dir >= 0xF000) {
            return 6;
        }
        if (dir < 0x3000) {
            return 7;
        }
        if (dir < 0x5000) {
            return 0;
        }
        if (dir < 0x7000) {
            return 1;
        }
        if (dir < 0x9000) {
            return 2;
        }
        if (dir < 0xB000) {
            return 3;
        }
        if (dir < 0xD000) {
            return 4;
        }
        if (dir < 0xF000) {
            return 5;
        }
        break;
    case 2:
        if (dir > 0x8000) {
            return 1;
        }
        return 0;
    case 5:
        if (dir < 0x3000) {
            return 3;
        }
        if (dir < 0x5000) {
            return 4;
        }
        if (dir <= 0x8000) {
            return 0;
        }
        if (dir < 0xC000) {
            return 1;
        }
        return 2;
    case 7:
        if (dir < 0x1000 || dir >= 0xF000) {
            return 5;
        }
        if (dir < 0x3000) {
            return 3;
        }
        if (dir < 0x5000) {
            return 6;
        }
        if (dir < 0x7000) {
            return 0;
        }
        if (dir < 0x9000) {
            return 4;
        }
        if (dir < 0xC000) {
            return 1;
        }
        return 2;
    }
    return 0;
}

CellAnimInstance::CellAnimInstance(u32 arg0, u32 arg1)
{
    Init(arg0, arg1);
}

CellAnimInstance::~CellAnimInstance()
{
    if (unk_30 != NULL) {
        unk_30 = NULL;
    }
    SAFE_DELETE_ARRAY(unk_00);
    SAFE_DELETE_ARRAY(unk_04);
    SAFE_DELETE_ARRAY(unk_08);
}

u8 CellAnimInstance::GetCell()
{
    return unk_00[unk_11];
}

fx32 *CellAnimInstance::GetOffsets()
{
    return &unk_14;
}

int CellAnimInstance::GetStatus()
{
    if (unk_2F) {
        return -1;
    }
    if (unk_0E == unk_2C && unk_0C == 0) {
        return 0;
    }
    return 1;
}

void CellAnimInstance::SetSpeed(fx32 speed)
{
    unk_38 = speed;
}

void CellAnimInstance::Init(u32 arg0, u32 arg1)
{
    unk_00 = NULL;
    unk_04 = NULL;
    unk_08 = NULL;
    ClearFrames();
    unk_3C = arg0;
    unk_48 = arg1;
    unk_0C = 0;
    unk_0E = 0;
    unk_2C = 0;
    unk_10 = 0;
    unk_11 = 0;
    unk_2E = 0;
    unk_2F = 0;
    unk_14 = 0;
    unk_18 = 0;
    unk_24 = 0;
    unk_28 = 0;
    unk_1C = 0;
    unk_20 = 0;
    unk_30 = NULL;
    unk_34 = 0;
    SetSpeed(FX32_ONE);
}

BOOL CellAnimInstance::SetDirection(u16 dir)
{
    int index = GetDirectionIndex(unk_2E, dir, unk_48);
    if (unk_11 == index) {
        return FALSE;
    }
    if (unk_2E <= index) {
        return TRUE;
    }
    unk_0C = 0;
    unk_14 = 0;
    unk_18 = 0;
    unk_24 = 0;
    unk_28 = 0;
    unk_1C = 0;
    unk_20 = 0;
    unk_34 = 0;
    unk_11 = index;
    Step();
    return FALSE;
}

void CellAnimInstance::Restart()
{
    ClearFrames();
    unk_0C = 0;
    unk_0E = 0;
    unk_10 = 0;
    unk_14 = 0;
    unk_18 = 0;
    unk_24 = 0;
    unk_28 = 0;
    unk_1C = 0;
    unk_20 = 0;
    unk_34 = 0;
    Step();
}

BOOL CellAnimInstance::SetAnim(int index)
{
    if (unk_11 == index) {
        return FALSE;
    }
    if (unk_2E <= index) {
        return TRUE;
    }
    ClearFrames();
    unk_0C = 0;
    unk_0E = 0;
    unk_10 = 0;
    unk_14 = 0;
    unk_18 = 0;
    unk_24 = 0;
    unk_28 = 0;
    unk_1C = 0;
    unk_20 = 0;
    unk_34 = 0;
    unk_11 = index;
    Step();
    return FALSE;
}

void CellAnimInstance::Step()
{
    if (unk_30 == NULL) {
        return;
    }
    if (unk_3C == 0) {
        StepSimple();
        return;
    }
    if (unk_0C != 0) {
        unk_0C--;
        if (unk_24 != 0) {
            unk_1C += unk_24;
        }
        if (unk_28 != 0) {
            unk_20 += unk_28;
        }
        if (unk_1C != 0) {
            unk_14 += unk_1C;
        }
        if (unk_20 != 0) {
            unk_18 += unk_20;
        }
        if (unk_0C != 0) {
            return;
        }
    }
    if (!unk_2F && unk_0E >= unk_2C) {
        return;
    }
    if (unk_0E == 0) {
        unk_14 = 0;
        unk_18 = 0;
        unk_24 = 0;
        unk_28 = 0;
        unk_1C = 0;
        unk_20 = 0;
    }
    while (TRUE) {
        u16 pos = unk_2C * unk_11 + unk_0E;
        switch (unk_30[pos].op) {
        case 0:
            break;
        case 1:
            for (int i = 0; i < unk_2E; i++) {
                unk_00[i] = unk_30[unk_2C * i + unk_0E].arg;
                unk_04[i] = unk_30[unk_2C * i + unk_0E].arg >> 8;
                if (unk_08[i] == 0xFF) {
                    unk_08[i] = unk_00[i];
                }
                if (unk_04[i] & 0x80) {
                    if (unk_10 != 0) {
                        unk_04[i] = unk_08[i];
                    } else {
                        unk_04[i] &= 0x7F;
                    }
                }
            }
            break;
        case 2:
            unk_0C = unk_30[pos].arg;
            unk_0E++;
            if (unk_0E < unk_2C) {
                return;
            }
            if (unk_2F) {
                unk_0E = 0;
            } else {
                unk_0E = unk_2C;
            }
            return;
        case 3:
            unk_10 = unk_30[pos].arg;
            for (int i = 0; i < unk_2E; i++) {
                unk_08[i] = 0xFF;
            }
            break;
        case 4:
            if (unk_10 != 0) {
                unk_0E = unk_30[pos].arg;
                unk_10--;
            }
            break;
        case 5:
            unk_1C = sub_02007DE4(unk_30[pos].arg);
            break;
        case 6:
            unk_20 = sub_02007DE4(unk_30[pos].arg);
            break;
        case 7:
            unk_24 = sub_02007DE4(unk_30[pos].arg);
            break;
        case 8:
            unk_28 = sub_02007DE4(unk_30[pos].arg);
            break;
        }
        unk_0E++;
        if (unk_0E >= unk_2C) {
            if (unk_2F) {
                unk_0E = 0;
            } else {
                unk_0E = unk_2C;
                return;
            }
        }
    }
}

void CellAnimInstance::StepSimple()
{
    if (unk_0C != 0 && --unk_0C != 0) {
        return;
    }
    if (!unk_2F && unk_0E >= unk_2C) {
        return;
    }
    while (TRUE) {
        u16 pos = unk_2C * unk_11 + unk_0E;
        switch (unk_30[pos].op) {
        case 1:
            for (int i = 0; i < unk_2E; i++) {
                unk_00[i] = unk_30[unk_2C * i + unk_0E].arg;
            }
            break;
        case 2:
            unk_0C = unk_30[pos].arg;
            unk_0E++;
            if (unk_0E < unk_2C) {
                return;
            }
            if (unk_2F) {
                unk_0E = 0;
            } else {
                unk_0E = unk_2C;
            }
            return;
        }
        unk_0E++;
        if (unk_0E >= unk_2C) {
            if (unk_2F) {
                unk_0E = 0;
            } else {
                unk_0E = unk_2C;
                return;
            }
        }
    }
}

void CellAnimInstance::Update()
{
    unk_34 += unk_38 * 60 / g_animFps;
    while (unk_34 >= FX32_ONE) {
        Step();
        unk_34 -= FX32_ONE;
    }
}

void CellAnimInstance::SetPrev(CellAnimInstance *prev)
{
    unk_44 = prev;
}

void CellAnimInstance::SetNext(CellAnimInstance *next)
{
    unk_40 = next;
}

CellAnimInstance *CellAnimInstance::GetPrev()
{
    return unk_44;
}

CellAnimInstance *CellAnimInstance::GetNext()
{
    return unk_40;
}

u16 CellAnimInstance::GetId()
{
    return unk_3E;
}

void CellAnimInstance::SetScript(AnimCmd *script, u16 length, u8 count, u8 loop)
{
    unk_30 = script;
    unk_2C = length;
    unk_2E = count;
    unk_2F = loop;
    unk_00 = new u8[unk_2E];
    unk_04 = new u8[unk_2E];
    unk_08 = new u8[unk_2E];
}

void CellAnimInstance::SetId(u16 id)
{
    unk_3E = id;
}

u8 CellAnimInstance::GetAnimCount()
{
    return unk_2E;
}
