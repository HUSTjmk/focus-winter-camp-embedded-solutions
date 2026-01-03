#include "gpio.h"
#include "main.h"
#include "stm32f1xx_it.h"
#include "stdbool.h"

static void(*bsp_ultrasonic_echo_callback_)(uint8_t state) = 0;

static void bsp_delay_microseconds(uint32_t us)
{
    volatile uint32_t count;
    count = (SystemCoreClock / 1000000) * us / 5; 
    while(count--);
}
/*Init函数可以忽略，因为HAL库一开始就帮你初始化了*/
void bsp_ultrasonic_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    HAL_GPIO_WritePin(Ultrasonic_Trig_GPIO_Port, Ultrasonic_Trig_Pin, GPIO_PIN_RESET);
    GPIO_InitStruct.Pin = Ultrasonic_Trig_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(Ultrasonic_Trig_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = Ultrasonic_Echo_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(Ultrasonic_Echo_GPIO_Port, &GPIO_InitStruct);

    /* EXTI interrupt init*/
    HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI1_IRQn);
}

void bsp_ultrasonic_deinit(void)
{
    HAL_GPIO_DeInit(Ultrasonic_Trig_GPIO_Port, Ultrasonic_Trig_Pin);
    HAL_GPIO_DeInit(Ultrasonic_Echo_GPIO_Port, Ultrasonic_Echo_Pin);
}

void bsp_ultrasonic_reset(void)
{
    bsp_ultrasonic_deinit();
    bsp_ultrasonic_init();
}

void bsp_ultrasonic_set_echo_callback(void(*callback)(uint8_t state))
{
    bsp_ultrasonic_echo_callback_ = callback;
}

void bsp_ultrasonic_clear_echo_callback(void)
{
    bsp_ultrasonic_echo_callback_ = NULL;
}

void bsp_ultrasonic_echo_callback(void)
{
    if (bsp_ultrasonic_echo_callback_)
    {
        uint8_t echo_state = (uint8_t)HAL_GPIO_ReadPin(Ultrasonic_Echo_GPIO_Port, Ultrasonic_Echo_Pin);
        bsp_ultrasonic_echo_callback_(echo_state);
    }
}

void bsp_ultrasonic_trigger_pulse(uint32_t pulse_width_us)
{
    HAL_GPIO_WritePin(Ultrasonic_Trig_GPIO_Port, Ultrasonic_Trig_Pin, GPIO_PIN_SET);    
    bsp_delay_microseconds(pulse_width_us);    
    HAL_GPIO_WritePin(Ultrasonic_Trig_GPIO_Port, Ultrasonic_Trig_Pin, GPIO_PIN_RESET);
}

bool bsp_ultrasonic_get_echo_state(void)
{
    return (bool)HAL_GPIO_ReadPin(Ultrasonic_Echo_GPIO_Port, Ultrasonic_Echo_Pin);
}

