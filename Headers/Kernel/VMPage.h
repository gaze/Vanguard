/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */
#ifndef _KERNEL_VMPAGE_H
#define _KERNEL_VMPAGE_H

#include <OS/Types.h>

typedef struct VMPage_s {
	TAILQ_ENTRY(VMPage_s) Pageq;
	PAddr Phys;
	VAddr Offset; // Offset into the VMO
} VMPage;


#endif
