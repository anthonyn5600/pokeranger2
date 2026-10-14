#include "CGame.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_02034478.hpp"
#include "scene/CQuestListScene.hpp"

UnkClass_0211E2A4::UnkClass_0211E2A4()
{
    unk_00 = 0;
    unk_04 = 0;
    unk_08 = 0;
}

UnkClass_0200ECD0 *UnkClass_0211E2A4::ov27_0211E2B8(const char *dir, const char *name, int plttCount, int oamIdx)
{
    CGame *game = CGame::GetInstance();
    if (oamIdx < 0) {
        oamIdx = unk_08;
    }
    UnkClass_0200ECD0 *anims = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[(u8)oamIdx], game->unk_14A8, TRUE, 0x40);
    anims->sub_0200F168(dir, name, unk_00, unk_04);
    anims->sub_0200F398();
    anims->sub_0200F64C();
    unk_00 += anims->unk_28;
    unk_04 += plttCount;
    return anims;
}

void UnkClass_0211E2A4::ov27_0211E374(UnkClass_0200ECD0 *anims, int oamIdx)
{
    if (oamIdx < 0) {
        oamIdx = unk_08;
    }
    int next = oamIdx + anims->unk_30;
    if (next > unk_08) {
        unk_08 = next;
    }
}

BOOL UnkClass_0211E394::ov27_0211E394(int id, UnkClass_0200ECD0 *anims, int animNormal, int animPressed, int x, int y, int w, int h, int priority, int type)
{
    unk_04 = id;
    unk_00 = type;
    unk_08[0] = anims->sub_0200F4FC(animNormal, x, y, priority);
    unk_08[1] = anims->sub_0200F4FC(animPressed, x, y, priority);
    if (unk_08[0] != NULL) {
        unk_08[0]->sub_0200EBF4(w, h, 0, 0);
    }
    if (unk_08[0] != NULL && unk_08[1] != NULL) {
        return TRUE;
    }
    return FALSE;
}

void UnkClass_0211E394::ov27_0211E438()
{
    switch (unk_00) {
    case 0:
    default:
        ov27_0211E460();
        break;
    case 1:
        ov27_0211E598();
        break;
    }
}

void UnkClass_0211E394::ov27_0211E460()
{
    if (unk_08[0] != NULL && unk_08[1] != NULL) {
        unk_20 = unk_08[0]->sub_0200EBBC();
        BOOL fire = FALSE;
        BOOL repeat = FALSE;
        BOOL pressed = TRUE;
        if (!(unk_18 & (unk_1C ^ unk_18)) && !unk_08[0]->sub_0200EB84()) {
            pressed = FALSE;
        }
        BOOL released = TRUE;
        if (!(unk_1C & (unk_1C ^ unk_18)) && !(unk_24 & (unk_24 ^ unk_20))) {
            released = FALSE;
        }
        if (pressed) {
            unk_14 = 24;
            fire = TRUE;
        } else if (unk_18 != 0 || unk_20 != 0) {
            if (unk_14 > 0) {
                if (--unk_14 <= 0) {
                    fire = TRUE;
                    repeat = TRUE;
                    unk_14 = 8;
                }
            }
        } else {
            unk_14 = 0;
        }
        if (unk_10 != NULL) {
            if (fire) {
                unk_10->OnPushButton(unk_04, repeat);
            } else if (released) {
                unk_10->OnReleaseButton(unk_04);
            }
        }
        unk_1C = unk_18;
        unk_24 = unk_20;
    }
}

void UnkClass_0211E394::ov27_0211E598()
{
    if (unk_08[0] != NULL && unk_08[1] != NULL) {
        if (unk_30 && unk_28 > 0) {
            return;
        }
        BOOL pressed = TRUE;
        if (!(unk_18 & (unk_1C ^ unk_18)) && !unk_08[0]->sub_0200EB84()) {
            pressed = FALSE;
        }
        if (pressed) {
            if (unk_30) {
                CGame::GetInstance()->m_audioEngine->sub_02034C44(250);
                unk_28 = 8;
                unk_2C = 0;
            } else {
                CGame::GetInstance()->m_audioEngine->sub_02034C44(253);
            }
        }
        unk_1C = unk_18;
    }
}

void UnkClass_0211E394::ov27_0211E64C()
{
    if (unk_08[0] != NULL && unk_08[1] != NULL) {
        switch (unk_00) {
        case 0:
        default:
            ov27_0211E688();
            break;
        case 1:
            ov27_0211E708();
            break;
        }
    }
}

void UnkClass_0211E394::ov27_0211E688()
{
    if (!unk_30) {
        unk_08[0]->unk_14 = FALSE;
        unk_08[1]->unk_14 = TRUE;
    } else if ((unk_20 != 0 || unk_18 != 0) && unk_14 >= 4) {
        unk_08[0]->unk_14 = FALSE;
        unk_08[1]->unk_14 = TRUE;
    } else {
        unk_08[0]->unk_14 = TRUE;
        unk_08[1]->unk_14 = FALSE;
    }
}

void UnkClass_0211E394::ov27_0211E708()
{
    if (unk_30 && unk_28 > 0) {
        if (unk_2C < 8) {
            unk_08[0]->unk_14 = FALSE;
            unk_08[1]->unk_14 = TRUE;
        } else {
            unk_08[0]->unk_14 = TRUE;
            unk_08[1]->unk_14 = FALSE;
        }
        if (++unk_2C >= 16) {
            unk_2C = 0;
        }
        if (--unk_28 <= 0 && unk_10 != NULL) {
            unk_10->OnPushButton(unk_04, FALSE);
        }
    } else {
        unk_08[0]->unk_14 = TRUE;
        unk_08[1]->unk_14 = FALSE;
    }
}

void UnkClass_0211E394::ov27_0211E7CC()
{
    unk_14 = 0;
    unk_18 = 0;
    unk_1C = 0;
    unk_20 = 0;
    unk_24 = 0;
    unk_28 = 0;
}
