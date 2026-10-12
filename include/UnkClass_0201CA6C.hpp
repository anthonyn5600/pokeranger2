#ifndef POKERANGER2_UNKCLASS_0201CA6C_HPP
#define POKERANGER2_UNKCLASS_0201CA6C_HPP

#include <nitro.h>

#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CNCLRFile.hpp"
#include "file/CNSCRFile.hpp"

// Sub-screen menu (BGS/PTC archives, data/menu/mt000_bg_LZ.bin): pokemon info, menu and assist messages
// (UnkClass_02022404::unk_34)
class UnkClass_0201CA6C {
public:
    UnkClass_0201CA6C();
    ~UnkClass_0201CA6C();

    void Release();
    void Load(int arg0, int arg1, int count);
    void ResetLoad();
    int LoadStep(int arg0, int arg1, int count);
    void LoadBG();
    void LoadPTC();
    void ReleaseBG();
    void SetupBlend();
    void sub_0201DF54(int arg0, int arg1);
    void sub_0201E0A4();
    void sub_0201EA2C();
    int sub_0201E288(int step);
    void sub_0201E27C();
    void sub_0201EC80();
    void sub_0201F024();
    void sub_0201F124();
    void sub_0201F38C();
    void sub_0201F48C();
    void Update();
    void Render();
    void ReleaseMessages();

public:
    int unk_00;
    int unk_04;
    int unk_08;
    u16 unk_0C;
    u8 unk_0E;
    u16 unk_10;
    u16 unk_12;
    u8 unk_14;
    u16 unk_16;
    u16 unk_18;
    u8 unk_1A;
    u8 unk_1B;
    u16 unk_1C;
    u16 unk_1E;
    u16 unk_20;
    int unk_24;
    UnkClass_0200ECD0 *unk_28;
    UnkClass_0200ECD0 *unk_2C;
    UnkClass_0200ECD0 *unk_30;
    UnkClass_0200ECD0 *unk_34;
    UnkClass_0200ECD0 *unk_38;
    UnkClass_0200ECD0 *unk_3C;
    UnkClass_0200ECD0 *unk_40;
    UnkClass_0200E960 *unk_44;
    UnkClass_020091E8_004 *unk_48;
    UnkClass_020091E8_004 *unk_4C;
    UnkClass_020091E8_004 *unk_50;
    int unk_54;
    CArchiveGuard *unk_58;
    CBGNCGRFile *unk_5C;
    CNCLRFile *unk_60;
    CNSCRFile *unk_64;
    CNSCRFile *unk_68;
    CNSCRFile *unk_6C;
    int unk_70;
    int unk_74;
    int unk_78;
};

STATIC_SIZE_ASSERT(UnkClass_0201CA6C, 0x7C);

#endif // POKERANGER2_UNKCLASS_0201CA6C_HPP
