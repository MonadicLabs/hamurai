
#include "naiveexecutionbackend.h"
#include "kernel.h"

#include <iostream>
using namespace std;

void hamurai::NaiveExecutionBackend::start()
{
    _needStop = false;
    _mainThread = std::thread( &NaiveExecutionBackend::processEvents, this );
}

void hamurai::NaiveExecutionBackend::stop()
{
    _needStop = true;
}

void hamurai::NaiveExecutionBackend::join()
{
    _mainThread.join();
}

void hamurai::NaiveExecutionBackend::processEvents()
{
    while( !_needStop )
    {

        std::shared_ptr< Event > e = nullptr;
        _mainQueue.dequeue( e, 0 );


        if( e )
        {
            cerr << "queue size=" << _mainQueue.size() << " - RECEIVED NEW EVENT ! - TYPE=" << e->type() << " from " << e->kernel() << endl;
            if( e->type() == hamurai::Event::HAMURAI_EVENT_INIT_QUERY )
            {
                std::shared_ptr< Kernel > k = e->kernel();
                k->init();
            }
            else if( e->type() == hamurai::Event::HAMURAI_EVENT_TICK )
            {
                std::shared_ptr< Kernel > k = e->kernel();
                k->tick();
            }
        }
    }
}


