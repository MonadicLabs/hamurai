#pragma once

#include <memory>

#include "eventmanager.h"

namespace hamurai
{

class ExecutionBackend : public EventManager
{
public:
    ExecutionBackend(){}
    virtual ~ExecutionBackend(){}

    virtual void receive( std::shared_ptr<Event> e ){}

private:

protected:

};
}
