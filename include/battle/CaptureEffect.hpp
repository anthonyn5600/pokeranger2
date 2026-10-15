#ifndef POKERANGER2_BATTLE_CAPTUREEFFECT_HPP
#define POKERANGER2_BATTLE_CAPTUREEFFECT_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"
#include "primitive/CSoftwareSprite.hpp"

class UnkClass_02129B74;

class Camera2D;
class CSoftwareSprite;
class CPrimitiveSPHERE;

// Defined in ov1
class CaptureEffect {
public:
    CaptureEffect(); // ov1_02129DD4
    ~CaptureEffect(); // ov1_02129E48
    void Update();
    void Render(Camera2D *camera);
    int SetZ(int z);

    inline void Stop()
    {
        unk_14 = FALSE;
        unk_18 = 0;
        unk_1A = 0;
        unk_0C = FX32_ONE;
    }
    void SetData(UnkClass_02129B74 *data);

public:
    UnkClass_02129B74 *m_data;
    CSoftwareSprite *unk_04;
    CSoftwareSprite *unk_08;
    fx32 unk_0C;
    CPrimitiveSPHERE *m_sphere;
    BOOL unk_14;
    u16 unk_18;
    u16 unk_1A;
    u16 m_animId;
};

STATIC_SIZE_ASSERT(CaptureEffect, 0x20);

#endif // POKERANGER2_BATTLE_CAPTUREEFFECT_HPP
