#ifndef __BSP_GESTURE_H__
#define __BSP_GESTURE_H__

#include "stdint.h"
void bsp_gesture_set_detect_callback(void(*callback)(void));
void bsp_gesture_clear_detect_callback(void);
void bsp_gesture_detect_callback(void);

#endif /* __BSP_GESTURE_H__ */
