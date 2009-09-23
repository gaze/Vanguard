/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#include <Kernel/Hat.h>
#include <Kernel/Console.h>

static SLIST_HEAD(, VMPage_s) freeList = SLIST_HEAD_INITIALIZER(freeList);
static SLIST_HEAD(, VMPage_s) usedList = SLIST_HEAD_INITIALIZER(usedList);

void * VMPageAddFree(void * base, PAddr freeBegin, PAddr *freeEnd){

}
