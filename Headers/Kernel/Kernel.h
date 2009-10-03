/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#ifndef _KERNEL_KERNEL_H

#include <stdio.h>

#define KERNEL

#define panic(...) do{ \
   printf("panic: " __VA_ARGS__); \
   for(;;); \
}while(0);

#endif
