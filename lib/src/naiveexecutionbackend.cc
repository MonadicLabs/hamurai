
#include "naiveexecutionbackend.h"


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


