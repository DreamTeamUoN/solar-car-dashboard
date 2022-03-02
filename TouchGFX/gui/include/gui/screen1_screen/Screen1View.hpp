#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void updateCspeedValue(unsigned int newCspeed);
    void updateTspeedValue(unsigned int newTspeed);
    void updateBattperValue(unsigned int newBattper);
    void updateRangeValue(unsigned int newRange);
    void updateBatteryTempValue(unsigned int newBatteryTemp);

protected:
};

#endif // SCREEN1VIEW_HPP
