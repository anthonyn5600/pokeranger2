#include "Log.hpp"

#include <string.h>

// SDK_FINALROM turns OS_Printf into a no-op macro, but the game still calls the real function
#undef OS_Printf

extern "C" void OS_Printf(const char *fmt, ...);

static LogConfig s_logConfig = { 0, 3 };

extern "C" void thunk_FUN_02064f9c(const char *text)
{
    OS_Printf(text);
}

extern "C" void sub_020441AC(const char *text)
{
}

extern "C" void Log_Flush(void)
{
    if (MAIN_BSS_0210CAB4.file == NULL) {
        return;
    }
    u32 len = MAIN_BSS_0210CAB4.pos - MAIN_BSS_0210CAC8;
    if (len != 0) {
        fwrite(MAIN_BSS_0210CAC8, len, 1, MAIN_BSS_0210CAB4.file);
        fflush(MAIN_BSS_0210CAB4.file);
    }
    MAIN_BSS_0210CAB4.pos = MAIN_BSS_0210CAC8;
}

extern "C" void Log_WriteFile(const char *text)
{
    if (MAIN_BSS_0210CAB4.file == NULL || *text == '\0') {
        return;
    }
    do {
        *MAIN_BSS_0210CAB4.pos++ = *text++;
        if (MAIN_BSS_0210CAB4.pos >= MAIN_BSS_0210CAC8 + sizeof(MAIN_BSS_0210CAC8)) {
            Log_Flush();
        }
    } while (*text != '\0');
}

extern "C" void Log_Write(const char *text)
{
    u32 outputs = s_logConfig.outputs;
    if (outputs & 4) {
        Log_WriteFile(text);
    }
    if (outputs & 2) {
        thunk_FUN_02064f9c(text);
    }
    if (outputs & 8) {
        sub_020441AC(text);
    }
    if ((outputs & 0x10) && MAIN_BSS_0210CAB4.callback != NULL) {
        MAIN_BSS_0210CAB4.callback(text, MAIN_BSS_0210CAB4.arg1, MAIN_BSS_0210CAB4.arg0);
    }
}

extern "C" void Log_VPrintln(const char *fmt, va_list args)
{
    char buf[0x200];
    vsprintf(buf, fmt, args);
    strcat(buf, "\n");
    Log_Write(buf);
}

extern "C" void Log_VPrint(const char *fmt, va_list args)
{
    char buf[0x200];
    vsprintf(buf, fmt, args);
    Log_Write(buf);
}

extern "C" void thunk_FUN_020442cc(const char *fmt, va_list args)
{
    Log_VPrintln(fmt, args);
}

extern "C" void Log_Println(const char *fmt, ...)
{
#ifdef PC_PORT
    va_list args;
    va_start(args, fmt);
    Log_VPrintln(fmt, args);
    va_end(args);
#else
    va_list args = (va_list)(&fmt + 1);
    Log_VPrintln(fmt, args);
#endif
}

extern "C" void thunk_FUN_02044308(const char *fmt, va_list args)
{
    Log_VPrint(fmt, args);
}
