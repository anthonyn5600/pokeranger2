#ifndef POKERANGER2_FIELD_UNKCLASS_02151244_HPP
#define POKERANGER2_FIELD_UNKCLASS_02151244_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CPrimitiveNTF.hpp"

// NtfTexture with 4 more words, held by the effect factories (ov0; ctor 0x02151244, dtor 0x02151280).
class UnkClass_02151244 : public NtfTexture {
public:
    UnkClass_02151244()
    {
        // Same store as NtfTexture's last one, so the backend drops it; it still counts toward the 102-instruction
        // PCode block split of the effect registry ctor (FieldEffectFactories.cpp), which the original needs.
        m_ntfp = NULL;
        unk_1C = 0;
        unk_20 = 0;
        unk_24 = 0;
        unk_28 = 0;
    }

public:
    int unk_1C;
    int unk_20;
    int unk_24;
    int unk_28;
};

STATIC_SIZE_ASSERT(UnkClass_02151244, 0x2C);

#endif // POKERANGER2_FIELD_UNKCLASS_02151244_HPP
