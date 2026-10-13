#ifndef POKERANGER2_SCENE_COPDSCREEN_HPP
#define POKERANGER2_SCENE_COPDSCREEN_HPP

#include "common.hpp"
#include "field/CPrimitiveNTF.hpp"

class Camera2D;

// Opening demo texture: an NtfTexture plus its frame layout from the scene's table
struct COPDTexture {
    COPDTexture()
    {
        unk_1C = 0;
        unk_20 = 0;
        unk_24 = 0;
        unk_28 = 0;
    }

    void SetSize(int width, int height)
    {
        unk_20 = width;
        unk_24 = height;
    }

    NtfTexture m_tex;
    int unk_1C;
    int unk_20;
    int unk_24;
    int unk_28;
};

STATIC_SIZE_ASSERT(COPDTexture, 0x2C);

// Defined in ov3: one screen of the opening demo
class COPDScreen {
public:
    virtual ~COPDScreen();
    virtual void Init() = 0;
    virtual void Release() = 0;
    virtual void Start(COPDTexture *textures) = 0;
    virtual void Stop() = 0;
    virtual int Update() = 0;
    virtual void Render(Camera2D *camera, int flip) = 0;
};

// Defined in ov3
class COPDCaptureDiscScreen : public COPDScreen {
public:
    COPDCaptureDiscScreen(); // ov3_02126ECC
    virtual ~COPDCaptureDiscScreen(); // ov3_02127350
    virtual void Init();
    virtual void Release();
    virtual void Start(COPDTexture *textures);
    virtual void Stop();
    virtual int Update();
    virtual void Render(Camera2D *camera, int flip);

public:
    u8 unk_004[0x804];
};

STATIC_SIZE_ASSERT(COPDCaptureDiscScreen, 0x808);

// Defined in ov3
class COPDTitleScreen : public COPDScreen {
public:
    COPDTitleScreen(); // ov3_021251DC
    virtual ~COPDTitleScreen(); // ov3_021255B8
    virtual void Init();
    virtual void Release();
    virtual void Start(COPDTexture *textures);
    virtual void Stop();
    virtual int Update();
    virtual void Render(Camera2D *camera, int flip);

public:
    u8 unk_004[0x60F];
    u8 unk_613;
};

STATIC_SIZE_ASSERT(COPDTitleScreen, 0x614);

#endif // POKERANGER2_SCENE_COPDSCREEN_HPP
