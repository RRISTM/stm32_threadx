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
#define THRAD_STACK_SIZE 1024
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
uint8_t thread_stack[THRAD_STACK_SIZE];
    TX_THREAD thread_ptr;

    uint8_t thread_stack2[THRAD_STACK_SIZE];
    TX_THREAD thread_ptr2;

#define TRACEX_BUFFER_SIZE 64000
uint8_t tracex_buffer[64000] __attribute__ ((section (".trace")));
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
    VOID my_thread_entry(ULONG initial_input);
    VOID my_thread_entry2(ULONG initial_input);
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
  (void)byte_pool;
  tx_thread_create( &thread_ptr, "my_thread", my_thread_entry, 0x1234, thread_stack, THRAD_STACK_SIZE, 15, 13, 1, TX_AUTO_START);
  tx_thread_create(&thread_ptr2, "my_thread2", my_thread_entry2, 0x1234, thread_stack2,    THRAD_STACK_SIZE, 14, 14, 1, TX_AUTO_START);

  tx_trace_enable(&tracex_buffer,TRACEX_BUFFER_SIZE,30);
  /* USER CODE END App_ThreadX_Init */

  return ret;
}

/* USER CODE BEGIN 1 */
VOID my_thread_entry (ULONG initial_input)
{
    while(1){
    	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
    	HAL_Delay(200);
        tx_thread_sleep(20);
    }
}

VOID my_thread_entry2 (ULONG initial_input)
{
    while(1){
        HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
        HAL_Delay(200);
        tx_thread_sleep(20);
    }
}
/* USER CODE END 1 */
