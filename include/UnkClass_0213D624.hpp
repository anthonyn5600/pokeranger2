#ifndef POKERANGER2_UNKCLASS_0213D624_HPP
#define POKERANGER2_UNKCLASS_0213D624_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in ov0 (empty ctor/dtor)
class UnkClass_02149118 {
public:
    UnkClass_02149118();
    ~UnkClass_02149118();

    static void ov0_02149120(); // sub_02044B38(0xB, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class UnkClass_021485C0 {
public:
    UnkClass_021485C0();
    ~UnkClass_021485C0();

    static void ov0_021485C8(); // sub_02044B38(0xA, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class UnkClass_02149984 {
public:
    UnkClass_02149984();
    ~UnkClass_02149984();

    static void ov0_0214998C(); // sub_02044B38(0xC, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class UnkClass_02149A74 {
public:
    UnkClass_02149A74();
    ~UnkClass_02149A74();

    static void ov0_02149A7C(); // sub_02044B38(0xD, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class UnkClass_02149E58 {
public:
    UnkClass_02149E58();
    ~UnkClass_02149E58();

    static void ov0_02149E60(); // sub_02044B38(0xE, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class UnkClass_0214B93C {
public:
    UnkClass_0214B93C();
    ~UnkClass_0214B93C();

    static void ov0_0214B944(); // sub_02044B38(0xF, handler table)
};

// Defined in ov0 (empty ctor/dtor)
class UnkClass_0214B6F0 {
public:
    UnkClass_0214B6F0();
    ~UnkClass_0214B6F0();

    static void ov0_0214B6F8(); // sub_02044B38(0x10, handler table)
};

// Defined in ov0: owns one object of each class above
class UnkClass_0213D624 {
public:
    UnkClass_0213D624();
    ~UnkClass_0213D624();

    void ov0_0213D658();
    void ov0_0213D728();

public:
    UnkClass_02149118 *unk_00;
    UnkClass_021485C0 *unk_04;
    UnkClass_02149984 *unk_08;
    UnkClass_02149A74 *unk_0C;
    UnkClass_02149E58 *unk_10;
    UnkClass_0214B93C *unk_14;
    UnkClass_0214B6F0 *unk_18;
};

STATIC_SIZE_ASSERT(UnkClass_0213D624, 0x1C);

#endif // POKERANGER2_UNKCLASS_0213D624_HPP
