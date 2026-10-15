// "Who wrote this?" tracking for display memory (pc/glue/vramtrack.cpp)
#ifndef PC_GLUE_VRAMTRACK_HPP
#define PC_GLUE_VRAMTRACK_HPP

#include <nitro/types.h>

void VramTrack_SetFrame(u32 frame);
// Writes the writer table (text) when tracking is on (NTRGFX_TRACK=1 / NTRGFX_TRACE); true if nothing to do
bool VramTrack_Save(const char *path);

#endif // PC_GLUE_VRAMTRACK_HPP
