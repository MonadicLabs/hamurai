#pragma once

#include "executionbackend.h"

#include <iostream>

namespace hamurai {

    class NaiveExecutionBackend : public ExecutionBackend
    {
    public:
        NaiveExecutionBackend(){}
        virtual ~NaiveExecutionBackend(){}

        virtual void receive( std::shared_ptr<Event> e )
        {
            if( e->type() == Event::HAMURAI_EVENT_KERNEL_INSERTION )
            {
                std::cerr << "RECEIVED KERNEL INSERTION ORDER !" << std::endl;
            }
            else if( e->type() == Event::HAMURAI_EVENT_KERNEL_DESTRUCTION )
            {
                std::cerr << "RECEIVED KERNEL DESTRUCTION EVENT" << std::endl;
            }
        }

    private:

    protected:

    };
}
