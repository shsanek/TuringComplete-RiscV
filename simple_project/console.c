/*
 * console.c
 *
 * Copyright (C) 2019-2021 Sylvain Munaut
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

#include "mini-printf.h"

#define CONSOLE    0x40000000
#define CONSOLE_H  20
#define CONSOLE_W  80

static volatile char* const console = (volatile char*) CONSOLE;

static int cur_x = 0;
static int cur_y = 0;

void scroll_console(int shift) {
    for (int y = shift; y < CONSOLE_H; y++) {
        for (int x = 0; x < CONSOLE_W; x++) {
            console[(y - shift) * CONSOLE_W + x] = console[y * CONSOLE_W + x];
        }
    }
	for (int i = 0; i < shift; i ++) {
		for (int x = 0; x < CONSOLE_W; x++) {
			console[(CONSOLE_H - i) * CONSOLE_W + x] = ' ';
		}
	}
    cur_y = CONSOLE_H - shift;
    cur_x = 0;
}

void console_putchar(char c)
{
    if (c == '\n') {
        cur_x = 0;
        cur_y++;
    } else {
        console[cur_y * CONSOLE_W + cur_x] = c;
        cur_x++;
        if (cur_x >= CONSOLE_W) {
            cur_x = 0;
            cur_y++;
        }
    }

    if (cur_y >= CONSOLE_H) {
        scroll_console(3);
    }
}

void console_puts(const char *p)
{
    char c;
    while ((c = *(p++)) != 0x00)
        console_putchar(c);
}

void
console_init(void)
{
    for (int y = 0; y < CONSOLE_H; y++) {
        for (int x = 0; x < CONSOLE_W; x++) {
            console[y  * CONSOLE_W + x] = 0;
        }
    }
}

char
console_getchar(void)
{
	return -1;
}

int
console_getchar_nowait(void)
{
	return -1;
}

int
console_printf(const char *fmt, ...)
{
	static char _printf_buf[128];
        va_list va;
        int l;

        va_start(va, fmt);
        l = mini_vsnprintf(_printf_buf, 128, fmt, va);
        va_end(va);

	console_puts(_printf_buf);

	return l;
}
