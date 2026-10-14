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
    ov0_0213D728();
}

void FieldSyscallSets::ov0_0213D658()
{
    unk_00 = new FieldActorSyscalls();
    FieldActorSyscalls::ov0_02149120();
    unk_04 = new FieldEnemySyscalls();
    FieldEnemySyscalls::ov0_021485C8();
    unk_08 = new FieldPlayerSyscalls();
    FieldPlayerSyscalls::ov0_0214998C();
    unk_0C = new FieldPartnerSyscalls();
    FieldPartnerSyscalls::ov0_02149A7C();
    unk_10 = new FieldSyscalls();
    FieldSyscalls::ov0_02149E60();
    unk_14 = new UnkClass_0214B93C();
    UnkClass_0214B93C::ov0_0214B944();
    unk_18 = new FieldNpcSyscalls();
    FieldNpcSyscalls::ov0_0214B6F8();
}

void FieldSyscallSets::ov0_0213D728()
{
    SAFE_DELETE(unk_00);
    SAFE_DELETE(unk_04);
    SAFE_DELETE(unk_08);
    SAFE_DELETE(unk_0C);
    SAFE_DELETE(unk_10);
    SAFE_DELETE(unk_14);
    SAFE_DELETE(unk_18);
}
