OUTPUT_FORMAT("elf32-i386")
ENTRY(start)
virt = 0xC0000000; /* 3 gig */
phys = 0x100000; /* 1 meg */
SECTIONS
{   
    .text virt + phys : AT(phys)
    {   code = .;
	*(.mbhdr)
        *(.text)
        . = ALIGN(4096); 
    }
    .data :  AT(phys + (data - code))
    {   data = .;
         *(.data)
         . = ALIGN(4096); 
    }
    .bss :  AT(phys + (bss - code))
    {   bss = .;
        *(.bss)
        *(COMMON)
        . = ALIGN(4096); 
    }
    . = ALIGN(4096);
    end = .; 
}
