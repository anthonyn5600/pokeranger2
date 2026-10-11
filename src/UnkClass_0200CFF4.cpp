#include "UnkClass_0200CFF4.hpp"

#include "CGame.hpp"

extern "C" {
extern char s_data_font_font_jp_utf8_NFTR_0208aa74;
extern char s_data_font_font_jp_lc_utf8_NFTR_0208aa94;
extern char s_data_font_font_us_utf8_NFTR_0208aab4;
extern char s_data_font_font_us_lc_utf8_NFTR_0208aad4;
}

UnkClass_0200CFF4::UnkClass_0200CFF4(u32 arg0)
{
    BOOL us = FALSE;
    if (CGame::GetInstance() != NULL) {
        us = TRUE;
    }

    if (!us) {
        unk_00 = new CBinaryFile(&s_data_font_font_jp_utf8_NFTR_0208aa74, 0, 0, 0, NULL, 0);
        unk_04 = new CBinaryFile(&s_data_font_font_jp_lc_utf8_NFTR_0208aa94, 0, 0, 0, NULL, 0);
    } else {
        unk_00 = new CBinaryFile(&s_data_font_font_us_utf8_NFTR_0208aab4, 0, 0, 0, NULL, 0);
        unk_04 = new CBinaryFile(&s_data_font_font_us_lc_utf8_NFTR_0208aad4, 0, 0, 0, NULL, 0);
    }

    NNS_G2dFontInitAuto(&unk_0C, unk_00->unk_4C);
    NNS_G2dFontInitAuto(&unk_14, unk_04->unk_4C);
}
