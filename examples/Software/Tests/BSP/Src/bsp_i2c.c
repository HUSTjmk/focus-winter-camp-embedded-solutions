#include "i2c.h"
#include "bsp_i2c.h"

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

void bsp_i2c_transmit(uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    HAL_I2C_Master_Transmit(&hi2c1, DevAddress, pData, Size, Timeout);
}

void bsp_i2c_receive(uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    HAL_I2C_Master_Receive(&hi2c1, DevAddress, pData, Size, Timeout);
}



