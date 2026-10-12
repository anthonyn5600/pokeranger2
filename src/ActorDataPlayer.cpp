#include <nitro.h>

#include "CActorData.hpp"
#include "UnkClass_02007AA4.hpp"
#include "common.hpp"
#include "field/CFieldDrawActorData.hpp"
#include "file/CArchiveGuard.hpp"
#include "heap.hpp"

CActorDataPlayer::CActorDataPlayer()
{
    Init();
    unk_50834 = 0xFFFF;
}

CActorDataPlayer::~CActorDataPlayer()
{
    Release();
}

void CActorDataPlayer::sub_02041344(u16 id, int form, u32 mask, const char *arcName, BOOL useTransfer, BOOL alloc)
{
    char name[0x60];
    char path[0x60];
    char palettePath[0x60];
    char file[0x60];
    char arc[4];
    NNSG2dPaletteData *paletteData;

    if (unk_50834 == id) {
        return;
    }
    Release();

    m_anims = (CActorAnim *)Heap_AllocWithAlignment(0x1D * sizeof(CActorAnim), 4);
    MI_CpuClearFast(m_anims, 0x1D * sizeof(CActorAnim));
    m_animCount = 0x1D;
    unk_05 = 0;
    OS_SPrintf(name, "player%1d", id);

    if (arcName != NULL) {
        STD_CopyLString(arc, arcName, 4);
    } else {
        STD_CopyString(arc, "PLR");
    }
    OS_SPrintf(path, "data/player/%s_LZ.bin", name);

    m_archive = new CArchiveGuard(arc, path, 0, 1, 0, unk_34, sizeof(unk_34));
    if (m_archive == NULL) {
        return;
    }

    OS_SPrintf(palettePath, "%s:%s.NCLR", arc, name);
    void *data = NNS_FndGetArchiveFileByName(palettePath);
    if (data != NULL && NNS_G2dGetUnpackedPaletteData(data, &paletteData)) {
        m_palette = new UnkClass_02007AA4(paletteData);
    }

    int index = 0;
    for (int i = 0; i < 0x1C; i++) {
        if (mask & (1 << (i + 1))) {
            OS_SPrintf(file, "%s:%s_%02d", arc, name, i);
            sub_02014CEC(&m_anims[index], file, 0, TRUE);
            m_anims[index].id = i + 1;
            index++;
        }
    }

    unk_18 = 4;
    unk_1C = id;
    unk_1E = 0;
    unk_28 = useTransfer;
    if (alloc) {
        if (!useTransfer) {
            unk_2C = NNS_GfdAllocLnkTexVram(sub_02014310(), FALSE, 0);
            sub_020141AC(NNS_GfdGetTexKeyAddr(unk_2C));
            sub_020142B4();
        }
        unk_30 = NNS_GfdAllocLnkPlttVram(sub_02014364(), FALSE, 0);
        sub_0201429C(NNS_GfdGetPlttKeyAddr(unk_30));
        sub_020142F8();
    }
    unk_50834 = id;
}

CActorAnim *CActorDataPlayer::GetAnim(u8 id)
{
    for (int i = 0; i < m_animCount; i++) {
        if (id == m_anims[i].id) {
            return &m_anims[i];
        }
    }
    return NULL;
}

CActorAnim *CActorDataPlayer::sub_020143B8(int action, u32 sub)
{
    u8 id = GetAnimId(action, sub);
    if (id == 0xFF) {
        return NULL;
    }
    for (int i = 0; i < m_animCount; i++) {
        if (id == m_anims[i].id) {
            return &m_anims[i];
        }
    }
    return NULL;
}

u8 CActorDataPlayer::GetAnimId(int action, u32 sub)
{
    u8 id = 0;
    for (int i = 0; i < 0x1D; i++) {
        if ((action >> i) & 1) {
            id = i;
            break;
        }
    }
    return id;
}

void CActorDataPlayer::Release()
{
    sub_02040DB8();
    unk_50834 = 0xFFFF;
}
