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
    virtual void sub_0200F8BC();

    static BOOL sub_0200F9E0();
    static void sub_0200F9F8();
    static void sub_0200FA0C(u32 bit);
    static void sub_0200FA2C(u32 bit);
    static void sub_0200FA48(u32 mode);

public:
    u32 unk_4;
    u32 unk_8;
};

#endif // POKERANGER2_CPOWERMANAGE_HPP
