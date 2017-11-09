#pragma once

#include <memory>

namespace hamurai
{

class Kernel;
class Event
{
public:

    typedef enum
    {
        HAMURAI_EVENT_NONE=0,
        HAMURAI_EVENT_TICK,
        HAMURAI_EVENT_DATA_RECEIVED,
        HAMURAI_EVENT_INIT_QUERY,
        HAMURAI_EVENT_EXECUTION_QUERY,
        HAMURAI_EVENT_KERNEL_INSERTION,
        HAMURAI_EVENT_KERNEL_DESTRUCTION,
        HAMURAI_EVENT_KERNEL_START,
        HAMURAI_EVENT_KERNEL_STOP,
        HAMURAI_EVENT_KERNEL_START_IDLE,
        HAMURAI_EVENT_KERNEL_STOP_IDLE,
        HAMURAI_EVENT_LAST
    } Type;

    Event(Type eventType = HAMURAI_EVENT_NONE, std::shared_ptr<Kernel> k = nullptr );

    Type type()
    {
        return _type;
    }

    std::shared_ptr< Kernel > kernel()
    {
        return _kernel;
    }

protected:
    // Event( Event::Type type );
    Event::Type _type;
    std::shared_ptr< Kernel > _kernel;

};

}
