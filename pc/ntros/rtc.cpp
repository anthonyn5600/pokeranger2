// The SDK's real-time clock API (RTC_*), reading the clock as the ARM7 would: the DS clock holds the date and time
// the owner set; here it is the computer's local time ($NTR_RTC "YYYY-MM-DD HH:MM:SS" sets it at start instead; it
// runs on from there). Years count from 2000 (0..99). Reads complete at once. The date conversions work like the
// SDK's (days since 2000-01-01, every fourth year a leap year, ranges clamped the same way).
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ntros.h"

#include "internal.hpp"

namespace {

constexpr s32 kDaysBeforeMonth[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
constexpr s32 kLastDay = 36524; // 2099-12-31
constexpr s64 kLastSecond = (s64)kLastDay * 86400 + 86399;

bool sInitialized;
time_t sOffset; // set clock minus host clock, in seconds

bool IsLeap(u32 year)
{
    return (year & 3) == 0;
}

// The clock now, as broken-down local time
struct tm Now()
{
    time_t now = time(NULL) + sOffset;
    struct tm t;
#ifdef _WIN32
    localtime_s(&t, &now);
#else
    localtime_r(&now, &t);
#endif
    return t;
}

void ToDate(const struct tm &t, RTCDate *date)
{
    date->year = (u32)(t.tm_year % 100); // tm_year counts from 1900
    date->month = (u32)(t.tm_mon + 1);
    date->day = (u32)t.tm_mday;
    date->week = (RTCWeek)t.tm_wday;
}

void ToTime(const struct tm &t, RTCTime *time)
{
    time->hour = (u32)t.tm_hour;
    time->minute = (u32)t.tm_min;
    time->second = (u32)(t.tm_sec > 59 ? 59 : t.tm_sec); // no leap second on the DS
}

} // namespace

extern "C" {

void RTC_Init(void)
{
    if (sInitialized) {
        return;
    }
    sInitialized = true;
    const char *set = getenv("NTR_RTC");
    struct tm t = {};
    if (set != NULL) {
        if (sscanf(set, "%d-%d-%d %d:%d:%d", &t.tm_year, &t.tm_mon, &t.tm_mday, &t.tm_hour, &t.tm_min, &t.tm_sec) != 6) {
            OS_Panic("NTR_RTC: expected \"YYYY-MM-DD HH:MM:SS\", got \"%s\"", set);
        }
        t.tm_year -= 1900;
        t.tm_mon -= 1;
        t.tm_isdst = -1;
        sOffset = mktime(&t) - time(NULL);
    }
}

RTCResult RTC_GetDate(RTCDate *date)
{
    struct tm t = Now();
    ToDate(t, date);
    return RTC_RESULT_SUCCESS;
}

RTCResult RTC_GetTime(RTCTime *time)
{
    struct tm t = Now();
    ToTime(t, time);
    return RTC_RESULT_SUCCESS;
}

RTCResult RTC_GetDateTime(RTCDate *date, RTCTime *time)
{
    struct tm t = Now();
    ToDate(t, date);
    ToTime(t, time);
    return RTC_RESULT_SUCCESS;
}

s32 RTC_ConvertDateToDay(const RTCDate *date)
{
    if (date->year >= 100 || date->month < 1 || date->month > 12 || date->day < 1 || date->day > 31
        || date->week >= RTC_WEEK_MAX) {
        return -1;
    }
    s32 day = (s32)(date->day - 1) + kDaysBeforeMonth[date->month - 1];
    if (date->month >= 3 && IsLeap(date->year)) {
        day++;
    }
    // 365 days a year, plus a day for each leap year before this one (2000, 2004, ...)
    return day + (s32)(date->year * 365 + (date->year + 3) / 4);
}

void RTC_ConvertDayToDate(RTCDate *date, s32 day)
{
    day = day < 0 ? 0 : day > kLastDay ? kLastDay
                                       : day;
    date->week = (RTCWeek)((day + 6) % 7); // 2000-01-01 was a Saturday
    u32 year = 0;
    for (; year < 99; year++) {
        s32 length = IsLeap(year) ? 366 : 365;
        if (day < length) {
            break;
        }
        day -= length;
    }
    if (day > 365) {
        day = 365;
    }
    date->year = year;
    if (IsLeap(year)) {
        if (day < 31 + 29) {
            date->month = day < 31 ? 1 : 2;
            date->day = (u32)(day < 31 ? day + 1 : day - 31 + 1);
            return;
        }
        day--; // count the rest as in a common year
    }
    int month = 11;
    while (day < kDaysBeforeMonth[month]) {
        month--;
    }
    date->month = (u32)(month + 1);
    date->day = (u32)(day - kDaysBeforeMonth[month] + 1);
}

s64 RTC_ConvertDateTimeToSecond(const RTCDate *date, const RTCTime *time)
{
    s32 day = RTC_ConvertDateToDay(date);
    if (day == -1) {
        return -1;
    }
    return (s64)day * 86400 + (s64)((time->hour * 60 + time->minute) * 60 + time->second);
}

void RTC_ConvertSecondToDateTime(RTCDate *date, RTCTime *time, s64 sec)
{
    sec = sec < 0 ? 0 : sec > kLastSecond ? kLastSecond
                                          : sec;
    s32 inDay = (s32)(sec % 86400);
    time->second = (u32)(inDay % 60);
    time->minute = (u32)(inDay / 60 % 60);
    time->hour = (u32)(inDay / 3600);
    RTC_ConvertDayToDate(date, (s32)(sec / 86400));
}

// From year, month and day (the week field is ignored)
RTCWeek RTC_GetDayOfWeek(RTCDate *date)
{
    RTCDate d = *date;
    d.week = RTC_WEEK_SUNDAY;
    s32 day = RTC_ConvertDateToDay(&d);
    return day < 0 ? RTC_WEEK_SUNDAY : (RTCWeek)((day + 6) % 7);
}

} // extern "C"
