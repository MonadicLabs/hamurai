#pragma once

#include "executionbackend.h"

#include <iostream>
#include <atomic>

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

        virtual void start();
        virtual void stop();
        virtual void join();

    private:
        void processEvents();
        std::atomic< bool > _needStop;

    protected:
        LockFreeQueue< std::shared_ptr< Event > > _mainQueue;
        std::thread _mainThread;

    };
}
