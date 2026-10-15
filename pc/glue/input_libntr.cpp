// The controls from libntr's window (until the port has its own frontend): libntr's event loop (SIM_Render) presses
// and releases buttons in KEYINPUT and HW_BUTTON_XY_BUF and tracks the mouse on the touch screen in s_tpData. After
// each of its frames this reads them back and reports them to ntros, which then owns what the game sees. Backspace
// closes and opens the lid.
#include <SDL2/SDL.h>
#include <nitro.h>

#include "ntros.h"

extern "C" TPData s_tpData; // libntr: the mouse on the touch screen, in pixels

void PcInput_Read()
{
    static bool sLidClosed;
    static bool sLidKeyDown;
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    bool lidKey = keys != NULL && keys[SDL_SCANCODE_BACKSPACE];
    if (lidKey && !sLidKeyDown) {
        sLidClosed = !sLidClosed;
        OS_TPrintf("pc: lid %s\n", sLidClosed ? "closed" : "opened");
    }
    sLidKeyDown = lidKey;

    NtrOsInput input = {};
    u16 xy = *(vu16 *)HW_BUTTON_XY_BUF;
    input.buttons = (u16)((~reg_PAD_KEYINPUT & 0x03FF) | (~xy & (PAD_BUTTON_X | PAD_BUTTON_Y)));
    input.touching = s_tpData.touch != 0;
    input.touchX = s_tpData.x;
    input.touchY = s_tpData.y;
    input.lidClosed = sLidClosed;
    NtrOs_SetInput(&input);
}
