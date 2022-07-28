/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SHIPBASE_HPP
#define SHIPBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/AnimatedImage.hpp>

class ShipBase : public touchgfx::Container
{
public:
    ShipBase();
    virtual ~ShipBase();
    virtual void initialize();

    /*
     * Custom Trigger Callback Setters
     */
    void setFireBulletTriggerCallback(touchgfx::GenericCallback<>& callback)
    {
        this->fireBulletTriggerCallback = &callback;
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Custom Trigger Emitters
     */
    virtual void emitFireBulletTriggerCallback()
    {
        if (fireBulletTriggerCallback && fireBulletTriggerCallback->isValid())
        {
            this->fireBulletTriggerCallback->execute();
        }
    }

    /*
     * Member Declarations
     */
    touchgfx::AnimatedImage animatedImage;

private:

    /*
     * Custom Trigger Callback Declarations
     */
    touchgfx::GenericCallback<>* fireBulletTriggerCallback;

};

#endif // SHIPBASE_HPP
