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

    void Init();
    void Update();
    void Render();
    void OnVBlank();
    void LoadPalette();
    void Release();
    void WriteOam();
    void Load();
    BOOL Start();
    BOOL Setup();
    void RequestPlaceRsc(int id);
    void UpdateInput();
    void Close();
    void ShowPlace(u16 id);
    void DrawPlaceName();
    void SelectCurrentArea();
    void SelectArea(u16 id);
    void SetAreaMarker(u16 id, int mode);
    void FadeIn();
    void FadeOut();
    BOOL IsFading();
    int GetResult();

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
