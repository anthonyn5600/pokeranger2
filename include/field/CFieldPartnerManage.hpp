#ifndef POKERANGER2_FIELD_CFIELDPARTNERMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDPARTNERMANAGE_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActorManage.hpp"
#include "field/CFieldEffectManageEventListener.hpp"
#include "field/CFieldPartner.hpp"

class CBinaryFile;
class CFieldPartnerManage;
class CFieldScene;

// The partner scripts: [0] FieldPartnerNpcScript.fsb, [1] FieldPartnerPokemonScript.fsb.
class UnkClass_0213949C {
public:
    UnkClass_0213949C();
    ~UnkClass_0213949C();
    void Load(const char *path, int idx);

    u8 unk_00[0x24];
    CBinaryFile *unk_24[2];
    void *unk_2C[2];
};

extern CFieldPartnerManage *MAIN_BSS_0210CA4C;

// Defined in ov0
class CFieldPartnerManage : public CFieldActorManage, public CFieldEffectManageEventListener {
public:
    CFieldPartnerManage();

    virtual ~CFieldPartnerManage()
    {
        sub_0203F034();
        MAIN_BSS_0210CA4C = NULL;
    }

    virtual void sub_0203EFE4(int capacity);
    virtual void sub_0203F034();
    virtual BOOL sub_0203F190();
    virtual void sub_0203F2B0(CFieldMap *map, BOOL update);
    virtual void sub_0203F348(UnkClass_0211E3FC *renderLists, UnkClass_020416AC *hud);

    virtual void func0();

    int ov0_02139920(u32 id, u16 kind, u16 flags, int type, int arg5);
    void ov0_02139E14(int mode);
    void ov0_02139E9C();
    void ov0_02139F10(BOOL arg);
    void ov0_02139F98(fx32 x, fx32 y, int dir);
    void ov0_0213A050(u32 id);
    int ov0_0213A084(u32 id);
    void ov0_0213A2B4();
    void ov0_0213A360(u32 id, u16 kind, u16 flags, int type, int arg5);
    u32 ov0_0213A4C4(u32 kind);
    u32 ov0_0213A520(u32 kind);
    BOOL ov0_0213A57C(u16 kind, CFieldPartner *partner);
    int ov0_0213A658(u16 kind);
    void ov0_0213A7FC(BOOL arg);

    // Next TU (ov0_0213A96C...)
    void ov0_0213B0F0();
    void ov0_0213B1BC();
    void ov0_0213B340();

    inline CFieldPartner *FindPartner(u32 target)
    {
        u32 kind;
        u32 id;
        u32 type = ((s32)target >> 24) & 0xFF;
        if (type == 2) {
            id = (target & 0xFFFFFF) | 0x5000000;
            kind = 1;
        } else if (type == 1) {
            id = (target & 0xFFFFFF) | 0x6000000;
            kind = 0;
        } else {
            return NULL;
        }
        for (int i = 0; i < m_count; i++) {
            CFieldPartner *partner = (CFieldPartner *)Get(i);
            if (partner != NULL && id == partner->unk_58 && kind == partner->unk_1FC) {
                return partner;
            }
        }
        return NULL;
    }

    inline BOOL RemovePartner(u32 target);

    // The partner that follows in the chain at `order` (CFieldPartner::unk_1E8).
    inline CFieldPartner *FindByOrder(int order)
    {
        int count = m_count;
        for (int i = 0; i < count; i++) {
            CFieldPartner *partner = (CFieldPartner *)(count <= i ? NULL : m_actors[i]);
            if (partner != NULL && order == partner->unk_1E8) {
                return partner;
            }
        }
        return NULL;
    }

public:
    u8 unk_14[0x40];
    u16 unk_54[11];
    u16 unk_6A[11];
    int unk_80;
    int unk_84; // partner NPCs
    int unk_88; // partner Pokémon
    UnkClass_0213949C *unk_8C;
    CFieldScene *unk_90;
    int unk_94;
};

STATIC_SIZE_ASSERT(CFieldPartnerManage, 0x98);

#endif // POKERANGER2_FIELD_CFIELDPARTNERMANAGE_HPP
