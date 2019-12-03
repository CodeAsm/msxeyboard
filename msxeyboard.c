#include "msxeyboard.h"

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinHigh(USB_LED_CAPS_LOCK);
  } else {
    writePinLow(USB_LED_CAPS_LOCK);
  }


  led_set_user(usb_led);
}
