#include "CGame.hpp"
#include "field/CFieldEffectManage.hpp"
#include "file/CBinaryFile.hpp"

UnkClass_021638B8::UnkClass_021638B8()
{
    MI_CpuClear8(m_scripts, sizeof(m_scripts));
    sub_02044B48(&m_vm, m_stack, 0x20);
}

UnkClass_021638B8::~UnkClass_021638B8()
{
    ov0_021639BC();
    sub_02044B78(&m_vm);
}

int UnkClass_021638B8::ov0_02163904(int id)
{
    char path[0x104];
    OS_SPrintf(path, "data/Script/field/effect/ef%03d.fsb", id);
    int i;
    for (i = 0; i < 3; i++) {
        if (m_scripts[i].m_script == NULL) {
            break;
        }
    }
    if (i >= 3) {
        return -1;
    }
    u32 heap = CGame::GetInstance()->unk_14A8;
    m_scripts[i].m_file = new CBinaryFile(path, 0, 0, heap, NULL, 0);
    m_scripts[i].m_script = m_scripts[i].m_file->unk_4C;
    sub_02044AC8(m_scripts[i].m_script);
    return i;
}

void UnkClass_021638B8::ov0_021639BC()
{
    for (int i = 0; i < 3; i++) {
        SAFE_DELETE(m_scripts[i].m_file);
        m_scripts[i].m_script = NULL;
    }
}

int UnkClass_021638B8::ov0_02163A08(int slot, int arg, int x, int y, int param)
{
    if (slot >= 0 && slot < 3 && m_scripts[slot].m_script != NULL) {
        sub_02044B84(&m_vm);
        m_vm.unk_04 -= 4;
        u32 *args = m_vm.unk_04;
        args[0] = arg;
        args[1] = x;
        args[2] = y;
        args[3] = param;
        sub_02046040(&m_vm, m_scripts[slot].m_script, "EventHandle", 4);
    }
    return 0;
}
