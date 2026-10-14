#ifndef POKERANGER2_FIELD_CFIELDPARTNER_HPP
#define POKERANGER2_FIELD_CFIELDPARTNER_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldPokeMove.hpp"
#include "field/FieldTrail.hpp"

class CFieldPartnerManage;
class CFieldPlayer;

// FieldPartner.cpp (ov0): base of the partner actors (the derived classes start at +0x268).
class CFieldPartner : public CFieldActor {
public:
    CFieldPartner();
    virtual ~CFieldPartner();
    virtual void sub_0202D7E0();
    virtual void sub_02032A44(int sequence);
    virtual void SetUnk1EC(int value);

    void ov0_02136CFC(BOOL keep, Point2D pos, int arg);
    void ov0_02138628();
    BOOL ov0_02136D50(Point2D *out, int rank, BOOL clear);
    BOOL ov0_021373C0(Point2D *out);
    BOOL ov0_02137790(Point2D *out, CFieldPartner *prev);
    BOOL ov0_02137AFC(Point2D *out, CFieldPartner *prev);
    void ov0_02138714(int arg);
    BOOL ov0_0213803C(int arg);
    void ov0_0213889C();
    void ov0_02138B44();
    void ov0_02138A7C();
    void ov0_0213905C();
    void ov0_02139134();
    void ov0_02139164();
    inline void PushHistory(Point2D pos, Point2D partnerPos);

    inline Point2D GetTrail(int i)
    {
        return unk_204.pos[i];
    }

    inline BOOL IsKind0()
    {
        return unk_1FC == 0;
    }

    inline BOOL IsNpc()
    {
        return unk_1FC == 1;
    }

public:
    CFieldPartnerManage *unk_E0;
    CFieldActor *unk_E4;
    int unk_E8;
    CFieldPokeMove unk_EC;
    int unk_1C8;
    u16 unk_1CC;
    u8 unk_1CE[0x2];
    int unk_1D0;
    int unk_1D4;
    Point2D unk_1D8;
    Point2D unk_1E0;
    int unk_1E8;
    int unk_1EC;
    u8 unk_1F0[0x4];
    int unk_1F4;
    int unk_1F8;
    u32 unk_1FC;
    u32 unk_200;
    FieldTrail unk_204;
};

STATIC_SIZE_ASSERT(CFieldPartner, 0x268);

#endif // POKERANGER2_FIELD_CFIELDPARTNER_HPP
