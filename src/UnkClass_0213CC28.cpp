#include "battle/UnkClass_0213CC28.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "CGame.hpp"
#include "UnkClass_020023EC.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200CAB4.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_02018208.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CBinaryFileMes.hpp"
#include "file/CNCLRFile.hpp"
#include "file/CNSCRFile.hpp"
#include "main.hpp"

extern "C" {
u8 *sub_02018B10(UnkClass_02018208 *obj, u32 i);
void sub_0202BC74(const u8 *src, u8 *dst, int len);
fx32 ov1_0212EE80(int assistType, int type);
}

#define LOAD_MESSAGES(table, path)                                                                         \
    {                                                                                                      \
        CBinaryFileMes *file = new CBinaryFileMes(path, 1);                                                \
        table = new UnkClass_020091E8_004();                                                               \
        u32 pos = 2;                                                                                       \
        table->unk_00 = ((u32 *)file->unk_4C)[0];                                                          \
        table->unk_04 = ((u32 *)file->unk_4C)[1];                                                          \
        table->unk_08 = new UnkClass_020091E8_004_08[table->unk_04];                                       \
        for (u32 i = 0; i < table->unk_04; ++i) {                                                          \
            table->unk_08[i].unk_00 = ((u32 *)file->unk_4C)[pos];                                          \
            ++pos;                                                                                         \
            table->unk_08[i].unk_04 = new u8[table->unk_08[i].unk_00];                                     \
            MI_CpuCopyFast(&((u32 *)file->unk_4C)[pos], table->unk_08[i].unk_04, table->unk_08[i].unk_00); \
            pos += table->unk_08[i].unk_00 / 4;                                                            \
        }                                                                                                  \
        delete file;                                                                                       \
    }

#define RELEASE_MESSAGES(table)                    \
    if (table != NULL) {                           \
        for (u32 i = 0; i < table->unk_04; ++i) {  \
            if (table->unk_08[i].unk_04 != NULL) { \
                delete[] table->unk_08[i].unk_04;  \
                table->unk_08[i].unk_04 = NULL;    \
            }                                      \
        }                                          \
        if (table->unk_08 != NULL) {               \
            delete[] table->unk_08;                \
            table->unk_08 = NULL;                  \
        }                                          \
        if (table != NULL) {                       \
            delete table;                          \
            table = NULL;                          \
        }                                          \
    }

static UnkClass_0213CC28 *sInstance;

static inline void SetRotation(MtxFx22 *mtx, fx32 sinVal, fx32 cosVal)
{
    mtx->_00 = cosVal;
    mtx->_01 = sinVal;
    mtx->_10 = -sinVal;
    mtx->_11 = cosVal;
}

static void ov1_0213E708(void *arg);

UnkClass_0213CC28::UnkClass_0213CC28(CGame *game)
{
    sInstance = this;
    m_game = game;
    unk_04 = 0x12;
    unk_08 = 0x12;
    unk_0C = 0;
    unk_0D = 0;
    unk_0E = 0;
    unk_0F = 0;
    m_flags = 0;
    unk_2E = 0;
    unk_90 = 0;
    m_charOffset = 0;
    m_rotState = 0;
    m_rotFrame = 0;
    m_bgX = 0xDC;
    m_bgY = 0;
    unk_24 = 0;
    m_angle = 0;
    for (int i = 0; i < 8; i++) {
        unk_91[i] = 0x12;
    }
    m_pokeObj = NULL;
    unk_164 = NULL;
    unk_168 = NULL;
    unk_158 = NULL;
    unk_15C = NULL;
    m_blinkTimer = 0;
    m_blinkPal = 1;
    m_blinkDir = 0;
    m_nclr = NULL;
    ov1_0213DE88();
    ov1_0213D018();
    ov1_0213DF20();
    ov1_0213E29C();
    ov1_0213E7C4(1);
    ov1_0213EF14(0);
    for (int i = 0; i < 8; i++) {
        unk_70[i] = 0;
    }
}

UnkClass_0213CC28::~UnkClass_0213CC28()
{
    ov1_0213CD40();
}

void UnkClass_0213CC28::ov1_0213CD40()
{
    SAFE_DELETE(unk_164);
    SAFE_DELETE(unk_168);
    SAFE_DELETE(m_nclr);
    SAFE_DELETE(m_pokeObj);
    SAFE_DELETE(unk_158);
    SAFE_DELETE(unk_15C);
    SAFE_DELETE(unk_160);
    RELEASE_MESSAGES(m_menuMes);
    RELEASE_MESSAGES(m_assistMes);
    RELEASE_MESSAGES(m_fieldWazaMes);
    GXS_SetGraphicsMode(GX_BGMODE_0);
}

void UnkClass_0213CC28::ov1_0213D018()
{
    m_game->unk_0C24->sub_020027E8();
    m_game->unk_0C28->sub_020027E8();
    ov1_0213D058(0x12);
    ov1_0213DA14();
    ov1_0213D614();
}

void UnkClass_0213CC28::ov1_0213D058(int palette)
{
    char nclrName[96];

    CArchiveGuard *archive = new CArchiveGuard("BGU", "data/menu/pam001_bg_LZ.bin", 1, 1, 0, NULL, 0);
    CBGNCGRFile *ncgr = new CBGNCGRFile("BGU:pam001.NCGR", 1, 0, 0);
    OS_SPrintf(nclrName, "BGU:pam%03d.NCLR", palette);
    m_nclr = new CNCLRFile(nclrName, 1, 0, 0);
    CNSCRFile *nscr = new CNSCRFile("BGU:pam001_00.NSCR", 1, 0, 0);
    G2S_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_512x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x0000, GX_BG_CHARBASE_0x00000);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB3, nscr->unk_B8, ncgr->unk_B8, m_nclr->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x7800, GX_BG_CHARBASE_0x00000);
    delete nscr;
    delete ncgr;
    delete archive;

    archive = new CArchiveGuard("BGU", "data/menu/pam000_bg_LZ.bin", 1, 1, 0, NULL, 0);
    ncgr = new CBGNCGRFile("BGU:pam000.NCGR", 1, 0, 0);
    CNSCRFile *nscr1 = new CNSCRFile("BGU:pam000_01.NSCR", 1, 0, 0);
    CNSCRFile *nscr2 = new CNSCRFile("BGU:pam000_02.NSCR", 1, 0, 0);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB1, nscr1->unk_B8, ncgr->unk_B8, NULL, NULL, NULL, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x04000);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB2, nscr2->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x04000);
    delete nscr1;
    delete nscr2;
    delete ncgr;
    delete archive;
    ov1_0213E4CC();
}

void UnkClass_0213CC28::ov1_0213D354(int palette)
{
    char nclrName[96];

    SAFE_DELETE(m_nclr);
    m_nclr = NULL;
    CArchiveGuard *archive = new CArchiveGuard("BGU", "data/menu/pam000_bg_LZ.bin", 1, 1, 0, NULL, 0);
    OS_SPrintf(nclrName, "BGU:pam%03d.NCLR", palette);
    m_nclr = new CNCLRFile(nclrName, 1, 0, 0);
    DC_FlushRange(m_nclr->unk_B8->pRawData, 0x20);
    GXS_LoadBGPltt(m_nclr->unk_B8->pRawData, 0, 0x20);
    delete archive;
}

void UnkClass_0213CC28::ov1_0213D458()
{
    void *pltt = (u8 *)m_nclr->unk_B8->pRawData + m_blinkPal * 32;
    DC_FlushRange(pltt, 0x10);
    GXS_LoadBGPltt(pltt, 0x20, 0x10);
}

void UnkClass_0213CC28::ov1_0213D490()
{
    unk_E0[0]->sub_0200EB34(1, TRUE);
    GXOamAffine *affine = (GXOamAffine *)&m_game->unk_0424[4];
    affine->PA = 0x80;
    affine->PB = 0;
    affine->PC = 0;
    affine->PD = 0x80;
}

void UnkClass_0213CC28::ov1_0213D4D0()
{
    G2S_SetBGMosaicSize(m_mosaic, m_mosaic);
    G2S_SetOBJMosaicSize(m_mosaic, m_mosaic);
    if (--m_mosaic == 0) {
        G2S_BG0Mosaic(FALSE);
        for (int i = 0; i < m_count; i++) {
            unk_F0[i]->sub_0200EB64(FALSE);
        }
        unk_13C->sub_0200EB64(FALSE);
        unk_140->sub_0200EB64(FALSE);
    }
}

void UnkClass_0213CC28::ov1_0213D568()
{
    m_mosaic = 15;
    G2S_BG0Mosaic(TRUE);
    for (int i = 0; i < m_count; i++) {
        unk_F0[i]->unk_14 = TRUE;
        unk_F0[i]->sub_0200EB64(TRUE);
    }
    unk_13C->unk_14 = TRUE;
    unk_140->unk_14 = TRUE;
    unk_13C->sub_0200EB64(TRUE);
    unk_140->sub_0200EB64(TRUE);
    G2S_SetBGMosaicSize(m_mosaic, m_mosaic);
    G2S_SetOBJMosaicSize(m_mosaic, m_mosaic);
}

void UnkClass_0213CC28::ov1_0213D614()
{
    LOAD_MESSAGES(m_menuMes, "/data/message/etc/menu_mes");
    LOAD_MESSAGES(m_assistMes, "/data/message/etc/assist_mes");
    LOAD_MESSAGES(m_fieldWazaMes, "/data/message/etc/fieldwaza_name");
}

void UnkClass_0213CC28::ov1_0213D92C(u16 species)
{
    char name[96];

    int charOffset = m_charOffset;
    m_pokeIcon = NULL;
    SAFE_DELETE(m_pokeObj);
    OS_SPrintf(name, "bp%03d", species);
    m_pokeObj = new UnkClass_0200ECD0((GXOamAttr *)&m_game->unk_0424[0x7A], m_game->unk_14A8, TRUE, 0x40);
    m_pokeObj->sub_0200EE14("data/pokeOBJ", name, charOffset / 32, 15);
    m_pokeIcon = m_pokeObj->sub_0200F4FC(0, 0xC0, 0x60, 0);
    m_flags |= 6;
}

void UnkClass_0213CC28::ov1_0213DA14()
{
    int charOffset = 0;
    unk_160 = new UnkClass_0200ECD0((GXOamAttr *)&m_game->unk_0424[0], m_game->unk_14A8, TRUE, 0x40);
    charOffset += unk_160->sub_0200EE14("data/menu", "pam003_00", charOffset / 32, 0);
    unk_158 = new UnkClass_0200ECD0((GXOamAttr *)&m_game->unk_0424[8], m_game->unk_14A8, TRUE, 0x40);
    charOffset += unk_158->sub_0200EE14("data/menu", "pam001_00", charOffset / 32, 2);
    unk_15C = new UnkClass_0200ECD0((GXOamAttr *)&m_game->unk_0424[13], m_game->unk_14A8, TRUE, 0x40);
    charOffset += unk_15C->sub_0200EE14("data/menu", "pam002_00", charOffset / 32, 6);
    unk_164 = new UnkClass_0200ECD0((GXOamAttr *)&m_game->unk_0424[0x6C], m_game->unk_14A8, TRUE, 0x40);
    charOffset += unk_164->sub_0200EE14("data/menu", "ma000_00", charOffset / 32, 8);
    unk_168 = new UnkClass_0200ECD0((GXOamAttr *)&m_game->unk_0424[0x6D], m_game->unk_14A8, TRUE, 0x40);
    m_charOffset = charOffset + unk_168->sub_0200EE14("data/menu", "ma001_00", charOffset / 32, 14);

    unk_E0[0] = unk_158->sub_0200F4FC(0, 0x98, 0x9A, 0);
    unk_A0[0] = unk_158->unk_24;
    unk_E0[0]->sub_0200EB34(0x20, FALSE);
    unk_E0[1] = unk_158->sub_0200F4FC(0, 0xB6, 0x9A, 0);
    unk_A0[1] = unk_158->unk_24;
    unk_E0[1]->sub_0200EB34(1, TRUE);
    unk_E0[2] = unk_158->sub_0200F4FC(0, 0xD9, 0xAA, 0);
    unk_A0[2] = unk_158->unk_24;
    unk_E0[2]->sub_0200EB34(0x20, FALSE);
    unk_E0[3] = unk_158->sub_0200F4FC(0, 0xE9, 0xAA, 0);
    unk_A0[3] = unk_158->unk_24;
    unk_E0[3]->sub_0200EB34(0x20, FALSE);
    unk_158->sub_0200F4FC(10, 0xDA, 0x98, 0);
    unk_130[0] = unk_15C->sub_0200F4FC(4, 0xB4, 0x20, 1);
    unk_130[1] = unk_15C->sub_0200F4FC(5, 0xC0, 0x98, 1);
    unk_130[2] = unk_15C->sub_0200F4FC(6, 0x94, 0x14, 0);
    unk_13C = unk_15C->sub_0200F4FC(0, 0x40, 0x19, 1);
    unk_140 = unk_15C->sub_0200F4FC(3, 0x40, 0xA9, 1);
    int anim = 1;
    for (int i = 0; i < 8; i++) {
        int y = i * 16 + 0x29;
        unk_F0[i] = unk_15C->sub_0200F4FC(anim, 0x40, y, 1);
        if (anim == 1) {
            anim = 2;
        } else {
            anim = 1;
        }
        unk_110[i] = unk_160->sub_0200F4FC(0, 0x60, y, 0);
        unk_B0[i] = unk_160->unk_24;
    }
    unk_148 = unk_164->sub_0200F4FC(0, 0x80, 0x31, 0);
    unk_D0 = unk_164->unk_24;
    unk_14C = unk_168->sub_0200F4FC(0, 0x8C, 0x31, 0);
    unk_D4 = unk_168->unk_24;
}

void UnkClass_0213CC28::ov1_0213DE88()
{
    GXS_SetGraphicsMode(GX_BGMODE_1);
    GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG0Priority(0);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(3);
    G2S_SetBG3Priority(2);
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ, 8, 8);
}

void UnkClass_0213CC28::ov1_0213DF20()
{
    m_game->unk_1498->sub_0200CAE0();
    m_game->unk_1498->sub_0200CB14();
    m_game->unk_1498->sub_0200CC88(12);
    int charNo = 0x220;
    for (int i = 0; i < 8; i++) {
        m_game->unk_1498->sub_0200CCD0(i, 8, 2, 2, i * 2 + 4, charNo, 0, 2);
        charNo += 0x10;
    }
    m_game->unk_1498->sub_0200CCD0(8, 11, 2, 2, 2, charNo, 0, 2);
    charNo += 0x16;
    m_game->unk_1498->sub_0200CCD0(9, 8, 2, 0x16, 2, charNo, 0, 2);
    charNo += 0x10;
    m_game->unk_1498->sub_0200CCD0(10, 12, 2, 0x12, 5, charNo, 0, 2);
    charNo += 0x18;
    m_game->unk_1498->sub_0200CCD0(11, 8, 2, 0x14, 0x10, charNo, 0, 2);
}

void UnkClass_0213CC28::ov1_0213E0AC(int type, int arg2)
{
    if (unk_08 != 0x11) {
        m_game->unk_1498->sub_0200CDA0(11, 0, 4, 3, m_menuMes->unk_08[32].unk_04, FALSE, 0);
    }
    ov1_0213E12C();
    ov1_0213E1D8(type);
    ov1_0213E244(arg2);
}

void UnkClass_0213CC28::ov1_0213E12C()
{
    m_game->unk_1498->sub_0200CDA0(8, 2, 4, 5, m_menuMes->unk_08[31].unk_04, FALSE, 0);
    for (u8 i = 0; i < 8; i++) {
        if (unk_30[i] != 0) {
            if (unk_70[i] != 0) {
                ov1_0213EBB4(unk_30[i], i, 7);
            } else {
                ov1_0213EBB4(unk_30[i], i, 3);
            }
        }
    }
}

void UnkClass_0213CC28::ov1_0213E1D8(int type)
{
    if (type < 0) {
        return;
    }
    if (type > 0x11) {
        return;
    }
    m_game->unk_1498->sub_0200CDA0(9, 0, 2, 1, m_assistMes->unk_08[type + 1].unk_04, TRUE, -3);
}

void UnkClass_0213CC28::ov1_0213E244(u32 index)
{
    if (index >= 25) {
        index = 25;
    }
    m_game->unk_1498->sub_0200CDA0(10, 0, 4, 1, m_fieldWazaMes->unk_08[index].unk_04, TRUE, 2);
}

void UnkClass_0213CC28::ov1_0213E29C()
{
    for (int i = 0; i < 12; i++) {
        m_game->unk_1498->sub_0200CF7C(i);
    }
}

void UnkClass_0213CC28::ov1_0213E2CC()
{
    for (int i = 9; i < 12; i++) {
        m_game->unk_1498->sub_0200CF7C(i);
    }
}

void UnkClass_0213CC28::ov1_0213E2FC()
{
    for (int i = 0; i < 9; i++) {
        m_game->unk_1498->sub_0200CF7C(i);
    }
}

void UnkClass_0213CC28::ov1_0213E32C(int arg0)
{
    if (m_flags & 1) {
        return;
    }
    if (!(m_flags & 0x200)) {
        return;
    }
    unk_158->sub_0200F64C();
    unk_15C->sub_0200F64C();
    unk_160->sub_0200F64C();
    unk_164->sub_0200F64C();
    unk_168->sub_0200F64C();
    if (arg0) {
        ov1_0213E8BC(unk_2E);
    }
    if (m_mosaic) {
        ov1_0213D4D0();
    }
    if (m_blinkTimer < 12) {
        m_blinkTimer++;
    } else {
        if (m_blinkDir == 0 && m_blinkPal == 5) {
            m_blinkDir = 1;
        }
        if (m_blinkDir == 1 && m_blinkPal == 1) {
            m_blinkDir = 0;
        }
        m_blinkPal += m_blinkDir * -2 + 1;
        m_blinkTimer = 0;
        ov1_0213D458();
    }
    switch (m_rotState) {
    case 0:
        ov1_0213E52C();
        break;
    case 2:
        ov1_0213E60C();
        break;
    }
    ov1_0213E44C();
    ov1_0213D490();
}

void UnkClass_0213CC28::ov1_0213E44C()
{
    if (m_angle + 0x100 >= 0xFFFF) {
        m_angle = 0;
    }
    fx32 sinVal = FX_SinIdx(m_angle);
    fx32 cosVal = FX_CosIdx(m_angle);
    SetRotation(&m_bgMtx, sinVal, cosVal);
    m_flags |= 0x80;
    m_game->sub_020100E4(ov1_0213E708, NULL);
}

void UnkClass_0213CC28::ov1_0213E4CC()
{
    SetRotation(&m_bgMtx, FX_SinIdx(0), FX_CosIdx(0));
    G2S_SetBG3Affine(&m_bgMtx, 0x80, 0x60, m_bgX, m_bgY);
}

void UnkClass_0213CC28::ov1_0213E52C()
{
    if (m_rotFrame == 60) {
        m_angle = 0;
        m_rotFrame = 0;
        m_rotState = 1;
        ov1_0213E12C();
        ov1_0213D568();
        return;
    }
    if (m_rotFrame >= 60) {
        return;
    }
    if (m_rotFrame < 30) {
        m_bgX -= 15;
    } else if (m_rotFrame < 45) {
        m_bgX += 8;
    } else if (m_rotFrame < 55) {
        m_bgX += 4;
    } else {
        m_bgX += 1;
    }
    u16 speed = 3;
    if (m_rotFrame != 0) {
        speed = 3 - m_rotFrame / 20;
    }
    m_angle += (u16)(speed * 0x888);
    m_rotFrame++;
}

void UnkClass_0213CC28::ov1_0213E60C()
{
    if (m_rotFrame == 30) {
        m_angle = 0;
        m_rotFrame = 0;
        m_rotState = 1;
        return;
    }
    if (m_rotFrame >= 30) {
        return;
    }
    u16 speed = 3;
    if (m_rotFrame != 0) {
        speed = 3 - m_rotFrame / 10;
    }
    m_angle += (u16)(speed * 0x888);
    m_rotFrame++;
}

void UnkClass_0213CC28::ov1_0213E68C()
{
    if (m_rotState == 0) {
        return;
    }
    m_angle = 0;
    m_rotFrame = 0;
    m_rotState = 2;
}

void UnkClass_0213CC28::ov1_0213E6B0()
{
    if (!(m_flags & 0x80)) {
        return;
    }
    G2S_SetBG3Affine(&m_bgMtx, 0x80, 0x60, m_bgX, m_bgY);
    m_flags &= ~0x80;
}

static void ov1_0213E708(void *arg)
{
    if (sInstance != NULL) {
        sInstance->ov1_0213E6B0();
    }
}

void UnkClass_0213CC28::ov1_0213E728()
{
    if (m_flags & 1) {
        sub_02001210();
        return;
    }
    if (!ov1_0213F01C()) {
        return;
    }
    if ((m_flags & 2) && (m_flags & 4)) {
        m_pokeObj->sub_0200F71C();
    }
    unk_15C->sub_0200F71C();
    unk_164->sub_0200F71C();
    unk_168->sub_0200F71C();
    if (!(m_flags & 0x10)) {
        return;
    }
    unk_160->sub_0200F71C();
    if ((m_flags & 0x40) && unk_08 != 0x11) {
        unk_158->sub_0200F71C();
    }
}

void UnkClass_0213CC28::ov1_0213E7B8()
{
    ov1_0213E12C();
}

void UnkClass_0213CC28::ov1_0213E7C4(int hide)
{
    for (int i = 0; i < 3; i++) {
        if (hide == 0) {
            if (i == 1 && unk_08 == 0x11) {
                unk_130[i]->unk_14 = FALSE;
            } else {
                unk_130[i]->unk_14 = TRUE;
                unk_148->unk_14 = TRUE;
                unk_14C->unk_14 = TRUE;
                m_flags |= 0x40;
            }
        }
        if (hide == 1) {
            unk_130[i]->unk_14 = FALSE;
            unk_148->unk_14 = FALSE;
            unk_14C->unk_14 = FALSE;
            m_flags &= ~0x40;
        }
    }
    unk_15C->sub_0200F64C();
}

void UnkClass_0213CC28::ov1_0213E86C(int digit, int value)
{
    unk_158->sub_0200F628(unk_A0[digit], value);
}

void UnkClass_0213CC28::ov1_0213E884()
{
    u8 anim = unk_0F;
    if (anim > 5) {
        anim = 0;
    }
    unk_164->sub_0200F628(unk_D0, unk_0E);
    unk_168->sub_0200F628(unk_D4, anim);
}

void UnkClass_0213CC28::ov1_0213E8BC(u16 frames)
{
    int time = frames;
    if (ov1_0213EF2C() && unk_08 == 0x11) {
        time = 0;
    }
    int seconds = time / 60;
    int rest = time - seconds * 60;
    int fraction = 0;
    if (rest > 0) {
        fraction = FX32_DIV(rest * 5 << FX32_SHIFT, FX32_CONST(3)) >> FX32_SHIFT;
    }
    int secTens = seconds / 10;
    int fracTens = fraction / 10;
    ov1_0213E86C(0, secTens);
    ov1_0213E86C(1, seconds - secTens * 10);
    ov1_0213E86C(2, fracTens);
    ov1_0213E86C(3, fraction - fracTens * 10);
    unk_158->sub_0200F64C();
}

int UnkClass_0213CC28::ov1_0213E9B4(int assistType, int type)
{
    fx32 rate = ov1_0212EE80(assistType, type);
    if (rate == FX32_ONE) {
        return 0;
    }
    if (rate > FX32_ONE) {
        return 1;
    }
    if (rate < FX32_ONE) {
        return 2;
    }
    return 0;
}

void UnkClass_0213CC28::ov1_0213E9E4(u16 arg0)
{
    unk_2E = arg0;
}

int UnkClass_0213CC28::ov1_0213E9EC()
{
    return 0x29;
}

void UnkClass_0213CC28::ov1_0213E9F4(u8 count)
{
    if (count < 1) {
        return;
    }
    if (count > 8) {
        return;
    }
    unk_90 = count;
    ov1_0213EA3C(count, ov1_0213E9EC());
}

void UnkClass_0213CC28::ov1_0213EA2C(u8 index)
{
    unk_70[index] = TRUE;
}

void UnkClass_0213CC28::ov1_0213EA3C(int count, int y)
{
    for (int i = 0; i < 8; i++) {
        unk_F0[i]->unk_14 = FALSE;
        unk_110[i]->unk_14 = FALSE;
    }
    unk_13C->sub_0200EB28(0x40, y - 0x10);
    unk_140->sub_0200EB28(0x40, y + count * 16);
    for (int i = 0; i < count; i++) {
        unk_F0[i]->sub_0200EB28(0x40, y);
        unk_110[i]->sub_0200EB28(0x60, y);
        unk_F0[i]->unk_14 = FALSE;
        unk_110[i]->unk_14 = FALSE;
        y += 0x10;
    }
    unk_13C->unk_14 = FALSE;
    unk_140->unk_14 = FALSE;
    m_count = count;
}

void UnkClass_0213CC28::ov1_0213EB14(int mode, int index)
{
    if (mode == 0) {
        unk_110[index]->unk_14 = FALSE;
    }
    if (mode == 1) {
        unk_160->sub_0200F628(unk_B0[index], 0);
        unk_110[index]->unk_14 = TRUE;
    }
    if (mode == 2) {
        unk_160->sub_0200F628(unk_B0[index], 1);
        unk_110[index]->unk_14 = TRUE;
    }
    unk_160->sub_0200F64C();
}

u8 *UnkClass_0213CC28::ov1_0213EB9C(u16 id)
{
    return sub_02018B10(m_game->unk_14B0, id);
}

void UnkClass_0213CC28::ov1_0213EBB4(u16 id, int index, int color)
{
    u8 name[32];

    m_game->unk_1498->sub_0200CF7C(index);
    sub_0202BC74(ov1_0213EB9C(id), name, 0x1F);
    m_game->unk_1498->sub_0200CDA0(index, 4, 4, color, name, FALSE, 0);
}

void UnkClass_0213CC28::ov1_0213EC34(u8 arg0, u8 arg1)
{
    unk_91[arg1] = arg0;
}

int UnkClass_0213CC28::ov1_0213EC40(u8 type)
{
    int result = 0;
    for (u8 i = 0; i < 8; i++) {
        if (unk_91[i] == 0x12) {
            break;
        }
        if (unk_70[i] == 0) {
            int rate = ov1_0213E9B4(type, unk_91[i]);
            if (rate == 1) {
                result = 1;
            }
            if (rate == 2 && result == 0) {
                result = 2;
            }
        }
    }
    return result;
}

int UnkClass_0213CC28::ov1_0213ECB4(int arg0, int arg1, int arg2)
{
    unk_08 = arg0;
    unk_0E = arg1;
    unk_0F = arg2;
    ov1_0213D354(arg0);
    ov1_0213E29C();
    ov1_0213E0AC(arg0, arg1);
    ov1_0213E7C4(0);
    ov1_0213E884();
    ov1_0213EF14(1);
    int result = 0;
    m_flags &= ~4;
    for (u8 i = 0; i < 8; i++) {
        if (unk_91[i] == 0x12) {
            break;
        }
        if (unk_70[i] != 0) {
            ov1_0213EB14(0, i);
        } else {
            int rate = ov1_0213E9B4(arg0, unk_91[i]);
            if (rate == 1) {
                result = 1;
            }
            if (rate == 2 && result == 0) {
                result = 2;
            }
            ov1_0213EB14(rate, i);
        }
    }
    return result;
}

void UnkClass_0213CC28::ov1_0213EDA4(u16 arg0, u8 arg1)
{
    unk_30[arg1] = arg0;
}

void UnkClass_0213CC28::ov1_0213EDB0(u8 arg0, u8 arg1, u8 arg2)
{
    unk_04 = arg0;
    unk_0C = arg1;
    unk_0D = arg2;
    ov1_0213E29C();
    ov1_0213E0AC(unk_04, unk_0C);
}

void UnkClass_0213CC28::ov1_0213EDDC()
{
    unk_08 = unk_04;
    unk_0E = unk_0C;
    unk_0F = unk_0D;
    if (m_flags & 2) {
        ov1_0213E8BC(unk_2E);
        ov1_0213ECB4((u8)unk_04, unk_0C, unk_0D);
        m_flags |= 4;
        return;
    }
    ov1_0213D354(0x12);
    ov1_0213E2CC();
    ov1_0213EF14(0);
    ov1_0213E884();
    ov1_0213E7C4(1);
    ov1_0213E12C();
    if (ov1_0213EF80()) {
        ov1_0213EF14(1);
    }
    for (u8 i = 0; i < 8; i++) {
        ov1_0213EB14(0, i);
    }
}

void UnkClass_0213CC28::ov1_0213EEB8()
{
    m_pokeIcon = NULL;
    SAFE_DELETE(m_pokeObj);
    m_flags &= ~2;
    m_game->unk_1498->sub_0200CF7C(10);
}

void UnkClass_0213CC28::ov1_0213EF14(int arg0)
{
    if (arg0) {
        m_flags |= 0x10;
    } else {
        m_flags &= ~0x10;
    }
}

BOOL UnkClass_0213CC28::ov1_0213EF2C()
{
    return (m_flags & 0x10) ? TRUE : FALSE;
}

void UnkClass_0213CC28::ov1_0213EF40(int arg0)
{
    if (arg0) {
        m_flags |= 0x20;
        return;
    }
    m_flags &= ~0x20;
    if (m_flags & 2) {
        return;
    }
    unk_04 = 0x12;
    unk_0C = 0;
    unk_0D = 0;
}

BOOL UnkClass_0213CC28::ov1_0213EF80()
{
    return (m_flags & 0x20) ? TRUE : FALSE;
}

void UnkClass_0213CC28::ov1_0213EF94(int arg0)
{
    if (arg0) {
        m_flags |= 0x200;
    } else {
        m_flags &= ~0x200;
    }
    unk_13C->SetVisible(arg0);
    unk_140->SetVisible(arg0);
    for (int i = 0; i < m_count; i++) {
        unk_F0[i]->SetVisible(arg0);
    }
    ov1_0213E2FC();
}

u32 UnkClass_0213CC28::ov1_0213F01C()
{
    return m_flags & 0x200;
}
