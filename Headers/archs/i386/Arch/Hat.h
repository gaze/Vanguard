/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#ifndef _ARCH_KERNEL_HAT_H
#define _ARCH_KERNEL_HAT_H

#include <Kernel/Queue.h>

struct Hat {
	bool kernel;
	SLIST_ENTRY(Hat) HatLink;
};


#endif
