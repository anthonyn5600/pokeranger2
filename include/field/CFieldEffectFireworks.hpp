#ifndef POKERANGER2_FIELD_CFIELDEFFECTFIREWORKS_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFIREWORKS_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CMeshSprite.hpp"

class CFieldEffectFireworks : public CFieldEffect {
public:
    CFieldEffectFireworks(int arg); // ov0_02169670
    virtual int GetEffectId()
    {
        return 0x15;
    }
    virtual int Update(int step);
    virtual int Render(Camera2D *camera);
    virtual int SetParam(int param, int value);
    virtual void SetColor(u16 color);

    void SetRes(VramImage *image, VramPalette *palette, CNCERFile *ncer); // ov0_0216974C

public:
    int m_arg;
    int m_time;
    CMeshSprite m_mesh;
};

STATIC_SIZE_ASSERT(CFieldEffectFireworks, 0x94);

class CFieldEffectFireworksFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTFIREWORKS_HPP
