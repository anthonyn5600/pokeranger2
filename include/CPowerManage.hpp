#ifndef POKERANGER2_CPOWERMANAGE_HPP
#define POKERANGER2_CPOWERMANAGE_HPP

#include <nitro.h>

class CPowerManage {
public:
    CPowerManage()
    {
        unk_4 = 0;
        unk_8 = 0;
    }
    ~CPowerManage();

    virtual void Init();
    virtual void CheckFold();

    static BOOL Initialize();
    static void Process();
    static void AllowSleep(u32 bit);
    static void BlockSleep(u32 bit);
    static void SetMode(u32 mode);

public:
    u32 unk_4;
    u32 unk_8;
};

#endif // POKERANGER2_CPOWERMANAGE_HPP
