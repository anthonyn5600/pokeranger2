#ifndef POKERANGER2_UNKCLASS_0202163C_HPP
#define POKERANGER2_UNKCLASS_0202163C_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;
class UnkClass_0200E960;
class UnkClass_0200ECD0;
class UnkClass_0201FC80;
class UnkClass_02021404;

struct UnkStruct_0202163C_5C {
    UnkClass_0200E960 *unk_00;
    s16 unk_04; // x
    s16 unk_06; // y
    s16 unk_08; // kind
};

// Sub-screen area map with the place name (UnkClass_02022404::unk_18)
class UnkClass_0202163C {
public:
    UnkClass_0202163C(CGame *game);
    ~UnkClass_0202163C();

    void Release();
    void Update();
    void Render();
    void Init();
    void Draw();
    void DrawIcons(int x, int y);
    void Load();
    void LoadOAM();
    void LoadOAMToVram();
    void LoadMapScr();
    void Hide();
    void DrawPlaceName();
    void LoadToVram();
    void SetupBG();
    BOOL Show(int mapId, int x, int y);
    BOOL SetMap(int mapId, int x, int y);
    void SetPos(int x, int y);
    void ClearIcons();
    BOOL AddIcon(int x, int y, int kind);

public:
    u8 unk_00[0x30];
    int unk_30; // x
    int unk_34; // y
    int unk_38; // map id
    UnkClass_0201FC80 *unk_3C;
    UnkClass_0201FC80 *unk_40;
    UnkClass_0201FC80 *unk_44;
    UnkClass_0200ECD0 *unk_48;
    UnkClass_0200ECD0 *unk_4C;
    UnkClass_0200ECD0 *unk_50;
    UnkClass_0200E960 *unk_54;
    UnkClass_0200E960 *unk_58;
    UnkStruct_0202163C_5C unk_5C[5];
    u16 unk_98;
    u32 unk_9C;
    int unk_A0; // OAM offset
    UnkClass_02021404 *unk_A4;
    CGame *unk_A8;
};

STATIC_SIZE_ASSERT(UnkClass_0202163C, 0xAC);

#endif // POKERANGER2_UNKCLASS_0202163C_HPP
