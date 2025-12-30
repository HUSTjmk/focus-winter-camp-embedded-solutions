#ifndef __BSP_UART_H__
#define __BSP_UART_H__

#include "stdint.h"
#include "stdbool.h"
#include "usart.h"
void bsp_uart_init(void);
void bsp_uart_deinit(void);
void bsp_uart_reset(void);
void bsp_enable_uart_receive_it(uint8_t *pData, uint16_t Size, bool enable_periodic);
void bsp_uart_set_rx_event_callback(void(*callback)(uint8_t *data, uint16_t size));
void bsp_uart_clear_rx_event_callback(void);
void bsp_uart_rx_event_callback(uint8_t *data, uint16_t size);
HAL_StatusTypeDef bsp_uart_transmit(uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef bsp_uart_receive(uint8_t *pData, uint16_t Size, uint32_t Timeout);  

#endif /* __BSP_UART_H__ */                        
