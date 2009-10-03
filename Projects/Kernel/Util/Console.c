/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#include <Kernel/Console.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

// I would like to have a chain of loggers at one point,
// that way you could have userspace loggers... serial consoles
// whatever.

static struct ConsoleOps *console;

void ConsolePuts(char *str){
	while(*str != '\0'){
		console->Putchar(*str);
		str++;
	}
}

void ConsolePutchar(char c){
	console->Putchar(c);
}

void ConsoleAdd(struct ConsoleOps * new){
	console = new;
}

static void
putchar(int c, void *arg)
{
	ConsolePutchar(c);
}

int
printf(const char *fmt, ...)
{
	va_list ap;
	int retval;

	va_start(ap, fmt);
	retval = vprintf(fmt, ap);
	va_end(ap);

	return (retval);
}

int
vprintf(const char *fmt, va_list ap)
{
	int retval;

	retval = UtilKvprintf(fmt, putchar, NULL, 10, ap);

	return (retval);
}
