/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */
#ifndef _KERNEL_ZONE_H
#define _KERNEL_ZONE_H

#include <OS/Types.h>
#include <Kernel/Queue.h>
#include <Kernel/VMMap.h>

typedef struct Slab {
	void *FreeQueue;
	TAILQ_ENTRY(Slab) Queue;
} Slab;

typedef struct {
	Size ObjSize;
	char Name[512];
	u32 FreeCount;
	TAILQ_HEAD(, Slab) EmptyList;
	TAILQ_HEAD(, Slab) PartialList;
	TAILQ_HEAD(, Slab) FullList;
} Zone;

Zone * ZoneCreate(char * name, Size size);
void ZoneCreateMapEarly(VMMap *vmm, Zone *VMMapEntryZone);

/* Used for whacking the zone back open again early */
void ZoneAllocNewSlab(Zone *VMMapEntryZone);

void ZoneStartup();

#endif
