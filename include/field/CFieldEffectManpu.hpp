#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPU_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPU_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CFieldActor;

// Emotion balloon over an actor (CFieldActor::unk_D0 holds its effect id). Defined in ov0, except SetType.
class CFieldEffectManpu : public CFieldEffectActor {
public:
    static void *operator new(size_t size);
    static void operator delete(void *ptr);

    CFieldEffectManpu(CEffectActorData *data)
        : CFieldEffectActor(data)
    {
        unk_1C = NULL;
        unk_20 = 0;
        unk_24 = -1;
        unk_28 = 0;
    }
    virtual ~CFieldEffectManpu();
    virtual int GetEffectId();
    virtual int ov0_02142344(Camera2D *camera);
    virtual void SetType(int type);
    virtual int Draw(Camera2D *camera) = 0;
    virtual void SetDepth(fx32 z) = 0;

    BOOL IsVisible();
    inline void Detach();

public:
    CFieldActor *unk_1C;
    u8 unk_20;
    u8 unk_21[0x3];
    int unk_24;
    int unk_28;
};

class CFieldEffectManpuSimple : public CFieldEffectManpu {
public:
    CFieldEffectManpuSimple(CEffectActorData *data, int type = 0)
        : CFieldEffectManpu(data)
    {
        unk_28 = 1;
        Init(type);
    }
    virtual int Draw(Camera2D *camera);
    virtual void SetDepth(fx32 z);

    void Init(int type);

public:
    CSoftwareSprite m_sprite;
    int unk_78;
};

extern "C" {
int Actor_ShowManpu(CFieldActor *actor, int type, int arg2);
}

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPU_HPP
