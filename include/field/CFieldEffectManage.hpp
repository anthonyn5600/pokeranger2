#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANAGE_HPP

#include <nitro.h>

#include "CEffectActorData.hpp"
#include "CellAnimController.hpp"
#include "FieldDataRecords.hpp"
#include "FieldEffectListeners.hpp"
#include "ScriptVM.hpp"
#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CFieldPlayer;
class GraphicsSet;
class DrawObjectList;
class Camera2D;

// Members of CFieldEffectManage defined in other ov0 TUs.
#include "field/CFieldEffectFootStepSmoke.hpp"

// Damage number (0..99) popping out of the player's head, drawn from the HP gauge's digit texture.
class CFieldEffectDamageIndication : public CFieldEffect {
public:
    CFieldEffectDamageIndication();
    virtual int GetEffectId()
    {
        return 0x24;
    }
    virtual int Update(int step);
    virtual int Render(Camera2D *camera);

    // Shows `damage` above `player` for `duration` frames.
    void Show(int damage, int duration, CFieldPlayer *player);
    void InitRects(GraphicsSet *digits);

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
    BOOL Load(int id, int first, int count);
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
    BOOL Load(int id, BOOL immediate);
};

class CBinaryFile;

// A loaded data/Script/field/effect/efNNN.fsb.
struct FieldEffectScript {
    u32 unk_00;
    CBinaryFile *m_file;
    void *m_script;
};

// FieldEffectScript.cpp (ov0): runs the "EventHandle" handler of the field effects' scripts (3 slots).
class FieldEffectScriptHandler {
public:
    FieldEffectScriptHandler();
    ~FieldEffectScriptHandler();

    // Loads ef<id>.fsb into a free slot; returns the slot or -1.
    int LoadScript(int id);
    void Release();
    // Calls the slot's EventHandle(arg, x, y, param).
    int CallEventHandle(int slot, int arg, int x, int y, int param);

    ScriptVM m_vm;
    FieldEffectScript m_scripts[3];
    u32 m_stack[0x20];
};

class IFieldEffectDataBuilder {};

// FieldEffectManage.cpp (ov0): owns the field's effects (128 slots, id = slot | type << 8) and their factories.
class CFieldEffectManage : public IFieldEffectDataBuilder {
public:
    class CResidentResource;

    CFieldEffectManage(FieldEffectListeners *listeners);
    virtual void BuildData(void *buf, int size);
    virtual ~CFieldEffectManage();
    int Update(int fps, BOOL arg1);
    int Render(Camera2D *camera);
    int Clear();
    u16 Create(int kind, int arg);
    u16 GetNext(u16 id);
    CFieldEffect *Get(u16 id);
    BOOL Remove(u16 id);
    void SetFactory(int kind, CFieldEffectFactory *factory);
    BOOL EmitFootStep(int kind, int arg1, int arg2, int arg3, const FieldMapData *table);
    int ShowDamage(int arg0, int arg1, CFieldPlayer *player);
    void EmitAirBubbles(fx32 x, fx32 y);
    void LoadResident();
    int SetDrawBudget(int layer, int budget);
    void AddToRenderLists(DrawObjectList *renderLists);
    void Reset();
    void NotifyListeners();
    void RestoreSavedEffects();
    void RestoreEffect(const u8 *data);
    void ov0_0214366C();

    class CResidentResource : public CEffectResource {
    public:
        CResidentResource();
        virtual ~CResidentResource();
        virtual VramImage *GetNcbr(int i);
        virtual CNCERFile *GetNcer(int i);
        virtual CellAnimController *GetCac(int i);
        virtual VramPalette *GetPalette();
        virtual void Update();
        virtual int GetCount();
        virtual BOOL IsLoaded();
        void Load();
        void Release();

        VramImage m_ncbr;
        VramPalette m_palette;
        CNCERFile *m_ncer[12];
        CellAnimController *m_cac[12];
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
    FieldEffectScriptHandler unk_7B0;
    FieldEffectListeners *m_listeners;
    u8 unk_87C;
    u8 unk_87D;
};
STATIC_SIZE_ASSERT(CFieldEffectManage, 0x880);

extern CFieldEffectManage *MAIN_BSS_0210CA60;

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANAGE_HPP
