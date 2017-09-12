#pragma once

#include "event.h"
#include "port.h"

#include <string>

namespace hamurai
{
    class DataEvent : public Event
    {
    public:
        DataEvent( const std::string& portName )
            :Event( Event::HAMURAI_EVENT_DATA ), _portName( portName )
        {

        }

        virtual ~DataEvent()
        {

        }

        std::string port_name()
        {
            return _portName;
        }

    private:
        std::string _portName;

    };
}
