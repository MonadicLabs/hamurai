#pragma once

#include "pipeline.h"

#include <memory>
#include <vector>

namespace hamurai
{
class Scheduler
{
public:
    Scheduler( std::shared_ptr<hamurai::Pipeline> p );
    virtual ~Scheduler();

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void join() = 0;

private:
    void flattenPipeline( const std::shared_ptr< Pipeline > p, std::vector< std::shared_ptr<Kernel> >& kernels );

protected:
    std::vector< std::shared_ptr< Kernel > > _kernels;

};
}
