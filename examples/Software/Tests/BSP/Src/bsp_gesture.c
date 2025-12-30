#include "gpio.h"
#include "bsp_gesture.h"
#include "i2c.h"

void(*bsp_gesture_detect_callback_)(void) = NULL;

void bsp_gesture_init(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GESTURE_INT_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GESTURE_INT_GPIO_Port, &GPIO_InitStruct);
    HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
    // GPIO and I2C initialization for gesture sensor can be added here if needed
}

void bsp_gesture_set_detect_callback(void(*callback)(void))
{
    bsp_gesture_detect_callback_ = callback;
}

void bsp_gesture_clear_detect_callback(void)
{
    bsp_gesture_detect_callback_ = NULL;
}

void bsp_gesture_detect_callback(void)
{
    if (bsp_gesture_detect_callback_)
    {
        bsp_gesture_detect_callback_();        
    }
}

