#include <nitro.h>

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "UnkClass_020416AC.hpp"
#include "common.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectManage.hpp"
#include "primitive/CPrimitiveRECT.hpp"

UnkClass_020416AC::UnkClass_020416AC(int layerCount)
{
    unk_00 = NULL;
    unk_04 = NULL;
    unk_08 = NULL;
    unk_0C = 0;
    unk_10 = 0;
    unk_910 = layerCount;
    for (int i = 0; i < 0x73; i++) {
        unk_14[i].layer = -1;
    }
    unk_914 = 0;
    Load();
}

UnkClass_020416AC::~UnkClass_020416AC()
{
    Release();
}

void UnkClass_020416AC::Load()
{
    unk_00 = new UnkClass_020074D4("data/shadow.NCBR", 0, 0, 0);
    unk_0C = NNS_GfdAllocLnkTexVram(unk_00->unk_38, FALSE, 0);
    unk_00->sub_020076E8(NNS_GfdGetTexKeyAddr(unk_0C));
    unk_00->sub_020076B0();

    unk_04 = new UnkClass_02007AA4("data/shadow.NCLR", 0, 0);
    unk_10 = NNS_GfdAllocLnkPlttVram(unk_04->unk_04->szByte, FALSE, 0);
    unk_04->sub_02007BFC(NNS_GfdGetPlttKeyAddr(unk_10));
    unk_04->sub_02007BC4();

    unk_08 = new CPrimitiveRECT();
    unk_08->SetRectangle(0, 0, 0, 0, 0x3FF);
    unk_08->SetTexCoords(0, 0, FX32_CONST(64), FX32_CONST(32));
    unk_08->unk_38 = (UnkClass_CPrimitive_ImageProxy *)unk_00;
    unk_08->unk_3C = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_04;
    unk_08->m_polygonID = 2;
    unk_08->m_alpha = 8;
}

void UnkClass_020416AC::Release()
{
    SAFE_DELETE(unk_00);
    SAFE_DELETE(unk_04);
    SAFE_DELETE(unk_08);
    if (unk_0C != 0) {
        NNS_GfdFreeLnkTexVram(unk_0C);
        unk_0C = 0;
    }
    if (unk_10 != 0) {
        NNS_GfdFreeLnkPlttVram(unk_10);
        unk_10 = 0;
    }
}

extern "C" void sub_02041920(UnkClass_020416AC *obj)
{
}

extern "C" void sub_02041924(UnkClass_020416AC *obj, Camera2D *camera, int layer, int z)
{
    for (int i = 0; i < obj->unk_914; i++) {
        if (layer == obj->unk_14[i].layer) {
            ShadowEntry *entry = &obj->unk_14[i];
            obj->unk_08->SetRectangle(entry->rect.pos.x, entry->rect.pos.y, entry->rect.size.x, entry->rect.size.y, z);
            obj->unk_08->Render(camera);
        }
    }
}

extern "C" void sub_020419AC(UnkClass_020416AC *obj)
{
    for (int i = 0; i < 0x73; i++) {
        obj->unk_14[i].layer = -1;
    }
    obj->unk_914 = 0;
}

extern "C" void sub_020419D8(UnkClass_020416AC *obj, int layer, Rectangle rect)
{
    if (layer < 0) {
        return;
    }
    if (layer < obj->unk_910 && obj->unk_914 < 0x73) {
        obj->unk_14[obj->unk_914].layer = layer;
        Rectangle *dst = &obj->unk_14[obj->unk_914].rect;
        dst->pos.x = rect.pos.x;
        dst->pos.y = rect.pos.y;
        dst->size.x = rect.size.x;
        dst->size.y = rect.size.y;
        obj->unk_914++;
    }
}

extern "C" void sub_02041A60(UnkClass_020416AC *obj, u8 alpha)
{
    if (obj->unk_08 != NULL) {
        obj->unk_08->m_alpha = alpha;
    }
}

extern "C" int sub_02041A70(CFieldActor *actor, int type, int arg2)
{
    CFieldEffectManage *mgr;
    u16 id = 0;

    if (actor != NULL && (mgr = MAIN_BSS_0210CA60) != NULL) {
        id = actor->unk_D0;
        if (id != 0) {
            CFieldEffectManpu *effect = (CFieldEffectManpu *)mgr->ov0_02143088(id);
            if (effect != NULL) {
                if (effect->unk_24 == 0xD || effect->unk_24 == 9) {
                    return 0;
                }
                mgr->ov0_021430D8(id);
            }
        }

        int kind = -1;
        int arg0 = 0;
        switch (type) {
        case 0:
        case 1:
        case 2:
            kind = 0x24;
            break;
        case 3:
            kind = 0x25;
            break;
        case 4:
            kind = 0x26;
            arg0 = 8;
            break;
        case 5:
            kind = 0x27;
            arg0 = 8;
            break;
        case 6:
            kind = 0x28;
            break;
        case 7:
            kind = 0x29;
            break;
        case 8:
            kind = 0x2A;
            break;
        case 12:
            kind = 0x65;
            break;
        case 13:
            kind = 0x66;
            break;
        case 9:
            kind = 0x64;
            break;
        case 14:
            kind = 0x67;
            break;
        case 10:
            kind = 0x41;
            break;
        case 11:
            kind = 0x41;
            break;
        }

        if (kind >= 0) {
            id = mgr->ov0_02142F6C(1, kind);
            actor->unk_D0 = id;
            CFieldEffectManpu *effect = (CFieldEffectManpu *)mgr->ov0_02143088(id);
            if (effect != NULL) {
                effect->SetType(type);
                effect->unk_1C = actor;
                effect->ov0_021421F0(arg0, arg2, 0);
                effect->ov0_02142264(0);
            }
        }
    }
    return id;
}

void CFieldEffectManpu::SetType(int type)
{
    unk_24 = type;
}

extern "C" void sub_02041C1C(CFieldActor *actor)
{
    if (actor == NULL) {
        return;
    }
    u16 id = actor->unk_D0;
    CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
    if (id == 0 || mgr == NULL) {
        return;
    }
    CFieldEffectManpu *effect = (CFieldEffectManpu *)mgr->ov0_02143088(id);
    if (effect != NULL && effect->unk_1C == actor) {
        mgr->ov0_021430D8(id);
    }
    actor->unk_D0 = 0;
}
