/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

/*
	 Nearly everything is statically allocated near the beginning.
	 Anything that is provisional to the kernel starting up, but
	 can be freed later on is put in a page aligned linker section
	 called "discardable", which after booting is freed to the free
	 page queues and left mappable. The only thing that's dynamically
	 allocated after kernel startup are the vm_page structs to track
	 memory. Post boot vm looks like this

	                       V Kernel    V Kernel break
         +---------------------------------------------+
	 |                     |     |     |           |
	 +---------------------------------------------+
                               ^ vm_pages

         The kernel break is set directly after the kernel, and we extend
	 the break for vm_pages. To do this, the first thing we do is
	 get the hat started asap
*/

#include <Kernel/Console.h>

void IntelConsoleInit();

int Init386()
{
   IntelConsoleInit();
   ConsolePuts("Vanguard x86\n");
}
