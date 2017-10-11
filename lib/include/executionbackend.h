#pragma once

#include <memory>

#include "event.h"

namespace hamurai
{
class ExecutionBackend
{
public:
    ExecutionBackend();
    virtual ~ExecutionBackend();

    virtual void start(){}
    virtual void stop(){}

    virtual void processEvent( std::shared_ptr< Event > e ){}

private:

protected:

};
}
