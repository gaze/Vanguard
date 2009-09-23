/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#include <string.h>
#include <stddef.h>

#include <OS/Types.h>

char * strcpy(char *restrict s1, const char *restrict s2){
	while(*s1++ = *s2++)
		;;
}

size_t strlen(const char *s){
	size_t len;

	while(*s++) len++;

	return len;
}
