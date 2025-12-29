#include "tim.h"
#include "bsp_timer.h"

void(*bsp_timer_period_elapsed_callback)(void) = 0;

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
    HAL_TIM_Base_Start(&htim4);
}

void bsp_timer_stop(void)
{
    HAL_TIM_Base_Stop(&htim4);
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
    bsp_timer_period_elapsed_callback = callback;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM4)
    {
        if (bsp_timer_period_elapsed_callback)
        {
            bsp_timer_period_elapsed_callback();
        }
    }
}



