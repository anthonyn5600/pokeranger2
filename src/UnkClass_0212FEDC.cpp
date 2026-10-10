#include <nitro.h>
#include <string.h>

#include "UnkClass_02007AA4.hpp"
#include "field/CFieldMap.hpp"
#include "heap.hpp"

static u16 sPaletteBuffer[16];

UnkClass_0212FEDC::UnkClass_0212FEDC()
{
    m_frames = NULL;
    m_texture = 0;
    m_mode = 0;
    m_palette = 0;
    m_color = 0;
    m_colorCount = 0;
    m_timer = 0;
    m_frame = 0;
    m_dirty = FALSE;
}

UnkClass_0212FEDC::~UnkClass_0212FEDC()
{
    Release();
}

void UnkClass_0212FEDC::Reset()
{
    m_timer = 0;
    m_frame = 0;
    m_dirty = FALSE;
}

BOOL UnkClass_0212FEDC::Load(void *data)
{
    u8 *p = (u8 *)data;

    m_texture = p[0];
    m_mode = p[1];
    m_palette = p[2];
    m_color = p[3];
    m_colorCount = p[4];
    m_frameCount = p[5];
    p += 6;
    m_frames = (FieldMapPaletteFrame *)Heap_AllocWithAlignment(m_frameCount * sizeof(FieldMapPaletteFrame), 4);
    for (int i = 0; i < m_frameCount; i++) {
        m_frames[i].palette = p[0];
        m_frames[i].color = p[1];
        m_frames[i].duration = p[2];
        p += 3;
    }
    Reset();
    return TRUE;
}

void UnkClass_0212FEDC::Release()
{
    if (m_frames != NULL) {
        Heap_Free(m_frames);
        m_frames = NULL;
    }
    m_texture = 0;
    m_mode = 0;
    m_palette = 0;
    m_color = 0;
    m_colorCount = 0;
    m_timer = 0;
    m_frame = 0;
    m_dirty = FALSE;
}

void UnkClass_0212FEDC::Update(int fps)
{
    FieldMapPaletteFrame *frame = m_mode == 3 ? &m_frames[0] : &m_frames[m_frame];
    m_timer += 60 / fps;
    if (m_timer >= frame->duration) {
        m_timer = 0;
        m_frame++;
        m_dirty = TRUE;
        if (m_mode == 3) {
            if (m_frame >= m_colorCount) {
                m_frame = 0;
            }
        } else if (m_frame >= m_frameCount) {
            m_frame = 0;
        }
    }
}

// The original Apply has no loop rotation, CSE or copy propagation (it reloads every field), unlike the rest of
// the file.
#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
#pragma opt_common_subs off

void UnkClass_0212FEDC::Apply()
{
    if (m_dirty) {
        // Two statements in the else branch keep mwcc from turning this into a ?: temp, which would take the
        // register the original gives to this.
        FieldMapPaletteFrame *frame;
        if (m_mode == 3) {
            frame = &m_frames[0];
        } else {
            int index = m_frame;
            frame = &m_frames[index];
        }
        UnkClass_021302BC *tex = m_textures[m_texture];
        UnkClass_02007AA4 *base = tex->m_palettes[m_palette];
        NNSGfdPlttKey key = tex->m_plttKeys[frame->palette];
        UnkClass_02007AA4 *anim = tex->m_palettes[frame->palette];
        NNSG2dPaletteData baseData = *base->unk_04;
        NNSG2dPaletteData data = *anim->unk_04;
        u16 *baseColors = (u16 *)baseData.pRawData;
        u16 *animColors = (u16 *)data.pRawData;
        u16 *buf = sPaletteBuffer;
        data.szByte = 32;
        if (baseColors != NULL && animColors != NULL && buf != NULL) {
            u32 addr = NNS_GfdGetPlttKeyAddr(key);
            switch (m_mode) {
            case 1:
                // (int)(u32): the original divides with the signed shift sequence, i.e. without knowing that the
                // u8 is non-negative.
                memcpy(buf, baseColors + (int)(u32)m_color / 16 * 16, 32);
                buf[m_color % 16] = animColors[frame->color];
                data.pRawData = buf;
                addr += (int)(u32)m_color / 16 * 32;
                break;
            case 2:
                data.pRawData = animColors + frame->color * 16;
                addr += m_color * 32;
                break;
            case 3:
                memcpy(buf, baseColors + (int)(u32)m_color / 16 * 16, 32);
                for (int i = 0; i < m_colorCount; i++) {
                    buf[m_color % 16 + i] = animColors[(m_frame + i) % m_colorCount + m_color];
                }
                data.pRawData = buf;
                addr += (int)(u32)m_color / 16 * 32;
                break;
            }
            NNS_G2dInitImagePaletteProxy(&base->unk_08);
            NNS_G2dLoadPalette(&data, addr, NNS_G2D_VRAM_TYPE_3DMAIN, &base->unk_08);
        }
    }
    m_dirty = FALSE;
}

#pragma pop
