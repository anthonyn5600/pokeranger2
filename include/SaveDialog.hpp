#ifndef POKERANGER2_SAVEDIALOG_HPP
#define POKERANGER2_SAVEDIALOG_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;
class SaveManager;

// One step of a save dialog script: a textbox message (< 0: close the textbox), the next state, a sound (< 0: stop
// the music, -2: without restarting it)
struct UnkStruct_0202773C_Step {
    int message;
    u16 state;
    int arg;
    int sound;
};

// Save dialog opened from the sub-screen icon menu (SubScreenIconMenuView::unk_11C): runs a step script through the
// textbox and saves the game with SaveManager
class SaveDialog {
public:
    SaveDialog(CGame *game);
    ~SaveDialog();

    static void Create();
    static SaveDialog *GetInstance();

    BOOL Update();
    void Reset();
    void Start();
    void sub_02027A2C();
    void SetStep(UnkStruct_0202773C_Step *step, int arg1, int arg3);
    void NextStep();
    BOOL IsActive();

public:
    u16 unk_00; // state
    int unk_04; // step index
    SaveManager *unk_08;
    UnkStruct_0202773C_Step *unk_0C;
    u16 unk_10;
    CGame *unk_14;
};

STATIC_SIZE_ASSERT(SaveDialog, 0x18);

extern SaveDialog *MAIN_BSS_0210C1BC;

#endif // POKERANGER2_SAVEDIALOG_HPP
