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
 * @file    SN32F240B/sn32_registry.h
 * @brief   SN32F240B capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef SN32_REGISTRY_H
#define SN32_REGISTRY_H

#if !defined(SN32F240B) || defined(__DOXYGEN__)
#define SN32F240B
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    SN32F240B capabilities
 * @{
 */

/*===========================================================================*/
/* SN32F091xC, SN32F098xx.                                                 */
/*===========================================================================*/
#if defined(SN32F240B)

/* RCC attributes. */
#define SN32_HAS_HSI48                     TRUE
#define SN32_HAS_HSI_PREDIV                TRUE
#define SN32_HAS_MCO_PREDIV                TRUE

/* ADC attributes.*/
#define SN32_HAS_ADC1                      TRUE
#define SN32_ADC_SUPPORTS_PRESCALER        FALSE
#define SN32_ADC_SUPPORTS_OVERSAMPLING     FALSE
#define SN32_ADC1_IRQ_SHARED_WITH_EXTI     TRUE
#define SN32_ADC1_HANDLER                  Vector70
#define SN32_ADC1_NUMBER                   12
#define SN32_ADC1_DMA_MSK                  (SN32_DMA_STREAM_ID_MSK(1, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 5))
#define SN32_ADC1_DMA_CHN                  0x00100011

#define SN32_HAS_ADC2                      FALSE
#define SN32_HAS_ADC3                      FALSE
#define SN32_HAS_ADC4                      FALSE

/* GPIO attributes.*/
#define SN32_HAS_GPIOA                     TRUE
#define SN32_HAS_GPIOB                     TRUE
#define SN32_HAS_GPIOC                     TRUE
#define SN32_HAS_GPIOD                     TRUE
#define SN32_GPIO_EN_MASK                  (RCC_AHBENR_GPIOAEN |           \
                                             RCC_AHBENR_GPIOBEN |           \
                                             RCC_AHBENR_GPIOCEN |           \
                                             RCC_AHBENR_GPIODEN |           \
                                             RCC_AHBENR_GPIOFEN)

/* I2C attributes.*/
#define SN32_HAS_I2C1                      TRUE
#define SN32_I2C1_RX_DMA_MSK               (SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 7))
#define SN32_I2C1_RX_DMA_CHN               0x02000200
#define SN32_I2C1_TX_DMA_MSK               (SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 6))
#define SN32_I2C1_TX_DMA_CHN               0x00200020

/* RTC attributes.*/
#define SN32_HAS_RTC                       TRUE
#define SN32_RTC_HAS_SUBSECONDS            TRUE
#define SN32_RTC_HAS_PERIODIC_WAKEUPS      TRUE
#define SN32_RTC_NUM_ALARMS                1
#define SN32_RTC_HAS_INTERRUPTS            TRUE

/* SPI attributes.*/
#define SN32_HAS_SPI1                      TRUE
#define SN32_SPI1_SUPPORTS_I2S             TRUE
#define SN32_SPI1_I2S_FULLDUPLEX           FALSE
#define SN32_SPI1_RX_DMA_MSK               (SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 3))
#define SN32_SPI1_RX_DMA_CHN               0x00000330
#define SN32_SPI1_TX_DMA_MSK               (SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 4))
#define SN32_SPI1_TX_DMA_CHN               0x00003300

/* TIM attributes.*/
#define SN32_TIM_MAX_CHANNELS              4

#define SN32_HAS_TIM1                      TRUE
#define SN32_TIM1_IS_32BITS                FALSE
#define SN32_TIM1_CHANNELS                 24

#define SN32_HAS_TIM2                      TRUE
#define SN32_TIM2_IS_32BITS                FALSE
#define SN32_TIM2_CHANNELS                 24

/* UART attributes.*/
#define SN32_HAS_UART1                    TRUE
#define SN32_UART1_RX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 5) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 6) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 3))
#define SN32_UART1_RX_DMA_CHN             0x00880888
#define SN32_UART1_TX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 7) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 5))
#define SN32_UART1_TX_DMA_CHN             0x08088088

#define SN32_HAS_USRT2                    TRUE
#define SN32_UART2_RX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 5) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 6) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 3))
#define SN32_UART2_RX_DMA_CHN             0x00990999
#define SN32_UART2_TX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 7) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 5))
#define SN32_UART2_TX_DMA_CHN             0x09099099

#define SN32_HAS_UART3                    TRUE
#define SN32_UART3_RX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 5) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 6) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 3))
#define SN32_UART3_RX_DMA_CHN             0x00AA0AAA
#define SN32_UART3_TX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 7) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 5))
#define SN32_UART3_TX_DMA_CHN             0x0A0AA0AA

#define SN32_HAS_LPUART1                   FALSE

/* USB attributes.*/
#define SN32_HAS_USB                       TRUE
#define SN32_USB_PMA_SIZE                  512
#define SN32_HAS_OTG1                      FALSE
#define SN32_HAS_OTG2                      FALSE
#define SN32_USBCLK                        48000000

/* IWDG attributes.*/
#define SN32_HAS_IWDG                      TRUE
#define SN32_IWDG_IS_WINDOWED              TRUE

/* LTDC attributes.*/
#define SN32_HAS_LTDC                      FALSE

/* FSMC attributes.*/
#define SN32_HAS_FSMC                      FALSE

/* CRC attributes.*/
#define SN32_HAS_CRC                       TRUE
#define SN32_CRC_PROGRAMMABLE              TRUE

#else
#error "SN32F0xx device not specified"
#endif

/** @} */

#endif /* SN32_REGISTRY_H */

/** @} */
