#include "bsp_pwm.h"

/*测试：舵机控制尾巴任务演示*/

static void tail_servo_set_angle(int16_t angle)
{
    if(angle > 180) angle = 180;
    if(angle < 0) angle = 0;
    //将角度转换为PWM占空比
    float duty_cycle = (angle / 180.0f) * (BSP_SERVO_MAX_DUTY_CYCLE - BSP_SERVO_MIN_DUTY_CYCLE) + BSP_SERVO_MIN_DUTY_CYCLE;
    bsp_servo_set_pwm(duty_cycle);
}

void app_tail_test_demo(void)
{
    bsp_servo_pwm_init();
    bsp_servo_pwm_start();
    while(1)
    {
        tail_servo_set_angle(180);
        HAL_Delay(1000);
        tail_servo_set_angle(90);
        HAL_Delay(1000);
        tail_servo_set_angle(0);
        HAL_Delay(1000);
        tail_servo_set_angle(90);
        HAL_Delay(1000);
    }
}
