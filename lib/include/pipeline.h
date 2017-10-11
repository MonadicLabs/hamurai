#pragma once

#include <memory>
#include <map>
#include <vector>

#include "kernel.h"
#include "link.h"
#include "executionbackend.h"
#include "initevent.h"

namespace hamurai
{
    class Pipeline : public Kernel
    {
    public:

        Pipeline( std::shared_ptr<ExecutionBackend> backend = nullptr )
            :_backend(backend)
        {

        }

        std::vector<std::shared_ptr<Kernel> > kernels();
        std::vector<std::shared_ptr<Link> > links();

        void start( std::shared_ptr< ExecutionBackend > backend );
        void stop();

        void addKernel( std::shared_ptr< Kernel > k )
        {
            _kernels.insert( make_pair( k->id(), k ) );
            _backend->processEvent( std::make_shared< InitEvent >( k ) );
        }

    private:
        std::map< hamurai::Id, std::shared_ptr< hamurai::Kernel > > _kernels;
        std::map< hamurai::Id, std::shared_ptr< hamurai::Link > > _links;

        std::shared_ptr< ExecutionBackend > _backend;

    protected:

    };
}
