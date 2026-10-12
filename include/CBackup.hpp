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

    BOOL sub_0202B72C();

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

// Backup through the other CPU (0x0202B8A4..); still asm
class CBackupSync : public CBackupBase {
public:
    CBackupSync();
    virtual ~CBackupSync();
    virtual BOOL Init();
    virtual BOOL Write(u32 dst, const void *src, u32 len, MIDmaCallback callback);
    virtual BOOL Read(u32 src, void *dst, u32 len, MIDmaCallback callback);
    virtual BOOL Wait(BOOL block);

public:
    u8 unk_10[0x10];
};

STATIC_SIZE_ASSERT(CBackupSync, 0x20);

#endif // POKERANGER2_CBACKUP_HPP
