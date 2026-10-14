#ifndef POKERANGER2_FIELDSCREENEFFECTMANAGE_HPP
#define POKERANGER2_FIELDSCREENEFFECTMANAGE_HPP

#include <nitro.h>

#include "common.hpp"

class CFieldScreenEffectObjectBase;
class Camera2D;
class FieldScreenEffectManage;

extern FieldScreenEffectManage *MAIN_BSS_0210CA78;

// Field screen effect manager (CFieldSEF* weather effects); ctor/dtor only inline (first found in CFieldScene::func6)
class FieldScreenEffectManage {
public:
    FieldScreenEffectManage()
    {
        MAIN_BSS_0210CA78 = this;
        m_count = 0;
        m_effects = NULL;
        Alloc(8);
    }

    ~FieldScreenEffectManage()
    {
        Free();
        MAIN_BSS_0210CA78 = NULL;
    }

    void Alloc(int count);
    void Free();
    void Update(int fps);
    void Draw(Camera2D *camera);
    int Add(CFieldScreenEffectObjectBase *effect);
    int SetPrimary(CFieldScreenEffectObjectBase *effect);
    void ClearSecondary();
    void ClearPrimary();
    CFieldScreenEffectObjectBase *CreateEffect(int type);
    int FindByType(int type);
    int sub_02035D38(int type);
    BOOL StartEffect(int type, int fadeIn, int hold, int fadeOut);
    BOOL StopEffect(int type, int fadeOut);
    BOOL IsEffectActive(int type);
    BOOL sub_02035F50(int type, int arg);

public:
    int m_count;
    CFieldScreenEffectObjectBase **m_effects;
};

STATIC_SIZE_ASSERT(FieldScreenEffectManage, 0x8);

#endif // POKERANGER2_FIELDSCREENEFFECTMANAGE_HPP
