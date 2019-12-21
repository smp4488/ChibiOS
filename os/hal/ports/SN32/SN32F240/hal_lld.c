/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    hal_lld.c
 * @brief   PLATFORM HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "hal.h"
#include <SN32F240B.h>

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   STM32L4xx clocks and PLL initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function should be invoked just after the system reset.
 *
 * @special
 */
void sn32_clock_init(void) {
#if (SYS_CLOCK_SETUP)

	#if SYS0_CLKCFG_VAL == IHRC			//IHRC

	#endif

	#if SYS0_CLKCFG_VAL == ILRC			//ILRC
	SN_SYS0->CLKCFG = 0x1;
    while ((SN_SYS0->CLKCFG & 0x70) != 0x10);
	#endif

	#if (SYS0_CLKCFG_VAL == EHSXTAL)	//EHS XTAL
	#if (EHS_FREQ > 12)
	SN_SYS0->ANBCTRL |= (1<<5);
	#else
	SN_SYS0->ANBCTRL &=~(1<<5);
	#endif
	SN_SYS0->ANBCTRL |= (1<<4);
	while ((SN_SYS0->CSST & 0x10) != 0x10);
	SN_SYS0->CLKCFG = 0x2;
    while ((SN_SYS0->CLKCFG & 0x70) != 0x20);
	#endif

	#if (SYS0_CLKCFG_VAL == ELSXTAL)	//ELS XTAL
	SN_SYS0->ANBCTRL |=0x04;
	while((SN_SYS0->CSST & 0x4) != 0x4);
	SN_SYS0->CLKCFG = 0x3;
    while ((SN_SYS0->CLKCFG & 0x70) != 0x30);
	#endif

	// #if (SYS0_CLKCFG_VAL == PLL)		//PLL
    // SN_SYS0->ANBCTRL = SYS0_ANBCTRL_VAL;
    // if (PLL_CLKIN == 0x1)	//EHS XTAL as F_CLKIN
	// {
	// 	//Enable EHS
	// 	#if (EHS_FREQ > 12)
	// 	SN_SYS0->ANBCTRL |= (1<<5);
	// 	#else
	// 	SN_SYS0->ANBCTRL &=~(1<<5);
	// 	#endif
	// 	SN_SYS0->ANBCTRL |= (1<<4);
	// 	while ((SN_SYS0->CSST & 0x10) != 0x10);
	// }

	// while ((SN_SYS0->CSST & 0x40) != 0x40);
    // SN_SYS0->CLKCFG = 0x4;
    // while ((SN_SYS0->CLKCFG & 0x70) != 0x40);
	// #endif

	SN_SYS0->AHBCP = AHB_PRESCALAR;

	#if (CLKOUT_SEL_VAL > 0)			//CLKOUT
	SN_SYS1->AHBCLKEN_b.CLKOUTSEL = CLKOUT_SEL_VAL;
	#endif
#endif //(SYS_CLOCK_SETUP)
}

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void) {

}

/** @} */
