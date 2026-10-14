#include "field/CFieldNpc.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "FieldScriptLauncher.hpp"
#include "field/CFieldMap.hpp"
#include "file/CBinaryFile.hpp"

extern "C" {
void LogError(const char *fmt, ...);
}

BOOL CFieldNpcActorScript::Call(CFieldActor *actor, const char *func)
{
    if (unk_2C != NULL && actor != NULL) {
        ScriptVM_Init(&unk_08, unk_30, unk_34);
        *--unk_08.unk_04 = actor->unk_58;
        if (func != NULL) {
            if (ScriptVM_Start(&unk_08, unk_2C, func) == -1) {
                LogError("not found func FieldNpc.cpp");
                return FALSE;
            }
        } else {
            LogError("null func name FieldNpc.cpp");
            return FALSE;
        }
        unk_04 = 8;
    } else {
        LogError("m_pScriptBlock ==  NULL by FieldNpc.cpp");
        return FALSE;
    }
    return TRUE;
}

CFieldNpc::CFieldNpc()
{
    unk_10 = 0x2000;
    Rectangle bounds = { { 0, -0x8000 }, { 0x10000, 0x20000 } };
    unk_24.pos.x = bounds.pos.x;
    unk_24.pos.y = bounds.pos.y;
    unk_24.size.x = bounds.size.x;
    unk_24.size.y = bounds.size.y;
    unk_1D0 = NULL;
    unk_1D4 = 0;
    unk_F4.unk_48 = this;
}

CFieldNpc::~CFieldNpc()
{
    SAFE_DELETE(unk_1D0);
}

BOOL CFieldNpc::sub_0203DA38()
{
    if (MAIN_BSS_0210CA44 == NULL) {
        return FALSE;
    }
    MAIN_BSS_0210CA44->ov0_0213FC24(this, "main", -1);
    return TRUE;
}

void CFieldNpc::LoadScript(int npcId)
{
    char path[0x80];
    SAFE_DELETE(unk_1D0);
    unk_1D4 = 0;
    u32 heapId = s_game->unk_14A8;
    OS_SPrintf(path, "data/Script/field/npc/n%03d/Npc%06d.fsb", npcId / 1000, npcId);
    unk_1D4 = npcId;
    unk_1D0 = new CBinaryFile(path, 0, 0, heapId, NULL, 0);
    void *block = unk_1D0->unk_4C;
    Script_Link(block);
    SetScript(new CFieldNpcActorScript(), block);
    unk_DC->Call(this, "normal");
    unk_0C = TRUE;
}

void CFieldNpc::Process(CFieldMap *map)
{
    unk_78 = 0;
    if (unk_DC != NULL && unk_DC->unk_04 == 2) {
        unk_DC->Call(this, "normal");
        unk_0C = TRUE;
    }
    UpdateScript();
    Update(map);
    if (unk_E8 != 0) {
        unk_F4.ov0_02158988();
    }
}

BOOL CFieldNpc::UpdateMove(CFieldMap *map)
{
    if (unk_E8 == 0) {
        unk_78 = 1;
    } else {
        unk_78 = 0;
    }
    BOOL result = CFieldActor::UpdateMove(map);
    if (result && unk_E8 != 0) {
        s_game->m_audioEngine->PlayStream(unk_F0, 0x40);
    }
    if (unk_E8 != 0) {
        unk_F4.ov0_02158988();
    }
    return result;
}

void CFieldNpc::ov0_0213C5DC()
{
    if (unk_E8 != 0) {
        unk_F4.ov0_02158F38();
    }
}

void CFieldNpc::sub_02032A44(int sequence)
{
    unk_F4.ov0_0215674C(sequence);
}

void CFieldNpc::StopMotion()
{
    if (unk_08 != NULL && unk_08->unk_0C != NULL) {
        unk_08->unk_0C->m_motion.m_mode = 0;
    }
}
