#ifndef POKERANGER2_CBACKUP_HPP
#define POKERANGER2_CBACKUP_HPP

#include <nitro.h>

#include "common.hpp"

// Card backup access: holds a lock ID once Init() succeeded; still asm (0x0202B5D0..)
class CBackupBase {
public:
    CBackupBase();
    virtual ~CBackupBase();
    virtual BOOL Init();
    virtual BOOL Finalize();
    virtual BOOL Write(u32 dst, const void *src, u32 len, MIDmaCallback callback) = 0;
    virtual BOOL Read(u32 src, void *dst, u32 len, MIDmaCallback callback) = 0;
    virtual BOOL Wait(BOOL block) = 0;

    BOOL TestRead();

public:
    BOOL unk_04; // initialized
    int unk_08; // lock ID
    int unk_0C; // last CARD result
};

// EEPROM / flash reads and verified writes
class CBackup : public CBackupBase {
public:
    CBackup();
    virtual ~CBackup();
    virtual BOOL Write(u32 dst, const void *src, u32 len, MIDmaCallback callback);
    virtual BOOL Read(u32 src, void *dst, u32 len, MIDmaCallback callback);
    virtual BOOL Wait(BOOL block);

public:
    MIDmaCallback unk_10;
};

STATIC_SIZE_ASSERT(CBackup, 0x14);

// Synchronous backup: Read/Write only queue the request, Wait copies it in 0x800-byte steps
class CBackupSync : public CBackupBase {
public:
    CBackupSync();
    virtual ~CBackupSync();
    virtual BOOL Init();
    virtual BOOL Write(u32 dst, const void *src, u32 len, MIDmaCallback callback);
    virtual BOOL Read(u32 src, void *dst, u32 len, MIDmaCallback callback);
    virtual BOOL Wait(BOOL block);

public:
    u32 unk_10; // bytes left
    u32 unk_14; // memory address
    u32 unk_18; // backup address
    int unk_1C; // 1 = read, 2 = write
};

STATIC_SIZE_ASSERT(CBackupSync, 0x20);

#endif // POKERANGER2_CBACKUP_HPP
