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
/* USER CODE BEGIN PV */
#define OUT_BYTE_ARRAY_LENGTH 400
uint8_t out_byte_array[OUT_BYTE_ARRAY_LENGTH];
TX_BYTE_POOL pool_ptr;
uint8_t* allocated_space_pointer;
uint8_t* allocated_space_pointer_2;
uint8_t* allocated_space_pointer_3;
uint32_t ret_val;
/* USER CODE END PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

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
  ret_val=tx_byte_pool_create(&pool_ptr,'our_byte_pool',out_byte_array,OUT_BYTE_ARRAY_LENGTH);

  ret_val=tx_byte_allocate(&pool_ptr,(VOID **)&allocated_space_pointer,128,TX_NO_WAIT );
  ret_val=tx_byte_allocate(&pool_ptr,(VOID **)&allocated_space_pointer_2,128,TX_NO_WAIT );
  ret_val=tx_byte_release(allocated_space_pointer);
  ret_val=tx_byte_allocate(&pool_ptr,(VOID **)&allocated_space_pointer_3,200,TX_NO_WAIT ); //this will fail
  /* USER CODE END App_ThreadX_Init */

  return ret;
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
