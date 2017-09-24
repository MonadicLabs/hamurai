#pragma once

#include "genericqueue.h"
#include "event.h"

namespace hamurai
{
class EventQueue : public GenericQueue<Event>
{
public:
    EventQueue();
    virtual ~EventQueue();

    virtual bool enqueue( Event const& item );
    virtual bool enqueue( Event&& item );
    virtual bool dequeue(Event & item, int64_t timeout_ms );

private:

protected:
    void * _backend;

};
}
