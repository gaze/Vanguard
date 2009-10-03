/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#include <Kernel/Kernel.h>
#include <Kernel/Hat.h>
#include <Kernel/VMPage.h>

/* Define this to be the max number of VM regions the loader will hand us.
     We keep regions around for quick lookups */
#define MAX_REGIONS 25

static TAILQ_HEAD(, VMPage) freeList = TAILQ_HEAD_INITIALIZER(freeList);
static TAILQ_HEAD(, VMPage) usedList = TAILQ_HEAD_INITIALIZER(usedList);

PAddr physFree = 0;

struct {
   PAddr RegionStart;
   PAddr RegionEnd;
   VMPage *Page;
} Regions[MAX_REGIONS];
u32 lastRegion = 0;

#define PAGE_ROUNDUP(x) x
#define PAGE_ROUNDDN(x) x
#define PAGE_SIZE 4096

static void VMPagePushToFree(VMPage *vmp){
   TAILQ_INSERT_HEAD(&freeList,vmp,Pageq);
   physFree += PAGE_SIZE;
}

void VMPagePrintStats(){
   printf("Free Memory: %i K\n", physFree/1024);
}

void * VMPageAddFree(void * base, PAddr freeBegin, PAddr freeEnd){
   if(lastRegion > MAX_REGIONS){
      panic("Please increase MAX_REGIONS");
   }
   
   Regions[lastRegion].RegionStart = freeBegin;
   Regions[lastRegion].RegionEnd = freeEnd;
   Regions[lastRegion].Page = (VMPage *)base;
   lastRegion++;

   PAddr idx = PAGE_ROUNDUP(freeBegin);
   VMPage *vmp = (VMPage *)base;

   while(idx < freeEnd){
      vmp->Phys = idx;
      vmp->Offset = VMPAGE_LONE;
      VMPagePushToFree(vmp);
      
      idx += PAGE_SIZE;
      
      vmp++;
   }
   printf("VMPage: 0x%x-0x%x available\n", freeBegin, freeEnd);

}
