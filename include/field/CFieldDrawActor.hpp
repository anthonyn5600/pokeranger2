#ifndef POKERANGER2_FIELD_CFIELDDRAWACTOR_HPP
#define POKERANGER2_FIELD_CFIELDDRAWACTOR_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "CellCharBuffer.hpp"
#include "Collision.hpp"
#include "common.hpp"
#include "field/CFieldDrawActorData.hpp"

// FieldDrawActor.cpp (arm9): the drawn part of a field actor (CFieldDrawObject::unk_0C).
class CFieldDrawActor : public CActor {
public:
    CFieldDrawActor();
    virtual ~CFieldDrawActor();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    void Load(int type, u16 id, int form, u32 mask, BOOL useTransfer);
    void LoadOwnData(int type, u16 id, int form, u32 mask, BOOL useTransfer);
    void Release();
    u32 Render(Camera2D *camera, fx32 z);
    void sub_0203EE3C();
    void StartColorBlink(u16 arg0, u8 alpha, int duration);
    void StopBlink(int duration);

    inline bool IsAnimChanged() const
    {
        return unk_1D8 != unk_1DC || unk_1E0 != unk_1E1;
    }

    inline BOOL IsBlinking()
    {
        return (m_effectFlags & 2) ? TRUE : FALSE;
    }

    inline void sub_reset()
    {
        unk_1DC = 3;
        unk_1E1 = 0;
    }

    inline void SetXY(fx32 x, fx32 y)
    {
        m_motion.SetX(x);
        m_motion.SetY(y);
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

    inline BOOL IsShaking()
    {
        return (m_effectFlags & 4) ? TRUE : FALSE;
    }

    inline s16 GetShakeX()
    {
        return IsShaking() ? m_shakeX : 0;
    }

    inline s16 GetShakeY()
    {
        return IsShaking() ? m_shakeY : 0;
    }

    inline void SetClipping(s16 x1, s16 x2, s16 y1, s16 y2)
    {
        if (m_sprite != NULL) {
            m_sprite->SetClipping(x1, x2, y1, y2);
        }
    }

    inline void ClearClipping()
    {
        if (m_sprite != NULL) {
            m_sprite->m_clipping.enabled = FALSE;
        }
    }

    inline void SetOutlineColor(u16 color)
    {
        m_outlineColor = color;
        m_outlinePhase = 0;
    }

    inline void StartOutline(int time)
    {
        m_effectFlags |= 1;
        m_outlineTime = time;
        m_outlinePhase = 0;
    }

    inline void StartBlink()
    {
        m_effectFlags |= 2;
        m_blinkColor = 0x1F;
        m_blinkAlpha = 0x1F;
    }

public:
    CFieldDrawActorData *m_actorData;
    NNSGfdTexKey unk_188[2];
    NNSGfdPlttKey unk_190;
    CellCharBuffer *m_cellBuffers;
    int m_cellBufferCount;
    fx32 m_animSpeed;
    int unk_1A0;
    int unk_1A4;
    u32 m_effectFlags;
    u16 m_outlineColor;
    u8 unk_1AE[0x2];
    int m_outlinePhase;
    int m_outlineTime;
    u16 m_blinkColor;
    u8 unk_1BA[0x2];
    int m_blinkFrame;
    int m_blinkDuration;
    u8 m_outlineWidth;
    u8 m_outlineAlpha;
    u8 m_blinkAlpha;
    u8 m_blinkFrom;
    u8 m_blinkTo;
    u8 unk_1C9;
    u16 unk_1CA;
    int m_shakeTime;
    s16 m_shakeX;
    s16 m_shakeY;
    u8 m_shakeRangeX;
    u8 m_shakeRangeY;
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
