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

/* CAN attributes.*/
#define SN32_HAS_CAN1                      TRUE
#define SN32_HAS_CAN2                      FALSE
#define SN32_HAS_CAN3                      FALSE
#define SN32_CAN_MAX_FILTERS               14

/* DAC attributes.*/
#define SN32_HAS_DAC1_CH1                  TRUE
#define SN32_DAC1_CH1_DMA_MSK              (SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 3))
#define SN32_DAC1_CH1_DMA_CHN              0x00000100

#define SN32_HAS_DAC1_CH2                  FALSE
#define SN32_DAC1_CH2_DMA_MSK              (SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 4))
#define SN32_DAC1_CH2_DMA_CHN              0x00001000

#define SN32_HAS_DAC2_CH1                  FALSE
#define SN32_HAS_DAC2_CH2                  FALSE

/* DMA attributes.*/
#define SN32_ADVANCED_DMA                  TRUE
#define SN32_DMA_SUPPORTS_CSELR            TRUE

#define SN32_DMA1_NUM_CHANNELS             7
#define SN32_DMA2_NUM_CHANNELS             5

#define SN32_DMA1_CH1_HANDLER              Vector64
#define SN32_DMA12_CH23_CH12_HANDLER       Vector68
#define SN32_DMA12_CH4567_CH345_HANDLER    Vector6C
#define SN32_DMA1_CH1_NUMBER               9
#define SN32_DMA12_CH23_CH12_NUMBER        10
#define SN32_DMA12_CH4567_CH345_NUMBER     11

#define SN32_DMA1_CH2_NUMBER               SN32_DMA12_CH23_CH12_NUMBER
#define SN32_DMA1_CH3_NUMBER               SN32_DMA12_CH23_CH12_NUMBER
#define SN32_DMA2_CH1_NUMBER               SN32_DMA12_CH23_CH12_NUMBER
#define SN32_DMA2_CH2_NUMBER               SN32_DMA12_CH23_CH12_NUMBER
#define DMA1_CH2_CMASK                      0x00000186U
#define DMA1_CH3_CMASK                      0x00000186U
#define DMA2_CH1_CMASK                      0x00000186U
#define DMA2_CH2_CMASK                      0x00000186U

#define SN32_DMA1_CH4_NUMBER               SN32_DMA12_CH4567_CH345_NUMBER
#define SN32_DMA1_CH5_NUMBER               SN32_DMA12_CH4567_CH345_NUMBER
#define SN32_DMA1_CH6_NUMBER               SN32_DMA12_CH4567_CH345_NUMBER
#define SN32_DMA1_CH7_NUMBER               SN32_DMA12_CH4567_CH345_NUMBER
#define SN32_DMA2_CH3_NUMBER               SN32_DMA12_CH4567_CH345_NUMBER
#define SN32_DMA2_CH4_NUMBER               SN32_DMA12_CH4567_CH345_NUMBER
#define SN32_DMA2_CH5_NUMBER               SN32_DMA12_CH4567_CH345_NUMBER
#define DMA1_CH4_CMASK                      0x00000E78U
#define DMA1_CH5_CMASK                      0x00000E78U
#define DMA1_CH6_CMASK                      0x00000E78U
#define DMA1_CH7_CMASK                      0x00000E78U
#define DMA2_CH3_CMASK                      0x00000E78U
#define DMA2_CH4_CMASK                      0x00000E78U
#define DMA2_CH5_CMASK                      0x00000E78U

/* ETH attributes.*/
#define SN32_HAS_ETH                       FALSE

/* EXTI attributes.*/
#define SN32_EXTI_NUM_LINES                32
#define SN32_EXTI_IMR_MASK                 0x7F840000U

/* GPIO attributes.*/
#define SN32_HAS_GPIOA                     TRUE
#define SN32_HAS_GPIOB                     TRUE
#define SN32_HAS_GPIOC                     TRUE
#define SN32_HAS_GPIOD                     TRUE
#define SN32_HAS_GPIOE                     FALSE
#define SN32_HAS_GPIOF                     FALSE
#define SN32_HAS_GPIOG                     FALSE
#define SN32_HAS_GPIOH                     FALSE
#define SN32_HAS_GPIOI                     FALSE
#define SN32_HAS_GPIOJ                     FALSE
#define SN32_HAS_GPIOK                     FALSE
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

#define SN32_HAS_I2C2                      TRUE
#define SN32_I2C2_RX_DMA_MSK               (SN32_DMA_STREAM_ID_MSK(1, 5) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 2))
#define SN32_I2C2_RX_DMA_CHN               0x00020020
#define SN32_I2C2_TX_DMA_MSK               (SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 1))
#define SN32_I2C2_TX_DMA_CHN               0x00002002

#define SN32_HAS_I2C3                      FALSE
#define SN32_HAS_I2C4                      FALSE

/* QUADSPI attributes.*/
#define SN32_HAS_QUADSPI1                  FALSE

/* RTC attributes.*/
#define SN32_HAS_RTC                       TRUE
#define SN32_RTC_HAS_SUBSECONDS            TRUE
#define SN32_RTC_HAS_PERIODIC_WAKEUPS      TRUE
#define SN32_RTC_NUM_ALARMS                1
#define SN32_RTC_HAS_INTERRUPTS            FALSE

/* SDIO attributes.*/
#define SN32_HAS_SDIO                      FALSE

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

#define SN32_HAS_SPI2                      TRUE
#define SN32_SPI2_SUPPORTS_I2S             TRUE
#define SN32_SPI2_I2S_FULLDUPLEX           FALSE
#define SN32_SPI2_RX_DMA_MSK               (SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 6))
#define SN32_SPI2_RX_DMA_CHN               0x00303000
#define SN32_SPI2_TX_DMA_MSK               (SN32_DMA_STREAM_ID_MSK(1, 5) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 7))
#define SN32_SPI2_TX_DMA_CHN               0x03030000

#define SN32_HAS_SPI3                      FALSE
#define SN32_HAS_SPI4                      FALSE
#define SN32_HAS_SPI5                      FALSE
#define SN32_HAS_SPI6                      FALSE

/* TIM attributes.*/
#define SN32_TIM_MAX_CHANNELS              4

#define SN32_HAS_TIM1                      TRUE
#define SN32_TIM1_IS_32BITS                FALSE
#define SN32_TIM1_CHANNELS                 4

#define SN32_HAS_TIM2                      TRUE
#define SN32_TIM2_IS_32BITS                TRUE
#define SN32_TIM2_CHANNELS                 4

#define SN32_HAS_TIM3                      TRUE
#define SN32_TIM3_IS_32BITS                FALSE
#define SN32_TIM3_CHANNELS                 4

#define SN32_HAS_TIM6                      TRUE
#define SN32_TIM6_IS_32BITS                FALSE
#define SN32_TIM6_CHANNELS                 0

#define SN32_HAS_TIM7                      TRUE
#define SN32_TIM7_IS_32BITS                FALSE
#define SN32_TIM7_CHANNELS                 0

#define SN32_HAS_TIM14                     TRUE
#define SN32_TIM14_IS_32BITS               FALSE
#define SN32_TIM14_CHANNELS                1

#define SN32_HAS_TIM15                     TRUE
#define SN32_TIM15_IS_32BITS               FALSE
#define SN32_TIM15_CHANNELS                2

#define SN32_HAS_TIM16                     TRUE
#define SN32_TIM16_IS_32BITS               FALSE
#define SN32_TIM16_CHANNELS                1

#define SN32_HAS_TIM17                     TRUE
#define SN32_TIM17_IS_32BITS               FALSE
#define SN32_TIM17_CHANNELS                1

#define SN32_HAS_TIM4                      FALSE
#define SN32_HAS_TIM5                      FALSE
#define SN32_HAS_TIM8                      FALSE
#define SN32_HAS_TIM9                      FALSE
#define SN32_HAS_TIM10                     FALSE
#define SN32_HAS_TIM11                     FALSE
#define SN32_HAS_TIM12                     FALSE
#define SN32_HAS_TIM13                     FALSE
#define SN32_HAS_TIM18                     FALSE
#define SN32_HAS_TIM19                     FALSE
#define SN32_HAS_TIM20                     FALSE
#define SN32_HAS_TIM21                     FALSE
#define SN32_HAS_TIM22                     FALSE

/* USART attributes.*/
#define SN32_HAS_USART1                    TRUE
#define SN32_USART1_RX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 5) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 6) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 3))
#define SN32_USART1_RX_DMA_CHN             0x00880888
#define SN32_USART1_TX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 7) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 5))
#define SN32_USART1_TX_DMA_CHN             0x08088088

#define SN32_HAS_USART2                    TRUE
#define SN32_USART2_RX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 5) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 6) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 3))
#define SN32_USART2_RX_DMA_CHN             0x00990999
#define SN32_USART2_TX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 7) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 5))
#define SN32_USART2_TX_DMA_CHN             0x09099099

#define SN32_HAS_USART3                    TRUE
#define SN32_USART3_RX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 5) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 6) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 3))
#define SN32_USART3_RX_DMA_CHN             0x00AA0AAA
#define SN32_USART3_TX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 7) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 5))
#define SN32_USART3_TX_DMA_CHN             0x0A0AA0AA

#define SN32_HAS_UART4                     TRUE
#define SN32_UART4_RX_DMA_MSK              (SN32_DMA_STREAM_ID_MSK(1, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 5) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 6) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 3))
#define SN32_UART4_RX_DMA_CHN              0x00BB0BBB
#define SN32_UART4_TX_DMA_MSK              (SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 7) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 5))
#define SN32_UART4_TX_DMA_CHN              0x0B0BB0BB

#define SN32_HAS_UART5                     TRUE
#define SN32_UART5_RX_DMA_MSK              (SN32_DMA_STREAM_ID_MSK(1, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 5) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 6) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 3))
#define SN32_UART5_RX_DMA_CHN              0x00CC0CCC
#define SN32_UART5_TX_DMA_MSK              (SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 7) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 5))
#define SN32_UART5_TX_DMA_CHN              0x0C0CC0CC

#define SN32_HAS_USART6                    TRUE
#define SN32_USART6_RX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 5) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 6) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 3))
#define SN32_USART6_RX_DMA_CHN             0x00DD0DDD
#define SN32_USART6_TX_DMA_MSK             (SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 7) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 5))
#define SN32_USART6_TX_DMA_CHN             0x0D0DD0DD

#define SN32_HAS_UART7                     TRUE
#define SN32_UART7_RX_DMA_MSK              (SN32_DMA_STREAM_ID_MSK(1, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 5) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 6) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 3))
#define SN32_UART7_RX_DMA_CHN              0x00EE0EEE
#define SN32_UART7_TX_DMA_MSK              (SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 7) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 5))
#define SN32_UART7_TX_DMA_CHN              0x0E0EE0EE

#define SN32_HAS_UART8                     TRUE
#define SN32_UART8_RX_DMA_MSK              (SN32_DMA_STREAM_ID_MSK(1, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 3) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 5) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 6) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 3))
#define SN32_UART8_RX_DMA_CHN              0x00FF0FFF
#define SN32_UART8_TX_DMA_MSK              (SN32_DMA_STREAM_ID_MSK(1, 2) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(1, 7) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 1) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 4) |\
                                             SN32_DMA_STREAM_ID_MSK(2, 5))
#define SN32_UART8_TX_DMA_CHN              0x0F0FF0FF

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

/* DMA2D attributes.*/
#define SN32_HAS_DMA2D                     FALSE

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
