#include <nitro.h>

#include "CBackup.hpp"
#include "common.hpp"

CBackupSync::CBackupSync()
{
    unk_10 = 0;
    unk_14 = 0;
    unk_18 = 0;
    unk_1C = 0;
}

CBackupSync::~CBackupSync()
{
}

BOOL CBackupSync::Init()
{
    unk_14 = 0;
    unk_18 = 0;
    unk_10 = 0;
    unk_1C = 0;
    return CBackupBase::Init();
}

BOOL CBackupSync::Write(u32 dst, const void *src, u32 len, MIDmaCallback callback)
{
    if (!unk_04 && !Init()) {
        return FALSE;
    }
    if (unk_1C != 0) {
        return FALSE;
    }
    unk_1C = 2;
    unk_14 = (u32)src;
    unk_18 = dst;
    unk_10 = len;
    return TRUE;
}

BOOL CBackupSync::Read(u32 src, void *dst, u32 len, MIDmaCallback callback)
{
    if (!unk_04 && !Init()) {
        return FALSE;
    }
    if (unk_1C != 0) {
        return FALSE;
    }
    unk_1C = 1;
    unk_14 = (u32)dst;
    unk_18 = src;
    unk_10 = len;
    return TRUE;
}

BOOL CBackupSync::Wait(BOOL block)
{
    BOOL done = FALSE;
    BOOL result = FALSE;
    u32 len;
    switch (unk_1C) {
    case 1:
        len = unk_10;
        if (len >= 0x800) {
            len = 0x800;
        }
        CARD_LockBackup((u16)unk_08);
        if (CARD_IsBackupEeprom()) {
            result = CARD_ReadEeprom(unk_18, (void *)unk_14, len);
        } else if (CARD_IsBackupFlash()) {
            result = CARD_ReadFlash(unk_18, (void *)unk_14, len);
        }
        unk_0C = CARD_GetResultCode();
        CARD_UnlockBackup((u16)unk_08);
        if (result) {
            unk_10 -= len;
            unk_18 += len;
            unk_14 += len;
            if (unk_10 == 0) {
                done = TRUE;
            }
        } else {
            done = TRUE;
        }
        break;
    case 2:
        len = unk_10;
        if (len >= 0x800) {
            len = 0x800;
        }
        CARD_LockBackup((u16)unk_08);
        if (CARD_IsBackupEeprom()) {
            result = CARD_WriteEeprom(unk_18, (const void *)unk_14, len);
        } else if (CARD_IsBackupFlash()) {
            result = CARD_WriteFlash(unk_18, (const void *)unk_14, len);
        }
        unk_0C = CARD_GetResultCode();
        CARD_UnlockBackup((u16)unk_08);
        if (result) {
            unk_10 -= len;
            unk_18 += len;
            unk_14 += len;
            if (unk_10 == 0) {
                done = TRUE;
            }
        } else {
            done = TRUE;
        }
        break;
    default:
        done = TRUE;
        break;
    }
    if (done) {
        unk_1C = 0;
    }
    return done;
}
