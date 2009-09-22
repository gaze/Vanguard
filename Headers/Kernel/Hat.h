/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#ifndef _KERNEL_HAT_H
#define _KERNEL_HAT_H

#include <sys/types.h>

// hat_t is an opaque handle
typedef void * hHat;

struct HatOps {
	hHat (*HatNew)(bool);
	void (*HatFree)(hHat);
	void * (*AllocEarly)();
	void (*HatBoot)();
	void (*HatActivate)();
};
#endif
