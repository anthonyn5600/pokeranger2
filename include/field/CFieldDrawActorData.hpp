#ifndef POKERANGER2_FIELD_CFIELDDRAWACTORDATA_HPP
#define POKERANGER2_FIELD_CFIELDDRAWACTORDATA_HPP

#include <nitro.h>
#include <nnsys.h>

#include "CActorData.hpp"
#include "common.hpp"

// Graphics data of a CFieldDrawActor (CFieldDrawActor::unk_184).
class CFieldDrawActorData : public CActorData {
public:
    CFieldDrawActorData();
    virtual ~CFieldDrawActorData()
    {
    }

    virtual void Release();
    virtual void AllocVram();
    virtual void ReleaseVram();

    void LoadData(int type, u16 id, int form, u16 mask, BOOL useTransfer, const char *arcName, BOOL alloc);
    void sub_020409B4(u16 id, int form, u16 mask, u32 heapId, const char *arcName);
    void sub_02040DB8();
    void LoadToVram();
    void LoadPaletteDeferred();

public:
    int unk_18;
    u16 unk_1C;
    u16 unk_1E;
    u16 unk_20;
    int unk_24;
    int unk_28;
    NNSGfdTexKey unk_2C;
    NNSGfdPlttKey unk_30;
};

STATIC_SIZE_ASSERT(CFieldDrawActorData, 0x34);

// The player's graphics (RTTI name CActorDataPlayer): all anims from data/player/player%1d_LZ.bin into an inline
// archive buffer.
class CActorDataPlayer : public CFieldDrawActorData {
public:
    CActorDataPlayer();
    virtual ~CActorDataPlayer();
    virtual void Release();
    virtual CActorAnim *GetAnim(u8 id);
    virtual CActorAnim *FindAnim(int action, u32 sub);
    virtual u8 GetAnimId(int action, u32 sub);

    void LoadPlayer(u16 id, int form, u32 mask, const char *arcName, BOOL useTransfer, BOOL alloc);

public:
    u8 unk_34[0x50800];
    u16 unk_50834;
};

STATIC_SIZE_ASSERT(CActorDataPlayer, 0x50838);

class CActorDataPartner : public CFieldDrawActorData {
public:
    CActorDataPartner();
    virtual ~CActorDataPartner();
    virtual void Release();
    virtual void AllocVram();
    virtual void ReleaseVram();

    void sub_02041230(int type, u16 id, int form, u16 mask);

public:
    u32 unk_34;
};

STATIC_SIZE_ASSERT(CActorDataPartner, 0x38);

#endif // POKERANGER2_FIELD_CFIELDDRAWACTORDATA_HPP
