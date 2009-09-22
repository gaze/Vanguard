#define MULTIBOOT_HEADER_MAGIC 0x1BADB002
#define MULTIBOOT_HEADER_FLAGS 0x00000003


#define KERNBASE        0xC0000000
#define KERNLOAD        0x100000
#define VIDMEM  0xb8000

#define END end
#define STACK END
#define PAGEMAP END+0x2000

/*#include "locations.h"*/

#define ASM     1

/*
        We're gonna shove the provisional
        page table at the end of memory.
        Then once the memory manager starts,
        we create a real page table, and push
        the memory the provisional page table
        takes up onto the free page stack
*/
                
#define R(addr) (addr-KERNBASE)

        .data


        .text

        /* Multiboot header.  */
multiboot_header:
        /* magic */
        .long   MULTIBOOT_HEADER_MAGIC
        /* flags */
        .long   MULTIBOOT_HEADER_FLAGS
        /* checksum */
        .long   -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

        .globl  start, _start

        /* Align 32 bits boundary.  */
        .align  4
        
start:
_start:

        /* PAGE TABLE */
        
        /* Page directory is 1024 big */
        mov $0x400, %ecx

        /* End is the end of the kernel, page aligned, set in linker */ 
        movl $3, R(END)
pt_fill:
        mov %ecx, %eax
        sub $1, %eax
        shl $12, %eax
        or $3, %eax
        mov %eax, R(initPT-4)(,%ecx,4)
        loop pt_fill


        /* PAGE DIRECTORY */

        /* Page table is 1024 big */
        mov $0x400, %ecx

        mov $R(initPT), %eax
        or $3, %eax
pd_fill:
        mov %eax, R(initPD-4)(,%ecx,4)
        loop pd_fill


        /* TURN PAGING ON */
        
        mov $R(initPD), %ecx
        mov %ecx, %cr3

        mov %cr0, %ecx
        or $0x80000000,%ecx

        mov %ecx, %cr0  /* Here we go! */

        lea higherhalf, %ecx
        jmp *%ecx

higherhalf:
        push %ebx
        call Init386
        
safety_net:
				jmp safety_net
