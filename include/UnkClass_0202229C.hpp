#ifndef POKERANGER2_UNKCLASS_0202229C_HPP
#define POKERANGER2_UNKCLASS_0202229C_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;

// Sub-screen picture (uppict/uppict%03d_) on BG0 (UnkClass_02022404::unk_54)
class UnkClass_0202229C {
public:
    UnkClass_0202229C(CGame *game);
    ~UnkClass_0202229C();

    void Release();
    void Update();
    void Render();
    void Init();
    BOOL Load(int id);
    void SetupBG();

public:
    u32 unk_00;
    CGame *unk_04;
};

STATIC_SIZE_ASSERT(UnkClass_0202229C, 0x8);

#endif // POKERANGER2_UNKCLASS_0202229C_HPP
