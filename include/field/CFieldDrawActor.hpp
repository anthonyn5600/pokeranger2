#ifndef POKERANGER2_FIELD_CFIELDDRAWACTOR_HPP
#define POKERANGER2_FIELD_CFIELDDRAWACTOR_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "UnkClass_02007770.hpp"
#include "common.hpp"
#include "field/CFieldDrawActorData.hpp"
#include "sub_02006000.hpp"

// FieldDrawActor.cpp (arm9): the drawn part of a field actor (CFieldDrawObject::unk_0C).
class CFieldDrawActor : public CActor {
public:
    CFieldDrawActor();
    virtual ~CFieldDrawActor();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10();

    void sub_0203DBB8(int type, u16 id, int form, u32 mask, BOOL useTransfer);
    void sub_0203E10C(int type, u16 id, int form, u32 mask, BOOL useTransfer);
    void sub_0203E55C();
    u32 sub_0203E934(Camera2D *camera, fx32 z);
    void sub_0203EE3C();
    void sub_0203EEA8(u16 arg0, u8 alpha, int duration);
    void sub_0203EEEC(int duration);

    inline bool IsAnimChanged() const
    {
        return unk_1D8 != unk_1DC || unk_1E0 != unk_1E1;
    }

    inline BOOL IsBlinking()
    {
        return (unk_1A8 & 2) ? TRUE : FALSE;
    }

    inline void sub_reset()
    {
        unk_1DC = 3;
        unk_1E1 = 0;
    }

    inline void SetXY(fx32 x, fx32 y)
    {
        m_motion.sub_02011D1C(x);
        m_motion.sub_02011D2C(y);
    }

    inline void sub_show()
    {
        unk_1DC = 0;
        unk_1E1 = 0;
    }

    inline void SetUnk1DC(int value)
    {
        unk_1DC = value;
        unk_1E1 = 0;
    }

    inline BOOL HasShadowOffset()
    {
        return (unk_1A8 & 4) ? TRUE : FALSE;
    }

    inline s16 GetShadowOffsetX()
    {
        return HasShadowOffset() ? unk_1D0 : 0;
    }

    inline s16 GetShadowOffsetY()
    {
        return HasShadowOffset() ? unk_1D2 : 0;
    }

    inline void SetClipping(s16 x1, s16 x2, s16 y1, s16 y2)
    {
        if (m_sprite != NULL) {
            m_sprite->SetClipping(x1, x2, y1, y2);
        }
    }

    inline void StartBlink()
    {
        unk_1A8 |= 2;
        unk_1B8 = 0x1F;
        unk_1C6 = 0x1F;
    }

public:
    CFieldDrawActorData *unk_184;
    NNSGfdTexKey unk_188[2];
    NNSGfdPlttKey unk_190;
    UnkClass_02007770 *unk_194;
    int unk_198;
    fx32 unk_19C;
    int unk_1A0;
    int unk_1A4;
    u32 unk_1A8;
    u16 m_outlineColor;
    u8 unk_1AE[0x2];
    int m_outlinePhase;
    int m_outlineTime;
    u16 unk_1B8;
    u8 unk_1BA[0x2];
    int unk_1BC;
    int unk_1C0;
    u8 m_outlineWidth;
    u8 m_outlineAlpha;
    u8 unk_1C6;
    u8 unk_1C7;
    u8 unk_1C8;
    u8 unk_1C9;
    u16 unk_1CA;
    int unk_1CC;
    s16 unk_1D0;
    s16 unk_1D2;
    u8 unk_1D4;
    u8 unk_1D5;
    u8 unk_1D6[0x2];
    int unk_1D8;
    int unk_1DC;
    u8 unk_1E0;
    u8 unk_1E1;
    u8 unk_1E2[0x2];
    Rectangle unk_1E4;
    int unk_1F4;
    int unk_1F8;
    int unk_1FC;
    u8 unk_200;
};

STATIC_SIZE_ASSERT(CFieldDrawActor, 0x204);

#endif // POKERANGER2_FIELD_CFIELDDRAWACTOR_HPP
