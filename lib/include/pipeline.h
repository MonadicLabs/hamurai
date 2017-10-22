#pragma once

#include <memory>
#include <map>
#include <vector>

#include <iostream>

#include "kernel.h"
#include "link.h"
#include "executionbackend.h"

using namespace std;

namespace hamurai
{
class Pipeline : public Kernel
{
public:

    Pipeline();
    virtual ~Pipeline();

    std::vector<std::shared_ptr<Kernel> > kernels();
    std::vector<std::shared_ptr<Link> > links();

    void start( std::shared_ptr< ExecutionBackend > backend )
    {

        setEventManager( backend );

        // We start all of our kernels
        for( auto kv : _kernels )
        {
            // cerr << "starting one kernel..." << endl;
            kv.second->start();
        }
    }

    void stop()
    {
        // We stop all of our kernels
        for( auto kv : _kernels )
        {
            kv.second->stop();
        }
    }

    virtual void receive( std::shared_ptr<Event> e )
    {
        if( _parentManager )
        {
            _parentManager->receive( e );
        }
    }

    void addKernel( std::shared_ptr< Kernel > k )
    {
        // Okay, so we add the reference to the kernel in our dictionary
        _kernels.insert( make_pair( rand(), k ) );

        // We set the kernel event manager as ourself
        k->setEventManager( shared_from_this() );

        // Tell our own event manager that we have added a new kernel to manage
        // schedule( std::make_shared<Event>(Event::HAMURAI_EVENT_KERNEL_INSERTION, k) );

    }

private:
    std::map< hamurai::Id, std::shared_ptr< hamurai::Kernel > > _kernels;
    std::map< hamurai::Id, std::shared_ptr< hamurai::Link > > _links;

protected:

};
}
