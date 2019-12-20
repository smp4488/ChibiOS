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
 * @file    hal_st_lld.c
 * @brief   PLATFORM ST subsystem low level driver source.
 *
 * @addtogroup ST
 * @{
 */

#include "hal.h"
#include "CT16.h"
#include "CT16B0.h"

#if (OSAL_ST_MODE != OSAL_ST_MODE_NONE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local types.                                                       */
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

#if (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING) || defined(__DOXYGEN__)
/**
 * @brief   CT0 interrupt handler.
 * @details This interrupt is used for system tick in free running mode.
 *
 * @isr
 */
c(SysTick_Handler) {

  OSAL_IRQ_PROLOGUE();
  //Wait until timer reset done.
  while (SN_CT16B0->TMRCTRL & mskCT16_CRST);
  osalSysLockFromISR();
  osalOsTimerHandlerI();
  osalSysUnlockFromISR();

  OSAL_IRQ_EPILOGUE();
}
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ST driver initialization.
 *
 * @notapi
 */
void st_lld_init(void) {
  CT16B0_Init();

  // Set CT16B0 as the up-counting mode.
  SN_CT16B0->TMRCTRL = (mskCT16_CRST | mskCT16_CM_EDGE_UP);

  // Set MR0 match as TC stop, and enable MR0 interrupt
  SN_CT16B0->MCTRL = (mskCT16_MR0STOP_EN | mskCT16_MR0IE_EN);

  // Set CT16B0 as the up-counting mode.
  SN_CT16B0->TMRCTRL = (mskCT16_CRST | mskCT16_CM_EDGE_UP);

  // Wait until timer reset done.
  while (SN_CT16B0->TMRCTRL & mskCT16_CRST);

  // Let TC start counting.
  SN_CT16B0->TMRCTRL |= mskCT16_CEN_EN;

  // Enable CT16B0's NVIC interrupt.
  CT16B0_NvicEnable();

  //   /* Periodic systick mode, the Cortex-Mx internal systick timer is usedin this mode.*/
  //   SysTick->LOAD = (72000000 / OSAL_ST_FREQUENCY) - 1;
  //   SysTick->VAL = 0;
  //   SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
  //                   SysTick_CTRL_ENABLE_Msk |
  //                   SysTick_CTRL_TICKINT_Msk;

//   /* IRQ enabled.*/
//   nvicSetSystemHandlerPriority(HANDLER_SYSTICK, 8);
  /* IRQ enabled.*/
  nvicEnableVector(31, 8);
}

#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */
