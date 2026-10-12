#ifndef POKERANGER2_LOG_HPP
#define POKERANGER2_LOG_HPP

#include <nitro.h>
#include <stdarg.h>
#include <stdio.h>

#include "common.hpp"

typedef void (*LogCallback)(const char *text, void *arg1, void *arg0);

// MAIN_BSS_0210CAB4: buffered log file (flushed from MAIN_BSS_0210CAC8)
struct LogFile {
    char *pos;
    FILE *file;
    void *arg0;
    void *arg1;
    LogCallback callback;
};

// Output mask: 2 = OS_Printf, 4 = log file, 8 = unused, 0x10 = callback
struct LogConfig {
    u32 unk_00;
    u32 outputs;
};

extern "C" {
extern LogFile MAIN_BSS_0210CAB4;
extern char MAIN_BSS_0210CAC8[0x400];

void thunk_FUN_02064f9c(const char *text);
void sub_020441AC(const char *text);
void sub_020441B0(void);
void sub_02044200(const char *text);
void sub_02044260(const char *text);
void sub_020442CC(const char *fmt, va_list args);
void sub_02044308(const char *fmt, va_list args);
void thunk_FUN_020442cc(const char *fmt, va_list args);
void sub_02044340(const char *fmt, ...);
void thunk_FUN_02044308(const char *fmt, va_list args);
}

#endif // POKERANGER2_LOG_HPP
