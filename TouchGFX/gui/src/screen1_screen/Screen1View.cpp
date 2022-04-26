#include <gui/screen1_screen/Screen1View.hpp>
#include "math.h"


Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateCspeedValue(unsigned int newCspeed)
{
	//circleProgress3.updateValue(newCspeed, 0);

	//Unicode::snprintf(textArea8Buffer, TEXTAREA8_SIZE, "%d", newCspeed);
	//textArea8.resizeToCurrentText();
	//textArea8.invalidate();
}

void Screen1View::updateTspeedValue(unsigned int newTspeed)
{
	//circleProgress4.updateValue(newTspeed, 0);

	//Unicode::snprintf(textArea7Buffer, TEXTAREA7_SIZE, "%d", newTspeed);
	//textArea7.resizeToCurrentText();
	//textArea7.invalidate();
}

void Screen1View::updateBattperValue(unsigned int newBattper)
{
	//imageProgress1.updateValue(newBattper, 0);

	//textProgress1.updateValue(newBattper, 0);
}

void Screen1View::updateRangeValue(unsigned int newRange)
{
	//boxProgress1.updateValue(newRange, 0);

	//Unicode::snprintf(textArea9Buffer, TEXTAREA9_SIZE, "%d", newRange);
	//textArea9.resizeToCurrentText();
	//textArea9.invalidate();
}

void Screen1View::updateBatteryTempValue(unsigned int newBatteryTemp)
{
	//boxProgress2.updateValue(newBatteryTemp, 0);

	//Unicode::snprintf(textArea10Buffer, TEXTAREA10_SIZE, "%d", newBatteryTemp);
	//textArea10.resizeToCurrentText();
	//textArea10.invalidate();
}



