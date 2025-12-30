#ifndef __BSP_TIMER_H__
#define __BSP_TIMER_H__

#include "stdint.h"
void bsp_timer_init(void);
void bsp_timer_deinit(void);
void bsp_timer_start(void);
void bsp_timer_stop(void);
void bsp_timer_reset(void);
void bsp_timer_set_auto_reload(uint32_t auto_reload);
void bsp_timer_set_prescaler(uint32_t prescaler);
void bsp_timer_clear_counter(void);
uint32_t bsp_timer_get_counter(void);
uint32_t bsp_timer_get_us(void);
void bsp_timer_set_period_elapsed_callback(void(*callback)(void));
void bsp_timer_clear_period_elapsed_callback(void);
void bsp_timer_period_elapsed_callback(void);

#endif /* __BSP_TIMER_H__ */

