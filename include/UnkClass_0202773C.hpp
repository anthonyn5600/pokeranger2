#ifndef POKERANGER2_UNKCLASS_0202773C_HPP
#define POKERANGER2_UNKCLASS_0202773C_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;
class UnkClass_02027FE8;

// One step of a save dialog script: a textbox message (< 0: close the textbox), the next state, a sound (< 0: stop
// the music, -2: without restarting it)
struct UnkStruct_0202773C_Step {
    int message;
    u16 state;
    int arg;
    int sound;
};

// Save dialog opened from the sub-screen icon menu (UnkClass_02023558::unk_11C): runs a step script through the
// textbox and saves the game with UnkClass_02027FE8
class UnkClass_0202773C {
public:
    UnkClass_0202773C(CGame *game);
    ~UnkClass_0202773C();

    static void Create();
    static UnkClass_0202773C *GetInstance();

    BOOL sub_0202780C();
    void Reset();
    void sub_020279A4();
    void sub_02027A2C();
    void SetStep(UnkStruct_0202773C_Step *step, int arg1, int arg3);
    void NextStep();
    BOOL IsActive();

public:
    u16 unk_00; // state
    int unk_04; // step index
    UnkClass_02027FE8 *unk_08;
    UnkStruct_0202773C_Step *unk_0C;
    u16 unk_10;
    CGame *unk_14;
};

STATIC_SIZE_ASSERT(UnkClass_0202773C, 0x18);

extern UnkClass_0202773C *MAIN_BSS_0210C1BC;

#endif // POKERANGER2_UNKCLASS_0202773C_HPP
