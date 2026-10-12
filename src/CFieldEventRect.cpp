#include "field/CFieldEventRect.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_020B26A0.hpp"
#include "heap.hpp"

extern "C" {
void LogError(const char *fmt, ...);
}

extern UnkClass_020B26A0 MAIN_BSS_020B26A0;

static inline void SetArea(CFieldEventRect *er, int group, const Rectangle &rect, int enabled)
{
    er->m_group = group;
    er->m_rect = rect;
    er->unk_18 = enabled;
}

CFieldEventRect::CFieldEventRect()
{
    m_group = 0;
    Rectangle rect = { 0, 0, 0, 0 };
    m_rect.pos = rect.pos;
    m_rect.size = rect.size;
    unk_18 = TRUE;
    m_prim.m_color = GX_RGB(31, 31, 0);
    m_prim.m_alpha = 16;
    m_prim.m_z = 0x200000;
    m_prim.m_polygonID = 1;
    m_state = 0;
    m_file = NULL;
    m_script = NULL;
    m_stack = NULL;
    m_scriptState = 2;
    Init();
}

CFieldEventRect::~CFieldEventRect()
{
    Release();
}

BOOL CFieldEventRect::Update(Point2D *pos, int group)
{
    if (pos != NULL) {
        if (sub_02006000(*pos, m_rect, 2) && group == m_group) {
            switch (m_state) {
            case 0:
                m_state = 1;
                break;
            case 1:
                m_state = 2;
                break;
            case 2:
                break;
            case 3:
                m_state = 1;
                break;
            }
        } else {
            switch (m_state) {
            case 0:
                break;
            case 1:
            case 2:
                m_state = 3;
                break;
            case 3:
                m_state = 0;
                break;
            }
        }
    }
    switch (m_state) {
    case 0:
        break;
    case 1:
        CallScript("EventEnter", m_script);
        break;
    case 2:
        break;
    case 3:
        CallScript("EventLeave", m_script);
        break;
    }
    RunScript();
    return IsInside(pos, group);
}

BOOL CFieldEventRect::IsInside(Point2D *pos, int group)
{
    if (pos != NULL && sub_02006000(*pos, m_rect, 2) && group == m_group) {
        return TRUE;
    }
    return FALSE;
}

void CFieldEventRect::Init()
{
    m_group = 0;
    Rectangle rect = { 0, 0, 0, 0 };
    m_rect.pos = rect.pos;
    m_rect.size = rect.size;
    unk_18 = TRUE;
    m_index = 0;
    SAFE_DELETE(m_file);
    m_script = NULL;
    if (m_stack != NULL) {
        Heap_Free(m_stack);
        m_stack = NULL;
    }
    m_scriptState = 2;
    m_stack = (u32 *)Heap_AllocWithAlignment(0x100, 4);
}

void CFieldEventRect::LoadScript(int id)
{
    char path[0x80];
    u32 heapId = s_game->unk_14A8;
    OS_SPrintf(path, "data/Script/field/eventrect/er%03d/EventRect%06d.fsb", id / 1000, id);
    m_file = new CBinaryFile(path, 0, 0, heapId, NULL, 0);
    m_script = m_file->unk_4C;
    sub_02044AC8(m_script);
}

void CFieldEventRect::Release()
{
    m_group = 0;
    Rectangle rect = { 0, 0, 0, 0 };
    m_rect.pos = rect.pos;
    m_rect.size = rect.size;
    unk_18 = FALSE;
    SAFE_DELETE(m_file);
    m_script = NULL;
    if (m_stack != NULL) {
        Heap_Free(m_stack);
        m_stack = NULL;
    }
    m_scriptState = 2;
}

void CFieldEventRect::Draw(Camera2D *camera)
{
    if (unk_18 != 0) {
        m_prim.m_color = GX_RGB(31, 31, 0);
        m_prim.m_alpha = 16;
    } else {
        m_prim.m_color = GX_RGB(0, 0, 31);
        m_prim.m_alpha = 8;
    }
    m_prim.SetRectangle(m_rect.pos.x, m_rect.pos.y, m_rect.size.x, m_rect.size.y, 0x200000);
    m_prim.Render(camera);
}

BOOL CFieldEventRect::CallScript(const char *func, void *script)
{
    if (script != NULL) {
        sub_02044B48(&m_vm, m_stack, 0x40);
        m_vm.unk_04 -= 2;
        u32 *args = m_vm.unk_04;
        args[0] = MAIN_BSS_020B26A0.unk_001A;
        args[1] = m_index;
        if (sub_02045A18(&m_vm, script, func) == -1) {
            LogError("not found func FieldEventRect.cpp");
            return FALSE;
        }
        m_scriptState = 8;
    } else {
        LogError("ScriptBlock ==  NULL by FieldEventRect.cpp");
        return FALSE;
    }
    return TRUE;
}

void CFieldEventRect::RunScript()
{
    m_scriptState = sub_02044C9C(&m_vm, 0xFFFFF);
}
