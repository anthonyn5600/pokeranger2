#include "AudioEngine.hpp"
#include "CGame.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "scene/CQuestListScene.hpp"

QLAnimLoader::QLAnimLoader()
{
    unk_00 = 0;
    unk_04 = 0;
    unk_08 = 0;
}

OamSpriteSet *QLAnimLoader::Load(const char *dir, const char *name, int plttCount, int oamIdx)
{
    CGame *game = CGame::GetInstance();
    if (oamIdx < 0) {
        oamIdx = unk_08;
    }
    OamSpriteSet *anims = new OamSpriteSet((GXOamAttr *)&game->unk_0424[(u8)oamIdx], game->unk_14A8, TRUE, 0x40);
    anims->LoadFiles(dir, name, unk_00, unk_04);
    anims->CopyToVram();
    anims->Update();
    unk_00 += anims->unk_28;
    unk_04 += plttCount;
    return anims;
}

void QLAnimLoader::ReserveOam(OamSpriteSet *anims, int oamIdx)
{
    if (oamIdx < 0) {
        oamIdx = unk_08;
    }
    int next = oamIdx + anims->unk_30;
    if (next > unk_08) {
        unk_08 = next;
    }
}

BOOL QLPushButton::Init(int id, OamSpriteSet *anims, int animNormal, int animPressed, int x, int y, int w, int h, int priority, int type)
{
    unk_04 = id;
    unk_00 = type;
    unk_08[0] = anims->AddSprite(animNormal, x, y, priority);
    unk_08[1] = anims->AddSprite(animPressed, x, y, priority);
    if (unk_08[0] != NULL) {
        unk_08[0]->SetTouchRect(w, h, 0, 0);
    }
    if (unk_08[0] != NULL && unk_08[1] != NULL) {
        return TRUE;
    }
    return FALSE;
}

void QLPushButton::Update()
{
    switch (unk_00) {
    case 0:
    default:
        UpdateNormal();
        break;
    case 1:
        UpdateBlink();
        break;
    }
}

void QLPushButton::UpdateNormal()
{
    if (unk_08[0] != NULL && unk_08[1] != NULL) {
        unk_20 = unk_08[0]->GetTouchHold();
        BOOL fire = FALSE;
        BOOL repeat = FALSE;
        BOOL pressed = TRUE;
        if (!(unk_18 & (unk_1C ^ unk_18)) && !unk_08[0]->GetTouchTrigger()) {
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

void QLPushButton::UpdateBlink()
{
    if (unk_08[0] != NULL && unk_08[1] != NULL) {
        if (unk_30 && unk_28 > 0) {
            return;
        }
        BOOL pressed = TRUE;
        if (!(unk_18 & (unk_1C ^ unk_18)) && !unk_08[0]->GetTouchTrigger()) {
            pressed = FALSE;
        }
        if (pressed) {
            if (unk_30) {
                CGame::GetInstance()->m_audioEngine->PlaySe(250);
                unk_28 = 8;
                unk_2C = 0;
            } else {
                CGame::GetInstance()->m_audioEngine->PlaySe(253);
            }
        }
        unk_1C = unk_18;
    }
}

void QLPushButton::UpdateAnim()
{
    if (unk_08[0] != NULL && unk_08[1] != NULL) {
        switch (unk_00) {
        case 0:
        default:
            UpdateAnimNormal();
            break;
        case 1:
            UpdateAnimBlink();
            break;
        }
    }
}

void QLPushButton::UpdateAnimNormal()
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

void QLPushButton::UpdateAnimBlink()
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

void QLPushButton::ResetInput()
{
    unk_14 = 0;
    unk_18 = 0;
    unk_1C = 0;
    unk_20 = 0;
    unk_24 = 0;
    unk_28 = 0;
}
