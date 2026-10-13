#ifndef POKERANGER2_FIELD_TFIELDEFFECTPARTICLE_HPP
#define POKERANGER2_FIELD_TFIELDEFFECTPARTICLE_HPP

#include <nitro.h>

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/TFieldParticle.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CSoftwareSprite.hpp"

template <class T>
class TFieldEffectParticle : public CFieldEffect {
public:
    virtual int ov0_02142264(int step)
    {
        int state = CFieldEffect::ov0_02142264(step);
        if (state != 4 && m_system != NULL) {
            m_system->Update(step);
        }
        return state;
    }

    virtual void ov0_021423E8(const FieldEffectSpriteRes &res)
    {
        m_res = res;
        if (m_system != NULL) {
            m_system->m_res = m_res;
        }
    }

    TFieldParticleSystem<T> *m_system;
    FieldEffectSpriteRes m_res;
};

#endif // POKERANGER2_FIELD_TFIELDEFFECTPARTICLE_HPP
