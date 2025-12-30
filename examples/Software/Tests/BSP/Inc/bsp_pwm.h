#ifndef __BSP_PWM_H__
#define __BSP_PWM_H__

#include "stdint.h"
#include "tim.h"
typedef enum {
    BSP_WHEEL1_CHANNEL_1 = TIM_CHANNEL_1,
    BSP_WHEEL1_CHANNEL_2 = TIM_CHANNEL_2,
    BSP_WHEEL2_CHANNEL_1 = TIM_CHANNEL_3,
    BSP_WHEEL2_CHANNEL_2 = TIM_CHANNEL_4
} BSP_Wheel_PWM_ChannelTypeDef;

#define BSP_SERVO_MAX_DUTY_CYCLE (0.125f)
#define BSP_SERVO_MIN_DUTY_CYCLE (0.025f)

void bsp_wheel_pwm_init(void);
void bsp_wheel_pwm_deinit(void);
void bsp_wheel_pwm_start(void);
void bsp_wheel_pwm_stop(void);
void bsp_wheel_set_pwm(BSP_Wheel_PWM_ChannelTypeDef channel, float duty_cycle);
void bsp_servo_pwm_init(void);
void bsp_servo_pwm_deinit(void);
void bsp_servo_pwm_start(void);
void bsp_servo_pwm_stop(void);
void bsp_servo_set_pwm(float duty_cycle);

#endif /* __BSP_PWM_H__ */
