#ifndef POKERANGER2_UNKCLASS_02018B9C_HPP
#define POKERANGER2_UNKCLASS_02018B9C_HPP

#include <nitro.h>
#include <nnsys.h>

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"

// A textured rectangle showing data/shadow.NCBR (used by overlay 1)
class UnkClass_02018B9C {
public:
    UnkClass_02018B9C();
    ~UnkClass_02018B9C();

    void Load();
    void Release();
    void SetRectangle(Rectangle *rect, fx32 z);
    void SetPolygonID(int id);
    void SetAlpha(int alpha);
    void Render(Camera2D *camera);

public:
    UnkClass_020074D4 *unk_00;
    UnkClass_02007AA4 *unk_04;
    CPrimitiveRECT *unk_08;
    NNSGfdTexKey unk_0C;
    NNSGfdPlttKey unk_10;
};

STATIC_SIZE_ASSERT(UnkClass_02018B9C, 0x14);

#endif // POKERANGER2_UNKCLASS_02018B9C_HPP
