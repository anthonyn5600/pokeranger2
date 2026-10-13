#ifndef POKERANGER2_SCENE_CCOMPANYLOGOSCENE_HPP
#define POKERANGER2_SCENE_CCOMPANYLOGOSCENE_HPP

#include "UnkClass_0201FC80.hpp"
#include "UnkClass_02027FE8.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

class UnkClass_0212F3DC; // ov11, ctor not identified yet

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
    UnkClass_02027FE8 *unk_0C;
    UnkClass_0201FC80 *unk_10[3];
    UnkClass_0212F3DC *unk_1C;
    int unk_20;
    int unk_24;
};

STATIC_SIZE_ASSERT(CCompanyLogoScene, 0x28);

#endif // POKERANGER2_SCENE_CCOMPANYLOGOSCENE_HPP
