#include "field/CFieldTargetObject.hpp"

#include <nitro.h>
#include <string.h>

#include "UnkClass_0213F918.hpp"
#include "field/CFieldMap.hpp"

extern "C" {
void LogError(const char *fmt, ...);
void sub_0203BF20(CFieldActorScript *script);
void sub_0203C2B8(CFieldActor *actor);
}

static inline BOOL HasScriptBlock(CFieldActorScript *script)
{
    return script->unk_2C != NULL;
}

// Collision shape: unk_50 = 0 uses this rectangle, 1 the circle at unk_44.
static inline void SetRect(CFieldActor *actor, Rectangle r)
{
    actor->unk_34.pos.x = r.pos.x;
    actor->unk_34.pos.y = r.pos.y;
    actor->unk_34.size.x = r.size.x;
    actor->unk_34.size.y = r.size.y;
}

BOOL CFieldTargetObjectActorScript::sub_0203BE48(CFieldActor *actor, const char *func)
{
    if (unk_2C != NULL && actor != NULL) {
        sub_02044B48(&unk_08, unk_30, unk_34);
        if (unk_38 == -1) {
            *--unk_08.unk_04 = actor->unk_58;
        } else {
            u32 *sp = unk_08.unk_04 -= 2;
            sp[0] = actor->unk_58;
            sp[1] = unk_38;
        }
        if (func != NULL) {
            if (sub_02045A18(&unk_08, unk_2C, func) == -1) {
                LogError("not found func FieldTargetObject.cpp");
                return FALSE;
            }
        } else {
            LogError("null func name FieldTargetObject.cpp");
            return FALSE;
        }
        unk_04 = 8;
    } else {
        LogError("m_pScriptBlock ==  NULL by FieldTargetObject.cpp");
        return FALSE;
    }
    return TRUE;
}

CFieldTargetObject::CFieldTargetObject()
{
    unk_EC = 0;
    unk_10 = 0x2000;
    Rectangle bounds = { { 0, -0x8000 }, { 0x10000, 0x20000 } };
    unk_24.pos.x = bounds.pos.x;
    unk_24.pos.y = bounds.pos.y;
    unk_24.size.x = bounds.size.x;
    unk_24.size.y = bounds.size.y;
    unk_50 = 0;
    // The compound literal passed by value leaves two copies of its data in .rodata (the original has both).
    SetRect(this, (Rectangle) { { 0, 0 }, { 0x40000, 0x40000 } });
    unk_D4 = 0;
    unk_D6 = 0x100;
    // Chained: the extra copy changes the schedule (vtable in r0, shape.x in r0) like the original.
    unk_F0 = unk_F4 = 0;
    unk_F8 = NULL;
    unk_FC = FALSE;
    unk_100[0] = 0;
    unk_110 = 0;
}

CFieldTargetObject::~CFieldTargetObject()
{
    SAFE_DELETE(unk_F8);
}

BOOL CFieldTargetObject::sub_0203DA38()
{
    if (MAIN_BSS_0210CA44 != NULL && unk_F8 != NULL && HasScriptBlock(unk_F8)) {
        ov0_0213FC24(MAIN_BSS_0210CA44, this, "main", -1);
        return TRUE;
    }
    return FALSE;
}

BOOL CFieldTargetObject::ov0_0213CD3C()
{
    GetScript()->unk_38 = -1;
    unk_DC->sub_0203BE48(this, "Normal");
    unk_110 = 1;
    return TRUE;
}

BOOL CFieldTargetObject::ov0_0213CD78(int arg)
{
    GetScript()->unk_38 = arg;
    unk_DC->sub_0203BE48(this, "TargetClear");
    unk_110 = 2;
    return TRUE;
}

BOOL CFieldTargetObject::ov0_0213CDB4(int arg)
{
    BOOL result = FALSE;
    CFieldTargetObjectActorScript *script = GetScript();
    if (script != NULL) {
        script->unk_38 = arg;
        result = script->sub_0203BE48(this, "TargetInit");
    }
    unk_110 = 3;
    return result;
}

void CFieldTargetObject::sub_0202DC54(int arg0, int arg1)
{
    switch (arg0) {
    case 0x10:
        unk_20 = 2;
        sub_02012114_(4, 0);
        sub_020128EC_(0x4000);
        break;
    case 0x20:
        unk_20 = 2;
        sub_02012114_(4, 0);
        sub_020128EC_(0xC000);
        break;
    case 8:
        unk_20 = 3;
        sub_02012114_(arg0, arg1);
        sub_020128EC_(0x4000);
        break;
    default:
        unk_20 = 2;
        sub_02012114_(arg0, arg1);
        sub_020128EC_(0x4000);
        break;
    }
}

BOOL CFieldTargetObject::ov0_0213CF30(CFieldActorScript *script, void *block)
{
    if (unk_F8 == NULL && script != NULL) {
        unk_F8 = script;
        script->unk_2C = block;
    } else {
        unk_F8->unk_2C = block;
        return FALSE;
    }
    return TRUE;
}

BOOL CFieldTargetObject::ov0_0213CF60(const char *func)
{
    if (unk_F8 != NULL && func != NULL) {
        if (unk_F8->sub_0203BE48(this, func)) {
            strcpy(unk_100, func);
            return TRUE;
        }
        unk_100[0] = 0;
    }
    return FALSE;
}

void CFieldTargetObject::ov0_0213CFBC()
{
    if (unk_FC && unk_F8 != NULL) {
        sub_0203BF20(unk_F8);
    }
}

BOOL CFieldTargetObject::ov0_0213CFDC()
{
    if (unk_F8 != NULL && HasScriptBlock(unk_F8)) {
        return TRUE;
    }
    return FALSE;
}

void CFieldTargetObject::sub_0203DA40(CFieldMap *map)
{
    sub_0203C2B8(this);
    sub_0203C87C(this, (int)map);
}

BOOL CFieldTargetObject::sub_0203D578(CFieldMap *map)
{
    switch (unk_E8) {
    case 0x70:
    case 0xDF:
    case 0xF3:
    case 0x122:
    case 0x123:
    case 0x142:
        switch (unk_110) {
        case 0:
        case 1:
        default:
            return CFieldActor::sub_0203D578(map);
        case 2:
        case 3:
            sub_0203C2B8(this);
            sub_0203C87C(this, (int)map);
            return FALSE;
        }
    }
    sub_0203C2B8(this);
    sub_0203C87C(this, (int)map);
    return FALSE;
}

void CFieldTargetObject::sub_0202D7E0()
{
    if (unk_08 != NULL && unk_08->unk_0C != NULL) {
        unk_08->unk_0C->m_motion.m_mode = 0;
    }
}
