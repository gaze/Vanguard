/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */
#ifndef _KERNEL_VMPAGE_H
#define _KERNEL_VMPAGE_H

#include <OS/Types.h>
#include <Kernel/Queue.h>

typedef struct VMPage {
	TAILQ_ENTRY(VMPage) Pageq;
	PAddr Phys;
	VAddr Offset; // Offset into the VMO
} VMPage;

#define VMPAGE_LONE ((VAddr)0)

void VMPagePrintStats();
void * VMPageAddFree(void * base, PAddr freeBegin, PAddr freeEnd);


#endif
