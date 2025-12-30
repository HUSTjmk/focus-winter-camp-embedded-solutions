#include "OLED.h"


void app_display_test_demo(void)
{
    OLED_Init();
    OLED_Clear();
    OLED_ShowString(0, 0, "Hello, World!", OLED_8X16);
    OLED_ShowNum(0, 16, 1234567890, 10, OLED_8X16);
    OLED_DrawRectangle(0, 32, 50, 20, OLED_UNFILLED);
    OLED_Update();
}
