#ifndef POKERANGER2_UNKCLASS_0201B724_HPP
#define POKERANGER2_UNKCLASS_0201B724_HPP

#include <nitro.h>

#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CNCLRFile.hpp"
#include "file/CNSCRFile.hpp"

// Sub-screen target info (TGT archive, data/menu/mt000_bg_LZ.bin): place name, target sprite (data/targetOBJ
// bt%03d_%02d) and its texts; loaded step by step by Load() (UnkClass_02022404::unk_40)
class UnkClass_0201B724 {
public:
    UnkClass_0201B724();
    ~UnkClass_0201B724();

    void Release();
    void ResetLoad();
    int Load(u32 id);
    void LoadArchive(const char *name);
    void LoadBG();
    void ReleaseBG();
    void SetupBlend();
    void DrawTexts();
    void Update();
    void Render();
    void ReleaseMessages();

public:
    int unk_00;
    u32 unk_04;
    u16 unk_08;
    u8 unk_0A;
    u8 unk_0B;
    u8 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    UnkClass_0200ECD0 *unk_14;
    UnkClass_0200ECD0 *unk_18;
    UnkClass_0200ECD0 *unk_1C;
    UnkClass_0200ECD0 *unk_20;
    UnkClass_0200ECD0 *unk_24;
    UnkClass_0200E960 *unk_28;
    UnkClass_020091E8_004 *unk_2C;
    UnkClass_020091E8_004 *unk_30;
    UnkClass_020091E8_004 *unk_34;
    CArchiveGuard *unk_38;
    CBGNCGRFile *unk_3C;
    CNCLRFile *unk_40;
    CNSCRFile *unk_44;
    CNSCRFile *unk_48;
    CNSCRFile *unk_4C;
    int unk_50;
    int unk_54;
    u8 unk_58[0x4];
};

STATIC_SIZE_ASSERT(UnkClass_0201B724, 0x5C);

#endif // POKERANGER2_UNKCLASS_0201B724_HPP
