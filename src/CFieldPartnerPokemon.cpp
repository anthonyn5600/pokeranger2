#include "field/CFieldPartnerPokemon.hpp"

#include <nitro.h>

#include "CGame.hpp"

extern "C" {
void LogError(const char *fmt, ...);
}

BOOL CFieldPokemonTargetClearScript::Run(u32 actorId, u32 targetId)
{
    if (unk_2C != NULL) {
        ScriptVM_Init(&unk_08, unk_30, unk_34);
        unk_08.unk_04 -= 2;
        u32 *args = unk_08.unk_04;
        args[0] = actorId;
        args[1] = targetId;
        if (ScriptVM_Start(&unk_08, unk_2C, "TargetClear") == -1) {
            LogError("not found func FieldPartnerPokemon.cpp");
            return FALSE;
        }
        unk_04 = 8;
    } else {
        LogError("m_pScriptBlock ==  NULL by FieldPartnerPokemon.cpp");
        return FALSE;
    }
    return TRUE;
}

CFieldPartnerPokemon::CFieldPartnerPokemon()
{
    unk_268 = -1;
    unk_26C = NULL;
    unk_274 = NULL;
    unk_278 = FALSE;
}

CFieldPartnerPokemon::~CFieldPartnerPokemon()
{
    SAFE_DELETE(unk_274);
    SAFE_DELETE(unk_26C);
}

void CFieldPartnerPokemon::Process(CFieldMap *map)
{
    UpdateScript();
    unk_EC.ov0_02152B04();
    Update(map);
}

BOOL CFieldPartnerPokemon::UpdateMove(CFieldMap *map)
{
    ov0_0213E4F0();
    ov0_02138628();
    BOOL result = CFieldActor::UpdateMove(map);
    unk_EC.ov0_02158988();
    if (result) {
        s_game->m_audioEngine->PlayStream(unk_268, 0x40);
    }
    return result;
}

BOOL CFieldPartnerPokemon::ov0_0213E3E4(u16 kind, u8 arg1)
{
    char path[0x34];
    u32 heapId = s_game->unk_14A8;
    OS_SPrintf(path, "data/Script/field/poketargetclear/ptc%03d_%02d.fsb", kind, arg1);
    SAFE_DELETE(unk_270);
    unk_26C = new CBinaryFile(path, 0, 0, heapId, NULL, 0);
    void *block = unk_26C->unk_4C;
    Script_Link(block);
    if (unk_274 == NULL) {
        unk_274 = new CFieldPokemonTargetClearScript();
    }
    unk_274->unk_2C = block;
    return TRUE;
}

BOOL CFieldPartnerPokemon::ov0_0213E4BC(u32 targetId)
{
    if (unk_274 == NULL) {
        return FALSE;
    }
    unk_278 = TRUE;
    return unk_274->Run(m_id, targetId);
}

void CFieldPartnerPokemon::ov0_0213E4F0()
{
    if (unk_278 && unk_274 != NULL) {
        unk_274->Step();
        if (unk_274->unk_04 == 2) {
            unk_278 = FALSE;
        }
    }
}
