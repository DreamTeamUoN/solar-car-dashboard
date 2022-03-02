#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "string.h"

unsigned int aCspeed=0;
unsigned int aTspeed=0;
unsigned int aBattper=0;
unsigned int aRange=0;
unsigned int aBatteryTemp=0;

extern "C"
{
xQueueHandle messageA;
xQueueHandle messageB;
xQueueHandle messageC;
xQueueHandle messageD;
xQueueHandle messageE;
}

Model::Model() : modelListener(0)
{
messageA = xQueueGenericCreate(1, 1, 0);
messageB = xQueueGenericCreate(1, 1, 0);
messageC = xQueueGenericCreate(1, 1, 0);
messageD = xQueueGenericCreate(1, 1, 0);
messageE = xQueueGenericCreate(1, 1, 0);
}

void Model::tick()
{
 if (xQueueReceive(messageA, &aCspeed, 0) == pdTRUE)
 {
	 modelListener->CspeedValue(aCspeed);
  //something with counter information
 }

 if (xQueueReceive(messageB, &aTspeed, 0) == pdTRUE)
  {
 	 modelListener->TspeedValue(aTspeed);
   //something with holder information
  }

 if (xQueueReceive(messageC, &aBattper, 0) == pdTRUE)
   {
  	 modelListener->BattperValue(aBattper);
    //something with holder information
   }

 if (xQueueReceive(messageD, &aRange, 0) == pdTRUE)
   {
  	 modelListener->RangeValue(aRange);
    //something with holder information
   }

 if (xQueueReceive(messageE, &aBatteryTemp, 0) == pdTRUE)
   {
  	 modelListener->BatteryTempValue(aBatteryTemp);
    //something with holder information
   }

}
