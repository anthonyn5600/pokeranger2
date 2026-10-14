#ifndef POKERANGER2_SCENE_COPTIONSCENE_HPP
#define POKERANGER2_SCENE_COPTIONSCENE_HPP

#include "CGame.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_02025648.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

// Defined in ov6
class COptionScene : public CScene {
public:
    COptionScene(CGame *game);
    virtual ~COptionScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func3();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void ov6_0211D460();
    void ov6_0211D638();
    void ov6_0211D6B4();

public:
    UnkClass_0200ECD0 *m_sprites;
    UnkClass_0200ECD0 *m_backSprites;
    // 0-2: text speed, 3-10: window frame, 11: frame cursor
    UnkClass_0200E960 *m_buttons[12];
    UnkClass_0200E960 *m_backButton;
    int m_buttonIds[12];
    CGame *m_game;
    int m_fadeTimer;
    u32 unk_78;
    int m_frame;
    int m_textSpeed;
    UnkClass_02025648 *unk_84;
    UnkClass_020091E8_004 *m_messages;
};

STATIC_SIZE_ASSERT(COptionScene, 0x8C);

#endif // POKERANGER2_SCENE_COPTIONSCENE_HPP
