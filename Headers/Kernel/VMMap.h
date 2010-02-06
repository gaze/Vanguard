/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */
#ifndef _KERNEL_VMMAP_H
#define _KERNEL_VMMAP_H

#include <OS/Types.h>
#include <Kernel/VMObject.h>
#include <Kernel/Queue.h>
#include <Arch/Hat.h>

/* A VMMap covers a certain area of virtual address
 * space. */

#define VMMAP_ENT_READ 0x1
#define VMMAP_ENT_WRITE 0x2
#define VMMAP_ENT_EXEC 0x4
#define VMMAP_ENT_SUBMAPPED 0x8
#define VMMAP_ENT_UNBACKED 0x10

typedef struct VMMapEntry {
	struct VMMapEntry *Next;
	struct VMMapEntry *Prev;
	VAddr Start;
	VAddr End;
	VMObject *Object;

	u32 flags;
} VMMapEntry;

typedef struct {
	VAddr Start;
	VAddr End;
	VMMapEntry Root;
	//Hat *Hat;
} VMMap;

#define VMMAP_TAP_RESERVE 0x1

#endif
