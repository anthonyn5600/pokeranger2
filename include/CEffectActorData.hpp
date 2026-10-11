#ifndef POKERANGER2_CEFFECTACTORDATA_HPP
#define POKERANGER2_CEFFECTACTORDATA_HPP

#include <nitro.h>
#include <nnsys.h>

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "UnkClass_02008788.hpp"
#include "common.hpp"
#include "file/CNCERFile.hpp"

// Effect sprite resources (arm9_0201668C.s, 0x020294C0..)
class CEffectActorData {
public:
    struct Entry {
        Entry()
        {
            ncbr = NULL;
            ncer = NULL;
            cac = NULL;
            unk_0C = NULL;
        }

        UnkClass_020074D4 *ncbr;
        CNCERFile *ncer;
        UnkClass_02008788 *cac;
        void *unk_0C;
    };

    virtual ~CEffectActorData();

    void sub_020295B0(BOOL immediate);

public:
    UnkClass_02007AA4 m_palette;
    NNSGfdPlttKey m_plttKey;
    Entry *m_entries;
    int m_count;
};

STATIC_SIZE_ASSERT(CEffectActorData, 0x34);

#endif // POKERANGER2_CEFFECTACTORDATA_HPP
