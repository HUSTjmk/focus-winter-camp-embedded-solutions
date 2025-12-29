#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "stdint.h"
void bsp_led_init(void);
void bsp_led_deinit(void);
void bsp_led_on(void);
void bsp_led_off(void);
void bsp_led_toggle(void);

#endif /* __BSP_LED_H__ */
