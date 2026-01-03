#include "i2c.h"
#include "bsp_i2c.h"

/*Init函数可以忽略，因为HAL库一开始就帮你初始化了*/
void bsp_i2c_init(void)
{
    MX_I2C1_Init();
}

void bsp_i2c_deinit(void)
{
    HAL_I2C_DeInit(&hi2c1);
}

void bsp_i2c_reset(void)
{
    bsp_i2c_deinit();
    bsp_i2c_init();
}

uint8_t bsp_i2c_transmit(uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    return HAL_I2C_Master_Transmit(&hi2c1, DevAddress, pData, Size, Timeout);
}

uint8_t bsp_i2c_receive(uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    return HAL_I2C_Master_Receive(&hi2c1, DevAddress, pData, Size, Timeout);
}

uint8_t bsp_i2c_mem_write(uint16_t DevAddress, uint16_t MemAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    return HAL_I2C_Mem_Write(&hi2c1, DevAddress, MemAddress, I2C_MEMADD_SIZE_8BIT, pData, Size, Timeout);
}

uint8_t bsp_i2c_mem_read(uint16_t DevAddress, uint16_t MemAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    return HAL_I2C_Mem_Read(&hi2c1, DevAddress, MemAddress, I2C_MEMADD_SIZE_8BIT, pData, Size, Timeout);
}



