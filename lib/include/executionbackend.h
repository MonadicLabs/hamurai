#pragma once

#include <memory>

#include "eventmanager.h"
#include "lockfreequeue.h"

namespace hamurai
{

class ExecutionBackend : public EventManager
{
public:
    ExecutionBackend(){}
    virtual ~ExecutionBackend(){}

    virtual void receive( std::shared_ptr<Event> e ){}

    virtual void start(){}
    virtual void stop(){}
    virtual void join(){}

private:

protected:

};
}
