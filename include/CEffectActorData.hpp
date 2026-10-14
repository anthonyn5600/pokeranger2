#ifndef POKERANGER2_CEFFECTACTORDATA_HPP
#define POKERANGER2_CEFFECTACTORDATA_HPP

#include <nitro.h>
#include <nnsys.h>

#include "CellAnimController.hpp"
#include "VramImage.hpp"
#include "VramPalette.hpp"
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
        void ReleaseImage();

        VramImage *ncbr;
        CNCERFile *ncer;
        CellAnimController *cac;
        NNSGfdTexKey texKey;
    };

    CEffectActorData()
    {
        m_entries = NULL;
        m_count = 0;
    }

    virtual ~CEffectActorData();
    virtual VramImage *GetNcbr(int i);
    virtual CNCERFile *GetNcer(int i);
    virtual CellAnimController *GetCac(int i);
    virtual VramPalette *GetPalette();
    virtual void Update();
    virtual int GetCount();
    virtual BOOL IsLoaded();

    u32 GetEntryCount() const
    {
        return m_count;
    }

    void Release();
    void AllocPalette(BOOL immediate);
    void FreeVram();
    void ReleaseAll();

public:
    VramPalette m_palette;
    NNSGfdPlttKey m_plttKey;
    Entry *m_entries;
    u32 m_count;
};

STATIC_SIZE_ASSERT(CEffectActorData, 0x34);

#endif // POKERANGER2_CEFFECTACTORDATA_HPP
