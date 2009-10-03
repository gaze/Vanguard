/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#include <Kernel/Kernel.h>
#include <Kernel/VMPage.h>
#include <stdio.h>

/* Grub multiboot header */
#include "multiboot.h"

void IntelConsoleInit();

/* Throw this somewhere */
#define alloca(x) __builtin_alloca(x)

extern void* end;

int Init386(u32 mb_info, u32 mb_magic)
{

   struct grub_multiboot_info *mbi = (struct grub_multiboot_info *)(mb_info);
   void *kbreak = end;

   IntelConsoleInit();   
   
   if(mb_magic != 0x2badb002){
      panic("Kernel loaded by non-multiboot compliant bootloader!\n");
   }

   printf("Vanguard x86\n");
   
   {
      struct grub_multiboot_mmap_entry *ent 
         = (struct grub_multiboot_mmap_entry *)mbi->mmap_addr;
      
      for(; ent < (struct grub_multiboot_mmap_entry *)
         (mbi->mmap_addr + mbi->mmap_length);
         ent = (struct grub_multiboot_mmap_entry *)
            ((u32) ent + ent->size + sizeof(ent->size))){

         if(ent->type == GRUB_MULTIBOOT_MEMORY_RESERVED)
            continue;

         u32 sectBase, sectEnd;

         /* XXX Will be fucked if handed a 64-bit addr by grub,
                    this truncates */

         sectBase = ent->addr;
         sectEnd = ent->addr+ent->len;

         kbreak = VMPageAddFree(kbreak, sectBase, sectEnd);
      }
   }

   VMPagePrintStats();

   I386HatInit();

   panic("End.\n");
}
