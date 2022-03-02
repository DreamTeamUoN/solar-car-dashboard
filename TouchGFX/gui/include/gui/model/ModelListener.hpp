#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>


/**ModelListener is the interface through which the Model can inform the currently
 * active presenter of events. All presenters should derive from this class.
 * It also provides a model pointer for the presenter to interact with the Model
 *
 * BindFunction is called automatically
 *
 * Add the virtual functions Model should be able to call on the active presenter to this class.
 *
 */

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }
    virtual void CspeedValue(unsigned int Cspeed) {}
    virtual void TspeedValue(unsigned int Tspeed) {}
    virtual void BattperValue(unsigned int Battper) {}
    virtual void RangeValue(unsigned int Range) {}
    virtual void BatteryTempValue(unsigned int BatteryTemp) {}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
