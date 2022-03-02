#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::CspeedValue(unsigned int Cspeed)
{
	view.updateCspeedValue(Cspeed);
}

void Screen1Presenter::TspeedValue(unsigned int Tspeed)
{
	view.updateTspeedValue(Tspeed);
}

void Screen1Presenter::BattperValue(unsigned int Battper)
{
	view.updateBattperValue(Battper);
}

void Screen1Presenter::RangeValue(unsigned int Range)
{
	view.updateRangeValue(Range);
}

void Screen1Presenter::BatteryTempValue(unsigned int BatteryTemp)
{
	view.updateBatteryTempValue(BatteryTemp);
}

