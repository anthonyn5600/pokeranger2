#include "CBattleResultParameter.hpp"

CBattleResultParameter::CBattleResultParameter()
{
    BattleResultParameter_Reset(this);
}

CBattleResultParameter::~CBattleResultParameter()
{
}

extern "C" {

void BattleResultParameter_Reset(CBattleResultParameter *obj)
{
    MI_CpuClear8(obj, sizeof(strBattleResultParameter));
    obj->unk_04 = 0xFF;
    obj->unk_08 = 0;
}
}
