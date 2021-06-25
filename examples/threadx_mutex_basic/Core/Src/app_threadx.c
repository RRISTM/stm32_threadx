/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_threadx.c
  * @author  MCD Application Team
  * @brief   ThreadX applicative file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "app_threadx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
#define THRAD_STACK_SIZE 1024

uint8_t thread_stack[THRAD_STACK_SIZE];
uint8_t thread_stack2[THRAD_STACK_SIZE];
uint8_t thread_stack3[THRAD_STACK_SIZE];
TX_THREAD thread_ptr;
TX_THREAD thread_ptr2;
TX_THREAD thread_ptr3;
TX_MUTEX mutex_ptr;
uint32_t ret_val;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
VOID my_thread_entry (ULONG initial_input);
VOID my_thread_entry2 (ULONG initial_input);
VOID my_thread_entry3 (ULONG initial_input);
/* USER CODE END PFP */
/**
  * @brief  Application ThreadX Initialization.
  * @param memory_ptr: memory pointer
  * @retval int
  */
UINT App_ThreadX_Init(VOID *memory_ptr)
{
  UINT ret = TX_SUCCESS;
  TX_BYTE_POOL *byte_pool = (TX_BYTE_POOL*)memory_ptr;

  /* USER CODE BEGIN App_ThreadX_Init */
  ret_val = tx_thread_create(&thread_ptr, "my_thread",
      my_thread_entry, 0x1234,
      thread_stack, THRAD_STACK_SIZE,
      13, 13, 1,
      TX_AUTO_START);
  ret_val = tx_thread_create(&thread_ptr2, "my_thread2",
      my_thread_entry2, 0x1234,
      thread_stack2, THRAD_STACK_SIZE,
      15, 15, 1,
      TX_AUTO_START);
  ret_val = tx_thread_create(&thread_ptr3, "my_thread3",
      my_thread_entry3, 0x1234,
      thread_stack3, THRAD_STACK_SIZE,
      14, 14, 1,
      TX_DONT_START);

  tx_mutex_create(&mutex_ptr,"my_mutex", TX_INHERIT);//use to inherit priority
  //tx_mutex_create(&mutex_ptr,"my_mutex", TX_NO_INHERIT);//use to not inherit priority
  /* USER CODE END App_ThreadX_Init */

  return ret;
}

/* USER CODE BEGIN 1 */
VOID my_thread_entry (ULONG initial_input)
{
    tx_thread_sleep(15);
    while(1){
        tx_mutex_get(&mutex_ptr,TX_WAIT_FOREVER);
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
        tx_mutex_put(&mutex_ptr);
        tx_thread_sleep(15);
    }
}

VOID my_thread_entry2 (ULONG initial_input)
{
    while(1){
        tx_mutex_get(&mutex_ptr,TX_WAIT_FOREVER);
        tx_thread_resume(&thread_ptr3);
        HAL_Delay(200);
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_1);
        tx_mutex_put(&mutex_ptr);
    }
}

VOID my_thread_entry3 (ULONG initial_input)
{
    tx_thread_sleep(10);
    while(1){
        HAL_Delay(200);
    }
}
/* USER CODE END 1 */
