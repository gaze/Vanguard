/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#ifndef _STRING_H
#define _STRING_H

#include <OS/Types.h>

char * strcpy(char *restrict s1, const char *restrict s2);
size_t strlen(const char *s);

#define toupper(c)      ((c) - 0x20 * (((c) >= 'a') && ((c) <= 'z')))
#define tolower(c)      ((c) + 0x20 * (((c) >= 'A') && ((c) <= 'Z')))

#endif
