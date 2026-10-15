#include "file/CBinaryFile.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "CGame.hpp"
#include "file/CBinaryFileMes.hpp"
#include "heap.hpp"

// The end offset of an open file. The game reads it through the directory view of the FSFile property union, where
// it lies on the DS (4-byte pointers); on PC that word is somewhere else.
#ifdef PC_PORT
#define FILE_END(file) ((file).prop.file.bottom)
#else
#define FILE_END(file) ((file).prop.dir.pos.pos)
#endif

// This is required to match the while-loop in ReadFile.
// This doesn't affect any other function.
#pragma optimization_level 2

extern "C" {

extern u32 MAIN_BSS_0208F320;
extern u32 *MAIN_BSS_0208F31C;
}

CBinaryFile::CBinaryFile()
{
    Init();
}

CBinaryFile::CBinaryFile(const char *path, u32 arg1, u32 arg2, u32 arg3, void *arg4, u32 arg5)
{
    Init();
    void *v0 = Load(path, arg1, arg2, arg3, arg4, arg5);

    if (v0 == NULL) {
        Init();
    }
}

CBinaryFile::~CBinaryFile()
{
    Release();
}

void CBinaryFile::Init()
{
    unk_4C = NULL;
    unk_50 = 0;
    unk_54 = 1;
}

void *CBinaryFile::Load(const char *path, u32 arg1, u32 arg2, u32 arg3, void *arg4, u32 arg5)
{
    Release();

    if (path != NULL && arg3 == 0) {
        if (STD_GetStringLength(path) >= 0x60) {
            return NULL;
        }

        STD_CopyLString((char *)&unk_58, path, 0x60);
    } else {
        STD_CopyLString((char *)&unk_58, "", 0x60);
    }

    if (arg1 == 2) {
        unk_4C = NNS_FndGetArchiveFileByName(path);

        if (unk_4C != NULL) {
            FS_InitFile(&file);
            FS_OpenFile(&file, path);

            unk_50 = FILE_END(file) - file.prop.file.top;
            FS_CloseFile(&file);
            unk_54 = 0;
        }

        return unk_4C;
    }

    void *v0 = ReadFile(path, arg1, arg2, arg4, arg5);

    if (v0 != NULL) {
        DC_FlushRange(v0, unk_50);

        if (arg4 != 0) {
            unk_54 = 0;
        }
    }

    return v0;
}

void *CBinaryFile::ReadFile(const char *path, u32 arg1, u32 arg2, void *arg3, u32 arg4)
{
    FS_InitFile(&file);
    BOOL v0 = FS_OpenFile(&file, path);

    if (!v0) {
        return NULL;
    }

    unk_50 = FILE_END(file) - file.prop.file.top;

    if (arg3 == NULL || arg2 != 0) {
        if (arg2 != 0) {
            if (unk_50 > 0x20000) {
                OS_Terminate();
            }

            unk_4C = &MAIN_BSS_0208F320;
        } else {
            u32 v1;

            if (arg1 == 0) {
                v1 = 4;
            } else {
                v1 = -4;
            }

            if (arg2 != 0) {
                v1 *= -1;
            }

            unk_54 = 1;
            unk_4C = Heap_AllocWithAlignment(unk_50, v1);

            if (unk_4C == NULL) {
                NNSFndHeapHandle *v2 = Heap_GetMainHandle();
                NNS_FndGetAllocatableSizeForExpHeapEx(*v2, 4);
                NNS_FndGetTotalFreeSizeForExpHeap(*v2);

                FS_CloseFile(&file);
                return NULL;
            }
        }
    } else {
        if (arg4 < unk_50) {
            FS_CloseFile(&file);
            return NULL;
        }

        unk_4C = arg3;
    }

    if (MAIN_BSS_0208F31C == 0) {
        s32 v3 = FS_ReadFile(&file, unk_4C, unk_50);

        if (unk_50 != v3) {
            if (arg3 != unk_4C && arg2 == 0 && unk_4C != NULL) {
                Heap_Free(unk_4C);
                unk_4C = NULL;
            }

            FS_CloseFile(&file);
            return NULL;
        }
    } else {
        void *v4 = unk_4C;
        u32 v5 = unk_50;

        while (v5) {
            s32 v6 = FS_ReadFile(&file, v4, 0x200);

            if (v6 < 0) {
                if (arg3 != unk_4C && arg2 == 0 && unk_4C != NULL) {
                    Heap_Free(unk_4C);
                    unk_4C = NULL;
                }

                FS_CloseFile(&file);
                return NULL;
            }

            v4 = (u8 *)v4 + v6;

            if (v5 < v6) {
                v5 = 0;
            } else {
                v5 -= v6;
            }
        }
    }

    if (arg2 != 0) {
        unk_50 = *((u32 *)unk_4C) >> 8;
        s32 v7 = *((s32 *)unk_4C) & 0xF0;

        if (arg3 == NULL) {
            arg3 = Heap_AllocWithAlignment(unk_50, arg1 == 0 ? 4 : -4);

            if (arg3 == NULL) {
                NNSFndHeapHandle *v12 = Heap_GetMainHandle();
                NNS_FndGetAllocatableSizeForExpHeapEx(*v12, 4);
                NNS_FndGetTotalFreeSizeForExpHeap(*v12);

                FS_CloseFile(&file);
                return NULL;
            }
        } else if (arg4 < unk_50) {
            FS_CloseFile(&file);
            return NULL;
        }

        switch (v7) {
        case 0x10:
            MI_UncompressLZ8(unk_4C, arg3);
            break;

        case 0x20:
            MI_UncompressHuffman(unk_4C, arg3);
            break;

        case 0x30:
            MI_UncompressRL8(unk_4C, arg3);
            break;

        case 0x80:
            MI_UnfilterDiff8(unk_4C, arg3);
            break;

        default:
            break;
        }

        unk_4C = arg3;
    }

    FS_CloseFile(&file);
    return unk_4C;
}

void CBinaryFile::Release()
{
    if (unk_54 != 0 && unk_4C != NULL) {
        Heap_Free(unk_4C);
        unk_4C = NULL;
    }

    Init();
}

BOOL CBinaryFile::Exists(const char *path, u32 arg1)
{
    FSFileID fileID;
    return FS_ConvertPathToFileID(&fileID, path);
}

const char *CBinaryFileMes::GetLanguageSuffix()
{
    static const char *DAT_0208A538[] = {
        "_jp.mes",
        "_us.mes",
        "_fr.mes",
        "_ge.mes",
        "_it.mes",
        "_sp.mes",
        "",
        ".eng",
        ".fre",
        ".ger",
        ".ita",
        ".spa",
    };

    CGame::GetInstance();
    return DAT_0208A538[1];
}

CBinaryFileMes::CBinaryFileMes(const char *path, u32 arg1)
{
    char v0[0x40];
    OS_SPrintf(v0, "%s%s", path, GetLanguageSuffix());

    void *v1 = Load(v0, arg1, 0, 0, 0, 0);

    if (v1 == NULL) {
        Init();
    }
}

// NOTE: The following are junk classes that generate vtables/RTTI to
// have the correct ordering for the symbols in the `.data` section
// of this TU. They are dead-stripped by the linker, but still have an
// influence on symbol order.
//
// We assume that the original source code also had unused classes that
// got dead-stripped by the linker. Which means we can't recover those.
//
// They are required for matching!

class Caaaaaaaaaaaaaa {
public:
    virtual void FuncA0();
    virtual void FuncA1();
};

void Caaaaaaaaaaaaaa::FuncA0()
{
}

class Cbbbbbbbbbbbbb {
public:
    virtual void FuncB0();
    virtual void FuncB1();
    virtual void FuncB2();
    virtual void FuncB3();
};

void Cbbbbbbbbbbbbb::FuncB0()
{
}

class Cccccccccc : public Caaaaaaaaaaaaaa {
public:
    virtual ~Cccccccccc();
};

Cccccccccc::~Cccccccccc()
{
}

class Cdddddddddddddddd : public Cbbbbbbbbbbbbb {
public:
    virtual void FuncD0();
};

void Cdddddddddddddddd::FuncD0()
{
}

class Cee : public Cbbbbbbbbbbbbb {
public:
    virtual ~Cee();
};

Cee::~Cee()
{
}

#ifdef PC_PORT
// The DS linker drops these classes before their undefined virtuals matter; the PC linker needs them defined.
void Caaaaaaaaaaaaaa::FuncA1()
{
}

void Cbbbbbbbbbbbbb::FuncB1()
{
}

void Cbbbbbbbbbbbbb::FuncB2()
{
}

void Cbbbbbbbbbbbbb::FuncB3()
{
}
#endif
