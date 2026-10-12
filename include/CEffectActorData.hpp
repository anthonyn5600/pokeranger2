#ifndef POKERANGER2_CEFFECTACTORDATA_HPP
#define POKERANGER2_CEFFECTACTORDATA_HPP

#include <nitro.h>
#include <nnsys.h>

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "UnkClass_02008788.hpp"
#include "common.hpp"
#include "file/CNCERFile.hpp"

class CEffectResource {
};

// Effect sprite resources (arm9_0201668C.s, 0x020294C0..)
class CEffectActorData : public CEffectResource {
public:
    struct Entry {
        Entry()
        {
            ncbr = NULL;
            ncer = NULL;
            cac = NULL;
            texKey = 0;
        }

        void Release();
        void AllocTex(BOOL immediate);
        void FreeTex();
        void sub_020294A8();

        UnkClass_020074D4 *ncbr;
        CNCERFile *ncer;
        UnkClass_02008788 *cac;
        NNSGfdTexKey texKey;
    };

    CEffectActorData()
    {
        m_entries = NULL;
        m_count = 0;
    }

    virtual ~CEffectActorData();
    virtual UnkClass_020074D4 *GetNcbr(int i);
    virtual CNCERFile *GetNcer(int i);
    virtual UnkClass_02008788 *GetCac(int i);
    virtual UnkClass_02007AA4 *GetPalette();
    virtual void Update();
    virtual int GetCount();
    virtual BOOL IsLoaded();

    u32 GetEntryCount() const
    {
        return m_count;
    }

    void Release();
    void sub_020295B0(BOOL immediate);
    void FreeVram();
    void sub_020296B0();

public:
    UnkClass_02007AA4 m_palette;
    NNSGfdPlttKey m_plttKey;
    Entry *m_entries;
    u32 m_count;
};

STATIC_SIZE_ASSERT(CEffectActorData, 0x34);

#endif // POKERANGER2_CEFFECTACTORDATA_HPP
