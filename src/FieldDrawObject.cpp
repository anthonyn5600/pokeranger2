#include <nitro.h>

#include "Camera2D.hpp"
#include "DrawObjectList.hpp"
#include "common.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldDrawActor.hpp"

CFieldDrawObject::CFieldDrawObject()
{
    m_actor = NULL;
    unk_10 = 0;
    unk_14 = 0;
}

CFieldDrawObject::~CFieldDrawObject()
{
    DeleteActor();
}

BOOL CFieldDrawObject::CreateActor(int arg0, u16 arg1, int arg2, u32 mask, int arg4)
{
    SAFE_DELETE(m_actor);
    m_actor = new CFieldDrawActor();
    m_actor->Load(arg0, arg1, arg2, mask, arg4);
    return TRUE;
}

BOOL CFieldDrawObject::CreateActorOwnData(int arg0, u16 arg1, int arg2, u32 mask, int arg4)
{
    SAFE_DELETE(m_actor);
    m_actor = new CFieldDrawActor();
    m_actor->LoadOwnData(arg0, arg1, arg2, mask, arg4);
    return TRUE;
}

void CFieldDrawObject::DeleteActor()
{
    SAFE_DELETE(m_actor);
}

int CFieldDrawObject::Draw(Camera2D *camera, int budget)
{
    unk_10 = budget;
    int used = 0;
    used += 4;
    if (m_actor != NULL) {
        Rectangle rect = m_actor->unk_1E4;
        rect.pos.x += GetX();
        rect.pos.y += GetY() - GetHeight();
        if (camera->IsRectVisible(&rect, 0x1199)) {
            used += m_actor->Render(camera, budget - used);
        }
    }
    unk_14 = budget - used;
    return used + 4;
}

void CFieldDrawObject::sub_02040740()
{
    if (m_actor != NULL) {
        m_actor->vfunc_08();
    }
    unk_04 = GetY();
}
