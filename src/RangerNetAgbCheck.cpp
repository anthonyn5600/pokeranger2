#include <nitro/ctrdg.h>

#include "common.hpp"

static u32 sAgbCodes[] = { 'B7AJ', 'B7BJ', 'B7CJ', 'B7DJ', 'B7EJ', 'B7JJ', 'B7KJ', 'B7LJ', 'B7NJ', 'B7OJ', 'B7PJ', 'B7QJ', 'B7RJ', 'B7SJ', 'B7TJ', 'B7UJ', 'B7VJ', 'B7WJ', 'B7XJ', 'B7YJ', 0 };

BOOL AgbCheck_IsValidGameCode()
{
    u32 i;
    u32 code;
    u32 c = CTRDG_GetAgbGameCode();
    code = ((c & 0xFF) << 24) | (((c >> 8) & 0xFF) << 16) | (((c >> 16) & 0xFF) << 8) | ((c >> 24) & 0xFF);
    for (i = 0; i < sAgbCodes[i]; i++) {
        if (code == sAgbCodes[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

// GBA cartridge check: Pokémon Ranger-series AGB game inserted? (maker code '01')
BOOL AgbCheck_IsValidCartridge()
{
    CTRDG_Init();
    if (!CTRDG_IsAgbCartridge()) {
        return FALSE;
    }
    CTRDG_Enable(TRUE);
    if (CTRDG_GetAgbMakerCode() != 0x3130) {
        return FALSE;
    }
    return AgbCheck_IsValidGameCode() ? TRUE : FALSE;
}

int AgbCheck_GetMissionNo()
{
    u32 v;
    if (!AgbCheck_IsValidCartridge()) {
        return -1;
    }
    CTRDG_Read32((const u32 *)0x08100004, &v);
    return v;
}
