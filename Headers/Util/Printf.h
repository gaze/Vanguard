/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#ifndef _UTIL_PRINTF_H
#define _UTIL_PRINTF_H

#include <stdarg.h>

int UtilKvprintf(char const *fmt, void (*func)(int, void*), void *arg, int radix, va_list ap);


#endif
