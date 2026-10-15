#ifndef POKERANGER2_FIELDSYSCALLSETS_HPP
#define POKERANGER2_FIELDSYSCALLSETS_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in ov0 (empty ctor/dtor)
class FieldActorSyscalls {
public:
    FieldActorSyscalls();
    ~FieldActorSyscalls();

    static void Register(); // Script_RegisterSyscalls(0xB, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class FieldEnemySyscalls {
public:
    FieldEnemySyscalls();
    ~FieldEnemySyscalls();

    static void Register(); // Script_RegisterSyscalls(0xA, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class FieldPlayerSyscalls {
public:
    FieldPlayerSyscalls();
    ~FieldPlayerSyscalls();

    static void Register(); // Script_RegisterSyscalls(0xC, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class FieldPartnerSyscalls {
public:
    FieldPartnerSyscalls();
    ~FieldPartnerSyscalls();

    static void Register(); // Script_RegisterSyscalls(0xD, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class FieldSyscalls {
public:
    FieldSyscalls();
    ~FieldSyscalls();

    static void Register(); // Script_RegisterSyscalls(0xE, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class UnkClass_0214B93C {
public:
    UnkClass_0214B93C();
    ~UnkClass_0214B93C();

    static void Register(); // Script_RegisterSyscalls(0xF, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class FieldNpcSyscalls {
public:
    FieldNpcSyscalls();
    ~FieldNpcSyscalls();

    static void Register(); // Script_RegisterSyscalls(0x10, handler table)
};

// Defined in ov0: owns one object of each class above
class FieldSyscallSets {
public:
    FieldSyscallSets();
    ~FieldSyscallSets();

    void Init();
    void Release();

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
