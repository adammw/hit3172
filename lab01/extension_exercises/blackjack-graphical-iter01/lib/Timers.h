/*
* Generated by SGWrapperGen - DO NOT EDIT!
*
* SwinGame wrapper for C - Timers
*
* Wrapping sgTimers.pas
*/

#ifndef sgTimers
#define sgTimers

#include <stdbool.h>
#include <stdint.h>

#include "Types.h"

timer create_timer();
timer create_timer_named(const char *name);
void free_timer(timer *toFree);
void pause_timer(timer toPause);
void release_all_timers();
void release_timer(const char *name);
void reset_timer(timer tmr);
void resume_timer(timer toUnpause);
void start_timer(timer toStart);
void stop_timer(timer toStop);
timer timer_named(const char *name);
uint32_t timer_ticks(timer toGet);

#ifdef __cplusplus
// C++ overloaded functions
timer create_timer(const char *name);
void free_timer(timer &toFree);

#endif

#endif
