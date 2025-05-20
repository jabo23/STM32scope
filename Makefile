DEVICE = STM32F767xI
FLASH  = 0x08000000

USE_ST_CMSIS = true

USE_DEBUG = true

# Include the main makefile
include ./STM32-base/make/common.mk
