#pragma once

#include <memory>
#include <map>
#include <vector>

#include "kernel.h"
#include "link.h"
#include "executionbackend.h"

namespace hamurai
{
    class Pipeline : public Kernel
    {
    public:

        std::vector<std::shared_ptr<Kernel> > kernels();
        std::vector<std::shared_ptr<Link> > links();

        void start( std::shared_ptr< ExecutionBackend > backend );
        void stop();

    private:
        std::map< hamurai::Id, std::shared_ptr< hamurai::Kernel > > _nodes;
        std::map< hamurai::Id, std::shared_ptr< hamurai::Link > > _links;

    protected:

    };
}
