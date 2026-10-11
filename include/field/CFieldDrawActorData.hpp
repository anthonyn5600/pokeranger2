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
    virtual void Release();
    virtual void sub_02040E2C();
    virtual void sub_02040E80();

    void sub_02040830(int type, u16 id, int form, u16 mask, BOOL useTransfer, BOOL arg5, BOOL arg6);
    void sub_02040EBC();
    void sub_02040EF8();

public:
    u8 unk_18[0x10];
    int unk_28;
    NNSGfdTexKey unk_2C;
    NNSGfdPlttKey unk_30;
};

STATIC_SIZE_ASSERT(CFieldDrawActorData, 0x34);

#endif // POKERANGER2_FIELD_CFIELDDRAWACTORDATA_HPP
