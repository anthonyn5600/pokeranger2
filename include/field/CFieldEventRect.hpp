#ifndef POKERANGER2_FIELD_CFIELDEVENTRECT_HPP
#define POKERANGER2_FIELD_CFIELDEVENTRECT_HPP

#include <nitro.h>

#include "UnkStruct_02044464.hpp"
#include "common.hpp"
#include "file/CBinaryFile.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "sub_02006000.hpp"

// FieldEventRect.cpp (ov0): a map area that runs a script (EventEnter/EventLeave) when entered or left.
class CFieldEventRect {
public:
    CFieldEventRect();
    ~CFieldEventRect();

    virtual void SetIndex(int index)
    {
        m_index = index;
    }

    BOOL Update(Point2D *pos, int group);
    BOOL IsInside(Point2D *pos, int group);
    void Init();
    void LoadScript(int id);
    void Release();
    void Draw(Camera2D *camera);
    BOOL CallScript(const char *func, void *script);
    void RunScript();

public:
    int m_group;
    Rectangle m_rect;
    int unk_18;
    CPrimitiveRECT m_prim;
    int m_state;
    CBinaryFile *m_file;
    int m_scriptState;
    UnkStruct_02044464 m_vm;
    void *m_script;
    u32 *m_stack;
    int m_index;
};

STATIC_SIZE_ASSERT(CFieldEventRect, 0x98);

#endif // POKERANGER2_FIELD_CFIELDEVENTRECT_HPP
