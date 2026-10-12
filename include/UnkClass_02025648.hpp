#ifndef POKERANGER2_UNKCLASS_02025648_HPP
#define POKERANGER2_UNKCLASS_02025648_HPP

#include <nitro.h>

#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CNCLRFile.hpp"

// Sub-screen ranger card (BGS archive, data/menu/mp000_bg_LZ.bin): player name, rank, styler level and energy, browser
// count; loaded step by step by sub_020257F4() (UnkClass_02022404::unk_4C) or at once by LoadAll() (overlay 6)
class UnkClass_02025648 {
public:
    UnkClass_02025648();
    ~UnkClass_02025648();

    void sub_020256A4();
    int sub_020257F4(int step);
    void LoadAll();
    int LoadBG(int step);
    void LoadBGAll();
    void SetupBlend();
    void DrawTexts();
    void DrawGauge();
    void sub_02027640();
    void sub_02027674();
    void sub_020276A0();

public:
    int unk_00;
    int unk_04;
    int unk_08;
    int unk_0C;
    int unk_10;
    int unk_14;
    int unk_18;
    int unk_1C;
    int unk_20;
    int unk_24;
    UnkClass_0200ECD0 *unk_28;
    UnkClass_0200ECD0 *unk_2C;
    UnkClass_0200ECD0 *unk_30;
    UnkClass_0200ECD0 *unk_34;
    UnkClass_0200E960 *unk_38;
    UnkClass_020091E8_004 *unk_3C;
    int unk_40;
    int unk_44;
    CArchiveGuard *unk_48;
    CBGNCGRFile *unk_4C;
    CNCLRFile *unk_50;
};

STATIC_SIZE_ASSERT(UnkClass_02025648, 0x54);

#endif // POKERANGER2_UNKCLASS_02025648_HPP
