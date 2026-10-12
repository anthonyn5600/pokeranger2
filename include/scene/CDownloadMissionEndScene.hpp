#ifndef POKERANGER2_SCENE_CDOWNLOADMISSIONENDSCENE_HPP
#define POKERANGER2_SCENE_CDOWNLOADMISSIONENDSCENE_HPP

#include "CGame.hpp"
#include "UnkClass_02027FE8.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

// Defined in arm9
class CDownloadMissionEndScene : public CScene {
public:
    CDownloadMissionEndScene(CGame *game)
        : game(game)
        , unk_000C(NULL)
    {
    }

    virtual ~CDownloadMissionEndScene()
    {
    }

    virtual u32 getSceneId()
    {
        return 0x1D;
    }
    virtual u32 func0();
    virtual void func1()
    {
    }
    virtual void func2()
    {
    }
    virtual void func5();
    virtual void func6();
    virtual void func7();

public:
    CGame *game;
    u32 unk_0008;
    UnkClass_02027FE8 *unk_000C;
    // Snapshot of the save fields the download mission overwrites
    u8 unk_0010;
    u8 unk_0011;
    u32 unk_0014;
    u32 unk_0018;
    u32 unk_001C[0x20];
    u32 unk_009C[0x20];
    u8 unk_011C[500];
    u8 unk_0310;
    u32 unk_0314;
    u32 unk_0318;
    u32 unk_031C;
    u32 unk_0320;
    u32 unk_0324;
    u32 unk_0328[17];
    u32 unk_036C;
    u32 unk_0370;
    u16 unk_0374;
    u16 unk_0376;
    u16 unk_0378;
    u32 unk_037C;
    u8 unk_0380;
    u32 unk_0384;
    u8 unk_0388;
    u8 unk_0389;
    u8 unk_038A;
    int unk_038C;
};

STATIC_SIZE_ASSERT(CDownloadMissionEndScene, 0x390);

#endif // POKERANGER2_SCENE_CDOWNLOADMISSIONENDSCENE_HPP
