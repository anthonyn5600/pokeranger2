#include "FieldScriptLauncher.hpp"

#include <string.h>

#include "CGame.hpp"
#include "ScriptManager.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldActorScript.hpp"
#include "field/CFieldPlayer.hpp"
#include "field/CFieldTargetObject.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;
extern CFieldPlayer *MAIN_BSS_0210CA48;

FieldScriptLauncher::FieldScriptLauncher(CGame *game)
{
    MAIN_BSS_0210CA44 = this;
    m_game = game;
    ov0_0213F960();
}

FieldScriptLauncher::~FieldScriptLauncher()
{
    ov0_0213F960();
    MAIN_BSS_0210CA44 = NULL;
}

void FieldScriptLauncher::ov0_0213F960()
{
    m_state = 0;
    m_label[0] = '\0';
    unk_28 = 0;
    m_actor = NULL;
    m_pendingKind = 0;
    m_pendingLabel[0] = '\0';
    m_pendingArg = 0;
    m_pendingActor = NULL;
    m_pendingFade = -1;
}

void FieldScriptLauncher::ov0_0213F990()
{
    m_pendingKind = 0;
    m_pendingLabel[0] = '\0';
    m_pendingArg = 0;
    m_pendingActor = NULL;
    m_pendingFade = -1;
}

void FieldScriptLauncher::ov0_0213F9B0(BOOL startPending)
{
    unk_30 = 0;
    switch (m_state) {
    case 1:
        if (ScriptManager_IsRunning(m_game->m_scriptManager) == 0 && unk_30 == 0) {
            m_state = 0;
            m_label[0] = '\0';
            unk_28 = 0;
        }
        break;
    case 2:
        m_actor->UpdateScript();
        if (m_actor->GetDCState() == 2) {
            m_actor->unk_0C = FALSE;
            m_actor = NULL;
            if (unk_30 == 0) {
                m_state = 0;
                m_label[0] = '\0';
                unk_28 = 0;
            }
        }
        break;
    case 3: {
        CFieldTargetObject *obj = (CFieldTargetObject *)m_actor;
        obj->ov0_0213CFBC();
        if ((obj->unk_F8 != NULL ? obj->unk_F8->unk_04 : 2) == 2) {
            obj->unk_FC = FALSE;
            m_actor = NULL;
            if (unk_30 == 0) {
                m_state = 0;
                m_label[0] = '\0';
                unk_28 = 0;
            }
        }
        break;
    }
    }

    if (!startPending || m_state != 0) {
        return;
    }
    switch (m_pendingKind) {
    case 1:
        ov0_0213FD60(m_pendingLabel, m_pendingArg, m_pendingFade);
        break;
    case 2:
        ov0_0213FDFC(m_pendingActor, m_pendingLabel, m_pendingFade);
        break;
    }
    ov0_0213F990();
}

BOOL FieldScriptLauncher::ov0_0213FB0C(const char *label, int arg, int fade)
{
    if (!ov0_0213FEEC()) {
        CFieldPlayer *player = MAIN_BSS_0210CA48;
        if (player != NULL) {
            player->sub_show();
            player->sub_0201287C_();
            player->ResetMove();
            player->ov0_021341E0();
        }
        CFieldScene *scene = MAIN_BSS_0210CA40;
        if (scene != NULL) {
            scene->unk_0078 = 0;
            scene->ov0_0212451C();
        }
    }
    m_pendingKind = 1;
    strcpy(m_pendingLabel, label);
    m_pendingArg = arg;
    m_pendingActor = NULL;
    m_pendingFade = fade;
    return TRUE;
}

BOOL FieldScriptLauncher::ov0_0213FC24(CFieldActor *actor, const char *label, int fade)
{
    if (!ov0_0213FEEC()) {
        CFieldPlayer *player = MAIN_BSS_0210CA48;
        if (player != NULL && !player->ov0_0213416C() && (((int)actor->unk_58 >> 24) & 0xFF) == 2) {
            player->sub_show();
            player->sub_0201287C_();
            player->ResetMove();
            player->ov0_021341E0();
        }
        CFieldScene *scene = MAIN_BSS_0210CA40;
        if (scene != NULL) {
            scene->unk_0078 = 0;
            scene->ov0_0212451C();
        }
    }
    m_pendingKind = 2;
    strcpy(m_pendingLabel, label);
    m_pendingActor = actor;
    m_pendingArg = 0;
    m_pendingFade = fade;
    return TRUE;
}

void FieldScriptLauncher::ov0_0213FD60(const char *label, int arg, int fade)
{
    if (m_actor != NULL) {
        m_actor->StopScript();
        m_actor->unk_0C = FALSE;
    }
    strcpy(m_label, label);
    m_state = 1;
    unk_28 = 0;
    sub_02034374(m_game->m_scriptManager, arg);
    ScriptManager_Run(m_game->m_scriptManager, label);
    MAIN_BSS_0210CA40->ov0_02123E58(fade);
    unk_30 = 1;
}

BOOL FieldScriptLauncher::ov0_0213FDFC(CFieldActor *actor, const char *label, int fade)
{
    if (actor != NULL && label != NULL) {
        if (m_actor != NULL) {
            m_actor->StopScript();
            m_actor->unk_0C = FALSE;
        }
        ScriptManager_IsBusy(m_game->m_scriptManager);
        m_actor = actor;
        strcpy(m_label, label);
        unk_28 = 0;
        MAIN_BSS_0210CA40->ov0_02123E58(fade);
        if ((((int)actor->unk_58 >> 24) & 0xFF) != 3) {
            m_state = 2;
            m_actor->RunScriptLabel(label);
            m_actor->unk_0C = TRUE;
        } else {
            m_state = 3;
            CFieldTargetObject *obj = (CFieldTargetObject *)m_actor;
            obj->ov0_0213CF60(label);
            obj->unk_FC = TRUE;
        }
        unk_30 = 1;
        return TRUE;
    }
    return FALSE;
}

BOOL FieldScriptLauncher::ov0_0213FEEC()
{
    if (m_state != 0 || m_pendingKind != 0 || ScriptManager_IsRunning(m_game->m_scriptManager)) {
        return TRUE;
    }
    return FALSE;
}

BOOL FieldScriptLauncher::ov0_0213FF2C()
{
    if (m_state != 0 || ScriptManager_IsRunning(m_game->m_scriptManager)) {
        return TRUE;
    }
    return FALSE;
}
