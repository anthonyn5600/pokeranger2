#ifndef POKERANGER2_CACTORDATA_HPP
#define POKERANGER2_CACTORDATA_HPP

#include <nitro.h>
#include <nnsys.h>

#include "CellAnimController.hpp"
#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"

struct CActorAnim {
    u8 flags;
    u8 id;
    VramImage *image;
    CNCERFile *cells;
    CellAnimController *bank;
};

class CActorData {
public:
    CActorData();
    CActorData(int type, int id, int form, u16 mask, BOOL releaseArchive, const char *arcName);
    CActorData(const char *path, const char *name, int mask, BOOL releaseArchive, const char *arcName);
    virtual ~CActorData();
    virtual void Release();
    virtual CActorAnim *GetAnim(u8 id);
    virtual CActorAnim *FindAnim(int action, u32 sub);
    virtual u8 GetAnimId(int action, u32 sub);
    virtual CActorAnim *GetAnimAt(int index);

    void Init();
    void Load(int type, int id, int form, u16 mask, BOOL releaseArchive, const char *arcName, u32 heapId);
    void LoadFromPath(const char *path, const char *name, int mask, BOOL releaseArchive, const char *arcName);
    BOOL LoadAnim(CActorAnim *anim, const char *base, u32 heapId);
    BOOL LoadAnimWithImage(CActorAnim *anim, const char *imageBase, const char *base, VramImage *image, u32 heapId);
    BOOL sub_02014CEC(CActorAnim *anim, const char *base, u32 heapId, BOOL arg3);
    BOOL sub_02014EA4(CActorAnim *anim, const char *imageBase, const char *base, VramImage *image, u32 heapId, BOOL arg5);
    void LoadArchived(int type, int id, int form, u16 mask, const char *arcName, u32 heapId, u32 archiveArg, BOOL fromArchive);
    void LoadImagesToVram(u32 addr);
    void AllocAndLoadImages(NNSGfdTexKey *keys);
    void LoadPaletteToVram(u32 addr);
    void ReleaseImages();
    void ReleasePalette();
    u32 GetImagesSize();
    u32 GetPaletteSize();
    int FindAnimIndex(u8 id);

public:
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    CArchiveGuard *m_archive;
    VramPalette *m_palette;
    CActorAnim *m_anims;
    u8 m_animCount;
};

STATIC_SIZE_ASSERT(CActorAnim, 0x10);
STATIC_SIZE_ASSERT(CActorData, 0x18);

#endif // POKERANGER2_CACTORDATA_HPP
