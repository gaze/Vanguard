/* multiboot.h - multiboot header file with grub definitions. */
/*
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2003,2007,2008  Free Software Foundation, Inc.
 *
 *  GRUB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GRUB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GRUB.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GRUB_MULTIBOOT_HEADER
#define GRUB_MULTIBOOT_HEADER 1

#include <OS/Types.h>

struct grub_multiboot_info
{
  /* Multiboot info version number */
  u32 flags;

  /* Available memory from BIOS */
  u32 mem_lower;
  u32 mem_upper;

  /* "root" partition */
  u32 boot_device;

  /* Kernel command line */
  u32 cmdline;

  /* Boot-Module list */
  u32 mods_count;
  u32 mods_addr;

  u32 syms[4];

  /* Memory Mapping buffer */
  u32 mmap_length;
  u32 mmap_addr;

  /* Drive Info buffer */
  u32 drives_length;
  u32 drives_addr;

  /* ROM configuration table */
  u32 config_table;

  /* Boot Loader Name */
  u32 boot_loader_name;

  /* APM table */
  u32 apm_table;

  /* Video */
  u32 vbe_control_info;
  u32 vbe_mode_info;
  u16 vbe_mode;
  u16 vbe_interface_seg;
  u16 vbe_interface_off;
  u16 vbe_interface_len;
};

struct grub_multiboot_mmap_entry
{
  u32 size;
  u64 addr;
  u64 len;
#define GRUB_MULTIBOOT_MEMORY_AVAILABLE		1
#define GRUB_MULTIBOOT_MEMORY_RESERVED		2
  u32 type;
} __attribute__((packed));

struct grub_mod_list
{
  /* the memory used goes from bytes 'mod_start' to 'mod_end-1' inclusive */
  u32 mod_start;
  u32 mod_end;

  /* Module command line */
  u32 cmdline;

  /* padding to take it to 16 bytes (must be zero) */
  u32 pad;
};

#endif
