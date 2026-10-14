#include "file/CNANRFile.hpp"

#include <nitro.h>
#include <nnsys.h>

CNANRFile::CNANRFile(const char *path, u32 arg1, u32 arg2, u32 arg3)
{
    void *v0 = Load(path, arg1, arg2, arg3, NULL, 0);

    if (v0 == NULL) {
        return;
    }

    BOOL v1 = NNS_G2dGetUnpackedAnimBank(unk_4C, &unk_B8);

    if (!v1) {
        Release();
        return;
    }
}

CNANRFile::~CNANRFile()
{
    Release();
}
