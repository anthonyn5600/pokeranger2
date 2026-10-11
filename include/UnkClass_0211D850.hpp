#ifndef POKERANGER2_UNKCLASS_0211D850_HPP
#define POKERANGER2_UNKCLASS_0211D850_HPP

#include <nitro.h>

#include "common.hpp"

class CFieldScreenEffectObjectBase;
class UnkClass_02003718;
class UnkClass_0211D850;

extern UnkClass_0211D850 *MAIN_BSS_0210CA78;

// Field screen effect manager (CFieldSEF* weather effects); ctor/dtor only inline (first found in CFieldScene::func6)
class UnkClass_0211D850 {
public:
    UnkClass_0211D850()
    {
        MAIN_BSS_0210CA78 = this;
        m_count = 0;
        m_effects = NULL;
        sub_02035720(8);
    }

    ~UnkClass_0211D850()
    {
        sub_02035774();
        MAIN_BSS_0210CA78 = NULL;
    }

    void sub_02035720(int count);
    void sub_02035774();
    void sub_0203580C(int fps);
    void sub_020358AC(UnkClass_02003718 *camera);
    int sub_02035900(CFieldScreenEffectObjectBase *effect);
    int sub_02035940(CFieldScreenEffectObjectBase *effect);
    void sub_02035998();
    void sub_020359FC();
    CFieldScreenEffectObjectBase *sub_02035A38(int type);
    int sub_02035CA4(int type);
    int sub_02035D38(int type);
    BOOL sub_02035DA0(int type, int fadeIn, int hold, int fadeOut);
    BOOL sub_02035E3C(int type, int fadeOut);
    BOOL sub_02035ECC(int type);
    BOOL sub_02035F50(int type, int arg);

public:
    int m_count;
    CFieldScreenEffectObjectBase **m_effects;
};

STATIC_SIZE_ASSERT(UnkClass_0211D850, 0x8);

#endif // POKERANGER2_UNKCLASS_0211D850_HPP
