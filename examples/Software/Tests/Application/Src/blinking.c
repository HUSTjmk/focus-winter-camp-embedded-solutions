#include "bsp_led.h"
#include "main.h"
void app_blinking_task_demo(void)
{
    while (1)
    {
        bsp_led_toggle();
        HAL_Delay(500);
        bsp_led_toggle();
        HAL_Delay(500);
    }
}
