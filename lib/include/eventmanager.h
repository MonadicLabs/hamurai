#pragma once

#include <memory>

#include "event.h"

namespace hamurai
{
    class EventManager
    {
    public:
        EventManager(){}
        virtual ~EventManager(){}

        virtual void receive( std::shared_ptr<Event> e )
        {

        }

    private:

    protected:

    };
}
