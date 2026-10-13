#include "field/CFieldPartnerNpc.hpp"

#include <nitro.h>
#include <string.h>

#include "UnkClass_0213F918.hpp"

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

void CFieldPartnerNpc::sub_0203DA40(CFieldMap *map)
{
    unk_78 = 0;
    sub_0202E68C(unk_E4->unk_14);
    sub_0203C2B8();
    sub_0203C87C(map);
}

BOOL CFieldPartnerNpc::sub_0203D578(CFieldMap *map)
{
    unk_78 = 1;
    ov0_02138628();
    sub_0202E68C(unk_E4->unk_14);
    return CFieldActor::sub_0203D578(map);
}

BOOL CFieldPartnerNpc::sub_0203DA38()
{
    if (m_name[0] == '\0' || MAIN_BSS_0210CA44 == NULL) {
        return FALSE;
    }
    MAIN_BSS_0210CA44->ov0_0213FB0C(m_name, unk_58, -1);
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
