#ifndef POKERANGER2_FIELDEVENTRECTMANAGE_HPP
#define POKERANGER2_FIELDEVENTRECTMANAGE_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEventRect.hpp"

class FieldEventRectManage;

extern FieldEventRectManage *MAIN_BSS_0210CA58;

// Defined in ov0
class FieldEventRectManage {
public:
    FieldEventRectManage();
    ~FieldEventRectManage();

    void Create(int count);
    void Clear();
    BOOL Update(Point2D *pos, int group, BOOL run);
    void Draw(Camera2D *camera);

    inline CFieldEventRect *Get(int i)
    {
        if (m_count < i) {
            return NULL;
        }
        return m_items[i];
    }

    inline int Add(CFieldEventRect *rect)
    {
        for (int i = 0; i < m_count; i++) {
            if (m_items[i] == NULL) {
                m_items[i] = rect;
                rect->SetIndex(i);
                return i;
            }
        }
        return -1;
    }

public:
    int m_count;
    CFieldEventRect **m_items;
    BOOL m_draw;
};

STATIC_SIZE_ASSERT(FieldEventRectManage, 0xC);

#endif // POKERANGER2_FIELDEVENTRECTMANAGE_HPP
