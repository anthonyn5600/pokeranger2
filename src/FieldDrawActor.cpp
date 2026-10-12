#include <nitro.h>
#include <nnsys.h>

#include "CActor.hpp"
#include "CGame.hpp"
#include "UnkClass_02007770.hpp"
#include "UnkClass_02040F34.hpp"
#include "common.hpp"
#include "field/CFieldDrawActor.hpp"
#include "field/CFieldDrawActorData.hpp"
#include "interpolation.hpp"
#include "scene/CScene.hpp"

class UnkClass_020B26A0;
extern UnkClass_020B26A0 MAIN_BSS_020B26A0;

extern "C" {
CFieldDrawActorData *sub_020176BC(UnkClass_020B26A0 *save, int arg1);
CFieldDrawActorData *sub_02017748(UnkClass_020B26A0 *save, u16 id, int form, u16 mask, BOOL arg4);
CFieldDrawActorData *sub_02017848(UnkClass_020B26A0 *save, u16 id, int form, u16 mask, BOOL arg4);
}

CFieldDrawActor::CFieldDrawActor()
{
    unk_184 = NULL;
    unk_1F4 = 0;
    unk_200 = 0;
    unk_1D8 = 0;
    unk_1DC = 0;
    unk_1E0 = 0;
    unk_1E1 = 0;
    unk_19C = FX32_ONE;
    unk_1A0 = 2;
    unk_1A4 = 4;
    unk_1C9 = 0xFF;
    unk_1CA = 0xFFFF;
    m_sprite->m_polygonID = 0;
    m_sprite->m_alpha = 0x1F;
    unk_1A8 = 0;
    unk_1D4 = 0;
    unk_1D5 = 0;
    unk_1CC = 0;
    unk_1B8 = 0;
    unk_1C6 = 0;
    unk_1BC = 0;
    unk_1C0 = 0;
    unk_1C7 = 0;
    unk_1C8 = 0;
    Rectangle rect = { { 0, 0 }, { 0x40000, 0x40000 } };
    unk_1E4.pos.x = rect.pos.x;
    unk_1E4.pos.y = rect.pos.y;
    unk_1E4.size.x = rect.size.x;
    unk_1E4.size.y = rect.size.y;
    unk_1F8 = 0;
    unk_1FC = 1;
    unk_194 = NULL;
    unk_198 = 0;
}

CFieldDrawActor::~CFieldDrawActor()
{
    sub_0203E55C();
}

void CFieldDrawActor::sub_0203DBB8(int type, u16 id, int form, u32 mask, BOOL useTransfer)
{
    sub_0203E55C();
    if (type == 4) {
        unk_184 = sub_020176BC(&MAIN_BSS_020B26A0, -1);
        unk_184->sub_02040E2C();
        if (OS_GetIrqMask() & OS_IE_V_BLANK) {
            unk_184->sub_02040EF8();
        } else {
            unk_184->sub_02040EBC();
        }
        unk_1F8 = 1;
        unk_1FC = 0;
    } else if (type != 2 && useTransfer && s_game->currentScene->getSceneId() == 1) {
        if (type == 1) {
            unk_184 = sub_02017748(&MAIN_BSS_020B26A0, id, form, mask, TRUE);
        } else {
            unk_184 = sub_02017848(&MAIN_BSS_020B26A0, id, form, mask, TRUE);
        }
        unk_184->sub_02040E2C();
        if (OS_GetIrqMask() & OS_IE_V_BLANK) {
            unk_184->sub_02040EF8();
        } else {
            unk_184->sub_02040EBC();
        }
        unk_1F8 = 1;
        unk_1FC = 0;
    } else {
        unk_184 = MAIN_BSS_0210CA64->sub_02041008(type, id, form, mask, useTransfer);
        unk_1F8 = 0;
        unk_1FC = 1;
    }
    unk_190 = unk_184->unk_30;
    sub_02011FF4(unk_184);
    if (useTransfer) {
        if (unk_184->m_animCount != 0) {
            unk_198 = unk_184->m_animCount;
            unk_194 = new UnkClass_02007770[unk_198];
            u32 maxSize = 0;
            for (int i = 0; i < unk_198; i++) {
                CActorAnim *anim = unk_184->GetAnimAt((u8)i);
                if (anim != NULL && (anim->flags & 1)) {
                    unk_194[i].sub_020077CC(anim->image);
                    unk_194[i].sub_020077E4(anim->cells);
                    if (maxSize < unk_194[i].unk_10) {
                        maxSize = unk_194[i].unk_10;
                    }
                }
            }
            unk_188[0] = NNS_GfdAllocLnkTexVram(maxSize, FALSE, 0);
            unk_188[1] = NNS_GfdAllocLnkTexVram(maxSize, FALSE, 0);
        }
    } else {
        unk_188[0] = unk_184->unk_2C;
    }
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_184->m_palette;
    unk_1F4 = useTransfer;
    unk_200 = 0;
    unk_1C9 = 0xFF;
    unk_1CA = 0xFFFF;
    unk_1A8 = 0;
    m_outlineWidth = 2;
    m_outlineColor = 0x7FFF;
    m_outlineAlpha = 0x1F;
    m_outlinePhase = 0;
    m_outlineTime = 0;
    int minX = 0;
    int maxX = 0;
    int minY = 0;
    int maxY = 0;
    for (int a = 0; a < 29; a++) {
        CActorAnim *anim = unk_184->GetAnim(a);
        if (anim != NULL && (anim->flags & 1)) {
            int c = 0;
            NNSG2dCellDataBank *bank = anim->cells->unk_B8;
            for (; c < bank->numCells; c++) {
                const NNSG2dCellData *cell = NNS_G2dGetCellDataByIdx(bank, c);
                for (int o = 0; o < cell->numOAMAttrs; o++) {
                    GXOamAttr attr;
                    NNS_G2dCopyCellAsOamAttr(cell, o, &attr);
                    int x = (attr.attr01 & GX_OAM_ATTR01_X_MASK) >> GX_OAM_ATTR01_X_SHIFT;
                    if (x > 0xFF) {
                        x |= ~0xFF;
                    }
                    int y = attr.attr01 & GX_OAM_ATTR01_Y_MASK;
                    if (y > 0x7F) {
                        y |= ~0xFF;
                    }
                    GXOamShape shape = NNS_G2dGetOAMSize(&attr);
                    int w = NNS_G2dGetOamSizeX(&shape);
                    int h = NNS_G2dGetOamSizeY(&shape);
                    if (x < minX) {
                        minX = x;
                    }
                    if (y < minY) {
                        minY = y;
                    }
                    if (x + w > maxX) {
                        maxX = x + w;
                    }
                    if (y + h > maxY) {
                        maxY = y + h;
                    }
                }
            }
        }
    }
    unk_1E4.pos.x = ((minX + maxX) / 2) << 12;
    unk_1E4.pos.y = ((minY + maxY) / 2) << 12;
    unk_1E4.size.x = (maxX - minX) << 12;
    unk_1E4.size.y = (maxY - minY) << 12;
}

void CFieldDrawActor::sub_0203E10C(int type, u16 id, int form, u32 mask, BOOL useTransfer)
{
    sub_0203E55C();
    if (type == 4) {
        unk_184 = new CActorDataPlayer();
        ((CActorDataPlayer *)unk_184)->sub_02041344(id, form, mask, "PDR", useTransfer, TRUE);
    } else {
        unk_184 = new CFieldDrawActorData();
        unk_184->sub_02040830(type, id, form, mask, useTransfer, NULL, TRUE);
    }
    unk_190 = unk_184->unk_30;
    sub_02011FF4(unk_184);
    if (useTransfer) {
        if (unk_184->m_animCount != 0) {
            unk_198 = unk_184->m_animCount;
            unk_194 = new UnkClass_02007770[unk_198];
            u32 maxSize = 0;
            for (int i = 0; i < 29; i++) {
                CActorAnim *anim = unk_184->GetAnimAt((u8)i);
                if (anim != NULL && (anim->flags & 1)) {
                    unk_194[i].sub_020077CC(anim->image);
                    unk_194[i].sub_020077E4(anim->cells);
                    if (maxSize < unk_194[i].unk_10) {
                        maxSize = unk_194[i].unk_10;
                    }
                }
            }
            unk_188[0] = NNS_GfdAllocLnkTexVram(maxSize, FALSE, 0);
            unk_188[1] = NNS_GfdAllocLnkTexVram(maxSize, FALSE, 0);
        }
    } else {
        unk_188[0] = unk_184->unk_2C;
    }
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_184->m_palette;
    unk_1F4 = useTransfer;
    unk_200 = 0;
    unk_1C9 = 0xFF;
    unk_1CA = 0xFFFF;
    unk_1A8 = 0;
    m_outlineWidth = 2;
    m_outlineColor = 0x7FFF;
    m_outlineAlpha = 0x1F;
    m_outlinePhase = 0;
    m_outlineTime = 0;
    int minX = 0;
    int maxX = 0;
    int minY = 0;
    int maxY = 0;
    for (int a = 0; a < 29; a++) {
        CActorAnim *anim = unk_184->GetAnim(a);
        if (anim != NULL && (anim->flags & 1)) {
            int c = 0;
            NNSG2dCellDataBank *bank = anim->cells->unk_B8;
            for (; c < bank->numCells; c++) {
                const NNSG2dCellData *cell = NNS_G2dGetCellDataByIdx(bank, c);
                for (int o = 0; o < cell->numOAMAttrs; o++) {
                    GXOamAttr attr;
                    NNS_G2dCopyCellAsOamAttr(cell, o, &attr);
                    int x = (attr.attr01 & GX_OAM_ATTR01_X_MASK) >> GX_OAM_ATTR01_X_SHIFT;
                    if (x > 0xFF) {
                        x |= ~0xFF;
                    }
                    int y = attr.attr01 & GX_OAM_ATTR01_Y_MASK;
                    if (y > 0x7F) {
                        y |= ~0xFF;
                    }
                    GXOamShape shape = NNS_G2dGetOAMSize(&attr);
                    int w = NNS_G2dGetOamSizeX(&shape);
                    int h = NNS_G2dGetOamSizeY(&shape);
                    if (x < minX) {
                        minX = x;
                    }
                    if (y < minY) {
                        minY = y;
                    }
                    if (x + w > maxX) {
                        maxX = x + w;
                    }
                    if (y + h > maxY) {
                        maxY = y + h;
                    }
                }
            }
        }
    }
    unk_1E4.pos.x = ((minX + maxX) / 2) << 12;
    unk_1E4.pos.y = ((minY + maxY) / 2) << 12;
    unk_1E4.size.x = (maxX - minX) << 12;
    unk_1E4.size.y = (maxY - minY) << 12;
    unk_1F8 = 1;
}

void CFieldDrawActor::sub_0203E55C()
{
    if (unk_184 != NULL) {
        if (unk_1F4 != 0) {
            NNS_GfdFreeLnkTexVram(unk_188[0]);
            NNS_GfdFreeLnkTexVram(unk_188[1]);
        }
        if (unk_1FC != 0) {
            unk_184->Release();
            if (unk_1F8 != 0) {
                SAFE_DELETE(unk_184);
            }
        } else {
            sub_020120B0();
            unk_184->sub_02040E80();
        }
        unk_1D8 = 0;
        unk_1DC = 0;
        unk_1E0 = 0;
        unk_1E1 = 0;
        unk_19C = FX32_ONE;
        unk_1F8 = 0;
        unk_184 = NULL;
        unk_1FC = 1;
    }
    SAFE_DELETE_ARRAY(unk_194);
    unk_198 = 0;
}

void CFieldDrawActor::vfunc_08()
{
    if (IsAnimChanged()) {
        unk_1D8 = unk_1DC;
        unk_1E0 = unk_1E1;
        sub_0203EE3C();
    }
    if (unk_1A8 & 1) {
        if (m_outlineTime >= 0) {
            m_outlineTime -= 60 / s_game->unk_146C.sub_02008E50();
            if (m_outlineTime <= 0) {
                unk_1A8 &= ~1;
            }
        }
        m_outlinePhase += 300 / s_game->unk_146C.sub_02008E50();
        if (m_outlinePhase >= 600) {
            m_outlinePhase -= 600;
        }
    }
    if ((unk_1A8 & 4) && unk_1CC >= 0) {
        if (--unk_1CC <= 0) {
            unk_1A8 &= ~4;
            unk_1D4 = 0;
            unk_1D5 = 0;
            unk_1CC = 0;
        } else {
            if (unk_1D4 != 0) {
                unk_1D0 = MATH_Rand16(&s_game->m_rand16, unk_1D4 * 2) - unk_1D4;
            } else {
                unk_1D0 = 0;
            }
            if (unk_1D5 != 0) {
                unk_1D2 = MATH_Rand16(&s_game->m_rand16, unk_1D5 * 2) - unk_1D5;
            } else {
                unk_1D2 = 0;
            }
        }
    }
    sub_020121F4();
    m_sprite->m_alpha = unk_108.value;
    m_sprite->SetScale(unk_11C.value, unk_134.value);
    m_sprite->m_rotAngle = unk_14C.value;
    if (IsBlinking() && unk_1C0 > 0) {
        unk_1BC++;
        unk_1C6 = LinearInterpolate(unk_1C7 << 12, unk_1C8 << 12, unk_1BC, unk_1C0) >> 12;
        if (unk_1BC >= unk_1C0) {
            unk_1C0 = 0;
            unk_1BC = 0;
            if (unk_1C6 == 0) {
                unk_1A8 &= ~2;
            }
        }
    }
}

void CFieldDrawActor::vfunc_0C(Camera2D *camera)
{
    sub_0203E934(camera, 0);
}

void CFieldDrawActor::vfunc_10(Camera2D *camera)
{
}

// Blends a 5-bit color toward white: t / 300 of the color, w / 300 of white (t + w == 300).
static inline void BlendToWhite(int &r, int &g, int &b, int t, int w)
{
    r = (r * t + w * 31) / 300;
    g = (g * t + w * 31) / 300;
    b = (b * t + w * 31) / 300;
}
u32 CFieldDrawActor::sub_0203E934(Camera2D *camera, fx32 z)
{
    fx32 y;
    fx32 x;
    u32 count = 0;
    int i;
    Point2D pos;
    Point2D p;
    Point2D origPos;
    if (unk_184 != NULL) {
        CActorAnim *anim = unk_184->GetAnim(unk_C0);
        if (anim != NULL && (anim->flags & 1)) {
            CSoftwareSprite *sprite = m_sprite;
            u16 cell = anim->bank->sub_02008828(unk_C8[unk_C0]);
            sprite->m_z = z;
            if (unk_1F4 != 0) {
                if ((anim->flags & 1) && (unk_1C9 != unk_C0 || unk_1CA != cell)) {
                    UnkClass_02007770 *pal = &unk_194[unk_184->sub_02015070(unk_C0)];
                    u8 buf = unk_200 ^ 1;
                    pal->sub_020078E4(cell);
                    pal->sub_02007A94(NNS_GfdGetTexKeyAddr(unk_188[buf]));
                    if (NNS_GfdRegisterNewVramTransferTask(NNS_GFD_DST_3D_TEX_VRAM, NNS_GfdGetTexKeyAddr(unk_188[buf]), pal->unk_14, pal->unk_10)) {
                        unk_200 = buf;
                        sprite->unk_30 = (UnkClass_CSoftwareSprite_30 *)pal;
                        sprite->unk_2C = NULL;
                        sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)anim->cells;
                        sprite->m_cellDataIdx = cell;
                        unk_1C9 = unk_C0;
                        unk_1CA = cell;
                        NNS_GfdGetVramTransferTaskTotalSize();
                    }
                }
            } else {
                sprite->unk_2C = (UnkClass_CPrimitive_ImageProxy *)unk_184->GetAnim(unk_C0)->image;
                sprite->unk_30 = NULL;
                sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)anim->cells;
                sprite->m_cellDataIdx = cell;
                unk_1C9 = unk_C0;
                unk_1CA = cell;
            }
            origPos.x = sprite->m_coords[0];
            origPos.y = sprite->m_coords[1];
            u16 color = sprite->m_color;
            int alpha = sprite->m_alpha;
            BOOL unk3C = sprite->unk_3C;
            pos = origPos;
            if (unk_1A8 & 4) {
                pos.x = origPos.x + (unk_1D0 << 12);
                pos.y = origPos.y + (unk_1D2 << 12);
            }
            sprite->SetPos(pos);
            if (unk_1A8 & 2) {
                sprite->SetColorAlpha(unk_1B8, unk_1C6 * alpha / 31, TRUE);
                sprite->m_z = z;
                count += sprite->Render(camera);
                sprite->SetColorAlpha(color, alpha, unk3C);
            }
            sprite->m_z = z - count;
            count += sprite->Render(camera);
            if (unk_1A8 & 1) {
                int b;
                int t;
                int g;
                int r;
                u16 c = m_outlineColor;
                b = (c & 0x7C00) >> 10;
                r = c & 0x1F;
                g = (c & 0x3E0) >> 5;
                t = m_outlinePhase;
                if (t < 300) {
                    BlendToWhite(r, g, b, t, 300 - t);
                } else {
                    BlendToWhite(r, g, b, 600 - t, t - 300);
                }
                sprite->SetColorAlpha(GX_RGB(r, g, b), m_outlineAlpha * alpha / 31, TRUE);
                x = ((Point2D *)&pos)->x;
                y = pos.y;
                for (i = 0; i < 4; i++) {
                    p.x = x;
                    p.y = y;
                    switch (i) {
                    case 0:
                        p.x = x + (m_outlineWidth << 12);
                        break;
                    case 1:
                        p.x = x - (m_outlineWidth << 12);
                        break;
                    case 2:
                        p.y = y + (m_outlineWidth << 12);
                        break;
                    case 3:
                        p.y = y - (m_outlineWidth << 12);
                        break;
                    }
                    sprite->SetPos(p);
                    sprite->m_z = z - count;
                    count += sprite->Render(camera);
                }
                sprite->SetColorAlpha(color, alpha, unk3C);
            }
            sprite->SetPos(origPos);
            if (sub_02012D88()) {
                CSoftwareSprite *ghost = sub_02012DA8();
                for (i = 0; i < 8; i++, ghost++) {
                    if (sub_02012D9C(i)) {
                        ghost->m_z = z - count;
                        ghost->unk_38 = (UnkClass_CSoftwareSprite_38 *)anim->cells;
                        ghost->m_cellDataIdx = sprite->m_cellDataIdx;
                        ghost->m_alpha = sub_02012DB0(i);
                        fx32 scale = sub_02012DC0(i);
                        ghost->SetScale(scale, scale);
                        if (unk_1F4 != 0) {
                            ghost->unk_30 = sprite->unk_30;
                            ghost->unk_2C = NULL;
                        } else {
                            ghost->unk_2C = sprite->unk_2C;
                            ghost->unk_30 = NULL;
                        }
                        count += ghost->Render(camera);
                    }
                }
            }
        }
    }
    return count;
}

void CFieldDrawActor::sub_0203EE3C()
{
    switch (unk_1D8) {
    case 0:
        sub_02012184(unk_1A0, unk_1E0, unk_19C);
        sub_02012114(unk_1A0, unk_1E0);
        break;
    case 1:
        sub_02012184(unk_1A4, unk_1E0, unk_19C);
        sub_02012114(unk_1A4, unk_1E0);
        break;
    case 3:
        break;
    }
}

void CFieldDrawActor::sub_0203EEA8(u16 arg0, u8 alpha, int duration)
{
    unk_1A8 |= 2;
    unk_1B8 = arg0;
    unk_1BC = 0;
    if (duration <= 0) {
        unk_1C6 = alpha;
        unk_1C0 = 0;
        return;
    }
    unk_1C6 = 0;
    unk_1C0 = duration;
    unk_1C7 = 0;
    unk_1C8 = alpha;
}

void CFieldDrawActor::sub_0203EEEC(int duration)
{
    unk_1BC = 0;
    if (duration > 0) {
        unk_1C0 = duration;
        unk_1C7 = unk_1C6;
        unk_1C8 = 0;
    } else {
        unk_1A8 &= ~2;
    }
}
