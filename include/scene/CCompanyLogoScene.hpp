#ifndef POKERANGER2_SCENE_CCOMPANYLOGOSCENE_HPP
#define POKERANGER2_SCENE_CCOMPANYLOGOSCENE_HPP

#include "BGLayer.hpp"
#include "SaveManager.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

class DownloadStationScan; // ov11, ctor not identified yet

// Defined in ov11
class CCompanyLogoScene : public CScene {
public:
    CCompanyLogoScene();
    virtual ~CCompanyLogoScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

public:
    int unk_04;
    int unk_08;
    SaveManager *unk_0C;
    BGLayer *unk_10[3];
    DownloadStationScan *unk_1C;
    int unk_20;
    int unk_24;
};

STATIC_SIZE_ASSERT(CCompanyLogoScene, 0x28);

#endif // POKERANGER2_SCENE_CCOMPANYLOGOSCENE_HPP
