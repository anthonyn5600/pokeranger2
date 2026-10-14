#ifndef POKERANGER2_SCENE_CMAPDISPSCREEN_HPP
#define POKERANGER2_SCENE_CMAPDISPSCREEN_HPP

#include <nitro.h>

#include "CGame.hpp"
#include "MessageTable.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "RegionMap.hpp"
#include "common.hpp"
#include "scene/CMapDispRscLoader.hpp"

// Defined in ov28
class CMapDispScreen {
public:
    class CPathBuilder : public IMapDispRscPathBuilder {
    public:
        virtual BOOL GetArchivePath(int id, char *buf, int size);
        virtual BOOL GetFilePath(int id, char *buf, int size);
    };

    CMapDispScreen(CGame *game);
    ~CMapDispScreen();

    void ov28_0211D19C();
    void ov28_0211D218();
    void ov28_0211D2DC();
    void ov28_0211D344();
    void ov28_0211D368();
    void ov28_0211D380();
    void ov28_0211D450();
    void ov28_0211D468();
    BOOL ov28_0211D700();
    BOOL ov28_0211D718();
    void ov28_0211D748(int id);
    void ov28_0211D794();
    void ov28_0211D844();
    void ov28_0211D88C(u16 id);
    void ov28_0211D8AC();
    void ov28_0211D980();
    void ov28_0211D9AC(u16 id);
    void ov28_0211D9D0(u16 id, int mode);
    void ov28_0211D9E0();
    void ov28_0211DA24();
    BOOL ov28_0211DA68();
    int ov28_0211DAB0();

public:
    u16 unk_00;
    int unk_04; // text needs redraw
    CMapDispRscLoader *unk_08;
    RegionMap *unk_0C;
    u32 unk_10;
    MessageTable *unk_14;
    OamSpriteSet *unk_18;
    u32 unk_1C;
    OamSprite *unk_20[6];
    u16 unk_38;
    CGame *unk_3C;
    CPathBuilder unk_40;
};

STATIC_SIZE_ASSERT(CMapDispScreen, 0x44);

#endif // POKERANGER2_SCENE_CMAPDISPSCREEN_HPP
