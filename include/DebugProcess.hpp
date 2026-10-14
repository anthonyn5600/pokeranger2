#ifndef POKERANGER2_DEBUGPROCESS_HPP
#define POKERANGER2_DEBUGPROCESS_HPP

#include <nitro.h>

#include "BGFontPrinter.hpp"
#include "common.hpp"

class DebugProcessManager;

class DebugProcess {
public:
    DebugProcess();
    ~DebugProcess();

    void Close();
    void SetChild(DebugProcess *child);
    DebugProcess *GetChild();
    void SetManager(DebugProcessManager *manager);
    DebugProcessManager *GetManager();
    BGFontPrinter *GetPrinter();

public:
    void (*unk_00)(DebugProcess *process);
    u16 (*unk_04)(DebugProcess *process);
    u32 unk_08[16];
    u16 unk_48;
    u16 unk_4A;
    u16 unk_4C;
    u16 unk_4E;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
    DebugProcess *unk_58;
    DebugProcess *unk_5C;
    DebugProcessManager *unk_60;
};

STATIC_SIZE_ASSERT(DebugProcess, 0x64);

class DebugProcessManager {
public:
    DebugProcessManager(BGFontPrinter *printer, u32 arg1);
    ~DebugProcessManager();

    void CloseAll();
    void Update();
    void Draw();
    void SetValue(int index, u32 value);
    u32 GetValue(int index);
    BGFontPrinter *GetPrinter();
    BOOL IsActive();
    void SetCurrent(DebugProcess *process);
    void SetFlags(u16 flags);

public:
    DebugProcess unk_00;
    DebugProcess *unk_64;
    BGFontPrinter *unk_68;
    u32 unk_6C;
    u16 unk_70;
    u32 unk_74[16];
};

STATIC_SIZE_ASSERT(DebugProcessManager, 0xB4);

#endif // POKERANGER2_DEBUGPROCESS_HPP
