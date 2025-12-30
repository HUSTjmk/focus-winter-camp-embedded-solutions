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
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define Wheel1_IN1_Pin GPIO_PIN_0
#define Wheel1_IN1_GPIO_Port GPIOA
#define Wheel1_IN2_Pin GPIO_PIN_1
#define Wheel1_IN2_GPIO_Port GPIOA
#define Wheel2_IN1_Pin GPIO_PIN_2
#define Wheel2_IN1_GPIO_Port GPIOA
#define Wheel2_IN2_Pin GPIO_PIN_3
#define Wheel2_IN2_GPIO_Port GPIOA
#define Ultrasonic_Trig_Pin GPIO_PIN_7
#define Ultrasonic_Trig_GPIO_Port GPIOA
#define Servo_Pin GPIO_PIN_0
#define Servo_GPIO_Port GPIOB
#define Ultrasonic_Echo_Pin GPIO_PIN_1
#define Ultrasonic_Echo_GPIO_Port GPIOB
#define Ultrasonic_Echo_EXTI_IRQn EXTI1_IRQn
#define Audio_TX_Pin GPIO_PIN_10
#define Audio_TX_GPIO_Port GPIOB
#define Audio_RX_Pin GPIO_PIN_11
#define Audio_RX_GPIO_Port GPIOB
#define GESTURE_INT_Pin GPIO_PIN_5
#define GESTURE_INT_GPIO_Port GPIOB
#define GESTURE_INT_EXTI_IRQn EXTI9_5_IRQn
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
