#pragma once

#include "scheduler.h"
#include "graph.h"
#include "kernel.h"

#include <vector>
#include <memory>

namespace hamurai
{

    class NaiveSchedulerWorker
    {
    public:
        NaiveSchedulerWorker( std::shared_ptr<Kernel> k )
            :_k(k)
        {

        }

        virtual ~NaiveSchedulerWorker()
        {

        }

        void start(){}
        void stop(){}
        void join(){}

    private:
        std::shared_ptr<Kernel> _k;

    };

    class NaiveScheduler : public Scheduler
    {
    public:
        NaiveScheduler(std::shared_ptr<hamurai::Pipeline> p );
        virtual ~NaiveScheduler();

        virtual void start();
        virtual void stop();
        virtual void join();

    private:
        std::vector< std::shared_ptr< NaiveSchedulerWorker > > _workers;

    };
}
