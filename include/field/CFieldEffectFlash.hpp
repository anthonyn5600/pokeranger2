#ifndef POKERANGER2_FIELD_CFIELDEFFECTFLASH_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFLASH_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Flash sprite of an attack effect (ov0): kind 0x79 grows, kind 0x78 scales with the fade in/out.
class CFieldEffectFlash : public CFieldEffectActor {
public:
    CFieldEffectFlash(int kind);
    virtual ~CFieldEffectFlash();
    virtual int GetEffectId()
    {
        return 0x20;
    }
    virtual BOOL Start(int inTime, int holdTime, int outTime);
    virtual int Stop(int outTime);
    virtual int Update(int step);
    virtual int Render(Camera2D *camera);
    virtual void StartAt(Point2D pos, int arg1, int arg2, int arg3, int arg4);
    virtual int SetParam(int param, int value);

    void InitSprite();

public:
    Point2D m_pos;
    int m_kind;
    fx32 m_scale;
    u8 unk_2C[0x4];
    CSoftwareSprite m_sprites[1];
    u16 m_cacId;
};

class CFieldEffectFlashFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTFLASH_HPP
