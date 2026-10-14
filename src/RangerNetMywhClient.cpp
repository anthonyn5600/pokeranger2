#include "CGame.hpp"
#include "RangerNetMywh.hpp"
#include "UnkClass_02034478.hpp"
#include "UnkClass_0211E05C.hpp"
#include "UnkClass_0212D97C.hpp"
#include "UnkClass_0212F3DC.hpp"

// Clients of the mywh connection (0212EBCC..0212F648): UnkClass_0212D97C's download states and
// UnkClass_0212F3DC, both driving the mywh connection through a state callback.

// RangerNetSession.cpp
void ov11_02128FEC();
WVRResult ov11_02129040();

static int sLogoState;
static int sDownloadState;

static void ov11_0212F32C(int state);
static void ov11_0212F5C8(int state);

void UnkClass_0212D97C::ov11_0212EBCC()
{
    switch (unk_152) {
    case 0:
        sDownloadState = 0;
        unk_152 = 1;
        break;
    case 1:
        unk_194->unk_710 = 1;
        CGame::GetInstance()->m_audioEngine->sub_02034C44(0xD1);
        unk_194->ov11_02122B7C(2, 1, 0, 1);
        if (!ov11_0212FE30(unk_050, ov11_0212F32C, unk_04C)) {
            unk_194->ov11_02122B7C(3, 1, 0, 1);
            ov11_0212F3B0();
            break;
        }
        unk_152 = 3;
        unk_144 = 7200;
        break;
    case 3:
        if (!ov11_02130200()) {
            break;
        }
        unk_194->ov11_0211FBE4(5);
        unk_152 = 4;
    case 4:
        unk_194->ov11_0211FB08(2, ov11_021301BC());
        if (sDownloadState == 2 || sDownloadState == 4) {
            if (ov11_021301DC() == NULL) {
                break;
            }
            ov11_0212E9B4(3);
            CGame::GetInstance()->m_audioEngine->sub_02034C5C(0xD1);
            CGame::GetInstance()->m_audioEngine->sub_02034C44(0xD2);
        } else if (sDownloadState == 5 || --unk_144 == 0) {
            unk_194->ov11_02122B7C(3, 1, 0, 1);
            ov11_0212F3B0();
        }
        break;
    case 11:
        unk_152 = 12;
        break;
    case 12:
        unk_152 = 25;
        ov11_0212FD74();
        break;
    case 20:
        if (unk_194->ov11_02122428()) {
            ov11_0212E9B4(8);
        }
        break;
    case 25:
        break;
    }
}

void UnkClass_0212D97C::ov11_0212EE24()
{
    const char *name = (const char *)ov11_021301DC();

    switch (unk_152) {
    case 0:
        unk_152 = 4;
        break;
    case 3:
        unk_152 = 4;
        break;
    case 4:
        unk_188 = unk_194->ov11_02123C8C(name);
        for (int i = 0; i < 11; i++) {
            unk_15C[i] = -1;
        }
        if (unk_188 < 0) {
            unk_188 = 10;
        }
        unk_15C[unk_188] = 1;
        unk_194->ov11_021217D4(unk_15C, TRUE, 7);
        unk_152 = 5;
        break;
    case 5: {
        int sel = unk_194->ov11_021212B4();
        if (sel < 0) {
            break;
        }
        unk_188 = sel - 11;
        unk_194->ov11_02122B7C(4, 1, 1, 1);
        unk_152 = 10;
        break;
    }
    case 10:
        ov11_0212E9B4(4);
        break;
    case 20:
        if (unk_194->ov11_02122428()) {
            ov11_0212E9B4(8);
        }
        break;
    case 25:
        break;
    }
}

void UnkClass_0212D97C::ov11_0212EF94()
{
    if (unk_048 != 0) {
        unk_048--;
    }
    switch (unk_152) {
    case 0:
        unk_048 = 7200;
        unk_152 = 4;
        unk_154 = 0;
        unk_144 = 15;
        unk_194->ov11_0211EF5C();
        CGame::GetInstance()->m_audioEngine->sub_02034C44(0xD1);
        break;
    case 3:
        unk_152 = 4;
        break;
    case 4: {
        unk_194->ov11_0211F06C();
        u16 n = ov11_0213018C();
        if (n == ov11_021301A4() && sDownloadState == 3) {
            unk_152 = 11;
            ov11_0212FD74();
            break;
        }
        if (sDownloadState == 5 || unk_048 == 0) {
            unk_194->ov11_02122B7C(16, 1, 0, 1);
            ov11_0212F3B0();
            break;
        }
        if (ov11_021301BC() <= 1) {
            unk_194->ov11_02122B7C(14, 1, 1, 1);
        }
        break;
    }
    case 11:
        unk_194->ov11_0211F06C();
        if (sDownloadState == 4 || sDownloadState == 6) {
            ov11_02130210(unk_050, unk_050);
            ov11_0212E9B4(7);
        }
        break;
    case 12:
        break;
    case 20:
        if (unk_194->ov11_02122428()) {
            ov11_0212E9B4(8);
        }
        break;
    case 25:
        break;
    }
}

void UnkClass_0212D97C::ov11_0212F158()
{
    switch (unk_152) {
    case 0:
        unk_194->unk_710 = 0;
        unk_194->ov11_0211F06C();
        unk_144 = 120;
        unk_152 = 13;
        unk_194->ov11_02122B7C(5, 1, 1, 1);
        unk_194->ov11_0211FBE4(3);
        unk_194->ov11_0211FB08(0, -1);
        break;
    case 13:
        unk_194->ov11_0211F06C();
        if (--unk_144 != 0) {
            break;
        }
        unk_152 = 16;
        unk_194->ov11_02121000(unk_050);
        unk_194->ov11_02122B7C(6, 1, 1, 1);
        break;
    case 16: {
        int ret = unk_194->ov11_02121010();
        if (ret == 0) {
            break;
        }
        if (ret < 0) {
            unk_194->ov11_02122B7C(13, 1, 0, 1);
            unk_152 = 19;
            break;
        }
        unk_194->ov11_0212374C(unk_188, FALSE);
        unk_152 = 25;
        break;
    }
    case 19:
        break;
    case 25:
        if (unk_194->ov11_02122428()) {
            ov11_0212E9B4(8);
        }
        break;
    case 20:
        if (unk_194->ov11_02122428()) {
            ov11_0212E9B4(8);
        }
        break;
    }
}

static void ov11_0212F32C(int state)
{
    switch (state) {
    case 0:
        sDownloadState = 1;
        break;
    case 1:
        sDownloadState = 2;
        break;
    case 2:
        sDownloadState = 3;
        break;
    case 3:
        if (sDownloadState == 3) {
            sDownloadState = 4;
        } else {
            sDownloadState = 6;
        }
        break;
    case 4:
        sDownloadState = 5;
        break;
    }
}

void UnkClass_0212D97C::ov11_0212F3B0()
{
    ov11_0212FD74();
    unk_152 = 20;
    unk_194->ov11_02124520();
    unk_194->unk_710 = 0;
}

UnkClass_0212F3DC::UnkClass_0212F3DC()
{
    unk_0 = new u8[ov11_021301D4()];
    unk_4 = new u8[0xF000];
    unk_8 = 0;
    sLogoState = 0;
    CGame::GetInstance()->unk_15DC = 0;
}

UnkClass_0212F3DC::~UnkClass_0212F3DC()
{
    if (unk_0 != NULL) {
        delete[] unk_0;
        unk_0 = NULL;
    }
    if (unk_4 != NULL) {
        delete[] unk_4;
        unk_4 = NULL;
    }
}

BOOL UnkClass_0212F3DC::ov11_0212F46C()
{
    switch (unk_8) {
    case 0:
        unk_8 = 1;
        ov11_02128FEC();
        break;
    case 1:
        if (!ov11_0212FE30(unk_4, ov11_0212F5C8, unk_0)) {
            unk_8 = 25;
        } else {
            unk_8 = 3;
            unk_A = 30;
        }
        break;
    case 3:
        if (sLogoState != 1) {
            break;
        }
        unk_8 = 4;
    case 4:
        if (sLogoState == 2 || sLogoState == 3) {
            CGame::GetInstance()->unk_15DC = 1;
            unk_8 = 25;
        } else if (sLogoState == 5 || --unk_A == 0) {
            unk_8 = 25;
        }
        break;
    case 25:
        ov11_0212FD74();
        unk_8 = 24;
        break;
    case 24:
        switch (sLogoState) {
        case 4:
        case 5:
        case 6:
            ov11_02129040();
            unk_8 = 26;
            break;
        }
        break;
    case 26:
        return FALSE;
    }
    return TRUE;
}

static void ov11_0212F5C8(int state)
{
    switch (state) {
    case 0:
        sLogoState = 1;
        break;
    case 1:
        sLogoState = 2;
        break;
    case 2:
        sLogoState = 3;
        break;
    case 3:
        if (sLogoState == 3) {
            sLogoState = 4;
        } else {
            sLogoState = 6;
        }
        break;
    case 4:
        sLogoState = 5;
        break;
    }
}
