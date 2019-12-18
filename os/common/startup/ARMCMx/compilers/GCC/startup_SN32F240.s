;/******************************************************************************
; * @file     startup_SN32F240.s
; * @brief    CMSIS Cortex-M0 Core Device Startup File
; *           for the SONIX SN32F200 Device Series
; * @version  V1.0
; * @date     December 2013
; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------
; *
; * @note
; * Copyright (C) 2009-2013 ARM Limited. All rights reserved.
; *
; * @par
; * ARM Limited (ARM) is supplying this software for use with Cortex-M
; * processor based microcontrollers.  This file can be freely distributed
; * within development tools that are supporting such ARM based processors.
; *
; * @par
; * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
; * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
; * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
; * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
; * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
; *
; ******************************************************************************/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size		EQU		0x00000200

				AREA	STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem		SPACE	Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size		EQU		0x00000000

				AREA	HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem		SPACE	Heap_Size
__heap_limit


				PRESERVE8
				THUMB


; Vector Table Mapped to Address 0 at Reset

				AREA	RESET, DATA, READONLY
				EXPORT	__Vectors

__Vectors		DCD		__initial_sp				; Top of Stack
				DCD		Reset_Handler				; Reset Handler
				DCD		NMI_Handler					; NMI Handler
                DCD     HardFault_Handler			; Hard Fault Handler
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		SVC_Handler					; SVCall Handler
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		PendSV_Handler				; PendSV Handler
				DCD		SysTick_Handler				; SysTick Handler

				; External Interrupts
				DCD		NDT_IRQHandler				; 16+ 0: NDT
				DCD		USB_IRQHandler				; 16+ 1: USB
				DCD		LCD_IRQHandler				; 16+ 2: LCD
				DCD		I2S_IRQHandler				; 16+ 3: I2S
				DCD		0							; 16+ 4: Reserved
				DCD		0							; 16+ 5: Reserved
				DCD		SSP0_IRQHandler				; 16+ 6: SSP0
				DCD		SSP1_IRQHandler				; 16+ 7: SSP1
				DCD		0							; 16+ 8: Reserved
				DCD		0							; 16+ 9: Reserved
				DCD		I2C0_IRQHandler				; 16+10: I2C0
				DCD		I2C1_IRQHandler				; 16+11: I2C1
				DCD		0							; 16+12: Reserved
				DCD		USART0_IRQHandler			; 16+13: USART0
				DCD		USART1_IRQHandler			; 16+14: USART1
				DCD     CT16B0_IRQHandler			; 16+15: 16-bit Counter-Timer 0
				DCD     CT16B1_IRQHandler			; 16+16: 16-bit Counter-Timer 1
				DCD     CT16B2_IRQHandler			; 16+17: 16-bit Counter-Timer 2
				DCD     0							; 16+18: Reserved
				DCD     CT32B0_IRQHandler			; 16+19: 32-bit Counter-Timer 0
				DCD     CT32B1_IRQHandler			; 16+20: 32-bit Counter-Timer 1
				DCD     CT32B2_IRQHandler			; 16+21: 32-bit Counter-Timer 2
				DCD     0							; 16+22: Reserved
				DCD		RTC_IRQHandler				; 16+23: RTC
				DCD		ADC_IRQHandler				; 16+24: A/D Converter
				DCD		WDT_IRQHandler				; 16+25: Watchdog Timer
				DCD		LVD_IRQHandler				; 16+26: Low Voltage Detect
				DCD		0							; 16+27: Reserved
				DCD		P3_IRQHandler				; 16+28: PIO INT3
				DCD		P2_IRQHandler				; 16+29: PIO INT2
				DCD		P1_IRQHandler				; 16+30: PIO INT1
				DCD		P0_IRQHandler				; 16+31: PIO INT0


				IF		:DEF:SN32F240
	AREA    |.ARM.__at_0x0000FFFC|, CODE, READONLY	;AREA CODE;    Define,CODE,READONLY
;0xFFFC
	DCD 0xAAAA5555;
	; ISP_MODE_FLAG = 0xAAAA5555 for USER MODE
				ENDIF

				IF		:DEF:SN32F230
	AREA    |.ARM.__at_0x00007FFC|, CODE, READONLY	;AREA CODE;    Define,CODE,READONLY
;0x7FFC
	DCD 0xAAAA5555;
	; ISP_MODE_FLAG = 0xAAAA5555 for USER MODE
				ENDIF

				IF		:DEF:SN32F220
	AREA    |.ARM.__at_0x00003FFC|, CODE, READONLY	;AREA CODE;    Define,CODE,READONLY
;0x3FFC
	DCD 0xAAAA5555;
	; ISP_MODE_FLAG = 0xAAAA5555 for USER MODE
				ENDIF


				AREA	|.text|, CODE, READONLY
; Reset Handler

Reset_Handler	PROC
				EXPORT  Reset_Handler			[WEAK]
				;IMPORT  SystemInit
				IMPORT  __main
				;LDR     R0, =SystemInit
				;BLX     R0
				LDR     R0, =__main
				BX      R0
				ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler		PROC
				EXPORT	NMI_Handler				[WEAK]
				B		.
				ENDP
HardFault_Handler	PROC
				EXPORT	HardFault_Handler		[WEAK]
				B		.
				ENDP
SVC_Handler		PROC
				EXPORT	SVC_Handler				[WEAK]
				B		.
				ENDP
PendSV_Handler	PROC
				EXPORT	PendSV_Handler			[WEAK]
				B		.
				ENDP
SysTick_Handler	PROC
				EXPORT	SysTick_Handler			[WEAK]
				B		.
				ENDP
Default_Handler	PROC
				EXPORT	NDT_IRQHandler				[WEAK]
				EXPORT	USB_IRQHandler				[WEAK]
				EXPORT	LCD_IRQHandler				[WEAK]
				EXPORT	I2S_IRQHandler				[WEAK]
				EXPORT	SSP0_IRQHandler				[WEAK]
				EXPORT	SSP1_IRQHandler				[WEAK]
				EXPORT	I2C0_IRQHandler				[WEAK]
				EXPORT	I2C1_IRQHandler				[WEAK]
				EXPORT	USART0_IRQHandler			[WEAK]
				EXPORT	USART1_IRQHandler			[WEAK]
				EXPORT	CT16B0_IRQHandler			[WEAK]
				EXPORT	CT16B1_IRQHandler			[WEAK]
				EXPORT	CT16B2_IRQHandler			[WEAK]
				EXPORT	CT32B0_IRQHandler			[WEAK]
				EXPORT	CT32B1_IRQHandler			[WEAK]
				EXPORT	CT32B2_IRQHandler			[WEAK]
				EXPORT	RTC_IRQHandler				[WEAK]
				EXPORT	ADC_IRQHandler				[WEAK]
				EXPORT	WDT_IRQHandler				[WEAK]
				EXPORT	LVD_IRQHandler				[WEAK]
				EXPORT	P3_IRQHandler				[WEAK]
				EXPORT	P2_IRQHandler				[WEAK]
				EXPORT	P1_IRQHandler				[WEAK]
				EXPORT	P0_IRQHandler				[WEAK]

NDT_IRQHandler
USB_IRQHandler
LCD_IRQHandler
I2S_IRQHandler
SSP0_IRQHandler
SSP1_IRQHandler
I2C0_IRQHandler
I2C1_IRQHandler
USART0_IRQHandler
USART1_IRQHandler
CT16B0_IRQHandler
CT16B1_IRQHandler
CT16B2_IRQHandler
CT32B0_IRQHandler
CT32B1_IRQHandler
CT32B2_IRQHandler
RTC_IRQHandler
ADC_IRQHandler
WDT_IRQHandler
LVD_IRQHandler
P3_IRQHandler
P2_IRQHandler
P1_IRQHandler
P0_IRQHandler

                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END
