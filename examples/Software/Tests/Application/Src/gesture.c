#include "paj7620.h"
#include "bsp_gesture.h"
#include "gesture.h"
#include "stm32f1xx_hal.h"

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
    bsp_gesture_set_detect_callback(getsure_read_from_isr);
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


