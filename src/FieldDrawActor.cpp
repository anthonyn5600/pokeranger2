#include <nitro.h>
#include <nnsys.h>

#include "CActor.hpp"
#include "CGame.hpp"
#include "CellCharBuffer.hpp"
#include "FieldDrawActorDataPool.hpp"
#include "common.hpp"
#include "field/CFieldDrawActor.hpp"
#include "field/CFieldDrawActorData.hpp"
#include "interpolation.hpp"
#include "scene/CScene.hpp"

class SaveData;
extern SaveData MAIN_BSS_020B26A0;

extern "C" {
CFieldDrawActorData *SaveData_LoadPlayerActorData(SaveData *save, int arg1);
CFieldDrawActorData *SaveData_FindPartnerActorData(SaveData *save, u16 id, int form, u16 mask, BOOL arg4);
CFieldDrawActorData *SaveData_FindPartyActorData(SaveData *save, u16 id, int form, u16 mask, BOOL arg4);
}

CFieldDrawActor::CFieldDrawActor()
{
    m_actorData = NULL;
    unk_1F4 = 0;
    unk_200 = 0;
    unk_1D8 = 0;
    unk_1DC = 0;
    unk_1E0 = 0;
    unk_1E1 = 0;
    m_animSpeed = FX32_ONE;
    unk_1A0 = 2;
    unk_1A4 = 4;
    unk_1C9 = 0xFF;
    unk_1CA = 0xFFFF;
    m_sprite->m_polygonID = 0;
    m_sprite->m_alpha = 0x1F;
    m_effectFlags = 0;
    m_shakeRangeX = 0;
    m_shakeRangeY = 0;
    m_shakeTime = 0;
    m_blinkColor = 0;
    m_blinkAlpha = 0;
    m_blinkFrame = 0;
    m_blinkDuration = 0;
    m_blinkFrom = 0;
    m_blinkTo = 0;
    Rectangle rect = { { 0, 0 }, { 0x40000, 0x40000 } };
    unk_1E4.pos.x = rect.pos.x;
    unk_1E4.pos.y = rect.pos.y;
    unk_1E4.size.x = rect.size.x;
    unk_1E4.size.y = rect.size.y;
    unk_1F8 = 0;
    unk_1FC = 1;
    m_cellBuffers = NULL;
    m_cellBufferCount = 0;
}

CFieldDrawActor::~CFieldDrawActor()
{
    Release();
}

void CFieldDrawActor::Load(int type, u16 id, int form, u32 mask, BOOL useTransfer)
{
    Release();
    if (type == 4) {
        m_actorData = SaveData_LoadPlayerActorData(&MAIN_BSS_020B26A0, -1);
        m_actorData->AllocVram();
        if (OS_GetIrqMask() & OS_IE_V_BLANK) {
            m_actorData->LoadPaletteDeferred();
        } else {
            m_actorData->LoadToVram();
        }
        unk_1F8 = 1;
        unk_1FC = 0;
    } else if (type != 2 && useTransfer && s_game->currentScene->getSceneId() == 1) {
        if (type == 1) {
            m_actorData = SaveData_FindPartnerActorData(&MAIN_BSS_020B26A0, id, form, mask, TRUE);
        } else {
            m_actorData = SaveData_FindPartyActorData(&MAIN_BSS_020B26A0, id, form, mask, TRUE);
        }
        m_actorData->AllocVram();
        if (OS_GetIrqMask() & OS_IE_V_BLANK) {
            m_actorData->LoadPaletteDeferred();
        } else {
            m_actorData->LoadToVram();
        }
        unk_1F8 = 1;
        unk_1FC = 0;
    } else {
        m_actorData = MAIN_BSS_0210CA64->Acquire(type, id, form, mask, useTransfer);
        unk_1F8 = 0;
        unk_1FC = 1;
    }
    unk_190 = m_actorData->unk_30;
    SetData(m_actorData);
    if (useTransfer) {
        if (m_actorData->m_animCount != 0) {
            m_cellBufferCount = m_actorData->m_animCount;
            m_cellBuffers = new CellCharBuffer[m_cellBufferCount];
            u32 maxSize = 0;
            for (int i = 0; i < m_cellBufferCount; i++) {
                CActorAnim *anim = m_actorData->GetAnimAt((u8)i);
                if (anim != NULL && (anim->flags & 1)) {
                    m_cellBuffers[i].SetImage(anim->image);
                    m_cellBuffers[i].SetCells(anim->cells);
                    if (maxSize < m_cellBuffers[i].m_size) {
                        maxSize = m_cellBuffers[i].m_size;
                    }
                }
            }
            unk_188[0] = NNS_GfdAllocLnkTexVram(maxSize, FALSE, 0);
            unk_188[1] = NNS_GfdAllocLnkTexVram(maxSize, FALSE, 0);
        }
    } else {
        unk_188[0] = m_actorData->unk_2C;
    }
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)m_actorData->m_palette;
    unk_1F4 = useTransfer;
    unk_200 = 0;
    unk_1C9 = 0xFF;
    unk_1CA = 0xFFFF;
    m_effectFlags = 0;
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
        CActorAnim *anim = m_actorData->GetAnim(a);
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

void CFieldDrawActor::LoadOwnData(int type, u16 id, int form, u32 mask, BOOL useTransfer)
{
    Release();
    if (type == 4) {
        m_actorData = new CActorDataPlayer();
        ((CActorDataPlayer *)m_actorData)->LoadPlayer(id, form, mask, "PDR", useTransfer, TRUE);
    } else {
        m_actorData = new CFieldDrawActorData();
        m_actorData->LoadData(type, id, form, mask, useTransfer, NULL, TRUE);
    }
    unk_190 = m_actorData->unk_30;
    SetData(m_actorData);
    if (useTransfer) {
        if (m_actorData->m_animCount != 0) {
            m_cellBufferCount = m_actorData->m_animCount;
            m_cellBuffers = new CellCharBuffer[m_cellBufferCount];
            u32 maxSize = 0;
            for (int i = 0; i < 29; i++) {
                CActorAnim *anim = m_actorData->GetAnimAt((u8)i);
                if (anim != NULL && (anim->flags & 1)) {
                    m_cellBuffers[i].SetImage(anim->image);
                    m_cellBuffers[i].SetCells(anim->cells);
                    if (maxSize < m_cellBuffers[i].m_size) {
                        maxSize = m_cellBuffers[i].m_size;
                    }
                }
            }
            unk_188[0] = NNS_GfdAllocLnkTexVram(maxSize, FALSE, 0);
            unk_188[1] = NNS_GfdAllocLnkTexVram(maxSize, FALSE, 0);
        }
    } else {
        unk_188[0] = m_actorData->unk_2C;
    }
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)m_actorData->m_palette;
    unk_1F4 = useTransfer;
    unk_200 = 0;
    unk_1C9 = 0xFF;
    unk_1CA = 0xFFFF;
    m_effectFlags = 0;
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
        CActorAnim *anim = m_actorData->GetAnim(a);
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

void CFieldDrawActor::Release()
{
    if (m_actorData != NULL) {
        if (unk_1F4 != 0) {
            NNS_GfdFreeLnkTexVram(unk_188[0]);
            NNS_GfdFreeLnkTexVram(unk_188[1]);
        }
        if (unk_1FC != 0) {
            m_actorData->Release();
            if (unk_1F8 != 0) {
                SAFE_DELETE(m_actorData);
            }
        } else {
            ClearData();
            m_actorData->ReleaseVram();
        }
        unk_1D8 = 0;
        unk_1DC = 0;
        unk_1E0 = 0;
        unk_1E1 = 0;
        m_animSpeed = FX32_ONE;
        unk_1F8 = 0;
        m_actorData = NULL;
        unk_1FC = 1;
    }
    SAFE_DELETE_ARRAY(m_cellBuffers);
    m_cellBufferCount = 0;
}

void CFieldDrawActor::vfunc_08()
{
    if (IsAnimChanged()) {
        unk_1D8 = unk_1DC;
        unk_1E0 = unk_1E1;
        RefreshAnim();
    }
    if (m_effectFlags & 1) {
        if (m_outlineTime >= 0) {
            m_outlineTime -= 60 / s_game->unk_146C.GetFps();
            if (m_outlineTime <= 0) {
                m_effectFlags &= ~1;
            }
        }
        m_outlinePhase += 300 / s_game->unk_146C.GetFps();
        if (m_outlinePhase >= 600) {
            m_outlinePhase -= 600;
        }
    }
    if ((m_effectFlags & 4) && m_shakeTime >= 0) {
        if (--m_shakeTime <= 0) {
            m_effectFlags &= ~4;
            m_shakeRangeX = 0;
            m_shakeRangeY = 0;
            m_shakeTime = 0;
        } else {
            if (m_shakeRangeX != 0) {
                m_shakeX = MATH_Rand16(&s_game->m_rand16, m_shakeRangeX * 2) - m_shakeRangeX;
            } else {
                m_shakeX = 0;
            }
            if (m_shakeRangeY != 0) {
                m_shakeY = MATH_Rand16(&s_game->m_rand16, m_shakeRangeY * 2) - m_shakeRangeY;
            } else {
                m_shakeY = 0;
            }
        }
    }
    Update();
    m_sprite->m_alpha = unk_108.value;
    m_sprite->SetScale(unk_11C.value, unk_134.value);
    m_sprite->m_rotAngle = m_rotTween.value;
    if (IsBlinking() && m_blinkDuration > 0) {
        m_blinkFrame++;
        m_blinkAlpha = LinearInterpolate(m_blinkFrom << 12, m_blinkTo << 12, m_blinkFrame, m_blinkDuration) >> 12;
        if (m_blinkFrame >= m_blinkDuration) {
            m_blinkDuration = 0;
            m_blinkFrame = 0;
            if (m_blinkAlpha == 0) {
                m_effectFlags &= ~2;
            }
        }
    }
}

void CFieldDrawActor::vfunc_0C(Camera2D *camera)
{
    Render(camera, 0);
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
u32 CFieldDrawActor::Render(Camera2D *camera, fx32 z)
{
    fx32 y;
    fx32 x;
    u32 count = 0;
    int i;
    Point2D pos;
    Point2D p;
    Point2D origPos;
    if (m_actorData != NULL) {
        CActorAnim *anim = m_actorData->GetAnim(unk_C0);
        if (anim != NULL && (anim->flags & 1)) {
            CSoftwareSprite *sprite = m_sprite;
            u16 cell = anim->bank->GetCell(unk_C8[unk_C0]);
            sprite->m_z = z;
            if (unk_1F4 != 0) {
                if ((anim->flags & 1) && (unk_1C9 != unk_C0 || unk_1CA != cell)) {
                    CellCharBuffer *pal = &m_cellBuffers[m_actorData->FindAnimIndex(unk_C0)];
                    u8 buf = unk_200 ^ 1;
                    pal->LoadCell(cell);
                    pal->SetVramAddr(NNS_GfdGetTexKeyAddr(unk_188[buf]));
                    if (NNS_GfdRegisterNewVramTransferTask(NNS_GFD_DST_3D_TEX_VRAM, NNS_GfdGetTexKeyAddr(unk_188[buf]), pal->m_buffer, pal->m_size)) {
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
                sprite->unk_2C = (UnkClass_CPrimitive_ImageProxy *)m_actorData->GetAnim(unk_C0)->image;
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
            if (m_effectFlags & 4) {
                pos.x = origPos.x + (m_shakeX << 12);
                pos.y = origPos.y + (m_shakeY << 12);
            }
            sprite->SetPos(pos);
            if (m_effectFlags & 2) {
                sprite->SetColorAlpha(m_blinkColor, m_blinkAlpha * alpha / 31, TRUE);
                sprite->m_z = z;
                count += sprite->Render(camera);
                sprite->SetColorAlpha(color, alpha, unk3C);
            }
            sprite->m_z = z - count;
            count += sprite->Render(camera);
            if (m_effectFlags & 1) {
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
            if (IsGhosting()) {
                CSoftwareSprite *ghost = GetSprites();
                for (i = 0; i < 8; i++, ghost++) {
                    if (IsGhostActive(i)) {
                        ghost->m_z = z - count;
                        ghost->unk_38 = (UnkClass_CSoftwareSprite_38 *)anim->cells;
                        ghost->m_cellDataIdx = sprite->m_cellDataIdx;
                        ghost->m_alpha = GetGhostAlpha(i);
                        fx32 scale = GetGhostScale(i);
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

void CFieldDrawActor::RefreshAnim()
{
    switch (unk_1D8) {
    case 0:
        SetAnimWithSpeed(unk_1A0, unk_1E0, m_animSpeed);
        SetAnim(unk_1A0, unk_1E0);
        break;
    case 1:
        SetAnimWithSpeed(unk_1A4, unk_1E0, m_animSpeed);
        SetAnim(unk_1A4, unk_1E0);
        break;
    case 3:
        break;
    }
}

void CFieldDrawActor::StartColorBlink(u16 arg0, u8 alpha, int duration)
{
    m_effectFlags |= 2;
    m_blinkColor = arg0;
    m_blinkFrame = 0;
    if (duration <= 0) {
        m_blinkAlpha = alpha;
        m_blinkDuration = 0;
        return;
    }
    m_blinkAlpha = 0;
    m_blinkDuration = duration;
    m_blinkFrom = 0;
    m_blinkTo = alpha;
}

void CFieldDrawActor::StopBlink(int duration)
{
    m_blinkFrame = 0;
    if (duration > 0) {
        m_blinkDuration = duration;
        m_blinkFrom = m_blinkAlpha;
        m_blinkTo = 0;
    } else {
        m_effectFlags &= ~2;
    }
}
