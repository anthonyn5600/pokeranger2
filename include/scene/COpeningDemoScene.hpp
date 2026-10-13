#ifndef POKERANGER2_SCENE_COPENINGDEMOSCENE_HPP
#define POKERANGER2_SCENE_COPENINGDEMOSCENE_HPP

#include "common.hpp"
#include "scene/COPDScreen.hpp"
#include "scene/CScene.hpp"

class CTitleResource;

// Defined in ov3
class COpeningDemoScene : public CScene {
public:
    COpeningDemoScene();
    virtual ~COpeningDemoScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func3();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void ov3_02124CAC(int screen);
    void ov3_02124F18();

public:
    COPDScreen *m_screen;
    int m_current;
    int m_next;
    COPDCaptureDiscScreen m_capture;
    COPDTitleScreen m_title;
    COPDTexture m_textures[15];
    Camera2D *m_camera;
    GXOamAttr m_subOam[128];
    int m_visibleWnd;
    GXWndPlane m_wnd0Inside;
    GXWndPlane m_wndOutside;
    CTitleResource *m_resource;
    u8 unk_14D0;
};

STATIC_SIZE_ASSERT(COpeningDemoScene, 0x14D4);

#endif // POKERANGER2_SCENE_COPENINGDEMOSCENE_HPP
