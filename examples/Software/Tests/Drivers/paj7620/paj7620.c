#include <stdint.h>
#include "paj7620.h"
#include "stdio.h"
#include "stdbool.h"
#include "bsp_i2c.h"
#include "bsp_gesture.h"

/*
    *这是学长快一年前使用这个模块的时候写的一个驱动程序（似乎是修改某个博主的历程）
    *学长主要在调试时发现不同方向手势检测的敏感度存在明显差异，遂添加了不同方向阈值配置功能，
    配置threshold_config_array数组即可调节各方向灵敏度（具体见手册），也可以用学长调出来合适的或者
    用产商默认的，把那行代码删了就行
    *只实现了手势功能，PS功能没有写完，感兴趣的可以查阅数据手册自行实现
*/

uint8_t enable_cmd[2] = {0x72, 0x01};  // Bank1 0x72寄存器写1
uint8_t interrupt_cmd[2] = {0x41, 0xFF};
uint8_t switch_bank0[2] = {0xEF, 0x00};
uint8_t threshold_config_array[] = {
    0x0C, 0x10, 0x01, 0x1F, 0x0F
};


static uint8_t Write(uint8_t reg_addr, uint8_t* reg_data, uint16_t length)
{
    return bsp_i2c_mem_write(PAJ7620_W_ADDR, reg_addr, reg_data, length, PAJ7620_TIMEOUT);
}

static uint8_t Read(uint8_t reg_addr, uint8_t *reg_data, uint16_t length)
{
    return bsp_i2c_mem_read(PAJ7620_R_ADDR, reg_addr, reg_data, length, PAJ7620_TIMEOUT);
}

static void Delay(uint32_t ms)
{
    HAL_Delay(ms);
}

// 唤醒函数（带状态确认）
static uint8_t PAJ7620_WakeUp(void) 
{
    uint8_t confirm = 0;
    uint8_t status;
    uint8_t temp_data = 0x00;
    Write(0x00, &temp_data, 1);
    Delay(PAJ7620_INIT_DELAY_MS);
    // 尝试读取唤醒确认寄存器
    for(uint8_t retry = 0; retry < PAJ7620_WAKEUP_RETRY; retry++) {
        status = Read(PAJ7620_WAKEUP_CONFIRM_REG, &confirm, 1);
        if(status == 0 && confirm == PAJ7620_WAKEUP_CONFIRM_VAL) {
            return 0;
        }        
    }    
    return 1;  // 唤醒失败
}

// 完整初始化流程
uint8_t PAJ7620_Init(void)
{
    //bsp_gesture_init();
    static uint8_t reg_addr;
    static uint8_t reg_val = 0;
    // 唤醒设备
    if(PAJ7620_WakeUp() != 0) 
        return 1;
    // 写入初始化寄存器配置
    for(uint8_t i = 0; i < PAJ7620_REG_INIT_ARRAY_SIZE; i++) 
    {
        reg_addr = initial_register_array[i][0];
        reg_val = initial_register_array[i][1];
        if(Write(reg_addr, &reg_val, 1) != 0) {                   
            return 1;
        }       
    }      
    // 配置中断，启用手势传感全部中断
    reg_addr = interrupt_cmd[0];
    reg_val = interrupt_cmd[1];
    if(Write(reg_addr, &reg_val, 1) != 0) {
        return 1;
    }
    //切换回bank0
    reg_addr = switch_bank0[0];
    reg_val = switch_bank0[1];
    if(Write(reg_addr, &reg_val, 1) != 0) {
        return 1; 
    }      
    //配置灵敏度阈值              
    if(Write(PAJ7620_THRESHOLD_CONFIG_REG, threshold_config_array, PAJ7620_ACCURACY_THRESHOLD_CONFIG_SIZE) != 0){
        return 1; 
    };
    reg_addr = enable_cmd[0];
    reg_val = enable_cmd[1];       
    return Write(reg_addr, &reg_val, 1);
}

Gesture_StatusTypeDef PAJ7620_Detect(void)
{
    uint8_t gesture_data[2] = {0};
    Gesture_StatusTypeDef fused_data;
    Read(PAJ7620_GES_DATA_REG, gesture_data, 2);
    fused_data = (Gesture_StatusTypeDef)((gesture_data[1] << 8) | gesture_data[0]);
    return fused_data;
}
