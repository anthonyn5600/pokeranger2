#include "field/CFieldPartnerNpc.hpp"

#include <nitro.h>
#include <string.h>

#include "FieldScriptLauncher.hpp"

CFieldPartnerNpc::CFieldPartnerNpc()
{
    Rectangle bounds = { { 0, -0x8000 }, { 0x10000, 0x20000 } };
    unk_24.pos.x = bounds.pos.x;
    unk_24.pos.y = bounds.pos.y;
    unk_24.size.x = bounds.size.x;
    unk_24.size.y = bounds.size.y;
    ClearName();
}

CFieldPartnerNpc::~CFieldPartnerNpc()
{
}

void CFieldPartnerNpc::Process(CFieldMap *map)
{
    unk_78 = 0;
    SetLayer(unk_E4->m_layer);
    UpdateScript();
    Update(map);
}

BOOL CFieldPartnerNpc::UpdateMove(CFieldMap *map)
{
    unk_78 = 1;
    ov0_02138628();
    SetLayer(unk_E4->m_layer);
    return CFieldActor::UpdateMove(map);
}

BOOL CFieldPartnerNpc::sub_0203DA38()
{
    if (m_name[0] == '\0' || MAIN_BSS_0210CA44 == NULL) {
        return FALSE;
    }
    MAIN_BSS_0210CA44->ov0_0213FB0C(m_name, m_id, -1);
    return TRUE;
}

void CFieldPartnerNpc::SetName(const char *name)
{
    if (name != NULL && name[0] != '\0') {
        strcpy(m_name, name);
    } else {
        ClearName();
    }
}

void CFieldPartnerNpc::ClearName()
{
    m_name[0] = '\0';
}
