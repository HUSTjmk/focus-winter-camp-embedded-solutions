#ifndef __PAJ7620_H__
#define __PAJ7620_H__

#include "main.h"

#define PAJ7620_W_ADDR                  (0x73<<1)           // 7-bit I2C地址
#define PAJ7620_R_ADDR                  ((0x73<<1)|0x01)    // 7-bit I2C地址
#define PAJ7620_REG_BANK_SELECT         0xEF                // 寄存器Bank切换地址
#define PAJ7620_WAKEUP_CONFIRM_REG      0x00                // 唤醒确认寄存器
#define PAJ7620_WAKEUP_CONFIRM_VAL      0x20                // 唤醒成功返回值
#define PAJ7620_INIT_DELAY_MS           5                   // 初始化延时
#define PAJ7620_WAKEUP_RETRY            5
#define PAJ7620_GES_DATA_REG            0x43
#define PAJ7620_THRESHOLD_CONFIG_REG    0x93
#define PAJ7620_ACCURACY_THRESHOLD_CONFIG_SIZE   5
#define PAJ7620_TIMEOUT                 10000
#define PAJ7620_REG_INIT_ARRAY_SIZE     50
#define PAJ7620_REG_GES_ARRAY_SIZE      30
#define PAJ7620_REG_PS_ARRAY_SIZE       35

typedef enum{
    GES_NONE             = 0x0000U,
    GES_UP               = 0x0001U,
    GES_DOWN             = 0x0002U,
    GES_LEFT             = 0x0004U,
    GES_RIGHT            = 0x0008U,
    GES_FORWARD          = 0x0010U,
    GES_BACKWARD         = 0x0020U,
    GES_CLOCKWISE        = 0x0040U,
    GES_COUNTERCLOCKWISE = 0x0080U,
    GES_WAVE             = 0x0100U 
}Gesture_StatusTypeDef;

uint8_t PAJ7620_Init(void);
Gesture_StatusTypeDef PAJ7620_Detect(void);

extern const uint8_t initial_register_array[PAJ7620_REG_INIT_ARRAY_SIZE][2];
extern const uint8_t gesture_register_array[PAJ7620_REG_GES_ARRAY_SIZE][2];
extern const uint8_t ps_register_array[PAJ7620_REG_PS_ARRAY_SIZE][2];

#endif// __PAJ7620_H__
