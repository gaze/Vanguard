/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#ifndef _KERNEL_CONSOLE_H
#define _KERNEL_CONSOLE_H

struct ConsoleOps {
	int (*Putchar)(char);
};

/* We only currently support one logger. */
void ConsoleAdd (struct ConsoleOps *);
void ConsolePuts (char *);
void ConsolePutchar (char);

#endif
