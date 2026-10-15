// The SDK's touch screen API (TP_*), with the ARM7 answering at once: a sampling request measures the pen as it is
// now (input.cpp) and completes before TP_RequestSamplingAsync returns, so the callback, if any, runs inside it.
// Raw positions convert to pixels with the calibration from the firmware's user settings, in the SDK's fixed point
// (dot sizes in 1/256 raw units per pixel, origins in 1/4 raw units). Auto sampling is not provided (the game
// doesn't use it).
#include <string.h>

#include "ntros.h"

#include "internal.hpp"

namespace {

constexpr int kRawMax = 0x1000;
constexpr int kDotShift = TP_CALIBRATE_DOT_SCALE_SHIFT; // 8
constexpr int kOriginShift = TP_CALIBRATE_ORIGIN_SCALE_SHIFT; // 2
constexpr int kInvShift = 28 - kDotShift; // pixels per raw unit, as 2^28 / dot size

struct Calibration {
    s32 x0, xDotSize, xDotSizeInv;
    s32 y0, yDotSize, yDotSizeInv;
};

bool sInitialized;
TPRecvCallback sCallback;
TPData sResult; // last sampling result (raw)
Calibration sCal;
bool sCalibrated;
vu16 sState;
vu16 sBusy; // TP_REQUEST_COMMAND_FLAG_* in progress
vu16 sError; // TP_REQUEST_COMMAND_FLAG_* that failed

bool InS16(s32 v)
{
    return v >= -0x8000 && v < 0x8000;
}

// One axis of TP_CalcCalibrateParam; false when out of range
bool CalcAxis(u16 raw1, u16 raw2, u16 pixel1, u16 pixel2, s16 *origin, s16 *dotSize)
{
    s32 dot = (s32)((u32)(raw1 - raw2) << kDotShift) / (s32)(pixel1 - pixel2);
    if (!InS16(dot)) {
        return false;
    }
    s32 org = (s16)((((s32)(raw1 + raw2) << kDotShift) - (s32)(pixel1 + pixel2) * (s16)dot) >> (kDotShift - kOriginShift + 1));
    if (!InS16(org)) {
        return false;
    }
    *dotSize = (s16)dot;
    *origin = (s16)org;
    return true;
}

void SetAxis(s32 origin, s32 dotSize, s32 *calOrigin, s32 *calDot, s32 *calInv)
{
    if (dotSize != 0) {
        *calOrigin = origin;
        *calDot = dotSize;
        *calInv = (s32)0x10000000 / dotSize;
    } else {
        *calOrigin = 0;
        *calDot = 0;
        *calInv = 0;
    }
}

u16 ToPixel(u16 raw, s32 origin, s32 inv, int max)
{
    u16 v = (u16)((((s64)raw << kOriginShift) - origin) * inv >> (kInvShift + kOriginShift));
    if ((s16)v < 0) {
        return 0;
    }
    return (s16)v > max ? (u16)max : v;
}

} // namespace

extern "C" {

void TP_Init(void)
{
    if (sInitialized) {
        return;
    }
    sInitialized = true;
    sCallback = NULL;
    sState = TP_STATE_READY;
    sCalibrated = false;
    sBusy = 0;
    sError = 0;
}

BOOL TP_GetUserInfo(TPCalibrateParam *calibrate)
{
    const NVRAMConfigTpCalibData &tp = ((const NVRAMConfig *)OS_GetSystemWork()->nvramUserInfo)->ncd.tp;
    if ((tp.raw_x1 == 0 && tp.raw_x2 == 0 && tp.raw_y1 == 0 && tp.raw_y2 == 0)
        || TP_CalcCalibrateParam(calibrate, tp.raw_x1, tp.raw_y1, tp.dx1, tp.dy1, tp.raw_x2, tp.raw_y2, tp.dx2, tp.dy2)
            != 0) {
        calibrate->x0 = 0;
        calibrate->y0 = 0;
        calibrate->xDotSize = 0;
        calibrate->yDotSize = 0;
    }
    return TRUE;
}

u32 TP_CalcCalibrateParam(TPCalibrateParam *calibrate, u16 raw_x1, u16 raw_y1, u16 dx1, u16 dy1, u16 raw_x2,
    u16 raw_y2, u16 dx2, u16 dy2)
{
    if (raw_x1 >= kRawMax || raw_y1 >= kRawMax || raw_x2 >= kRawMax || raw_y2 >= kRawMax) {
        return 1;
    }
    if (dx1 >= GX_LCD_SIZE_X || dx2 >= GX_LCD_SIZE_X || dy1 >= GX_LCD_SIZE_Y || dy2 >= GX_LCD_SIZE_Y) {
        return 1;
    }
    if (dx1 == dx2 || dy1 == dy2 || raw_x1 == raw_x2 || raw_y1 == raw_y2) {
        return 1;
    }
    // Like the SDK, the x results are stored before y is checked
    if (!CalcAxis(raw_x1, raw_x2, dx1, dx2, &calibrate->x0, &calibrate->xDotSize)) {
        return 1;
    }
    if (!CalcAxis(raw_y1, raw_y2, dy1, dy2, &calibrate->y0, &calibrate->yDotSize)) {
        return 1;
    }
    return 0;
}

void TP_SetCalibrateParam(const TPCalibrateParam *param)
{
    if (param == NULL) {
        sCalibrated = false;
        return;
    }
    OSIntrMode enabled = OS_DisableInterrupts();
    SetAxis(param->x0, param->xDotSize, &sCal.x0, &sCal.xDotSize, &sCal.xDotSizeInv);
    SetAxis(param->y0, param->yDotSize, &sCal.y0, &sCal.yDotSize, &sCal.yDotSizeInv);
    (void)OS_RestoreInterrupts(enabled);
    sCalibrated = true;
}

void TP_SetCallback(TPRecvCallback callback)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    sCallback = callback;
    (void)OS_RestoreInterrupts(enabled);
}

void TP_RequestSamplingAsync(void)
{
    SDK_ASSERT(!(sBusy & TP_REQUEST_COMMAND_FLAG_SAMPLING));
    OSIntrMode enabled = OS_DisableInterrupts();
    sBusy |= TP_REQUEST_COMMAND_FLAG_SAMPLING;
    sError &= ~TP_REQUEST_COMMAND_FLAG_SAMPLING;
    (void)OS_RestoreInterrupts(enabled);

    // The ARM7 measures and replies
    ntros::Input_SampleTouch();
    SPITpData data;
    memcpy(data.bytes, OS_GetSystemWork()->touch_panel, sizeof(data.bytes));
    sResult.x = (u16)data.e.x;
    sResult.y = (u16)data.e.y;
    sResult.touch = (u16)data.e.touch;
    sResult.validity = (u16)data.e.validity;
    sState = TP_STATE_READY;
    sBusy &= ~TP_REQUEST_COMMAND_FLAG_SAMPLING;
    if (sCallback != NULL) {
        sCallback(TP_REQUEST_COMMAND_SAMPLING, TP_RESULT_SUCCESS, 0);
    }
}

u32 TP_WaitRawResult(TPData *result)
{
    TP_WaitBusy(TP_REQUEST_COMMAND_FLAG_SAMPLING);
    if (sError & TP_REQUEST_COMMAND_FLAG_SAMPLING) {
        return 1;
    }
    *result = sResult;
    return 0;
}

u32 TP_GetCalibratedResult(TPData *result)
{
    if (sError & TP_REQUEST_COMMAND_FLAG_SAMPLING) {
        return 1;
    }
    *result = sResult;
    TP_GetCalibratedPoint(result, result);
    return 0;
}

u32 TP_WaitCalibratedResult(TPData *result)
{
    TP_WaitBusy(TP_REQUEST_COMMAND_FLAG_SAMPLING);
    return TP_GetCalibratedResult(result);
}

void TP_GetCalibratedPoint(TPData *disp, const TPData *raw)
{
    if (!sCalibrated) {
        *disp = *raw;
        return;
    }
    disp->touch = raw->touch;
    disp->validity = raw->validity;
    if (raw->touch == 0) {
        disp->x = 0;
        disp->y = 0;
        return;
    }
    // raw may be disp: read both before writing
    u16 x = ToPixel(raw->x, sCal.x0, sCal.xDotSizeInv, GX_LCD_SIZE_X - 1);
    u16 y = ToPixel(raw->y, sCal.y0, sCal.yDotSizeInv, GX_LCD_SIZE_Y - 1);
    disp->x = x;
    disp->y = y;
}

void TP_GetUnCalibratedPoint(u16 *raw_x, u16 *raw_y, u16 dx, u16 dy)
{
    if (!sCalibrated) {
        *raw_x = dx;
        *raw_y = dy;
        return;
    }
    *raw_x = (u16)((((s32)(dx * sCal.xDotSize) >> (kDotShift - kOriginShift)) + sCal.x0) >> kOriginShift);
    *raw_y = (u16)((((s32)(dy * sCal.yDotSize) >> (kDotShift - kOriginShift)) + sCal.y0) >> kOriginShift);
}

// Requests complete when made: nothing is ever busy here
void TP_WaitBusy(TPRequestCommandFlag command_flgs)
{
    SDK_ASSERT(!(sBusy & command_flgs));
}

void TP_WaitAllBusy(void)
{
    SDK_ASSERT(sBusy == 0);
}

u32 TP_CheckBusy(TPRequestCommandFlag command_flgs)
{
    return (u32)(sBusy & command_flgs);
}

u32 TP_CheckError(TPRequestCommandFlag command_flgs)
{
    return (u32)(sError & command_flgs);
}

} // extern "C"
