#include "UnkClass_0213D624.hpp"

UnkClass_0213D624::UnkClass_0213D624()
{
    unk_00 = NULL;
    unk_04 = NULL;
    unk_08 = NULL; // unk_0C isn't cleared
    unk_10 = NULL;
    unk_14 = NULL;
    unk_18 = NULL;
}

UnkClass_0213D624::~UnkClass_0213D624()
{
    ov0_0213D728();
}

void UnkClass_0213D624::ov0_0213D658()
{
    unk_00 = new UnkClass_02149118();
    UnkClass_02149118::ov0_02149120();
    unk_04 = new UnkClass_021485C0();
    UnkClass_021485C0::ov0_021485C8();
    unk_08 = new UnkClass_02149984();
    UnkClass_02149984::ov0_0214998C();
    unk_0C = new UnkClass_02149A74();
    UnkClass_02149A74::ov0_02149A7C();
    unk_10 = new UnkClass_02149E58();
    UnkClass_02149E58::ov0_02149E60();
    unk_14 = new UnkClass_0214B93C();
    UnkClass_0214B93C::ov0_0214B944();
    unk_18 = new UnkClass_0214B6F0();
    UnkClass_0214B6F0::ov0_0214B6F8();
}

void UnkClass_0213D624::ov0_0213D728()
{
    SAFE_DELETE(unk_00);
    SAFE_DELETE(unk_04);
    SAFE_DELETE(unk_08);
    SAFE_DELETE(unk_0C);
    SAFE_DELETE(unk_10);
    SAFE_DELETE(unk_14);
    SAFE_DELETE(unk_18);
}
