/*
 * i_video.c
 *
 * Video system support code
 *
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

#include <stdint.h>
#include <string.h>
#include <stdint.h>

#include "doomdef.h"

#include "i_system.h"
#include "v_video.h"
#include "i_video.h"

#include "config.h"


void
I_InitGraphics(void)
{
	/* Don't need to do anything really ... */

	/* Ok, maybe just set gamma default */
	usegamma = 1;
}

void
I_ShutdownGraphics(void)
{
	/* Don't need to do anything really ... */
}


void
I_SetPalette(byte* palette)
{
	static volatile uint32_t * const video_pal = (void*)(VID_PAL_BASE);
	byte r, g, b;

	for (int i=0 ; i<256 ; i++) {
		r = gammatable[usegamma][*palette++];
		g = gammatable[usegamma][*palette++];
		b = gammatable[usegamma][*palette++];
		video_pal[i] = (((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b) << 8;
	}
}


void
I_UpdateNoBlit(void)
{
}

void
I_FinishUpdate (void)
{
	_memcpy(
		(void*)VID_FB_BASE,
		screens[0],
		SCREENHEIGHT * SCREENWIDTH
	);
}


void
I_WaitVBL(int count)
{
}


void
I_ReadScreen(byte* scr)
{
	_memcpy(
		scr,
		screens[0],
		SCREENHEIGHT * SCREENWIDTH
	);
}


#if 0	/* WTF ? Not used ... */
void
I_BeginRead(void)
{
}

void
I_EndRead(void)
{
}
#endif
