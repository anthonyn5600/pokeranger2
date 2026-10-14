#include "scene/CTitleBG.hpp"

#include <nitro.h>
#include <string.h>

#include "BGLayer.hpp"

static CTitleBG::LayerConfig sLayersDay[4] = {
    { 0, 0, 0, 0 },
    { 0, 1, 0, 0 },
    { 1, 0, 1, -0x214 },
    { 1, 0, 1, -0xF5 },
};

static CTitleBG::LayerConfig sLayersNight[4] = {
    { 0, 0, 0, 0 },
    { 0, 1, 0, 0 },
    { 0, 0, 1, 0x1000 },
    { 0, 0, 0, 0 },
};

static CTitleBG::LayerConfig *sLayers[2] = { sLayersDay, sLayersNight };

CTitleBG::CTitleBG()
{
    m_mode = -1;
    for (int i = 0; i < 4; i++) {
        m_scroll[i] = 0;
    }
}

CTitleBG::~CTitleBG()
{
}

void CTitleBG::SetupBG(int mode)
{
    G2_SetBG0Control((GXBGScrSizeText)sLayers[mode][0].screenSize, (GXBGColorMode)sLayers[mode][0].colorMode, GX_BG_SCRBASE_0x0000, GX_BG_CHARBASE_0x04000, GX_BG_EXTPLTT_01);
    G2_SetBG1Control((GXBGScrSizeText)sLayers[mode][1].screenSize, (GXBGColorMode)sLayers[mode][1].colorMode, GX_BG_SCRBASE_0x1000, GX_BG_CHARBASE_0x14000, GX_BG_EXTPLTT_01);
    G2_SetBG2ControlText((GXBGScrSizeText)sLayers[mode][2].screenSize, (GXBGColorMode)sLayers[mode][2].colorMode, GX_BG_SCRBASE_0x2000, GX_BG_CHARBASE_0x24000);
    G2_SetBG3ControlText((GXBGScrSizeText)sLayers[mode][3].screenSize, (GXBGColorMode)sLayers[mode][3].colorMode, GX_BG_SCRBASE_0x3000, GX_BG_CHARBASE_0x34000);
    G2_SetBG0Offset(0, 0);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
}

void CTitleBG::Load(int mode)
{
    ResetOffsets();
    if (mode >= 0 && (u32)mode < 2) {
        m_mode = mode;
        SetupBG(mode);
        for (int i = 0; i < 4; i++) {
            char path[32];
            char name[32];
            OS_SPrintf(name, "title_ue%d%d", mode, i);
            strcpy(path, name);
            strcat(path, "_");
            BGS_LoadCharAndPltt("title/", path, i, name, 0, name, 0);
            BGS_LoadScr("title/", path, i, name, 0, 0, 0, 0);
        }
    } else {
        m_mode = -1;
    }
}

void CTitleBG::ResetOffsets()
{
    G2_SetBG0Offset(0, 0);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
}

void CTitleBG::Update()
{
    if (m_mode < 0) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        switch (sLayers[m_mode][i].scrollType) {
        case 0:
            break;
        case 1:
            m_scroll[i] += sLayers[m_mode][i].speed;
            while (m_scroll[i] > 0x200000) {
                m_scroll[i] -= 0x200000;
            }
            while (m_scroll[i] < 0) {
                m_scroll[i] += 0x200000;
            }
            break;
        }
    }
}

void CTitleBG::Apply()
{
    for (int i = 0; i < 4; i++) {
        switch (sLayers[m_mode][i].scrollType) {
        case 0:
            break;
        case 1:
            SetOffset(i, m_scroll[i] >> FX32_SHIFT, 0);
            break;
        }
    }
}

void CTitleBG::SetOffset(int bg, int h, int v)
{
    switch (bg) {
    case 0:
        G2_SetBG0Offset(h, v);
        break;
    case 1:
        G2_SetBG1Offset(h, v);
        break;
    case 2:
        G2_SetBG2Offset(h, v);
        break;
    case 3:
        G2_SetBG3Offset(h, v);
        break;
    }
}
