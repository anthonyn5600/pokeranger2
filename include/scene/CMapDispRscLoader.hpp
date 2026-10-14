#ifndef POKERANGER2_SCENE_CMAPDISPRSCLOADER_HPP
#define POKERANGER2_SCENE_CMAPDISPRSCLOADER_HPP

#include <nitro.h>

#include "common.hpp"
#include "file/CBinaryFile.hpp"

// Defined in ov28
class IMapDispRscPathBuilder {
public:
    virtual BOOL GetArchivePath(int id, char *buf, int size) = 0;
    virtual BOOL GetFilePath(int id, char *buf, int size) = 0;
};

// Defined in ov28: loads a direct color bitmap into sub BG3 on its own thread
class CMapDispRscLoader {
public:
    CMapDispRscLoader();
    ~CMapDispRscLoader();

    void SetupBG();
    void RestoreBG();
    BOOL Request(int id);
    void Update();
    BOOL Load(int id);
    BOOL Quit();
    BOOL IsDone();

public:
    int m_request;
    u32 unk_04;
    CBinaryFile *unk_08;
    IMapDispRscPathBuilder *m_pathBuilder;
    GXBGMode m_savedBGMode;
    BOOL m_alarmAvailable;
    OSThread m_thread;
    u8 m_stack[0x1000];
    OSMessageQueue m_queue;
    OSMessage m_messages[1];
};

STATIC_SIZE_ASSERT(CMapDispRscLoader, 0x10FC);

#endif // POKERANGER2_SCENE_CMAPDISPRSCLOADER_HPP
