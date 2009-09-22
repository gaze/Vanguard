/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#define KERNBASE        0xC0000000
#define KERNLOAD        0x100000
#define VIDMEM  0xb8000

#ifndef __ASM__
extern long *end;
#define END &end
#else
#define END end
#endif

#define PAGE_SIZE 4096


#define STACK END
#define PAGEMAP END+0x2000
