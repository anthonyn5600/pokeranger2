#include <nitro.h>

#include "Camera2D.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldEffectManpu.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;
extern void *OVERLAY0_BSS_0217B0E0;

extern "C" {
void *ov0_0216D2E4(void *heap, size_t size);
void ov0_0216D3D0(void *heap, void *ptr);
}

// fake: an unreferenced global (own section, stripped by mwld) that only takes part in mwcc's size sort of the
// TU's data; it orders the typeinfos ManpuSimple, Manpu, Actor like the original.
u32 sFieldEffectManpuUnused;

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

int CFieldEffectManpu::ov0_02142344(Camera2D *camera)
{
    CFieldActor *actor = unk_1C;
    if (actor != NULL && actor->IsActive() && !actor->IsUnk04Bit0()) {
        if (unk_28 == 0) {
            SetDepth(0x10);
        } else {
            SetDepth(actor->unk_08 != NULL ? actor->unk_08->unk_10 : -0x4000);
        }
        return Draw(camera);
    }
    return 0;
}

void *CFieldEffectManpu::operator new(size_t size)
{
    return ov0_0216D2E4(OVERLAY0_BSS_0217B0E0, size);
}

void CFieldEffectManpu::operator delete(void *ptr)
{
    ov0_0216D3D0(OVERLAY0_BSS_0217B0E0, ptr);
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

static inline Point2D GetOffset(CFieldActor *actor)
{
    return *(Point2D *)&actor->unk_70;
}

static inline Point2D GetBalloonPos(CFieldActor *actor)
{
    Point2D pos = *(Point2D *)&actor->unk_70 + actor->GetPos();
    pos.y -= actor->GetHeight();
    return pos;
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
    if (scene != NULL && (camera = scene->unk_0008) != NULL) {
        Rectangle rect;
        rect.pos.x = unk_1C->GetX();
        rect.pos.y = unk_1C->GetY() + GetOffset(unk_1C).y;
        rect.size.x = rect.size.y = 0x40000;
        visible = camera->sub_020038A8(&rect, 0x1199);
    }
    return visible;
}

int CFieldEffectManpu::sub_02033028()
{
    return 1;
}
