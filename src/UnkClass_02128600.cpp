#include "battle/UnkClass_02128600.hpp"

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "UnkClass_02008788.hpp"
#include "battle/UnkClass_02128860.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CSoftwareSprite.hpp"

static const u16 sDigitDivisors[] = { 10000, 1000, 100, 10, 1 };

UnkClass_02128600::UnkClass_02128600()
{
    ov1_02128628();
}

UnkClass_02128600::~UnkClass_02128600()
{
    ov1_021287A8();
}

void UnkClass_02128600::ov1_02128628()
{
    CArchiveGuard *guard = new CArchiveGuard("BHP", "data/battle/system/battle_number01_LZ.bin", 1, 1, 0, NULL, 0);

    m_image = new UnkClass_020074D4("BHP:battle_number01.NCBR", 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->sub_020076E8(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->sub_020076B0();

    m_palette = new UnkClass_02007AA4("BHP:battle_number01.NCLR", 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->sub_02007BFC(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->sub_02007BC4();

    m_cells = new CNCERFile("BHP:battle_number01.NCER", 0, 0, 0);
    m_anim = new UnkClass_02008788();
    m_anim->sub_0200887C("BHP:battle_number01.cac", 0, 0);

    SAFE_DELETE(guard);
}

void UnkClass_02128600::ov1_021287A8()
{
    SAFE_DELETE(m_image);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_cells);
    SAFE_DELETE(m_anim);
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}

UnkClass_02128860::UnkClass_02128860()
{
    m_data = NULL;
    m_sprite = new CSoftwareSprite();
    m_sprite->SetTransformParams(0, 0, FX32_ONE, FX32_ONE, 0, 0x401);
    m_sprite->m_color = GX_RGB(31, 31, 31);
    m_sprite->m_alpha = 31;
    m_sprite->m_polygonID = 0;
}

UnkClass_02128860::~UnkClass_02128860()
{
    SAFE_DELETE(m_sprite);
}

void UnkClass_02128860::ov1_0212891C(UnkClass_02128600 *data)
{
    m_data = data;
    m_sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)data->m_image, NULL);
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)data->m_palette;
    m_sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)data->m_cells;
    m_sprite->m_cellDataIdx = 0;
    m_animId = data->m_anim->sub_02008A80(1, 0);
}

void UnkClass_02128860::ov1_02128970(Camera2D *camera)
{
    BOOL started;
    u16 value;
    u8 digit;
    int i;
    u16 divisor;

    value = m_hp;
    Point2D pos = m_pos;
    m_sprite->SetPos(pos);
    m_sprite->m_cellDataIdx = 10;
    started = FALSE;
    m_sprite->Render(camera);

    for (i = 0; i < 5; i++) {
        divisor = sDigitDivisors[i];
        digit = value / divisor;
        if (digit != 0 || started) {
            m_sprite->SetPos(pos);
            m_sprite->m_cellDataIdx = digit;
            started = TRUE;
            m_sprite->Render(camera);
            pos.x += 0x4000;
        }
        value -= digit * divisor;
    }
}
