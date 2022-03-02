/*
 * queue_tasks.h
 *
 *  Created on: 2 Mar 2022
 *      Author: oabou
 */

#ifndef APPLICATION_USER_QUEUE_TASKS_H_
#define APPLICATION_USER_QUEUE_TASKS_H_

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

void CurrentSpeedTask(void *argument);
void TargetSpeedTask(void *argument);
void BatteryPercentageTask(void *argument);
void RangeTask(void *argument);
void BatteryTemperatureTask(void *argument);

#endif /* APPLICATION_USER_QUEUE_TASKS_H_ */
