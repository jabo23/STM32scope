#ifndef DEBUG_H
#define DEBUG_H

#include "../../../STM32-base-STM32Cube/CMSIS/STM32F7xx/inc/stm32f767xx.h"

#include <stdint.h>
#include <stddef.h>

void debug_init(void);
void debug_write(char * data, size_t len);

#endif