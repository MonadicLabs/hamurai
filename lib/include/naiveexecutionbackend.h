#pragma once

#include "executionbackend.h"

#include <iostream>
#include <atomic>
#include <thread>
#include <set>

using namespace std;

namespace hamurai {

    class NaiveExecutionBackend : public ExecutionBackend
    {
    public:
        NaiveExecutionBackend(){}
        virtual ~NaiveExecutionBackend(){}

        virtual void receive( std::shared_ptr<Event> e )
        {
            if( e->type() == Event::HAMURAI_EVENT_KERNEL_START_IDLE )
            {
                _idling.insert( e->kernel() );
            }
            _mainQueue.enqueue( e );
        }

        virtual void start();
        virtual void stop();
        virtual void join();

    private:
        void processEvents();
        std::atomic< bool > _needStop;

    protected:
        EventQueue _mainQueue;
        std::thread _mainThread;

        std::set< std::shared_ptr< Kernel > > _idling;

    };
}
