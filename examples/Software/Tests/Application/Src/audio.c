#include "bsp_uart.h"

/*
    UART传输测试，不包含和语音模块的具体协议交互，仅测试UART发送功能
*/

void app_test_audio_demo(void)
{
    uint8_t test_data[] = "Hello, UART Audio Test!\r\n";
    //bsp_uart_init();
    while (1)
    {
        bsp_uart_transmit(test_data, sizeof(test_data) - 1, 1000);
        HAL_Delay(1000);
    }
}
