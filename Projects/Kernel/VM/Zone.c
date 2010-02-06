#include <Kernel/Kernel.h>
#include <Kernel/Zone.h>
#include <Kernel/Queue.h>
#include <Kernel/VMMap.h>

/* A zone is a collection of slabs.
 *
 * A slab can hold small items or large items. The slab header is on the top
 * of the page for small slabs, and or is held in a small slab.
 */

#define PAGE_SIZE 4096

#define SANITY_CHECKS

#define SLAB_FULL ((void *)0x0000f4cd)

#define SLAB_MAX_ITEMS(z) ((PAGE_SIZE-sizeof(Slab))/((z)->ObjSize))

Zone ZoneZoneStore;
Zone *ZoneZone;

static void *ItemFromZone(Zone *z, Slab *s, u32 index){
	void *p = (void *)((VAddr)s + sizeof(Slab));

#ifdef SANITY_CHECKS
	// Make sure we're inside the slab
	// XXX Shit... are we off by one?
	if(index > SLAB_MAX_ITEMS(z))
		panic("Outsize Slab!\n");
#endif

	p += index * z->ObjSize;

	return p;
}


#define SLAB_FREE (void *)0x00000000

static void SlabNew(Zone *z, Slab *s){
	int i;
	
	void *lastFree = SLAB_FREE;

	z->FreeCount = 0;

	for(i=0;i<SLAB_MAX_ITEMS(z);i++){
		VAddr *obj = (VAddr *)ItemFromZone(z,s,i);
		*obj = lastFree;
		lastFree = obj;
		z->FreeCount++;
	}

	s->FreeQueue = lastFree;

	TAILQ_INSERT_HEAD(&z->EmptyList, s, Queue);
}

void ZoneInitInternal(Zone *z, char *name, Size size){
	int i;

	//strncpy(z->name, name, 512);
	TAILQ_INIT(&z->EmptyList);
	TAILQ_INIT(&z->FullList);
	TAILQ_INIT(&z->PartialList);

	z->ObjSize = size;
}

static Slab *ZoneGetSlabWillAllocate(Zone *z){
	Slab *s;

	if(!TAILQ_EMPTY(&z->PartialList)){
		s = TAILQ_FIRST(&z->PartialList);
	} else if (!TAILQ_EMPTY(&z->EmptyList)){
		// There's no partially used page
		// This allocation will complete since the page is
		// empty.

		s = TAILQ_FIRST(&z->EmptyList);
		TAILQ_REMOVE(&z->PartialList, s, Queue);
		TAILQ_INSERT_HEAD(&z->PartialList, s, Queue);
	} else
		s = (Slab *)0;

	return s;
}

void *ZoneAllocEarly(Zone *z, VAddr *kbreak){
	Slab *s = ZoneGetSlabWillAllocate(z);
	void *item;

	if(s == (Slab *)0){
		// Aw. No slabs. Create one!
		*kbreak += PAGE_SIZE;
		s = (void *)(*kbreak);
		SlabNew(z, s);
	}

	item = s->FreeQueue;
	s->FreeQueue = *(VAddr *)(s->FreeQueue);

	if(s->FreeQueue = SLAB_FULL)
		panic("Slab is full. G'day!\n");
}

void ZoneStartup(){
	/* Yo dawg, I herd u leik zones... */

	ZoneZone = &ZoneZoneStore;

	ZoneInitInternal(ZoneZone, "Zones", sizeof(Zone));
}

void ZoneCreateMapEarly(VMMap *vmm, Zone *VMMapEntryZone){
	panic("UNIMPLEMENTED ZoneCreateMapEarly");	
}

Zone * ZoneCreateEarly(char * name, Size size, VAddr *kbreak){
	Zone *z = (Zone *)ZoneAllocEarly(ZoneZone, kbreak);
	ZoneInitInternal(z, name, size);
	return z;
}

Zone * ZoneCreate(char * name, Size size){
	panic("UNIMPLEMENTED ZoneCreate");
}

void ZoneAllocNewSlab(Zone *VMMapEntryZone){
	panic("UNIMPLEMENTED ZoneAllocNewSlab");
}
