#ifndef POKERANGER2_BATTLE_UNKCLASS_02135BB4_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02135BB4_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;
class UnkClass_02008FA8;

// Defined in ov1
class UnkClass_02135BB4 {
public:
    UnkClass_02135BB4(CGame *game);
    ~UnkClass_02135BB4();
    void ov1_02135C2C();
    void ov1_02135C58();
    int ov1_02135C68();
    int ov1_02135C78();
    int ov1_02135C8C();

public:
    CGame *m_game;
    UnkClass_02008FA8 *unk_04;
};

STATIC_SIZE_ASSERT(UnkClass_02135BB4, 0x8);

#endif // POKERANGER2_BATTLE_UNKCLASS_02135BB4_HPP
