#include "UnkClass_02029800.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_02008788.hpp"
#include "UnkClass_02034478.hpp"
#include "common.hpp"

UnkClass_02029800::UnkClass_02029800()
{
    unk_00 = NULL;
    unk_04 = NULL;
    unk_08 = NULL;
    unk_20 = 0;
}

UnkClass_02029800::~UnkClass_02029800()
{
    sub_0202A1B4();
}

void UnkClass_02029800::sub_0202982C(int type)
{
    unk_24 = type;
    GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_OBJ);
    if (unk_24 < 100) {
        sub_02029A34();
    } else if (unk_24 < 200) {
        sub_02029B70();
    } else {
        sub_02029884();
    }
}

void UnkClass_02029800::sub_02029884()
{
    int charNo = 0;
    CGame *game = CGame::GetInstance();

    unk_00 = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0024[0x40], game->unk_14A8, FALSE, 0x40);
    charNo += unk_00->sub_0200EE14("data/menu", "title100_01", 0, 4);
    unk_0C = unk_00->sub_0200F4FC(0, -0x40, 0x40, 0);
    unk_0C->sub_0200EB34(0, TRUE);

    unk_04 = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0024[0x50], game->unk_14A8, FALSE, 0x40);
    charNo += unk_04->sub_0200EE14("data/menu", "title100_00", charNo / 32, 5);
    unk_10 = unk_04->sub_0200F4FC(0, 0x80, 0x30, 0);
    unk_28 = unk_04->unk_24;

    unk_08 = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0024[0x60], game->unk_14A8, FALSE, 0x40);
    unk_08->sub_0200EE14("data/menu", "title100_02", charNo / 32, 13);
    unk_14 = unk_08->sub_0200F4FC(0, 0x180, 0x30, 0);

    unk_20 = 1;
    unk_18 = 70;
    unk_1C = 0;
}

void UnkClass_02029800::sub_02029A34()
{
    int charNo = 0;
    CGame *game = CGame::GetInstance();
    char name[16];

    OS_SPrintf(name, "mit%03d", unk_24);

    unk_00 = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0024[0x40], game->unk_14A8, FALSE, 0x40);
    charNo += unk_00->sub_0200EE14("data/menu", name, 0, 4);
    unk_0C = unk_00->sub_0200F4FC(0, 0x80, 0x60, 0);

    unk_04 = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0024[0x44], game->unk_14A8, FALSE, 0x40);
    unk_04->sub_0200EE14("data/menu", "mit104", charNo / 32, 5);
    unk_10 = unk_04->sub_0200F4FC(0, 0x80, 0x60, 0);
    unk_28 = unk_04->unk_24;

    unk_20 = 1;
    unk_18 = 0;
    unk_1C = 240;
}

void UnkClass_02029800::sub_02029B70()
{
    int charNo = 0;
    CGame *game = CGame::GetInstance();

    unk_00 = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0024[0x40], game->unk_14A8, FALSE, 0x40);
    switch (unk_24) {
    case 100:
        charNo += unk_00->sub_0200EE14("data/menu", "title101_00", 0, 4);
        unk_1C = 240;
        break;
    case 101:
        charNo += unk_00->sub_0200EE14("data/menu", "title101_02", 0, 4);
        unk_1C = 240;
        break;
    case 102:
        charNo += unk_00->sub_0200EE14("data/menu", "title101_03", 0, 4);
        unk_1C = 420;
        break;
    }
    unk_0C = unk_00->sub_0200F4FC(0, 0x80, -0x30, 0);

    unk_04 = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0024[0x44], game->unk_14A8, FALSE, 0x40);
    if (unk_24 == 102) {
        unk_04->sub_0200EE14("data/menu", "title101_04", charNo / 32, 12);
    } else {
        unk_04->sub_0200EE14("data/menu", "title101_01", charNo / 32, 12);
    }
    unk_10 = unk_04->sub_0200F4FC(0, 0x80, -0x30, 0);
    unk_28 = unk_04->unk_24;

    unk_20 = 1;
    unk_18 = 0;
}

void UnkClass_02029800::sub_02029D4C()
{
    if (unk_24 < 100) {
        sub_02029F34();
    } else if (unk_24 < 200) {
        sub_02029F74();
    } else {
        sub_02029D7C();
    }
}

void UnkClass_02029800::sub_02029D7C()
{
    CGame *game = CGame::GetInstance();
    if (unk_20 == 0) {
        return;
    }

    int x = unk_0C->unk_0C;
    switch (unk_20) {
    case 1:
        x += 0x20;
        if (x == 0x140) {
            unk_20 = 2;
            unk_1C = 10;
            unk_0C->sub_0200EB28(x, 0x10);
        }
        break;
    case 2:
        if (--unk_1C == 0) {
            unk_20 = 3;
        }
        break;
    case 3:
        x -= 0x10;
        if (x == 0xD0) {
            unk_20 = 4;
        }
        break;
    case 4:
        x -= 0x10;
        if (x == 0x10) {
            unk_20 = 5;
        }
        break;
    }
    unk_0C->sub_0200EB28(x, unk_0C->unk_0E);

    x = unk_14->unk_0C;
    switch (unk_20) {
    case 4:
    case 5:
        if (x > 0x80) {
            x -= 0x10;
        } else {
            unk_20 = 6;
            unk_1C = 15;
        }
        break;
    case 6:
        if (--unk_1C == 0) {
            unk_20 = 7;
            game->m_audioEngine->sub_0203499C(0x2F);
            game->m_audioEngine->sub_02034A40(0x15, 0);
        }
        break;
    }
    unk_14->sub_0200EB28(x, unk_14->unk_0E);

    if (unk_20 == 7) {
        if (unk_04->unk_38->sub_02008860(unk_04->unk_08[unk_28]) == 0) {
            unk_20 = 8;
        }
    }
    unk_18++;
    unk_00->sub_0200F64C();
    if (unk_20 >= 7) {
        unk_04->sub_0200F64C();
    }
    unk_08->sub_0200F64C();
}

void UnkClass_02029800::sub_02029F34()
{
    if (unk_20 == 0) {
        return;
    }
    if (unk_1C != 0) {
        unk_1C--;
    } else {
        unk_20 = 2;
    }
    unk_00->sub_0200F64C();
    unk_04->sub_0200F64C();
}

void UnkClass_02029800::sub_02029F74()
{
    if (unk_20 == 0) {
        return;
    }

    int y = unk_0C->unk_0E;
    switch (unk_20) {
    case 1:
        y += 8;
        if (y == 0x30) {
            unk_20 = 2;
        }
        break;
    case 2:
        y += 4;
        if (y == 0x38) {
            unk_20 = 3;
        }
        break;
    case 3:
        y -= 2;
        if (y == 0x30) {
            unk_20 = 4;
        }
        break;
    case 4:
        if (unk_1C == 0x10) {
            unk_20 = 5;
        }
        break;
    case 5:
        y += 1;
        if (y == 0x38) {
            unk_20 = 6;
        }
        break;
    case 6:
        y -= 4;
        if (y == 0x30) {
            unk_20 = 7;
        }
        break;
    case 7:
        y -= 8;
        if (y == -0x30) {
            unk_20 = 8;
        }
        break;
    case 8:
        break;
    }
    unk_0C->sub_0200EB28(unk_0C->unk_0C, y);
    unk_10->sub_0200EB28(unk_10->unk_0C, y);
    if (unk_1C != 0) {
        unk_1C--;
    } else {
        unk_20 = 9;
    }
    if (unk_1C < 190) {
        unk_00->sub_0200F64C();
    }
    unk_04->sub_0200F64C();
}

void UnkClass_02029800::sub_0202A0A4()
{
    if (unk_24 < 100) {
        sub_0202A150();
    } else if (unk_24 < 200) {
        sub_0202A184();
    } else {
        sub_0202A0D4();
    }
}

void UnkClass_02029800::sub_0202A0D4()
{
    int div = unk_20 < 3 ? 2 : 1;
    CGame *game = CGame::GetInstance();
    s16 scale = (s16)((FX32_ONE / div) >> 4);
    GXOamAffine *oam = (GXOamAffine *)&game->unk_0024[0];
    oam->PA = scale;
    oam->PB = 0;
    oam->PC = 0;
    oam->PD = scale;
    if (unk_20 == 0) {
        return;
    }
    unk_00->sub_0200F71C();
    if (unk_20 >= 7) {
        unk_04->sub_0200F71C();
    }
    unk_08->sub_0200F71C();
}

void UnkClass_02029800::sub_0202A150()
{
    if (unk_20 == 0) {
        return;
    }
    if (unk_1C < 140) {
        unk_00->sub_0200F71C();
    }
    unk_04->sub_0200F71C();
}

void UnkClass_02029800::sub_0202A184()
{
    if (unk_20 == 0) {
        return;
    }
    unk_00->sub_0200F71C();
    unk_04->sub_0200F71C();
}

int UnkClass_02029800::sub_0202A1AC()
{
    return unk_20;
}

void UnkClass_02029800::sub_0202A1B4()
{
    GX_SetVisiblePlane(GX_GetVisiblePlane() ^ GX_PLANEMASK_OBJ);
    if (unk_00 != NULL) {
        unk_00->sub_0200F6C4();
        unk_00->sub_0200F4A8();
    }
    if (unk_04 != NULL) {
        unk_04->sub_0200F6C4();
        unk_04->sub_0200F4A8();
    }
    if (unk_08 != NULL) {
        unk_08->sub_0200F6C4();
        unk_08->sub_0200F4A8();
    }
    SAFE_DELETE(unk_00);
    SAFE_DELETE(unk_04);
    SAFE_DELETE(unk_08);
    unk_20 = 0;
}
