#ifndef __BSP_ULTRASONIC_H__
#define __BSP_ULTRASONIC_H__

#include "stdint.h"
void bsp_ultrasonic_init(void);
void bsp_ultrasonic_deinit(void);
void bsp_ultrasonic_reset(void);
void bsp_ultrasonic_set_echo_callback(void(*callback)(uint8_t state));
void bsp_ultrasonic_clear_echo_callback(void);
void bsp_ultrasonic_echo_callback(void);
void bsp_ultrasonic_trigger_pulse(uint32_t pulse_width_us);

#endif /* __BSP_ULTRASONIC_H__ */
