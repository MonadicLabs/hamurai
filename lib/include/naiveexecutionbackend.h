#pragma once

#include "executionbackend.h"

#include <iostream>
#include <atomic>
#include <thread>

using namespace std;

namespace hamurai {

    class NaiveExecutionBackend : public ExecutionBackend
    {
    public:
        NaiveExecutionBackend(){}
        virtual ~NaiveExecutionBackend(){}

        virtual void receive( std::shared_ptr<Event> e )
        {
            cerr << "enqueuing Event... " << e->kernel() << " - " << e->type() << endl;
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

    };
}
