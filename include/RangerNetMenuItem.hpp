#ifndef POKERANGER2_RANGERNETMENUITEM_HPP
#define POKERANGER2_RANGERNETMENUITEM_HPP

#include "common.hpp"

class OamSpriteSet;
class OamSprite;

// Defined in ov11
// 0x88-byte element of RangerNetMenu::unk_108[4]
class RangerNetMenuItem {
public:
    RangerNetMenuItem();
    ~RangerNetMenuItem();
    void Update();
    void Draw();
    void SetState(int a, int b);
    void SetId(int id);
    void SlideOutTop();
    void StartArrowAnim();
    void MoveToRow(int slot, int pos);
    void SetEnabled(int a);
    void StartBlink(fx32 v);
    BOOL IsEmpty()
    {
        return unk_38 == 0 ? TRUE : FALSE;
    }
    void InitLabel(OamSpriteSet **res, int idx, int v);
    void InitFrame(OamSpriteSet *res);
    void SetIcon(int type);
    void SetPos(int x, int y);
    void StartMove(fx32 a, fx32 b, fx32 c, fx32 d, int e, int f, int g);
    void SlideInLeft(int arg);
    void SlideOutLeft();
    void SlideInRight(int arg);
    void SlideOutRight();
    void SlideInBottom(int arg, int g);
    void SetVisible(BOOL visible);
    BOOL IsTouched();
    void UpdateMove();
    void UpdateArrows();
    void SetActive(BOOL active); // SetActive
    OamSpriteSet **unk_00;
    OamSpriteSet *unk_04;
    OamSpriteSet *unk_08;
    OamSprite *unk_0C;
    OamSprite *unk_10;
    OamSprite *unk_14;
    OamSprite **unk_18;
    int unk_1C;
    int unk_20;
    int unk_24;
    int unk_28;
    int unk_2C;
    int unk_30;
    int unk_34;
    int unk_38;
    int unk_3C;
    int unk_40;
    int unk_44;
    int unk_48;
    int unk_4C;
    int unk_50;
    int unk_54;
    int unk_58;
    u8 unk_5C[0x4];
    fx32 unk_60;
    fx32 unk_64;
    fx32 unk_68;
    fx32 unk_6C;
    int unk_70;
    fx32 unk_74;
    int unk_78;
    int unk_7C;
    int unk_80;
    int unk_84;
};

STATIC_SIZE_ASSERT(RangerNetMenuItem, 0x88);

#endif // POKERANGER2_RANGERNETMENUITEM_HPP
