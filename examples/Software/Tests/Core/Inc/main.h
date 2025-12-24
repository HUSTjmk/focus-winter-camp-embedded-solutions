/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Wheel1_Spd_Pin GPIO_PIN_0
#define Wheel1_Spd_GPIO_Port GPIOA
#define Wheel2_Spd_Pin GPIO_PIN_1
#define Wheel2_Spd_GPIO_Port GPIOA
#define Wheel3_Spd_Pin GPIO_PIN_2
#define Wheel3_Spd_GPIO_Port GPIOA
#define Wheel4_Spd_Pin GPIO_PIN_3
#define Wheel4_Spd_GPIO_Port GPIOA
#define Ultrasonic_Echo_Pin GPIO_PIN_1
#define Ultrasonic_Echo_GPIO_Port GPIOB
#define Ultrasonic_Echo_EXTI_IRQn EXTI1_IRQn
#define Ultrasonic_Trigger_Pin GPIO_PIN_2
#define Ultrasonic_Trigger_GPIO_Port GPIOB
#define Audio_TX_Pin GPIO_PIN_10
#define Audio_TX_GPIO_Port GPIOB
#define Audio_RX_Pin GPIO_PIN_11
#define Audio_RX_GPIO_Port GPIOB
#define Wheel1_Dir_Pin GPIO_PIN_12
#define Wheel1_Dir_GPIO_Port GPIOB
#define Wheel2_Dir_Pin GPIO_PIN_13
#define Wheel2_Dir_GPIO_Port GPIOB
#define Wheel3_Dir_Pin GPIO_PIN_14
#define Wheel3_Dir_GPIO_Port GPIOB
#define Wheel4_Dir_Pin GPIO_PIN_15
#define Wheel4_Dir_GPIO_Port GPIOB
#define I2C_Bus_SCL_Pin GPIO_PIN_6
#define I2C_Bus_SCL_GPIO_Port GPIOB
#define I2C_Bus_SDA_Pin GPIO_PIN_7
#define I2C_Bus_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
