#pragma once

namespace hamurai
{
class Event
{
public:

    typedef enum
    {
        HAMURAI_EVENT_NONE=0,
        HAMURAI_EVENT_DATA
    } Type;

    Event()
        :_type(HAMURAI_EVENT_NONE)
    {

    }

    Type type()
    {
        return _type;
    }

protected:
    Event( Event::Type type );
    Event::Type _type;

};
}
