#ifndef POKERANGER2_FIELDSYSCALLSETS_HPP
#define POKERANGER2_FIELDSYSCALLSETS_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in ov0 (empty ctor/dtor)
class FieldActorSyscalls {
public:
    FieldActorSyscalls();
    ~FieldActorSyscalls();

    static void ov0_02149120(); // Script_RegisterSyscalls(0xB, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class FieldEnemySyscalls {
public:
    FieldEnemySyscalls();
    ~FieldEnemySyscalls();

    static void ov0_021485C8(); // Script_RegisterSyscalls(0xA, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class FieldPlayerSyscalls {
public:
    FieldPlayerSyscalls();
    ~FieldPlayerSyscalls();

    static void ov0_0214998C(); // Script_RegisterSyscalls(0xC, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class FieldPartnerSyscalls {
public:
    FieldPartnerSyscalls();
    ~FieldPartnerSyscalls();

    static void ov0_02149A7C(); // Script_RegisterSyscalls(0xD, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class FieldSyscalls {
public:
    FieldSyscalls();
    ~FieldSyscalls();

    static void ov0_02149E60(); // Script_RegisterSyscalls(0xE, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class UnkClass_0214B93C {
public:
    UnkClass_0214B93C();
    ~UnkClass_0214B93C();

    static void ov0_0214B944(); // Script_RegisterSyscalls(0xF, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class FieldNpcSyscalls {
public:
    FieldNpcSyscalls();
    ~FieldNpcSyscalls();

    static void ov0_0214B6F8(); // Script_RegisterSyscalls(0x10, handler table)
};

// Defined in ov0: owns one object of each class above
class FieldSyscallSets {
public:
    FieldSyscallSets();
    ~FieldSyscallSets();

    void ov0_0213D658();
    void ov0_0213D728();

public:
    FieldActorSyscalls *unk_00;
    FieldEnemySyscalls *unk_04;
    FieldPlayerSyscalls *unk_08;
    FieldPartnerSyscalls *unk_0C;
    FieldSyscalls *unk_10;
    UnkClass_0214B93C *unk_14;
    FieldNpcSyscalls *unk_18;
};

STATIC_SIZE_ASSERT(FieldSyscallSets, 0x1C);

#endif // POKERANGER2_FIELDSYSCALLSETS_HPP
