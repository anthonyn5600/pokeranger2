#include "field/CFieldPlayer.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "CTouchPanel.hpp"
#include "Camera2D.hpp"
#include "UnkClass_02001C04.hpp"
#include "UnkClass_02007F98.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_02022404.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkClass_020B26A0.hpp"
#include "UnkStruct_020107A8.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "field/CFieldPartnerManage.hpp"
#include "fx_utils.hpp"
#include "interpolation.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldPlayer *MAIN_BSS_0210CA48;
extern CFieldScene *MAIN_BSS_0210CA40;
extern u16 DAT_0208d58c;
extern UnkClass_020B26A0 MAIN_BSS_020B26A0;
extern UnkClass_02041D80 *MAIN_BSS_0210CA6C;
extern u16 *MAIN_BSS_0210CA70;

extern "C" {
void ov0_0213EA6C(Point2D *out, Point2D cell, int floor, int arg3);
void sub_02041A70(CFieldActor *actor, int arg1, int arg2);
void sub_02016DA4(UnkClass_020B26A0 *save, int arg1);
}

fx32 sub_02007254(fx32 x, fx32 y);

// Offsets from the player for the trail effect, by direction.
static const Point2D sTrailOffsets[8] = {
    { 0, -0x10000 },
    { -0x8000, -0x10000 },
    { -0xC000, -0x14000 },
    { -0x8000, -0x18000 },
    { 0, -0x20000 },
    { 0x8000, -0x18000 },
    { 0xC000, -0x14000 },
    { 0x8000, -0x10000 },
};

CFieldPlayer::CFieldPlayer()
{
    MAIN_BSS_0210CA48 = this;
    unk_10 = 0x1CCC;
    unk_E0 = 0x7000;
    unk_E8 = 7;
    unk_EC = 0;
    Rectangle bounds = { { 0, -0x8000 }, { 0x10000, 0x20000 } };
    unk_24.pos.x = bounds.pos.x;
    unk_24.pos.y = bounds.pos.y;
    unk_24.size.x = bounds.size.x;
    unk_24.size.y = bounds.size.y;
    unk_78 = 1;
    ResetMove();
    unk_108 = 1;
    unk_10C = 0;
    unk_110 = 0;
    unk_E4 = 0;
    unk_138 = 0;
    unk_13C = 0;
    unk_98 = 0;
    unk_14C = 0;
    unk_148 = 0xF0;
    ov0_02133EB4();
    unk_1B4 = 1;
}

CFieldPlayer::~CFieldPlayer()
{
    MAIN_BSS_0210CA48 = NULL;
}

void CFieldPlayer::ov0_021307B0(UnkClass_02001C04 *pad, CTouchPanel *touch, Camera2D *camera, CFieldMap *map, u32 flags)
{
    int quantDir = 0xFFFF;
    int baseSpeed = 0xF0000 / DAT_0208d58c;
    if (MAIN_BSS_0210CA6C != NULL) {
        UnkStruct_02041D80 *info = sub_02041D80(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.unk_001A);
        baseSpeed = info->unk_50 * 60 / DAT_0208d58c;
    }
    BOOL smooth = (flags & 2) ? TRUE : FALSE;
    unk_6C = map;
    unk_FC.x = 0;
    unk_FC.y = 0;
    unk_104 = 0;
    if (flags & 1) {
        if ((unk_10C & 1) && (unk_E4 & 2)) {
            switch (unk_140) {
            case 0:
                break;
            case 1:
                sub_020129F4_(0, 8);
                break;
            case 2:
                StartBlink();
                break;
            }
        } else {
            sub_020129F4_(0, 0x1F);
            ClearUnk1A8Bits(2);
        }
    }
    if (flags & 1) {
        Point2D pos = GetPos();
        Point2D newPos = GetPos();
        int dir = 0;
        BOOL moving = FALSE;
        int speed = unk_10 * 60 / DAT_0208d58c;
        int vx = unk_114 * 60 / DAT_0208d58c;
        int vy = unk_118 * 60 / DAT_0208d58c;
        switch (unk_110) {
        case 0:
        default:
            if (touch != NULL && touch->unk_04) {
                unk_1B4 = 1;
            }
            if (pad != NULL) {
                u16 held = pad->unk_0000;
                if ((u16)(held & 0x40)) {
                    moving = TRUE;
                    if ((u16)(held & 0x20)) {
                        dir = 0xA000;
                    } else if ((u16)(held & 0x10)) {
                        dir = 0xE000;
                    } else {
                        dir = 0xC000;
                    }
                } else if ((u16)(held & 0x80)) {
                    moving = TRUE;
                    if ((u16)(held & 0x20)) {
                        dir = 0x6000;
                    } else if ((u16)(held & 0x10)) {
                        dir = 0x2000;
                    } else {
                        dir = 0x4000;
                    }
                } else if ((u16)(held & 0x20)) {
                    moving = TRUE;
                    dir = 0x8000;
                } else if ((u16)(held & 0x10)) {
                    moving = TRUE;
                    dir = 0;
                }
            }
            if (touch != NULL && !moving && unk_1B4 != 0 && touch->unk_05) {
                fx32 x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
                fx32 y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
                x -= camera->unk_1C;
                y -= camera->unk_20;
                moving = TRUE;
                x -= GetX();
                y -= GetY();
                dir = FX_Div(FX_Atan2(y, x) << 4, 0x6486);
            }
            break;
        case 1:
            moving = TRUE;
            speed = 0xF0000 / DAT_0208d58c;
            dir = FX_Div(FX_Atan2(vy, vx) << 4, 0x6486);
            SetUnk8C(QuadraticInterpolate(0, 0x20000, 0, unk_138, unk_144));
            if (--unk_138 <= 0) {
                SetUnk8C(0);
                if (MAIN_BSS_020B26A0.unk_0001 == 0) {
                    unk_110 = 7;
                } else {
                    unk_138 = 10;
                    unk_110 = 2;
                }
            }
            break;
        case 2:
            if (--unk_138 <= 0) {
                unk_110 = 0;
                sub_0201287C_();
                sub_show();
            }
            break;
        case 3:
            switch (unk_13C) {
            case 0:
                SetPosXY(GetX() + vx, GetY());
                SetUnk8C(GetUnk8C() - vy);
                unk_118 += unk_128;
                if (unk_118 > unk_12C) {
                    unk_118 = unk_12C;
                }
                if (vx < 0) {
                    vx = -vx;
                }
                unk_120 += vx;
                if ((unk_114 != 0 && unk_120 >= unk_124) || (unk_114 == 0 && GetUnk8C() <= unk_11C)) {
                    if (unk_118 < unk_12C) {
                        unk_118 = unk_12C;
                    }
                    unk_13C = 1;
                }
                break;
            case 3:
                if (--unk_138 <= 0) {
                    unk_118 = unk_12C;
                    unk_13C = 1;
                    if (unk_08->unk_0C->unk_1A0 != 0x8000) {
                        sub_0202DC54(0x1000, 0);
                    }
                }
                break;
            case 1:
                SetUnk8C(GetUnk8C() - vy);
                if (GetUnk8C() > 0) {
                    break;
                }
                SetUnk8C(0);
                if (unk_08->unk_0C->unk_1A0 != 0x8000) {
                    sub_0202DC54(0x400, 0);
                }
                s_game->m_audioEngine->sub_02034C44(0x11E);
                unk_13C = 2;
            case 2:
                unk_130 -= 60 / DAT_0208d58c;
                if (unk_130 <= 0) {
                    if (MAIN_BSS_020B26A0.unk_0001 != 0) {
                        sub_020128EC_(unk_134);
                        unk_110 = 0;
                        sub_0201287C_();
                        sub_show();
                    } else {
                        unk_110 = 7;
                    }
                    if (MAIN_BSS_0210CA4C != NULL) {
                        MAIN_BSS_0210CA4C->ov0_0213A96C(FALSE, 0, TRUE);
                    }
                    unk_10C &= ~1;
                    unk_E4 = 0;
                    unk_140 = 0;
                }
                break;
            }
            break;
        case 4:
            if (!IsUnk00CSet()) {
                unk_110 = 0;
            }
            break;
        case 5:
            if (GetAnimState() == 0) {
                sub_0201287C_();
                sub_0202DC54(0x100, 0);
                unk_110 = 0;
            }
            break;
        case 6:
            if (GetAnimState() == 0) {
                sub_0201287C_();
                sub_show();
                unk_110 = 0;
            }
            break;
        }
        if ((unk_10C & 1) && unk_E4 >= 0) {
            if (--unk_E4 <= 0) {
                unk_10C &= ~1;
            }
        }
        int dx = 0;
        int dy = 0;
        if (unk_6C != NULL) {
            CFieldMapLayerAttribute *attr = unk_6C->GetAttributeLayer(unk_14);
            if (attr != NULL) {
                switch (attr->GetCellAtPos(pos.x, pos.y)) {
                case 15:
                    dy -= baseSpeed;
                    break;
                case 16:
                    dx += baseSpeed;
                    break;
                case 17:
                    dy += baseSpeed;
                    break;
                case 18:
                    dx -= baseSpeed;
                    break;
                case 12:
                    smooth = TRUE;
                    break;
                case 14:
                case 23:
                    speed = 0x23FDC / DAT_0208d58c;
                    break;
                case 6:
                    if (unk_08->unk_0C->unk_1A0 == 0x8000) {
                        speed = 0x83FF4 / DAT_0208d58c;
                    } else {
                        speed = 0x3C000 / DAT_0208d58c;
                    }
                    break;
                case 8:
                    if (unk_08->unk_0C->unk_1A0 == 0x8000) {
                        speed = 0x71FE8 / DAT_0208d58c;
                    } else {
                        speed = 0x47FF4 / DAT_0208d58c;
                    }
                    break;
                }
            }
        }
        if (unk_08->unk_0C->unk_1A0 == 0x80000 || unk_08->unk_0C->unk_1A0 == 0x800000) {
            smooth = TRUE;
        }
        if (smooth) {
            if (moving) {
                dx += FX32_MUL(speed, FX_CosIdx((u16)dir));
                dy += FX32_MUL(speed, FX_SinIdx((u16)dir));
            }
            int old = unk_F4.x;
            if (dx != old) {
                int max = dx > old ? dx : old;
                dx = (dx * (1000 - unk_108) + old * unk_108) / 1000;
                if (dx > max) {
                    dx = max;
                }
            }
            old = unk_F4.y;
            if (dy != old) {
                int max = dy > old ? dy : old;
                dy = (dy * (1000 - unk_108) + old * unk_108) / 1000;
                if (dy > max) {
                    dy = max;
                }
            }
        } else if (moving && speed != 0) {
            dx += FX32_MUL(speed, FX_CosIdx((u16)dir));
            dy += FX32_MUL(speed, FX_SinIdx((u16)dir));
        }
        if (dx != 0 || dy != 0) {
            if (MATH_ABS(dx) < 0x28) {
                dx = 0;
            }
            if (MATH_ABS(dy) < 0x28) {
                dy = 0;
            }
            unk_F4.x = dx;
            unk_F4.y = dy;
            newPos.x += dx;
            newPos.y += dy;
            if (unk_E8 & 1) {
                PointPair2D seg = { pos, newPos };
                int mode = 1;
                if (unk_08->unk_0C->unk_1A0 == 0x8000) {
                    mode |= 4;
                }
                if (sub_0203CF40(seg, unk_E0, mode)) {
                    if (!sub_0203D110(unk_64, FX32_MUL(unk_E0, 0xF33), mode)) {
                        newPos = GetPrevPos();
                    } else {
                        newPos = pos;
                    }
                }
            }
            if (newPos.x != pos.x || newPos.y != pos.y) {
                if (unk_08 != NULL && unk_08->unk_0C != NULL) {
                    unk_08->unk_0C->m_motion.sub_02011AB0(newPos, 1);
                }
            }
            unk_FC.x = newPos.x - pos.x;
            unk_FC.y = newPos.y - pos.y;
            unk_104 = sub_02007254(unk_FC.x, unk_FC.y);
            if (unk_08->unk_0C->unk_1A0 == 0x80000) {
                if (unk_104 >= 0x5B33) {
                    if (unk_D0 == 0) {
                        sub_02041A70(this, 4, -1);
                    }
                    if (unk_54 == 0 && unk_08 != NULL) {
                        unk_54 = 1;
                        if (unk_08->unk_0C != NULL) {
                            unk_08->unk_0C->sub_02012B68(1, 8, 1, -3, 0, 0);
                        }
                    }
                } else {
                    if (unk_D0 != 0) {
                        sub_02041C1C(this);
                    }
                    if (unk_54 != 0) {
                        unk_54 = 0;
                        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
                            unk_08->unk_0C->sub_02012C00();
                        }
                    }
                }
            }
        }
        int angle = (u16)dir;
        if (moving) {
            quantDir = (angle & 0xE000) + ((angle & 0x1000) ? 0x2000 : 0);
        }
        if (unk_6C != NULL) {
            CFieldMapLayerCollision *coll = unk_6C->GetLayer(unk_14);
            if (coll != NULL) {
                int cell = coll->GetCellAtPos(GetX(), GetY());
                if (unk_110 == 0 || unk_110 == 1) {
                    switch (cell) {
                    case 0x40:
                        sub_0202E68C(unk_14 + 1);
                        break;
                    case 0x41:
                        sub_0202E68C(unk_14 - 1);
                        break;
                    case 0x33:
                        if (quantDir == 0 || quantDir == 0xE000 || quantDir == 0x2000) {
                            ov0_021337DC(0, 0x2000, 0x2000, -0x2000, 0x4CC, 0x2000, 0x20000, 0x10000, 0, 0);
                        }
                        break;
                    case 0x34:
                        if (quantDir == 0x8000 || quantDir == 0xA000 || quantDir == 0x6000) {
                            ov0_021337DC(0x8000, 0xA000, -0x2000, -0x2000, 0x4CC, 0x2000, 0x20000, 0x10000, 0, 0);
                        }
                        break;
                    case 0x35:
                        if (quantDir == 0x4000 || quantDir == 0x6000 || quantDir == 0x2000) {
                            ov0_021337DC(0x4000, 0x6000, 0, -0x2000, 0x4CC, 0x2000, 0, 0x28000, 0, 0);
                        }
                        break;
                    case 0x36:
                        if (quantDir == 0xC000 || quantDir == 0xA000 || quantDir == 0xE000) {
                            ov0_021337DC(0xC000, 0xE000, 0, -0x2000, 0x4CC, 0x2000, 0, 0x28000, 0, 0);
                        }
                        break;
                    case 0x37:
                        if (quantDir == 0 || quantDir == 0xE000 || quantDir == 0x2000) {
                            ov0_021337DC(0, 0x2000, 0x2000, -0x2000, 0x4CC, 0x2000, 0x20000, 0x20000, 8, 0);
                        }
                        break;
                    case 0x38:
                        if (quantDir == 0x8000 || quantDir == 0xA000 || quantDir == 0x6000) {
                            ov0_021337DC(0x8000, 0xA000, -0x2000, -0x2000, 0x4CC, 0x2000, 0x20000, 0x20000, 8, 0);
                        }
                        break;
                    case 0x39:
                        if (quantDir == 0x4000 || quantDir == 0x6000 || quantDir == 0x2000) {
                            ov0_021337DC(0x4000, 0x6000, 0, -0x2000, 0x4CC, 0x2000, 0, 0x38000, 8, 0);
                        }
                        break;
                    case 0x3A:
                        if (quantDir == 0xC000 || quantDir == 0xA000 || quantDir == 0xE000) {
                            ov0_021337DC(0xC000, 0xE000, 0, -0x2000, 0x4CC, 0x2000, 0, 0x38000, 8, 0);
                        }
                        break;
                    case 0x3B:
                        if (quantDir == 0 || quantDir == 0xE000 || quantDir == 0x2000) {
                            ov0_021337DC(0, 0x2000, 0x2000, -0x3000, 0x800, 0x3000, 0x20000, 0x40000, 0x10, 1);
                        }
                        break;
                    case 0x3C:
                        if (quantDir == 0x8000 || quantDir == 0xA000 || quantDir == 0x6000) {
                            ov0_021337DC(0x8000, 0xA000, -0x2000, -0x3000, 0x800, 0x3000, 0x20000, 0x40000, 0x10, 1);
                        }
                        break;
                    case 0x3D:
                        if (quantDir == 0x4000 || quantDir == 0x6000 || quantDir == 0x2000) {
                            ov0_021337DC(0x4000, 0x6000, 0, -0x3000, 0x800, 0x3000, 0, 0x50000, 0x10, 1);
                        }
                        break;
                    case 0x3E:
                        if (quantDir == 0xC000 || quantDir == 0xA000 || quantDir == 0xE000) {
                            ov0_021337DC(0xC000, 0xE000, 0, -0x3000, 0x800, 0x3000, 0, 0x50000, 0x10, 1);
                        }
                        break;
                    }
                }
            }
            CFieldMapLayerAttribute *attr = unk_6C->GetAttributeLayer(unk_14);
            if (attr != NULL) {
                int attrCell = attr->GetCellAtPos(GetX(), GetY());
                Point2D center;
                center.x = (((GetX() >> FX32_SHIFT) & ~0xF) + 8) << FX32_SHIFT;
                center.y = (((GetY() >> FX32_SHIFT) & ~0xF) + 8) << FX32_SHIFT;
                if (unk_110 == 0) {
                    switch (attrCell) {
                    case 14:
                    case 23:
                        if (!moving) {
                            if (GetUnkC0() != 7 && GetUnkC0() != 8) {
                                sub_reset();
                                if (GetDir() != 0 && GetDir() < 0x8000) {
                                    sub_0202DC54(0x100, 0);
                                } else {
                                    sub_0202DC54(0x80, 0);
                                }
                            }
                            ClearUnk004Bit8();
                        } else if (angle > 0 && angle < 0x8000) {
                            SetUnk004Bit8();
                            if (GetUnkC0() != 8) {
                                sub_reset();
                                sub_0202DC54(0x100, 0);
                            }
                        } else {
                            SetUnk004Bit8();
                            if (GetUnkC0() != 7) {
                                sub_reset();
                                sub_0202DC54(0x80, 0);
                            }
                        }
                        unk_90 = 1;
                        SetUnk8C(0);
                        break;
                    case 13:
                        if ((angle >= 0x2000 && angle <= 0x6000) || (angle >= 0xA000 && angle <= 0xE000)) {
                            if (unk_F0 & 2) {
                                SetUnk8C(0x2000);
                            } else {
                                SetUnk8C(0);
                            }
                        } else {
                            SetUnk8C(0);
                        }
                        sub_show();
                        SetUnk004Bit8();
                        unk_90 = 1;
                        break;
                    case 6:
                        unk_90 = 0;
                        sub_show();
                        SetUnk004Bit8();
                        SetUnk8C(0);
                        break;
                    case 12:
                        if (quantDir == 0xFFFF) {
                            sub_reset();
                            SetUnk1DC(0);
                        } else {
                            sub_show();
                        }
                        SetUnk004Bit8();
                        unk_90 = 1;
                        SetUnk8C(0);
                        break;
                    case 19:
                        if (unk_110 != 4) {
                            unk_110 = 4;
                            Point2D dest = center;
                            dest.y -= 0x10000;
                            MoveTo(dest, 0x4000);
                            sub_020128EC_(0xC000);
                        }
                        sub_reset();
                        SetUnk1DC(0);
                        SetUnk004Bit8();
                        unk_90 = 1;
                        SetUnk8C(0);
                        break;
                    case 20:
                        if (unk_110 != 4) {
                            unk_110 = 4;
                            Point2D dest = center;
                            dest.x += 0x10000;
                            MoveTo(dest, 0x4000);
                            sub_020128EC_(0);
                        }
                        sub_reset();
                        SetUnk1DC(0);
                        SetUnk004Bit8();
                        unk_90 = 1;
                        SetUnk8C(0);
                        break;
                    case 21:
                        if (unk_110 != 4) {
                            unk_110 = 4;
                            Point2D dest = center;
                            dest.y += 0x10000;
                            MoveTo(dest, 0x4000);
                            sub_020128EC_(0x4000);
                        }
                        sub_reset();
                        SetUnk1DC(0);
                        SetUnk004Bit8();
                        unk_90 = 1;
                        SetUnk8C(0);
                        break;
                    case 22:
                        if (unk_110 != 4) {
                            unk_110 = 4;
                            Point2D dest = center;
                            dest.x -= 0x10000;
                            MoveTo(dest, 0x4000);
                            sub_020128EC_(0x8000);
                        }
                        sub_reset();
                        SetUnk1DC(0);
                        SetUnk004Bit8();
                        unk_90 = 1;
                        SetUnk8C(0);
                        break;
                    default:
                        if (GetUnkC0() != 4 && GetUnk1D8() == 3) {
                            sub_show();
                            SetUnk004Bit8();
                            unk_90 = 1;
                            SetUnk8C(0);
                        }
                        break;
                    }
                }
            }
        }
        if (!moving) {
            unk_F0 = 0;
            if ((++unk_EC & 0x1FF) == 0) {
                if (unk_08->unk_0C->unk_1A0 == 2 && GetUnk1D8() == 0) {
                    sub_reset();
                    sub_0202DC54(0x10, 0);
                }
            } else if (GetAnimState() == 0 && GetUnkC0() == 4) {
                sub_show();
            }
        } else {
            unk_F0++;
            unk_EC = 0;
            if (GetUnkC0() == 4) {
                sub_show();
            }
        }
        if (unk_110 == 0) {
            if (quantDir == 0xFFFF) {
                sub_020128D8_();
                if (GetUnk1D8() != 0 && GetUnk1D8() != 3 && GetUnkC0() != 8 && GetUnkC0() != 7) {
                    sub_reset();
                    SetUnk1DC(0);
                }
            } else {
                sub_020128EC_(quantDir);
                if (GetUnk1D8() != 3 && GetUnkC0() != 8 && GetUnkC0() != 7) {
                    sub_reset();
                    SetUnk1DC(1);
                }
            }
        }
        ov0_02132E68(moving);
    } else {
        unk_F0 = 0;
    }
    sub_0203C87C(map);
    int animState = GetUnk1D8();
    if (unk_08->unk_0C->unk_1A0 == 0x80000 || unk_08->unk_0C->unk_1A0 == 0x800000) {
        if (animState == 1 && !s_game->m_audioEngine->sub_02034C84(0x10E)) {
            s_game->m_audioEngine->sub_02034C44(0x10E);
        } else if (animState == 0 && s_game->m_audioEngine->sub_02034C84(0x10E)) {
            s_game->m_audioEngine->sub_02034C5C(0x10E);
        }
        if (animState == 1 && !(unk_F0 & 0xF)) {
            sub_02016DA4(&MAIN_BSS_020B26A0, 1);
        }
    } else if (animState == 1 && unk_B8 > 0 && unk_7C == 0) {
        sub_02016DA4(&MAIN_BSS_020B26A0, 1);
    }
    if (MAIN_BSS_0210CA70 != NULL) {
        MAIN_BSS_0210CA70[2] = quantDir;
    }
    if (s_game->currentScene->getSceneId() != 1) {
        return;
    }
    if (MAIN_BSS_020B26A0.unk_8B64 == 1) {
        unk_14C += 60 / DAT_0208d58c;
        if ((u32)unk_14C >= (u32)unk_148) {
            CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
            if (mgr != NULL) {
                int i = sub_02007DF0(8, GetDir(), 0);
                mgr->ov0_02143344(sTrailOffsets[i].x + GetX(), sTrailOffsets[i].y + GetY());
            }
            unk_14C = 0;
        }
    }
    ov0_02133EE4();
}

void CFieldPlayer::ov0_02132E68(BOOL arg1)
{
    CFieldPartnerManage *mgr = MAIN_BSS_0210CA4C;
    if (mgr == NULL) {
        return;
    }
    if (arg1) {
        mgr->ov0_02139E14(0);
        return;
    }
    if (unk_08->IsUnk00CSet()) {
        mgr->ov0_02139E14(0);
    } else {
        mgr->ov0_02139E14(1);
    }
}

BOOL CFieldPlayer::ov0_02132EE4(u16 arg1, int arg2, u32 arg3)
{
    return sub_0203C418(4, arg1, arg2, arg3, 1);
}

BOOL CFieldPlayer::ov0_02132F14(u8 arg1, int arg2, u8 arg3)
{
    int base = arg2 == 0 ? 1 : 3;
    BOOL result = ov0_02132EE4((arg1 & 1) + base, 0, 0x1FFFFFFE);
    if (result) {
        if (arg3 == 1) {
            SetMasks(0x20, 0x40);
        } else {
            SetMasks(2, 4);
        }
    }
    return result;
}

void CFieldPlayer::ov0_02132FA0(u8 mode)
{
    UnkStruct_020107A8 *info;
    void *table = s_game->unk_1434;
    switch (mode) {
    case 0:
    default:
        SetMasks(2, 4);
        unk_10 = 0x1CCC;
        unk_108 = 0x3CA;
        unk_B4 = 0x109;
        unk_B8 = 0x18;
        SetUnkBE(0x10, 0xA);
        SetUnkBC(0, 0);
        break;
    case 1:
        SetMasks(0x20, 0x40);
        unk_10 = 0x1E66;
        unk_108 = 0x3BB;
        unk_B4 = -1;
        unk_B8 = 0;
        SetUnkBE(0x10, 0xA);
        SetUnkBC(0, 0);
        break;
    case 2:
        SetMasks(0x8000, 0x10000);
        unk_10 = 0x3000;
        unk_108 = 0x3CA;
        unk_B4 = 0x10D;
        unk_B8 = 0x10;
        info = sub_020107A8(table, 0x2B);
        SetUnkBE(info->unk_0C, info->unk_0D);
        SetUnkBC(info->unk_0A, info->unk_0B);
        break;
    case 3:
        SetMasks(0x80000, 0x100000);
        unk_10 = 0x2800;
        unk_108 = 0x352;
        unk_B4 = 0x10E;
        unk_B8 = 0;
        info = sub_020107A8(table, 0xA9);
        SetUnkBE(info->unk_0C, info->unk_0D);
        SetUnkBC(info->unk_0A, info->unk_0B);
        break;
    case 4:
        SetMasks(0x800000, 0x1000000);
        unk_10 = 0x2800;
        unk_108 = 0x352;
        unk_B4 = 0x10E;
        unk_B8 = 0;
        info = sub_020107A8(table, 0xBE);
        SetUnkBE(info->unk_0C, info->unk_0D);
        SetUnkBC(info->unk_0A, info->unk_0B);
        break;
    case 5:
        SetMasks(0x2000000, 0x4000000);
        unk_10 = 0x1CCC;
        unk_108 = 0x384;
        unk_B4 = -1;
        unk_B8 = 0;
        unk_B4 = 0x10E;
        unk_B8 = 0;
        info = sub_020107A8(table, 0xAC);
        SetUnkBE(info->unk_0C, info->unk_0D);
        SetUnkBC(info->unk_0A, info->unk_0B);
        break;
    case 6:
        SetMasks(0x20000, 0x40000);
        unk_10 = 0x2800;
        unk_108 = 0x384;
        unk_B4 = -1;
        unk_B8 = 0;
        info = sub_020107A8(table, 0x6A);
        SetUnkBE(info->unk_0C, info->unk_0D);
        SetUnkBC(info->unk_0A, info->unk_0B);
        break;
    case 7:
        SetMasks(0x200000, 0x400000);
        unk_10 = 0x1CCC;
        unk_108 = 0x384;
        unk_B4 = 0x11F;
        unk_B8 = 0x14;
        info = sub_020107A8(table, 0x8E);
        SetUnkBE(info->unk_0C, info->unk_0D);
        SetUnkBC(info->unk_0A, info->unk_0B);
        break;
    }
    ResetMove();
    unk_08->unk_0C->sub_0203EE3C();
}

BOOL CFieldPlayer::ov0_021333A0(fx32 dx, fx32 dy, int arg3, int damage, int arg5)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL && ((scene->unk_00D0 & 1) ? TRUE : FALSE)) {
        return FALSE;
    }
    if (!(unk_10C & 1)) {
        if (arg3 > 0) {
            int cell = 0;
            if (unk_6C != NULL) {
                CFieldMapLayerAttribute *attr = unk_6C->GetAttributeLayer(unk_14);
                if (attr != NULL) {
                    cell = attr->GetCellAtPos(GetX(), GetY());
                }
            }
            if (cell == 0xE || cell == 0x17) {
                if (unk_14 > 0) {
                    sub_0202E68C(unk_14 - 1);
                }
                ov0_021337DC(0x4000, 0x6000, 0, -0x3000, 0x800, 0x3000, 0, 0x10000, 0x10, 2);
            } else {
                unk_110 = 1;
                unk_114 = dx;
                unk_118 = dy;
                unk_138 = arg3;
                unk_144 = arg3;
                if (unk_08 != NULL && unk_08->unk_0C != NULL) {
                    unk_08->unk_0C->sub_020128D8();
                }
                sub_reset();
                if (unk_08->unk_0C->unk_1A0 == 2 || unk_08->unk_0C->unk_1A0 == 0x20) {
                    sub_0202DC54(0x800, 0);
                } else {
                    ShowSprite();
                }
                sub_020128EC_(FX_Div(FX_Atan2(-dy, -dx) << 4, 0x6486));
            }
            scene->unk_0078 = 0;
            scene->ov0_0212451C();
            if (scene->unk_0054 != NULL) {
                scene->unk_0054->sub_02022DD4();
            }
        }
        UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
        int energy = save->unk_0001;
        if (damage > 0) {
            energy -= damage;
            save->unk_0001 = energy > 0 ? (u8)energy : 0;
            ov0_02133E8C(damage);
        }
        if (arg5 < 0) {
            arg5 = unk_138 + 60;
        }
        if (energy <= 0) {
            unk_138 = 20;
            s_game->unk_14BC->sub_0200E0E0(2, 120);
            scene->unk_0054->sub_02023198(0);
            scene->unk_0054->unk_60 = 1;
            if (s_game->unk_14C0->sub_0200E310() || (s_game->unk_14C0->sub_0200E324() != 4 && s_game->unk_14C0->sub_0200E324() != 2)) {
                s_game->unk_14C0->sub_0200E0E0(2, 120);
            }
            s_game->m_audioEngine->sub_02034B58(60);
            s_game->m_audioEngine->sub_02034C44(0x114);
            if (arg5 > 0) {
                SetInvincible(unk_138 + 60, 0);
            }
            if (arg3 <= 0) {
                unk_110 = 2;
            }
        } else if (arg5 > 0) {
            s_game->m_audioEngine->sub_02034CA0(0x49, 0x4F);
            SetInvincible(unk_138 + 60, 2);
        } else {
            s_game->m_audioEngine->sub_02034CA0(0x92, 0x131);
        }
    }
    return TRUE;
}

BOOL CFieldPlayer::ov0_021337DC(int dir, int dir2, fx32 vx, fx32 vy, int arg5, int arg6, fx32 distX, fx32 distY, int arg9, int mode)
{
    fx32 dx = vx >= 0 ? distX : -distX;
    CFieldMapLayerCollision *coll = NULL;
    CFieldMapLayerAttribute *attr = NULL;
    if (unk_6C != NULL) {
        coll = unk_6C->GetLayer(unk_14);
        attr = unk_6C->GetAttributeLayer(unk_14);
        if (coll != NULL) {
            int size = coll->m_cellSize;
            if (vx != 0) {
                dx = (size * (((dx + GetX()) >> FX32_SHIFT) / size) + size / 2) * FX32_ONE - GetX();
                distX = dx >= 0 ? dx : -dx;
            }
            distY = (size * (((distY + GetY()) >> FX32_SHIFT) / size) + size / 2) * FX32_ONE - GetY();
        }
    }
    unk_134 = dir;
    unk_110 = 3;
    sub_reset();
    if (unk_08->unk_0C->unk_1A0 == 0x8000) {
        if (unk_08 != NULL) {
            unk_08->sub_show();
        }
        sub_020128EC_(dir);
    } else {
        sub_020128EC_(dir2);
    }
    if (mode == 2) {
        unk_13C = 3;
        if (unk_08->unk_0C->unk_1A0 != 0x8000) {
            sub_0202DC54(0x2000, 0);
        }
        unk_138 = 10;
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->m_flags |= 8;
        }
    } else {
        unk_13C = 0;
        if (unk_08->unk_0C->unk_1A0 != 0x8000) {
            sub_0202DC54(0x1000, 0);
        }
        s_game->m_audioEngine->sub_02034C44(0x111);
    }
    unk_114 = vx;
    unk_118 = vy;
    SetPosXY(GetX(), GetY() + distY);
    SetUnk8C(distY);
    unk_124 = distX;
    unk_11C = distY;
    unk_128 = arg5;
    unk_12C = arg6;
    unk_130 = arg9;
    unk_120 = 0;
    if (mode != 0 && coll != NULL) {
        int cell = coll->GetCellAtPos(dx + GetX(), GetY());
        int attrCell = 0;
        if (attr != NULL) {
            attrCell = attr->GetCellAtPos(dx + GetX(), GetY());
        }
        while (CFieldMapLayerCollision::IsWall(cell) || attrCell == 0xE || attrCell == 0x17) {
            // fx32 is long: the int conversion keeps this sum a CSE candidate (computed once, like the original).
            SetPosXY(GetX(), (int)GetY() + 0x10000);
            SetUnk8C(GetUnk8C() + 0x10000);
            unk_11C += 0x10000;
            cell = coll->GetCellAtPos(dx + GetX(), GetY());
            if (attr != NULL) {
                attrCell = attr->GetCellAtPos(dx + GetX(), GetY());
            }
        }
    }
    SetInvincible(-1, 0);
    return TRUE;
}

void CFieldPlayer::sub_0202E68C(int arg0)
{
    // A plain &MAIN_BSS_020B26A0 gets rematerialized at each use; the original keeps it in a register.
    UnkClass_020B26A0 *save = (UnkClass_020B26A0 *)(void *)&MAIN_BSS_020B26A0;
    unk_14 = arg0;
    if (arg0 == save->unk_0026) {
        return;
    }
    save->unk_0026 = arg0;
    save->SetUnk0020(GetPos());
}

void CFieldPlayer::ov0_02133E8C(int arg1)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        MAIN_BSS_0210CA60->ov0_0214332C(arg1, 0x78, this);
    }
}

void CFieldPlayer::ov0_02133EB4()
{
    unk_1B0 = 0;
    for (int i = 0; i < 6; i++) {
        unk_150[i].x = unk_150[i].y = -1;
        unk_180[i].x = unk_180[i].y = -1;
    }
}

void CFieldPlayer::PushHistory(Point2D pos, Point2D partnerPos)
{
    Point2D tmp[6];
    MI_CpuCopyFast(unk_150, tmp, sizeof(tmp));
    MI_CpuCopyFast(tmp, &unk_150[1], sizeof(Point2D) * 5);
    MI_CpuCopyFast(unk_180, tmp, sizeof(tmp));
    MI_CpuCopyFast(tmp, &unk_180[1], sizeof(Point2D) * 5);
    unk_150[0] = pos;
    unk_180[0] = partnerPos;
    if (unk_1B0 < 6) {
        unk_1B0++;
    }
}

void CFieldPlayer::ov0_02133EE4()
{
    if (unk_6C == NULL) {
        return;
    }
    if (unk_6C->GetLayer(unk_14) == NULL) {
        return;
    }
    Point2D cell;
    Point2D pos;
    pos.x = GetPos().x >> FX32_SHIFT;
    pos.y = GetPos().y >> FX32_SHIFT;
    cell.x = ((pos.x & 8) ? 1 : 0) + (pos.x >> 4);
    cell.y = ((pos.y & 8) ? 1 : 0) + (pos.y >> 4);
    int lx = GetTrail(0).x >> FX32_SHIFT;
    int ly = GetTrail(0).y >> FX32_SHIFT;
    // The trail cell goes through a Point2D: compared directly (`lx >> 4`), lx is folded into a temp and gets
    // colored before the trail's y.
    Point2D last;
    last.x = lx >> 4;
    last.y = ly >> 4;
    if (cell.x == last.x && cell.y == last.y) {
        return;
    }
    if (MATH_ABS(cell.x - last.x) > 1 || MATH_ABS(cell.y - last.y) > 1) {
        ov0_02133EB4();
    }
    Point2D partner;
    ov0_0213EA6C(&partner, cell, unk_14, 0);
    cell.x <<= 16;
    cell.y <<= 16;
    partner.x <<= 16;
    partner.y <<= 16;
    PushHistory(cell, partner);
}

BOOL CFieldPlayer::ov0_0213416C()
{
    if (unk_110 == 5 || unk_110 == 6 || GetUnkC0() == 7 || GetUnkC0() == 8) {
        return TRUE;
    }
    return FALSE;
}

BOOL CFieldPlayer::ov0_021341E0()
{
    if (unk_110 != 7) {
        unk_110 = 0;
        unk_138 = 0;
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->unk_8C = 0;
        }
        return TRUE;
    }
    return FALSE;
}
