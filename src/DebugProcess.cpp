#include "DebugProcess.hpp"

#include <nitro.h>

DebugProcess::DebugProcess()
{
    unk_48 = 0;
    unk_4A = 0;
    unk_4C = 0;
    unk_4E = 0;
    unk_50 = 0;
    unk_54 = 1;
    unk_00 = NULL;
    unk_04 = NULL;
    unk_58 = NULL;
    unk_5C = NULL;
    unk_60 = NULL;
    for (int i = 0; i < 16; i++) {
        unk_08[i] = 0;
    }
}

DebugProcess::~DebugProcess()
{
}

void DebugProcess::Close()
{
    if (&GetManager()->unk_00 != this) {
        DebugProcess *parent = unk_58;
        DebugProcess *child = parent->GetChild();
        SAFE_DELETE(child);
        parent->SetChild(NULL);
        parent->unk_50 = 1;
        GetManager()->SetCurrent(parent);
    }
    if (&GetManager()->unk_00 == this) {
        GetPrinter()->Printf(0, 0, "");
    }
    GetManager()->SetFlags(1);
}

void DebugProcess::SetChild(DebugProcess *child)
{
    unk_5C = child;
}

DebugProcess *DebugProcess::GetChild()
{
    return unk_5C;
}

void DebugProcess::SetManager(DebugProcessManager *manager)
{
    unk_60 = manager;
}

DebugProcessManager *DebugProcess::GetManager()
{
    return unk_60;
}

BGFontPrinter *DebugProcess::GetPrinter()
{
    return GetManager()->GetPrinter();
}

DebugProcessManager::DebugProcessManager(BGFontPrinter *printer, u32 arg1)
{
    unk_68 = printer;
    unk_6C = arg1;
    unk_00.SetChild(NULL);
    unk_00.SetManager(this);
    unk_64 = &unk_00;
    for (int i = 0; i < 16; i++) {
        unk_74[i] = 0;
    }
}

DebugProcessManager::~DebugProcessManager()
{
    CloseAll();
}

void DebugProcessManager::CloseAll()
{
    while (&unk_00 != unk_64) {
        unk_64->Close();
    }
    unk_70 = 1;
}

void DebugProcessManager::Update()
{
    if (!IsActive()) {
        return;
    }
    if (unk_64->unk_04 != NULL) {
        unk_70 |= unk_64->unk_04(unk_64);
    }
    Draw();
}

void DebugProcessManager::Draw()
{
    if (unk_70 == 0) {
        return;
    }
    DebugProcess *process = unk_00.GetChild();
    while (process != NULL) {
        if (unk_64->unk_00 != NULL) {
            process->unk_00(process);
        }
        process = process->GetChild();
    }
    unk_70 = 0;
}

void DebugProcessManager::SetValue(int index, u32 value)
{
    unk_74[index] = value;
}

u32 DebugProcessManager::GetValue(int index)
{
    return unk_74[index];
}

BGFontPrinter *DebugProcessManager::GetPrinter()
{
    return unk_68;
}

BOOL DebugProcessManager::IsActive()
{
    return &unk_00 != unk_64;
}

void DebugProcessManager::SetCurrent(DebugProcess *process)
{
    unk_64 = process;
}

void DebugProcessManager::SetFlags(u16 flags)
{
    unk_70 = flags;
}
