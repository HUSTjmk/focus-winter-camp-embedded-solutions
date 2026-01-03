#include "tim.h"
#include "bsp_pwm.h"

/*Init函数可以忽略，因为HAL库一开始就帮你初始化了*/

void bsp_wheel_pwm_init(void)
{
    MX_TIM2_Init();
}
void bsp_wheel_pwm_deinit(void)
{
    HAL_TIM_PWM_DeInit(&htim2);
}
void bsp_wheel_pwm_start(void)
{
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_ALL);
}
void bsp_wheel_pwm_stop(void)
{
    HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_ALL);
}
void bsp_wheel_set_pwm(BSP_Wheel_PWM_ChannelTypeDef channel, float duty_cycle)
{
    __HAL_TIM_SET_COMPARE(&htim2, channel, duty_cycle*TIM2->ARR);
}

void bsp_servo_pwm_init(void)
{
    MX_TIM3_Init();
}

void bsp_servo_pwm_deinit(void)
{
    HAL_TIM_PWM_DeInit(&htim3);
}

void bsp_servo_pwm_start(void)
{
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
}

void bsp_servo_pwm_stop(void)
{
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
}

void bsp_servo_set_pwm(float duty_cycle)
{
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, duty_cycle*TIM3->ARR);
}
