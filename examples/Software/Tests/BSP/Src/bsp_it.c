#include "bsp_it.h"
#include "bsp_ultrasonic.h"
#include "bsp_timer.h"
#include "bsp_uart.h"
#include "bsp_gesture.h"
#include "main.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == Ultrasonic_Echo_Pin)
    {
        bsp_ultrasonic_echo_callback();
    }
    if (GPIO_Pin == GESTURE_INT_Pin)
    {
        bsp_gesture_detect_callback();
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM4)
    {
        bsp_timer_period_elapsed_callback();
    }
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if (huart->Instance == USART3)
    {
        bsp_uart_rx_event_callback(huart->pRxBuffPtr, Size);
    }
}


