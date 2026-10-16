// The port's window and main loop (stage 4). main() opens a window with SDL, starts what libntr still provides
// (SIM_PortInit, local libntr patch: its register variables, wireless and network parts) and runs the game. Every
// finished picture comes to Frontend_ShowFrame: it reads the window's events, reports the controls to ntros, waits
// until the frame's time is up and shows the picture. The frame length comes from the sound card's clock
// (Audio_FrameNs), else the DS's 59.83 frames per second.
//
// Settings come from sim_config.ini (libntr's file, which also holds the system settings the game reads):
//   [General] ScreenLayout=vertical|horizontal, SwapScreens, FullScreen, WindowWidth / WindowHeight (0 = pick)
//   [PAD]     AKey, BKey, XKey, YKey, UpKey, DownKey, LeftKey, RightKey, LKey, RKey, StartKey, SelectKey: SDL key
//             codes (defaults Z X C V, arrows, Q E, Enter, Right Shift)
// Fixed keys: Backspace closes / opens the lid, F11 or Alt+Enter switches full screen. Game controllers work with
// SDL's standard layout (buttons by name: A = A, B = B, ...; D-pad or left stick; Back = Select).
// The mouse (or a finger) on the bottom screen is the stylus.
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <chrono>
#include <fstream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <mmsystem.h> // timeBeginPeriod
#include <windows.h>
#endif

#include "frontend.h"
#include "ntros.h"

extern "C" void NitroMain(void);
extern "C" void SIM_PortInit(int argc, char *argv[]); // libntr (local patch)

namespace {

using Clock = std::chrono::steady_clock;

constexpr int kWidth = 256;
constexpr int kHeight = 192;
constexpr long kDsFrameNs = 16715260; // 263 lines x 2130 cycles at 33513982 Hz

// DS buttons in KEYINPUT order (PAD_BUTTON_A .. PAD_BUTTON_L), then X and Y
enum Button {
    kA,
    kB,
    kSelect,
    kStart,
    kRight,
    kLeft,
    kUp,
    kDown,
    kR,
    kL,
    kX,
    kY,
    kButtonCount
};

struct Settings {
    bool horizontal = false;
    bool swapScreens = false;
    bool fullScreen = false;
    int windowWidth = 0;
    int windowHeight = 0;
    SDL_Keycode keys[kButtonCount] = { SDLK_z, SDLK_x, SDLK_RSHIFT, SDLK_RETURN, SDLK_RIGHT, SDLK_LEFT, SDLK_UP, SDLK_DOWN, SDLK_e, SDLK_q, SDLK_c, SDLK_v };
};

Settings sSettings;
SDL_Window *sWindow;
SDL_Renderer *sRenderer;
SDL_Texture *sTexture;
bool sKeyHeld[kButtonCount];
bool sPadHeld[kButtonCount];
bool sStickHeld[kButtonCount];
bool sPenDown; // the mouse button went down on the bottom screen and is still held
int sPenX, sPenY;
bool sLidClosed;

void LoadSettings(const char *path)
{
    static const char *const kKeyNames[kButtonCount] = { "AKey", "BKey", "SelectKey", "StartKey", "RightKey", "LeftKey", "UpKey", "DownKey", "RKey", "LKey", "XKey", "YKey" };
    std::ifstream file(path);
    std::string line, section;
    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        if (line.size() > 2 && line[0] == '[') {
            section = line.substr(1, line.find(']') - 1);
            continue;
        }
        size_t eq = line.find('=');
        if (eq == std::string::npos) {
            continue;
        }
        std::string name = line.substr(0, eq), value = line.substr(eq + 1);
        if (section == "General") {
            if (name == "ScreenLayout") {
                sSettings.horizontal = value == "horizontal";
            } else if (name == "SwapScreens") {
                sSettings.swapScreens = value == "true";
            } else if (name == "FullScreen") {
                sSettings.fullScreen = value == "true";
            } else if (name == "WindowWidth") {
                sSettings.windowWidth = atoi(value.c_str());
            } else if (name == "WindowHeight") {
                sSettings.windowHeight = atoi(value.c_str());
            }
        } else if (section == "PAD") {
            for (int b = 0; b < kButtonCount; b++) {
                if (name == kKeyNames[b] && atol(value.c_str()) != 0) {
                    sSettings.keys[b] = (SDL_Keycode)atol(value.c_str());
                }
            }
        }
    }
}

// Both screens side by side or one above the other, in DS pixels
int LayoutWidth()
{
    return sSettings.horizontal ? kWidth * 2 : kWidth;
}
int LayoutHeight()
{
    return sSettings.horizontal ? kHeight : kHeight * 2;
}

// Where a screen (0 top, 1 bottom) goes, in DS pixels of the layout
SDL_Rect ScreenRect(int screen)
{
    int slot = screen ^ (sSettings.swapScreens ? 1 : 0);
    return sSettings.horizontal ? SDL_Rect { slot * kWidth, 0, kWidth, kHeight } : SDL_Rect { 0, slot * kHeight, kWidth, kHeight };
}

void OpenWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0) {
        fprintf(stderr, "pc: cannot start SDL: %s\n", SDL_GetError());
        exit(1);
    }
    int width = sSettings.windowWidth, height = sSettings.windowHeight;
    if (width <= 0 || height <= 0) {
        // The biggest whole-number scale that fits the desktop
        SDL_Rect usable = { 0, 0, 1280, 720 };
        SDL_GetDisplayUsableBounds(0, &usable);
        int scale = 1;
        while (LayoutWidth() * (scale + 1) <= usable.w * 9 / 10 && LayoutHeight() * (scale + 1) <= usable.h * 9 / 10) {
            scale++;
        }
        width = LayoutWidth() * scale;
        height = LayoutHeight() * scale;
    }
    sWindow = SDL_CreateWindow("Pok\xC3\xA9mon Ranger: Shadows of Almia", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE | (sSettings.fullScreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0));
    if (sWindow == NULL) {
        fprintf(stderr, "pc: cannot open the window: %s\n", SDL_GetError());
        exit(1);
    }
    // No vsync: the frame limiter paces (the DS's 59.83 Hz isn't the monitor's rate)
    sRenderer = SDL_CreateRenderer(sWindow, -1, SDL_RENDERER_ACCELERATED);
    if (sRenderer == NULL) {
        sRenderer = SDL_CreateRenderer(sWindow, -1, SDL_RENDERER_SOFTWARE);
    }
    if (sRenderer == NULL) {
        fprintf(stderr, "pc: cannot draw in the window: %s\n", SDL_GetError());
        exit(1);
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
    sTexture = SDL_CreateTexture(sRenderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, kWidth, kHeight * 2);
    // Drawing in DS pixels: SDL scales to the window, keeps the shape (black bars) and converts mouse positions
    SDL_RenderSetLogicalSize(sRenderer, LayoutWidth(), LayoutHeight());
}

void ToggleFullScreen()
{
    bool full = (SDL_GetWindowFlags(sWindow) & SDL_WINDOW_FULLSCREEN_DESKTOP) != 0;
    SDL_SetWindowFullscreen(sWindow, full ? 0 : SDL_WINDOW_FULLSCREEN_DESKTOP);
}

// The pen at a layout position: on the bottom screen, or (while held) clamped to its edge
void MovePen(int x, int y)
{
    SDL_Rect r = ScreenRect(1);
    sPenX = x - r.x < 0 ? 0 : x - r.x >= kWidth ? kWidth - 1
                                                : x - r.x;
    sPenY = y - r.y < 0 ? 0 : y - r.y >= kHeight ? kHeight - 1
                                                 : y - r.y;
}

bool OnBottomScreen(int x, int y)
{
    SDL_Rect r = ScreenRect(1);
    SDL_Point p = { x, y };
    return SDL_PointInRect(&p, &r);
}

int PadButton(int button)
{
    switch (button) {
    case SDL_CONTROLLER_BUTTON_A:
        return kA;
    case SDL_CONTROLLER_BUTTON_B:
        return kB;
    case SDL_CONTROLLER_BUTTON_X:
        return kX;
    case SDL_CONTROLLER_BUTTON_Y:
        return kY;
    case SDL_CONTROLLER_BUTTON_BACK:
        return kSelect;
    case SDL_CONTROLLER_BUTTON_START:
        return kStart;
    case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
        return kL;
    case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
        return kR;
    case SDL_CONTROLLER_BUTTON_DPAD_UP:
        return kUp;
    case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
        return kDown;
    case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
        return kLeft;
    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
        return kRight;
    default:
        return -1;
    }
}

void HandleEvent(const SDL_Event &e)
{
    constexpr int kStickDeadzone = 8000;
    switch (e.type) {
    case SDL_QUIT:
        // The save is on disk already (ntros writes it as the game does)
        exit(0);
    case SDL_KEYDOWN:
    case SDL_KEYUP: {
        bool down = e.type == SDL_KEYDOWN;
        SDL_Keycode key = e.key.keysym.sym;
        if (down && !e.key.repeat) {
            if (key == SDLK_F11 || (key == SDLK_RETURN && (e.key.keysym.mod & KMOD_ALT))) {
                ToggleFullScreen();
                return;
            }
            if (key == SDLK_BACKSPACE) {
                sLidClosed = !sLidClosed;
                fprintf(stderr, "pc: lid %s\n", sLidClosed ? "closed" : "opened");
                return;
            }
        }
        for (int b = 0; b < kButtonCount; b++) {
            if (key == sSettings.keys[b]) {
                sKeyHeld[b] = down;
            }
        }
        break;
    }
    case SDL_CONTROLLERDEVICEADDED:
        SDL_GameControllerOpen(e.cdevice.which);
        break;
    case SDL_CONTROLLERBUTTONDOWN:
    case SDL_CONTROLLERBUTTONUP: {
        int b = PadButton(e.cbutton.button);
        if (b >= 0) {
            sPadHeld[b] = e.type == SDL_CONTROLLERBUTTONDOWN;
        }
        break;
    }
    case SDL_CONTROLLERAXISMOTION:
        if (e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX) {
            sStickHeld[kLeft] = e.caxis.value < -kStickDeadzone;
            sStickHeld[kRight] = e.caxis.value > kStickDeadzone;
        } else if (e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY) {
            sStickHeld[kUp] = e.caxis.value < -kStickDeadzone;
            sStickHeld[kDown] = e.caxis.value > kStickDeadzone;
        } else if (e.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT) {
            sStickHeld[kL] = e.caxis.value > kStickDeadzone;
        } else if (e.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT) {
            sStickHeld[kR] = e.caxis.value > kStickDeadzone;
        }
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (e.button.button == SDL_BUTTON_LEFT && OnBottomScreen(e.button.x, e.button.y)) {
            sPenDown = true;
            MovePen(e.button.x, e.button.y);
        }
        break;
    case SDL_MOUSEBUTTONUP:
        if (e.button.button == SDL_BUTTON_LEFT) {
            sPenDown = false;
        }
        break;
    case SDL_MOUSEMOTION:
        if (sPenDown) {
            MovePen(e.motion.x, e.motion.y);
        }
        break;
    }
}

void ReportInput()
{
    static const unsigned short kBits[kButtonCount] = { 0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 0x0100, 0x0200, 0x0400, 0x0800 };
    NtrOsInput input = {};
    for (int b = 0; b < kButtonCount; b++) {
        if (sKeyHeld[b] || sPadHeld[b] || sStickHeld[b]) {
            input.buttons |= kBits[b];
        }
    }
    input.touching = sPenDown;
    input.touchX = sPenX;
    input.touchY = sPenY;
    input.lidClosed = sLidClosed;
    NtrOs_SetInput(&input);
}

void SleepUntil(Clock::time_point deadline)
{
#ifdef _WIN32
    // Sleep has 1 ms steps at best (with timeBeginPeriod): sleep most of the way, then spin
    static const bool sTimerPeriod = (timeBeginPeriod(1), true);
    (void)sTimerPeriod;
    auto left = std::chrono::duration_cast<std::chrono::microseconds>(deadline - Clock::now()).count();
    if (left > 2000) {
        Sleep((DWORD)((left - 1500) / 1000));
    }
    while (Clock::now() < deadline) {
    }
#else
    std::this_thread::sleep_until(deadline);
#endif
}

// Absolute deadlines, so frames don't drift; more than 100 ms behind (a load, a stall), start over from now
void WaitForFrameEnd()
{
    static Clock::time_point sDeadline;
    long frameNs = Audio_FrameNs();
    auto now = Clock::now();
    if (sDeadline == Clock::time_point()) {
        sDeadline = now;
    }
    sDeadline += std::chrono::nanoseconds(frameNs > 0 ? frameNs : kDsFrameNs);
    if (now - sDeadline > std::chrono::milliseconds(100)) {
        sDeadline = now;
    } else if (now < sDeadline) {
        SleepUntil(sDeadline);
    }
}

} // namespace

void Frontend_ShowFrame(const FrontendPicture *picture)
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        HandleEvent(e);
    }
    ReportInput();
    WaitForFrameEnd();
    SDL_UpdateTexture(sTexture, NULL, picture, kWidth * 4);
    SDL_SetRenderDrawColor(sRenderer, 0, 0, 0, 255);
    SDL_RenderClear(sRenderer);
    for (int screen = 0; screen < 2; screen++) {
        SDL_Rect src = { 0, screen * kHeight, kWidth, kHeight };
        SDL_Rect dst = ScreenRect(screen);
        SDL_RenderCopy(sRenderer, sTexture, &src, &dst);
    }
    SDL_RenderPresent(sRenderer);
}

int main(int argc, char *argv[])
{
    SDL_SetMainReady();
    LoadSettings("sim_config.ini");
    OpenWindow();
    SIM_PortInit(argc, argv);
    NitroMain();
    return 0;
}

#ifdef _WIN32
// A Windows program (no console window): its entry point
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    return main(__argc, __argv);
}
#endif
