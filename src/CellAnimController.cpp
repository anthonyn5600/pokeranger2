#include "CellAnimController.hpp"

#include <nitro.h>

#include "file/CBinaryFile.hpp"
#include "heap.hpp"

CellAnimController::CellAnimController()
{
    Init();
}

CellAnimController::CellAnimController(const char *path)
{
    Init();
    Load(path, 0, 0);
}

CellAnimController::~CellAnimController()
{
    if (unk_08 != 0) {
        RemoveAll();
    }
    if (unk_04 != NULL) {
        Heap_Free(unk_04);
        unk_04 = NULL;
    }
    SAFE_DELETE(unk_0C);
}

u16 CellAnimController::GetCell(u16 id)
{
    CellAnimInstance *anim = Find(id);
    if (anim != NULL) {
        return anim->GetCell();
    }
    return 0;
}

fx32 *CellAnimController::GetOffsets(u16 id)
{
    CellAnimInstance *anim = Find(id);
    if (anim != NULL) {
        return anim->GetOffsets();
    }
    return NULL;
}

int CellAnimController::GetStatus(u16 id)
{
    CellAnimInstance *anim = Find(id);
    if (anim != NULL) {
        return anim->GetStatus();
    }
    return 2;
}

BOOL CellAnimController::Load(const char *path, u32 heapId, u32 arg2)
{
    if (unk_04 != NULL) {
        return TRUE;
    }
    CBinaryFile *file = new CBinaryFile(path, arg2 == 0 ? 1 : 0, 0, heapId, NULL, 0);
    AnimFileHeader *data = (AnimFileHeader *)file->unk_4C;
    unk_00 = data->size >> 2;
    unk_02 = data->count;
    unk_03 = data->loop;
    unk_04 = (AnimCmd *)Heap_AllocWithAlignment(unk_00 * 4 * data->count, arg2 == 0 ? 4 : -4);
    MI_CpuCopy32(data->cmds, unk_04, unk_00 * 4 * data->count);
    if (file != NULL) {
        delete file;
    }
    return FALSE;
}

BOOL CellAnimController::SetDirection(u16 id, u16 dir)
{
    CellAnimInstance *anim = Find(id);
    if (anim != NULL) {
        anim->SetDirection(dir);
        return FALSE;
    }
    return TRUE;
}

BOOL CellAnimController::SetAnim(u16 id, u16 index)
{
    CellAnimInstance *anim = Find(id);
    if (anim != NULL) {
        anim->SetAnim(index);
        return FALSE;
    }
    return TRUE;
}

void CellAnimController::Restart(u16 id)
{
    CellAnimInstance *anim = Find(id);
    if (anim != NULL) {
        anim->Restart();
    }
}

u8 CellAnimController::GetAnimCount(u16 id)
{
    CellAnimInstance *anim = Find(id);
    if (anim != NULL) {
        return anim->GetAnimCount();
    }
    return 0;
}

void CellAnimController::UpdateAll()
{
    CellAnimInstance *anim = unk_0C->GetNext();
    while (anim != unk_0C && GetCount() != 0) {
        anim->Update();
        anim = anim->GetNext();
    }
}

BOOL CellAnimController::Update(u16 id)
{
    CellAnimInstance *anim = Find(id);
    if (anim != NULL) {
        anim->Update();
        return FALSE;
    }
    return TRUE;
}

BOOL CellAnimController::SetSpeed(u16 id, fx32 speed)
{
    CellAnimInstance *anim = Find(id);
    if (anim != NULL) {
        anim->SetSpeed(speed);
        return FALSE;
    }
    return TRUE;
}

u16 CellAnimController::Create(u32 arg0, u32 arg1)
{
    if (unk_04 == NULL) {
        return 0;
    }
    unk_0A++;
    unk_08++;
    CellAnimInstance *anim = new CellAnimInstance(arg0, arg1);
    anim->SetScript(unk_04, unk_00, unk_02, unk_03);
    anim->SetId(unk_0A);
    CellAnimInstance *last = unk_0C->GetPrev();
    if (last == unk_0C) {
        unk_0C->SetPrev(anim);
        unk_0C->SetNext(anim);
        anim->SetPrev(unk_0C);
        anim->SetNext(unk_0C);
    } else {
        last->SetNext(anim);
        anim->SetPrev(last);
        anim->SetNext(unk_0C);
        unk_0C->SetPrev(anim);
    }
    return unk_0A;
}

BOOL CellAnimController::Remove(u16 id)
{
    CellAnimInstance *anim = Find(id);
    if (anim == NULL) {
        return TRUE;
    }
    CellAnimInstance *prev = anim->GetPrev();
    CellAnimInstance *next = anim->GetNext();
    prev->SetNext(next);
    next->SetPrev(prev);
    delete anim;
    unk_08--;
    return FALSE;
}

BOOL CellAnimController::RemoveAll()
{
    CellAnimInstance *anim = unk_0C->GetNext();
    while (anim != unk_0C) {
        CellAnimInstance *next = anim->GetNext();
        delete anim;
        anim = next;
    }
    unk_08 = 0;
    unk_0C->SetPrev(unk_0C);
    unk_0C->SetNext(unk_0C);
    return FALSE;
}

u8 CellAnimController::GetCount()
{
    return unk_08;
}

void CellAnimController::Init()
{
    unk_00 = 0;
    unk_02 = 0;
    unk_03 = 0;
    unk_04 = NULL;
    unk_08 = 0;
    unk_0A = 0;
    unk_0C = new CellAnimInstance(0, 0);
    unk_0C->SetPrev(unk_0C);
    unk_0C->SetNext(unk_0C);
}

CellAnimInstance *CellAnimController::Find(u16 id)
{
    CellAnimInstance *anim = unk_0C->GetNext();
    while (TRUE) {
        if (anim == unk_0C) {
            return NULL;
        }
        if (id == anim->GetId()) {
            break;
        }
        anim = anim->GetNext();
    }
    return anim;
}

u16 CellAnimController::GetScriptPos(u16 id)
{
    CellAnimInstance *anim = Find(id);
    if (anim == NULL) {
        return 0;
    } else {
        return anim->unk_0E;
    }
}

u8 CellAnimController::GetLoopCount(u16 id)
{
    CellAnimInstance *anim = Find(id);
    if (anim == NULL) {
        return 0;
    } else {
        return anim->unk_10;
    }
}
