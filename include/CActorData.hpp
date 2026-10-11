#ifndef POKERANGER2_CACTORDATA_HPP
#define POKERANGER2_CACTORDATA_HPP

#include <nitro.h>
#include <nnsys.h>

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "UnkClass_02008788.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"

struct CActorAnim {
    u8 flags;
    u8 id;
    UnkClass_020074D4 *image;
    CNCERFile *cells;
    UnkClass_02008788 *bank;
};

class CActorData {
public:
    CActorData();
    CActorData(int type, int id, int form, u16 mask, BOOL releaseArchive, const char *arcName);
    CActorData(const char *path, const char *name, int mask, BOOL releaseArchive, const char *arcName);
    virtual ~CActorData();
    virtual void Release();
    virtual CActorAnim *GetAnim(u8 id);
    virtual CActorAnim *sub_020143B8(int action, u32 sub);
    virtual u8 GetAnimId(int action, u32 sub);
    virtual CActorAnim *GetAnimAt(int index);

    void Init();
    void sub_02013154(int type, int id, int form, u16 mask, BOOL releaseArchive, const char *arcName, u32 heapId);
    void sub_020138E4(const char *path, const char *name, int mask, BOOL releaseArchive, const char *arcName);
    BOOL sub_02013CD4(CActorAnim *anim, const char *base, u32 heapId);
    BOOL sub_02013E78(CActorAnim *anim, const char *imageBase, const char *base, UnkClass_020074D4 *image, u32 heapId);
    BOOL sub_02014CEC(CActorAnim *anim, const char *base, u32 heapId, BOOL arg3);
    BOOL sub_02014EA4(CActorAnim *anim, const char *imageBase, const char *base, UnkClass_020074D4 *image, u32 heapId, BOOL arg5);
    void sub_02014514(int type, int id, int form, u16 mask, const char *arcName, u32 heapId, u32 archiveArg, BOOL fromArchive);
    void sub_020141AC(u32 addr);
    void sub_02014218(NNSGfdTexKey *keys);
    void sub_0201429C(u32 addr);
    void sub_020142B4();
    void sub_020142F8();
    u32 sub_02014310();
    u32 sub_02014364();
    int sub_02015070(u8 id);

public:
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    CArchiveGuard *m_archive;
    UnkClass_02007AA4 *m_palette;
    CActorAnim *m_anims;
    u8 m_animCount;
};

STATIC_SIZE_ASSERT(CActorAnim, 0x10);
STATIC_SIZE_ASSERT(CActorData, 0x18);

#endif // POKERANGER2_CACTORDATA_HPP
