#include <nitro.h>

#include "CBackup.hpp"
#include "CardBackupInfo.hpp"
#include "common.hpp"

extern "C" {
extern CardBackupInfo sCardBackupInfo;
}

CBackupBase::CBackupBase()
{
    unk_04 = FALSE;
    unk_0C = 0;
    unk_08 = OS_LOCK_ID_ERROR;
}

CBackupBase::~CBackupBase()
{
    Finalize();
}

BOOL CBackupBase::Init()
{
    if (!sCardBackupInfo.valid) {
        return FALSE;
    }
    if (!unk_04) {
        CARD_Init();
        unk_08 = OS_GetLockID();
        if (unk_08 == OS_LOCK_ID_ERROR) {
            return FALSE;
        }
        unk_04 = TRUE;
    }
    if (TestRead()) {
        return TRUE;
    }
    Finalize();
    return FALSE;
}

BOOL CBackupBase::Finalize()
{
    if (unk_04) {
        OS_ReleaseLockID((u16)unk_08);
        unk_04 = FALSE;
        unk_08 = OS_LOCK_ID_ERROR;
    }
    return TRUE;
}

BOOL CBackupBase::TestRead()
{
    u8 buf;
    BOOL result = FALSE;
    CARD_LockBackup((u16)unk_08);
    if (CARD_IsBackupEeprom()) {
        result = CARD_ReadEeprom(0, &buf, 1);
    } else if (CARD_IsBackupFlash()) {
        result = CARD_ReadFlash(0, &buf, 1);
    }
    unk_0C = CARD_GetResultCode();
    CARD_UnlockBackup((u16)unk_08);
    return result;
}
