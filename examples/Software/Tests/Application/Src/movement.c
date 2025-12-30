#include "bsp_pwm.h"
#include "stdbool.h"

static void left_wheel_move(float speed, bool dir)
{
    if(dir)
    {
        bsp_wheel_set_pwm(BSP_WHEEL1_CHANNEL_1, speed);
        bsp_wheel_set_pwm(BSP_WHEEL1_CHANNEL_2, 0);
    }
    else
    {
        bsp_wheel_set_pwm(BSP_WHEEL1_CHANNEL_1, 0);
        bsp_wheel_set_pwm(BSP_WHEEL1_CHANNEL_2, speed);
    }
}

static void right_wheel_move(float speed, bool dir)
{
    if(dir)
    {
        bsp_wheel_set_pwm(BSP_WHEEL2_CHANNEL_1, speed);
        bsp_wheel_set_pwm(BSP_WHEEL2_CHANNEL_2, 0);
    }
    else
    {
        bsp_wheel_set_pwm(BSP_WHEEL2_CHANNEL_1, 0);
        bsp_wheel_set_pwm(BSP_WHEEL2_CHANNEL_2, speed);
    }
}


void app_move_test_demo(void)
{
    bsp_wheel_pwm_init();
    bsp_wheel_pwm_start();
    while(1)
    {
        // Move forward
        left_wheel_move(0.5f, true);
        right_wheel_move(0.5f, true);
        HAL_Delay(2000);

        // Move backward
        left_wheel_move(0.5f, false);
        right_wheel_move(0.5f, false);
        HAL_Delay(2000);

        // Turn left
        left_wheel_move(0.3f, false);
        right_wheel_move(0.3f, true);
        HAL_Delay(2000);

        // Turn right
        left_wheel_move(0.3f, true);
        right_wheel_move(0.3f, false);
        HAL_Delay(2000);

        // Stop
        left_wheel_move(0.0f, true);
        right_wheel_move(0.0f, true);
    }
}
