// The port's own window and main loop (pc/frontend): main() opens the window, starts what libntr still provides and
// runs the game. Whoever renders the screens hands each finished picture to Frontend_ShowFrame from the display
// timeline's endFrame / sleepFrame callbacks.
#ifndef PC_FRONTEND_H
#define PC_FRONTEND_H

#include <stdint.h>

// Both screens, 256x384 RGBA, top screen first, top row first
typedef uint8_t FrontendPicture[384][256][4];

// Shows the picture, reports the player's controls to ntros (NtrOs_SetInput) and waits until the frame's time is up
void Frontend_ShowFrame(const FrontendPicture *picture);

// audio.cpp: how long this frame should take, in ns (the sound card's clock sets the pace); 0 = no sound device yet
long Audio_FrameNs();

#endif // PC_FRONTEND_H
