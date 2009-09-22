/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#include <Kernel/Console.h>

// I would like to have a chain of loggers at one point,
// that way you could have userspace loggers... serial consoles
// whatever.

static struct ConsoleOps *console;

int ConsolePuts(char *str){
	console->Puts(str);
}

int ConsoleAdd(struct ConsoleOps * new){
	console = new;
}
