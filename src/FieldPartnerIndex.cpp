#include "field/FieldPartnerIndex.hpp"

#include <nitro.h>

extern "C" void LogError(const char *fmt, ...);

u16 DAT_0208d58c = 60;

// Whether an enemy label has a partner index
BOOL sub_02034F9C(int kind)
{
    switch (kind) {
    case 0xD7:
    case 0xA4:
    case 0xA7:
    case 0xA1:
    case 0xBC:
    case 0xE2:
    case 0x1F:
    case 0xDC:
    case 0xD9:
    case 0xAA:
    case 0xD2:
    case 0xAF:
    case 0xB6:
    case 0x5C:
    case 0xD5:
    case 0x63:
    case 0xB7:
        return TRUE;
    }
    return FALSE;
}

// GetEnemyLabel2PartnerIndex
int sub_02035088(int kind)
{
    switch (kind) {
    case 0xD7:
    case 0x103:
        return 0;
    case 0xA4:
        return 1;
    case 0xA7:
        return 2;
    case 0xA1:
        return 3;
    case 0xBC:
    case 0x102:
        return 4;
    case 0xE2:
        return 5;
    case 0x1F:
        return 6;
    case 0xDC:
        return 7;
    case 0xD9:
        return 8;
    case 0xAA:
    case 0x101:
        return 9;
    case 0xD2:
        return 10;
    case 0xAF:
        return 11;
    case 0xB6:
        return 12;
    case 0x5C:
        return 13;
    case 0xD5:
        return 14;
    case 0x63:
        return 15;
    case 0xB7:
        return 16;
    }
    LogError("GetEnemyLabel2PartnerIndex(index= %d)", kind);
    return 0;
}

// GetPartnerIndex2EnemyLabel
int sub_02035240(int index)
{
    switch (index) {
    case 0:
        return 0xD7;
    case 1:
        return 0xA4;
    case 2:
        return 0xA7;
    case 3:
        return 0xA1;
    case 4:
        return 0xBC;
    case 5:
        return 0xE2;
    case 6:
        return 0x1F;
    case 7:
        return 0xDC;
    case 8:
        return 0xD9;
    case 9:
        return 0xAA;
    case 10:
        return 0xD2;
    case 11:
        return 0xAF;
    case 12:
        return 0xB6;
    case 13:
        return 0x5C;
    case 14:
        return 0xD5;
    case 15:
        return 0x63;
    case 16:
        return 0xB7;
    }
    LogError("GetPartnerIndex2EnemyLabel(index= %d)", index);
    return 0;
}
