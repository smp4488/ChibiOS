# Required platform files.
PLATFORMSRC := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               $(CHIBIOS)/os/hal/ports/SN32/SN32F240/hal_lld.c

# Required include directories.
PLATFORMINC := $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               $(CHIBIOS)/os/hal/ports/SN32/SN32F240

# Optional platform files.
ifeq ($(USE_SMART_BUILD),yes)
HALCONF := $(strip $(shell cat halconf.h | egrep -e "\#define"))

# ifneq ($(findstring HAL_USE_EXT TRUE,$(HALCONF)),)
# PLATFORMSRC += $(CHIBIOS)/os/hal/ports/SN32/SN32F240/hal_ext_lld_isr.c
# endif
# else
# PLATFORMSRC += $(CHIBIOS)/os/hal/ports/SN32/SN32F240/hal_ext_lld_isr.c
endif

# Drivers compatible with the platform.
include $(CHIBIOS)/os/hal/ports/SN32/LLD/GPIO/driver.mk
include $(CHIBIOS)/os/hal/ports/SN32/LLD/USB/driver.mk
include $(CHIBIOS)/os/hal/ports/SN32/LLD/CT/driver.mk


# include $(CHIBIOS)/os/hal/ports/SN32/LLD/TIM/driver.mk
# include $(CHIBIOS)/os/hal/ports/SN32/LLD/GPIOv3/driver.mk
# include $(CHIBIOS)/os/hal/ports/SN32/LLD/USBv1/driver.mk
# include $(CHIBIOS)/os/hal/ports/SN32/LLD/TIMv1/driver.mk

# PLATFORMINC += $(CHIBIOS)/os/hal/templates/
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_usb_lld.c
