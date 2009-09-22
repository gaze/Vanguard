/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

/*
	 The x86 hardware address translation layer
*/

#include <sys/types.h>
#include <Kernel/Queue.h>
#include <Kernel/Hat.h>

typedef struct HatI386_s {
	bool kernel;   // i386 has a split mapping scheme
	
//	SLIST_ENTRY(HatI386_s) HatLink;
} HatI386;

typedef HatI386* hHatI386;

//SLIST_HEAD(user_hat_list, i386_hat);

typedef int pde;
typedef int pte;

pde initPD[1024] __attribute__((aligned(4096)));
pte initPT[1024] __attribute__((aligned(4096)));

hHat HatNew(bool kernel){
	hHatI386 h;
	
	return (hHat *)h;
}

void HatFree(hHat hat){
	hHatI386 *h = (hHatI386 *)hat;
	
}

void *AllocEarly(u32 len){

}

static const struct HatOps hatOpsI386 = {
        .HatNew = HatNew,
	.HatFree = HatFree,
	.AllocEarly = AllocEarly,
};

int HatInitI386(void *kernBase, void *kernEnd){
//	VMSetActiveHat(hatOpsI386);

//	SLIST_INIT(user_hat_list);
}
