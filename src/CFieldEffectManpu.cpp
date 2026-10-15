#include "field/CFieldEffectManpu.hpp"

#include <nitro.h>

#include "Camera2D.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldEffectManpuPos.hpp"
#include "field/ManpuBlockHeap.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;
ManpuBlockHeap *OVERLAY0_BSS_0217B0E0;

// A call in the dtor body (even an inlined one) makes mwcc store the class's own vptr first, like the original.
inline void CFieldEffectManpu::Detach()
{
    if (unk_1C != NULL) {
        unk_1C->unk_D0 = 0;
    }
}

CFieldEffectManpu::~CFieldEffectManpu()
{
    Detach();
}

int CFieldEffectManpu::Render(Camera2D *camera)
{
    CFieldActor *actor = unk_1C;
    if (actor != NULL && actor->IsActive() && !actor->IsHidden()) {
        if (unk_28 == 0) {
            SetDepth(0x10);
        } else {
            SetDepth(actor->m_drawObject != NULL ? actor->m_drawObject->unk_10 : -0x4000);
        }
        return Draw(camera);
    }
    return 0;
}

void *CFieldEffectManpu::operator new(size_t size)
{
    return OVERLAY0_BSS_0217B0E0->Alloc(size);
}

void CFieldEffectManpu::operator delete(void *ptr)
{
    OVERLAY0_BSS_0217B0E0->Free(ptr);
}

void CFieldEffectManpuSimple::Init(int type)
{
    if (unk_18 != NULL && unk_18->GetNcbr(type) != NULL && unk_18->GetPalette() != NULL && unk_18->GetNcer(type) != NULL) {
        m_sprite.SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(type), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(type));
        m_sprite.m_cellDataIdx = 0;
        m_sprite.m_polygonID = 8;
        unk_20 = 1;
    }
    unk_78 = type;
}

void CFieldEffectManpuSimple::SetDepth(fx32 z)
{
    m_sprite.m_z = z;
}

int CFieldEffectManpuSimple::Draw(Camera2D *camera)
{
    CFieldActor *actor = unk_1C;
    m_sprite.SetPos(GetBalloonPos(actor));
    ((CSoftwareSprite *)&m_sprite)->Render(camera);
    return 0;
}

BOOL CFieldEffectManpu::IsVisible()
{
    if (unk_1C == NULL || unk_20 == 0) {
        return FALSE;
    }
    BOOL visible = FALSE;
    CFieldScene *scene = MAIN_BSS_0210CA40;
    Camera2D *camera;
    if (scene != NULL && (camera = scene->m_camera) != NULL) {
        Rectangle rect;
        rect.pos.x = unk_1C->GetX();
        rect.pos.y = unk_1C->GetY() + GetOffset(unk_1C).y;
        rect.size.x = rect.size.y = 0x40000;
        visible = camera->IsRectVisible(&rect, 0x1199);
    }
    return visible;
}

int CFieldEffectManpu::GetEffectId()
{
    return 1;
}
