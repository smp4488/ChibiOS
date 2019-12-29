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
 * @file    hal_usb_lld.c
 * @brief   PLATFORM USB subsystem low level driver source.
 *
 * @addtogroup USB
 * @{
 */

#include "hal.h"
#include "usb.h"
#include "usbhw.h"
#include "usbsystem.h"
#include "usbuser.h"
#include "usbepfunc.h"
#include "usbram.h"

#if (HAL_USE_USB == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
#define SN32_USB_IRQ_VECTOR     Vector44

OSAL_IRQ_HANDLER(SN32_USB_IRQ_VECTOR) {
    OSAL_IRQ_PROLOGUE();
    // serve_usb_irq(&USBD1);
    USB_IRQHandler();
    OSAL_IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   USB1 driver identifier.
 */
#if (PLATFORM_USB_USE_USB1 == TRUE) || defined(__DOXYGEN__)
USBDriver USBD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

// uint8_t *const usbd_sram = (uint8_t *)(SN_USB_BASE + 0x100);

/**
 * @brief   EP0 state.
 * @note    It is an union because IN and OUT endpoints are never used at the
 *          same time for EP0.
 */
static union {
  /**
   * @brief   IN EP0 state.
   */
  USBInEndpointState in;
  /**
   * @brief   OUT EP0 state.
   */
  USBOutEndpointState out;
} ep0_state;

// static uint8_t ep0setup_buffer[8];
// static uint32_t *pRAM = &USB_SRAM_EP0_W0;

/**
 * @brief   EP0 initialization structure.
 */
static const USBEndpointConfig ep0config = {
  USB_EP_MODE_TYPE_CTRL,
  _usb_ep0setup,
  _usb_ep0in,
  _usb_ep0out,
  0x40,
  0x40,
  &ep0_state.in,
  &ep0_state.out,
  2,
//   pRAM
//   &USB_SRAM_EP0_W0
//   ep0setup_buffer
};

/**
 * @brief   EP0 initialization structure.
 */
// static const USBEndpointConfig ep0config = {
//   USB_EP_MODE_TYPE_CTRL,
//   USB_EP0SetupEvent,
//   USB_EP0InEvent,
//   USB_EP0OutEvent,
//   0x40,
//   0x40,
//   &ep0_state.in,
//   &ep0_state.out,
//   2,
// //   pRAM
// //   &USB_SRAM_EP0_W0
// //   ep0setup_buffer
// };

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers and threads.                                    */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level USB driver initialization.
 *
 * @notapi
 */
void usb_lld_init(void) {
  /* Driver initialization.*/
  usbObjectInit(&USBD1);
  USB_Init();
}

/**
 * @brief   Configures and activates the USB peripheral.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_start(USBDriver *usbp) {

  if (usbp->state == USB_STOP) {
    /* Enables the peripheral.*/
#if PLATFORM_USB_USE_USB1 == TRUE
    if (&USBD1 == usbp) {

        /* USB clock enabled.*/
        // rccEnableUSB(FALSE);
        // SN_USB->EP0CTL->ENDP_CNT = 0x0001;
        // USB_Init();
        usbConnectBus(usbp);
        nvicEnableVector(USB_IRQn, 5);
    }
#endif
    // usb_lld_reset(usbp);
  }
  /* Configures the peripheral.*/
}

/**
 * @brief   Deactivates the USB peripheral.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_stop(USBDriver *usbp) {
  if (usbp->state == USB_READY) {
    /* Resets the peripheral.*/

    /* Disables the peripheral.*/
#if PLATFORM_USB_USE_USB1 == TRUE
    if (&USBD1 == usbp) {
        // nvicDisableVector(USB_IRQn);
        // STM32_USB->CNTR = CNTR_PDWN | CNTR_FRES;
        // rccDisableUSB(FALSE);
    }
#endif
  }
}

/**
 * @brief   USB low level reset routine.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_reset(USBDriver *usbp) {
  /* Post reset initialization.*/
//   USB_ResetEvent();

  /* EP0 initialization.*/
  usbp->epc[0] = &ep0config;
  usb_lld_init_endpoint(usbp, 0);
}

/**
 * @brief   Sets the USB address.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_set_address(USBDriver *usbp) {
//   STM32_USB->DADDR = (uint32_t)(usbp->address) | DADDR_EF;
//   __USB_SETADDRESS(usbp->address);
  USB_SetAddressEvent();
}

/**
 * @brief   Enables an endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_init_endpoint(USBDriver *usbp, usbep_t ep) {
//   const USBEndpointConfig *epcp = usbp->epc[ep];
  (void)usbp;
  (void)ep;
}

/**
 * @brief   Disables all the active endpoints except the endpoint zero.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_disable_endpoints(USBDriver *usbp) {
  unsigned i;

  /* Resets the packet memory allocator.*/
//   usb_pm_reset(usbp);

  /* Disabling all endpoints.*/
  for (i = USB_EP1; i <= USB_EP6; i++) {
    USB_EPnDisable(i);              // Disable EP1~EP6
  }
}

/**
 * @brief   Returns the status of an OUT endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @return              The endpoint status.
 * @retval EP_STATUS_DISABLED The endpoint is not active.
 * @retval EP_STATUS_STALLED  The endpoint is stalled.
 * @retval EP_STATUS_ACTIVE   The endpoint is active.
 *
 * @notapi
 */
usbepstatus_t usb_lld_get_status_out(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  switch (SN_USB->INSTS) {
      case mskEP0_IN:
          return EP_STATUS_DISABLED;
      case mskEP0_IN_STALL:
          return EP_STATUS_STALLED;
      default:
          return EP_STATUS_ACTIVE;
  }
//   return EP_STATUS_DISABLED;
}

/**
 * @brief   Returns the status of an IN endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @return              The endpoint status.
 * @retval EP_STATUS_DISABLED The endpoint is not active.
 * @retval EP_STATUS_STALLED  The endpoint is stalled.
 * @retval EP_STATUS_ACTIVE   The endpoint is active.
 *
 * @notapi
 */
usbepstatus_t usb_lld_get_status_in(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  switch (SN_USB->INSTS) {
    case mskEP0_OUT:
      return EP_STATUS_DISABLED;
    case mskEP0_OUT_STALL:
      return EP_STATUS_STALLED;
    default:
      return EP_STATUS_ACTIVE;
  }
//   return EP_STATUS_DISABLED;
}

/**
 * @brief   Reads a setup packet from the dedicated packet buffer.
 * @details This function must be invoked in the context of the @p setup_cb
 *          callback in order to read the received setup packet.
 * @pre     In order to use this function the endpoint must have been
 *          initialized as a control endpoint.
 * @post    The endpoint is ready to accept another packet.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @param[out] buf      buffer where to copy the packet data
 *
 * @notapi
 */
void usb_lld_read_setup(USBDriver *usbp, usbep_t ep, uint8_t *buf) {
  (void)usbp;
  (void)ep;
//   int i;
//   for (i = 0; i < 8; i++) {
//     *buf = usbd_sram[i];
//     //*buf = ep0setup_buffer[i];
//     // ep0setup_buffer[i] = usbd_sram[i];
//     buf += 1;
//   }

//   USB_EPnINFunction(ep, buf, 8);
  USB_EP0SetupEvent();
}

/**
 * @brief   Prepares for a receive operation.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_prepare_receive(USBDriver *usbp, usbep_t ep) {

  (void)usbp;
  (void)ep;
//   USB_EP0InEvent();
}

/**
 * @brief   Prepares for a transmit operation.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_prepare_transmit(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  (void)ep;
//   USB_EP0OutEvent();
}

/**
 * @brief   Starts a receive operation on an OUT endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_start_out(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  (void)ep;

//   uint32_t rxcnt;
//   USBOutEndpointState *oesp = usbp->epc[ep]->out_state;
//   if (oesp->rxsize > usbp->epc[ep]->out_maxsize) {
//     rxcnt = usbp->epc[ep]->out_maxsize;
//   }
//   else {
//     rxcnt = oesp->rxsize;
//   }
//   USB_EPnWriteByteData(ep, );
  //   _toggle_dsq(oesp->hwEp, &(oesp->dsq));
  //   USBD->EP[oesp->hwEp].MXPLD = rxcnt;
  // USB_EPnReadByteData(ep, )
    // &wUSB_EPnOffset[ep] = rxcnt;
}

/**
 * @brief   Starts a transmit operation on an IN endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_start_in(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  (void)ep;

}

/**
 * @brief   Brings an OUT endpoint in the stalled state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_stall_out(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  (void)ep;

}

/**
 * @brief   Brings an IN endpoint in the stalled state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_stall_in(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  (void)ep;

}

/**
 * @brief   Brings an OUT endpoint in the active state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_clear_out(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  (void)ep;

}

/**
 * @brief   Brings an IN endpoint in the active state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_clear_in(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  (void)ep;

}

#endif /* HAL_USE_USB == TRUE */

/** @} */
