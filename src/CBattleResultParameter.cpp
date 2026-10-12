#include "CBattleResultParameter.hpp"

CBattleResultParameter::CBattleResultParameter()
{
    sub_02010D04(this);
}

CBattleResultParameter::~CBattleResultParameter()
{
}

extern "C" {

void sub_02010D04(CBattleResultParameter *obj)
{
    MI_CpuClear8(obj, sizeof(strBattleResultParameter));
    obj->unk_04 = 0xFF;
    obj->unk_08 = 0;
}
}
