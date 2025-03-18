/*
 * i_system.c
 *
 * System support code
 *
 * Copyright (C) 1993-1996 by id Software, Inc.
 * Copyright (C) 2021 Sylvain Munaut
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doomdef.h"
#include "doomstat.h"

#include "d_main.h"
#include "g_game.h"
#include "m_misc.h"
#include "i_sound.h"
#include "i_video.h"

#include "i_system.h"

#include "console.h"
#include "config.h"


/* Video controller, used as a time base */
	/* Normally running at 70 Hz, although in 640x480 compat
	 * mode, it's 60 Hz so our tick is 15% too slow ... */
//static volatile uint32_t * const video_state = (void*)(VID_CTRL_BASE);

/* Video Ticks tracking */
static uint16_t vt_last = 0;
static uint16_t vt_next_time = 0;
static uint32_t vt_base = 0;


void
I_Init(void)
{
	vt_last = 0;
	vt_next_time = 0;
	//vt_last = video_state[0] & 0xffff;
}


byte *
I_ZoneBase(int *size)
{
	/* Give 6M to DOOM */
	*size = 6 * 1024 * 1024;
	return (byte *) malloc (*size);
}

int
I_GetTime(void)
{
	uint16_t vt_now = vt_next_time;

	if (vt_now < vt_last)
		vt_base += 65536;
	vt_last = vt_now;

	/* TIC_RATE is 35 in theory */
	return (vt_base + vt_now) >> 1;
}

static void
I_GetRemoteEvent(void)
{
	event_t event;

	const char map[] = {
		KEY_LEFTARROW,  // 0
		KEY_RIGHTARROW, // 1
		KEY_DOWNARROW,  // 2
		KEY_UPARROW,    // 3
		KEY_RSHIFT,     // 4
		KEY_RCTRL,      // 5
		KEY_RALT,       // 6
		KEY_ESCAPE,     // 7
		KEY_ENTER,      // 8
		KEY_TAB,        // 9
		KEY_BACKSPACE,  // 10
		KEY_PAUSE,      // 11
		KEY_EQUALS,     // 12
		KEY_MINUS,      // 13
		KEY_F1,         // 14
		KEY_F2,         // 15
		KEY_F3,         // 16
		KEY_F4,         // 17
		KEY_F5,         // 18
		KEY_F6,         // 19
		KEY_F7,         // 20
		KEY_F8,         // 21
		KEY_F9,         // 22
		KEY_F10,        // 23
		KEY_F11,        // 24
		KEY_F12,        // 25
	};

	int ch = console_getchar_nowait();

	if (ch == -1) {
		return;
	}

	printf("map input: %d\n", ch);
	event.type = ev_keydown;
	event.data1 = ch;
	D_PostEvent(&event);

	event.type = ev_keyup;
	event.data1 = ch;
	D_PostEvent(&event);
}

void
I_StartFrame(void)
{
	/* Nothing to do */
}

void
I_StartTic(void)
{
	I_GetRemoteEvent();
}

ticcmd_t *
I_BaseTiccmd(void)
{
	static ticcmd_t emptycmd;
	return &emptycmd;
}


void
I_Quit(void)
{
	D_QuitNetGame();
	M_SaveDefaults();
	I_ShutdownGraphics();
	*((int*)(0x64000008)) = 0;
}


byte *
I_AllocLow(int length)
{
	byte*	mem;
	mem = (byte *)malloc (length);
	//memset (mem,0,length);
	return mem;
}


void
I_Tactile
( int on,
  int off,
  int total )
{
	// UNUSED.
	on = off = total = 0;
}


void
I_Error(char *error, ...)
{
	va_list	argptr;

	// Message first.
	va_start (argptr,error);
	fprintf (stderr, "Error: ");
	vfprintf (stderr,error,argptr);
	fprintf (stderr, "\n");
	va_end (argptr);

	fflush( stderr );

	// Shutdown. Here might be other errors.
	if (demorecording)
		G_CheckDemoStatus();

	D_QuitNetGame ();
	I_ShutdownGraphics();

	*((int*)(0x64000008)) = -1;
}
