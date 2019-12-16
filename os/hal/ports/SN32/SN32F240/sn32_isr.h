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
 * @file    SN32F0xx/sn32_isr.h
 * @brief   ISR remapper driver header.
 *
 * @addtogroup SN32F0xx_ISR
 * @{
 */

#ifndef SN32_ISR_H
#define SN32_ISR_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    ISR names and numbers remapping
 * @{
 */
/*
 * CAN units.
 */
#define SN32_CAN1_UNIFIED_HANDLER  VectorB8
#define SN32_CAN1_UNIFIED_NUMBER   30

/*
 * I2C units.
 */
#define SN32_I2C1_GLOBAL_HANDLER   Vector9C
#define SN32_I2C1_GLOBAL_NUMBER    23

#define SN32_I2C2_GLOBAL_HANDLER   VectorA0
#define SN32_I2C2_GLOBAL_NUMBER    24

/*
 * TIM units.
 */
#define SN32_TIM1_UP_HANDLER       Vector74
#define SN32_TIM1_CC_HANDLER       Vector78
#define SN32_TIM2_HANDLER          Vector7C
#define SN32_TIM3_HANDLER          Vector80
#define SN32_TIM6_HANDLER          Vector84
#define SN32_TIM7_HANDLER          Vector88
#define SN32_TIM14_HANDLER         Vector8C
#define SN32_TIM15_HANDLER         Vector90
#define SN32_TIM16_HANDLER         Vector94
#define SN32_TIM17_HANDLER         Vector98

#define SN32_TIM1_UP_NUMBER        13
#define SN32_TIM1_CC_NUMBER        14
#define SN32_TIM2_NUMBER           15
#define SN32_TIM3_NUMBER           16
#define SN32_TIM6_NUMBER           17
#define SN32_TIM7_NUMBER           18
#define SN32_TIM14_NUMBER          19
#define SN32_TIM15_NUMBER          20
#define SN32_TIM16_NUMBER          21
#define SN32_TIM17_NUMBER          22

/*
 * USART units.
 */
#define SN32_USART1_HANDLER        VectorAC
#define SN32_USART2_HANDLER        VectorB0
#define SN32_USART3_8_HANDLER      VectorB4

#define SN32_USART1_NUMBER         27
#define SN32_USART2_NUMBER         28
#define SN32_USART3_8_NUMBER       29

/*
 * USB units.
 */
#define SN32_USB1_LP_HANDLER       VectorBC
#define SN32_USB1_LP_NUMBER        31
#define SN32_USB1_HP_HANDLER       VectorBC
#define SN32_USB1_HP_NUMBER        31
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#endif /* SN32_ISR_H */

/** @} */
