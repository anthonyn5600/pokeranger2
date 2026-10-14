#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANAGE_HPP

#include <nitro.h>

#include "CEffectActorData.hpp"
#include "UnkClass_02008788.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkClass_02143714.hpp"
#include "UnkStruct_02044464.hpp"
#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CFieldPlayer;
class UnkClass_0201AAE0;
class UnkClass_0211E3FC;
class Camera2D;

// Members of CFieldEffectManage defined in other ov0 TUs.
#include "field/CFieldEffectFootStepSmoke.hpp"

// Damage number (0..99) popping out of the player's head, drawn from the HP gauge's digit texture.
class CFieldEffectDamageIndication : public CFieldEffect {
public:
    CFieldEffectDamageIndication();
    virtual int sub_02033028()
    {
        return 0x24;
    }
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);

    // Shows `damage` above `player` for `duration` frames.
    void ov0_02164DB8(int damage, int duration, CFieldPlayer *player);
    void InitRects(UnkClass_0201AAE0 *digits);

    CPrimitiveRECT m_rects[2];
    int m_digits;
    Point2D m_vel;
    CFieldPlayer *m_player;
    Point2D m_offset;
};

#include "field/CFieldEffectAirBubbles.hpp"

class CFieldEffectAttackActorData : public CEffectActorData {
public:
    virtual void Update();

    // Loads data/effect/e<id>_LZ.bin: count entries a<first>, a<first + 1>...
    BOOL ov0_0214FFF0(int id, int first, int count);
};

// Between the Attack and Normal actor data on purpose: the class order (Attack, Manpu, Normal) decides the order of
// their vtables in FieldEffectActorData.cpp's data.
#include "field/CFieldManpuEffectActorData.hpp"

class CFieldEffectNormalActorData : public CEffectActorData {
public:
    CFieldEffectNormalActorData()
    {
    }
    virtual void Update();

    // Loads data/field/effect/ef<id>_LZ.bin.
    BOOL ov0_021503B8(int id, BOOL immediate);
};

class CBinaryFile;

// A loaded data/Script/field/effect/efNNN.fsb.
struct FieldEffectScript {
    u32 unk_00;
    CBinaryFile *m_file;
    void *m_script;
};

// FieldEffectScript.cpp (ov0): runs the "EventHandle" handler of the field effects' scripts (3 slots).
class UnkClass_021638B8 {
public:
    UnkClass_021638B8();
    ~UnkClass_021638B8();

    // Loads ef<id>.fsb into a free slot; returns the slot or -1.
    int ov0_02163904(int id);
    void ov0_021639BC();
    // Calls the slot's EventHandle(arg, x, y, param).
    int ov0_02163A08(int slot, int arg, int x, int y, int param);

    UnkStruct_02044464 m_vm;
    FieldEffectScript m_scripts[3];
    u32 m_stack[0x20];
};

class IFieldEffectDataBuilder {};

// FieldEffectManage.cpp (ov0): owns the field's effects (128 slots, id = slot | type << 8) and their factories.
class CFieldEffectManage : public IFieldEffectDataBuilder {
public:
    class CResidentResource;

    CFieldEffectManage(UnkClass_02143714 *listeners);
    virtual void BuildData(void *buf, int size);
    virtual ~CFieldEffectManage();
    int ov0_021428EC(int fps, BOOL arg1);
    int ov0_02142D88(Camera2D *camera);
    int ov0_02142F08();
    u16 ov0_02142F6C(int kind, int arg);
    u16 ov0_02143024(u16 id);
    CFieldEffect *ov0_02143088(u16 id);
    BOOL ov0_021430D8(u16 id);
    void ov0_0214318C(int kind, CFieldEffectFactory *factory);
    BOOL ov0_021431A4(int kind, int arg1, int arg2, int arg3, const UnkStruct_02041D80 *table);
    int ov0_0214332C(int arg0, int arg1, CFieldPlayer *player);
    void ov0_02143344(fx32 x, fx32 y);
    void ov0_02143358();
    int ov0_0214336C(int layer, int budget);
    void ov0_02143380(UnkClass_0211E3FC *renderLists);
    void ov0_021433D0();
    void ov0_02143410();
    void ov0_021434F0();
    void ov0_02143568(const u8 *data);
    void ov0_0214366C();

    class CResidentResource : public CEffectResource {
    public:
        CResidentResource();
        virtual ~CResidentResource();
        virtual UnkClass_020074D4 *GetNcbr(int i);
        virtual CNCERFile *GetNcer(int i);
        virtual UnkClass_02008788 *GetCac(int i);
        virtual UnkClass_02007AA4 *GetPalette();
        virtual void Update();
        virtual int GetCount();
        virtual BOOL IsLoaded();
        void Load();
        void Release();

        UnkClass_020074D4 m_ncbr;
        UnkClass_02007AA4 m_palette;
        CNCERFile *m_ncer[12];
        UnkClass_02008788 *m_cac[12];
        NNSGfdTexKey m_texKey;
        NNSGfdPlttKey m_plttKey;
    };

    CFieldEffect *m_effects[0x80];
    CFieldEffectFootStepSmoke m_footStepSmoke;
    CFieldEffectDamageIndication m_damageIndication;
    CFieldEffectAirBubbles m_airBubbles;
    CFieldEffectFactory *m_factories[41];
    CResidentResource m_resident;
    CFieldEffectAttackActorData m_attackActorData;
    int unk_77C;
    int unk_780[4];
    int unk_790[4];
    int unk_7A0[4];
    UnkClass_021638B8 unk_7B0;
    UnkClass_02143714 *m_listeners;
    u8 unk_87C;
    u8 unk_87D;
};
STATIC_SIZE_ASSERT(CFieldEffectManage, 0x880);

extern CFieldEffectManage *MAIN_BSS_0210CA60;

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANAGE_HPP
