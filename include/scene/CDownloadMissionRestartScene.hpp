#ifndef POKERANGER2_SCENE_CDOWNLOADMISSIONRESTARTSCENE_HPP
#define POKERANGER2_SCENE_CDOWNLOADMISSIONRESTARTSCENE_HPP

#include "CGame.hpp"
#include "UnkClass_02027FE8.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

// Defined in arm9
class CDownloadMissionRestartScene : public CScene {
public:
    CDownloadMissionRestartScene(CGame *game)
        : game(game)
        , unk_000C(NULL)
    {
    }

    virtual ~CDownloadMissionRestartScene()
    {
        SAFE_DELETE(unk_000C);
    }

    virtual u32 getSceneId()
    {
        return 0x1E;
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
    u32 unk_0010;
};

STATIC_SIZE_ASSERT(CDownloadMissionRestartScene, 0x14);

#endif // POKERANGER2_SCENE_CDOWNLOADMISSIONRESTARTSCENE_HPP
