#include "paj7620.h"
#include "bsp_gesture.h"
#include "gesture.h"
#include "stm32f1xx_hal.h"

/*测试：手势识别任务演示*/

uint8_t init_status = 0;
Gesture_StatusTypeDef gesture;
uint8_t gesture_detected = 0;

static void getsure_read_from_isr(void)
{
    gesture = PAJ7620_Detect();
    gesture_detected = 1;
}

void app_gesture_test_demo(void)
{
    init_status = PAJ7620_Init();
    if(init_status != 0){
        // 初始化失败，进行错误处理
    }
    bsp_gesture_set_detect_callback(getsure_read_from_isr);
    /*  
        测试发现：启用中断模式时，模块上电后无法清除中断标志位，所以无法触发中断。
        这里初始化时读取一次手势传感数据清除标志位，使中断功能可以正常使用 
        学长是用示波器探测波形解决的。我们鼓励各位尝试各种调试方法解决问题。
    */
	gesture = PAJ7620_Detect();
    while(1)
    {        
        if(gesture_detected == 0){
            HAL_Delay(100);
            continue;
        }            
        switch(gesture)
        {
            case GES_NONE:
                // No gesture detected
                break;
            case GES_FORWARD:
                // Handle forward gesture
                break;
            case GES_BACKWARD:
                // Handle backward gesture
                break;
            case GES_RIGHT:
                // Handle right gesture
                break;
            case GES_LEFT:
                // Handle left gesture
                break;
            case GES_UP:
                // Handle up gesture
                break;
            case GES_DOWN:
                // Handle down gesture
                break;
            case GES_CLOCKWISE:
                // Handle clockwise gesture
                break;
            case GES_COUNTERCLOCKWISE:
                // Handle counterclockwise gesture
                break;
            case GES_WAVE:
                // Handle wave gesture
                break;
            default:
                // No gesture detected
                break;
        }                
    }
}


