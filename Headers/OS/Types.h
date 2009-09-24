/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#ifndef _OS_TYPES_H
#define _OS_TYPES_H

typedef signed long long s64;
typedef signed int s32;

typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef u8 bool;

/* Defined PER MACHINE!!! */
typedef u32 PAddr;
typedef u32 VAddr;

/* Some BSD defs */

typedef u32 uint32_t;
typedef u8 uint8_t;
typedef u32 size_t;
typedef s32 ssize_t;

typedef u64 uintmax_t;
typedef s64 intmax_t;

typedef s64 quad_t;
typedef u64 u_quad_t;

typedef unsigned char u_char;
typedef unsigned int u_int;
typedef unsigned short u_short;
typedef unsigned long u_long;

typedef s32 intptr_t;
typedef u32 uintptr_t;

typedef s32 ptrdiff_t;

#endif
