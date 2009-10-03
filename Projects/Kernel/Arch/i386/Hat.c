/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

/*
	 The x86 hardware address translation layer
*/

#include <OS/Types.h>
#include <Kernel/Queue.h>
#include <Kernel/Hat.h>

#include <stddef.h>

typedef int pde;
typedef int pte;

pde initPD[1024] __attribute__((aligned(4096)));
pte initPT[1024] __attribute__((aligned(4096)));

static SLIST_HEAD(, Hat) userHatList = SLIST_HEAD_INITIALIZER(userHatList);

/////// HAT API ////////

hHat HatNew(){
}

void HatFree(hHat hat){
}

void *AllocEarly(u32 len){
}

int I386HatInit(){
}
