#ifndef POKERANGER2_FIELD_CFIELDEFFECTCELLANIME_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTCELLANIME_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Plays the cell animations of an effect archive once per state (ov0). m_kind >= 0 loads its own actor data (attack or
// normal effect, up to two animations); m_kind < 0 uses animation -1 - m_kind of the resident data.
class CFieldEffectCellAnime : public CFieldEffectActor {
public:
    CFieldEffectCellAnime(int kind, BOOL attack);
    virtual ~CFieldEffectCellAnime();
    virtual int sub_02033028()
    {
        return 6;
    }
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual void sub_0203365C(int arg0);

    void InitSprites();
    UnkClass_02008788 *GetCac()
    {
        if (m_kind >= 0) {
            return unk_18->GetCac(m_index);
        }
        return unk_18->GetCac(-1 - m_kind);
    }

public:
    int m_kind;
    Point2D m_pos;
    int m_index;
    int m_lastState;
    CSoftwareSprite m_sprites[2];
    u16 m_cacIds[2];
    int m_se;
};
STATIC_SIZE_ASSERT(CFieldEffectCellAnime, 0xD0);

class CFieldEffectNormalCellAnimeFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

class CFieldEffectAttackCellAnimeFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTCELLANIME_HPP
