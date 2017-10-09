
#include "naivescheduler.h"

hamurai::NaiveScheduler::NaiveScheduler(std::shared_ptr<Pipeline> p)
    :Scheduler(p)
{
    for( std::shared_ptr<Kernel> k : _kernels )
    {
        _workers.push_back( std::make_shared< NaiveSchedulerWorker >(k) );
    }
}

hamurai::NaiveScheduler::~NaiveScheduler()
{

}

void hamurai::NaiveScheduler::start()
{
    for( std::shared_ptr< NaiveSchedulerWorker > w : _workers )
    {
        w->start();
    }
}

void hamurai::NaiveScheduler::stop()
{
    for( std::shared_ptr< NaiveSchedulerWorker > w : _workers )
    {
        w->stop();
    }
}

void hamurai::NaiveScheduler::join()
{
    for( std::shared_ptr< NaiveSchedulerWorker > w : _workers )
    {
        w->join();
    }
}
