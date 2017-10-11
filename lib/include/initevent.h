#pragma once

#include "event.h"
#include "kernel.h"

#include <memory>

namespace hamurai
{
    class InitEvent : public hamurai::Event
    {
    public:
        InitEvent( std::shared_ptr< Kernel > kernel )
            :Event( HAMURAI_EVENT_INIT ), _kernel(kernel)
        {

        }

        virtual ~InitEvent()
        {

        }

        std::shared_ptr< Kernel > kernel()
        {
            return _kernel;
        }

    private:
        std::shared_ptr< Kernel > _kernel;

    };
}
