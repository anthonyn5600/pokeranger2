#ifndef POKERANGER2_SCENE_CTITLESCENE_HPP
#define POKERANGER2_SCENE_CTITLESCENE_HPP

#include "CGame.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_0201FC80.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"
#include "scene/CTitleBG.hpp"
#include "sub_02006000.hpp"

class UnkClass_0200E960;
class UnkClass_02027FE8;
class UnkClass_02034478;

// Title screen BG/OBJ resources, kept in the save work (unk_8BA0) between title scenes
class CTitleResource {
public:
    CTitleResource()
    {
        unk_00 = NULL;
        unk_04 = NULL;
        unk_30 = 0;
        for (int i = 0; i < 10; i++) {
            m_sprites[i] = NULL;
        }
    }

    ~CTitleResource()
    {
        for (int i = 0; i < 10; i++) {
            SAFE_DELETE(m_sprites[i]);
        }
        SAFE_DELETE(unk_04);
        SAFE_DELETE(unk_00);
    }

    // Also used by COpeningDemoScene: its string literals are this inline's statics, so both TUs share them
    void Load(CGame *game)
    {
        unk_00 = new UnkClass_0201FC80((int)game);
        unk_00->SetBG(5);
        unk_00->LoadArchive("menu/", "title000_bg_");
        unk_00->LoadChar("title000", 0, 0, 0);
        unk_00->LoadPltt("title000", 0, 0, 0);
        unk_00->LoadScr("title000_00", 0, 0, 0, 0, 0);
        unk_00->ReleaseArchive();
        unk_00->Setup(0x100, 0x100);

        unk_04 = new UnkClass_0201FC80((int)game);
        unk_04->SetBG(5);
        unk_04->LoadArchive("menu/", "title004_bg_");
        unk_04->LoadChar("title004", 0, 0, 0);
        unk_04->LoadPltt("title004", 0, 0, 0);
        unk_04->LoadScr("title004_00", 0, 0, 0, 0, 0);
        unk_04->ReleaseArchive();
        unk_04->Setup(0x100, 0x100);

        m_sprites[1] = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[0x00], game->unk_14A8, TRUE, 0x40);
        m_sprites[0] = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[0x18], game->unk_14A8, TRUE, 0x40);
        m_sprites[4] = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[0x30], game->unk_14A8, TRUE, 0x40);
        m_sprites[2] = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[0x18], game->unk_14A8, TRUE, 0x40);
        m_sprites[3] = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[0x00], game->unk_14A8, TRUE, 0x40);
        m_sprites[5] = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[0x00], game->unk_14A8, TRUE, 0x40);
        for (int i = 0; i < 4; i++) {
            m_sprites[6 + i] = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[0x40], game->unk_14A8, TRUE, 0x40);
        }

        unk_30 = 0;
        int ofs = unk_30;
        ofs += m_sprites[1]->sub_0200F168("data/menu", "title002_00", 0, 0);
        ofs += m_sprites[0]->sub_0200F168("data/menu", "title001_00", ofs / 32, 2);
        ofs += m_sprites[4]->sub_0200F168("data/menu", "ma003_00", ofs / 32, 4);
        ofs += m_sprites[2]->sub_0200F168("data/menu", "title003_00", ofs / 32, 6);
        ofs += m_sprites[3]->sub_0200F168("data/menu", "title005_00", ofs / 32, 12);
        ofs += m_sprites[5]->sub_0200F168("data/menu", "title005_01", ofs / 32, 13);
        unk_30 = ofs;
        int i;
        int ofs2 = unk_30;
        for (i = 0; i < 4; i++) {
            char name[0x60];
            OS_SPrintf(name, "tp%03d", i);
            ofs2 += m_sprites[6 + i]->sub_0200F168("data/menu", name, ofs2 / 32, i + 8);
        }
        unk_30 = ofs2;
    }

    UnkClass_0200ECD0 *GetSprite(int idx)
    {
        if (idx >= 0 && idx < 10) {
            m_sprites[idx]->sub_0200F398();
            m_sprites[idx]->sub_0200F4A8();
            return m_sprites[idx];
        }
        return NULL;
    }

public:
    UnkClass_0201FC80 *unk_00;
    UnkClass_0201FC80 *unk_04;
    UnkClass_0200ECD0 *m_sprites[10];
    int unk_30;
};

STATIC_SIZE_ASSERT(CTitleResource, 0x34);

// Defined in ov3
class CTitleScene : public CScene {
public:
    CTitleScene(CGame *game);
    virtual ~CTitleScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func3();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void SetState(int state)
    {
        unk_E0 = unk_DC;
        unk_DC = state;
    }

    void ov3_0211CD2C();
    void ov3_0211CD6C();
    void ov3_0211CD8C();
    void ov3_0211D1B0();
    void ov3_0211DD90();
    void ov3_0211DF20();
    void ov3_021202E0();
    void ov3_0212038C(int msg);
    void ov3_02120634();
    void ov3_0212069C();
    void ov3_021206E8(int y);

public:
    UnkClass_02034478 *m_audioEngine;
    CGame *m_game;
    u32 m_flags;
    u16 unk_10;
    u32 unk_14;
    int unk_18;
    int unk_1C;
    int unk_20;
    UnkClass_0201FC80 *unk_24;
    UnkClass_0200E960 *unk_28;
    UnkClass_0200E960 *unk_2C;
    UnkClass_0200E960 *unk_30;
    UnkClass_0200E960 *unk_34;
    UnkClass_0200E960 *unk_38;
    UnkClass_0200E960 *unk_3C;
    UnkClass_0200ECD0 *unk_40;
    UnkClass_0200ECD0 *unk_44[4];
    UnkClass_0200ECD0 *unk_54;
    UnkClass_0200ECD0 *unk_58;
    Rectangle unk_5C;
    Rectangle unk_6C;
    Rectangle unk_7C;
    UnkClass_020091E8_004 *unk_8C;
    UnkClass_020091E8_004 *unk_90;
    u16 unk_94;
    u16 unk_96;
    int unk_98;
    int unk_9C;
    fx32 unk_A0;
    UnkClass_0201FC80 *unk_A4;
    UnkClass_0200E960 *unk_A8;
    UnkClass_0200E960 *unk_AC;
    UnkClass_0200ECD0 *unk_B0;
    Circle unk_B4;
    Circle unk_C0;
    UnkClass_0200E960 *unk_CC;
    UnkClass_0200ECD0 *unk_D0;
    UnkClass_0200E960 *unk_D4;
    UnkClass_0200ECD0 *unk_D8;
    int unk_DC;
    int unk_E0;
    UnkClass_02027FE8 *unk_E4;
    int unk_E8;
    CTitleBG *m_bg;
    CTitleResource *m_resource;
    int unk_F4;
    u8 unk_F8;
    int unk_FC;
};

STATIC_SIZE_ASSERT(CTitleScene, 0x100);

#endif // POKERANGER2_SCENE_CTITLESCENE_HPP
