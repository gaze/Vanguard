/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#ifndef _STDIO_H
#define _STDIO_H

#include <stdarg.h>
#include <OS/Types.h>

int printf(const char *restrict format, ...);

int snprintf(char *restrict s, size_t n, const char *restrict format, ...);

int sprintf(char *restrict s, const char *restrict format, ...);

int vprintf(const char *restrict format, va_list ap);

int vsnprintf(char *restrict s, size_t n, const char *restrict format, va_list ap);

#endif
