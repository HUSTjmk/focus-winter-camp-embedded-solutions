#include "tim.h"
#include "bsp_timer.h"

void(*bsp_timer_period_elapsed_callback_)(void) = NULL;

/*Init函数可以忽略，因为HAL库一开始就帮你初始化了*/
void bsp_timer_init(void)
{
    MX_TIM4_Init();
}

void bsp_timer_deinit(void)
{
    HAL_TIM_Base_DeInit(&htim4);
}

void bsp_timer_start(void)
{
    HAL_TIM_Base_Start_IT(&htim4);
}
void bsp_timer_stop(void)
{
    HAL_TIM_Base_Stop_IT(&htim4);
}

void bsp_timer_reset(void)
{
    bsp_timer_deinit();
    bsp_timer_init();
}

void bsp_timer_set_auto_reload(uint32_t auto_reload)
{
    __HAL_TIM_SET_AUTORELOAD(&htim4, auto_reload);
}

void bsp_timer_set_prescaler(uint32_t prescaler)
{
    __HAL_TIM_SET_PRESCALER(&htim4, prescaler);
}

void bsp_timer_clear_counter(void)
{
    __HAL_TIM_SET_COUNTER(&htim4, 0);
}   

uint32_t bsp_timer_get_counter(void)
{
    return __HAL_TIM_GET_COUNTER(&htim4);
}

void bsp_timer_set_period_elapsed_callback(void(*callback)(void))
{
    bsp_timer_period_elapsed_callback_ = callback;
}

void bsp_timer_clear_period_elapsed_callback(void)
{
    bsp_timer_period_elapsed_callback_ = NULL;
}

void bsp_timer_period_elapsed_callback(void)
{
    if (bsp_timer_period_elapsed_callback_)
    {
        bsp_timer_period_elapsed_callback_();
    }
}

uint32_t bsp_timer_get_us(void)
{
    uint32_t timer_clock = HAL_RCC_GetPCLK1Freq(); // TIM4 is on APB1
    uint32_t prescaler = htim4.Init.Prescaler + 1; // Prescaler is zero-based
    uint32_t timer_frequency = timer_clock / prescaler; // Timer frequency in Hz
    uint32_t counter = bsp_timer_get_counter();
    return (counter * 1000000) / timer_frequency; // Convert to microseconds
}




