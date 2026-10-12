#ifndef POKERANGER2_UNKCLASS_02040F34_HPP
#define POKERANGER2_UNKCLASS_02040F34_HPP

#include <nitro.h>

#include "common.hpp"

class CFieldDrawActorData;

class UnkClass_02040F34 {
public:
    UnkClass_02040F34();
    ~UnkClass_02040F34();

    CFieldDrawActorData *sub_02041008(int type, u16 id, int form, u16 mask, BOOL useTransfer);

public:
    int m_count;
    CFieldDrawActorData *m_data;
};

extern UnkClass_02040F34 *MAIN_BSS_0210CA64;

STATIC_SIZE_ASSERT(UnkClass_02040F34, 0x8);

#endif // POKERANGER2_UNKCLASS_02040F34_HPP
