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

# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_usb_lld.c

# include $(CHIBIOS)/os/hal/ports/STM32/LLD/ADCv1/driver.mk
# include $(CHIBIOS)/os/hal/ports/STM32/LLD/CANv1/driver.mk
# include $(CHIBIOS)/os/hal/ports/STM32/LLD/DACv1/driver.mk
# include $(CHIBIOS)/os/hal/ports/STM32/LLD/DMAv1/driver.mk
# include $(CHIBIOS)/os/hal/ports/STM32/LLD/EXTIv1/driver.mk
# include $(CHIBIOS)/os/hal/ports/STM32/LLD/GPIOv2/driver.mk
# include $(CHIBIOS)/os/hal/ports/STM32/LLD/I2Cv2/driver.mk
# include $(CHIBIOS)/os/hal/ports/STM32/LLD/RTCv2/driver.mk
# include $(CHIBIOS)/os/hal/ports/STM32/LLD/SPIv2/driver.mk
# include $(CHIBIOS)/os/hal/ports/STM32/LLD/TIMv1/driver.mk
# include $(CHIBIOS)/os/hal/ports/STM32/LLD/USARTv2/driver.mk
# include $(CHIBIOS)/os/hal/ports/STM32/LLD/USBv1/driver.mk
# include $(CHIBIOS)/os/hal/ports/STM32/LLD/xWDGv1/driver.mk


# # List of all the template platform files.
# ifneq ($(findstring HAL_USE_ADC TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_adc_lld.c
# endif
# ifneq ($(findstring HAL_USE_CAN TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_can_lld.c
# endif
# ifneq ($(findstring HAL_USE_DAC TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_dac_lld.c
# endif
# ifneq ($(findstring HAL_USE_EXT TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_ext_lld.c
# endif
# ifneq ($(findstring HAL_USE_GPT TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_gpt_lld.c
# endif
# ifneq ($(findstring HAL_USE_I2C TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_i2c_lld.c
# endif
# ifneq ($(findstring HAL_USE_I2S TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_i2s_lld.c
# endif
# ifneq ($(findstring HAL_USE_ICU TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_icu_lld.c
# endif
# ifneq ($(findstring HAL_USE_MAC TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_mac_lld.c
# endif
# ifneq ($(findstring HAL_USE_PAL TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_pal_lld.c
# endif
# ifneq ($(findstring HAL_USE_PWM TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_pwm_lld.c
# endif
# ifneq ($(findstring HAL_USE_QSPI TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_qspi_lld.c
# endif
# ifneq ($(findstring HAL_USE_RTC TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_rtc_lld.c
# endif
# ifneq ($(findstring HAL_USE_SDC TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_sdc_lld.c
# endif
# ifneq ($(findstring HAL_USE_SERIAL TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_serial_lld.c
# endif
# ifneq ($(findstring HAL_USE_SPI TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_spi_lld.c
# endif
# ifneq ($(findstring HAL_USE_UART TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_uart_lld.c
# endif
# ifneq ($(findstring HAL_USE_USB TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_usb_lld.c
# endif
# ifneq ($(findstring HAL_USE_WDG TRUE,$(HALCONF)),)
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_wdg_lld.c
# endif

# Required include directories
# PLATFORMINC += ${CHIBIOS}/os/hal/templates
