/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

struct ConsoleOps {
	int (*Puts)(char *);
};

/* We only currently support one logger. */
int ConsoleAdd (struct ConsoleOps *);
int ConsolePuts (char *);
