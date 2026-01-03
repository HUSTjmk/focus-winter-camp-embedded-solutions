#include "bsp_ultrasonic.h"
#include "bsp_timer.h"
#include "main.h"

/*测试：超声波测距任务演示，带中断版本。跟随功能请自行实现哦*/

#define SPEED_OF_SOUND_CM_PER_US 0.0343f // Speed of sound in cm/us
#define FILTER_ALPHA 0.3f
uint32_t time_elapsed;
uint32_t distance_cm;

static void ultrasonic_distance_filter(uint32_t *distance)
{
    static uint32_t prev_distance = 0;
    *distance = (uint32_t)(FILTER_ALPHA * (*distance) + (1 - FILTER_ALPHA) * prev_distance);
    prev_distance = *distance;
}

static void ultrasonic_echo_callback(uint8_t echo_state)
{
    // Handle echo received event
    if(echo_state == 1){
        // Echo started
        bsp_timer_clear_counter();
        bsp_timer_start();
    }
    else if(echo_state == 0){
        // Echo ended
        bsp_timer_stop();
        time_elapsed = bsp_timer_get_counter();
        distance_cm = (bsp_timer_get_us() * SPEED_OF_SOUND_CM_PER_US) / 2;
        ultrasonic_distance_filter(&distance_cm);
        bsp_timer_clear_counter();
    }
    else{
        // Invalid state
    }
}

void app_following_test_demo(void)
{
    bsp_ultrasonic_init();
    bsp_timer_init();
    bsp_timer_start();
    bsp_ultrasonic_set_echo_callback(ultrasonic_echo_callback);
    while (1)
    {
        bsp_ultrasonic_trigger_pulse(100);
        HAL_Delay(100);
    }
}
