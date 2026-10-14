#ifndef POKERANGER2_FIELD_CFIELDEFFECTFIREWORKS_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFIREWORKS_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CMeshSprite.hpp"

class CFieldEffectFireworks : public CFieldEffect {
public:
    CFieldEffectFireworks(int arg); // ov0_02169670
    virtual int sub_02033028()
    {
        return 0x15;
    }
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual void sub_02033440(u16 color);

    void SetRes(UnkClass_020074D4 *image, UnkClass_02007AA4 *palette, CNCERFile *ncer); // ov0_0216974C

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
