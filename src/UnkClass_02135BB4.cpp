#include "battle/UnkClass_02135BB4.hpp"

#include "CGame.hpp"
#include "UnkClass_02008E88.hpp"

UnkClass_02135BB4::UnkClass_02135BB4(CGame *game)
{
    m_game = game;
    unk_04 = new UnkClass_02008FA8(game->GetPrinter(), (u32)game->unk_0014);
}

UnkClass_02135BB4::~UnkClass_02135BB4()
{
    unk_04->sub_02009020();
    SAFE_DELETE(unk_04);
}

void UnkClass_02135BB4::ov1_02135C2C()
{
    unk_04->sub_020090E8(0, 0);
    unk_04->sub_020090E8(1, 0);
}

void UnkClass_02135BB4::ov1_02135C58()
{
    unk_04->sub_02009050();
}

int UnkClass_02135BB4::ov1_02135C68()
{
    return unk_04->sub_02009108();
}

int UnkClass_02135BB4::ov1_02135C78()
{
    return unk_04->sub_020090F4(0);
}

int UnkClass_02135BB4::ov1_02135C8C()
{
    return unk_04->sub_020090F4(1);
}
