#ifndef __BSP_I2C_H__
#define __BSP_I2C_H__

#include "stdint.h"
void bsp_i2c_init(void);
void bsp_i2c_deinit(void);
void bsp_i2c_reset(void);
uint8_t bsp_i2c_transmit(uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);
uint8_t bsp_i2c_receive(uint16_t DevAddress, uint8_t *pData,
                        uint16_t Size, uint32_t Timeout);
uint8_t bsp_i2c_mem_write(uint16_t DevAddress, uint16_t MemAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);
uint8_t bsp_i2c_mem_read(uint16_t DevAddress, uint16_t MemAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);                        
#endif /* __BSP_I2C_H__ */
