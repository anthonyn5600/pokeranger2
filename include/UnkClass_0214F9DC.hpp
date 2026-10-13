#ifndef POKERANGER2_UNKCLASS_0214F9DC_HPP
#define POKERANGER2_UNKCLASS_0214F9DC_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;
class UnkClass_02008FA8;

// Field debug menu entry: kind 0 opens menu `value` (or runs `set` as an action), 1/7/8 edit an int up to
// `arg0`, 3 a bool, 4 picks one of `arg1` names (`arg0` is a const char *[]), 5 an id named by
// `const char *arg0(int)` with `int arg1()` choices, 6 shows `get` (`value` = menu)
struct DebugMenuItem {
    const char *name;
    int kind;
    int unk_08;
    int unk_0C;
    int value;
    void *get;
    void *set;
    void *arg0;
    void *arg1;
};

// Field debug menu page (unk_10/unk_14: cursor and scroll, cleared by UnkClass_0214F9DC::ov0_0214FAA0)
struct DebugMenu {
    const char *name;
    DebugMenuItem *items;
    int count;
    int unk_0C;
    int unk_10;
    int unk_14;
};

STATIC_SIZE_ASSERT(DebugMenuItem, 0x24);
STATIC_SIZE_ASSERT(DebugMenu, 0x18);

// Defined in ov0: the field debug menu (no menu interpreter is left in the retail game)
class UnkClass_0214F9DC {
public:
    UnkClass_0214F9DC(CGame *game);
    ~UnkClass_0214F9DC();
    void ov0_0214FA94(DebugMenu *menus, int count);
    void ov0_0214FAA0();
    void ov0_0214FB08();
    BOOL ov0_0214FB18();

public:
    CGame *m_game;
    UnkClass_02008FA8 *unk_04;
    DebugMenu *unk_08;
    DebugMenu *unk_0C;
    int unk_10;
};

STATIC_SIZE_ASSERT(UnkClass_0214F9DC, 0x14);

#endif // POKERANGER2_UNKCLASS_0214F9DC_HPP
