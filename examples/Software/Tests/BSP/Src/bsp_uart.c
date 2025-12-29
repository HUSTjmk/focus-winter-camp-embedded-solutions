#include "usart.h"
#include "bsp_uart.h"
#include "stdbool.h"

uint8_t* bsp_pdata_default = NULL;
uint32_t bsp_size_default = 0;
bool enable_rxit_periodic = true;

void(*bsp_uart_rx_event_callback)(uint8_t *data, uint16_t size) = 0;

void bsp_uart_init(void)
{
    MX_USART3_UART_Init();
}

void bsp_uart_deinit(void)
{
    HAL_UART_DeInit(&huart3);
}

void bsp_uart_reset(void)
{
    bsp_uart_deinit();
    bsp_uart_init();
}

void bsp_enable_uart_receive_it(uint8_t *pData, uint16_t Size, bool enable_periodic)
{
    bsp_pdata_default = pData;
    bsp_size_default = Size;
    enable_rxit_periodic = enable_periodic;
    HAL_UARTEx_ReceiveToIdle_IT(&huart3, pData, Size);
}

HAL_StatusTypeDef bsp_uart_transmit(uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    return HAL_UART_Transmit(&huart3, pData, Size, Timeout);
}

HAL_StatusTypeDef bsp_uart_receive(uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    return HAL_UART_Receive(&huart3, pData, Size, Timeout);
}

void bsp_uart_set_rx_event_callback(void(*callback)(uint8_t *data, uint16_t size))
{
    bsp_uart_rx_event_callback = callback;
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if (huart->Instance == USART3)
    {
        if (bsp_uart_rx_event_callback)
        {
            bsp_uart_rx_event_callback(huart->pRxBuffPtr, Size);
        }
        if (enable_rxit_periodic && bsp_pdata_default && bsp_size_default)
        {
            HAL_UARTEx_ReceiveToIdle_IT(huart, bsp_pdata_default, bsp_size_default);
        }
    }
}


