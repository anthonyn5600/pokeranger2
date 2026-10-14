#ifndef POKERANGER2_FIELDDRAWACTORDATAPOOL_HPP
#define POKERANGER2_FIELDDRAWACTORDATAPOOL_HPP

#include <nitro.h>

#include "common.hpp"

class CFieldDrawActorData;

class FieldDrawActorDataPool {
public:
    FieldDrawActorDataPool();
    ~FieldDrawActorDataPool();

    CFieldDrawActorData *Acquire(int type, u16 id, int form, u16 mask, BOOL useTransfer);

public:
    int m_count;
    CFieldDrawActorData *m_data;
};

extern FieldDrawActorDataPool *MAIN_BSS_0210CA64;

STATIC_SIZE_ASSERT(FieldDrawActorDataPool, 0x8);

#endif // POKERANGER2_FIELDDRAWACTORDATAPOOL_HPP
