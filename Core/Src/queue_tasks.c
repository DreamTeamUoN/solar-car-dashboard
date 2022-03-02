#include "main.h"
#include "FreeRTOS.h"
#include "cmsis_os.h"

#include "queue.h"
#include "string.h"
#include <stdlib.h>

 extern xQueueHandle messageA;
 unsigned int Cspeed = 0;
 void CurrentSpeedTask(void *argument)
 {
   for(;;)
   {
 	xQueueSend(messageA, &Cspeed, 0);
 	Cspeed++;
     osDelay(100);
   }
 }


 extern xQueueHandle messageB;
 unsigned int Tspeed = 0;
 void TargetSpeedTask(void *argument)
 {
   for(;;)
   {
 	xQueueSend(messageB, &Tspeed, 0);
 	Tspeed++;
     osDelay(100);
   }
 }

 extern xQueueHandle messageC;
 unsigned int Battper = 0;
 void BatteryPercentageTask(void *argument)
 {
   for(;;)
   {
 	xQueueSend(messageC, &Battper, 0);
 	Battper++;
     osDelay(100);
   }
 }

 extern xQueueHandle messageD;
 unsigned int Range = 0;
 void RangeTask(void *argument)
 {
   for(;;)
   {
 	xQueueSend(messageD, &Range, 0);
 	Range++;
     osDelay(100);
   }
 }

 extern xQueueHandle messageE;
 unsigned int BatteryTemp = 0;
 void BatteryTemperatureTask(void *argument)
 {
   for(;;)
   {
 	xQueueSend(messageE, &BatteryTemp, 0);
 	BatteryTemp++;
     osDelay(100);
   }
 }
