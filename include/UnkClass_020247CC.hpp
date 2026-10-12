#ifndef POKERANGER2_UNKCLASS_020247CC_HPP
#define POKERANGER2_UNKCLASS_020247CC_HPP

#include <nitro.h>

#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "common.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CNCLRFile.hpp"
#include "file/CNSCRFile.hpp"

// Sub-screen party panel (BGS archive, data/menu/mc000_bg_LZ.bin): the leader and the partner Pokémon that follow
// the player, with their names and icons (UnkClass_02022404::unk_30)
class UnkClass_020247CC {
public:
    UnkClass_020247CC();
    ~UnkClass_020247CC();

    void sub_02024A2C();
    void sub_02024A60();
    void Load();
    void SetupBG();
    void SetupBlend();
    void DrawTexts();
    void sub_020255F0();
    void sub_02025624();

public:
    u32 unk_00[8]; // [0] = the leader's kind, then the partners'
    int unk_20; // has a leader
    int unk_24;
    int unk_28; // partner count
    int unk_2C;
    u16 unk_30[8];
    u8 unk_40[8];
    u8 unk_48[8];
    UnkClass_0200ECD0 *unk_50;
    UnkClass_0200ECD0 *unk_54;
    UnkClass_0200ECD0 *unk_58;
    UnkClass_0200E960 *unk_5C;
    CBGNCGRFile *unk_60;
    CNCLRFile *unk_64;
    CNSCRFile *unk_68;
    CNSCRFile *unk_6C;
    CNSCRFile *unk_70;
    UnkClass_020091E8_004 *unk_74;
};

STATIC_SIZE_ASSERT(UnkClass_020247CC, 0x78);

#endif // POKERANGER2_UNKCLASS_020247CC_HPP
