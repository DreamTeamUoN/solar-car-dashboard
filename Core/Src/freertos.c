/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TouchGFXTask */
osThreadId_t TouchGFXTaskHandle;
const osThreadAttr_t TouchGFXTask_attributes = {
  .name = "TouchGFXTask",
  .stack_size = 4096 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for videoTask */
osThreadId_t videoTaskHandle;
const osThreadAttr_t videoTask_attributes = {
  .name = "videoTask",
  .stack_size = 1000 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for CurrentSpeedTask */
osThreadId_t CurrentSpeedTaskHandle;
const osThreadAttr_t CurrentSpeedTask_attributes = {
  .name = "CurrentSpeedTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TargetSpeedTask */
osThreadId_t TargetSpeedTaskHandle;
const osThreadAttr_t TargetSpeedTask_attributes = {
  .name = "TargetSpeedTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for BatteryPercentageTask */
osThreadId_t BatteryPercentageTaskHandle;
const osThreadAttr_t BatteryPercentageTask_attributes = {
  .name = "BatteryPercentageTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for RangeTask */
osThreadId_t RangeTaskHandle;
const osThreadAttr_t RangeTask_attributes = {
  .name = "RangeTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for BatteryTemperatureTask */
osThreadId_t BatteryTemperatureTaskHandle;
const osThreadAttr_t BatteryTemperatureTask_attributes = {
  .name = "BatteryTemperatureTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for messageA */
osMessageQueueId_t messageAHandle;
const osMessageQueueAttr_t messageA_attributes = {
  .name = "messageA"
};
/* Definitions for messageB */
osMessageQueueId_t messageBHandle;
const osMessageQueueAttr_t messageB_attributes = {
  .name = "messageB"
};
/* Definitions for messageC */
osMessageQueueId_t messageCHandle;
const osMessageQueueAttr_t messageC_attributes = {
  .name = "messageC"
};
/* Definitions for messageD */
osMessageQueueId_t messageDHandle;
const osMessageQueueAttr_t messageD_attributes = {
  .name = "messageD"
};
/* Definitions for messageE */
osMessageQueueId_t messageEHandle;
const osMessageQueueAttr_t messageE_attributes = {
  .name = "messageE"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   extern portBASE_TYPE IdleTaskHook(void* p);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
extern void TouchGFX_Task(void *argument);
extern void videoTaskFunc(void *argument);
void CurrentSpeed_Task(void *argument);
void TargetSpeed_Task(void *argument);
void BatteryPercentage_Task(void *argument);
void Range_Task(void *argument);
void BatteryTemperature_Task(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationIdleHook(void);

/* USER CODE BEGIN 2 */
void vApplicationIdleHook( void )
{
   /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
   to 1 in FreeRTOSConfig.h. It will be called on each iteration of the idle
   task. It is essential that code added to this hook function never attempts
   to block in any way (for example, call xQueueReceive() with a block time
   specified, or call vTaskDelay()). If the application makes use of the
   vTaskDelete() API function (as this demo application does) then it is also
   important that vApplicationIdleHook() is permitted to return to its calling
   function, because it is the responsibility of the idle task to clean up
   memory allocated by the kernel to any task that has since been deleted. */
  
  vTaskSetApplicationTaskTag(NULL, IdleTaskHook);
}
/* USER CODE END 2 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of messageA */
  messageAHandle = osMessageQueueNew (16, sizeof(uint16_t), &messageA_attributes);

  /* creation of messageB */
  messageBHandle = osMessageQueueNew (16, sizeof(uint16_t), &messageB_attributes);

  /* creation of messageC */
  messageCHandle = osMessageQueueNew (16, sizeof(uint16_t), &messageC_attributes);

  /* creation of messageD */
  messageDHandle = osMessageQueueNew (16, sizeof(uint16_t), &messageD_attributes);

  /* creation of messageE */
  messageEHandle = osMessageQueueNew (16, sizeof(uint16_t), &messageE_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of TouchGFXTask */
  TouchGFXTaskHandle = osThreadNew(TouchGFX_Task, NULL, &TouchGFXTask_attributes);

  /* creation of videoTask */
  videoTaskHandle = osThreadNew(videoTaskFunc, NULL, &videoTask_attributes);

  /* creation of CurrentSpeedTask */
  CurrentSpeedTaskHandle = osThreadNew(CurrentSpeed_Task, NULL, &CurrentSpeedTask_attributes);

  /* creation of TargetSpeedTask */
  TargetSpeedTaskHandle = osThreadNew(TargetSpeed_Task, NULL, &TargetSpeedTask_attributes);

  /* creation of BatteryPercentageTask */
  BatteryPercentageTaskHandle = osThreadNew(BatteryPercentage_Task, NULL, &BatteryPercentageTask_attributes);

  /* creation of RangeTask */
  RangeTaskHandle = osThreadNew(Range_Task, NULL, &RangeTask_attributes);

  /* creation of BatteryTemperatureTask */
  BatteryTemperatureTaskHandle = osThreadNew(BatteryTemperature_Task, NULL, &BatteryTemperatureTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_CurrentSpeed_Task */
/**
* @brief Function implementing the CurrentSpeedTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_CurrentSpeed_Task */
void CurrentSpeed_Task(void *argument)
{
  /* USER CODE BEGIN CurrentSpeed_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END CurrentSpeed_Task */
}

/* USER CODE BEGIN Header_TargetSpeed_Task */
/**
* @brief Function implementing the TargetSpeedTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TargetSpeed_Task */
void TargetSpeed_Task(void *argument)
{
  /* USER CODE BEGIN TargetSpeed_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END TargetSpeed_Task */
}

/* USER CODE BEGIN Header_BatteryPercentage_Task */
/**
* @brief Function implementing the BatteryPercentageTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_BatteryPercentage_Task */
void BatteryPercentage_Task(void *argument)
{
  /* USER CODE BEGIN BatteryPercentage_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END BatteryPercentage_Task */
}

/* USER CODE BEGIN Header_Range_Task */
/**
* @brief Function implementing the RangeTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Range_Task */
void Range_Task(void *argument)
{
  /* USER CODE BEGIN Range_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Range_Task */
}

/* USER CODE BEGIN Header_BatteryTemperature_Task */
/**
* @brief Function implementing the BatteryTemperatureTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_BatteryTemperature_Task */
void BatteryTemperature_Task(void *argument)
{
  /* USER CODE BEGIN BatteryTemperature_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END BatteryTemperature_Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
