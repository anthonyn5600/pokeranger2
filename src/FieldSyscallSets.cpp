#include "FieldSyscallSets.hpp"

FieldSyscallSets::FieldSyscallSets()
{
    unk_00 = NULL;
    unk_04 = NULL;
    unk_08 = NULL; // unk_0C isn't cleared
    unk_10 = NULL;
    unk_14 = NULL;
    unk_18 = NULL;
}

FieldSyscallSets::~FieldSyscallSets()
{
    Release();
}

void FieldSyscallSets::Init()
{
    unk_00 = new FieldActorSyscalls();
    FieldActorSyscalls::Register();
    unk_04 = new FieldEnemySyscalls();
    FieldEnemySyscalls::Register();
    unk_08 = new FieldPlayerSyscalls();
    FieldPlayerSyscalls::Register();
    unk_0C = new FieldPartnerSyscalls();
    FieldPartnerSyscalls::Register();
    unk_10 = new FieldSyscalls();
    FieldSyscalls::Register();
    unk_14 = new UnkClass_0214B93C();
    UnkClass_0214B93C::Register();
    unk_18 = new FieldNpcSyscalls();
    FieldNpcSyscalls::Register();
}

void FieldSyscallSets::Release()
{
    SAFE_DELETE(unk_00);
    SAFE_DELETE(unk_04);
    SAFE_DELETE(unk_08);
    SAFE_DELETE(unk_0C);
    SAFE_DELETE(unk_10);
    SAFE_DELETE(unk_14);
    SAFE_DELETE(unk_18);
}
