
#include "scheduler.h"

hamurai::Scheduler::Scheduler(std::shared_ptr<hamurai::Pipeline> p)
{
    flattenPipeline( p, _kernels );
}

hamurai::Scheduler::~Scheduler()
{

}

void hamurai::Scheduler::flattenPipeline(const std::shared_ptr<hamurai::Pipeline> p, std::vector<std::shared_ptr<Kernel> > &kernels)
{
    for( std::shared_ptr<Kernel> k : p->kernels() )
    {
        std::shared_ptr<Pipeline> ispipeline = std::dynamic_pointer_cast<Pipeline>(k);
        if( ispipeline )
        {
            flattenPipeline( ispipeline, kernels );
        }
        else
        {
            kernels.push_back( k );
        }
    }
}
