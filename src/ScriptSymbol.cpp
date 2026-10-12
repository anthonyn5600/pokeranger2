#include <nitro.h>

#include "common.hpp"

// fsc script symbol names: 6 characters per u32, base 40
static char s_symbolChars[40] = { '\0', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_', '-', '/' };

extern "C" BOOL sub_0204439C(char *out, u32 value)
{
    BOOL ok = TRUE;
    for (int i = 5; i >= 0; i--) {
        char c = s_symbolChars[value % 40];
        out[i] = c;
        if (c == '\0') {
            ok = FALSE;
        }
        value /= 40;
    }
    out[6] = '\0';
    return ok;
}

extern "C" void sub_02044404(const u32 *values, char *out)
{
    int i = 0;
    while (i < 2 && sub_0204439C(out, values[i])) {
        i++;
        out += 6;
    }
}
