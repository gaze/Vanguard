/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */
#ifndef _KERNEL_VMOBJECT_H
#define _KERNEL_VMOBJECT_H

#include <OS/Types.h>
#include <Kernel/Queue.h>
#include <Arch/Hat.h>
#include <Kernel/VMPage.h>

typedef struct {
	TAILQ_HEAD(, VMPage) pages;
} VMObject;

#endif
