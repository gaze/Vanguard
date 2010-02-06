#include <Kernel/Kernel.h>
#include <Kernel/VMMap.h>
#include <Kernel/Zone.h>
#include <Arch/Hat.h>

//Hat KernelHat;
VMObject KernelObject;
VMMapEntry PrelimMap;
VMMap KernelMap;

Zone *VMObjectZone;
Zone *VMMapZone;
Zone *VMMapEntryZone;

/* Bring up the VMMap module. It's a bit of a dance
 *
 * We create zones to support VMMap, but the zone allocator
 * doesn't have the VMMap subsystem. The zone allocator
 * thus creates the associated zones without the VMMap,
 * we create the kernel map, then we ask the zone allocator
 * to ask us to create the mappings it has created thus far.
 *
 * We have to create a reservation so that the allocator recurse
 * back into itself infinitely.
 *
 */

#define MAP_ENTRIES_MIN 3

void *VMMapAllocateExtent(VMMap *map, Size size, u32 flags){

	/* Ensure there are enough map entries reserved */

	if(VMMapEntryZone->FreeCount < MAP_ENTRIES_MIN &&
		!(flags & VMMAP_TAP_RESERVE)){
		
		/* Uhm... the swapper could potentially just reclaim this as
                 * we push further down. Have to consider that once that's
                 * written.
                 */
		ZoneAllocNewSlab(VMMapEntryZone);
	}

	/* If we're here, the slab has enough pages that it's okay. */

}

void VMMapStartupEarly(VAddr *kbreak){
	VMMapEntryZone = ZoneCreateEarly("VMMapEntry", sizeof(VMMapEntry), kbreak);
	VMMapObjectZone = ZoneCreateEarly("VMMapObject", sizeof(VMMapObject), kbreak);
	VMMapZone = ZoneCreateEarly("VMMapZone", sizeof(VMMapZone), kbreak);
}

void VMMapStartup(VAddr start, VAddr endUsed, VAddr end){
	KernelMap.Start = start;
	KernelMap.End   = end;

	KernelMap.Root.Next = (VMMapEntry *)0;
	KernelMap.Root.Prev = (VMMapEntry *)0;
	KernelMap.Root.Start = start;
	KernelMap.Root.End = end;
	KernelMap.Root.Object = &KernelObject;

	TAILQ_INIT(&KernelObject.pages);

	ZoneCreateMapEarly(&KernelMap, VMMapEntryZone);
}
