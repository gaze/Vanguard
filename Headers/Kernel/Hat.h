/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#ifndef _KERNEL_HAT_H
#define _KERNEL_HAT_H

#include <OS/Types.h>
#include <Arch/Hat.h>

typedef struct Hat *hHat;

/*
 * The HAT API
 */
hHat HatNew();
void HatFree(hHat);
void HatActivate(hHat);

void * AllocEarly();

#endif
